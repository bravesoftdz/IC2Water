//---------------------------------------------------------------------------

#ifndef StopConsumeQFormH
#define StopConsumeQFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "GlobalParameter.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include "StopConsumeShowForm.h"
//---------------------------------------------------------------------------
class TStopConsumeQFrm : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RadioGroup1;
	TButton *Button1;
	TADOQuery *CARDADOQ;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStopConsumeQFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStopConsumeQFrm *StopConsumeQFrm;
//---------------------------------------------------------------------------
#endif
