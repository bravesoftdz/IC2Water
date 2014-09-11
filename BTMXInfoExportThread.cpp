//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BTMXInfoExportThread.h"
#include "BTMXShowForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TBTMXInfoExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TBTMXInfoExportThread::TBTMXInfoExportThread(bool CreateSuspended,
                                						TcxProgressBar* progress,
                                                        TADOQuery* Query,
                                                        TcxButton* EXBTN,
                                                        TcxButton* PreBTN,
                                                        TcxButton* EBTN,
                                                        String savepath,
                                                        String BeginDatestr,
														String EndDatestr,
														String AllXFstr,
														String AllCSstr,
														int qtag,
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
    Validqtag = qtag;
	ValidCZYstr = CZYstr;
	ValidAllXFstr = AllXFstr;
	ValidAllCSstr = AllCSstr;
}
//---------------------------------------------------------------------------
void __fastcall TBTMXInfoExportThread::Execute()
{
	//---- Place thread code here ----
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
		MessageBox(BTMXShowFRM->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
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
        DTX += ValidQuery->FieldByName("KH")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BH")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("UName")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BUMEN")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZW")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SF_YE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SFJE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SYCS")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("JYNO")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("CTNAME")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SFLX")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SFRQ")->AsAnsiString.Trim();
        DTX += "\n";
        Validprogress->Position = i*100/allrecord;
        ValidQuery->Next();
        if(ValidQuery->Eof)
            break;
    }

	if(0 == Validqtag)
		Templatepath = path + "\\ExportXLSTemplate\\BTXMXTemplate.xlt";
	if(1 == Validqtag)
		Templatepath = path + "\\ExportXLSTemplate\\BTDMXTemplate.xlt";

    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    String tmpoutstr = "";
	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBeginDatestr.t_str());
	ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", ValidEndDatestr.t_str());
	ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", ValidAllCSstr.t_str());
    tmpoutstr = "￥" + ValidAllXFstr;
    ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", tmpoutstr.t_str());
	ST.OlePropertyGet("Cells",2,10).OlePropertySet("Value", ValidCZYstr.t_str());
	ST.OlePropertyGet("Cells",2,12).OlePropertySet("Value", DateTimeToStr(Now()).t_str());

    Variant RE = ST.OlePropertyGet("Range", "A5").OleFunction("Select");
    Clipboard()->Clear();
    Clipboard()->SetTextBuf(DTX.c_str());
    ST.OleFunction("Paste");
    Clipboard()->Clear();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
    WB.OleFunction("SaveAs", Validsavepath.t_str());
    ExcelApp.OleFunction("Quit");
    ExcelApp = Unassigned;
    Validprogress->Position = 100;
	MessageBox(BTMXShowFRM->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    ValidEXBTN->Enabled = true;
    ValidPreBTN->Enabled = true;
	ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------
