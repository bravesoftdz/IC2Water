//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BTMXExportThread.h"
#include "GlobalParameter.h"
#include "SDIMAIN.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TBTMXExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TBTMXExportThread::TBTMXExportThread(bool CreateSuspended,
												TADOQuery* Query,
												TcxProgressBar* progress,
												TcxButton* ExportBTN,
												TcxButton* PreviewBTN,
												String filename,
												String BeginTimeStr,
												String EndTimeStr,
												String KHStr,
												String BHStr,
												String JHStr,
												String DDStr) : TThread(CreateSuspended)
{
	ValidADOQuery = Query;
    Validprogress = progress;
    ValidExportBTN = ExportBTN;
    ValidPreviewBTN = PreviewBTN;
    Validfilename = filename;
	ValidBeginTimeStr = BeginTimeStr;
    ValidEndTimeStr = EndTimeStr;
    ValidKHStr = KHStr;
    ValidBHStr = BHStr;
    ValidJHStr = JHStr;
    ValidDDStr = DDStr;
}
//---------------------------------------------------------------------------
void __fastcall TBTMXExportThread::Execute()
{
	//---- Place thread code here ----
    ValidExportBTN->Enabled = false;
    ValidPreviewBTN->Enabled = false;

	Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(SDIAppForm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
		ValidExportBTN->Enabled = true;
		ValidPreviewBTN->Enabled = true;
		return;
	}

    String DTX = "";
//    ValidADOQuery->Open();
    ValidADOQuery->First();

    int allcount = ValidADOQuery->RecordCount;
    int currentcount = 0;
    Validprogress->Position = 0;

    while(!ValidADOQuery->Eof)
    {
        Validprogress->Position = currentcount*100/allcount;
        currentcount++;

		DTX += ValidADOQuery->FieldByName("BH")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("KH")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SF_YE")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SFJE")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SYCS")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SFRQ")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("JYNO")->AsAnsiString.Trim();
        DTX += "\t";
//        DTX += ValidADOQuery->FieldByName("GZZID")->AsAnsiString;
//        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SFLX")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("CZY")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SCRQ")->AsAnsiString.Trim();
        DTX += "\n";
        ValidADOQuery->Next();
    }

    String TempPath = GlobalPath;

    TempPath += "\\ExportTemplate\\BTMXTemplate.xlt";

    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", TempPath.t_str());

	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");

    Variant ST = WB.OlePropertyGet("Sheets", 1);

    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBeginTimeStr.t_str());
    ST.OlePropertyGet("Cells",2,7).OlePropertySet("Value", ValidEndTimeStr.t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidKHStr.t_str());
    ST.OlePropertyGet("Cells",3,7).OlePropertySet("Value", ValidBHStr.t_str());
    ST.OlePropertyGet("Cells",4,2).OlePropertySet("Value", ValidJHStr.t_str());
    ST.OlePropertyGet("Cells",4,7).OlePropertySet("Value", ValidDDStr.t_str());

    Variant RE = ST.OlePropertyGet("Range", "A7").OleFunction("Select");
   	Clipboard()->Clear();
    Clipboard()->SetTextBuf(DTX.c_str());
    ST.OleFunction("Paste");
    Clipboard()->Clear();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");

    WB.OleFunction("SaveAs", Validfilename.t_str());

    ExcelApp.OleFunction("Quit");

    ExcelApp = Unassigned;

    ValidADOQuery->Close();
    Validprogress->Position = 100;
    ValidExportBTN->Enabled = true;
    ValidPreviewBTN->Enabled = true;
	MessageBox(SDIAppForm->Handle, "数据导出完毕!", "Successfully!", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
