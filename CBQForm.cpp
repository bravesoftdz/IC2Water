//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CBQForm.h"
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
#pragma resource "*.dfm"
TCBQFrm *CBQFrm;
//---------------------------------------------------------------------------
__fastcall TCBQFrm::TCBQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCBQFrm::CBEndDateEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TCBQFrm::FormShow(TObject *Sender)
{
	QueryBTN->Enabled = false;
//	CBBeginDateEdit->Text = "";
//  CBEndDateEdit->Text = "";

	CBBeginDateEdit->Date = Date();
    CBEndDateEdit->Date = Date();
    CheckBox1->Checked = true;
    CheckBox2->Checked = true;
    CheckBox3->Checked = true;
    CheckBox4->Checked = true;

    CBADOQ->Close();
    CBADOQ->SQL->Clear();
    CBADOQ->SQL->Add("select * from STNAME");
    CBADOQ->Open();
    if(!CBADOQ->IsEmpty())
    {
        CBADOQ->First();
        CBCTComboBox->Properties->Items->Clear();
        while(!CBADOQ->Eof)
        {
        	CBCTComboBox->Properties->Items->Add(CBADOQ->FieldByName("STNAME")->AsString.Trim());
            CBADOQ->Next();
        }
        CBCTComboBox->Properties->Items->Add("所有餐厅");
        CBCTComboBox->ItemIndex = -1;
    }
    CBADOQ->Close();
    CBADOQ->SQL->Clear();
    CBADOQ->SQL->Add("select * from SUBMEALINFO");
    CBADOQ->Open();
    if(!CBADOQ->IsEmpty())
    {
    	if(CBADOQ->FieldByName("breakfaststart")->AsDateTime<"10:00:00")
			BFstarttime = CBADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();
        else
        	BFstarttime = CBADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();

		if(CBADOQ->FieldByName("breakfastend")->AsDateTime<"10:00:00")
			BFendtime = CBADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();
        else
            BFendtime = CBADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();

        if(CBADOQ->FieldByName("lunchstart")->AsDateTime<"10:00:00")
			LHstarttime = CBADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();
        else
        	LHstarttime = CBADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();

        if(CBADOQ->FieldByName("lunchend")->AsDateTime<"10:00:00")
			LHendtime = CBADOQ->FieldByName("lunchend")->AsDateTime.TimeString();
        else
        	LHendtime = CBADOQ->FieldByName("lunchend")->AsDateTime.TimeString();

        if(CBADOQ->FieldByName("supperstart")->AsDateTime<"10:00:00")
			SRstarttime = CBADOQ->FieldByName("supperstart")->AsDateTime.TimeString();
        else
            SRstarttime = CBADOQ->FieldByName("supperstart")->AsDateTime.TimeString();

        if(CBADOQ->FieldByName("supperend")->AsDateTime<"10:00:00")
			SRendtime = CBADOQ->FieldByName("supperend")->AsDateTime.TimeString();
        else
        	SRendtime = CBADOQ->FieldByName("supperend")->AsDateTime.TimeString();

        if(CBADOQ->FieldByName("nightstart")->AsDateTime<"10:00:00")
			NTstarttime = CBADOQ->FieldByName("nightstart")->AsDateTime.TimeString();
        else
        	NTstarttime = CBADOQ->FieldByName("nightstart")->AsDateTime.TimeString();

        if(CBADOQ->FieldByName("nightend")->AsDateTime<"10:00:00")
			NTendtime = CBADOQ->FieldByName("nightend")->AsDateTime.TimeString();
        else
        	NTendtime = CBADOQ->FieldByName("nightend")->AsDateTime.TimeString();
    }
    CBADOQ->Close();

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
    }             */
}
//---------------------------------------------------------------------------
void __fastcall TCBQFrm::QueryBTNClick(TObject *Sender)
{
	if(!CBBeginDateEdit->Text.IsEmpty()&&!CBEndDateEdit->Text.IsEmpty())
    {
    	//&&!CBCTComboBox->Text.IsEmpty()
    	if(!CheckBox1->Checked&&!CheckBox2->Checked
        &&!CheckBox3->Checked&&!CheckBox4->Checked)
        {
        	ShowMessage("必须选择餐别!");
            return;
        }
        String MXsqlstr = "select MXBAK.*,CARD_F.XM as UName,CARD_F.BM as BUMEN,CARD_F.ZW as ZW,SFJPARAM.STNAME as CTNAME from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x' and";
        if(CBCTComboBox->Text!="所有餐厅" && !CBCTComboBox->Text.IsEmpty())
        {
        	MXsqlstr += " SFJPARAM.STNAME='";
            MXsqlstr += CBCTComboBox->Text;
            MXsqlstr += "' and SFRQ<='";
            MXsqlstr += CBEndDateEdit->Text;
            MXsqlstr += " 23:59:59' and SFRQ>='";
            MXsqlstr += CBBeginDateEdit->Text;
            MXsqlstr += " 00:00:00' and ";
        }
        else
        {
			MXsqlstr += " SFRQ<='";
            MXsqlstr += CBEndDateEdit->Text;
            MXsqlstr += " 23:59:59' and SFRQ>='";
            MXsqlstr += CBBeginDateEdit->Text;
            MXsqlstr += " 00:00:00' and ";
        }

        String addsqlstr = "";
        unsigned short hour;
        unsigned short min;
        unsigned short sec;
        unsigned short msec;

        if(CheckBox1->Checked)
        {
        	if(addsqlstr.IsEmpty())
            {
				addsqlstr = "((convert(varchar(100),MXBAK.SFRQ,108)<='";
                addsqlstr += BFendtime;
                addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                addsqlstr += BFstarttime;
                addsqlstr += "')";
            }
        }
        if(CheckBox2->Checked)
        {
        	if(addsqlstr.IsEmpty())
            {
				addsqlstr = "((convert(varchar(100),MXBAK.SFRQ,108)<='";
                addsqlstr += LHendtime;
                addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                addsqlstr += LHstarttime;
                addsqlstr += "')";
            }
            else
            {
				addsqlstr += " or (convert(varchar(100),MXBAK.SFRQ,108)<='";
                addsqlstr += LHendtime;
                addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                addsqlstr += LHstarttime;
                addsqlstr += "')";
            }
        }
        if(CheckBox3->Checked)
        {
        	if(addsqlstr.IsEmpty())
            {
				addsqlstr = "((convert(varchar(100),MXBAK.SFRQ,108)<='";
                addsqlstr += SRendtime;
                addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                addsqlstr += SRstarttime;
                addsqlstr += "')";
            }
            else
            {
				addsqlstr += " or (convert(varchar(100),MXBAK.SFRQ,108)<='";
                addsqlstr += SRendtime;
                addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                addsqlstr += SRstarttime;
                addsqlstr += "')";
            }
        }
        if(CheckBox4->Checked)
        {
         	if(addsqlstr.IsEmpty())
            {
            	if(StrToDateTime(NTendtime)>StrToDateTime(NTstarttime))
				{
                    addsqlstr = "((convert(varchar(100),MXBAK.SFRQ,108)<='";
                    addsqlstr += NTendtime;
                    addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    addsqlstr += NTstarttime;
                    addsqlstr += "')";
                }
                else
                {
                    addsqlstr = "((convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    addsqlstr += NTstarttime;
                    addsqlstr += "') or (convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                    addsqlstr += NTendtime;
                    addsqlstr += "')";
                }
            }
            else
            {
            	if(StrToDateTime(NTendtime)>StrToDateTime(NTstarttime))
				{
                    addsqlstr += " or (convert(varchar(100),MXBAK.SFRQ,108)<'";
                    addsqlstr += NTendtime;
                    addsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>'";
                    addsqlstr += NTstarttime;
                    addsqlstr += "')";
                }
                else
                {
                    addsqlstr += " or (convert(varchar(100),MXBAK.SFRQ,108)<'23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    addsqlstr += NTstarttime;
                    addsqlstr += "') or (convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                    addsqlstr += NTendtime;
                    addsqlstr += "')";
                }
            }
        }

        addsqlstr += ")";

        MXsqlstr += addsqlstr;
        CBADOQ->Close();
        CBADOQ->SQL->Clear();
        CBADOQ->SQL->Add(MXsqlstr);
        CBADOQ->Open();
        if(!CBADOQ->IsEmpty())
        {
        	if(CBADOQ->RecordCount > 65500)
            {
            	CBADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65530条，无法正常显示与导出，请修改查询条件!");
                return;
            }
            CBADOQ->Close();
            CBMXShowFrm->CBMXADOQuery->Close();
            CBMXShowFrm->CBMXADOQuery->SQL->Clear();
            CBMXShowFrm->CBMXADOQuery->SQL->Add(MXsqlstr);

            CBMXShowFrm->MSCBBFstarttime = BFstarttime;
            CBMXShowFrm->MSCBBFendtime = BFendtime;
            CBMXShowFrm->MSCBLHstarttime = LHstarttime;
            CBMXShowFrm->MSCBLHendtime = LHendtime;
            CBMXShowFrm->MSCBSRstarttime = SRstarttime;
            CBMXShowFrm->MSCBSRendtime = SRendtime;
            CBMXShowFrm->MSCBNTstarttime = NTstarttime;
            CBMXShowFrm->MSCBNTendtime = NTendtime;
            CBMXShowFrm->MSBeginDateTimeStr = CBBeginDateEdit->Text + " 00:00:00";
            CBMXShowFrm->MSEndDateTimeStr = CBEndDateEdit->Text + " 23:59:59";
            CBMXShowFrm->MSCTStr = CBCTComboBox->Text;
            CBMXShowFrm->MSBFtag = CheckBox1->Checked;
            CBMXShowFrm->MSLHtag = CheckBox2->Checked;
            CBMXShowFrm->MSSRtag = CheckBox3->Checked;
            CBMXShowFrm->MSNTtag = CheckBox4->Checked;
            CBMXShowFrm->MSCZYStr = OperatorName;
            CBMXShowFrm->ShowModal();
        }
        else
        	ShowMessage("符合该查询条件的记录条数为0!");
    }
    else
    	ShowMessage("必须完整填写查询起止时间!");
}
//---------------------------------------------------------------------------
