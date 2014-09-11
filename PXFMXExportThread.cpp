//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PXFMXExportThread.h"
#include "GlobalParameter.h"
#include "SDIMAIN.h"
#include "PXFMXShowForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall PXFMXInfoExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall PXFMXInfoExportThread::PXFMXInfoExportThread(bool CreateSuspended,
														TADOQuery* Query,
														TcxProgressBar* progress,
														TcxButton* ExportBTN,
														TcxButton* PreviewBTN,
														String filename,
														String BeginTimeStr,
														String EndTimeStr,
														String KHStr,
														String XMStr,
														String XFZEStr,
														String XFZCSStr,
														String CZZEStr,
														String CZZCSStr,
														String QKZEStr,
														String QKZCSStr,
														String czystr) : TThread(CreateSuspended)
{
	ValidADOQuery = Query;
    Validprogress = progress;
    ValidExportBTN = ExportBTN;
    ValidPreviewBTN = PreviewBTN;
    Validfilename = filename;
	ValidBeginTimeStr = BeginTimeStr;
    ValidEndTimeStr = EndTimeStr;
    ValidKHStr = KHStr;
	ValidXMStr = XMStr;
	ValidXFZEStr = XFZEStr;
	ValidXFZCSStr = XFZCSStr;
	ValidCZZEStr = CZZEStr;
	ValidCZZCSStr = CZZCSStr;
	ValidQKZEStr = QKZEStr;
	ValidQKZCSStr = QKZCSStr;
	Validczystr = czystr;
}
//---------------------------------------------------------------------------
void __fastcall PXFMXInfoExportThread::Execute()
{
	//---- Place thread code here ----
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
		MessageBox(PXFMXShowFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
		ValidExportBTN->Enabled = true;
		ValidPreviewBTN->Enabled = true;
		return;
	}

    String DTX = "";
    ValidADOQuery->Open();
    ValidADOQuery->First();

	int allcount = ValidADOQuery->RecordCount;
    int currentcount = 0;
    Validprogress->Position = 0;

    while(!ValidADOQuery->Eof)
    {
        Validprogress->Position = currentcount*100/allcount;
		currentcount++;

		DTX += ValidADOQuery->FieldByName("KH")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("BH")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("XM")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("BM")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("ZW")->AsAnsiString.Trim();
		DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SF_YE")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SFJE")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SYCS")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("JYNO")->AsAnsiString.Trim();
		DTX += "\t";
//		DTX += ValidADOQuery->FieldByName("CTNAME")->AsAnsiString.Trim();
//		DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SFLX")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("SFRQ")->AsAnsiString.Trim();
        DTX += "\n";
		Validprogress->Position = currentcount*100/allcount;
        ValidADOQuery->Next();
	}

    String TempPath = GlobalPath;

    TempPath += "\\ExportXLSTemplate\\PXFMXTemplate.xlt";

    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", TempPath.t_str());

	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");

    Variant ST = WB.OlePropertyGet("Sheets", 1);

	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidKHStr.t_str());
	ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", ValidXFZEStr.t_str());
	ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", ValidCZZEStr.t_str());
	ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", ValidQKZEStr.t_str());
	ST.OlePropertyGet("Cells",2,10).OlePropertySet("Value", ValidBeginTimeStr.t_str());
	ST.OlePropertyGet("Cells",2,12).OlePropertySet("Value", ValidEndTimeStr.t_str());
	ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidXMStr.t_str());
	ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", ValidXFZCSStr.t_str());
	ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", ValidCZZCSStr.t_str());
	ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", ValidQKZCSStr.t_str());
	ST.OlePropertyGet("Cells",3,10).OlePropertySet("Value", Validczystr.t_str());
    ST.OlePropertyGet("Cells",3,12).OlePropertySet("Value", DateTimeToStr(Now()).t_str());

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
    Validprogress->Position = 100;
    ValidExportBTN->Enabled = true;
    ValidPreviewBTN->Enabled = true;
	MessageBox(PXFMXShowFrm->Handle, "数据导出完毕!", "Successfully!", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
