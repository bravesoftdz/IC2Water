//---------------------------------------------------------------------------

#ifndef CardRechargeFRMH
#define CardRechargeFRMH
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
#include <ExtCtrls.hpp>

//#include <stdio.h>
//---------------------------------------------------------------------------
class TCardRechargeMoneyFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
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
	TcxGroupBox *cxGroupBox2;
	TcxButton *ReCharge5BTN;
	TcxButton *ReCharge10BTN;
	TcxButton *ReCharge20BTN;
	TcxButton *ReCharge30BTN;
	TcxButton *ReCharge40BTN;
	TcxButton *ReCharge90BTN;
	TcxButton *ReCharge80BTN;
	TcxButton *ReCharge70BTN;
	TcxButton *ReCharge60BTN;
	TcxButton *ReCharge50BTN;
	TcxButton *ReCharge1000BTN;
	TcxButton *ReCharge500BTN;
	TcxButton *ReCharge200BTN;
	TcxButton *ReCharge150BTN;
	TcxButton *ReCharge100BTN;
	TcxButton *ReadCardBTN;
	TcxButton *ReChargeBTN;
	TcxButton *ExitBTN;
	TADOQuery *ADOReChargeQuery;
	TADOQuery *HJLADOQ;
	TADOTable *ADOTable1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TPanel *Panel1;
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall ReadCardBTNClick(TObject *Sender);
	void __fastcall cxTextEdit16KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ReChargeBTNClick(TObject *Sender);
	void __fastcall ReCharge5BTNClick(TObject *Sender);
	void __fastcall ReCharge10BTNClick(TObject *Sender);
	void __fastcall ReCharge20BTNClick(TObject *Sender);
	void __fastcall ReCharge30BTNClick(TObject *Sender);
	void __fastcall ReCharge40BTNClick(TObject *Sender);
	void __fastcall ReCharge50BTNClick(TObject *Sender);
	void __fastcall ReCharge60BTNClick(TObject *Sender);
	void __fastcall ReCharge70BTNClick(TObject *Sender);
	void __fastcall ReCharge80BTNClick(TObject *Sender);
	void __fastcall ReCharge90BTNClick(TObject *Sender);
	void __fastcall ReCharge100BTNClick(TObject *Sender);
	void __fastcall ReCharge150BTNClick(TObject *Sender);
	void __fastcall ReCharge200BTNClick(TObject *Sender);
	void __fastcall ReCharge500BTNClick(TObject *Sender);
	void __fastcall ReCharge1000BTNClick(TObject *Sender);
	void __fastcall cxTextEdit16Exit(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TCardRechargeMoneyFRM(TComponent* Owner);

public:
	void __fastcall Function_ReCharge(double ReChargeMoney);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardRechargeMoneyFRM *CardRechargeMoneyFRM;
//---------------------------------------------------------------------------
#endif
