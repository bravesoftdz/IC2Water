//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CZMXQForm.h"
#include "ReChargePosMXQueryForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
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
TReChargePosForm *ReChargePosForm;
//---------------------------------------------------------------------------
__fastcall TReChargePosForm::TReChargePosForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TReChargePosForm::cxButton1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TReChargePosForm::QueryBTNClick(TObject *Sender)
{
	if(!CZBeginDateEdit->Text.IsEmpty()&&!CZEndDateEdit->Text.IsEmpty())
	{
		String MXsqlstr = "select CK.*,CARD_F.BM as BUMEN,CARD_F.BZ as BANBIE,CARD_F.ZB as ZUBIE,CARD_F.XM as NAME from CK join CARD_F on CK.bh=CARD_F.BH and CK.kh=CARD_F.KH where ";
		String SUMsqlstr = "select sum(ckje) as allck from CK join CARD_F on CK.bh=CARD_F.BH and CK.kh=CARD_F.KH where ";
		String sqlstr = "sfrq>'";
		sqlstr += CZBeginDateEdit->Text;
        sqlstr += " 00:00:00";
		sqlstr += "' and sfrq<'";
		sqlstr += CZEndDateEdit->Text;
		sqlstr += " 23:59:59'";
		sqlstr += " and sflx='I' ";

		if(JHComboBox->ItemIndex != -1)
		{
			sqlstr += "and JYNO=";
			sqlstr += JHComboBox->Text;
        }
        if(!CZKHTextEdit->Text.IsEmpty())
		{
			sqlstr += " and CK.kh=";
			sqlstr += CZKHTextEdit->Text.Trim();
		}
		if(!CZBHTextEdit->Text.IsEmpty())
		{
			sqlstr += " and CK.bh='";
			sqlstr += CZBHTextEdit->Text.Trim();
			sqlstr += "'";
		}
		if(!CZBMComboBox->Text.IsEmpty())
		{
			sqlstr += " and CARD_F.BM='";
			sqlstr += CZBMComboBox->Text.Trim();
			sqlstr += "'";
		}
        if(!BBComboBox->Text.IsEmpty())
        {
            sqlstr += " and BZ='";
            sqlstr += BBComboBox->Text;
            sqlstr += "'";
        }

        if(!ZBComboBox->Text.IsEmpty())
        {
            sqlstr += " and ZB='";
            sqlstr += ZBComboBox->Text;
            sqlstr += "'";
        }
//        sqlstr += " group by CK.kh order by CK.kh";

		MXsqlstr += sqlstr;
		MXsqlstr += " order by sfrq desc";
        SUMsqlstr += sqlstr;
		CZJADOQ->Close();
		CZJADOQ->SQL->Clear();
		CZJADOQ->SQL->Add(MXsqlstr);
		CZJADOQ->Open();
		if(!CZJADOQ->IsEmpty())
        {
			if(CZJADOQ->RecordCount > 65500)
            {
				CZJADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示与导出，请修改查询条件!");
                return;
            }
			CZJADOQ->Close();
			CZJADOQ->SQL->Clear();
			CZJADOQ->SQL->Add(SUMsqlstr);
			CZJADOQ->Open();
			CZMXShowFrm->AllCKTextEdit->Text = CZJADOQ->FieldByName("allck")->AsString.Trim();
			CZJADOQ->Close();

            CZMXShowFrm->BeginDateTimeStr = CZBeginDateEdit->Text + " 00:00:00";
            CZMXShowFrm->EndDateTimeStr = CZEndDateEdit->Text + " 23:59:59";
			CZMXShowFrm->KHStr = "";
			CZMXShowFrm->BHStr = "";
			CZMXShowFrm->BMStr = "";
			CZMXShowFrm->CZCZYStr = "";
			CZMXShowFrm->DKQCZTag = false;
			CZMXShowFrm->POSCZTag = true;
            CZMXShowFrm->FKCZTag = false;
            CZMXShowFrm->CZYStr = OperatorName;
            CZMXShowFrm->CZMXExportProgressBar->Position = 0;

            CZMXShowFrm->CZMXADOQuery->Close();
            CZMXShowFrm->CZMXADOQuery->SQL->Clear();
            CZMXShowFrm->CZMXADOQuery->SQL->Add(MXsqlstr);
            CZMXShowFrm->ShowModal();
        }
        else
        	ShowMessage("符合该查询条件的记录条数为0!");
	}
	else
	{
        ShowMessage("必须填写查询起止日期!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TReChargePosForm::FormShow(TObject *Sender)
{
	CZBeginDateEdit->Date = Date();
	CZEndDateEdit->Date = Date();

	JHComboBox->Properties->Items->Clear();

	CZJADOQ->Close();
	CZJADOQ->SQL->Clear();
	CZJADOQ->SQL->Add("select * from SFJPARAM where JQLX='充值机'");
	CZJADOQ->Open();
	if(!CZJADOQ->IsEmpty())
	{
		CZJADOQ->First();
		while(!CZJADOQ->Eof)
		{
			JHComboBox->Properties->Items->Add(CZJADOQ->FieldByName("JH")->AsString.Trim());
			CZJADOQ->Next();
		}
	}
	CZJADOQ->Close();

	CZJADOQ->SQL->Clear();
	CZJADOQ->SQL->Add("select * from BUMEN");
	CZJADOQ->Open();
	if(!CZJADOQ->IsEmpty())
	{
		CZJADOQ->First();
		while(!CZJADOQ->Eof)
		{
			CZBMComboBox->Properties->Items->Add(CZJADOQ->FieldByName("BUMEN")->AsString.Trim());
			CZJADOQ->Next();
        }
	}
	CZJADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReChargePosForm::CZKHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------


void __fastcall TReChargePosForm::CZBMComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TReChargePosForm::CZBMComboBoxPropertiesChange(TObject *Sender)
{
//	BBComboBox->Properties->Items->Clear();
    BBComboBox->Text = "";
//    ZBComboBox->Properties->Items->Clear();
	ZBComboBox->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TReChargePosForm::BBComboBoxEnter(TObject *Sender)
{
	if(!CZBMComboBox->Text.IsEmpty()&&(CZBMComboBox->Text != "所有部门"))
	{
		BBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from BANBIE where BUMEN='";
        sqlstr += CZBMComboBox->Text;
        sqlstr += "'";
		QADOQ->Close();
        QADOQ->SQL->Clear();
        QADOQ->SQL->Add(sqlstr);
        QADOQ->Open();
        if(!QADOQ->IsEmpty())
		{
            QADOQ->First();
            while(!QADOQ->Eof)
            {
                BBComboBox->Properties->Items->Add(QADOQ->FieldByName("BANBIE")->AsString.Trim());
                QADOQ->Next();
			}
			BBComboBox->Properties->Items->Add("所有班别");
        }
        QADOQ->Close();
	}
	else
	{
        BBComboBox->Properties->Items->Clear();
    }
}
//---------------------------------------------------------------------------

void __fastcall TReChargePosForm::ZBComboBoxEnter(TObject *Sender)
{
	if(!CZBMComboBox->Text.IsEmpty()&&(CZBMComboBox->Text != "所有部门")&&!BBComboBox->Text.IsEmpty())
	{
		ZBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from ZUBIE where BUMEN='";;
        sqlstr += CZBMComboBox->Text;
        sqlstr += "' and BANBIE='";
        sqlstr += BBComboBox->Text;
        sqlstr += "'";
        QADOQ->Close();
        QADOQ->SQL->Clear();
        QADOQ->SQL->Add(sqlstr);
        QADOQ->Open();
        if(!QADOQ->IsEmpty())
		{
			QADOQ->First();
            while(!QADOQ->Eof)
            {
                ZBComboBox->Properties->Items->Add(QADOQ->FieldByName("ZUBIE")->AsString.Trim());
                QADOQ->Next();
			}
			ZBComboBox->Properties->Items->Add("所有组别");
        }
        QADOQ->Close();
	}
	else
	{
        ZBComboBox->Properties->Items->Clear();
    }
}
//---------------------------------------------------------------------------

