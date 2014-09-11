//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CTQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinValentine"
#pragma link "dxSkinXmas2008Blue"
#pragma link "frxClass"
#pragma resource "*.dfm"
TCTQFrm *CTQFrm;
//---------------------------------------------------------------------------
__fastcall TCTQFrm::TCTQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCTQFrm::CTBeginDateEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TCTQFrm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TCTQFrm::QueryBTNClick(TObject *Sender)
{
    if(!CTBeginDateEdit->Text.IsEmpty()&&!CTEndDateEdit->Text.IsEmpty())
    {
        //查询所有消费
        BeginDatestr = CTBeginDateEdit->Text;
        EndDatestr = CTEndDateEdit->Text;
        CTStr = CTComboBox->Text;
        String Allsqlstr = "select sum(SFJE) as allsfje,count(*) as allcount from MXBAK join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x' and";
        if(CTComboBox->Text!="所有餐厅" && !CTComboBox->Text.IsEmpty())
        {
            Allsqlstr += " SFJPARAM.STNAME='";
            Allsqlstr += CTComboBox->Text;
            Allsqlstr += "' and SFRQ>='";
            Allsqlstr += CTBeginDateEdit->Text;
            Allsqlstr += " 00:00:00' and SFRQ<='";
            Allsqlstr += CTEndDateEdit->Text;
            Allsqlstr += " 23:59:59'";

            CTADOQ->Close();
            CTADOQ->SQL->Clear();
            CTADOQ->SQL->Add(Allsqlstr);
            CTADOQ->Open();
            ALLZE = CTADOQ->FieldByName("allsfje")->AsFloat;
            ALLCS = CTADOQ->FieldByName("allcount")->AsInteger;
            CTADOQ->Close();
        }
        else
        {
            Allsqlstr += " SFRQ>='";
            Allsqlstr += CTBeginDateEdit->Text;
            Allsqlstr += " 00:00:00' and SFRQ<='";
            Allsqlstr += CTEndDateEdit->Text;
            Allsqlstr += " 23:59:59'";

            CTADOQ->Close();
            CTADOQ->SQL->Clear();
            CTADOQ->SQL->Add(Allsqlstr);
            CTADOQ->Open();
            ALLZE = CTADOQ->FieldByName("allsfje")->AsFloat;
            ALLCS = CTADOQ->FieldByName("allcount")->AsInteger;
            CTADOQ->Close();
        }

        cxTextEdit17->Text = ALLCS;
        cxTextEdit18->Text = "￥" + FloatToStr(ALLZE);
        if(ALLCS)
        	cxTextEdit19->Text = "￥" + FloatToStr(ALLZE/ALLCS);
        else
            cxTextEdit19->Text = "￥0";

        cxTextEdit20->Text = "查询";

        String tempsqlstr = "select sum(SFJE) as fcsfje,count(*) as fccount from MXBAK join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x' and";
        if(CTComboBox->Text!="所有餐厅" && !CTComboBox->Text.IsEmpty())
        {
            tempsqlstr += " SFJPARAM.STNAME='";
            tempsqlstr += CTComboBox->Text;
            tempsqlstr += "' and SFRQ>='";
            tempsqlstr += CTBeginDateEdit->Text;
            tempsqlstr += " 00:00:00' and SFRQ<='";
            tempsqlstr += CTEndDateEdit->Text;
            tempsqlstr += " 23:59:59' and";
        }
        else
        {
            tempsqlstr += " SFRQ>='";
            tempsqlstr += CTBeginDateEdit->Text;
            tempsqlstr += " 00:00:00' and SFRQ<='";
            tempsqlstr += CTEndDateEdit->Text;
            tempsqlstr += " 23:59:59' and";
        }

        if(CheckBox1->Checked)
        {
            String BFsqlstr = tempsqlstr;
            BFsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            BFsqlstr += BFendtime;
            BFsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            BFsqlstr += BFstarttime;
            BFsqlstr += "')";

            CTADOQ->Close();
            CTADOQ->SQL->Clear();
            CTADOQ->SQL->Add(BFsqlstr);
            CTADOQ->Open();
            BFCS = CTADOQ->FieldByName("fccount")->AsInteger;
            BFZE = CTADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit4->Text = "查询";
            cxTextEdit1->Text = IntToStr(BFCS);
            cxTextEdit2->Text = "￥" + FloatToStr(BFZE);
            if(BFCS)
                cxTextEdit3->Text = "￥" + FloatToStr(BFZE/BFCS);
            else
                cxTextEdit3->Text = "￥0";
        }
        else
        {
            cxTextEdit4->Text = "未查询";
            cxTextEdit1->Text = 0;
            cxTextEdit2->Text = "￥0";
            cxTextEdit3->Text = "￥0";
        }

        if(CheckBox2->Checked)
        {
            String LHsqlstr = tempsqlstr;
            LHsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            LHsqlstr += LHendtime;
            LHsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            LHsqlstr += LHstarttime;
            LHsqlstr += "')";

            CTADOQ->Close();
            CTADOQ->SQL->Clear();
            CTADOQ->SQL->Add(LHsqlstr);
            CTADOQ->Open();
            LHCS = CTADOQ->FieldByName("fccount")->AsInteger;
            LHZE = CTADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit8->Text = "查询";
            cxTextEdit5->Text = IntToStr(LHCS);
            cxTextEdit6->Text = "￥" + FloatToStr(LHZE);
            if(LHCS)
                cxTextEdit7->Text = "￥" + FloatToStr(LHZE/LHCS);
            else
                cxTextEdit7->Text = "￥0";
        }
        else
        {
            cxTextEdit8->Text = "未查询";
            cxTextEdit5->Text = 0;
            cxTextEdit6->Text = "￥0";
            cxTextEdit7->Text = "￥0";
        }

        if(CheckBox3->Checked)
        {
            String SRsqlstr = tempsqlstr;
            SRsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            SRsqlstr += SRendtime;
            SRsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            SRsqlstr += SRstarttime;
            SRsqlstr += "')";

            CTADOQ->Close();
            CTADOQ->SQL->Clear();
            CTADOQ->SQL->Add(SRsqlstr);
            CTADOQ->Open();
            SRCS = CTADOQ->FieldByName("fccount")->AsInteger;
            SRZE = CTADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit12->Text = "查询";
            cxTextEdit9->Text = IntToStr(SRCS);
            cxTextEdit10->Text = "￥" + FloatToStr(SRZE);
            if(SRCS)
                cxTextEdit11->Text = "￥" + FloatToStr(SRZE/SRCS);
            else
                cxTextEdit11->Text = "￥0";
        }
        else
        {
            cxTextEdit12->Text = "未查询";
            cxTextEdit9->Text = 0;
            cxTextEdit10->Text = "￥0";
            cxTextEdit11->Text = "￥0";
        }

        if(CheckBox4->Checked)
        {
            String NTsqlstr = tempsqlstr;
            NTsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            NTsqlstr += NTendtime;
            NTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            NTsqlstr += NTstarttime;
            NTsqlstr += "')";

            CTADOQ->Close();
            CTADOQ->SQL->Clear();
            CTADOQ->SQL->Add(NTsqlstr);
            CTADOQ->Open();
            NTCS = CTADOQ->FieldByName("fccount")->AsInteger;
            NTZE = CTADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit16->Text = "查询";
            cxTextEdit13->Text = IntToStr(NTCS);
            cxTextEdit14->Text = "￥" + FloatToStr(NTZE);
            if(NTCS)
                cxTextEdit15->Text = "￥" + FloatToStr(NTZE/NTCS);
            else
                cxTextEdit15->Text = "￥0";
        }
        else
        {
            cxTextEdit16->Text = "未查询";
            cxTextEdit13->Text = 0;
            cxTextEdit14->Text = "￥0";
            cxTextEdit15->Text = "￥0";
        }

        if(BFZE||LHZE||SRZE||NTZE||ALLZE)
        {
            ExportBTN->Enabled = true;
            PreviewBTN->Enabled = true;
        }
    }
    else
    	ShowMessage("必须完整填写查询起止时间!");
}
//---------------------------------------------------------------------------
void __fastcall TCTQFrm::FormShow(TObject *Sender)
{
	QueryBTN->Enabled = false;
    CheckBox1->Checked = true;
    CheckBox2->Checked = true;
    CheckBox3->Checked = true;
    CheckBox4->Checked = true;
    cxTextEdit1->Text = "";
    cxTextEdit2->Text = "";
    cxTextEdit3->Text = "";
    cxTextEdit4->Text = "";
    cxTextEdit5->Text = "";
    cxTextEdit6->Text = "";
    cxTextEdit7->Text = "";
    cxTextEdit8->Text = "";
    cxTextEdit9->Text = "";
    cxTextEdit10->Text = "";
    cxTextEdit11->Text = "";
    cxTextEdit12->Text = "";
    cxTextEdit13->Text = "";
    cxTextEdit14->Text = "";
    cxTextEdit15->Text = "";
    cxTextEdit16->Text = "";
    cxTextEdit17->Text = "";
    cxTextEdit18->Text = "";
    cxTextEdit19->Text = "";
    cxTextEdit20->Text = "";
//    CTBeginDateEdit->Text = "";
//    CTEndDateEdit->Text = "";

	CTBeginDateEdit->Date = Date();
	CTEndDateEdit->Date = Date();
    BFtag = false;
    LHtag = false;
    SRtag = false;
    NTtag = false;

    BFCS = 0;
    BFZE = 0;
    LHCS = 0;
    LHZE = 0;
    SRCS = 0;
    SRZE = 0;
    NTCS = 0;
    NTZE = 0;
    ALLCS = 0;
    ALLZE = 0;

    ExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;

    CTADOQ->Close();
    CTADOQ->SQL->Clear();
    CTADOQ->SQL->Add("select * from STNAME");
    CTADOQ->Open();
    if(!CTADOQ->IsEmpty())
    {
        CTADOQ->First();
        CTComboBox->Properties->Items->Clear();
        while(!CTADOQ->Eof)
        {
        	CTComboBox->Properties->Items->Add(CTADOQ->FieldByName("STNAME")->AsString.Trim());
            CTADOQ->Next();
        }
        CTComboBox->Properties->Items->Add("所有餐厅");
        CTComboBox->ItemIndex = -1;
    }
    CTADOQ->Close();
    CTADOQ->SQL->Clear();
    CTADOQ->SQL->Add("select * from SUBMEALINFO");
    CTADOQ->Open();
    if(!CTADOQ->IsEmpty())
    {
    	if(CTADOQ->FieldByName("breakfaststart")->AsDateTime<"10:00:00")
			BFstarttime = CTADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();
        else
        	BFstarttime = CTADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();

		if(CTADOQ->FieldByName("breakfastend")->AsDateTime<"10:00:00")
			BFendtime = CTADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();
        else
            BFendtime = CTADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();

        if(CTADOQ->FieldByName("lunchstart")->AsDateTime<"10:00:00")
			LHstarttime = CTADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();
        else
        	LHstarttime = CTADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();

        if(CTADOQ->FieldByName("lunchend")->AsDateTime<"10:00:00")
			LHendtime = CTADOQ->FieldByName("lunchend")->AsDateTime.TimeString();
        else
        	LHendtime = CTADOQ->FieldByName("lunchend")->AsDateTime.TimeString();

        if(CTADOQ->FieldByName("supperstart")->AsDateTime<"10:00:00")
			SRstarttime = CTADOQ->FieldByName("supperstart")->AsDateTime.TimeString();
        else
            SRstarttime = CTADOQ->FieldByName("supperstart")->AsDateTime.TimeString();

        if(CTADOQ->FieldByName("supperend")->AsDateTime<"10:00:00")
			SRendtime = CTADOQ->FieldByName("supperend")->AsDateTime.TimeString();
        else
        	SRendtime = CTADOQ->FieldByName("supperend")->AsDateTime.TimeString();

        if(CTADOQ->FieldByName("nightstart")->AsDateTime<"10:00:00")
			NTstarttime = CTADOQ->FieldByName("nightstart")->AsDateTime.TimeString();
        else
        	NTstarttime = CTADOQ->FieldByName("nightstart")->AsDateTime.TimeString();

        if(CTADOQ->FieldByName("nightend")->AsDateTime<"10:00:00")
			NTendtime = CTADOQ->FieldByName("nightend")->AsDateTime.TimeString();
        else
        	NTendtime = CTADOQ->FieldByName("nightend")->AsDateTime.TimeString();
    }
    CTADOQ->Close();

	QueryBTN->Enabled = true;
	/*
    if(BFstarttime!="00:00:00"&&BFendtime!="00:00:00"&&LHstarttime!="00:00:00"
    	&&LHendtime!="00:00:00"&&SRstarttime!="00:00:00"&&SRendtime!="00:00:00"
        &&NTstarttime!="00:00:00")
	{
		QueryBTN->Enabled = true;
    }
    else
    {
        ShowMessage("必须正确设置餐别时间才能使用该报表，请在“系统参数设置”中进行设置!");
        QueryBTN->Enabled = false;
    }      */
}
//---------------------------------------------------------------------------
void __fastcall TCTQFrm::ExportBTNClick(TObject *Sender)
{
	if(SaveDialog->Execute())
    {
    	ExportBTN->Enabled = false;
        PreviewBTN->Enabled = false;
        if(FileExists(SaveDialog->FileName+".xls"))
        {
            ExportBTN->Enabled = true;
            PreviewBTN->Enabled = true;
            throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
            return;
        }
        else
        {
            String savename = SaveDialog->FileName;
            savename += ".xls";
            Variant ExcelApp;
            try
            {
                ExcelApp = CreateOleObject("Excel.Application");
            }
            catch(...)
            {
                MessageBox(this->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
                return;
            }

            String Templatepath = GlobalPath + "\\ExportXLSTemplate\\CTTJTemplate.xlt";
            ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
            Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
            Variant ST = WB.OlePropertyGet("Sheets", 1);

            ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", (BeginDatestr+" 00:00:00").t_str());
            ST.OlePropertyGet("Cells",2,7).OlePropertySet("Value", (EndDatestr+" 23:59:59").t_str());
            ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", CTStr.t_str());
            ST.OlePropertyGet("Cells",3,5).OlePropertySet("Value", OperatorName.t_str());
            ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", DateTimeToStr(Now()).t_str());

            ST.OlePropertyGet("Cells",6,2).OlePropertySet("Value", cxTextEdit1->Text.t_str());
            ST.OlePropertyGet("Cells",7,2).OlePropertySet("Value", cxTextEdit2->Text.t_str());
            ST.OlePropertyGet("Cells",8,2).OlePropertySet("Value", cxTextEdit3->Text.t_str());
            ST.OlePropertyGet("Cells",9,2).OlePropertySet("Value", cxTextEdit4->Text.t_str());

            ST.OlePropertyGet("Cells",6,4).OlePropertySet("Value", cxTextEdit5->Text.t_str());
            ST.OlePropertyGet("Cells",7,4).OlePropertySet("Value", cxTextEdit6->Text.t_str());
            ST.OlePropertyGet("Cells",8,4).OlePropertySet("Value", cxTextEdit7->Text.t_str());
            ST.OlePropertyGet("Cells",9,4).OlePropertySet("Value", cxTextEdit8->Text.t_str());

            ST.OlePropertyGet("Cells",6,6).OlePropertySet("Value", cxTextEdit9->Text.t_str());
            ST.OlePropertyGet("Cells",7,6).OlePropertySet("Value", cxTextEdit10->Text.t_str());
            ST.OlePropertyGet("Cells",8,6).OlePropertySet("Value", cxTextEdit11->Text.t_str());
            ST.OlePropertyGet("Cells",9,6).OlePropertySet("Value", cxTextEdit12->Text.t_str());

            ST.OlePropertyGet("Cells",6,8).OlePropertySet("Value", cxTextEdit13->Text.t_str());
            ST.OlePropertyGet("Cells",7,8).OlePropertySet("Value", cxTextEdit14->Text.t_str());
            ST.OlePropertyGet("Cells",8,8).OlePropertySet("Value", cxTextEdit15->Text.t_str());
            ST.OlePropertyGet("Cells",9,8).OlePropertySet("Value", cxTextEdit16->Text.t_str());

            ST.OlePropertyGet("Cells",6,10).OlePropertySet("Value", cxTextEdit17->Text.t_str());
            ST.OlePropertyGet("Cells",7,10).OlePropertySet("Value", cxTextEdit18->Text.t_str());
            ST.OlePropertyGet("Cells",8,10).OlePropertySet("Value", cxTextEdit19->Text.t_str());
            ST.OlePropertyGet("Cells",9,10).OlePropertySet("Value", cxTextEdit20->Text.t_str());

            ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
            WB.OleFunction("SaveAs", savename.t_str());
            ExcelApp.OleFunction("Quit");
            ExcelApp = Unassigned;
            MessageBox(this->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);
        }
    	ExportBTN->Enabled = true;
        PreviewBTN->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TCTQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\CTTJPreview.fr3";
    frxCTTJReport->LoadFromFile(temppath.t_str(), true);
    ((TfrxMemoView*)frxCTTJReport->FindObject("QSRQM"))->Text = (BeginDatestr+" 00:00:00").t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("JZRQM"))->Text = (EndDatestr+" 23:59:59").t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("CTM"))->Text = CTStr.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("BBCZYM"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("SCRQM"))->Text = DateTimeToStr(Now()).t_str();

    ((TfrxMemoView*)frxCTTJReport->FindObject("BFCSM"))->Text = cxTextEdit1->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("BFZEM"))->Text = cxTextEdit2->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("BFPJM"))->Text = cxTextEdit3->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("BFBZM"))->Text = cxTextEdit4->Text.t_str();

    ((TfrxMemoView*)frxCTTJReport->FindObject("LHCSM"))->Text = cxTextEdit5->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("LHZEM"))->Text = cxTextEdit6->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("LHPJM"))->Text = cxTextEdit7->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("LHBZM"))->Text = cxTextEdit8->Text.t_str();

    ((TfrxMemoView*)frxCTTJReport->FindObject("SRCSM"))->Text = cxTextEdit9->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("SRZEM"))->Text = cxTextEdit10->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("SRPJM"))->Text = cxTextEdit11->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("SRBZM"))->Text = cxTextEdit12->Text.t_str();

    ((TfrxMemoView*)frxCTTJReport->FindObject("NTCSM"))->Text = cxTextEdit13->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("NTZEM"))->Text = cxTextEdit14->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("NTPJM"))->Text = cxTextEdit15->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("NTBZM"))->Text = cxTextEdit16->Text.t_str();

    ((TfrxMemoView*)frxCTTJReport->FindObject("ZJCSM"))->Text = cxTextEdit17->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("ZJZEM"))->Text = cxTextEdit18->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("ZJPJM"))->Text = cxTextEdit19->Text.t_str();
    ((TfrxMemoView*)frxCTTJReport->FindObject("ZJBZM"))->Text = cxTextEdit20->Text.t_str();

    frxCTTJReport->ShowReport(true);
}
//---------------------------------------------------------------------------
