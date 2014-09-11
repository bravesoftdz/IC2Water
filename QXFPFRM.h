//---------------------------------------------------------------------------

#ifndef QXFPFRMH
#define QXFPFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "SDIMAIN.h"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class Tqxfpform : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TPanel *Panel2;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox10;
	TCheckBox *CheckBox11;
	TCheckBox *CheckBox12;
	TPanel *Panel3;
	TCheckBox *CheckBox13;
	TCheckBox *CheckBox14;
	TCheckBox *CheckBox15;
	TCheckBox *CheckBox16;
	TPanel *Panel4;
	TCheckBox *CheckBox17;
	TCheckBox *CheckBox18;
	TCheckBox *CheckBox19;
	TCheckBox *CheckBox20;
	TCheckBox *CheckBox21;
	TPanel *Panel5;
	TCheckBox *CheckBox22;
	TCheckBox *CheckBox23;
	TPanel *Panel6;
	TCheckBox *CheckBox24;
	TCheckBox *CheckBox25;
	TCheckBox *CheckBox26;
	TCheckBox *CheckBox27;
	TCheckBox *CheckBox28;
	TCheckBox *CheckBox29;
	TCheckBox *CheckBox30;
	TCheckBox *CheckBox31;
	TCheckBox *CheckBox32;
	TCheckBox *CheckBox33;
	TCheckBox *CheckBox34;
	TCheckBox *CheckBox35;
	TCheckBox *CheckBox36;
	TCheckBox *CheckBox37;
	TCheckBox *CheckBox38;
	TCheckBox *CheckBox39;
	TCheckBox *CheckBox40;
	TCheckBox *CheckBox41;
	TCheckBox *CheckBox42;
	TCheckBox *CheckBox43;
	TADOQuery *ADOQuery1;
	TCheckBox *CheckBox44;
	TCheckBox *CheckBox45;
	TCheckBox *CheckBox46;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tqxfpform(TComponent* Owner);
	String username;
	String usergroup;
};
//---------------------------------------------------------------------------
extern PACKAGE Tqxfpform *qxfpform;
//---------------------------------------------------------------------------
#endif
