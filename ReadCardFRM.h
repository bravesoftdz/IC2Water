//---------------------------------------------------------------------------

#ifndef ReadCardFRMH
#define ReadCardFRMH
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
#include "cxLabel.hpp"
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
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "CardMXForm.h"
//---------------------------------------------------------------------------
class TReadCardInfoFRM : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxTextEdit *cxTextEdit7;
	TcxTextEdit *cxTextEdit9;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxTextEdit *cxTextEdit12;
	TcxLabel *cxLabel15;
	TcxTextEdit *cxTextEdit15;
	TcxLabel *cxLabel16;
	TcxTextEdit *cxTextEdit16;
	TcxButton *ReadCardInfoBTN;
	TcxButton *CloseFormBTN;
	TcxTextEdit *cxTextEdit17;
	TcxLabel *cxLabel13;
	TcxTextEdit *cxTextEdit18;
	TADOQuery *ADOCardInfoQuery;
	TcxGroupBox *cxGroupBox2;
	TcxButton *cxButton1;
	TcxComboBox *SectionNameComboBox;
	TADOQuery *ADOQuery1;
	TcxComboBox *ClassNameComboBox;
	TcxComboBox *GroupNameComboBox;
	TcxComboBox *DegreeComboBox;
	TcxButton *MXBTN;
	TcxComboBox *SexComboBox;
	TcxGroupBox *cxGroupBox3;
	TcxLabel *cxLabel6;
	TcxTextEdit *cxTextEdit6;
	TcxLabel *cxLabel5;
	TcxTextEdit *cxTextEdit5;
	TcxButton *cxButton2;
	TcxLabel *cxLabel17;
	TcxLabel *cxLabel18;
	TcxTextEdit *cxTextEdit8;
	void __fastcall ReadCardInfoBTNClick(TObject *Sender);
	void __fastcall CloseFormBTNClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall SectionNameComboBoxEnter(TObject *Sender);
	void __fastcall SectionNameComboBoxExit(TObject *Sender);
	void __fastcall SectionNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ClassNameComboBoxExit(TObject *Sender);
	void __fastcall ClassNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall GroupNameComboBoxExit(TObject *Sender);
	void __fastcall DegreeComboBoxEnter(TObject *Sender);
	void __fastcall DegreeComboBoxExit(TObject *Sender);
	void __fastcall ClassNameComboBoxEnter(TObject *Sender);
	void __fastcall GroupNameComboBoxEnter(TObject *Sender);
	void __fastcall MXBTNClick(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxTextEdit6KeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TReadCardInfoFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TReadCardInfoFRM *ReadCardInfoFRM;
//---------------------------------------------------------------------------
#endif
