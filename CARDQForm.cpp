//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CARDQForm.h"
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
TCARDQFrm *CARDQFrm;
//---------------------------------------------------------------------------
__fastcall TCARDQFrm::TCARDQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCARDQFrm::KHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TCARDQFrm::BMComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TCARDQFrm::FormShow(TObject *Sender)
{
	KHTextEdit->Text = "";
    BHTextEdit->Text = "";
    XMTextEdit->Text = "";
    BMComboBox->Properties->Items->Clear();
    BBComboBox->Properties->Items->Clear();
    ZBComboBox->Properties->Items->Clear();
    QADOQ->Close();
    QADOQ->SQL->Clear();
    QADOQ->SQL->Add("select * from BUMEN");
    QADOQ->Open();
    if(!QADOQ->IsEmpty())
    {
        QADOQ->First();
        while(!QADOQ->Eof)
        {
            BMComboBox->Properties->Items->Add(QADOQ->FieldByName("BUMEN")->AsString.Trim());
            QADOQ->Next();
		}
		BMComboBox->Properties->Items->Add("所有部门");
    }
    QADOQ->Close();
}
//---------------------------------------------------------------------------
void __fastcall TCARDQFrm::BBComboBoxEnter(TObject *Sender)
{
	if(!BMComboBox->Text.IsEmpty()&&(BMComboBox->Text != "所有部门"))
	{
		BBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from BANBIE where BUMEN='";
        sqlstr += BMComboBox->Text;
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
void __fastcall TCARDQFrm::ZBComboBoxEnter(TObject *Sender)
{
	if(!BMComboBox->Text.IsEmpty()&&(BMComboBox->Text != "所有部门")&&!BBComboBox->Text.IsEmpty())
	{
		ZBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from ZUBIE where BUMEN='";;
        sqlstr += BMComboBox->Text;
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
void __fastcall TCARDQFrm::BMComboBoxPropertiesChange(TObject *Sender)
{
//	BBComboBox->Properties->Items->Clear();
    BBComboBox->Text = "";
//    ZBComboBox->Properties->Items->Clear();
	ZBComboBox->Text = "";

}
//---------------------------------------------------------------------------
void __fastcall TCARDQFrm::QueryBTNClick(TObject *Sender)
{
	String sqlstr = "select * from CARD";

    String sunsqlstr = "select sum(yj) as sumyj from CARD";
    String addsqlstr = "";

    if(!KHTextEdit->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
        	addsqlstr += " where KH=";
            addsqlstr += KHTextEdit->Text;
        }
    }

    if(!BHTextEdit->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
            addsqlstr += " where BH='";
            addsqlstr += BHTextEdit->Text;
            addsqlstr += "'";
        }
        else
        {
            addsqlstr += " and BH='";
            addsqlstr += BHTextEdit->Text;
            addsqlstr += "'";
        }
    }

    if(!XMTextEdit->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
            addsqlstr += " where XM='";
            addsqlstr += XMTextEdit->Text;
            addsqlstr += "'";
        }
        else
        {
            addsqlstr += " and XM='";
            addsqlstr += XMTextEdit->Text;
            addsqlstr += "'";
        }
    }

    if(!BMComboBox->Text.IsEmpty()&&(BMComboBox->Text != "所有部门"))
    {
        if(addsqlstr.IsEmpty())
        {
            addsqlstr += " where BM='";
            addsqlstr += BMComboBox->Text;
            addsqlstr += "'";
        }
        else
        {
            addsqlstr += " and BM='";
            addsqlstr += BMComboBox->Text;
            addsqlstr += "'";
        }
    }

    if(!BBComboBox->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
            addsqlstr += " where BZ='";
            addsqlstr += BBComboBox->Text;
            addsqlstr += "'";
        }
        else
        {
            addsqlstr += " and BZ='";
            addsqlstr += BBComboBox->Text;
            addsqlstr += "'";
        }
    }

    if(!ZBComboBox->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
            addsqlstr += " where ZB='";
            addsqlstr += ZBComboBox->Text;
            addsqlstr += "'";
        }
        else
        {
            addsqlstr += " and ZB='";
            addsqlstr += ZBComboBox->Text;
            addsqlstr += "'";
        }
    }

    sqlstr += addsqlstr;
    sunsqlstr += addsqlstr;
    CARDADOQ->Close();
    CARDADOQ->SQL->Clear();
    CARDADOQ->SQL->Add(sqlstr);
    CARDADOQ->Open();
    if(!CARDADOQ->IsEmpty())
    {
        if(CARDADOQ->RecordCount > 65500)
        {
        	CARDADOQ->Close();
            ShowMessage("符合该查询条件的记录条数大于65530条，无法正常显示与导出，请修改查询条件!");
            return;
        }
        CARDADOQ->Close();
        CARDADOQ->SQL->Clear();
        CARDADOQ->SQL->Add(sunsqlstr);
        CARDADOQ->Open();
        CARDShowFrm->Edit1->Text = CARDADOQ->FieldByName("SUMYJ")->AsString.Trim();
        CARDADOQ->Close();

        CARDShowFrm->KHStr = KHTextEdit->Text;
        CARDShowFrm->BHStr = BHTextEdit->Text;
        CARDShowFrm->XMStr = XMTextEdit->Text;
        CARDShowFrm->BMStr = BMComboBox->Text;
        CARDShowFrm->BBStr = BBComboBox->Text;
        CARDShowFrm->ZBStr = ZBComboBox->Text;
        CARDShowFrm->CZYStr = OperatorName;
        CARDShowFrm->CARDADOQuery->Close();
        CARDShowFrm->CARDADOQuery->SQL->Clear();
        CARDShowFrm->CARDADOQuery->SQL->Add(sqlstr);
        CARDShowFrm->ShowModal();
    }
    else
        ShowMessage("符合该查询条件的记录条数为0!");
}
//---------------------------------------------------------------------------
