//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SectionInfoFixFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
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
TSectionInfoFixFROM *SectionInfoFixFROM;


//---------------------------------------------------------------------------
__fastcall TSectionInfoFixFROM::TSectionInfoFixFROM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoFixFROM::CancelSIFBTNClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSectionInfoFixFROM::ConfirmSIFBTNClick(TObject *Sender)
{
	if(SectionInfoFixEdit->EditModified)
	{
		ShowMessage("Changed!");
		SectionInfoManageFRM->SectionInfoADOT->FieldByName("BUMEN")->AsString = SectionInfoFixEdit->Text;
		SectionInfoManageFRM->SectionInfoADOT->Post();
	}
	Close();
}
//---------------------------------------------------------------------------

