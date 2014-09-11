//---------------------------------------------------------------------------

#ifndef DealMistakFRMH
#define DealMistakFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
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
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxTimeEdit.hpp"
#include <ExtCtrls.hpp>
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
//---------------------------------------------------------------------------
class TDealMistakeForm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TcxGroupBox *cxGroupBox1;
	TMemo *Memo1;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TcxDateEdit *cxDateEdit1;
	TcxTimeEdit *cxTimeEdit1;
	TcxTimeEdit *cxTimeEdit2;
	TcxGrid *DataGrid;
	TcxGridDBTableView *DataGridDBTV;
	TcxGridLevel *DataGridLL;
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
	TLabel *Label4;
	TcxTextEdit *cxTextEdit1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TcxGridDBColumn *DataGridDBTVColumn1;
	TcxGridDBColumn *DataGridDBTVColumn2;
	TcxGridDBColumn *DataGridDBTVColumn3;
	TcxGridDBColumn *DataGridDBTVColumn4;
	TcxGridDBColumn *DataGridDBTVColumn5;
	TLabel *Label5;
	TcxTextEdit *cxTextEdit2;
	TADOTable *ADOTable1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButton3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDealMistakeForm(TComponent* Owner);
	int querykh;
	String bhstr;
};
//---------------------------------------------------------------------------
extern PACKAGE TDealMistakeForm *DealMistakeForm;
//---------------------------------------------------------------------------
#endif
