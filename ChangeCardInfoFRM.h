//---------------------------------------------------------------------------

#ifndef ChangeCardInfoFRMH
#define ChangeCardInfoFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
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
#include "cxGridCustomTableView.hpp"
//---------------------------------------------------------------------------
class TChangeCardInfoForm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit5;
	TcxTextEdit *cxTextEdit6;
	TcxLabel *cxLabel7;
	TcxTextEdit *cxTextEdit7;
	TcxLabel *cxLabel15;
	TcxTextEdit *cxTextEdit15;
	TcxLabel *cxLabel16;
	TcxTextEdit *cxTextEdit16;
	TcxTextEdit *cxTextEdit17;
	TcxLabel *cxLabel13;
	TcxTextEdit *cxTextEdit18;
	TcxLabel *cxLabel14;
	TcxGroupBox *cxGroupBox2;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxTextEdit *cxTextEdit12;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxTextEdit *cxTextEdit9;
	TcxComboBox *SectionNameComboBox;
	TcxComboBox *ClassNameComboBox;
	TcxComboBox *GroupNameComboBox;
	TcxComboBox *DegreeComboBox;
	TADOQuery *ChangeCardInfoADOQ;
	TcxComboBox *SexComboBox;
	TADOQuery *ADOQuery1;
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall SectionNameComboBoxEnter(TObject *Sender);
	void __fastcall SectionNameComboBoxExit(TObject *Sender);
	void __fastcall SectionNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ClassNameComboBoxExit(TObject *Sender);
	void __fastcall ClassNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall DegreeComboBoxEnter(TObject *Sender);
	void __fastcall DegreeComboBoxExit(TObject *Sender);
	void __fastcall GroupNameComboBoxExit(TObject *Sender);
	void __fastcall ClassNameComboBoxEnter(TObject *Sender);
	void __fastcall GroupNameComboBoxEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TChangeCardInfoForm(TComponent* Owner);
	String BHStr;
	TcxCustomGridTableView* GBView;
};
//---------------------------------------------------------------------------
extern PACKAGE TChangeCardInfoForm *ChangeCardInfoForm;
//---------------------------------------------------------------------------
#endif
