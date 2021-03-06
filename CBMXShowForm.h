//---------------------------------------------------------------------------

#ifndef CBMXShowFormH
#define CBMXShowFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxProgressBar.hpp"
#include "cxStyles.hpp"
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
#include "dxSkinscxPCPainter.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxTextEdit.hpp"

#include "CBMXExportThread.h"
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TCBMXShowFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxGrid *DataGrid;
	TcxGridDBTableView *DataGridDBTV;
	TcxGridLevel *DataGridLL;
	TcxGroupBox *cxGroupBox2;
	TcxProgressBar *CBMXExportProgressBar;
	TcxGroupBox *cxGroupBox3;
	TPanel *Panel2;
	TcxButton *CBMXExportBTN;
	TcxButton *CBMXExitBTN;
	TcxButton *PreviewBTN;
	TcxGroupBox *cxGroupBox4;
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
	TADOQuery *CBMXADOQuery;
	TDataSource *CBMXDataSource;
	TSaveDialog *SaveDialog;
	TADOQuery *ADOQInThread;
	TfrxReport *frxCBMXReport;
	TfrxDBDataset *frxDBDataset1;
	TADOQuery *TJADOQuery;
	TcxGroupBox *cxGroupBox5;
	TLabel *Label1;
	TcxTextEdit *ZCSTextEdit;
	TcxGroupBox *cxGroupBox6;
	TLabel *Label5;
	TcxTextEdit *ZZETextEdit;
	TcxGroupBox *cxGroupBox7;
	TLabel *Label2;
	TLabel *Label3;
	TcxTextEdit *NTCSTextEdit;
	TcxTextEdit *NTZETextEdit;
	TcxGroupBox *cxGroupBox8;
	TLabel *Label4;
	TLabel *Label6;
	TcxTextEdit *SRCSTextEdit;
	TcxTextEdit *SRZETextEdit;
	TcxGroupBox *cxGroupBox9;
	TLabel *Label7;
	TLabel *Label8;
	TcxTextEdit *LHCSTextEdit;
	TcxTextEdit *LHZETextEdit;
	TcxGroupBox *cxGroupBox10;
	TLabel *Label9;
	TLabel *Label10;
	TcxTextEdit *BFCSTextEdit;
	TcxTextEdit *BFZETextEdit;
	void __fastcall CBMXExitBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CBMXExportBTNClick(TObject *Sender);
	void __fastcall PreviewBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCBMXShowFrm(TComponent* Owner);
    String MSCBBFstarttime;
    String MSCBBFendtime;
    String MSCBLHstarttime;
    String MSCBLHendtime;
    String MSCBSRstarttime;
    String MSCBSRendtime;
    String MSCBNTstarttime;
    String MSCBNTendtime;
    String MSBeginDateTimeStr;
    String MSEndDateTimeStr;
    String MSCTStr;
    bool MSBFtag;
    bool MSLHtag;
    bool MSSRtag;
    bool MSNTtag;
    String MSCZYStr;

    double BFSUM;
    int BFCOUNT;
    double LHSUM;
    int LHCOUNT;
    double SRSUM;
    int SRCOUNT;
    double NTSUM;
    int NTCOUNT;
};
//---------------------------------------------------------------------------
extern PACKAGE TCBMXShowFrm *CBMXShowFrm;
//---------------------------------------------------------------------------
#endif
