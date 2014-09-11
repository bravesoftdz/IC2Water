//---------------------------------------------------------------------------

#ifndef SectionInfoFixFRMH
#define SectionInfoFixFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
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
#include <Menus.hpp>

#include "SectionInfoMngFRM.h"

//---------------------------------------------------------------------------
class TSectionInfoFixFROM : public TForm
{
__published:	// IDE-managed Components
	TcxLabel *cxLabel1;
	TcxButton *ConfirmSIFBTN;
	TcxButton *CancelSIFBTN;
	TcxTextEdit *SectionInfoFixEdit;
	void __fastcall CancelSIFBTNClick(TObject *Sender);
	void __fastcall ConfirmSIFBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSectionInfoFixFROM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSectionInfoFixFROM *SectionInfoFixFROM;
//---------------------------------------------------------------------------
#endif
