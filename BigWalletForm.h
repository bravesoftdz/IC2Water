//---------------------------------------------------------------------------

#ifndef BigWalletFormH
#define BigWalletFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
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
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxTextEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TBigWalletFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox3;
	TcxButton *cxButton1;
	TLabel *Label1;
	TLabel *Label2;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TLabel *Label3;
	TcxTextEdit *cxTextEdit3;
	TLabel *Label4;
	TcxTextEdit *cxTextEdit4;
	TLabel *Label5;
	TcxTextEdit *cxTextEdit5;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TLabel *Label6;
	TcxTextEdit *cxTextEdit6;
	TLabel *Label7;
	TcxTextEdit *cxTextEdit7;
	TLabel *Label8;
	TcxTextEdit *cxTextEdit8;
	TcxTextEdit *cxTextEdit9;
	TLabel *Label9;
	TcxButton *cxButton4;
	TADOQuery *ADOQuery1;
	TcxButton *cxButton5;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBigWalletFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBigWalletFrm *BigWalletFrm;
//---------------------------------------------------------------------------
#endif
