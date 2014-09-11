//---------------------------------------------------------------------------

#ifndef CZMXQFormH
#define CZMXQFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>

#include "GlobalParameter.h"
#include "CZMXShowForm.h"

//---------------------------------------------------------------------------
class TCZMXQFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel4;
	TcxDateEdit *CZBeginDateEdit;
	TcxLabel *cxLabel3;
	TcxDateEdit *CZEndDateEdit;
	TcxLabel *cxLabel15;
	TcxTextEdit *CZKHTextEdit;
	TcxTextEdit *CZBHTextEdit;
	TcxLabel *cxLabel17;
	TcxComboBox *CZCZYComboBox;
	TcxLabel *cxLabel16;
	TcxLabel *cxLabel1;
	TcxComboBox *CZBMComboBox;
	TcxButton *ReadCardInfoBTN;
	TcxCheckBox *cxCheckBox1;
	TcxCheckBox *cxCheckBox2;
	TcxCheckBox *cxCheckBox3;
	TcxButton *QueryBTN;
	TADOQuery *CKADOQ;
	TcxButton *cxButton1;
	TcxLabel *cxLabel2;
	TcxComboBox *BBComboBox;
	TcxLabel *cxLabel5;
	TcxComboBox *ZBComboBox;
	TADOQuery *QADOQ;
	void __fastcall CZKHTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CZBHTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CZBMComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CZCZYComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ReadCardInfoBTNClick(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall CZEndDateEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CZBeginDateEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall CZBMComboBoxPropertiesChange(TObject *Sender);
	void __fastcall BBComboBoxEnter(TObject *Sender);
	void __fastcall BBComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ZBComboBoxEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCZMXQFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCZMXQFrm *CZMXQFrm;
//---------------------------------------------------------------------------
#endif
