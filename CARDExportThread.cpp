//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CARDExportThread.h"
#include "CARDShowForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCARDExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCARDExportThread::TCARDExportThread(bool CreateSuspended,
                                                TcxProgressBar* progress,
                                             	TADOQuery* Query,
                                             	TcxButton* EXBTN,
                                             	TcxButton* PreBTN,
                                            	TcxButton* EBTN,
                                             	String savepath,
												String KHstr,
                                                String BHstr,
                                                String XMstr,
                                                String BMstr,
                                                String BBstr,
                                                String ZBstr,
                                                String CZYstr) : TThread(CreateSuspended)
{
	Validprogress = progress;
    ValidQuery = Query;
    ValidEXBTN = EXBTN;
    ValidPreBTN = PreBTN;
    ValidEBTN = EBTN;
    Validsavepath = savepath;
    ValidKHstr = KHstr;
    ValidBHstr = BHstr;
    ValidXMstr = XMstr;
    ValidBMstr = BMstr;
    ValidBBstr = BBstr;
    ValidZBstr = ZBstr;
    ValidCZYstr = CZYstr;
}
//---------------------------------------------------------------------------
void __fastcall TCARDExportThread::Execute()
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
		MessageBox(CARDShowFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
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
        DTX += ValidQuery->FieldByName("XM")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SF_YE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("XB")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BM")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BZ")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZB")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZW")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZT")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("RQ")->AsAnsiString.Trim();
        DTX += "\n";
        Validprogress->Position = i*100/allrecord;
        ValidQuery->Next();
        if(ValidQuery->Eof)
            break;
    }

    Templatepath = path + "\\ExportXLSTemplate\\CARDTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    String tmpoutstr = "";
    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidKHstr.t_str());
    ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", ValidBHstr.t_str());
    ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", ValidXMstr.t_str());
    ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", DateTimeToStr(Now()).t_str());

    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidBMstr.t_str());
    ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", ValidBBstr.t_str());
    ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", ValidZBstr.t_str());
    ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", ValidCZYstr.t_str());

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
    MessageBox(CARDShowFrm->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    ValidEXBTN->Enabled = true;
    ValidPreBTN->Enabled = true;
    ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------
