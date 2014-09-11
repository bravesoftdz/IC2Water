// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BKMXExportThread.h"
#include "GlobalParameter.h"
#include "BKMXShowForm.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall TBKMXExportThread::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall TBKMXExportThread::TBKMXExportThread(bool CreateSuspended,
												TcxProgressBar* progress,
                                                TADOQuery* Query,
                                                TcxButton* EXBTN,
                                                TcxButton* PreBTN,
                                                TcxButton* EBTN,
                                                String savepath,
                                                String BeginDatestr,
                                                String EndDatestr,
                                                String CZCZYstr,
                                                String CZYstr) : TThread(CreateSuspended)
{
	Validprogress = progress;
    ValidQuery = Query;
    ValidEXBTN = EXBTN;
    ValidPreBTN = PreBTN;
    ValidEBTN = EBTN;
    Validsavepath = savepath;

    ValidBeginDatestr = BeginDatestr;
    ValidEndDatestr = EndDatestr;
    ValidCZCZYstr = CZCZYstr;
    ValidCZYstr = CZYstr;
}
// ---------------------------------------------------------------------------

void __fastcall TBKMXExportThread::Execute()
{
	// ---- Place thread code here ----
    ValidEXBTN->Enabled = false;
    ValidPreBTN->Enabled = false;
    ValidEBTN->Enabled = false;

    Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(BKMXShowFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
        ValidEXBTN->Enabled = true;
        ValidPreBTN->Enabled = true;
        ValidEBTN->Enabled = true;
		return;
	}

    ValidQuery->Open();
    String DTX = "";
    String path = GlobalPath;
    String Templatepath;
    ValidQuery->First();
    int allrecord = ValidQuery->RecordCount;
    for(int i = 0; i <65531; i++)
    {
        DTX += ValidQuery->FieldByName("kh")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("bh")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BUMEN")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("NAME")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("YE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("LX")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("Operator")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("DateTime")->AsAnsiString.Trim();
        DTX += "\n";
        Validprogress->Position = i*100/allrecord;
        ValidQuery->Next();
        if(ValidQuery->Eof)
            break;
    }

    Templatepath = path + "\\ExportXLSTemplate\\BKMXTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", ValidCZCZYstr.t_str());

    ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", ValidCZYstr.t_str());
    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBeginDatestr.t_str());


    ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidEndDatestr.t_str());

    Variant RE = ST.OlePropertyGet("Range", "A6").OleFunction("Select");
    Clipboard()->Clear();
    Clipboard()->SetTextBuf(DTX.c_str());
    ST.OleFunction("Paste");
    Clipboard()->Clear();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
    WB.OleFunction("SaveAs", Validsavepath.t_str());
    ExcelApp.OleFunction("Quit");
    ExcelApp = Unassigned;
    Validprogress->Position = 100;
    MessageBox(BKMXShowFrm->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    ValidEXBTN->Enabled = true;
    ValidPreBTN->Enabled = true;
    ValidEBTN->Enabled = true;

}
// ---------------------------------------------------------------------------
