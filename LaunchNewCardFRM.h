//---------------------------------------------------------------------------

#ifndef launchNewCardFRMH
#define launchNewCardFRMH
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
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "dxSkinscxPCPainter.hpp"
#include <DB.hpp>
#include "cxPropertiesStore.hpp"
#include <ADODB.hpp>
#include "cxHeader.hpp"

//#include <stdio.h>
#include "cxSpinEdit.hpp"
#include "cxTimeEdit.hpp"
#include "cxCalendar.hpp"

#include<time.h>
#include <jpeg.hpp>

//---------------------------------------------------------------------------
class TLaunchNewUserCardFRM : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel3;
	TcxLabel *cxLabel4;
	TcxGroupBox *cxGroupBox1;
	TcxTextEdit *DegreeTextEdit;
	TcxLabel *cxLabel14;
	TcxLabel *cxLabel12;
	TcxTextEdit *cxTextEdit4;
	TcxComboBox *DegreeComboBox;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel8;
	TcxComboBox *SectionNameComboBox;
	TcxTextEdit *UserNameTextEdit;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel2;
	TcxTextEdit *NumberOFCardTextEdit;
	TcxTextEdit *SerialOFCardTextEdit;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel7;
	TcxComboBox *UserSexComboBox;
	TcxComboBox *ClassNameComboBox;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel11;
	TcxComboBox *GroupNameComboBox;
	TcxTextEdit *IdentityIDTextEdit;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel15;
	TcxTextEdit *PerPassWordTextEdit;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TcxLabel *cxLabel16;
	TcxTextEdit *DepositTextEdit;
	TcxLabel *Label17;
	TcxTextEdit *PrepayTextEdit;
	TcxLabel *cxLabel18;
	TcxLabel *cxLabel19;
	TcxLabel *cxLabel20;
	TcxCheckBox *DateCheckBox;
	TcxCheckBox *cxCheckBox2;
	TcxCheckBox *cxCheckBox3;
	TcxButton *LaunchNewCardBTN;
	TcxButton *LaunchNewCardExitBTN;
	TDataSource *DataSource1;
	TADOTable *ADOTable1;
	TcxStyleRepository *cxStyleRepository1;
	TcxGridTableViewStyleSheet *GridTableViewStyleSheetDevExpress;
	TcxStyle *cxStyle1;
	TcxStyle *cxStyle2;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TcxStyle *cxStyle5;
	TcxStyle *cxStyle6;
	TcxStyle *cxStyle7;
	TcxStyle *cxStyle8;
	TcxStyle *cxStyle9;
	TcxStyle *cxStyle10;
	TcxStyle *cxStyle11;
	TcxStyle *cxStyle12;
	TcxStyle *cxStyle13;
	TcxStyle *cxStyle14;
	TADOQuery *LaunchNewCardADOQ;
	TcxComboBox *ConsumeRateComboBox;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *LaunchProcessPanel;
	TPanel *Panel7;
	TcxDateEdit *UseDateEdit;
	TADOTable *UpdateInfoADOTable;
	TADOCommand *ADOCommand1;
	TADOQuery *ADOQuery1;
	TADOQuery *GetNumADOQ;
	TImage *Image1;
	TcxButton *cxButton1;
	TcxLabel *cxLabel1;
	TcxTextEdit *cxTextEdit1;
	TGroupBox *GroupBox2;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit7;
	TEdit *Edit8;
	TButton *LaunchFLBTN;
	TButton *LaunchTimeBTN;
	TButton *LaunchClearBTN;
	TButton *ReadSupCardBTN;
	TADOQuery *SuperInDBADOQ;
	void __fastcall LaunchNewCardExitBTNClick(TObject *Sender);
	void __fastcall LaunchNewCardBTNClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SectionNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall ClassNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall UserNameTextEditExit(TObject *Sender);
	void __fastcall UserSexComboBoxExit(TObject *Sender);
	void __fastcall SectionNameComboBoxExit(TObject *Sender);
	void __fastcall DegreeComboBoxExit(TObject *Sender);
	void __fastcall IdentityIDTextEditExit(TObject *Sender);
	void __fastcall PerPassWordTextEditExit(TObject *Sender);
	void __fastcall DegreeTextEditExit(TObject *Sender);
	void __fastcall IdentityIDTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall PerPassWordTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall PrepayTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall NumberOFCardTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SerialOFCardTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SerialOFCardTextEditExit(TObject *Sender);
	void __fastcall NumberOFCardTextEditExit(TObject *Sender);
	void __fastcall SectionNameComboBoxEnter(TObject *Sender);
	void __fastcall DegreeComboBoxEnter(TObject *Sender);
	void __fastcall PrepayTextEditExit(TObject *Sender);
	void __fastcall GroupNameComboBoxExit(TObject *Sender);
	void __fastcall ClassNameComboBoxExit(TObject *Sender);
	void __fastcall SectionNameComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall UserNameTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall UserSexComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ClassNameComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall DegreeComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall GroupNameComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall DegreeTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall DepositTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ConsumeRateComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall LaunchFLBTNClick(TObject *Sender);
	void __fastcall LaunchTimeBTNClick(TObject *Sender);
	void __fastcall LaunchClearBTNClick(TObject *Sender);
	void __fastcall ReadSupCardBTNClick(TObject *Sender);
    void __fastcall CRCProc(unsigned char* InData, int len, unsigned char* CRCData);

private:	// User declarations
public:		// User declarations
	__fastcall TLaunchNewUserCardFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLaunchNewUserCardFRM *LaunchNewUserCardFRM;
//---------------------------------------------------------------------------
#endif
