//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SZHZQForm.h"
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
#pragma link "frxDBSet"
#pragma link "cxMemo"
#pragma resource "*.dfm"
TSZHZQFrm *SZHZQFrm;
//---------------------------------------------------------------------------
__fastcall TSZHZQFrm::TSZHZQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSZHZQFrm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSZHZQFrm::ExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TSZHZQFrm::cxMemo1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSZHZQFrm::FormShow(TObject *Sender)
{
	QueryBTN->Enabled = true;
    ExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    ExitBTN->Enabled = true;

//	ZHBeginDateEdit->Text = "";
//    ZHEndDateEdit->Text = "";
	ZHBeginDateEdit->Date = Date();
	ZHEndDateEdit->Date = Date();

    cxMemo1->Text = "";
    cxMemo1->Lines->Clear();

    BMComboBox->Properties->Items->Clear();
    BMComboBox->Text = "";
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add("select * from BUMEN");
    ZHADOQuery->Open();
    if(!ZHADOQuery->IsEmpty())
    {
        ZHADOQuery->First();
        while(!ZHADOQuery->Eof)
        {
            BMComboBox->Properties->Items->Add(ZHADOQuery->FieldByName("BUMEN")->AsString.Trim());
            ZHADOQuery->Next();
        }
        BMComboBox->Properties->Items->Add("所有部门");
    }
    ZHADOQuery->Close();

    cxTextEdit1->Text = "";
    cxTextEdit10->Text = "";
    cxTextEdit12->Text = "";
    cxTextEdit13->Text = "";
    cxTextEdit15->Text = "";
    cxTextEdit18->Text = "";
    cxTextEdit2->Text = "";
    cxTextEdit20->Text = "";
    cxTextEdit22->Text = "";
    cxTextEdit23->Text = "";
    cxTextEdit25->Text = "";
    cxTextEdit27->Text = "";
    cxTextEdit28->Text = "";
    cxTextEdit3->Text = "";
    cxTextEdit30->Text = "";
    cxTextEdit32->Text = "";
    cxTextEdit33->Text = "";
    cxTextEdit35->Text = "";
    cxTextEdit37->Text = "";
    cxTextEdit38->Text = "";
    cxTextEdit39->Text = "";
    cxTextEdit4->Text = "";
    cxTextEdit40->Text = "";
    cxTextEdit42->Text = "";
    cxTextEdit43->Text = "";
    cxTextEdit44->Text = "";
    cxTextEdit45->Text = "";
    cxTextEdit46->Text = "";
    cxTextEdit47->Text = "";
    cxTextEdit48->Text = "";
    cxTextEdit5->Text = "";
    cxTextEdit51->Text = "";
    cxTextEdit52->Text = "";
    cxTextEdit53->Text = "";
    cxTextEdit54->Text = "";
    cxTextEdit55->Text = "";
    cxTextEdit56->Text = "";
    cxTextEdit57->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TSZHZQFrm::QueryBTNClick(TObject *Sender)
{
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
    cxTextEdit15->Text = "";

    cxTextEdit18->Text = "";
    cxTextEdit20->Text = "";
    cxTextEdit22->Text = "";

    cxTextEdit23->Text = "";
    cxTextEdit25->Text = "";
    cxTextEdit27->Text = "";

    cxTextEdit28->Text = "";
    cxTextEdit30->Text = "";
    cxTextEdit32->Text = "";

    cxTextEdit33->Text = "";
    cxTextEdit35->Text = "";
    cxTextEdit37->Text = "";

    cxTextEdit38->Text = "";
    cxTextEdit39->Text = "";
    cxTextEdit40->Text = "";
    cxTextEdit41->Text = "";
    cxTextEdit42->Text = "";

    cxTextEdit43->Text = "";
    cxTextEdit44->Text = "";
    cxTextEdit45->Text = "";
    cxTextEdit46->Text = "";
    cxTextEdit47->Text = "";

    cxTextEdit48->Text = "";
    cxTextEdit51->Text = "";
    cxTextEdit52->Text = "";

    cxTextEdit53->Text = "";
    cxTextEdit54->Text = "";
    cxTextEdit55->Text = "";
    cxTextEdit56->Text = "";
    cxTextEdit57->Text = "";

	if(ZHBeginDateEdit->Text.IsEmpty()||ZHEndDateEdit->Text.IsEmpty())
    {
        ShowMessage("必须完整填写查询条件!");
        return;
	}

/*	String YZT1str = "0";
	String YZT2str = "0";
	String YZT3str = "0";
	String YZT4str = "0";

	String XZT1str = "0";
	String XZT2str = "0";
	String XZT3str = "0";
	String XZT4str = "0";     */

    Beginstr = ZHBeginDateEdit->Text + " 00:00:00";
	Endstr = ZHEndDateEdit->Text + " 23:59:59";
	BMstr = BMComboBox->Text;

	String orignalcardstr = "";
	String currentcardstr = "";
	String orignalallcksqlstr = "select SUM(SFJE) as allck from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX in ('I','A') and SFRQ<'";
	String currentallcksqlstr = "select SUM(SFJE) as allck from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX in ('I','A') and SFRQ<='";
	String orignalallkksqlstr = "select SUM(MXBAK.SF_YE) as allkk from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='K' and SFRQ<'";
	String currentallkksqlstr = "select SUM(MXBAK.SF_YE) as allkk from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='K' and SFRQ<='";
	String orignalallqksqlstr = "select SUM(SFJE) as allqk from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX in ('d','T','Q') and SFRQ<'";
	String currentallqksqlstr = "select SUM(SFJE) as allqk from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX in ('d','T','Q') and SFRQ<='";
	String orignalallxfsqlstr = "select SUM(SFJE) as allxf from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='X' and SFRQ<'";
	String currentallxfsqlstr = "select SUM(SFJE) as allxf from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='X' and SFRQ<='";
	String orignalallqyjsqlstr = "select SUM(SFJE) as allqyj from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='R' and SFRQ<'";
	String currentallqyjsqlstr = "select SUM(SFJE) as allqyj from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='R' and SFRQ<='";
	String orignalallyjsqlstr = "select SUM(SFJE) as allyj from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='W' and SFRQ<'";
	String currentallyjsqlstr = "select SUM(SFJE) as allyj from MXBAK join CARD_F on  MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='W' and SFRQ<='";
	if(BMstr != "所有部门"&&!BMstr.IsEmpty())
	{
		orignalcardstr = "select * from CARD_F where ZT!='退卡' and RQ<'";
		orignalcardstr += Beginstr;
		orignalcardstr += "' and BM='";
		orignalcardstr += BMstr;
		orignalcardstr += "'";

		currentcardstr = "select * from CARD_F where ZT!='退卡' and RQ<='";
		currentcardstr += Endstr;
		currentcardstr += "' and BM='";
		currentcardstr += BMstr;
		currentcardstr += "'";

		orignalallcksqlstr += Beginstr;
		orignalallcksqlstr += "' and BM='";
		orignalallcksqlstr += BMstr;
		orignalallcksqlstr += "'";

		currentallcksqlstr += Endstr;
		currentallcksqlstr += "' and BM='";
		currentallcksqlstr += BMstr;
		currentallcksqlstr += "'";

		orignalallkksqlstr += Beginstr;
		orignalallkksqlstr += "' and BM='";
		orignalallkksqlstr += BMstr;
		orignalallkksqlstr += "'";

		currentallkksqlstr += Endstr;
		currentallkksqlstr += "' and BM='";
		currentallkksqlstr += BMstr;
		currentallkksqlstr += "'";

		orignalallqksqlstr += Beginstr;
		orignalallqksqlstr += "' and BM='";
		orignalallqksqlstr += BMstr;
		orignalallqksqlstr += "'";

		currentallqksqlstr += Endstr;
		currentallqksqlstr += "' and BM='";
		currentallqksqlstr += BMstr;
		currentallqksqlstr += "'";

		orignalallxfsqlstr += Beginstr;
		orignalallxfsqlstr += "' and BM='";
		orignalallxfsqlstr += BMstr;
		orignalallxfsqlstr += "'";

		currentallxfsqlstr += Endstr;
		currentallxfsqlstr += "' and BM='";
		currentallxfsqlstr += BMstr;
		currentallxfsqlstr += "'";

		orignalallqyjsqlstr += Beginstr;
		orignalallqyjsqlstr += "' and BM='";
		orignalallqyjsqlstr += BMstr;
		orignalallqyjsqlstr += "'";

		currentallqyjsqlstr += Endstr;
		currentallqyjsqlstr += "' and BM='";
		currentallqyjsqlstr += BMstr;
		currentallqyjsqlstr += "'";

		orignalallyjsqlstr += Beginstr;
		orignalallyjsqlstr += "' and BM='";
		orignalallyjsqlstr += BMstr;
		orignalallyjsqlstr += "'";

		currentallyjsqlstr += Endstr;
		currentallyjsqlstr += "' and BM='";
		currentallyjsqlstr += BMstr;
		currentallyjsqlstr += "'";
	}
	else
	{
		orignalcardstr = "select * from CARD_F where ZT!='退卡' and ZT!='挂补' and RQ<'";
		orignalcardstr += Beginstr;
		orignalcardstr += "'";

		currentcardstr = "select * from CARD_F where ZT!='退卡' and ZT!='挂补' and RQ<='";
		currentcardstr += Endstr;
		currentcardstr += "'";

		orignalallcksqlstr += Beginstr;
		orignalallcksqlstr += "'";

		currentallcksqlstr += Endstr;
		currentallcksqlstr += "'";

		orignalallkksqlstr += Beginstr;
		orignalallkksqlstr += "'";

		currentallkksqlstr += Endstr;
		currentallkksqlstr += "'";


		orignalallqksqlstr += Beginstr;
		orignalallqksqlstr += "'";

		currentallqksqlstr += Endstr;
		currentallqksqlstr += "'";

		orignalallxfsqlstr += Beginstr;
		orignalallxfsqlstr += "'";

		currentallxfsqlstr += Endstr;
		currentallxfsqlstr += "'";

		orignalallqyjsqlstr += Beginstr;
		orignalallqyjsqlstr += "'";

		currentallqyjsqlstr += Endstr;
		currentallqyjsqlstr += "'";

		orignalallyjsqlstr += Beginstr;
		orignalallyjsqlstr += "'";

		currentallyjsqlstr += Endstr;
		currentallyjsqlstr += "'";
	}

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(orignalcardstr);
	ADOQuery1->Open();
	if(ADOQuery1->IsEmpty())
	{
		YZT1str = "0";         //卡数
		YZT2str = "0";         //总余额
		YZT3str = "0";         //总押金
		YZT4str = "0";         //总额
	}
	else
	{
		YZT1str = IntToStr(ADOQuery1->RecordCount);
		int ock,okk,oqk,oxf,oqyj,oyj;
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(orignalallcksqlstr);
		ADOQuery1->Open();
		ock = ADOQuery1->FieldByName("allck")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(orignalallkksqlstr);
		ADOQuery1->Open();
		okk = ADOQuery1->FieldByName("allkk")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(orignalallqksqlstr);
		ADOQuery1->Open();
		oqk = ADOQuery1->FieldByName("allqk")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(orignalallxfsqlstr);
		ADOQuery1->Open();
		oxf = ADOQuery1->FieldByName("allxf")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(orignalallqyjsqlstr);
		ADOQuery1->Open();
		oqyj = ADOQuery1->FieldByName("allqyj")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(orignalallyjsqlstr);
		ADOQuery1->Open();
		oyj = ADOQuery1->FieldByName("allyj")->AsFloat*10;
		ADOQuery1->Close();

		YZT2str = FloatToStr(((ock + okk - oqk - oxf)*1.0)/10);
		YZT3str = FloatToStr(((oyj - oqyj)*1.0)/10);
		YZT4str = FloatToStr(((ock + okk - oqk - oxf + oyj - oqyj)*1.0)/10);
	}

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(currentcardstr);
	ADOQuery1->Open();
	if(ADOQuery1->IsEmpty())
	{
		XZT1str = "0";
		XZT2str = "0";
		XZT3str = "0";
		XZT4str = "0";
	}
	else
	{
		XZT1str = IntToStr(ADOQuery1->RecordCount);
		int cck,ckk,cqk,cxf,cqyj,cyj;
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(currentallcksqlstr);
		ADOQuery1->Open();
		cck = ADOQuery1->FieldByName("allck")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(currentallkksqlstr);
		ADOQuery1->Open();
		ckk = ADOQuery1->FieldByName("allkk")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(currentallqksqlstr);
		ADOQuery1->Open();
		cqk = ADOQuery1->FieldByName("allqk")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(currentallxfsqlstr);
		ADOQuery1->Open();
		cxf = ADOQuery1->FieldByName("allxf")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(currentallqyjsqlstr);
		ADOQuery1->Open();
		cqyj = ADOQuery1->FieldByName("allqyj")->AsFloat*10;
		ADOQuery1->Close();

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(currentallyjsqlstr);
		ADOQuery1->Open();
		cyj = ADOQuery1->FieldByName("allyj")->AsFloat*10;
		ADOQuery1->Close();

		XZT2str = FloatToStr(((cck + ckk- cqk - cxf)*1.0)/10);
		XZT3str = FloatToStr(((cyj - cqyj)*1.0)/10);
		XZT4str = FloatToStr(((cck + ckk - cqk - cxf + cyj - cqyj)*1.0)/10);
	}
/*
	String orignalcardstr = "";
	String currentcardstr = "";
    String originalstatesqlstr = "";
    String currentstatesqlstr = "";
	if(BMstr != "所有部门"&&!BMstr.IsEmpty())
	{
		orignalcardstr = "select BH,KH,SUM(YJ) as YJE from CARD_F where RQ<'";
		orignalcardstr += Beginstr;
		orignalcardstr += "' and BM='";
		orignalcardstr += BMstr;
		orignalcardstr += "' group by BH,KH";

		currentcardstr = "select BH,KH,SUM(YJ) as YJE from CARD_F where RQ<='";
		currentcardstr += Endstr;
		currentcardstr += "' and BM='";
		currentcardstr += BMstr;
		currentcardstr += "' group by BH,KH";
    }
	else
	{
//		originalstatesqlstr = "select count(*) as KPS,SUM(SF_YE) as YE,SUM(YJ) as YJE,SUM(SF_YE+YJ) as ZJE from CARD where ZT='发卡' and RQ<='";
//		originalstatesqlstr += Beginstr;
//		originalstatesqlstr += "'";

//		currentstatesqlstr = "select count(*) as KPS,SUM(SF_YE) as YE,SUM(YJ) as YJE,SUM(SF_YE+YJ) as ZJE from CARD where ZT='发卡' and RQ<='";
 //		currentstatesqlstr += Endstr;
//		currentstatesqlstr += "'";
		orignalcardstr = "select BH,KH,SUM(YJ) as YJE from CARD_F where RQ<'";
		orignalcardstr += Beginstr;
		orignalcardstr += "' group by BH,KH";

		currentcardstr = "select BH,KH,SUM(YJ) as YJE from CARD_F where RQ<='";
		currentcardstr += Endstr;
		currentcardstr += "' group by BH,KH";
    }

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(orignalcardstr);
	ADOQuery1->Open();
	if(ADOQuery1->IsEmpty())
	{
		YZT1str = "0";
		YZT2str = "0";
		YZT3str = "0";
		YZT4str = "0";
	}
	else
	{
		ADOQuery1->First();
		YZT1str = IntToStr(ADOQuery1->RecordCount);
		int ye,yje,zje;
		ye = 0;
		yje = (int)(ADOQuery1->FieldByName("YJE")->AsFloat*100);
		zje = 0;
		String kysqlstr;// = "select SF_YE from MXBAK where BH='";
		while(!ADOQuery1->Eof)
		{
			kysqlstr = "select top 1 SF_YE from MXBAK where BH='";
			kysqlstr += ADOQuery1->FieldByName("BH")->AsString.Trim();
			kysqlstr += "' and KH=";
			kysqlstr += ADOQuery1->FieldByName("KH")->AsString;
			kysqlstr += " and sfrq<'";
			kysqlstr += Beginstr;
			kysqlstr += "' order by SYCS desc";
			ADOQuery2->Close();
			ADOQuery2->SQL->Clear();
			ADOQuery2->SQL->Add(kysqlstr);
			ADOQuery2->Open();
			if(!ADOQuery2->IsEmpty())
			{
				ye += (int)(ADOQuery2->FieldByName("SF_YE")->AsFloat*100);
			}
			ADOQuery2->Close();
			ADOQuery1->Next();
		}
		zje = ye+yje;
		YZT2str = FloatToStr(((float)ye)/100);
		YZT3str = FloatToStr(((float)yje)/100);
		YZT4str = FloatToStr(((float)(ye+yje))/100);
	}
	ADOQuery1->Close();

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(currentcardstr);
	ADOQuery1->Open();
	if(ADOQuery1->IsEmpty())
	{
		XZT1str = "0";
		XZT2str = "0";
		XZT3str = "0";
		XZT4str = "0";
	}
	else
	{
		ADOQuery1->First();
		XZT1str = IntToStr(ADOQuery1->RecordCount);
		int ye,yje,zje;
		ye = 0;
		yje = (int)(ADOQuery1->FieldByName("YJE")->AsFloat*100);
		zje = 0;
		String kysqlstr;// = "select SF_YE from MXBAK where BH='";
		while(!ADOQuery1->Eof)
		{
			kysqlstr = "select top 1 SF_YE from MXBAK where BH='";
			kysqlstr += ADOQuery1->FieldByName("BH")->AsString.Trim();
			kysqlstr += "' and KH=";
			kysqlstr += ADOQuery1->FieldByName("KH")->AsString;
			kysqlstr += " and sfrq<='";
			kysqlstr += Endstr;
			kysqlstr += "' order by SYCS desc";
			ADOQuery2->Close();
			ADOQuery2->SQL->Clear();
			ADOQuery2->SQL->Add(kysqlstr);
			ADOQuery2->Open();
			if(!ADOQuery2->IsEmpty())
			{
				ye += (int)(ADOQuery2->FieldByName("SF_YE")->AsFloat*100);
			}
			ADOQuery2->Close();
			ADOQuery1->Next();
		}
		zje = ye+yje;
		XZT2str = FloatToStr(((float)ye)/100);
		XZT3str = FloatToStr(((float)yje)/100);
		XZT4str = FloatToStr(((float)(ye+yje))/100);
	}
	ADOQuery1->Close();       */
/*
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(originalstatesqlstr);
    ZHADOQuery->Open();
	YZT1str = IntToStr(ZHADOQuery->FieldByName("KPS")->AsInteger);
	YZT2str = FloatToStr(ZHADOQuery->FieldByName("YE")->AsFloat);
	YZT3str = FloatToStr(ZHADOQuery->FieldByName("YJE")->AsFloat);
	YZT4str = FloatToStr(ZHADOQuery->FieldByName("ZJE")->AsFloat);
    ZHADOQuery->Close();

    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(currentstatesqlstr);
    ZHADOQuery->Open();
    XZT1str = IntToStr(ZHADOQuery->FieldByName("KPS")->AsInteger);
    XZT2str = FloatToStr(ZHADOQuery->FieldByName("YE")->AsFloat);
    XZT3str = FloatToStr(ZHADOQuery->FieldByName("YJE")->AsFloat);
    XZT4str = FloatToStr(ZHADOQuery->FieldByName("ZJE")->AsFloat);
	ZHADOQuery->Close();  */

    ZBHL1str = IntToStr(StrToInt(XZT1str)-StrToInt(YZT1str));
    ZBHL2str = FloatToStr(StrToFloat(XZT2str)-StrToFloat(YZT2str));
    ZBHL3str = FloatToStr(StrToFloat(XZT3str)-StrToFloat(YZT3str));
    ZBHL4str = FloatToStr(StrToFloat(XZT4str)-StrToFloat(YZT4str));

    String XFsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
    {
		XFsqlstr = "select count(*) as SFZCS,SUM(-SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='X' and SFRQ>='";
        XFsqlstr += Beginstr;
        XFsqlstr += "' and SFRQ<='";
        XFsqlstr += Endstr;
        XFsqlstr += "' and BM='";
        XFsqlstr += BMstr;
        XFsqlstr += "'";
    }
    else
    {
		XFsqlstr = "select count(*) as SFZCS,SUM(-SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='X' and SFRQ>='";
        XFsqlstr += Beginstr;
        XFsqlstr += "' and SFRQ<='";
        XFsqlstr += Endstr;
        XFsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(XFsqlstr);
    ZHADOQuery->Open();
    KPXF1str = IntToStr(ZHADOQuery->FieldByName("SFZCS")->AsInteger);
    KPXF2str = FloatToStr(((int)(ZHADOQuery->FieldByName("SFZE")->AsFloat*10)*1.0)/10);
    ZHADOQuery->Close();

    String DKQCZsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
    {
		DKQCZsqlstr = "select count(*) as DKQCZCS,SUM(SFJE) as KDQCZZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='a' and SFRQ>='";
        DKQCZsqlstr += Beginstr;
        DKQCZsqlstr += "' and SFRQ<='";
        DKQCZsqlstr += Endstr;
        DKQCZsqlstr += "' and BM='";
        DKQCZsqlstr += BMstr;
        DKQCZsqlstr += "'";
    }
    else
    {
		DKQCZsqlstr = "select count(*) as DKQCZCS,SUM(SFJE) as KDQCZZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='a' and SFRQ>='";
        DKQCZsqlstr += Beginstr;
        DKQCZsqlstr += "' and SFRQ<='";
        DKQCZsqlstr += Endstr;
        DKQCZsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(DKQCZsqlstr);
    ZHADOQuery->Open();
    DKQCK1str = IntToStr(ZHADOQuery->FieldByName("DKQCZCS")->AsInteger);
    DKQCK2str = FloatToStr(ZHADOQuery->FieldByName("KDQCZZE")->AsFloat);
    DKQCK3str = FloatToStr(ZHADOQuery->FieldByName("KDQCZZE")->AsFloat);
    ZHADOQuery->Close();

    String CZJCZsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
    {
		CZJCZsqlstr = "select count(*) as CZJCZCS,SUM(SFJE) as CZJCZZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='I' and SFRQ>='";
        CZJCZsqlstr += Beginstr;
        CZJCZsqlstr += "' and SFRQ<='";
        CZJCZsqlstr += Endstr;
        CZJCZsqlstr += "' and BM='";
        CZJCZsqlstr += BMstr;
        CZJCZsqlstr += "'";
    }
    else
    {
		CZJCZsqlstr = "select count(*) as CZJCZCS,SUM(SFJE) as CZJCZZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='I' and SFRQ>='";
        CZJCZsqlstr += Beginstr;
        CZJCZsqlstr += "' and SFRQ<='";
        CZJCZsqlstr += Endstr;
        CZJCZsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(CZJCZsqlstr);
    ZHADOQuery->Open();
    CZJCZ1str = IntToStr(ZHADOQuery->FieldByName("CZJCZCS")->AsInteger);
	CZJCZ2str = FloatToStr(((int)(ZHADOQuery->FieldByName("CZJCZZE")->AsFloat*10)*1.0)/10);
	CZJCZ3str = FloatToStr(((int)(ZHADOQuery->FieldByName("CZJCZZE")->AsFloat*10)*1.0)/10);
    ZHADOQuery->Close();

    BT1str = "0";
    BT2str = "0";
    BT3str = "0";

    String QKsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
    {
		QKsqlstr = "select count(*) as QKCS, SUM(-SFJE) as QKZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='D' and SFRQ>='";
        QKsqlstr += Beginstr;
        QKsqlstr += "' and SFRQ<='";
        QKsqlstr += Endstr;
        QKsqlstr += "' and BM='";
        QKsqlstr += BMstr;
        QKsqlstr += "'";
    }
    else
    {
		QKsqlstr = "select count(*) as QKCS, SUM(-SFJE) as QKZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='D' and SFRQ>='";
        QKsqlstr += Beginstr;
        QKsqlstr += "' and SFRQ<='";
        QKsqlstr += Endstr;
        QKsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(QKsqlstr);
    ZHADOQuery->Open();
    QK1str = IntToStr(ZHADOQuery->FieldByName("QKCS")->AsInteger);
	QK2str = FloatToStr(((int)(ZHADOQuery->FieldByName("QKZE")->AsFloat*10)*1.0)/10);
	QK3str = FloatToStr(((int)(ZHADOQuery->FieldByName("QKZE")->AsFloat*10)*1.0)/10);
    ZHADOQuery->Close();

    String KHsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
	{
		KHsqlstr = "select SUM(case when SFLX='K' then 1 else 0 end) as KHCS,SUM(case when SFLX='K' then MXBAK.SF_YE else 0 end) as KHZE,SUM(case when SFLX='W' then MXBAK.SFJE else 0 end) as YJZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where (SFLX='K' or SFLX='W') and SFRQ>='";
    	KHsqlstr += Beginstr;
        KHsqlstr += "' and SFRQ<='";
        KHsqlstr += Endstr;
        KHsqlstr += "' and BM='";
        KHsqlstr += BMstr;
        KHsqlstr += "'";
    }
    else
    {
		KHsqlstr = "select SUM(case when SFLX='K' then 1 else 0 end) as KHCS,SUM(case when SFLX='K' then MXBAK.SF_YE else 0 end) as KHZE,SUM(case when SFLX='W' then MXBAK.SFJE else 0 end) as YJZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where (SFLX='K' or SFLX='W') and SFRQ>='";
    	KHsqlstr += Beginstr;
        KHsqlstr += "' and SFRQ<='";
        KHsqlstr += Endstr;
        KHsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(KHsqlstr);
    ZHADOQuery->Open();
    KH1str = IntToStr(ZHADOQuery->FieldByName("KHCS")->AsInteger);
    KH2str = IntToStr(ZHADOQuery->FieldByName("KHCS")->AsInteger);
	KH3str = FloatToStr(((int)(ZHADOQuery->FieldByName("KHZE")->AsFloat*10)*1.0)/10);
	KH4str = FloatToStr(((int)(ZHADOQuery->FieldByName("YJZE")->AsFloat*10)*1.0)/10);
	KH5str = FloatToStr(((int)(ZHADOQuery->FieldByName("KHZE")->AsFloat*10)*1.0)/10);
    ZHADOQuery->Close();

    String TKsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
    {
    /*	TKsqlstr = "select SUM(TKJE) as alltkje,SUM(TKCB) as alltkcb,COUNT(*) as allcs from CARD_T where TKRQ>='";
        TKsqlstr += Beginstr;
        TKsqlstr += "' and TKRQ<='";
        TKsqlstr += Endstr;
        TKsqlstr += "' and BM='";
        TKsqlstr += BMstr;
        TKsqlstr += "'";   */
        TKsqlstr = "select SUM(CARD_T.TKJE) as alltkje,SUM(CARD_T.TKCB) as alltkcb,COUNT(*) as allcs from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡') and CARD_T.TKRQ>='";
        TKsqlstr += Beginstr;
        TKsqlstr += "' and CARD_T.TKRQ<='";
        TKsqlstr += Endstr;
        TKsqlstr += "' and CARD_T.BM='";
        TKsqlstr += BMstr;
        TKsqlstr += "'";
    }
    else
    {
	/*	TKsqlstr = "select SUM(TKJE) as alltkje,SUM(TKCB) as alltkcb,COUNT(*) as allcs from CARD_T where TKRQ>='";
    	TKsqlstr += Beginstr;
        TKsqlstr += "' and TKRQ<='";
        TKsqlstr += Endstr;
        TKsqlstr += "'";   */
        TKsqlstr = "select SUM(CARD_T.TKJE) as alltkje,SUM(CARD_T.TKCB) as alltkcb,COUNT(*) as allcs from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡') and CARD_T.TKRQ>='";
        TKsqlstr += Beginstr;
        TKsqlstr += "' and CARD_T.TKRQ<='";
        TKsqlstr += Endstr;
        TKsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(TKsqlstr);
    ZHADOQuery->Open();
    TK1str = IntToStr(ZHADOQuery->FieldByName("allcs")->AsInteger);
    TK2str = IntToStr(-ZHADOQuery->FieldByName("allcs")->AsInteger);
	TK3str = FloatToStr(-((int)(ZHADOQuery->FieldByName("alltkje")->AsFloat*10)*1.0)/10);
	TK4str = FloatToStr(-((int)(ZHADOQuery->FieldByName("alltkcb")->AsFloat*10)*1.0)/10);
	TK5str = FloatToStr(-((int)(ZHADOQuery->FieldByName("alltkje")->AsFloat*10)*1.0)/10);
    ZHADOQuery->Close();

    String BKsqlstr = "";
    if(BMstr != "所有部门"&&!BMstr.IsEmpty())
    {
		BKsqlstr = "select SUM(case when SFLX='F' then 1 else 0 end) as BKCS,SUM(case when SFLX='G' then MXBAK.SFJE else 0 end) as BKYJZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where (SFLX='G' or SFLX='F') and SFRQ>='";
        BKsqlstr += Beginstr;
        BKsqlstr += "' and SFRQ<='";
        BKsqlstr += Endstr;
        BKsqlstr += "' and BM='";
        BKsqlstr += BMstr;
        BKsqlstr += "'";
    }
    else
    {
		BKsqlstr = "select SUM(case when SFLX='F' then 1 else 0 end) as BKCS,SUM(case when SFLX='G' then MXBAK.SFJE else 0 end) as BKYJZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where (SFLX='G' or SFLX='F') and SFRQ>='";
        BKsqlstr += Beginstr;
        BKsqlstr += "' and SFRQ<='";
        BKsqlstr += Endstr;
        BKsqlstr += "'";
    }
    ZHADOQuery->Close();
    ZHADOQuery->SQL->Clear();
    ZHADOQuery->SQL->Add(BKsqlstr);
    ZHADOQuery->Open();
    BK1str = IntToStr(ZHADOQuery->FieldByName("BKCS")->AsInteger);
	BK2str = FloatToStr(((int)(ZHADOQuery->FieldByName("BKYJZE")->AsFloat*10)*1.0)/10);
	BK3str = FloatToStr(((int)(ZHADOQuery->FieldByName("BKYJZE")->AsFloat*10)*1.0)/10);
    ZHADOQuery->Close();

    ZJ1str = IntToStr(StrToInt(KPXF1str)+StrToInt(DKQCK1str)+StrToInt(CZJCZ1str)
    				  +StrToInt(BT1str)+StrToInt(QK1str)+StrToInt(KH1str)
                      +StrToInt(TK1str)+StrToInt(BK1str));

    ZJ2str = IntToStr(StrToInt(KH2str)+StrToInt(TK2str));

    ZJ3str = FloatToStr(StrToFloat(KPXF2str)+StrToFloat(DKQCK2str)+StrToFloat(CZJCZ2str)
    					+StrToFloat(BT2str)+StrToFloat(QK2str)+StrToFloat(KH3str)
                        +StrToFloat(TK3str));

    ZJ4str = FloatToStr(StrToFloat(KH4str)+StrToFloat(TK4str)+StrToFloat(BK2str));

    ZJ5str = FloatToStr(StrToFloat(DKQCK3str)+StrToFloat(CZJCZ3str)+StrToFloat(BT3str)
    					+StrToFloat(QK3str)+StrToFloat(KH5str)+StrToFloat(TK5str)
                        +StrToFloat(BK3str));

    cxMemo1->Lines->Clear();
    cxMemo1->Text = "";
    STADOQuery->Close();
    STADOQuery->SQL->Clear();
    STADOQuery->SQL->Add("select * from STNAME");
    STADOQuery->Open();
    if(!STADOQuery->IsEmpty())
    {
        STADOQuery->First();
        while(!STADOQuery->Eof)
        {
        	String Subsqlstr = "";
			if((!BMstr.IsEmpty())&&(BMstr != "所有部门"))
    		{
				Subsqlstr = "select count(*) as cns,SUM(-SFJE) as SFZE from MXBAK join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='X' and SFRQ>='";
            	Subsqlstr += Beginstr;
                Subsqlstr += "' and SFRQ<='";
                Subsqlstr += Endstr;
                Subsqlstr += "' and BM='";
                Subsqlstr += BMstr;
                Subsqlstr += "' and STNAME='";
                Subsqlstr += STADOQuery->FieldByName("STNAME")->AsString.Trim();
                Subsqlstr += "'";
            }
            else
            {
				Subsqlstr = "select count(*) as cns,SUM(-SFJE) as SFZE from MXBAK join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='X' and SFRQ>='";
            	Subsqlstr += Beginstr;
                Subsqlstr += "' and SFRQ<='";
                Subsqlstr += Endstr;
                Subsqlstr += "' and STNAME='";
                Subsqlstr += STADOQuery->FieldByName("STNAME")->AsString.Trim();
                Subsqlstr += "'";
            }

			ZHADOQuery->Close();
            ZHADOQuery->SQL->Clear();
            ZHADOQuery->SQL->Add(Subsqlstr);
            ZHADOQuery->Open();
            String tempout = STADOQuery->FieldByName("STNAME")->AsString.Trim();
			tempout += "		                  ";
			tempout += FloatToStr(((int)(ZHADOQuery->FieldByName("SFZE")->AsFloat*10)*1.0)/10);
            tempout += "		                  ";
            tempout += IntToStr(ZHADOQuery->FieldByName("cns")->AsInteger);
            cxMemo1->Lines->Add(tempout);
            ZHADOQuery->Close();
            STADOQuery->Next();
        }
    }
    STADOQuery->Close();

    cxTextEdit1->Text = XZT1str;
    cxTextEdit2->Text = XZT2str;
    cxTextEdit3->Text = XZT3str;
    cxTextEdit4->Text = XZT4str;

    cxTextEdit5->Text = YZT1str;
    cxTextEdit6->Text = YZT2str;
    cxTextEdit7->Text = YZT3str;
    cxTextEdit8->Text = YZT4str;

    cxTextEdit9->Text = ZBHL1str;
    cxTextEdit10->Text = ZBHL2str;
    cxTextEdit11->Text = ZBHL3str;
    cxTextEdit12->Text = ZBHL4str;

    cxTextEdit13->Text = KPXF1str;
    cxTextEdit15->Text = KPXF2str;

    cxTextEdit18->Text = DKQCK1str;
    cxTextEdit20->Text = DKQCK2str;
    cxTextEdit22->Text = DKQCK3str;

    cxTextEdit23->Text = CZJCZ1str;
    cxTextEdit25->Text = CZJCZ2str;
    cxTextEdit27->Text = CZJCZ3str;

    cxTextEdit28->Text = BT1str;
    cxTextEdit30->Text = BT2str;
    cxTextEdit32->Text = BT3str;

    cxTextEdit33->Text = QK1str;
    cxTextEdit35->Text = QK2str;
    cxTextEdit37->Text = QK3str;

    cxTextEdit38->Text = KH1str;
    cxTextEdit39->Text = KH2str;
    cxTextEdit40->Text = KH3str;
    cxTextEdit41->Text = KH4str;
    cxTextEdit42->Text = KH5str;

    cxTextEdit43->Text = TK1str;
    cxTextEdit44->Text = TK2str;
    cxTextEdit45->Text = TK3str;
    cxTextEdit46->Text = TK4str;
    cxTextEdit47->Text = TK5str;

    cxTextEdit48->Text = BK1str;
    cxTextEdit51->Text = BK2str;
    cxTextEdit52->Text = BK3str;

    cxTextEdit53->Text = ZJ1str;
    cxTextEdit54->Text = ZJ2str;
    cxTextEdit55->Text = ZJ3str;
    cxTextEdit56->Text = ZJ4str;
    cxTextEdit57->Text = ZJ5str;

    ExportBTN->Enabled = true;
    PreviewBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSZHZQFrm::ExportBTNClick(TObject *Sender)
{
	QueryBTN->Enabled = false;
    ExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    ExitBTN->Enabled = false;
    String savename;

    if(SaveDialog->Execute())
    {
        if(FileExists(SaveDialog->FileName+".xls"))
        {
            QueryBTN->Enabled = true;
            ExportBTN->Enabled = true;
            PreviewBTN->Enabled = true;
            ExitBTN->Enabled = true;
            throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
            return;
        }
        else
        {
            savename = SaveDialog->FileName;
            savename += ".xls";
        }
    }

    Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(this->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
        QueryBTN->Enabled = true;
        ExportBTN->Enabled = true;
        PreviewBTN->Enabled = true;
        ExitBTN->Enabled = true;
		return;
	}

    String Templatepath = GlobalPath + "\\ExportXLSTemplate\\SZHZTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    String tmpoutstr = "";

    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", OperatorName.t_str());
    ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", Beginstr.t_str());
    ST.OlePropertyGet("Cells",2,6).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", BMstr.t_str());
    ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", Endstr.t_str());

    ST.OlePropertyGet("Cells",5,3).OlePropertySet("Value",XZT1str.t_str());
    ST.OlePropertyGet("Cells",5,4).OlePropertySet("Value",XZT2str.t_str());
    ST.OlePropertyGet("Cells",5,5).OlePropertySet("Value",XZT3str.t_str());
    ST.OlePropertyGet("Cells",5,6).OlePropertySet("Value",XZT4str.t_str());

    ST.OlePropertyGet("Cells",6,3).OlePropertySet("Value",YZT1str.t_str());
    ST.OlePropertyGet("Cells",6,4).OlePropertySet("Value",YZT2str.t_str());
    ST.OlePropertyGet("Cells",6,5).OlePropertySet("Value",YZT3str.t_str());
    ST.OlePropertyGet("Cells",6,6).OlePropertySet("Value",YZT4str.t_str());

    ST.OlePropertyGet("Cells",7,3).OlePropertySet("Value",ZBHL1str.t_str());
    ST.OlePropertyGet("Cells",7,4).OlePropertySet("Value",ZBHL1str.t_str());
    ST.OlePropertyGet("Cells",7,5).OlePropertySet("Value",ZBHL1str.t_str());
    ST.OlePropertyGet("Cells",7,6).OlePropertySet("Value",ZBHL1str.t_str());

    ST.OlePropertyGet("Cells",9,2).OlePropertySet("Value",KPXF1str.t_str());
    ST.OlePropertyGet("Cells",9,4).OlePropertySet("Value",KPXF2str.t_str());

    ST.OlePropertyGet("Cells",10,2).OlePropertySet("Value",DKQCK1str.t_str());
    ST.OlePropertyGet("Cells",10,4).OlePropertySet("Value",DKQCK2str.t_str());
    ST.OlePropertyGet("Cells",10,6).OlePropertySet("Value",DKQCK3str.t_str());

    ST.OlePropertyGet("Cells",11,2).OlePropertySet("Value",CZJCZ1str.t_str());
    ST.OlePropertyGet("Cells",11,4).OlePropertySet("Value",CZJCZ2str.t_str());
    ST.OlePropertyGet("Cells",11,6).OlePropertySet("Value",CZJCZ3str.t_str());

    ST.OlePropertyGet("Cells",12,2).OlePropertySet("Value",BT1str.t_str());
    ST.OlePropertyGet("Cells",12,4).OlePropertySet("Value",BT2str.t_str());
    ST.OlePropertyGet("Cells",12,6).OlePropertySet("Value",BT3str.t_str());

    ST.OlePropertyGet("Cells",13,2).OlePropertySet("Value",QK1str.t_str());
    ST.OlePropertyGet("Cells",13,4).OlePropertySet("Value",QK2str.t_str());
    ST.OlePropertyGet("Cells",13,6).OlePropertySet("Value",QK3str.t_str());

    ST.OlePropertyGet("Cells",14,2).OlePropertySet("Value",KH1str.t_str());
    ST.OlePropertyGet("Cells",14,3).OlePropertySet("Value",KH2str.t_str());
    ST.OlePropertyGet("Cells",14,4).OlePropertySet("Value",KH3str.t_str());
    ST.OlePropertyGet("Cells",14,5).OlePropertySet("Value",KH4str.t_str());
    ST.OlePropertyGet("Cells",14,6).OlePropertySet("Value",KH5str.t_str());

    ST.OlePropertyGet("Cells",15,2).OlePropertySet("Value",TK1str.t_str());
    ST.OlePropertyGet("Cells",15,3).OlePropertySet("Value",TK2str.t_str());
    ST.OlePropertyGet("Cells",15,4).OlePropertySet("Value",TK3str.t_str());
    ST.OlePropertyGet("Cells",15,5).OlePropertySet("Value",TK4str.t_str());
    ST.OlePropertyGet("Cells",15,6).OlePropertySet("Value",TK5str.t_str());

    ST.OlePropertyGet("Cells",16,2).OlePropertySet("Value",BK1str.t_str());
    ST.OlePropertyGet("Cells",16,5).OlePropertySet("Value",BK2str.t_str());
    ST.OlePropertyGet("Cells",16,6).OlePropertySet("Value",BK3str.t_str());

    ST.OlePropertyGet("Cells",17,2).OlePropertySet("Value",ZJ1str.t_str());
    ST.OlePropertyGet("Cells",17,3).OlePropertySet("Value",ZJ2str.t_str());
    ST.OlePropertyGet("Cells",17,4).OlePropertySet("Value",ZJ3str.t_str());
    ST.OlePropertyGet("Cells",17,5).OlePropertySet("Value",ZJ4str.t_str());
    ST.OlePropertyGet("Cells",17,6).OlePropertySet("Value",ZJ5str.t_str());

    STADOQuery->Close();
    STADOQuery->SQL->Clear();
    STADOQuery->SQL->Add("select * from STNAME");
    STADOQuery->Open();
    if(!STADOQuery->IsEmpty())
    {
        STADOQuery->First();
        int circletag = 0;
        double ZE = 0;
        int CS = 0;
        while(!STADOQuery->Eof)
        {
        	String Subsqlstr = "";
            if((BMstr != "所有部门")&&(!BMstr.IsEmpty()))
    		{
				Subsqlstr = "select count(*) as cns,SUM(-SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='X' and SFRQ>='";
            	Subsqlstr += Beginstr;
                Subsqlstr += "' and SFRQ<='";
                Subsqlstr += Endstr;
                Subsqlstr += "' and BM='";
                Subsqlstr += BMstr;
                Subsqlstr += "' and STNAME='";
                Subsqlstr += STADOQuery->FieldByName("STNAME")->AsString.Trim();
                Subsqlstr += "'";
            }
            else
			{
				Subsqlstr = "select count(*) as cns,SUM(-SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='X' and SFRQ>='";
            	Subsqlstr += Beginstr;
                Subsqlstr += "' and SFRQ<='";
                Subsqlstr += Endstr;
                Subsqlstr += "' and STNAME='";
                Subsqlstr += STADOQuery->FieldByName("STNAME")->AsString.Trim();
				Subsqlstr += "'";
            }

        	ZHADOQuery->Close();
            ZHADOQuery->SQL->Clear();
            ZHADOQuery->SQL->Add(Subsqlstr);
            ZHADOQuery->Open();
            ST.OlePropertyGet("Cells",20 + circletag,1).OlePropertySet("Value",STADOQuery->FieldByName("STNAME")->AsString.Trim().t_str());
            ST.OlePropertyGet("Cells",20 + circletag,3).OlePropertySet("Value",ZHADOQuery->FieldByName("SFZE")->AsFloat);
            ST.OlePropertyGet("Cells",20 + circletag,5).OlePropertySet("Value",ZHADOQuery->FieldByName("cns")->AsInteger);
            ZE += ZHADOQuery->FieldByName("SFZE")->AsFloat;
            CS += ZHADOQuery->FieldByName("cns")->AsInteger;
            ZHADOQuery->Close();
            STADOQuery->Next();
            circletag++;
        }
	    ST.OlePropertyGet("Cells",20 + circletag,1).OlePropertySet("Value","总计");
	    ST.OlePropertyGet("Cells",20 + circletag,3).OlePropertySet("Value",ZE);
	    ST.OlePropertyGet("Cells",20 + circletag,5).OlePropertySet("Value",CS);
    }
    STADOQuery->Close();

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
    WB.OleFunction("SaveAs", savename.t_str());
    ExcelApp.OleFunction("Quit");
    ExcelApp = Unassigned;
    MessageBox(this->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    QueryBTN->Enabled = true;
    ExportBTN->Enabled = true;
    PreviewBTN->Enabled = true;
    ExitBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSZHZQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\SZHZMXPreview.fr3";
    frxZHReport->LoadFromFile(temppath.t_str(), true);
    ((TfrxMemoView*)frxZHReport->FindObject("Beginstr"))->Text = Beginstr.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("Endstr"))->Text = Endstr.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("BMstr"))->Text = BMstr.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("SCRQ"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("CZY"))->Text = OperatorName.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("XZT1str"))->Text = XZT1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("XZT2str"))->Text = XZT2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("XZT3str"))->Text = XZT3str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("XZT4str"))->Text = XZT4str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("YZT1str"))->Text = YZT1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("YZT2str"))->Text = YZT2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("YZT3str"))->Text = YZT3str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("YZT4str"))->Text = YZT4str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("ZBHL1str"))->Text = ZBHL1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZBHL2str"))->Text = ZBHL2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZBHL3str"))->Text = ZBHL3str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZBHL4str"))->Text = ZBHL4str.t_str();

    //((TfrxMemoView*)frxZHReport->FindObject(""))->Text = ;

    ((TfrxMemoView*)frxZHReport->FindObject("KPXF1str"))->Text = KPXF1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("KPXF2str"))->Text = KPXF2str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("DKQCK1str"))->Text = DKQCK1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("DKQCK2str"))->Text = DKQCK2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("DKQCK3str"))->Text = DKQCK3str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("CZJCZ1str"))->Text = CZJCZ1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("CZJCZ2str"))->Text = CZJCZ2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("CZJCZ3str"))->Text = CZJCZ3str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("BT1str"))->Text = BT1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("BT2str"))->Text = BT2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("BT3str"))->Text = BT3str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("QK1str"))->Text = QK1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("QK2str"))->Text = QK2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("QK3str"))->Text = QK3str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("KH1str"))->Text = KH1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("KH2str"))->Text = KH2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("KH3str"))->Text = KH3str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("KH4str"))->Text = KH4str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("KH5str"))->Text = KH5str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("TK1str"))->Text = TK1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("TK2str"))->Text = TK2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("TK3str"))->Text = TK3str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("TK4str"))->Text = TK4str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("TK5str"))->Text = TK5str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("BK1str"))->Text = BK1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("BK2str"))->Text = BK2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("BK3str"))->Text = BK3str.t_str();

    ((TfrxMemoView*)frxZHReport->FindObject("ZJ1str"))->Text = ZJ1str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZJ2str"))->Text = ZJ2str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZJ3str"))->Text = ZJ3str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZJ4str"))->Text = ZJ4str.t_str();
    ((TfrxMemoView*)frxZHReport->FindObject("ZJ5str"))->Text = ZJ5str.t_str();

    STADOQuery->Close();
    STADOQuery->SQL->Clear();
    STADOQuery->SQL->Add("select * from STNAME");
    STADOQuery->Open();
    if(!STADOQuery->IsEmpty())
    {
        STADOQuery->First();
        int circletag = 1;
        double ZJE = 0;
        int ZCS = 0;
        while(!STADOQuery->Eof)
        {
			String Subsqlstr = "";
            if((BMstr != "所有部门")&&(!BMstr.IsEmpty()))
			{
				Subsqlstr = "select count(*) as cns,SUM(-SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='X' and SFRQ>='";
            	Subsqlstr += Beginstr;
                Subsqlstr += "' and SFRQ<='";
                Subsqlstr += Endstr;
				Subsqlstr += "' and BM='";
                Subsqlstr += BMstr;
                Subsqlstr += "' and STNAME='";
                Subsqlstr += STADOQuery->FieldByName("STNAME")->AsString.Trim();
                Subsqlstr += "'";
            }
            else
            {
				Subsqlstr = "select count(*) as cns,SUM(-SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='X' and SFRQ>='";
            	Subsqlstr += Beginstr;
				Subsqlstr += "' and SFRQ<='";
                Subsqlstr += Endstr;
                Subsqlstr += "' and STNAME='";
                Subsqlstr += STADOQuery->FieldByName("STNAME")->AsString.Trim();
                Subsqlstr += "'";
            }

        	ZHADOQuery->Close();
            ZHADOQuery->SQL->Clear();
            ZHADOQuery->SQL->Add(Subsqlstr);
            ZHADOQuery->Open();
            String CT = "CT";
            CT += circletag;
            String ZE = "SFZE";
            ZE += circletag;
            String CS = "CS";
            CS += circletag;
            ((TfrxMemoView*)frxZHReport->FindObject(CT.t_str()))->Text = STADOQuery->FieldByName("STNAME")->AsString.Trim().t_str();
            ((TfrxMemoView*)frxZHReport->FindObject(ZE.t_str()))->Text = FloatToStr(ZHADOQuery->FieldByName("SFZE")->AsFloat).t_str();
            ((TfrxMemoView*)frxZHReport->FindObject(CS.t_str()))->Text = IntToStr(ZHADOQuery->FieldByName("cns")->AsInteger).t_str();
            ZJE += ZHADOQuery->FieldByName("SFZE")->AsFloat;
            ZCS += ZHADOQuery->FieldByName("cns")->AsInteger;
            ZHADOQuery->Close();
            STADOQuery->Next();
            circletag++;
        }
        String CT = "CT";
        CT += circletag;
        String ZE = "SFZE";
        ZE += circletag;
        String CS = "CS";
        CS += circletag;
        ((TfrxMemoView*)frxZHReport->FindObject(CT.t_str()))->Text = "总计";
        ((TfrxMemoView*)frxZHReport->FindObject(ZE.t_str()))->Text = FloatToStr(ZJE).t_str();
        ((TfrxMemoView*)frxZHReport->FindObject(CS.t_str()))->Text = IntToStr(ZCS).t_str();

//	    ST.OlePropertyGet("Cells",20 + circletag,1).OlePropertySet("Value","总计");
//	    ST.OlePropertyGet("Cells",20 + circletag,3).OlePropertySet("Value",ZE);
//	    ST.OlePropertyGet("Cells",20 + circletag,5).OlePropertySet("Value",CS);
    }
    STADOQuery->Close();

    frxZHReport->ShowReport(true);
}
//---------------------------------------------------------------------------


