//---------------------------------------------------------------------------

#ifndef BatchLaunchCardProcessFrmH
#define BatchLaunchCardProcessFrmH
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
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "ChooseDataFrm.h"
#include "BatchLaunchCardFRM.h"
#include "GlobalParameter.h"
#include <ADODB.hpp>
#include <DB.hpp>

#include <time.h>
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"

#include "Comobj.hpp"
#include "clipbrd.hpp"
//---------------------------------------------------------------------------
class TBatchLaunchCardProcessForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxTextEdit *NameTextEdit;
	TcxTextEdit *MoneyTextEdit;
	TcxTextEdit *GroupTextEdit;
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TTimer *BLTime;
	TcxLabel *cxLabel5;
	TcxTextEdit *ZWTextEdit;
	TADOQuery *BLCADOQ;
	TADOQuery *ADOQuery1;
	TcxDateEdit *UseDateEdit;
	TcxLabel *cxLabel6;
	TADOQuery *ADOQuery2;
	TcxTextEdit *ClassTextEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel7;
	TcxTextEdit *KHTextEdit;
	TcxLabel *cxLabel8;
	TcxTextEdit *BHTextEdit;
	TCheckBox *CheckBox1;
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall BLTimeTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TBatchLaunchCardProcessForm(TComponent* Owner);
	int Nameindex;
	int Moneyindex;
	int Groupindex;
	int Classindex;
	int ZWindex;
	int KHindex;
	int BHindex;
	int startindex;
    int alllinecount;
    String errstr;
};
//---------------------------------------------------------------------------
extern PACKAGE TBatchLaunchCardProcessForm *BatchLaunchCardProcessForm;
//---------------------------------------------------------------------------
#endif
