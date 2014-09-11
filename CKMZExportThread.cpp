//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CKMZExportThread.h"
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
//      void __fastcall TCKMXExportThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCKMXExportThread::TCKMXExportThread(bool CreateSuspended,
                                                TADOQuery* Query,
                                                TcxProgressBar* progress,
                                                TcxButton* ExportBTN,
                                                TcxButton* PreviewBTN,
                                                String filename,
                                                String BeginTimeStr,
                                                String EndTimeStr,
                                                String KHStr,
                                                String BHStr,
                                                String JYLXStr,
                                                String CZYStr,
                                                String sqlstr,
                                                TcxCheckBox *cxCheckB1,
                                				TcxCheckBox *cxCheckB2) : TThread(CreateSuspended)
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
	ValidJYLXStr = JYLXStr;
	ValidCZYStr = CZYStr;
    Validsqlstr = sqlstr;
    cxCheckBox1 = cxCheckB1;
    cxCheckBox2 = cxCheckB2;
}
//---------------------------------------------------------------------------
void __fastcall TCKMXExportThread::Execute()
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

		DTX += ValidADOQuery->FieldByName("bh")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("kh")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("XM")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("sf_ye")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("ckje")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("sfrq")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("BM")->AsAnsiString.Trim();
        DTX += "\t";
//        DTX += ValidADOQuery->FieldByName("GZZID")->AsAnsiString;
//        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("sflx")->AsAnsiString.Trim();
        DTX += "\t";
		DTX += ValidADOQuery->FieldByName("CZY")->AsAnsiString.Trim();
//        DTX += "\t";
//        DTX += ValidADOQuery->FieldByName("SCRQ")->AsAnsiString;
        DTX += "\n";
        ValidADOQuery->Next();
    }
    ValidADOQuery->Close();

    String tmpsumsqlstr = "select sum(ckje) as sumckje ";
    int sqllength = Validsqlstr.Length();
    tmpsumsqlstr += Validsqlstr.SubString(9, sqllength-8);
//        ShowMessage(exportsqlstr.SubString(sqllength-2,3));

    double qkje = 0;
    double ckje = 0;

    if("'d'" == Validsqlstr.SubString(sqllength-2,3))
    {
        ValidADOQuery->Close();
        ValidADOQuery->SQL->Clear();
        ValidADOQuery->SQL->Add(tmpsumsqlstr);
        ValidADOQuery->Open();
        if(!ValidADOQuery->IsEmpty())
            qkje = ValidADOQuery->FieldByName("sumckje")->AsFloat;
        ValidADOQuery->Close();
    }
    else if("'a'" == Validsqlstr.SubString(sqllength-2,3)||"'p'" == Validsqlstr.SubString(sqllength-2,3))
    {
        ValidADOQuery->Close();
        ValidADOQuery->SQL->Clear();
        ValidADOQuery->SQL->Add(tmpsumsqlstr);
        ValidADOQuery->Open();
        if(!ValidADOQuery->IsEmpty())
            ckje = ValidADOQuery->FieldByName("sumckje")->AsFloat;
        ValidADOQuery->Close();
    }
    else
    {
        String tstr = tmpsumsqlstr;
        tstr += " and sflx='d'";
        ValidADOQuery->Close();
        ValidADOQuery->SQL->Clear();
        ValidADOQuery->SQL->Add(tstr);
        ValidADOQuery->Open();
        if(!ValidADOQuery->IsEmpty())
            qkje = ValidADOQuery->FieldByName("sumckje")->AsFloat;
        ValidADOQuery->Close();

        tstr = tmpsumsqlstr;
        if(cxCheckBox1->Checked&&!cxCheckBox2->Checked)
            tstr += " and sflx='a'";
        if(!cxCheckBox1->Checked&&cxCheckBox2->Checked)
            tstr += " and sflx='p'";
        if(cxCheckBox1->Checked&&cxCheckBox2->Checked)
            tstr += " and sflx='a' or sflx='p'";

        ValidADOQuery->Close();
        ValidADOQuery->SQL->Clear();
        ValidADOQuery->SQL->Add(tstr);
        ValidADOQuery->Open();
        if(!ValidADOQuery->IsEmpty())
            ckje = ValidADOQuery->FieldByName("sumckje")->AsFloat;
        ValidADOQuery->Close();
    }

    String TempPath = GlobalPath;

	TempPath += "\\ExportTemplate\\CKMXTemplate.xlt";

    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", TempPath.t_str());

	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");

    Variant ST = WB.OlePropertyGet("Sheets", 1);

	ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", ValidBeginTimeStr.t_str());
    ST.OlePropertyGet("Cells",2,7).OlePropertySet("Value", ValidEndTimeStr.t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", ValidKHStr.t_str());
    ST.OlePropertyGet("Cells",3,7).OlePropertySet("Value", ValidBHStr.t_str());

    ST.OlePropertyGet("Cells",4,2).OlePropertySet("Value", ValidJYLXStr.t_str());
	ST.OlePropertyGet("Cells",4,7).OlePropertySet("Value", ValidCZYStr.t_str());
    String tmpoutstr = "￥"+FloatToStr(ckje);
	ST.OlePropertyGet("Cells",5,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+FloatToStr(-qkje);
	ST.OlePropertyGet("Cells",5,7).OlePropertySet("Value", tmpoutstr.t_str());

	Variant RE = ST.OlePropertyGet("Range", "A8").OleFunction("Select");
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
