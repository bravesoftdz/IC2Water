//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PreOrderQueryForm.h"
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
TPreOrderQFrm *PreOrderQFrm;
//---------------------------------------------------------------------------
__fastcall TPreOrderQFrm::TPreOrderQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPreOrderQFrm::POBeginDateEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TPreOrderQFrm::FormShow(TObject *Sender)
{
	QueryBTN->Enabled = false;
//	POBeginDateEdit->Text = "";
//	POEndDateEdit->Text = "";
	POBeginDateEdit->Date = Date();
	POEndDateEdit->Date = Date();

    CheckBox1->Checked = true;
    CheckBox2->Checked = true;
    CheckBox3->Checked = true;
    CheckBox4->Checked = true;

    PreOADOQ->Close();
    PreOADOQ->SQL->Clear();
    PreOADOQ->SQL->Add("select * from BUMEN");
    PreOADOQ->Open();
    if(!PreOADOQ->IsEmpty())
    {
        PreOADOQ->First();
        POBMComboBox->Properties->Items->Clear();
        while(!PreOADOQ->Eof)
        {
            POBMComboBox->Properties->Items->Add(PreOADOQ->FieldByName("BUMEN")->AsString.Trim());
            PreOADOQ->Next();
        }
        POBMComboBox->Properties->Items->Add("所有部门");
        POBMComboBox->ItemIndex = -1;
    }

    PreOADOQ->Close();
    PreOADOQ->SQL->Clear();
    PreOADOQ->SQL->Add("select * from STNAME");
    PreOADOQ->Open();
    if(!PreOADOQ->IsEmpty())
    {
        PreOADOQ->First();
        POCTComboBox->Properties->Items->Clear();
        while(!PreOADOQ->Eof)
        {
        	POCTComboBox->Properties->Items->Add(PreOADOQ->FieldByName("STNAME")->AsString.Trim());
            PreOADOQ->Next();
        }
        POCTComboBox->Properties->Items->Add("所有餐厅");
        POCTComboBox->ItemIndex = -1;
    }
    PreOADOQ->Close();

    PreOADOQ->SQL->Clear();
    PreOADOQ->SQL->Add("select * from PreOderMEAlINFO");
    PreOADOQ->Open();
    if(!PreOADOQ->IsEmpty())
    {
    	if(PreOADOQ->FieldByName("breakfaststart")->AsDateTime<"10:00:00")
			BFstarttime = PreOADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();
        else
        	BFstarttime = PreOADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();

		if(PreOADOQ->FieldByName("breakfastend")->AsDateTime<"10:00:00")
			BFendtime = PreOADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();
        else
            BFendtime = PreOADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();

        if(PreOADOQ->FieldByName("lunchstart")->AsDateTime<"10:00:00")
			LHstarttime = PreOADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();
        else
        	LHstarttime = PreOADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();

        if(PreOADOQ->FieldByName("lunchend")->AsDateTime<"10:00:00")
			LHendtime = PreOADOQ->FieldByName("lunchend")->AsDateTime.TimeString();
        else
        	LHendtime = PreOADOQ->FieldByName("lunchend")->AsDateTime.TimeString();

        if(PreOADOQ->FieldByName("supperstart")->AsDateTime<"10:00:00")
			SRstarttime = PreOADOQ->FieldByName("supperstart")->AsDateTime.TimeString();
        else
            SRstarttime = PreOADOQ->FieldByName("supperstart")->AsDateTime.TimeString();

        if(PreOADOQ->FieldByName("supperend")->AsDateTime<"10:00:00")
			SRendtime = PreOADOQ->FieldByName("supperend")->AsDateTime.TimeString();
        else
        	SRendtime = PreOADOQ->FieldByName("supperend")->AsDateTime.TimeString();

        if(PreOADOQ->FieldByName("nightstart")->AsDateTime<"10:00:00")
			NTstarttime = PreOADOQ->FieldByName("nightstart")->AsDateTime.TimeString();
        else
        	NTstarttime = PreOADOQ->FieldByName("nightstart")->AsDateTime.TimeString();

        if(PreOADOQ->FieldByName("nightend")->AsDateTime<"10:00:00")
			NTendtime = PreOADOQ->FieldByName("nightend")->AsDateTime.TimeString();
        else
        	NTendtime = PreOADOQ->FieldByName("nightend")->AsDateTime.TimeString();
    }
    PreOADOQ->Close();

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
    }    */
}
//---------------------------------------------------------------------------
void __fastcall TPreOrderQFrm::QueryBTNClick(TObject *Sender)
{
	if(!POBeginDateEdit->Text.IsEmpty()&&!POEndDateEdit->Text.IsEmpty())
    {
    	if(!CheckBox1->Checked&&!CheckBox2->Checked
        &&!CheckBox3->Checked&&!CheckBox4->Checked)
        {
        	ShowMessage("必须选择餐别!");
            return;
        }

		String MXsqlstr = "select MXBAK.*,CARD_F.XM as UName,CARD_F.BM as BUMEN,CARD_F.ZW as ZW,SFJPARAM.STNAME as CTNAME from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where (SFLX='O' or SFLX='S' or SFLX='D' or SFLX='F' or SFLX='G') and";
        if(POCTComboBox->Text!="所有餐厅" && !POCTComboBox->Text.IsEmpty())
        {
        	MXsqlstr += " SFJPARAM.STNAME='";
            MXsqlstr += POCTComboBox->Text;
            MXsqlstr += "' and SFRQ<='";
            MXsqlstr += POEndDateEdit->Text;
            MXsqlstr += " 23:59:59' and SFRQ>='";
            MXsqlstr += POBeginDateEdit->Text;
            MXsqlstr += " 00:00:00' and ";
        }
        else
        {
			MXsqlstr += " SFRQ<='";
            MXsqlstr += POEndDateEdit->Text;
            MXsqlstr += " 23:59:59' and SFRQ>='";
            MXsqlstr += POBeginDateEdit->Text;
            MXsqlstr += " 00:00:00' and ";
        }

        if(POBMComboBox->Text!="所有部门"&&!POBMComboBox->Text.IsEmpty())
        {
			MXsqlstr += "CARD_F.BM='";
            MXsqlstr += POBMComboBox->Text;
            MXsqlstr += "' and ";
        }

        String addsqlstr = "";

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
        PreOADOQ->Close();
        PreOADOQ->SQL->Clear();
        PreOADOQ->SQL->Add(MXsqlstr);
        PreOADOQ->Open();
        if(!PreOADOQ->IsEmpty())
        {
        	if(PreOADOQ->RecordCount > 65500)
            {
            	PreOADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65530条，无法正常显示与导出，请修改查询条件!");
                return;
            }
            PreOADOQ->Close();
            PreOrderMXFrm->CBMXADOQuery->Close();
            PreOrderMXFrm->CBMXADOQuery->SQL->Clear();
            PreOrderMXFrm->CBMXADOQuery->SQL->Add(MXsqlstr);

            PreOrderMXFrm->MSCBBFstarttime = BFstarttime;
            PreOrderMXFrm->MSCBBFendtime = BFendtime;
            PreOrderMXFrm->MSCBLHstarttime = LHstarttime;
            PreOrderMXFrm->MSCBLHendtime = LHendtime;
            PreOrderMXFrm->MSCBSRstarttime = SRstarttime;
            PreOrderMXFrm->MSCBSRendtime = SRendtime;
            PreOrderMXFrm->MSCBNTstarttime = NTstarttime;
            PreOrderMXFrm->MSCBNTendtime = NTendtime;
            PreOrderMXFrm->MSBeginDateTimeStr = POBeginDateEdit->Text + " 00:00:00";
            PreOrderMXFrm->MSEndDateTimeStr = POEndDateEdit->Text + " 23:59:59";
            PreOrderMXFrm->MSCTStr = POCTComboBox->Text;
            PreOrderMXFrm->MSBFtag = CheckBox1->Checked;
            PreOrderMXFrm->MSLHtag = CheckBox2->Checked;
            PreOrderMXFrm->MSSRtag = CheckBox3->Checked;
            PreOrderMXFrm->MSNTtag = CheckBox4->Checked;
            PreOrderMXFrm->MSCZYStr = OperatorName;
            PreOrderMXFrm->MSBMStr = POBMComboBox->Text;
            PreOrderMXFrm->ShowModal();
        }
        else
        	ShowMessage("符合该查询条件的记录条数为0!");
    }
    else
    	ShowMessage("必须完整填写查询起止时间!");
}
//---------------------------------------------------------------------------
