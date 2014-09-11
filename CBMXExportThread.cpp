//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CBMXExportThread.h"
#include "CBMXShowForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCBMXExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCBMXExportThread::TCBMXExportThread(bool CreateSuspended,
												TcxProgressBar* progress,
                                                TADOQuery* Query,
                                                TcxButton* EXBTN,
                                                TcxButton* PreBTN,
                                                TcxButton* EBTN,
                                                String savepath,
                                                String BeginDatestr,
                                                String EndDatestr,
                                                String CTNamestr,
                                                bool bftag,
                                                bool lhtag,
                                                bool srtag,
                                                bool nttag,
                                                double bfze,
                                                int bfcs,
                                                double lhze,
                                                int lhcs,
                                                double srze,
                                                int srcs,
                                                double ntze,
                                                int ntcs,
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
    ValidCTNamestr = CTNamestr;
    Validbftag = bftag;
    Validlhtag = lhtag;
    Validsrtag = srtag;
    Validnttag = nttag;
    Validbfze = bfze;
    Validbfcs = bfcs;
    Validlhze = lhze;
    Validlhcs = lhcs;
    Validsrze = srze;
    Validsrcs = srcs;
    Validntze = ntze;
    Validntcs = ntcs;
    ValidCZYstr = CZYstr;
}
//---------------------------------------------------------------------------
void __fastcall TCBMXExportThread::Execute()
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
		MessageBox(CBMXShowFrm->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
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

    Templatepath = path + "\\ExportXLSTemplate\\CBMXTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    String tmpoutstr = "￥";
    String outstr = "";
    if(!Validbftag)
    {
    	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", "N");
        ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", 0);
        outstr = tmpoutstr+"0";
        ST.OlePropertyGet("Cells",4,2).OlePropertySet("Value", outstr.t_str());
    }
    else
    {
    	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", "Y");
        ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", Validbfcs);
        outstr = tmpoutstr+Validbfze;
        ST.OlePropertyGet("Cells",4,2).OlePropertySet("Value", outstr.t_str());
    }

    if(!Validlhtag)
    {
    	ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", "N");
        ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", 0);
        outstr = tmpoutstr+"0";
        ST.OlePropertyGet("Cells",4,4).OlePropertySet("Value", outstr.t_str());
    }
    else
    {
    	ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", "Y");
        ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", Validlhcs);
        outstr = tmpoutstr+Validlhze;
        ST.OlePropertyGet("Cells",4,4).OlePropertySet("Value", outstr.t_str());
    }

    if(!Validsrtag)
    {
    	ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", "N");
        ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", 0);
        outstr = tmpoutstr+"0";
        ST.OlePropertyGet("Cells",4,6).OlePropertySet("Value", outstr.t_str());
    }
    else
    {
    	ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", "Y");
        ST.OlePropertyGet("Cells",3,6).OlePropertySet("Value", Validsrcs);
        outstr = tmpoutstr+Validsrze;
        ST.OlePropertyGet("Cells",4,6).OlePropertySet("Value", outstr.t_str());
    }

    if(!Validnttag)
    {
    	ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", "N");
        ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", 0);
        outstr = tmpoutstr+"0";
        ST.OlePropertyGet("Cells",4,8).OlePropertySet("Value", outstr.t_str());
    }
    else
    {
    	ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", "Y");
        ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", Validntcs);
        outstr = tmpoutstr+Validntze;
        ST.OlePropertyGet("Cells",4,8).OlePropertySet("Value", outstr.t_str());
    }

    ST.OlePropertyGet("Cells",2,10).OlePropertySet("Value", ValidCTNamestr.t_str());
    ST.OlePropertyGet("Cells",3,10).OlePropertySet("Value", Validbfcs+Validlhcs+Validsrcs+Validntcs);
    outstr = tmpoutstr+(Validbfze+Validlhze+Validsrze+Validntze);
    ST.OlePropertyGet("Cells",4,10).OlePropertySet("Value", outstr.t_str());

    ST.OlePropertyGet("Cells",2,12).OlePropertySet("Value", ValidBeginDatestr.t_str());
    ST.OlePropertyGet("Cells",3,12).OlePropertySet("Value", ValidEndDatestr.t_str());
    ST.OlePropertyGet("Cells",4,12).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
    ST.OlePropertyGet("Cells",5,12).OlePropertySet("Value", ValidCZYstr.t_str());

    Variant RE = ST.OlePropertyGet("Range", "A8").OleFunction("Select");
    Clipboard()->Clear();
    Clipboard()->SetTextBuf(DTX.c_str());
    ST.OleFunction("Paste");
    Clipboard()->Clear();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
    WB.OleFunction("SaveAs", Validsavepath.t_str());
    ExcelApp.OleFunction("Quit");
    ExcelApp = Unassigned;
    Validprogress->Position = 100;
    MessageBox(CBMXShowFrm->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    ValidEXBTN->Enabled = true;
    ValidPreBTN->Enabled = true;
    ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------
