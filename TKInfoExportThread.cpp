//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TKInfoExportThread.h"
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
//      void __fastcall TTkInfoExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TTkInfoExportThread::TTkInfoExportThread(bool CreateSuspended,
													TADOQuery* Query,
                                                    TcxButton* ExportBTN,
                                                    TcxButton* PreviewBTN,
                                                    String filename,
                                                    String BeginTimeStr,
                                                    String EndTimestr) : TThread(CreateSuspended)
{
	ValidADOQuery = Query;
    ValidExportBTN = ExportBTN;
    ValidPreviewBTN = PreviewBTN;
    Validfilename = filename;
    ValidBeginTimeStr = BeginTimeStr;
    ValidEndTimeStr = EndTimestr;
}
//---------------------------------------------------------------------------
void __fastcall TTkInfoExportThread::Execute()
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
    ValidADOQuery->First();
    while(!ValidADOQuery->Eof)
    {
		DTX += ValidADOQuery->FieldByName("BH")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("KH")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("XM")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SF_YE")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("TKCB")->AsAnsiString.Trim();
        DTX += "\t";
//		DTX += ValidADOQuery->FieldByName("BKCB")->AsAnsiString.Trim();
//        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("TKOperator")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("ZW")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("BZ")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidADOQuery->FieldByName("TKRQ")->AsAnsiString.Trim();
        DTX += "\n";
        ValidADOQuery->Next();
    }

    String TempPath = GlobalPath;

	TempPath += "\\ExportTemplate\\TKInfoTemplate.xlt";

    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", TempPath.t_str());

	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");

    Variant ST = WB.OlePropertyGet("Sheets", 1);

	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBeginTimeStr.t_str());
    ST.OlePropertyGet("Cells",2,7).OlePropertySet("Value", ValidEndTimeStr.t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", "退卡信息");
    ST.OlePropertyGet("Cells",3,7).OlePropertySet("Value", OperatorName.t_str());


	Variant RE = ST.OlePropertyGet("Range", "A6").OleFunction("Select");
   	Clipboard()->Clear();
    Clipboard()->SetTextBuf(DTX.c_str());
    ST.OleFunction("Paste");
    Clipboard()->Clear();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");

    WB.OleFunction("SaveAs", Validfilename.t_str());

    ExcelApp.OleFunction("Quit");

    ExcelApp = Unassigned;

    ValidADOQuery->Close();

    ValidExportBTN->Enabled = true;
    ValidPreviewBTN->Enabled = true;
    MessageBox(SDIAppForm->Handle, "数据导出完毕!", "Successfully!", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
