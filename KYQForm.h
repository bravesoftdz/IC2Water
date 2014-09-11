//---------------------------------------------------------------------------

#ifndef KYQFormH
#define KYQFormH
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
#include "cxProgressBar.hpp"
#include "cxStyles.hpp"
#include "dxSkinscxPCPainter.hpp"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>

#include "GlobalParameter.h"
#include "KYExportThread.h"
//---------------------------------------------------------------------------
class TKYQFrm : public TForm
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
	TcxTextEdit *XMTextEdit;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TcxGrid *DataGrid;
	TcxGridDBTableView *DataGridDBTV;
	TcxGridLevel *DataGridLL;
	TcxGroupBox *cxGroupBox4;
	TcxProgressBar *KYExportProgressBar;
	TcxGroupBox *cxGroupBox5;
	TPanel *Panel2;
	TcxButton *KYExportBTN;
	TcxButton *KYExitBTN;
	TcxButton *PreviewBTN;
	TcxGroupBox *cxGroupBox6;
	TPanel *Panel1;
	TcxStyleRepository *cxStyleRepository1;
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
	TcxGridTableViewStyleSheet *GridTableViewStyleSheetDevExpress;
	TADOQuery *KYADOQuery;
	TDataSource *KYDataSource;
	TSaveDialog *SaveDialog;
	TADOQuery *ADOQInThread;
	TfrxReport *frxKYReport;
	TfrxDBDataset *frxDBDataset1;
	TcxButton *ReadCardInfoBTN;
	TcxButton *QueryBTN;
	TcxTextEdit *AllKYTextEdit;
	TLabel *Label2;
	TcxTextEdit *AllKSTextEdit;
	TLabel *Label1;
	void __fastcall BMComboBoxKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall BHTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KYExitBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ReadCardInfoBTNClick(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall KYExportBTNClick(TObject *Sender);
	void __fastcall PreviewBTNClick(TObject *Sender);
	void __fastcall AllKSTextEditKeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TKYQFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKYQFrm *KYQFrm;
//---------------------------------------------------------------------------
#endif
