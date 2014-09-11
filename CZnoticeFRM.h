//---------------------------------------------------------------------------

#ifndef CZnoticeFRMH
#define CZnoticeFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TCZNoticForm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TPanel *Panel1;
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCZNoticForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCZNoticForm *CZNoticForm;
//---------------------------------------------------------------------------
#endif
