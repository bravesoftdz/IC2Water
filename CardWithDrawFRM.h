//---------------------------------------------------------------------------

#ifndef CardWithDrawFRMH
#define CardWithDrawFRMH
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
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>

//---------------------------------------------------------------------------
class TCardWithDrawMoneyFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxButton *ReadCardBTN;
	TcxButton *WithDrawBTN;
	TcxButton *ExitWithDrawBTN;
	TcxGroupBox *cxGroupBox2;
	TcxButton *WithDraw5BTN;
	TcxButton *WithDraw10BTN;
	TcxButton *WithDraw20BTN;
	TcxButton *WithDraw30BTN;
	TcxButton *WithDraw40BTN;
	TcxButton *WithDraw90BTN;
	TcxButton *WithDraw80BTN;
	TcxButton *WithDraw70BTN;
	TcxButton *WithDraw60BTN;
	TcxButton *WithDraw50BTN;
	TcxButton *WithDraw1000BTN;
	TcxButton *WithDraw500BTN;
	TcxButton *WithDraw200BTN;
	TcxButton *WithDraw150BTN;
	TcxButton *WithDraw100BTN;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel14;
	TcxLabel *cxLabel15;
	TcxLabel *cxLabel16;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxTextEdit *cxTextEdit12;
	TcxTextEdit *cxTextEdit15;
	TcxTextEdit *cxTextEdit16;
	TcxTextEdit *cxTextEdit17;
	TcxTextEdit *cxTextEdit18;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxTextEdit *cxTextEdit5;
	TcxTextEdit *cxTextEdit6;
	TcxTextEdit *cxTextEdit7;
	TcxTextEdit *cxTextEdit8;
	TcxTextEdit *cxTextEdit9;
	TADOQuery *ADOWithDrawQuery;
	TADOQuery *HJLADOQ;
	TADOTable *ADOTable1;
	void __fastcall ExitWithDrawBTNClick(TObject *Sender);
	void __fastcall ReadCardBTNClick(TObject *Sender);
	void __fastcall WithDrawBTNClick(TObject *Sender);
	void __fastcall WithDraw5BTNClick(TObject *Sender);
	void __fastcall WithDraw10BTNClick(TObject *Sender);
	void __fastcall WithDraw20BTNClick(TObject *Sender);
	void __fastcall WithDraw30BTNClick(TObject *Sender);
	void __fastcall WithDraw40BTNClick(TObject *Sender);
	void __fastcall WithDraw50BTNClick(TObject *Sender);
	void __fastcall WithDraw60BTNClick(TObject *Sender);
	void __fastcall WithDraw70BTNClick(TObject *Sender);
	void __fastcall WithDraw80BTNClick(TObject *Sender);
	void __fastcall WithDraw90BTNClick(TObject *Sender);
	void __fastcall WithDraw100BTNClick(TObject *Sender);
	void __fastcall WithDraw150BTNClick(TObject *Sender);
	void __fastcall WithDraw200BTNClick(TObject *Sender);
	void __fastcall WithDraw500BTNClick(TObject *Sender);
	void __fastcall WithDraw1000BTNClick(TObject *Sender);
	void __fastcall cxTextEdit16KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit16Exit(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TCardWithDrawMoneyFRM(TComponent* Owner);

public:
	void Function_WithDraw(double WDMoney);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardWithDrawMoneyFRM *CardWithDrawMoneyFRM;
//---------------------------------------------------------------------------
#endif
