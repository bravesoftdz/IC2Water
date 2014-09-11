//---------------------------------------------------------------------------

#ifndef SysConFRMH
#define SysConFRMH
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
#include "cxRadioGroup.hpp"
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
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
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
#include <ADODB.hpp>
#include "cxMemo.hpp"
#include "CheckIDFRM.h"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTimeEdit.hpp"
#include "PreorderdealFRM.h"

//---------------------------------------------------------------------------
class TSystemConfigFRM : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxGroupBox *cxGroupBox1;
	TcxTextEdit *TECancelCardDeposit;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxTextEdit *TEDeliverCardDeposit;
	TcxTextEdit *TEUnitName;
	TcxTextEdit *TEUnitPassword;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel14;
	TcxGroupBox *cxGroupBox2;
	TcxTextEdit *TEDailyMaxConsumption4;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxTextEdit *TEDailyMaxConsumption3;
	TcxTextEdit *TEDailyMaxConsumption2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxTextEdit *TEDailyMaxConsumption1;
	TcxTextEdit *TEDailyMaxConsumption;
	TcxLabel *cxLabel15;
	TcxGroupBox *cxGroupBox3;
	TcxButton *BTUnitName;
	TcxButton *TBUnitPassword;
	TcxButton *TBDeliverCardDeposit;
	TcxButton *TBCancelCardDeposit;
	TcxButton *TBDailyMaxConsumption;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
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
	TADOQuery *ADOQuery1;
	TcxMemo *cxMemo1;
	TcxLabel *cxLabel5;
	TcxTextEdit *TEMaxPosNUM;
	TcxButton *TBMaxPosNUM;
	TcxButton *TBDailyMaxConsumption1;
	TcxButton *TBDailyMaxConsumption2;
	TcxButton *TBDailyMaxConsumption3;
	TcxButton *TBDailyMaxConsumption4;
	TcxLabel *cxLabel6;
	TcxTextEdit *TECardPassword;
	TcxButton *TBCardPassWord;
	TcxLabel *cxLabel7;
	TcxTextEdit *TEPasswordEdtion;
	TcxButton *TBPasswordEdtion;
	TcxGroupBox *cxGroupBox5;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TcxTimeEdit *cxTimeEdit1;
	TcxTimeEdit *cxTimeEdit2;
	TcxTimeEdit *cxTimeEdit3;
	TcxTimeEdit *cxTimeEdit4;
	TcxTimeEdit *cxTimeEdit5;
	TcxTimeEdit *cxTimeEdit6;
	TcxTimeEdit *cxTimeEdit7;
	TcxTimeEdit *cxTimeEdit8;
	TcxButton *cxButton1;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxTextEdit *cxTextEdit5;
	TcxTextEdit *cxTextEdit6;
	TcxTextEdit *cxTextEdit7;
	TcxTextEdit *cxTextEdit8;
	TADOTable *ADOTable2;
	TPanel *Panel3;
	TPanel *Panel6;
	TcxTextEdit *cxTextEdit9;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxTextEdit *cxTextEdit12;
	TcxTextEdit *cxTextEdit13;
	TcxTextEdit *cxTextEdit14;
	TcxTextEdit *cxTextEdit15;
	TcxTextEdit *cxTextEdit16;
	TcxTextEdit *cxTextEdit17;
	TcxTextEdit *cxTextEdit18;
	TcxTextEdit *cxTextEdit19;
	TcxTextEdit *cxTextEdit20;
	TcxTextEdit *cxTextEdit21;
	TcxTextEdit *cxTextEdit22;
	TcxTextEdit *cxTextEdit23;
	TcxTextEdit *cxTextEdit24;
	TcxTextEdit *cxTextEdit25;
	TcxTextEdit *cxTextEdit26;
	TcxTextEdit *cxTextEdit27;
	TcxTextEdit *cxTextEdit28;
	TcxTextEdit *cxTextEdit29;
	TcxTextEdit *cxTextEdit30;
	TcxTextEdit *cxTextEdit31;
	TcxTextEdit *cxTextEdit32;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TPanel *Panel5;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TLabel *Label22;
	TCheckBox *CheckBox5;
	TPanel *Panel10;
	TcxButton *cxButton2;
	TcxLabel *cxLabel8;
	TcxButton *SystemNameBTN;
	TcxTextEdit *SystemNameTextEdit;
	TcxLabel *cxLabel16;
	TcxTextEdit *TEUsingSector;
	TcxButton *TBUsingSector;
	TcxGroupBox *cxGroupBox4;
	TPanel *Panel4;
	TcxButton *cxButton8;
	TcxGrid *FLGrid;
	TcxGridDBTableView *FLGridTV;
	TcxGridDBColumn *FLGridTVDM;
	TcxGridDBColumn *FLGridTVFL;
	TcxGridLevel *FLGridLL;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BTUnitNameClick(TObject *Sender);
	void __fastcall TBUnitPasswordClick(TObject *Sender);
	void __fastcall TBDeliverCardDepositClick(TObject *Sender);
	void __fastcall TBUsingSectorClick(TObject *Sender);
	void __fastcall TBDailyMaxConsumptionClick(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall TBMaxPosNUMClick(TObject *Sender);
	void __fastcall TEUnitPasswordKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEUnitPasswordExit(TObject *Sender);
	void __fastcall TECardPasswordKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TECardPasswordExit(TObject *Sender);
	void __fastcall TEPasswordEdtionExit(TObject *Sender);
	void __fastcall TBCancelCardDepositClick(TObject *Sender);
	void __fastcall TBCardPassWordClick(TObject *Sender);
	void __fastcall TBPasswordEdtionClick(TObject *Sender);
	void __fastcall TEDeliverCardDepositKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TECancelCardDepositKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEPasswordEdtionKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEUsingSectorKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEDailyMaxConsumptionKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEDailyMaxConsumption1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEDailyMaxConsumption2KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEDailyMaxConsumption3KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEDailyMaxConsumption4KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TEMaxPosNUMKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall TBDailyMaxConsumption1Click(TObject *Sender);
	void __fastcall TBDailyMaxConsumption2Click(TObject *Sender);
	void __fastcall TBDailyMaxConsumption3Click(TObject *Sender);
	void __fastcall TBDailyMaxConsumption4Click(TObject *Sender);
	void __fastcall TECardPasswordKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall TEPasswordEdtionKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SystemNameBTNClick(TObject *Sender);
	void __fastcall TEUsingSectorKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall CheckBox6Click(TObject *Sender);
	void __fastcall CheckBox7Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxTextEdit1Exit(TObject *Sender);
	void __fastcall TEUsingSectorExit(TObject *Sender);

//	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);


private:	// User declarations
public:		// User declarations
	__fastcall TSystemConfigFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSystemConfigFRM *SystemConfigFRM;
//---------------------------------------------------------------------------
#endif
