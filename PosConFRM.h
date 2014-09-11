//---------------------------------------------------------------------------

#ifndef PosConFRMH
#define PosConFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
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
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxLabel.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxSpinButton.hpp"
#include "cxSpinEdit.hpp"
#include <Menus.hpp>
#include <ImgList.hpp>
#include "cxProgressBar.hpp"
#include "cxMemo.hpp"

#include "SDIMAIN.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include "ScanAllPosThread.h"
#include "ScanPosInBaseThread.h"
#include <Buttons.hpp>
#include "SetAllPosParamThread.h"
#include "SetAllPOSBASE.h"
#include <Buttons.hpp>
#include "GlobalParameter.h"

#include "AddPosFrm.h"
#include "AddMPOSFrm.h"

//---------------------------------------------------------------------------
class TPosConfigFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TcxListView *POSListView;
	TcxImageList *cxImageList1;
	TcxMemo *cxMemo1;
	TADOQuery *SCanPosADOQ;
	TcxGroupBox *cxGroupBox5;
	TPanel *Panel1;
	TPanel *Panel2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TcxGroupBox *cxGroupBox4;
	TPanel *Panel8;
	TcxProgressBar *SCanProBar;
	TADOQuery *TmpADOQ;
	TcxGroupBox *cxGroupBox7;
	TcxGroupBox *cxGroupBox3;
	TcxComboBox *PosStyleComBox;
	TcxComboBox *PosPlaceComBox;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxTextEdit *MaxEdit;
	TcxMaskEdit *PassWordEdit;
	TcxButton *DelOneBTN;
	TcxButton *AddOneBTN;
	TcxButton *ScanPosBTN;
	TcxButton *PauseBTN;
	TcxButton *cxButton4;
	TcxTextEdit *POSNumEdit;
	TcxLabel *cxLabel5;
	TcxTextEdit *ComNumEdit;
	TcxLabel *cxLabel6;
	TcxButton *SetSingleBTN;
	TcxButton *SetAllPosBTN;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TSpeedButton *SpeedButton3;
	TPanel *Panel6;
	TSpeedButton *SpeedButton4;
	TcxButton *SelectAllBTN;
	TcxButton *CancelSelAllBTN;
	TADOQuery *ADOQuery1;
	TcxButton *cxButton1;
	TcxTextEdit *DMaxEdit;
	TcxLabel *cxLabel7;
	TcxButton *AddDBTN;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TcxTextEdit *MaxCSEdit;
	TcxButton *SetAllBaseBTN;
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall ScanPosBTNClick(TObject *Sender);
	void __fastcall SetSingleBTNClick(TObject *Sender);
//	void __fastcall SetAllBTNClick(TObject *Sender);
	void __fastcall AddOneBTNClick(TObject *Sender);
	void __fastcall DelOneBTNClick(TObject *Sender);
	void __fastcall PauseBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PassWordEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall MaxEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PassWordEditExit(TObject *Sender);
	void __fastcall POSListViewSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall SetAllPosBTNClick(TObject *Sender);
	void __fastcall CancelSelAllBTNClick(TObject *Sender);

    void __fastcall cxListViewWindowProcEx(TMessage &message);
	void __fastcall SelectAllBTNClick(TObject *Sender);
	void __fastcall AddDBTNClick(TObject *Sender);
	void __fastcall PosStyleComBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall SetAllBaseBTNClick(TObject *Sender);

private:	// User declarations
    TWndMethod FOriginalcxListViewWindowProc;
	TScanAllPosThread* ScanAllPosThread;
	TSCanPosInBaseThread* ScanPosInBaseThread;
	TSetAllPosParamThread* SetAllPosParamThread;
	TSetAllPOSBaseThread* SetAllPosBaseThread;
public:		// User declarations
	__fastcall TPosConfigFRM(TComponent* Owner);
	bool ScanTag;
};
//---------------------------------------------------------------------------
extern PACKAGE TPosConfigFRM *PosConfigFRM;
//---------------------------------------------------------------------------
#endif
