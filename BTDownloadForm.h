//---------------------------------------------------------------------------

#ifndef BTDownloadFormH
#define BTDownloadFormH
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
#include "GlobalParameter.h"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxMemo.hpp"
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
#include "cxProgressBar.hpp"
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>

#include "CSBTDownThread.h"
#include "JBBTDownThread.h"
#include "cxLabel.hpp"

//---------------------------------------------------------------------------
class TBTDownloadFrm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *ExitBTN;
	TcxGroupBox *cxGroupBox1;
	TcxMemo *cxMemo1;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *CSBTDownBTN;
	TcxProgressBar *CSProgressBar;
	TPanel *Panel3;
	TcxProgressBar *JBProgressBar;
	TPanel *Panel4;
	TcxButton *JBBTDownBTN;
	TPanel *Panel5;
	TADOQuery *JBBTDownADOQ;
	TADOQuery *CSBTADownDOQ;
	TPanel *Panel6;
	TPanel *CSPanel;
	TPanel *Panel8;
	TPanel *JBPanel;
	TcxGroupBox *cxGroupBox4;
	TcxLabel *cxLabel1;
	TcxTextEdit *ComNoEdit;
	TcxLabel *cxLabel2;
	TcxTextEdit *MachNOEdit;
	TcxButton *SaveBTJPARAMBTN;
	TcxTextEdit *PasswordEdit;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxTextEdit *MaxXFEdit;
	TcxTextEdit *MaxNumEdit;
	TcxLabel *cxLabel5;
	TcxButton *DownBTJPARAMBTN;
	TADOQuery *BTJPARAMADOQ;
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CSBTDownBTNClick(TObject *Sender);
	void __fastcall JBBTDownBTNClick(TObject *Sender);
	void __fastcall ComNoEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall MachNOEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall MaxNumEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall MaxXFEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall PasswordEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SaveBTJPARAMBTNClick(TObject *Sender);
	void __fastcall DownBTJPARAMBTNClick(TObject *Sender);
private:	// User declarations
	TCSBTDownThread* CSBTDownThread;
    TJBBTDownThread* JBBTDownThread;

    unsigned char btcomo;
    unsigned char btcmd;
    unsigned char btreceivebuf[16];
    int btreceivelen;
    unsigned char* btdir;
    int btdirlen;
    int btPosNo;
public:		// User declarations
	__fastcall TBTDownloadFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBTDownloadFrm *BTDownloadFrm;
//---------------------------------------------------------------------------
#endif
