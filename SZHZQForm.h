//---------------------------------------------------------------------------

#ifndef SZHZQFormH
#define SZHZQFormH
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
#include "cxMemo.hpp"
#include "Comobj.hpp"
#include "GlobalParameter.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSZHZQFrm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxDateEdit *ZHBeginDateEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel3;
	TcxDateEdit *ZHEndDateEdit;
	TcxButton *QueryBTN;
	TcxComboBox *BMComboBox;
	TcxLabel *cxLabel1;
	TcxGroupBox *cxGroupBox3;
	TcxButton *ExportBTN;
	TcxButton *PreviewBTN;
	TcxButton *ExitBTN;
	TDataSource *ZHDataSource;
	TADOQuery *ZHADOQuery;
	TfrxReport *frxZHReport;
	TSaveDialog *SaveDialog;
	TfrxDBDataset *frxDBDataset1;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TcxMemo *cxMemo1;
	TcxGroupBox *cxGroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label17;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
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
	TcxTextEdit *cxTextEdit15;
	TcxTextEdit *cxTextEdit22;
	TcxTextEdit *cxTextEdit20;
	TcxTextEdit *cxTextEdit18;
	TcxTextEdit *cxTextEdit23;
	TcxTextEdit *cxTextEdit25;
	TcxTextEdit *cxTextEdit27;
	TcxTextEdit *cxTextEdit28;
	TcxTextEdit *cxTextEdit30;
	TcxTextEdit *cxTextEdit32;
	TcxTextEdit *cxTextEdit33;
	TcxTextEdit *cxTextEdit35;
	TcxTextEdit *cxTextEdit37;
	TcxTextEdit *cxTextEdit38;
	TcxTextEdit *cxTextEdit39;
	TcxTextEdit *cxTextEdit40;
	TcxTextEdit *cxTextEdit41;
	TcxTextEdit *cxTextEdit42;
	TcxTextEdit *cxTextEdit43;
	TcxTextEdit *cxTextEdit44;
	TcxTextEdit *cxTextEdit45;
	TcxTextEdit *cxTextEdit46;
	TcxTextEdit *cxTextEdit47;
	TcxTextEdit *cxTextEdit48;
	TcxTextEdit *cxTextEdit52;
	TcxTextEdit *cxTextEdit53;
	TcxTextEdit *cxTextEdit54;
	TcxTextEdit *cxTextEdit55;
	TcxTextEdit *cxTextEdit56;
	TcxTextEdit *cxTextEdit57;
	TcxTextEdit *cxTextEdit51;
	TADOQuery *STADOQuery;
	TADOQuery *ADOQuery1;
	TADOQuery *ADOQuery2;
	TPanel *Panel1;
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ExitBTNClick(TObject *Sender);
	void __fastcall cxMemo1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall QueryBTNClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ExportBTNClick(TObject *Sender);
	void __fastcall PreviewBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSZHZQFrm(TComponent* Owner);

    String Beginstr;
    String Endstr;
    String BMstr;

    String XZT1str;
    String XZT2str;
    String XZT3str;
    String XZT4str;

    String YZT1str;
    String YZT2str;
    String YZT3str;
    String YZT4str;

    String ZBHL1str;
    String ZBHL2str;
    String ZBHL3str;
    String ZBHL4str;

    String KPXF1str;
    String KPXF2str;

    String DKQCK1str;
    String DKQCK2str;
    String DKQCK3str;

    String CZJCZ1str;
    String CZJCZ2str;
    String CZJCZ3str;

    String BT1str;
    String BT2str;
    String BT3str;

    String QK1str;
    String QK2str;
    String QK3str;

    String KH1str;
    String KH2str;
    String KH3str;
    String KH4str;
    String KH5str;

    String TK1str;
    String TK2str;
    String TK3str;
    String TK4str;
    String TK5str;

	String BK1str;
    String BK2str;
    String BK3str;

    String ZJ1str;
    String ZJ2str;
    String ZJ3str;
    String ZJ4str;
    String ZJ5str;
};
//---------------------------------------------------------------------------
extern PACKAGE TSZHZQFrm *SZHZQFrm;
//---------------------------------------------------------------------------
#endif
