//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFTJALLExportThread.h"
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
//      void __fastcall TXFTJALLExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TXFTJALLExportThread::TXFTJALLExportThread(bool CreateSuspended,
                                                    TcxProgressBar* progress,
                                                    TADOQuery* Query,
                                                    TcxButton* EXBTN,
                                                    TcxButton* PreBTN,
                                                    TcxButton* EBTN,
                                                    TcxButton* QBTN,
                                                    String ZZE,
                                                    String ZZCS,
                                                    String BZE,
                                                    String BZCS,
                                                    String LZE,
                                                    String LZCS,
                                                    String SZE,
                                                    String SZCS,
                                                    String NZE,
                                                    String NZCS,
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
    ValidBZE = BZE;
    ValidBZCS = BZCS;
    ValidLZE = LZE;
    ValidLZCS = LZCS;
    ValidSZE = SZE;
    ValidSZCS = SZCS;
    ValidNZE = NZE;
    ValidNZCS = NZCS;
    Validsavepath = savepath;
    ValidBeginDatestr = BeginDatestr;
    ValidEndDatestr = EndDatestr;
    ValidBMStr = BMStr;
    ValidBHStr = BHStr;
    ValidCZYStr = CZYStr;
}
//---------------------------------------------------------------------------
void __fastcall TXFTJALLExportThread::Execute()
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
        DTX += ValidQuery->FieldByName("ZSFZE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZSFCS")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BFSFZE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("BFCS")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("LHSFZE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("LHCS")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SUSFZE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("SUCS")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("NTSFZE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("NTCS")->AsAnsiString.Trim();
        DTX += "\n";
        Validprogress->Position = i*100/allrecord;
        ValidQuery->Next();
        if(ValidQuery->Eof)
            break;
    }

    Templatepath = path + "\\ExportXLSTemplate\\XFTJALLMXTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBHStr.t_str());
    ST.OlePropertyGet("Cells",2,5).OlePropertySet("Value", ValidBMStr.t_str());
    ST.OlePropertyGet("Cells",2,9).OlePropertySet("Value", ValidBeginDatestr.t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidCZYStr.t_str());
    ST.OlePropertyGet("Cells",3,5).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
    ST.OlePropertyGet("Cells",3,9).OlePropertySet("Value", ValidEndDatestr.t_str());

    ST.OlePropertyGet("Cells",5,2).OlePropertySet("Value", ValidZZE.t_str());
    ST.OlePropertyGet("Cells",6,2).OlePropertySet("Value", ValidZZCS.t_str());

    ST.OlePropertyGet("Cells",5,4).OlePropertySet("Value", ValidBZE.t_str());
    ST.OlePropertyGet("Cells",6,4).OlePropertySet("Value", ValidBZCS.t_str());

    ST.OlePropertyGet("Cells",5,6).OlePropertySet("Value", ValidLZE.t_str());
    ST.OlePropertyGet("Cells",6,6).OlePropertySet("Value", ValidLZCS.t_str());

    ST.OlePropertyGet("Cells",5,8).OlePropertySet("Value", ValidSZE.t_str());
    ST.OlePropertyGet("Cells",6,8).OlePropertySet("Value", ValidSZCS.t_str());

    ST.OlePropertyGet("Cells",5,10).OlePropertySet("Value", ValidNZE.t_str());
    ST.OlePropertyGet("Cells",6,10).OlePropertySet("Value", ValidNZCS.t_str());

    Variant RE = ST.OlePropertyGet("Range", "A9").OleFunction("Select");
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
