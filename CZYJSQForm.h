//---------------------------------------------------------------------------

#ifndef CZYJSQFormH
#define CZYJSQFormH
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
#include <Menus.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <Dialogs.hpp>
#include "Comobj.hpp"
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TCZYJSQFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxDateEdit *JSBeginDateEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel3;
	TcxDateEdit *JSEndDateEdit;
	TcxButton *QueryBTN;
	TcxComboBox *USERComboBox;
	TcxLabel *cxLabel1;
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
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
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
	TcxTextEdit *cxTextEdit21;
	TcxTextEdit *cxTextEdit22;
	TcxTextEdit *cxTextEdit23;
	TcxTextEdit *cxTextEdit24;
	TcxTextEdit *cxTextEdit25;
	TcxTextEdit *cxTextEdit26;
	TcxTextEdit *cxTextEdit27;
	TcxGroupBox *cxGroupBox3;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TcxTextEdit *cxTextEdit28;
	TcxTextEdit *cxTextEdit29;
	TcxTextEdit *cxTextEdit30;
	TcxButton *ExportBTN;
	TcxButton *PreviewBTN;
	TcxButton *ExitBTN;
	TDataSource *JSDataSource;
	TADOQuery *JSADOQuery;
	TSaveDialog *SaveDialog;
	TfrxDBDataset *frxDBDataset1;
	TfrxReport *frxJSReport;
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall ExportBTNClick(TObject *Sender);
	void __fastcall PreviewBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCZYJSQFrm(TComponent* Owner);
    String QSSJstr;
    String JZSJstr;
    String QCZYstr;

    String KZCSstr;
    String KCBstr;
    String KZEstr;

    String AZCSstr;
    String ACBstr;
    String AZEstr;

    String IZCSstr;
    String ICBstr;
    String IZEstr;

    String GZCSstr;
    String GCBstr;
    String GZEstr;

    String DZCSstr;
    String DCBstr;
    String DZEstr;

    String CZCSstr;
    String CCBstr;
    String CZEstr;

    String TZCSstr;
    String TCBstr;
    String TZEstr;

    String QZCSstr;
    String QCBstr;
    String QZEstr;

    String JSZCSstr;
    String JSZCBstr;
    String JSZJEstr;

    String ZCZJEstr;
    String SRZJEstr;
    String ZJSstr;
};
//---------------------------------------------------------------------------
extern PACKAGE TCZYJSQFrm *CZYJSQFrm;
//---------------------------------------------------------------------------
#endif
