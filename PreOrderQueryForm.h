//---------------------------------------------------------------------------

#ifndef PreOrderQueryFormH
#define PreOrderQueryFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
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
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

#include "GlobalParameter.h"
#include "PreOrderMXForm.h"

//---------------------------------------------------------------------------
class TPreOrderQFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel4;
	TcxDateEdit *POBeginDateEdit;
	TcxLabel *cxLabel3;
	TcxDateEdit *POEndDateEdit;
	TcxButton *QueryBTN;
	TcxComboBox *POCTComboBox;
	TcxLabel *cxLabel5;
	TPanel *Panel1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TADOQuery *PreOADOQ;
	TcxLabel *cxLabel1;
	TcxComboBox *POBMComboBox;
	void __fastcall POBeginDateEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPreOrderQFrm(TComponent* Owner);
    String BFstarttime;
    String BFendtime;
    String LHstarttime;
    String LHendtime;
    String SRstarttime;
    String SRendtime;
    String NTstarttime;
    String NTendtime;
};
//---------------------------------------------------------------------------
extern PACKAGE TPreOrderQFrm *PreOrderQFrm;
//---------------------------------------------------------------------------
#endif
