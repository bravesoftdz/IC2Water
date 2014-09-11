//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FixRecordForm.h"
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFixRecordFRM *FixRecordFRM;
//---------------------------------------------------------------------------
__fastcall TFixRecordFRM::TFixRecordFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFixRecordFRM::Button3Click(TObject *Sender)
{
	TFixRecordThread* FRThread = new TFixRecordThread(true,ADOQuery1,ADOQuery2,ADOQuery3,ProgressBar1,Button3);
	if(FRThread)
		FRThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TFixRecordFRM::FormShow(TObject *Sender)
{
	fixrecordtag = true;
	ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFixRecordFRM::Button1Click(TObject *Sender)
{
	fixrecordtag = false;
	this->Close();
}
//---------------------------------------------------------------------------
