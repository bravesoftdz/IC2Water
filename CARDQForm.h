//---------------------------------------------------------------------------

#ifndef CARDQFormH
#define CARDQFormH
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
#include <Menus.hpp>

#include "GlobalParameter.h"
#include "CARDShowForm.h"
//---------------------------------------------------------------------------
class TCARDQFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel15;
	TcxTextEdit *KHTextEdit;
	TcxTextEdit *BHTextEdit;
	TcxLabel *cxLabel17;
	TcxLabel *cxLabel16;
	TcxLabel *cxLabel1;
	TcxComboBox *BMComboBox;
	TcxButton *QueryBTN;
	TcxTextEdit *XMTextEdit;
	TcxLabel *cxLabel2;
	TcxComboBox *ZBComboBox;
	TcxLabel *cxLabel5;
	TADOQuery *CARDADOQ;
	TcxComboBox *BBComboBox;
	TADOQuery *QADOQ;
	void __fastcall KHTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall BMComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BBComboBoxEnter(TObject *Sender);
	void __fastcall ZBComboBoxEnter(TObject *Sender);
	void __fastcall BMComboBoxPropertiesChange(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCARDQFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCARDQFrm *CARDQFrm;
//---------------------------------------------------------------------------
#endif
