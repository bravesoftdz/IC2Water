//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFTJQForm.h"
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
#pragma link "cxPC"
#pragma link "dxSkinscxPCPainter"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxProgressBar"
#pragma link "cxStyles"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TXFTJQFrm *XFTJQFrm;
//---------------------------------------------------------------------------
__fastcall TXFTJQFrm::TXFTJQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TXFTJQFrm::ABFCSTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::BHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::ExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::FormShow(TObject *Sender)
{
//	BeginDateEdit->Text = "";
//    EndDateEdit->Text = "";
	BeginDateEdit->Date = Date();
    EndDateEdit->Date = Date();
    BHTextEdit->Text = "";
    BMComboBox->Text = "";

    ALLMXADOQuery->Close();
    ALLADOQInThread->Close();
    GRADOQuery->Close();
    GRADOQInThread->Close();
    CCADOQuery->Close();
    CCADOQInThread->Close();
    GRHZADOQuery->Close();
    GRHZADOQInThread->Close();

//    ALLDataGridDBTV->ClearItems();
//    GRDataGridTV->ClearItems();
//    CCDataGridTV->ClearItems();
//    GRHZDataGridTV->ClearItems();

    ALLMXExportProgressBar->Position = 0;
    GRProgressBar->Position = 0;
    CCProgressBar->Position = 0;
    GRHZProgressBar->Position = 0;

    QueryBTN->Enabled = true;
    ALLMXExportBTN->Enabled = false;
    ALLPreviewBTN->Enabled = false;
    GRExportBTN->Enabled = false;
    GRPreviewBTN->Enabled = false;
    CCExportBTN->Enabled = false;
    CCPreviewBTN->Enabled = false;
    GRHZExportBTN->Enabled = false;
    GRHZPreviewBTN->Enabled = false;
    ExitBTN->Enabled = true;

    ABFCSTextEdit->Text = "";
    ABFZETextEdit->Text = "";
    ALHCSTextEdit->Text = "";
    ALHZETextEdit->Text = "";
    ASRCSTextEdit->Text = "";
    ASRZETextEdit->Text = "";
    ANTCSTextEdit->Text = "";
    ANTZETextEdit->Text = "";
    AZCSTextEdit->Text = "";
    AZZETextEdit->Text = "";
    GRZCSTextEdit->Text = "";
    GRZETextEdit->Text = "";
    CBFCSTextEdit->Text = "";
    CSBFZETextEdit->Text = "";
    CLHCSTextEdit->Text = "";
    CLHZETextEdit->Text = "";
    CSRCSTextEdit->Text = "";
    CSRZETextEdit->Text = "";
    CNTCSTextEdit->Text = "";
    CNTZETextEdit->Text = "";
    CZCSTextEdit->Text = "";
    CZZETextEdit->Text = "";
    GRHZZCSTextEdit->Text = "";
    GRHZZETextEdit->Text = "";

    BMComboBox->Properties->Items->Clear();
    InitADOQuery->Close();
    InitADOQuery->SQL->Clear();
    InitADOQuery->SQL->Add("select * from BUMEN");
    InitADOQuery->Open();
    if(!InitADOQuery->IsEmpty())
    {
        InitADOQuery->First();
        while(!InitADOQuery->Eof)
        {
        	BMComboBox->Properties->Items->Add(InitADOQuery->FieldByName("BUMEN")->AsString.Trim());
            InitADOQuery->Next();
        }
        BMComboBox->Properties->Items->Add("所有单位");
    }
	InitADOQuery->Close();

	CTComboBox->Properties->Items->Clear();
	InitADOQuery->SQL->Clear();
	InitADOQuery->SQL->Add("select * from STNAME");
	InitADOQuery->Open();
	if(!InitADOQuery->IsEmpty())
	{
		InitADOQuery->First();
		while(!InitADOQuery->Eof)
		{
			CTComboBox->Properties->Items->Add(InitADOQuery->FieldByName("STNAME")->AsString.Trim());
			InitADOQuery->Next();
		}
		CTComboBox->Properties->Items->Add("所有餐厅");
	}

    InitADOQuery->Close();
    InitADOQuery->SQL->Clear();
    InitADOQuery->SQL->Add("select * from SUBMEALINFO");
    InitADOQuery->Open();
    if(!InitADOQuery->IsEmpty())
    {
    	if(InitADOQuery->FieldByName("breakfaststart")->AsDateTime<"10:00:00")
			BFstarttime = InitADOQuery->FieldByName("breakfaststart")->AsDateTime.TimeString();
        else
        	BFstarttime = InitADOQuery->FieldByName("breakfaststart")->AsDateTime.TimeString();

		if(InitADOQuery->FieldByName("breakfastend")->AsDateTime<"10:00:00")
			BFendtime = InitADOQuery->FieldByName("breakfastend")->AsDateTime.TimeString();
        else
            BFendtime = InitADOQuery->FieldByName("breakfastend")->AsDateTime.TimeString();

        if(InitADOQuery->FieldByName("lunchstart")->AsDateTime<"10:00:00")
			LHstarttime = InitADOQuery->FieldByName("lunchstart")->AsDateTime.TimeString();
        else
        	LHstarttime = InitADOQuery->FieldByName("lunchstart")->AsDateTime.TimeString();

        if(InitADOQuery->FieldByName("lunchend")->AsDateTime<"10:00:00")
			LHendtime = InitADOQuery->FieldByName("lunchend")->AsDateTime.TimeString();
        else
        	LHendtime = InitADOQuery->FieldByName("lunchend")->AsDateTime.TimeString();

        if(InitADOQuery->FieldByName("supperstart")->AsDateTime<"10:00:00")
			SRstarttime = InitADOQuery->FieldByName("supperstart")->AsDateTime.TimeString();
        else
            SRstarttime = InitADOQuery->FieldByName("supperstart")->AsDateTime.TimeString();

        if(InitADOQuery->FieldByName("supperend")->AsDateTime<"10:00:00")
			SRendtime = InitADOQuery->FieldByName("supperend")->AsDateTime.TimeString();
        else
        	SRendtime = InitADOQuery->FieldByName("supperend")->AsDateTime.TimeString();

        if(InitADOQuery->FieldByName("nightstart")->AsDateTime<"10:00:00")
			NTstarttime = InitADOQuery->FieldByName("nightstart")->AsDateTime.TimeString();
        else
        	NTstarttime = InitADOQuery->FieldByName("nightstart")->AsDateTime.TimeString();

        if(InitADOQuery->FieldByName("nightend")->AsDateTime<"10:00:00")
			NTendtime = InitADOQuery->FieldByName("nightend")->AsDateTime.TimeString();
        else
        	NTendtime = InitADOQuery->FieldByName("nightend")->AsDateTime.TimeString();
    }
    InitADOQuery->Close();

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

void __fastcall TXFTJQFrm::QueryBTNClick(TObject *Sender)
{

	if(BeginDateEdit->Text.IsEmpty())
    {
        ShowMessage("必须填写查询起始时间!");
        return;
    }
    if(EndDateEdit->Text.IsEmpty())
    {
        ShowMessage("必须填写查询截止时间!");
        return;
    }
/*    if(BMComboBox->Text.IsEmpty())
    {
        ShowMessage("必须填写查询单位!");
        return;
    }   */

    ALLMXExportBTN->Enabled = false;
    ALLPreviewBTN->Enabled = false;
    ALLMXADOQuery->Close();
    ALLTJADOQuery->Close();
    AZCSTextEdit->Text = "";
    AZZETextEdit->Text = "";
    ABFCSTextEdit->Text = "";
    ABFZETextEdit->Text = "";
    ALHCSTextEdit->Text = "";
    ALHZETextEdit->Text = "";
    ASRCSTextEdit->Text = "";
    ASRZETextEdit->Text = "";
    ANTCSTextEdit->Text = "";
    ANTZETextEdit->Text = "";
    ALLMXExportProgressBar->Position = 0;

    GRExportBTN->Enabled = false;
    GRPreviewBTN->Enabled = false;
    GRADOQuery->Close();
    AGRTJADOQuery->Close();
    GRZCSTextEdit->Text = "";
    GRZETextEdit->Text = "";
    GRProgressBar->Position = 0;

    CCExportBTN->Enabled = false;
    CCPreviewBTN->Enabled = false;
    CCADOQuery->Close();
    CCTJADOQuery->Close();
    CZCSTextEdit->Text = "";
    CZZETextEdit->Text = "";
    CBFCSTextEdit->Text = "";
    CSBFZETextEdit->Text = "";
    CLHCSTextEdit->Text = "";
    CLHZETextEdit->Text = "";
    CSRCSTextEdit->Text = "";
    CSRZETextEdit->Text = "";
    CNTCSTextEdit->Text = "";
    CNTZETextEdit->Text = "";
    CCProgressBar->Position = 0;

    GRHZExportBTN->Enabled = false;
    GRHZPreviewBTN->Enabled = false;
    GRHZADOQuery->Close();
    GRHZTJADOQuery->Close();
    GRHZZCSTextEdit->Text = "";
    GRHZZETextEdit->Text = "";
    GRHZProgressBar->Position = 0;

    Beginstr = BeginDateEdit->Text + " 00:00:00";
    Endstr = EndDateEdit->Text + " 23:59:59";
    BMstr = BMComboBox->Text;
	BHstr = BHTextEdit->Text;
	CTstr = CTComboBox->Text;

	ExitBTN->Enabled = false;

//消费统计（全部）
    String AllTJsqlstr = "";
	String Allsqlstr = "select SUM(SFJE) as ZSFZE,COUNT(*) as ZSFCS,";
    Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    Allsqlstr += BFendtime;
    Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    Allsqlstr += BFstarttime;
    Allsqlstr += "' then SFJE end) as BFSFZE,";
    Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    Allsqlstr += BFendtime;
    Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    Allsqlstr += BFstarttime;
    Allsqlstr += "' then 1 else 0 end) as BFCS,";
    Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    Allsqlstr += LHendtime;
    Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    Allsqlstr += LHstarttime;
    Allsqlstr += "' then SFJE end) as LHSFZE,";
    Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    Allsqlstr += LHendtime;
    Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    Allsqlstr += LHstarttime;
    Allsqlstr += "' then 1 else 0 end) as LHCS,";
    Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    Allsqlstr += SRendtime;
    Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    Allsqlstr += SRstarttime;
    Allsqlstr += "' then SFJE end) as SUSFZE,";
    Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    Allsqlstr += SRendtime;
    Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    Allsqlstr += SRstarttime;
    Allsqlstr += "' then 1 else 0 end) as SUCS,";

    if(StrToDateTime(NTendtime)>StrToDateTime(NTstarttime))
    {
        Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
        Allsqlstr += NTendtime;
        Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        Allsqlstr += NTstarttime;
        Allsqlstr += "' then SFJE end) as NTSFZE,";
        Allsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
		Allsqlstr += NTendtime;
        Allsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        Allsqlstr += NTstarttime;
        AllTJsqlstr = Allsqlstr;
		Allsqlstr += "' then 1 else 0 end) as NTCS,Convert(Varchar(10),SFRQ,120) as qdate from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
		AllTJsqlstr += "' then 1 else 0 end) as NTCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
	}
    else
    {
    	Allsqlstr += "SUM(case when (convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        Allsqlstr += NTstarttime;
        Allsqlstr += "') or (convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
        Allsqlstr += NTendtime;
        Allsqlstr += "') then SFJE end) as NTSFZE,";
        Allsqlstr += "SUM(case when (convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        Allsqlstr += NTstarttime;
        Allsqlstr += "') or (convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
        Allsqlstr += NTendtime;
        AllTJsqlstr = Allsqlstr;
		Allsqlstr += "') then 1 else 0 end) as NTCS,Convert(Varchar(10),SFRQ,120) as qdate from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
		AllTJsqlstr += "') then 1 else 0 end) as NTCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
    }

	String Alladdsqlstr = "";
	if(CTstr !="所有餐厅"&&!CTstr.IsEmpty())
	{
		Alladdsqlstr = "join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFJPARAM.STNAME='";
		Alladdsqlstr += CTstr;
		Alladdsqlstr += "'";
	}
	else
	{
		Alladdsqlstr = "where SFLX='X'";
	}

	if(BMstr != "所有单位"&&!BMstr.IsEmpty())
    {
        if(BHstr.IsEmpty())
        {
			Alladdsqlstr += " and CARD_F.BM='";
            Alladdsqlstr += BMstr;
            Alladdsqlstr += "' and SFRQ<='";
            Alladdsqlstr += Endstr;
            Alladdsqlstr += "' and SFRQ>='";
            Alladdsqlstr += Beginstr;
            Alladdsqlstr += "'";
        }
        else
        {
			Alladdsqlstr += " and CARD_F.BM='";
            Alladdsqlstr += BMstr;
            Alladdsqlstr += "' and SFRQ<='";
            Alladdsqlstr += Endstr;
            Alladdsqlstr += "' and SFRQ>='";
            Alladdsqlstr += Beginstr;
            Alladdsqlstr += "' and MXBAK.BH='";
            Alladdsqlstr += BHstr;
            Alladdsqlstr += "'";
        }
    }
    else
    {
        if(BHstr.IsEmpty())
        {
			Alladdsqlstr += " and SFRQ<='";
            Alladdsqlstr += Endstr;
            Alladdsqlstr += "' and SFRQ>='";
            Alladdsqlstr += Beginstr;
            Alladdsqlstr += "'";
        }
        else
        {
			Alladdsqlstr += " and SFRQ<='";
            Alladdsqlstr += Endstr;
            Alladdsqlstr += "' and SFRQ>='";
            Alladdsqlstr += Beginstr;
            Alladdsqlstr += "' and MXBAK.BH='";
            Alladdsqlstr += BHstr;
            Alladdsqlstr += "'";
        }
    }
    Allsqlstr += Alladdsqlstr;
    Allsqlstr += " Group By Convert(Varchar(10),SFRQ,120) order by Convert(Varchar(10),SFRQ,120) asc";
    AllTJsqlstr += Alladdsqlstr;

    ALLMXADOQuery->Close();
    ALLMXADOQuery->SQL->Clear();
    ALLMXADOQuery->SQL->Add(Allsqlstr);
    ALLMXADOQuery->Open();
    if(!ALLMXADOQuery->IsEmpty())
    {
    	RQCol->DataBinding->FieldName = "qdate";
        ZECol->DataBinding->FieldName = "ZSFZE";
        ZCSCol->DataBinding->FieldName = "ZSFCS";
        BFZECol->DataBinding->FieldName = "BFSFZE";
        BFZCSCol->DataBinding->FieldName = "BFCS";
        LHZECol->DataBinding->FieldName = "LHSFZE";
        LHZCSCol->DataBinding->FieldName = "LHCS";
        SRZECol->DataBinding->FieldName = "SUSFZE";
        SRZCSCol->DataBinding->FieldName = "SUCS";
        NTZECol->DataBinding->FieldName = "NTSFZE";
        NTZCSCol->DataBinding->FieldName = "NTCS";
    }

    ALLTJADOQuery->Close();
    ALLTJADOQuery->SQL->Clear();
    ALLTJADOQuery->SQL->Add(AllTJsqlstr);
    ALLTJADOQuery->Open();
    if(!ALLTJADOQuery->IsEmpty())
    {
    	AZCSTextEdit->Text = IntToStr(ALLTJADOQuery->FieldByName("ZSFCS")->AsInteger);
        AZZETextEdit->Text = FloatToStr(ALLTJADOQuery->FieldByName("ZSFZE")->AsFloat);
        ABFCSTextEdit->Text = IntToStr(ALLTJADOQuery->FieldByName("BFCS")->AsInteger);
        ABFZETextEdit->Text = FloatToStr(ALLTJADOQuery->FieldByName("BFSFZE")->AsFloat);
        ALHCSTextEdit->Text = IntToStr(ALLTJADOQuery->FieldByName("LHCS")->AsInteger);
        ALHZETextEdit->Text = FloatToStr(ALLTJADOQuery->FieldByName("LHSFZE")->AsFloat);
        ASRCSTextEdit->Text = IntToStr(ALLTJADOQuery->FieldByName("SUCS")->AsInteger);
        ASRZETextEdit->Text = FloatToStr(ALLTJADOQuery->FieldByName("SUSFZE")->AsFloat);
        ANTCSTextEdit->Text = IntToStr(ALLTJADOQuery->FieldByName("NTCS")->AsInteger);
        ANTZETextEdit->Text = FloatToStr(ALLTJADOQuery->FieldByName("NTSFZE")->AsFloat);
    }
    ALLTJADOQuery->Close();


//消费统计（按个人）
	String AGRsqlstr = "select Convert(Varchar(10),SFRQ,120) as qdate,CARD_F.XM,MXBAK.BH,SUM(SFJE) as ZE,COUNT(*) as ZCS,CARD_F.BM from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//;where SFLX='X'";
	String AGRTJsqlstr = "select SUM(SFJE) as ZE,COUNT(*) as ZCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
	String AGRaddsqlstr = "";
	if(CTstr !="所有餐厅"&&!CTstr.IsEmpty())
	{
		AGRaddsqlstr = "join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFJPARAM.STNAME='";
		AGRaddsqlstr += CTstr;
		AGRaddsqlstr += "'";
	}
	else
		AGRaddsqlstr = "where SFLX='X'";

	if(BMstr != "所有单位"&&!BMstr.IsEmpty())
    {
        if(BHstr.IsEmpty())
        {
			AGRaddsqlstr += " and CARD_F.BM='";
            AGRaddsqlstr += BMstr;
            AGRaddsqlstr += "' and SFRQ<='";
            AGRaddsqlstr += Endstr;
            AGRaddsqlstr += "' and SFRQ>='";
            AGRaddsqlstr += Beginstr;
            AGRaddsqlstr += "'";
        }
        else
        {
			AGRaddsqlstr += " and CARD_F.BM='";
            AGRaddsqlstr += BMstr;
            AGRaddsqlstr += "' and SFRQ<='";
            AGRaddsqlstr += Endstr;
            AGRaddsqlstr += "' and SFRQ>='";
            AGRaddsqlstr += Beginstr;
            AGRaddsqlstr += "' and MXBAK.BH='";
            AGRaddsqlstr += BHstr;
            AGRaddsqlstr += "'";
        }
    }
    else
    {
        if(BHstr.IsEmpty())
        {
            AGRaddsqlstr += " and SFRQ<='";
            AGRaddsqlstr += Endstr;
            AGRaddsqlstr += "' and SFRQ>='";
            AGRaddsqlstr += Beginstr;
            AGRaddsqlstr += "'";
        }
        else
        {
            AGRaddsqlstr += " and SFRQ<='";
            AGRaddsqlstr += Endstr;
            AGRaddsqlstr += "' and SFRQ>='";
            AGRaddsqlstr += Beginstr;
            AGRaddsqlstr += "' and MXBAK.BH='";
            AGRaddsqlstr += BHstr;
            AGRaddsqlstr += "'";
        }
    }
    AGRsqlstr += AGRaddsqlstr;
	AGRsqlstr += " Group By Convert(Varchar(10),SFRQ,120),MXBAK.BH,CARD_F.XM,CARD_F.BM order by Convert(Varchar(10),SFRQ,120),MXBAK.BH asc";
    AGRTJsqlstr += AGRaddsqlstr;
    GRADOQuery->Close();
    GRADOQuery->SQL->Clear();
    GRADOQuery->SQL->Add(AGRsqlstr);
    GRADOQuery->Open();
    if(!GRADOQuery->IsEmpty())
    {
        //DataBinding
        GRRQCol->DataBinding->FieldName = "qdate";
        GRXMCol->DataBinding->FieldName = "XM";
        GRBHCol->DataBinding->FieldName = "BH";
        GRXFCSCol->DataBinding->FieldName = "ZCS";
        GRXFZECol->DataBinding->FieldName = "ZE";
        GRBMCol->DataBinding->FieldName = "BM";
    }

    AGRTJADOQuery->Close();
    AGRTJADOQuery->SQL->Clear();
    AGRTJADOQuery->SQL->Add(AGRTJsqlstr);
    AGRTJADOQuery->Open();
    if(!AGRTJADOQuery->IsEmpty())
    {
    	GRZCSTextEdit->Text = IntToStr(AGRTJADOQuery->FieldByName("ZCS")->AsInteger);
        GRZETextEdit->Text = FloatToStr(AGRTJADOQuery->FieldByName("ZE")->AsFloat);
    }
    AGRTJADOQuery->Close();

//消费统计（个人及餐次）
    String GCTJsqlstr = "";
	String GCsqlstr = "select SUM(SFJE) as ZSFZE,COUNT(*) as ZSFCS,";
    GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    GCsqlstr += BFendtime;
    GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    GCsqlstr += BFstarttime;
    GCsqlstr += "' then SFJE end) as BFSFZE,";
    GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    GCsqlstr += BFendtime;
    GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    GCsqlstr += BFstarttime;
    GCsqlstr += "' then 1 else 0 end) as BFCS,";
    GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    GCsqlstr += LHendtime;
    GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    GCsqlstr += LHstarttime;
    GCsqlstr += "' then SFJE end) as LHSFZE,";
    GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    GCsqlstr += LHendtime;
    GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    GCsqlstr += LHstarttime;
    GCsqlstr += "' then 1 else 0 end) as LHCS,";
    GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    GCsqlstr += SRendtime;
    GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    GCsqlstr += SRstarttime;
    GCsqlstr += "' then SFJE end) as SUSFZE,";
    GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
    GCsqlstr += SRendtime;
    GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
    GCsqlstr += SRstarttime;
    GCsqlstr += "' then 1 else 0 end) as SUCS,";

    if(StrToDateTime(NTendtime)>StrToDateTime(NTstarttime))
    {
        GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
        GCsqlstr += NTendtime;
        GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        GCsqlstr += NTstarttime;
        GCsqlstr += "' then SFJE end) as NTSFZE,";
        GCsqlstr += "SUM(case when convert(varchar(100),MXBAK.SFRQ,108)<='";
        GCsqlstr += NTendtime;
        GCsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        GCsqlstr += NTstarttime;
        GCTJsqlstr = GCsqlstr;
		GCsqlstr += "' then 1 else 0 end) as NTCS,MXBAK.BH,CARD_F.XM,MXBAK.KH from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
		GCTJsqlstr += "' then 1 else 0 end) as NTCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
	}
    else
    {
    	GCsqlstr += "SUM(case when (convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        GCsqlstr += NTstarttime;
        GCsqlstr += "') or (convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
        GCsqlstr += NTendtime;
        GCsqlstr += "') then SFJE end) as NTSFZE,";
        GCsqlstr += "SUM(case when (convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
        GCsqlstr += NTstarttime;
        GCsqlstr += "') or (convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
		GCsqlstr += NTendtime;
        GCTJsqlstr = GCsqlstr;
		GCsqlstr += "') then 1 else 0 end) as NTCS,MXBAK.BH,CARD_F.XM,MXBAK.KH from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
		GCTJsqlstr += "') then 1 else 0 end) as NTCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
    }

	String GCaddsqlstr = "";
	if(CTstr !="所有餐厅"&&!CTstr.IsEmpty())
	{
		GCaddsqlstr = "join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFJPARAM.STNAME='";
		GCaddsqlstr += CTstr;
		GCaddsqlstr += "'";
	}
	else
		GCaddsqlstr = "where SFLX='X'";

    if(BMstr != "所有单位"&&!BMstr.IsEmpty())
    {
        if(BHstr.IsEmpty())
		{
			GCaddsqlstr += " and CARD_F.BM='";
            GCaddsqlstr += BMstr;
            GCaddsqlstr += "' and SFRQ<='";
            GCaddsqlstr += Endstr;
            GCaddsqlstr += "' and SFRQ>='";
            GCaddsqlstr += Beginstr;
            GCaddsqlstr += "'";
        }
        else
        {
			GCaddsqlstr += " and CARD_F.BM='";
            GCaddsqlstr += BMstr;
            GCaddsqlstr += "' and SFRQ<='";
            GCaddsqlstr += Endstr;
            GCaddsqlstr += "' and SFRQ>='";
            GCaddsqlstr += Beginstr;
            GCaddsqlstr += "' and MXBAK.BH='";
            GCaddsqlstr += BHstr;
            GCaddsqlstr += "'";
        }
    }
    else
    {
        if(BHstr.IsEmpty())
        {
			GCaddsqlstr += " and SFRQ<='";
            GCaddsqlstr += Endstr;
            GCaddsqlstr += "' and SFRQ>='";
            GCaddsqlstr += Beginstr;
            GCaddsqlstr += "'";
        }
        else
        {
        	GCaddsqlstr += " and SFRQ<='";
            GCaddsqlstr += Endstr;
            GCaddsqlstr += "' and SFRQ>='";
            GCaddsqlstr += Beginstr;
            GCaddsqlstr += "' and MXBAK.BH='";
            GCaddsqlstr += BHstr;
            GCaddsqlstr += "'";
        }
    }
    GCsqlstr += GCaddsqlstr;
	GCsqlstr += " Group By MXBAK.BH,CARD_F.XM,MXBAK.KH order by MXBAK.BH asc";
    GCTJsqlstr += GCaddsqlstr;

    CCADOQuery->Close();
    CCADOQuery->SQL->Clear();
    CCADOQuery->SQL->Add(GCsqlstr);
    CCADOQuery->Open();
    if(!CCADOQuery->IsEmpty())
    {
    	CCBHCol->DataBinding->FieldName = "BH";
        CCXMCol->DataBinding->FieldName = "XM";
        CCKHCol->DataBinding->FieldName = "KH";
        CCZECol->DataBinding->FieldName = "ZSFZE";
        CCZCSCol->DataBinding->FieldName = "ZSFCS";
        CCBFZECol->DataBinding->FieldName = "BFSFZE";
        CCBFCSCol->DataBinding->FieldName = "BFCS";
        CCLHZECol->DataBinding->FieldName = "LHSFZE";
        CCLHCSCol->DataBinding->FieldName = "LHCS";
        CCSRZECol->DataBinding->FieldName = "SUSFZE";
        CCSRCSCol->DataBinding->FieldName = "SUCS";
        CCNTZECol->DataBinding->FieldName = "NTSFZE";
        CCNTCSCol->DataBinding->FieldName = "NTCS";
    }

    CCTJADOQuery->Close();
    CCTJADOQuery->SQL->Clear();
    CCTJADOQuery->SQL->Add(GCTJsqlstr);
    CCTJADOQuery->Open();
    if(!CCTJADOQuery->IsEmpty())
    {
    	CZCSTextEdit->Text = IntToStr(CCTJADOQuery->FieldByName("ZSFCS")->AsInteger);
        CZZETextEdit->Text = FloatToStr(CCTJADOQuery->FieldByName("ZSFZE")->AsFloat);
        CBFCSTextEdit->Text = IntToStr(CCTJADOQuery->FieldByName("BFCS")->AsInteger);
        CSBFZETextEdit->Text = FloatToStr(CCTJADOQuery->FieldByName("BFSFZE")->AsFloat);
        CLHCSTextEdit->Text = IntToStr(CCTJADOQuery->FieldByName("LHCS")->AsInteger);
        CLHZETextEdit->Text = FloatToStr(CCTJADOQuery->FieldByName("LHSFZE")->AsFloat);
        CSRCSTextEdit->Text = IntToStr(CCTJADOQuery->FieldByName("SUCS")->AsInteger);
        CSRZETextEdit->Text = FloatToStr(CCTJADOQuery->FieldByName("SUSFZE")->AsFloat);
        CNTCSTextEdit->Text = IntToStr(CCTJADOQuery->FieldByName("NTCS")->AsInteger);
        CNTZETextEdit->Text = FloatToStr(CCTJADOQuery->FieldByName("NTSFZE")->AsFloat);
    }
    CCTJADOQuery->Close();

//消费统计（个人汇总）
	String HZsqlstr = "select CARD_F.XM,MXBAK.BH,MXBAK.KH,SUM(SFJE) as ZE,COUNT(*) as ZCS,CARD_F.BM from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
	String HZTJsqlstr = "select SUM(SFJE) as ZE,COUNT(*) as ZCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH ";//where SFLX='X'";
	String HZaddsqlstr = "";

	if(CTstr !="所有餐厅"&&!CTstr.IsEmpty())
	{
		HZaddsqlstr = "join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFJPARAM.STNAME='";
		HZaddsqlstr += CTstr;
		HZaddsqlstr += "'";
	}
	else
	{
		HZaddsqlstr = "where SFLX='X'";
	}
    if(BMstr != "所有单位"&&!BMstr.IsEmpty())
    {
        if(BHstr.IsEmpty())
        {
			HZaddsqlstr += " and CARD_F.BM='";
            HZaddsqlstr += BMstr;
            HZaddsqlstr += "' and SFRQ<='";
            HZaddsqlstr += Endstr;
            HZaddsqlstr += "' and SFRQ>='";
            HZaddsqlstr += Beginstr;
            HZaddsqlstr += "'";
        }
        else
        {
			HZaddsqlstr += " and CARD_F.BM='";
            HZaddsqlstr += BMstr;
            HZaddsqlstr += "' and SFRQ<='";
            HZaddsqlstr += Endstr;
            HZaddsqlstr += "' and SFRQ>='";
            HZaddsqlstr += Beginstr;
            HZaddsqlstr += "' and MXBAK.BH='";
            HZaddsqlstr += BHstr;
            HZaddsqlstr += "'";
        }
    }
    else
    {
        if(BHstr.IsEmpty())
        {
            HZaddsqlstr += " and SFRQ<='";
            HZaddsqlstr += Endstr;
            HZaddsqlstr += "' and SFRQ>='";
            HZaddsqlstr += Beginstr;
            HZaddsqlstr += "'";
        }
        else
        {
            HZaddsqlstr += " and SFRQ<='";
            HZaddsqlstr += Endstr;
            HZaddsqlstr += "' and SFRQ>='";
            HZaddsqlstr += Beginstr;
            HZaddsqlstr += "' and MXBAK.BH='";
            HZaddsqlstr += BHstr;
            HZaddsqlstr += "'";
        }
    }
    HZsqlstr += HZaddsqlstr;
	HZsqlstr += " Group By MXBAK.BH,MXBAK.KH,CARD_F.XM,CARD_F.BM order by MXBAK.BH asc";
    HZTJsqlstr += HZaddsqlstr;
    GRHZADOQuery->Close();
    GRHZADOQuery->SQL->Clear();
    GRHZADOQuery->SQL->Add(HZsqlstr);
    GRHZADOQuery->Open();
    if(!GRHZADOQuery->IsEmpty())
    {
        //DataBinding
        HZBHCol->DataBinding->FieldName = "BH";
        HZXMCol->DataBinding->FieldName = "XM";
        HZKHCol->DataBinding->FieldName = "KH";
        HZXFCSCol->DataBinding->FieldName = "ZCS";
        HZXFZECol->DataBinding->FieldName = "ZE";
        HZBMCol->DataBinding->FieldName = "BM";
    }

    GRHZTJADOQuery->Close();
    GRHZTJADOQuery->SQL->Clear();
    GRHZTJADOQuery->SQL->Add(HZTJsqlstr);
    GRHZTJADOQuery->Open();
    if(!GRHZTJADOQuery->IsEmpty())
    {
    	GRHZZCSTextEdit->Text = IntToStr(GRHZTJADOQuery->FieldByName("ZCS")->AsInteger);
        GRHZZETextEdit->Text = FloatToStr(GRHZTJADOQuery->FieldByName("ZE")->AsFloat);
    }
	GRHZTJADOQuery->Close();



    ALLMXExportBTN->Enabled = true;
	ALLPreviewBTN->Enabled = true;

    GRExportBTN->Enabled = true;
	GRPreviewBTN->Enabled = true;

	CCExportBTN->Enabled = true;
	CCPreviewBTN->Enabled = true;

    GRHZExportBTN->Enabled = true;
    GRHZPreviewBTN->Enabled = true;

	ExitBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::ALLMXExportBTNClick(TObject *Sender)
{
	if(!ALLMXADOQuery->IsEmpty())
    {
    	ALLADOQInThread->Close();
        ALLADOQInThread->SQL->Clear();
		ALLADOQInThread->SQL = ALLMXADOQuery->SQL;
		if(ALLSaveDialog->Execute())
		{
			if(FileExists(ALLSaveDialog->FileName+".xls"))
			{
				throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
                return;
			}
			else
			{
				String savename = ALLSaveDialog->FileName;
				savename += ".xls";

                TXFTJALLExportThread* EXThread = new TXFTJALLExportThread(true,
                														  ALLMXExportProgressBar,
                                                                          ALLADOQInThread,
                                                                          ALLMXExportBTN,
                                                                          ALLPreviewBTN,
                                                                          ExitBTN,
                                                                          QueryBTN,
                                                                          AZZETextEdit->Text,
                                                                          AZCSTextEdit->Text,
                                                                          ABFZETextEdit->Text,
                                                                          ABFCSTextEdit->Text,
                                                                          ALHZETextEdit->Text,
                                                                          ALHCSTextEdit->Text,
                                                                          ASRZETextEdit->Text,
                                                                          ASRCSTextEdit->Text,
                                                                          ANTZETextEdit->Text,
                                                                          ANTCSTextEdit->Text,
                                                                          savename,
                                                                          Beginstr,
                                                                          Endstr,
                                                                          BMstr,
                                                                          BHstr,
                                                                          OperatorName);
                if(EXThread)
                {
                    EXThread->Resume();
                }
            }
        }
    }
	else
	{
		MessageBox(this->Handle, "没有可导出信息！", "No Record Error!", MB_OK|MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::ALLPreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\XFTJALLMXPreview.fr3";
    frxALLMXReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxALLMXReport->FindObject("BHMemo"))->Text = BHstr.t_str();
	((TfrxMemoView*)frxALLMXReport->FindObject("BMMemo"))->Text = BMstr.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("CTMemo"))->Text = CTstr.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("QSRQMemo"))->Text = Beginstr.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("BBCZYMemo"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("JZRQMemo"))->Text = Endstr.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("ZZEMemo"))->Text = AZZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("ZCSMemo"))->Text = AZCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("BFZEMemo"))->Text = ABFZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("BFCSMemo"))->Text = ABFCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("LHZEMemo"))->Text = ALHZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("LHCSMemo"))->Text = ALHCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("SRZEMemo"))->Text = ASRZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("SRCSMemo"))->Text = ASRCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxALLMXReport->FindObject("NTZEMemo"))->Text = ANTZETextEdit->Text.t_str();
	((TfrxMemoView*)frxALLMXReport->FindObject("NTCSMemo"))->Text = ANTCSTextEdit->Text.t_str();

    ((TfrxMemoView*)frxALLMXReport->FindObject("RQ"))->DataField = "qdate";
    ((TfrxMemoView*)frxALLMXReport->FindObject("ZZE"))->DataField = "ZSFZE";
    ((TfrxMemoView*)frxALLMXReport->FindObject("ZCS"))->DataField = "ZSFCS";
    ((TfrxMemoView*)frxALLMXReport->FindObject("BZE"))->DataField = "BFSFZE";
    ((TfrxMemoView*)frxALLMXReport->FindObject("BZCS"))->DataField = "BFCS";
    ((TfrxMemoView*)frxALLMXReport->FindObject("LZE"))->DataField = "LHSFZE";
    ((TfrxMemoView*)frxALLMXReport->FindObject("LZCS"))->DataField = "LHCS";
    ((TfrxMemoView*)frxALLMXReport->FindObject("SZE"))->DataField = "SUSFZE";
    ((TfrxMemoView*)frxALLMXReport->FindObject("SZCS"))->DataField = "SUCS";
    ((TfrxMemoView*)frxALLMXReport->FindObject("NZE"))->DataField = "NTSFZE";
    ((TfrxMemoView*)frxALLMXReport->FindObject("NZCS"))->DataField = "NTCS";

    frxALLMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::GRExportBTNClick(TObject *Sender)
{
	if(!GRADOQuery->IsEmpty())
    {
    	GRADOQInThread->Close();
        GRADOQInThread->SQL->Clear();
		GRADOQInThread->SQL = GRADOQuery->SQL;
		if(GRSaveDialog->Execute())
		{
			if(FileExists(GRSaveDialog->FileName+".xls"))
			{
				throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
                return;
			}
			else
			{
				String savename = GRSaveDialog->FileName;
				savename += ".xls";
                TXFTJGRExportThread* EXThread = new TXFTJGRExportThread(true,
                														GRProgressBar,
                                                                        GRADOQInThread,
                                                                        GRExportBTN,
                                                                        GRPreviewBTN,
                                                                        ExitBTN,
                                                                        QueryBTN,
                                                                        GRZETextEdit->Text,
                                                                        GRZCSTextEdit->Text,
                                                                        savename,
                                                                        Beginstr,
                                                                        Endstr,
                                                                        BMstr,
                                                                        BHstr,
                                                                        OperatorName);
                if(EXThread)
                {
                    EXThread->Resume();
                }
            }
        }
    }
	else
	{
		MessageBox(this->Handle, "没有可导出信息！", "No Record Error!", MB_OK|MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::GRPreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\XFTJGRMXPreview.fr3";
    frxGRMXReport->LoadFromFile(temppath.t_str(), true);

	((TfrxMemoView*)frxGRMXReport->FindObject("GRBHMemo"))->Text = BHstr.t_str();
	((TfrxMemoView*)frxGRMXReport->FindObject("GRBMMemo"))->Text = BMstr.t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("CTMemo"))->Text = CTstr.t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRQSRQMemo"))->Text = Beginstr.t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRBBCZYMemo"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRSCRQMemo"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRJZRQMemo"))->Text = Endstr.t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRXFZEMemo"))->Text = GRZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRXFZCSMemo"))->Text = GRZCSTextEdit->Text.t_str();

    ((TfrxMemoView*)frxGRMXReport->FindObject("GRRQM"))->DataField = "qdate";
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRXMM"))->DataField = "XM";
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRBHM"))->DataField = "BH";
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRXFCSM"))->DataField = "ZCS";
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRXFZEM"))->DataField = "ZE";
    ((TfrxMemoView*)frxGRMXReport->FindObject("GRBMM"))->DataField = "BM";

    frxGRMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::CCExportBTNClick(TObject *Sender)
{
	if(!CCADOQuery->IsEmpty())
    {
    	CCADOQInThread->Close();
        CCADOQInThread->SQL->Clear();
		CCADOQInThread->SQL = CCADOQuery->SQL;
		if(CCSaveDialog->Execute())
		{
			if(FileExists(CCSaveDialog->FileName+".xls"))
			{
				throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
                return;
			}
			else
			{
				String savename = CCSaveDialog->FileName;
				savename += ".xls";

                TXFTJGCExportThread* EXThread = new TXFTJGCExportThread(true,
                														CCProgressBar,
                                                                        CCADOQInThread,
                                                                        CCExportBTN,
                                                                        CCPreviewBTN,
                                                                        ExitBTN,
                                                                        QueryBTN,
                                                                        CZZETextEdit->Text,
                                                                        CZCSTextEdit->Text,
                                                                        CSBFZETextEdit->Text,
                                                                        CBFCSTextEdit->Text,
                                                                        CLHZETextEdit->Text,
                                                                        CLHCSTextEdit->Text,
                                                                        CSRZETextEdit->Text,
                                                                        CSRCSTextEdit->Text,
                                                                        CNTZETextEdit->Text,
                                                                        CNTCSTextEdit->Text,
                                                                        savename,
                                                                        Beginstr,
                                                                        Endstr,
                                                                        BMstr,
                                                                        BHstr,
                                                                        OperatorName);
                if(EXThread)
                {
                    EXThread->Resume();
                }

            }
        }
    }
	else
	{
		MessageBox(this->Handle, "没有可导出信息！", "No Record Error!", MB_OK|MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::CCPreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\XFTJGCMXPreview.fr3";
    frxCCReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxCCReport->FindObject("BHMemo"))->Text = BHstr.t_str();
	((TfrxMemoView*)frxCCReport->FindObject("BMMemo"))->Text = BMstr.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("CTMemo"))->Text = CTstr.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("QSRQMemo"))->Text = Beginstr.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("BBCZYMemo"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("JZRQMemo"))->Text = Endstr.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("ZZEMemo"))->Text = CZZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("ZCSMemo"))->Text = CZCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("BFZEMemo"))->Text = CSBFZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("BFCSMemo"))->Text = CBFCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("LHZEMemo"))->Text = CLHZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("LHCSMemo"))->Text = CLHCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("SRZEMemo"))->Text = CSRZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("SRCSMemo"))->Text = CSRCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("NTZEMemo"))->Text = CNTZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxCCReport->FindObject("NTCSMemo"))->Text = CNTCSTextEdit->Text.t_str();

    ((TfrxMemoView*)frxCCReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxCCReport->FindObject("XM"))->DataField = "XM";
    ((TfrxMemoView*)frxCCReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxCCReport->FindObject("ZZE"))->DataField = "ZSFZE";
    ((TfrxMemoView*)frxCCReport->FindObject("ZCS"))->DataField = "ZSFCS";
    ((TfrxMemoView*)frxCCReport->FindObject("BZE"))->DataField = "BFSFZE";
    ((TfrxMemoView*)frxCCReport->FindObject("BZCS"))->DataField = "BFCS";
    ((TfrxMemoView*)frxCCReport->FindObject("LZE"))->DataField = "LHSFZE";
    ((TfrxMemoView*)frxCCReport->FindObject("LZCS"))->DataField = "LHCS";
    ((TfrxMemoView*)frxCCReport->FindObject("SZE"))->DataField = "SUSFZE";
    ((TfrxMemoView*)frxCCReport->FindObject("SZCS"))->DataField = "SUCS";
    ((TfrxMemoView*)frxCCReport->FindObject("NZE"))->DataField = "NTSFZE";
    ((TfrxMemoView*)frxCCReport->FindObject("NZCS"))->DataField = "NTCS";

    frxCCReport->ShowReport(true);
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::GRHZExportBTNClick(TObject *Sender)
{
	if(!GRHZADOQuery->IsEmpty())
    {
    	GRHZADOQInThread->Close();
        GRHZADOQInThread->SQL->Clear();
		GRHZADOQInThread->SQL = GRHZADOQuery->SQL;
		if(GRHZSaveDialog->Execute())
		{
			if(FileExists(GRHZSaveDialog->FileName+".xls"))
			{
				throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
                return;
			}
			else
			{
				String savename = GRHZSaveDialog->FileName;
				savename += ".xls";
                TXFTJZHExportThread* EXThread = new TXFTJZHExportThread(true,
                														GRHZProgressBar,
                                                                        GRHZADOQInThread,
                                                                        GRHZExportBTN,
                                                                        GRHZPreviewBTN,
                                                                        ExitBTN,
                                                                        QueryBTN,
                                                                        GRHZZETextEdit->Text,
                                                                        GRHZZCSTextEdit->Text,
                                                                        savename,
                                                                        Beginstr,
                                                                        Endstr,
                                                                        BMstr,
                                                                        BHstr,
                                                                        OperatorName);
                if(EXThread)
                {
                    EXThread->Resume();
                }
            }
        }
    }
	else
	{
		MessageBox(this->Handle, "没有可导出信息！", "No Record Error!", MB_OK|MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TXFTJQFrm::GRHZPreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\XFTJHZMXPreview.fr3";
    frxGRHZReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxGRHZReport->FindObject("HZBHMemo"))->Text = BHstr.t_str();
	((TfrxMemoView*)frxGRHZReport->FindObject("HZBMMemo"))->Text = BMstr.t_str();
	((TfrxMemoView*)frxGRHZReport->FindObject("CTMemo"))->Text = CTstr.t_str();
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZQSRQMemo"))->Text = Beginstr.t_str();
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZBBCZYMemo"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZSCRQMemo"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZJZRQMemo"))->Text = Endstr.t_str();
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZXFZEMemo"))->Text = GRHZZETextEdit->Text.t_str();
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZXFZCSMemo"))->Text = GRHZZCSTextEdit->Text.t_str();

    ((TfrxMemoView*)frxGRHZReport->FindObject("HZBHM"))->DataField = "BH";
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZXMM"))->DataField = "XM";
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZKHM"))->DataField = "KH";
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZXFCSM"))->DataField = "ZCS";
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZXFZEM"))->DataField = "ZE";
    ((TfrxMemoView*)frxGRHZReport->FindObject("HZBMM"))->DataField = "BM";

    frxGRHZReport->ShowReport(true);
}
//---------------------------------------------------------------------------

