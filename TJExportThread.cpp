//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TJExportThread.h"
#pragma package(smart_init)
#include "WaterQForm.h"
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TTJExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TTJExportThread::TTJExportThread(bool CreateSuspended,
											TListView *LV,
											TButton *EBTN,
                                            TcxButton *QBTN,
                                			TcxButton *ExitBTN,
											TProgressBar* probar,
											String yfstr,
											double zxf,
											String savepath) : TThread(CreateSuspended)
{
	ValidLV = LV;
	ValidEBTN = EBTN;
    ValidQBTN = QBTN;
    ValidExitBTN = ExitBTN;
	Validprobar = probar;
	Validyfstr = yfstr;
	Validzxf = zxf;
	Validsavepath = savepath;
}
//---------------------------------------------------------------------------
void __fastcall TTJExportThread::Execute()
{
	//---- Place thread code here ----
	ValidEBTN->Enabled = false;
    ValidQBTN->Enabled = false;
    ValidExitBTN->Enabled = false;
	Validprobar->Position = 0;

	Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(SKMXQFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
		return;
	}

	String DTX = "";
	String path = GlobalPath;
	String Templatepath;
	int allcount = ValidLV->Items->Count;
	for(int i = 0; i < allcount; i++)
	{
		TListItem* tmpitem = ValidLV->Items->Item[i];
		DTX += tmpitem->Caption;
		DTX += "\t";
		DTX += tmpitem->SubItems->Strings[0];
		DTX += "\n";
		Validprobar->Position = (i+1)*100/allcount;
	}

	Templatepath = path + "\\ExportXLSTemplate\\TJTemplate.xlt";
	ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
	Variant ST = WB.OlePropertyGet("Sheets", 1);

	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", Validyfstr.t_str());
	ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", Validzxf);

	Variant RE = ST.OlePropertyGet("Range", "A6").OleFunction("Select");
	Clipboard()->Clear();
	Clipboard()->SetTextBuf(DTX.c_str());
	ST.OleFunction("Paste");
	Clipboard()->Clear();

	ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
	WB.OleFunction("SaveAs", Validsavepath.t_str());
	ExcelApp.OleFunction("Quit");
	ExcelApp = Unassigned;
	MessageBox(SKMXQFrm->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);
	ValidEBTN->Enabled = true;
    ValidQBTN->Enabled = true;
    ValidExitBTN->Enabled = true;
}
//---------------------------------------------------------------------------
