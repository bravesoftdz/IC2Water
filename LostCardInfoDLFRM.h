//---------------------------------------------------------------------------

#ifndef LostCardInfoDLFRMH
#define LostCardInfoDLFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxListView.hpp"
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
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxRadioGroup.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <ImgList.hpp>

#include "GlobalParameter.h"
#include "DLSCanPosThread.h"
#include "PostAllCardLostInfoThread.h"
#include "PostLostInfoThread.h"
#include <Buttons.hpp>
#include "LostInfoDLFrm.h"
//---------------------------------------------------------------------------
class TLostCardInfoDownloadFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxListView *POSListView;
	TcxGroupBox *cxGroupBox2;
	TPanel *Panel8;
	TcxProgressBar *SCanProBar;
	TPanel *Panel1;
	TADOQuery *LIDLADOQ;
	TcxImageList *cxImageList1;
	TcxGroupBox *cxGroupBox3;
	TcxGroupBox *cxGroupBox5;
	TPanel *Panel4;
	TcxButton *GABTN;
	TPanel *Panel5;
	TPanel *Panel6;
	TcxGroupBox *cxGroupBox6;
	TcxButton *ExitBTN;
	TcxGroupBox *cxGroupBox7;
	TcxGroupBox *cxGroupBox8;
	TcxGroupBox *cxGroupBox9;
	TPanel *Panel7;
	TPanel *Panel9;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TPanel *Panel2;
	TPanel *Panel3;
	TcxGroupBox *cxGroupBox4;
	TcxGroupBox *cxGroupBox10;
	TPanel *Panel10;
	TcxButton *DGSBTN;
	TPanel *Panel11;
	TPanel *Panel12;
	TPanel *Panel13;
	TADOTable *GSADOT;
	TPanel *Panel14;
	TcxButton *SELALLBTN;
	TcxButton *CLSELALLBTN;
	TcxButton *cxButton1;
	void __fastcall GABTNClick(TObject *Sender);
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DGSBTNClick(TObject *Sender);
	void __fastcall POSListViewSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall SELALLBTNClick(TObject *Sender);
	void __fastcall CLSELALLBTNClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxListViewWindowProcEx(TMessage &message);
	void __fastcall cxButton1Click(TObject *Sender);

//	void __fastcall DownInfoBTNClick(TObject *Sender);
private:	// User declarations
	TWndMethod FOriginalcxListViewWindowProc;
	TDLSCanPosThread* SCanPosThread;
	TPostAllCardLostInfoThread* PostACLIThread;
	TPostLostInfoThread* PostLIThread;
public:		// User declarations
	__fastcall TLostCardInfoDownloadFRM(TComponent* Owner);
	bool existtag;
	bool scantag;
};
//---------------------------------------------------------------------------
extern PACKAGE TLostCardInfoDownloadFRM *LostCardInfoDownloadFRM;
//---------------------------------------------------------------------------
#endif
