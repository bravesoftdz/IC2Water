//---------------------------------------------------------------------------

#ifndef DataToFileFormH
#define DataToFileFormH
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
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
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
#include <ExtCtrls.hpp>
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include <Dialogs.hpp>
#include "FileCtrl.hpp"
#include "CollectToFileThread.h"
#include "FileInDataBaseThread.h"
#include <ADODB.hpp>
#include <DB.hpp>

//---------------------------------------------------------------------------
class TDataToFileFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TPanel *Panel1;
	TLabel *Label1;
	TcxTextEdit *cxTextEdit1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TLabel *Label2;
	TcxTextEdit *cxTextEdit2;
	TLabel *Label3;
	TcxTextEdit *cxTextEdit3;
	TPanel *Panel8;
	TcxProgressBar *CollectProgressBar;
	TPanel *Panel2;
	TLabel *Label4;
	TcxButton *cxButton4;
	TcxTextEdit *cxTextEdit4;
	TcxButton *cxButton5;
	TPanel *Panel3;
	TcxProgressBar *cxProgressBar1;
	TMemo *Memo1;
	TcxButton *cxButton1;
	TOpenDialog *OpenDialog1;
	TADOQuery *ADOQuery1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall Memo1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit3KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations
	TCollectToFileThread* CollectToFileThread;
    TFileInDataBaseThread* FileInDataBaseThread;
public:		// User declarations
	__fastcall TDataToFileFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataToFileFrm *DataToFileFrm;
//---------------------------------------------------------------------------
#endif
