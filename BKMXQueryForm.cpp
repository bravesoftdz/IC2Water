//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BKMXQueryForm.h"
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
TBKMXQForm *BKMXQForm;
//---------------------------------------------------------------------------
__fastcall TBKMXQForm::TBKMXQForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBKMXQForm::QueryBTNClick(TObject *Sender)
{
	if(!CZBeginDateEdit->Text.IsEmpty()&&!CZEndDateEdit->Text.IsEmpty())
	{
		String MXsqlstr = "select OperationList.*,CARD_F.BM as BUMEN,CARD_F.XM as NAME from OperationList join CARD_F on OperationList.bh=CARD_F.BH and OperationList.kh=CARD_F.KH where LX='补发卡' ";
		String sqlstr = "and DateTime>'";
		sqlstr += CZBeginDateEdit->Text;
        sqlstr += " 00:00:00";
		sqlstr += "' and DateTime<'";
		sqlstr += CZEndDateEdit->Text;
		sqlstr += " 23:59:59'";
		if(!CZCZYComboBox->Text.IsEmpty())
		{
			sqlstr += " and Operator='";
			sqlstr += CZCZYComboBox->Text.Trim();
			sqlstr += "'";
		}

        MXsqlstr += sqlstr;
		ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add(MXsqlstr);
        ADOQuery1->Open();
        if(!ADOQuery1->IsEmpty())
        {
        	if(ADOQuery1->RecordCount > 65500)
            {
            	ADOQuery1->Close();
                ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示与导出，请修改查询条件!");
				return;
            }

            BKMXShowFrm->BeginDateTimeStr = CZBeginDateEdit->Text + " 00:00:00";
            BKMXShowFrm->EndDateTimeStr = CZEndDateEdit->Text + " 23:59:59";
            BKMXShowFrm->CZCZYStr = CZCZYComboBox->Text;
            BKMXShowFrm->CZYStr = OperatorName;
            BKMXShowFrm->CZMXExportProgressBar->Position = 0;

            BKMXShowFrm->CZMXADOQuery->Close();
            BKMXShowFrm->CZMXADOQuery->SQL->Clear();
            BKMXShowFrm->CZMXADOQuery->SQL->Add(MXsqlstr);
            BKMXShowFrm->ShowModal();
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
void __fastcall TBKMXQForm::FormShow(TObject *Sender)
{
	CZBeginDateEdit->Date = Date();
	CZEndDateEdit->Date = Date();
	CZCZYComboBox->Properties->Items->Clear();
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from SYSUSER");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		ADOQuery1->First();
		while(!ADOQuery1->Eof)
		{
			CZCZYComboBox->Properties->Items->Add(ADOQuery1->FieldByName("USERNAME")->AsString.Trim());
			ADOQuery1->Next();
        }
	}
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

