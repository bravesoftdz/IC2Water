//---------------------------------------------------------------------------

#ifndef SingleWDGSFrmH
#define SingleWDGSFrmH
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
#include "cxListView.hpp"
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
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <Menus.hpp>
#include "SingleGSThread.h"
//---------------------------------------------------------------------------
class TSingleWDGSForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TcxTextEdit *cxTextEdit1;
	TcxButton *GSBTN;
	TcxButton *ExitBTN;
	TADOQuery *ADOQuery1;
	TcxListView *cxListView1;
	TADOQuery *ADOInThread;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall GSBTNClick(TObject *Sender);
private:	// User declarations
	TSingleGSThread* vaildgsthread;
public:		// User declarations
	__fastcall TSingleWDGSForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSingleWDGSForm *SingleWDGSForm;
//---------------------------------------------------------------------------
#endif
