//---------------------------------------------------------------------------

#ifndef PreOrderMXFormH
#define PreOrderMXFormH
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

#include "GlobalParameter.h"
#include "POMXExportThread.h"

//---------------------------------------------------------------------------
class TPreOrderMXFrm : public TForm
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
	TcxGroupBox *cxGroupBox5;
	TcxGroupBox *cxGroupBox6;
	TcxGroupBox *cxGroupBox7;
	TcxGroupBox *cxGroupBox8;
	TcxGroupBox *cxGroupBox9;
	TcxGroupBox *cxGroupBox10;
	TLabel *Label9;
	TLabel *Label10;
	TcxTextEdit *BFDCCSTextEdit;
	TcxTextEdit *BFDCJETextEdit;
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
	TfrxReport *frxDCMXReport;
	TfrxDBDataset *frxDBDataset1;
	TADOQuery *TJADOQuery;
	TcxTextEdit *BFXFCSTextEdit;
	TcxTextEdit *BFXFJETextEdit;
	TLabel *Label11;
	TLabel *Label12;
	TcxTextEdit *BFZETextEdit;
	TLabel *Label13;
	TcxTextEdit *LHDCCSTextEdit;
	TLabel *Label1;
	TLabel *Label2;
	TcxTextEdit *LHDCJETextEdit;
	TcxTextEdit *LHXFCSTextEdit;
	TLabel *Label3;
	TLabel *Label4;
	TcxTextEdit *LHXFJETextEdit;
	TcxTextEdit *LHZETextEdit;
	TLabel *Label5;
	TcxTextEdit *SPDCCSTextEdit;
	TLabel *Label6;
	TLabel *Label7;
	TcxTextEdit *SPDCJETextEdit;
	TcxTextEdit *SPXFCSTextEdit;
	TLabel *Label8;
	TLabel *Label14;
	TcxTextEdit *SPXFJETextEdit;
	TcxTextEdit *SPZETextEdit;
	TLabel *Label15;
	TcxTextEdit *NTDCCSTextEdit;
	TLabel *Label16;
	TLabel *Label17;
	TcxTextEdit *NTDCJETextEdit;
	TcxTextEdit *NTXFCSTextEdit;
	TLabel *Label18;
	TLabel *Label19;
	TcxTextEdit *NTXFJETextEdit;
	TcxTextEdit *NTZETextEdit;
	TLabel *Label20;
	TcxTextEdit *DCCSTextEdit;
	TLabel *Label21;
	TLabel *Label22;
	TcxTextEdit *DCJETextEdit;
	TcxTextEdit *XFCSTextEdit;
	TLabel *Label23;
	TLabel *Label24;
	TcxTextEdit *XFJETextEdit;
	TcxTextEdit *ZETextEdit;
	TLabel *Label25;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CBMXExitBTNClick(TObject *Sender);
	void __fastcall CBMXExportBTNClick(TObject *Sender);
	void __fastcall PreviewBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPreOrderMXFrm(TComponent* Owner);
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
    String MSBMStr;
    bool MSBFtag;
    bool MSLHtag;
    bool MSSRtag;
    bool MSNTtag;
    String MSCZYStr;

    double BFPSUM;
    double BFASUM;
    double BFSUM;
    int BFPCOUNT;
    int BFACOUNT;

    double LHPSUM;
    double LHASUM;
    double LHSUM;
    int LHPCOUNT;
    int LHACOUNT;

    double SRPSUM;
    double SRASUM;
    double SRSUM;
    int SRPCOUNT;
    int SRACOUNT;

    double NTPSUM;
    double NTASUM;
    double NTSUM;
    int NTPCOUNT;
    int NTACOUNT;
};
//---------------------------------------------------------------------------
extern PACKAGE TPreOrderMXFrm *PreOrderMXFrm;
//---------------------------------------------------------------------------
#endif
