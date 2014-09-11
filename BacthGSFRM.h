//---------------------------------------------------------------------------

#ifndef BacthGSFRMH
#define BacthGSFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
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
#include "cxProgressBar.hpp"
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
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

#include "BatchGSThread.h"
//---------------------------------------------------------------------------
class TBatchGSForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TLabel *Label1;
	TcxComboBox *cxComboBox1;
	TcxComboBox *cxComboBox2;
	TLabel *Label2;
	TcxButton *cxButton1;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TADOQuery *ADOQuery1;
	TcxGrid *DataGrid;
	TcxGridDBTableView *DataGridDBTV;
	TcxGridDBColumn *DataGridDBTVColumn1;
	TcxGridDBColumn *DataGridDBTVColumn2;
	TcxGridDBColumn *DataGridDBTVColumn3;
	TcxGridDBColumn *DataGridDBTVColumn4;
	TcxGridDBColumn *DataGridDBTVColumn5;
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
	TDataSource *DataSource1;
	TADOQuery *ADOQuery2;
	TADOQuery *ADOQThread;
	TcxProgressBar *cxProgressBar1;
	TADOQuery *ADOQuery3;
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxComboBox1Enter(TObject *Sender);
	void __fastcall cxComboBox1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxComboBox2Enter(TObject *Sender);
	void __fastcall cxComboBox1Exit(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
private:	// User declarations
	TBatchGSThread* BGSThread;
public:		// User declarations
	__fastcall TBatchGSForm(TComponent* Owner);
	String sqlinthread;
};
//---------------------------------------------------------------------------
extern PACKAGE TBatchGSForm *BatchGSForm;
//---------------------------------------------------------------------------
#endif
