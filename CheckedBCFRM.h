//---------------------------------------------------------------------------

#ifndef CheckedBCFRMH
#define CheckedBCFRMH
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
#include "cxListView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxProgressBar.hpp"
#include "cxRichEdit.hpp"
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
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include "cxCheckGroup.hpp"
#include "cxCheckListBox.hpp"
#include "ScanPosCheckBatchThread.h"
#include "CheckedBatchCollectDataThread.h"
#include "CheckedBatchInBaseThread.h"

//---------------------------------------------------------------------------
class TCheckBatchCollectFRM : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxGroupBox *cxGroupBox1;
	TPanel *Panel9;
	TSpeedButton *SpeedButton2;
	TPanel *Panel10;
	TSpeedButton *SpeedButton1;
	TPanel *Panel2;
	TPanel *Panel3;
	TcxGroupBox *cxGroupBox5;
	TcxRichEdit *DataRichEdit;
	TcxListView *DisPlayListView;
	TPanel *Panel4;
	TcxGroupBox *cxGroupBox4;
	TPanel *Panel8;
	TcxProgressBar *ScallProgressBar;
	TcxProgressBar *CollectProgressBar;
	TcxGroupBox *cxGroupBox3;
	TPanel *Panel7;
	TPanel *Panel5;
	TcxButton *BatchCollectBTN;
	TcxButton *ExitBTN;
	TcxButton *InBaseBTN;
	TPanel *Panel6;
	TcxGroupBox *cxGroupBox2;
	TcxMemo *cxMemo1;
	TcxImageList *cxImageList1;
	TADOQuery *CheckBCADOQ;
	TADOQuery *CheckIBADOQ;
	TcxCheckListBox *cxCheckListBox1;
	TADOQuery *ADOQuery1;
	TcxButton *cxButton1;
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BatchCollectBTNClick(TObject *Sender);
	void __fastcall InBaseBTNClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
	int CBatchOnlinePosNum;
	bool Collecting;
	bool Scanning;
	TScanPosCheckBatchThread* ScanPCBThread;
	TCheckedBatchCollectDataThread* CBCDThread;
	TCheckBatchInBaseThread* CBIBThread;
public:		// User declarations
	__fastcall TCheckBatchCollectFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCheckBatchCollectFRM *CheckBatchCollectFRM;
//---------------------------------------------------------------------------
#endif
