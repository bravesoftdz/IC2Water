//---------------------------------------------------------------------------

#ifndef RealTimeCollectDataFRMH
#define RealTimeCollectDataFRMH
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
#include <Windows.h>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxEdit.hpp"
#include "cxInplaceContainer.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include "cxTL.hpp"
#include "cxTLdxBarBuiltInMenu.hpp"
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
#include "cxGroupBox.hpp"
#include <ImgList.hpp>
#include "cxListView.hpp"
#include <ComCtrls.hpp>
#include "ScallPosThread.h"
#include "CollectDataThread.h"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <Buttons.hpp>
#include "cxCheckBox.hpp"



//---------------------------------------------------------------------------
class TRealTimeCollectFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel6;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox4;
	TPanel *Panel7;
	TcxMemo *cxMemo1;
	TcxGroupBox *cxGroupBox5;
	TcxGroupBox *cxGroupBox3;
	TcxButton *RealCollectBTN;
	TcxImageList *cxImageList1;
	TcxListView *DataDisplayView;
	TPanel *Panel5;
	TPanel *Panel8;
	TcxProgressBar *ScallProgressBar;
	TcxProgressBar *CollectProgressBar;
	TADOQuery *CollectDataADOQuery;
	TcxButton *ExitBTN;
	TTreeView *TreeView1;
	TPanel *Panel9;
	TPanel *Panel10;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TADOTable *GSADOT;
	TcxCheckBox *cxCheckBox1;
	TcxButton *cxButton1;
	void __fastcall RealCollectBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall InBaseBTNClick(TObject *Sender);
private:	// User declarations
	int OnlinePosNum;
	TScallPosThread* ScallPosThread;
	TCollectDataThread* CollectdataThread;
	bool Collecting;
	bool Scanning;
public:		// User declarations
	__fastcall TRealTimeCollectFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRealTimeCollectFRM *RealTimeCollectFRM;
//---------------------------------------------------------------------------
#endif
