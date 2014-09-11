//---------------------------------------------------------------------------

#ifndef BackUpDateFrmH
#define BackUpDateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TBackUpDatafrm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TLabel *Label1;
	TcxButton *cxButton3;
private:	// User declarations
public:		// User declarations
	__fastcall TBackUpDatafrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBackUpDatafrm *BackUpDatafrm;
//---------------------------------------------------------------------------
#endif
