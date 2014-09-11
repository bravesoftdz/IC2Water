//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QKnoticeFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TQKnoticeform *QKnoticeform;
//---------------------------------------------------------------------------
__fastcall TQKnoticeform::TQKnoticeform(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQKnoticeform::cxButton1Click(TObject *Sender)
{
	Panel1->Caption = "";
	this->Close();
}
//---------------------------------------------------------------------------
