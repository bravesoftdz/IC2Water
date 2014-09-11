//---------------------------------------------------------------------------

#ifndef CTQFormH
#define CTQFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
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
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "GlobalParameter.h"
#include <Dialogs.hpp>
#include "Comobj.hpp"
#include "frxClass.hpp"
//---------------------------------------------------------------------------
class TCTQFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel4;
	TcxDateEdit *CTBeginDateEdit;
	TcxLabel *cxLabel3;
	TcxDateEdit *CTEndDateEdit;
	TcxButton *QueryBTN;
	TcxComboBox *CTComboBox;
	TcxLabel *cxLabel5;
	TPanel *Panel1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TPanel *Panel2;
	TcxGroupBox *cxGroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TcxButton *ExportBTN;
	TcxButton *PreviewBTN;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxTextEdit *cxTextEdit5;
	TcxTextEdit *cxTextEdit6;
	TcxTextEdit *cxTextEdit7;
	TcxTextEdit *cxTextEdit8;
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
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TADOQuery *CTADOQ;
	TSaveDialog *SaveDialog;
	TfrxReport *frxCTTJReport;
	void __fastcall CTBeginDateEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ExportBTNClick(TObject *Sender);
	void __fastcall PreviewBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCTQFrm(TComponent* Owner);
    String BFstarttime;
    String BFendtime;
    String LHstarttime;
    String LHendtime;
    String SRstarttime;
    String SRendtime;
    String NTstarttime;
    String NTendtime;
    String BeginDatestr;
    String EndDatestr;
    String CTStr;
    double BFZE;
    int BFCS;
    double LHZE;
    int LHCS;
    double SRZE;
    int SRCS;
    double NTZE;
    int NTCS;
    double ALLZE;
    int ALLCS;

    bool BFtag;
    bool LHtag;
    bool SRtag;
    bool NTtag;
};
//---------------------------------------------------------------------------
extern PACKAGE TCTQFrm *CTQFrm;
//---------------------------------------------------------------------------
#endif
