//---------------------------------------------------------------------------

#ifndef MakeAssistanceFRMH
#define MakeAssistanceFRMH
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
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "cxMemo.hpp"
#include <ExtCtrls.hpp>
#include "cxProgressBar.hpp"
//#include "cxRadioGroup.hpp"
#include "cxCheckGroup.hpp"
#include <ADODB.hpp>
#include <DB.hpp>

#include "MakeAssistanceFRM.h"
#include "GlobalParameter.h"
#include "CreateCSBTThread.h"
#include "CreateJBBTThread.h"

//---------------------------------------------------------------------------
class TMakeAssistancedFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxMemo *cxMemo1;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TcxDateEdit *BeginDateEdit;
	TcxDateEdit *EndDateEdit;
	TcxTextEdit *BTJETextEdit;
	TLabel *Label4;
	TcxTextEdit *BTCSUTextEdit;
	TcxButton *CSBTBTN;
	TcxProgressBar *CSBTProgressBar;
	TLabel *Label5;
	TcxComboBox *BTGComboBox;
	TLabel *Label6;
	TcxTextEdit *BTJEGTextEdit;
	TPanel *Panel3;
	TPanel *Panel4;
	TcxCheckGroup *JBRQCheckGroup;
	TPanel *Panel5;
	TcxProgressBar *JBBTProgressBar;
	TcxButton *JBBTBTN;
	TcxButton *JBJEBTN;
	TADOQuery *BTZWADOQ;
	TADOQuery *CSBTADOQ;
	TcxButton *BTExitBTN;
	TADOQuery *CSBTinBaseADOQ;
	TADOQuery *JBBTADOQ;
	TADOQuery *JBBTinBaseADOQ;
	TPanel *Panel6;
	void __fastcall BTJETextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall BTCSUTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall BTJEGTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CSBTBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BTExitBTNClick(TObject *Sender);
	void __fastcall JBBTBTNClick(TObject *Sender);
	void __fastcall JBJEBTNClick(TObject *Sender);
private:	// User declarations
	TCreateCSBTThread* CreateCSBTThread;
    TCreateJBBTThread* CreateJBBTThread;
public:		// User declarations
	__fastcall TMakeAssistancedFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMakeAssistancedFRM *MakeAssistancedFRM;
//---------------------------------------------------------------------------
#endif
