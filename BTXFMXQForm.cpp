//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BTXFMXQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
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
#pragma resource "*.dfm"
TBTFXMXQFrm *BTFXMXQFrm;
//---------------------------------------------------------------------------
__fastcall TBTFXMXQFrm::TBTFXMXQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBTFXMXQFrm::Button1Click(TObject *Sender)
{
	if(-1 == RadioGroup1->ItemIndex)
	{
		ShowMessage("必须选择查询补贴类型!");
		return;
	}
	if(XFBeginDateEdit->Text.IsEmpty()||XFEndDateEdit->Text.IsEmpty())
	{
		ShowMessage("必须完整填写查询起至日期!");
		return;
	}

	String displaysqlstr = "select TOP 1000 MXBAK.*,CARD_F.XM as UName,CARD_F.BM as BUMEN,CARD_F.ZW as ZW,SFJPARAM.STNAME as CTNAME from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where";
	String MXsqlstr = "select MXBAK.*,CARD_F.XM as UName,CARD_F.BM as BUMEN,CARD_F.ZW as ZW,SFJPARAM.STNAME as CTNAME from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where";
	String SUMsqlstr = "select SUM(MXBAK.SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where";
	String Allcssqlstr = "select count(*) as allcs from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where";
	String sqlstr = "  SFRQ>='";
	sqlstr += XFBeginDateEdit->Text;
	sqlstr += " 00:00:00' and SFRQ<='";
	sqlstr += XFEndDateEdit->Text;
	sqlstr += " 23:59:59'";

	int radiotag = RadioGroup1->ItemIndex;
	if(0 == radiotag)
	{
		sqlstr += " and SFLX='Y'";
	}
	if(1 == radiotag)
	{
        sqlstr += " and SFLX='B'";
	}

	displaysqlstr += sqlstr;
	MXsqlstr += sqlstr;
	SUMsqlstr += sqlstr;
	Allcssqlstr += sqlstr;

	XFADOQ->Close();
	XFADOQ->SQL->Clear();
	XFADOQ->SQL->Add(MXsqlstr);
	XFADOQ->Open();
	if(!XFADOQ->IsEmpty())
	{
		XFADOQ->Close();
		XFADOQ->SQL->Clear();
		XFADOQ->SQL->Add(SUMsqlstr);
		XFADOQ->Open();
		BTMXShowFRM->AllXFTextEdit->Text = XFADOQ->FieldByName("SFZE")->AsString.Trim();
		XFADOQ->Close();

		XFADOQ->Close();
		XFADOQ->SQL->Clear();
		XFADOQ->SQL->Add(Allcssqlstr);
		XFADOQ->Open();
		BTMXShowFRM->AllCSTextEdit->Text = XFADOQ->FieldByName("allcs")->AsInteger;
		XFADOQ->Close();

		BTMXShowFRM->BeginDateTimeStr = XFBeginDateEdit->Text + " 00:00:00";
		BTMXShowFRM->EndDateTimeStr = XFEndDateEdit->Text + " 23:59:59";
		BTMXShowFRM->tag = radiotag;
		BTMXShowFRM->XFMXExportProgressBar->Position = 0;
		BTMXShowFRM->CZYStr = OperatorName;

		BTMXShowFRM->allsqlstr = MXsqlstr;
		BTMXShowFRM->XFMXADOQuery->Close();
		BTMXShowFRM->XFMXADOQuery->SQL->Clear();
		BTMXShowFRM->XFMXADOQuery->SQL->Add(displaysqlstr);
		BTMXShowFRM->ShowModal();
	}
	else
		ShowMessage("符合该查询条件的记录条数为0!");
}
//---------------------------------------------------------------------------

void __fastcall TBTFXMXQFrm::Button2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

