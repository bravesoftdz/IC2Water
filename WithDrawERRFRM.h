//---------------------------------------------------------------------------

#ifndef WithDrawERRFRMH
#define WithDrawERRFRMH
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
#include "cxGroupBox.hpp"
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
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TWithDrawERRForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxGroupBox *cxGroupBox1;
	TcxButton *cxButton2;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel8;
	TcxTextEdit *cxTextEdit8;
	TcxTextEdit *cxTextEdit7;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel9;
	TcxTextEdit *cxTextEdit9;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxTextEdit *cxTextEdit12;
	TcxTextEdit *cxTextEdit6;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel5;
	TcxTextEdit *cxTextEdit5;
	TcxTextEdit *cxTextEdit4;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel3;
	TcxTextEdit *cxTextEdit3;
	TcxLabel *cxLabel14;
	TcxTextEdit *cxTextEdit18;
	TcxTextEdit *cxTextEdit17;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel15;
	TcxTextEdit *cxTextEdit15;
	TcxLabel *cxLabel16;
	TcxTextEdit *cxTextEdit16;
	TADOQuery *ADOReChargeQuery;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWithDrawERRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWithDrawERRForm *WithDrawERRForm;
//---------------------------------------------------------------------------
#endif
