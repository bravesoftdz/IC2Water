//---------------------------------------------------------------------------

#ifndef BatchLaunchCardFRMH
#define BatchLaunchCardFRMH
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
#include "cxButtons.hpp"
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
#include "cxMemo.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include "dxSkinscxPCPainter.hpp"
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "cxListView.hpp"
#include <ComCtrls.hpp>
#include "Comobj.hpp"
#include "GlobalParameter.h"
#include "ChooseDataFrm.h"
//---------------------------------------------------------------------------
class TBatchLaunchCardForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *ImportDataBTN;
	TcxButton *BatchBTN;
	TcxButton *ExitBTN;
	TcxGroupBox *cxGroupBox3;
	TcxMemo *cxMemo1;
	TPanel *Panel3;
	TOpenDialog *OpenDialog1;
	TcxListView *cxListView1;
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ImportDataBTNClick(TObject *Sender);
	void __fastcall BatchBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBatchLaunchCardForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBatchLaunchCardForm *BatchLaunchCardForm;
//---------------------------------------------------------------------------
#endif
