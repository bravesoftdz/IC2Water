//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CZnoticeFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TCZNoticForm *CZNoticForm;
//---------------------------------------------------------------------------
__fastcall TCZNoticForm::TCZNoticForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCZNoticForm::cxButton1Click(TObject *Sender)
{
	Panel1->Caption = "";
	this->Close();
}
//---------------------------------------------------------------------------
