//---------------------------------------------------------------------------

#ifndef GoonPWFRMH
#define GoonPWFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TGoonPWForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TPanel *Panel1;
	TButton *Button1;
	TPanel *Panel2;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button2;
	TPanel *Panel3;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TGoonPWForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGoonPWForm *GoonPWForm;
//---------------------------------------------------------------------------
#endif
