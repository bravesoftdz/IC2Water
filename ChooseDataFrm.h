//---------------------------------------------------------------------------

#ifndef ChooseDataFrmH
#define ChooseDataFrmH
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
#include "cxMemo.hpp"
#include "cxRadioGroup.hpp"
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
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "BatchLaunchCardProcessFrm.h"

//---------------------------------------------------------------------------
class TChooseDataForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox5;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TPanel *Panel1;
	TPanel *Panel2;
	TcxMemo *cxMemo1;
	TPanel *Panel3;
	TcxRadioGroup *cxRadioGroup1;
	TcxRadioGroup *cxRadioGroup3;
	TcxRadioGroup *cxRadioGroup4;
	TcxRadioGroup *cxRadioGroup5;
	TcxRadioGroup *cxRadioGroup2;
	TcxRadioGroup *cxRadioGroup6;
	TcxRadioGroup *cxRadioGroup7;
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TChooseDataForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChooseDataForm *ChooseDataForm;
//---------------------------------------------------------------------------
#endif
