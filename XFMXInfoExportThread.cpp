//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFMXInfoExportThread.h"
#include "XFMXShowForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TXFMXInfoExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TXFMXInfoExportThread::TXFMXInfoExportThread(bool CreateSuspended,
                                						TcxProgressBar* progress,
                                                        TADOQuery* Query,
                                                        TcxButton* EXBTN,
                                                        TcxButton* PreBTN,
                                                        TcxButton* EBTN,
                                                        String savepath,
                                                        String BeginDatestr,
                                                        String EndDatestr,
                                                        String KHstr,
                                                        String BHstr,
														String AllXFstr,
														String AllCSstr,
                                                        String BMstr,
                                                        String BBstr,
                                                        String ZBstr,
                                                        String XMstr,
                                                        String JHstr,
                                                        String CTstr,
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
    ValidKHstr = KHstr;
    ValidBHstr = BHstr;
	ValidAllXFstr = AllXFstr;
	ValidAllCSstr = AllCSstr;
    ValidBMstr = BMstr;
    ValidBBstr  = BBstr;
    ValidZBstr = ZBstr;
    ValidXMstr = XMstr;
    ValidJHstr = JHstr;
    ValidCTstr = CTstr;
    ValidCZYstr = CZYstr;
}
//---------------------------------------------------------------------------
void __fastcall TXFMXInfoExportThread::Execute()
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
		MessageBox(XFMXShowFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
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
        DTX += ValidQuery->FieldByName("BANBIE")->AsAnsiString.Trim();
        DTX += "\t";
        DTX += ValidQuery->FieldByName("ZUBIE")->AsAnsiString.Trim();
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

    Templatepath = path + "\\ExportXLSTemplate\\XFMXTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    String tmpoutstr = "";
    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidKHstr.t_str());
    ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", ValidBHstr.t_str());
    ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", ValidBMstr.t_str());
    ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", ValidBBstr.t_str());
    tmpoutstr = "￥" + ValidAllXFstr;
    ST.OlePropertyGet("Cells",2,10).OlePropertySet("Value", tmpoutstr.t_str());
    ST.OlePropertyGet("Cells",2,12).OlePropertySet("Value", ValidBeginDatestr.t_str());
    ST.OlePropertyGet("Cells",2,14).OlePropertySet("Value", DateTimeToStr(Now()).t_str());

    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidJHstr.t_str());
    ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", ValidCTstr.t_str());
	ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", ValidXMstr.t_str());
    ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", ValidZBstr.t_str());
	ST.OlePropertyGet("Cells",3,10).OlePropertySet("Value", ValidAllCSstr.t_str());
	ST.OlePropertyGet("Cells",3,12).OlePropertySet("Value", ValidCZYstr.t_str());
	ST.OlePropertyGet("Cells",3,14).OlePropertySet("Value", ValidEndDatestr.t_str());

    Variant RE = ST.OlePropertyGet("Range", "A7").OleFunction("Select");
    Clipboard()->Clear();
    Clipboard()->SetTextBuf(DTX.c_str());
    ST.OleFunction("Paste");
    Clipboard()->Clear();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
    WB.OleFunction("SaveAs", Validsavepath.t_str());
    ExcelApp.OleFunction("Quit");
    ExcelApp = Unassigned;
    Validprogress->Position = 100;
    MessageBox(XFMXShowFrm->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    ValidEXBTN->Enabled = true;
    ValidPreBTN->Enabled = true;
    ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------
