//---------------------------------------------------------------------------

#ifndef ReChargePosMXQueryFormH
#define ReChargePosMXQueryFormH
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
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TReChargePosForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TcxLabel *cxLabel4;
	TcxDateEdit *CZBeginDateEdit;
	TcxLabel *cxLabel3;
	TcxDateEdit *CZEndDateEdit;
	TcxLabel *cxLabel1;
	TcxButton *QueryBTN;
	TADOQuery *CZJADOQ;
	TcxButton *cxButton1;
	TcxComboBox *JHComboBox;
	TcxLabel *cxLabel15;
	TcxTextEdit *CZKHTextEdit;
	TcxLabel *cxLabel17;
	TcxTextEdit *CZBHTextEdit;
	TcxComboBox *CZBMComboBox;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel5;
	TcxComboBox *BBComboBox;
	TcxLabel *cxLabel6;
	TcxComboBox *ZBComboBox;
	TADOQuery *QADOQ;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CZKHTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CZBMComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CZBMComboBoxPropertiesChange(TObject *Sender);
	void __fastcall BBComboBoxEnter(TObject *Sender);
	void __fastcall ZBComboBoxEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TReChargePosForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TReChargePosForm *ReChargePosForm;
//---------------------------------------------------------------------------
#endif
