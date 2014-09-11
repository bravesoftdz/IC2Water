//---------------------------------------------------------------------------

#ifndef AddPosFrmH
#define AddPosFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
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
#include <Menus.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TADDPOSForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxButton *ADDBTN;
	TcxButton *ExitBTN;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit7;
	TcxTextEdit *cxTextEdit8;
	TcxTextEdit *cxTextEdit9;
	TcxTextEdit *cxTextEdit11;
	TcxTextEdit *cxTextEdit12;
	TcxComboBox *cxComboBox1;
	TcxComboBox *cxComboBox2;
	TADOQuery *ADOQuery1;
	TcxComboBox *cxComboBox3;
	TcxComboBox *cxComboBox4;
	TcxComboBox *cxComboBox5;
	TLabel *Label6;
	TcxTextEdit *cxTextEdit2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TcxTextEdit *MaxCSEdit;
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit12KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit7KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit8KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall cxComboBox1PropertiesChange(TObject *Sender);
	void __fastcall ADDBTNClick(TObject *Sender);
	void __fastcall cxComboBox4PropertiesChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxComboBox1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxComboBox5KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall MaxCSEditExit(TObject *Sender);
	void __fastcall MaxCSEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxComboBox4KeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TADDPOSForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TADDPOSForm *ADDPOSForm;
//---------------------------------------------------------------------------
#endif
