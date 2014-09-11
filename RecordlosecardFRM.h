//---------------------------------------------------------------------------

#ifndef RecordlosecardFRMH
#define RecordlosecardFRMH
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
#include "cxRadioGroup.hpp"
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
//#include "SDIMAIN.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include "GlobalParameter.h"
#include "SingleGSFrm.h"
#include "SingleWDGSFrm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TRecordLostCardFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxRadioButton *cxRadioButton3;
	TcxRadioButton *cxRadioButton4;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxGroupBox *cxGroupBox2;
	TcxTextEdit *cxTextEdit5;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit6;
	TcxTextEdit *cxTextEdit16;
	TcxLabel *cxLabel8;
	TcxTextEdit *cxTextEdit19;
	TcxLabel *cxLabel9;
	TcxTextEdit *cxTextEdit7;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxTextEdit *cxTextEdit8;
	TcxLabel *cxLabel10;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxLabel *cxLabel11;
	TcxTextEdit *cxTextEdit9;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxTextEdit *cxTextEdit13;
	TcxLabel *cxLabel12;
	TcxTextEdit *cxTextEdit12;
	TcxTextEdit *cxTextEdit17;
	TcxTextEdit *cxTextEdit15;
	TcxLabel *cxLabel15;
	TcxLabel *cxLabel13;
	TcxButton *QueryBTN;
	TcxButton *PutLostInfoBTN;
	TcxButton *DelLostInfoBTN;
	TcxButton *NextBTN;
	TADOQuery *LostCardADOQuery;
	TADOQuery *InDatabaseADOQuery;
	TcxLabel *cxLabel7;
	TcxTextEdit *cxTextEdit14;
	TcxButton *cxButton1;
	TcxRadioGroup *cxRadioGroup1;
	TPanel *Panel1;
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxRadioButton3Click(TObject *Sender);
	void __fastcall cxRadioButton4Click(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall NextBTNClick(TObject *Sender);
	void __fastcall PutLostInfoBTNClick(TObject *Sender);
	void __fastcall DelLostInfoBTNClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit1Exit(TObject *Sender);
	void __fastcall cxTextEdit5KeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TRecordLostCardFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRecordLostCardFRM *RecordLostCardFRM;
//---------------------------------------------------------------------------
#endif
