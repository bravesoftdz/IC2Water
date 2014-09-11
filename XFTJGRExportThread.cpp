//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFTJGRExportThread.h"
#include "XFTJQForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TXFTJGRExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TXFTJGRExportThread::TXFTJGRExportThread(bool CreateSuspended,
													TcxProgressBar* progress,
                                                    TADOQuery* Query,
                                                    TcxButton* EXBTN,
                                                    TcxButton* PreBTN,
                                                    TcxButton* EBTN,
                                                    TcxButton* QBTN,
                                                    String ZZE,
                                                    String ZZCS,
                                                    String savepath,
                                                    String BeginDatestr,
                                                    String EndDatestr,
                                                    String BMStr,
                                                    String BHStr,
                                                    String CZYStr) : TThread(CreateSuspended)
{
	Validprogress = progress;
    ValidQuery = Query;
    ValidEXBTN = EXBTN;
    ValidPreBTN = PreBTN;
    ValidEBTN = EBTN;
    ValidQBTN = QBTN;
    ValidZZE = ZZE;
    ValidZZCS = ZZCS;
    Validsavepath = savepath;
    ValidBeginDatestr = BeginDatestr;
    ValidEndDatestr = EndDatestr;
    ValidBMStr = BMStr;
    ValidBHStr = BHStr;
    ValidCZYStr = CZYStr;
}
//---------------------------------------------------------------------------
void __fastcall TXFTJGRExportThread::Execute()
{
	//---- Place thread code here ----
    ValidEXBTN->Enabled = false;
    ValidPreBTN->Enabled = false;
    ValidEBTN->Enabled = false;
    ValidQBTN->Enabled = false;

    Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(XFTJQFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
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
        DTX += ValidQuery->FieldByName("qdate")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("XM")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BH")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZCS")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BM")->AsAnsiString.Trim();
        DTX += "\n";
        Validprogress->Position = i*100/allrecord;
        ValidQuery->Next();
        if(ValidQuery->Eof)
            break;
    }

    Templatepath = path + "\\ExportXLSTemplate\\XFTJGRMXTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBHStr.t_str());
    ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", ValidBMStr.t_str());
    ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", ValidBeginDatestr.t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidCZYStr.t_str());
    ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
    ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", ValidEndDatestr.t_str());

    ST.OlePropertyGet("Cells",4,2).OlePropertySet("Value", ValidZZE.t_str());
    ST.OlePropertyGet("Cells",4,5).OlePropertySet("Value", ValidZZCS.t_str());

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
    MessageBox(XFTJQFrm->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    ValidEXBTN->Enabled = true;
    ValidPreBTN->Enabled = true;
    ValidEBTN->Enabled = true;
    ValidQBTN->Enabled = true;
}
//---------------------------------------------------------------------------
