//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FixTitleFRM.h"
#include "SDIMAIN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
TFixTitleForm *FixTitleForm;
//---------------------------------------------------------------------------
__fastcall TFixTitleForm::TFixTitleForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFixTitleForm::cxButton2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFixTitleForm::cxButton1Click(TObject *Sender)
{
//	ShowMessage(IntToStr(cxTextEdit1->Text.Length()));
	if(!cxTextEdit1->Text.IsEmpty())
    {
    	if(cxTextEdit1->Text.Length()>40)
        {
    		ShowMessage("标题长度不能大于40");
            return;
        }
    	SDIAppForm->Panel3->Caption = cxTextEdit1->Text;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("select * from XTSET");
        ADOQuery1->Open();
        ADOQuery1->Edit();
        ADOQuery1->FieldByName("Caption")->AsString = cxTextEdit1->Text;
        ADOQuery1->Post();
        ADOQuery1->Close();
    }
    else
    	ShowMessage("标题长度不能为0!");
    this->Close();
}
//---------------------------------------------------------------------------
