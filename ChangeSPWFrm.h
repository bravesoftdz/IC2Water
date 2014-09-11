//---------------------------------------------------------------------------

#ifndef ChangeSPWFrmH
#define ChangeSPWFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <Menus.hpp>
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TChangeSPWForm : public TForm
{
__published:	// IDE-managed Components
	TcxLabel *cxLabel1;
	TcxTextEdit *TEOldPassword;
	TcxTextEdit *TENewPassword1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxTextEdit *TENewPassword2;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TADOQuery *ADOQuery1;
	void __fastcall TENewPassword1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEOldPasswordExit(TObject *Sender);
	void __fastcall TENewPassword1Exit(TObject *Sender);
	void __fastcall TENewPassword2Exit(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TChangeSPWForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChangeSPWForm *ChangeSPWForm;
//---------------------------------------------------------------------------
#endif
