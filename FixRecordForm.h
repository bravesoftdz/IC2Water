//---------------------------------------------------------------------------

#ifndef FixRecordFormH
#define FixRecordFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <XPMan.hpp>
#include "FixRecordThread.h"
//---------------------------------------------------------------------------
class TFixRecordFRM : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TPanel *Panel1;
	TGroupBox *GroupBox3;
	TProgressBar *ProgressBar1;
	TButton *Button3;
	TXPManifest *XPManifest1;
	TADOQuery *ADOQuery1;
	TADOQuery *ADOQuery2;
	TADOQuery *ADOQuery3;
	TButton *Button1;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFixRecordFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFixRecordFRM *FixRecordFRM;
//---------------------------------------------------------------------------
#endif
