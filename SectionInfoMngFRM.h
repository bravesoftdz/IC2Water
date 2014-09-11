//---------------------------------------------------------------------------

#ifndef SectionInfoMngFRMH
#define SectionInfoMngFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
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
#include "cxButtons.hpp"
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ADODB.hpp>
#include "cxContainer.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxDBEdit.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "QXFPFRM.h"

//#include "SectionInfoFixFRM.h"
#include "GlobalParameter.h"

//---------------------------------------------------------------------------
class TSectionInfoManageFRM : public TForm
{
__published:	// IDE-managed Components
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet4;
	TcxTabSheet *cxTabSheet5;
	TPanel *Panel1;
	TcxButton *SectionInfoFixBTN;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TcxButton *cxButton10;
	TcxButton *cxButton11;
	TcxButton *cxButton12;
	TPanel *Panel3;
	TcxButton *cxButton13;
	TcxButton *cxButton16;
	TcxButton *cxButton17;
	TcxButton *cxButton18;
	TPanel *Panel4;
	TcxButton *cxButton19;
	TcxButton *cxButton22;
	TcxButton *cxButton23;
	TcxButton *cxButton24;
	TPanel *Panel5;
	TcxButton *cxButton25;
	TcxButton *cxButton28;
	TcxButton *cxButton29;
	TcxButton *cxButton30;
	TcxGridDBTableView *SectionInfoGridTV;
	TcxGridLevel *SectionInfoGridLL;
	TcxGrid *SectionInfoGrid;
	TDataSource *SectionInfoDS;
	TADOTable *SectionInfoADOT;
	TcxGridDBColumn *SectionInfoGridTVDM;
	TcxGridDBColumn *SectionInfoGridTVBUMEN;
	TcxStyleRepository *SectionInfoSR;
	TcxGridTableViewStyleSheet *GridTableViewStyleSheetDevExpress;
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
	TcxGridDBTableView *SubSectionInfoGridTV;
	TcxGridLevel *SubSectionInfoGridLL;
	TcxGrid *SubSectionInfoGrid;
	TDataSource *SubSectionInfoDS;
	TcxGroupBox *cxGroupBox1;
	TcxComboBox *SectionNameComboBox;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TADOQuery *SubSectionInfoADOQ;
	TcxGridDBColumn *SubSectionInfoGridTVNUMCol;
	TcxGridDBColumn *SubSectionInfoGridTVSNameCol;
	TcxGridDBColumn *SubSectionInfoGridTVBnameCol;
	TcxDBTextEdit *ClassNameDBTextEdit;
	TcxGroupBox *cxGroupBox2;
	TcxLabel *cxLabel3;
	TcxComboBox *SectionNameComboBox1;
	TcxLabel *cxLabel4;
	TcxComboBox *ClassNameComboBox;
	TDataSource *GroupInfoDS;
	TADOQuery *GroupInfoADOQ;
	TcxGridDBTableView *GroupInfoGridTV;
	TcxGridLevel *GroupInfoGridLL;
	TcxGrid *GroupInfoGrid;
	TcxGridDBColumn *GroupInfoGridTVNumCol;
	TcxGridDBColumn *GroupInfoGridTVSNameCol;
	TcxGridDBColumn *GroupInfoGridTVCNameCol;
	TcxGridDBColumn *GroupInfoGridTVGNameCol;
	TcxLabel *cxLabel5;
	TcxDBTextEdit *GroupNameDBTextEdit;
	TcxTextEdit *cxTextEdit1;
	TLabel *Label1;
	TLabel *Label2;
	TcxTextEdit *cxTextEdit3;
	TLabel *Label3;
	TLabel *Label4;
	TcxDBTextEdit *cxDBTextEdit1;
	TcxDBTextEdit *cxDBTextEdit2;
	TLabel *Label5;
	TLabel *Label6;
	TcxTextEdit *cxTextEdit2;
	TcxDBTextEdit *cxDBTextEdit3;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGridDBTableView1;
	TcxGridDBColumn *cxGridDBColumn1;
	TcxGridDBColumn *cxGridDBColumn2;
	TcxGridLevel *cxGridLevel1;
	TDataSource *SFDS;
	TDataSource *STDS;
	TADOTable *SFADOT;
	TcxTextEdit *cxTextEdit4;
	TLabel *Label7;
	TLabel *Label8;
	TcxDBTextEdit *cxDBTextEdit4;
	TcxGrid *cxGrid2;
	TcxGridDBTableView *cxGridDBTableView2;
	TcxGridDBColumn *cxGridDBColumn3;
	TcxGridDBColumn *cxGridDBColumn4;
	TcxGridLevel *cxGridLevel2;
	TADOTable *STADOT;
	TcxTextEdit *cxTextEdit5;
	TLabel *Label9;
	TLabel *Label10;
	TcxDBTextEdit *cxDBTextEdit5;
	TcxTabSheet *cxTabSheet6;
	TcxGrid *cxGrid3;
	TcxGridDBTableView *cxGridDBTableView3;
	TcxGridDBColumn *cxGridDBColumn5;
	TcxGridDBColumn *cxGridDBColumn6;
	TcxGridLevel *cxGridLevel3;
	TPanel *Panel2;
	TLabel *Label11;
	TLabel *Label12;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton5;
	TcxButton *cxButton8;
	TcxTextEdit *cxTextEdit6;
	TcxDBTextEdit *cxDBTextEdit6;
	TADOTable *USERADOT;
	TDataSource *USERDS;
	TcxGridDBColumn *cxGridDBTableView3Column1;
	TcxGridDBColumn *cxGridDBTableView3Column2;
	TcxGridDBColumn *cxGridDBTableView3Column3;
	TLabel *Label13;
	TcxComboBox *cxComboBox1;
	TADOQuery *USERADOQ;
	TcxTextEdit *cxTextEdit7;
	TLabel *Label14;
	TcxTextEdit *cxTextEdit8;
	TcxTextEdit *cxTextEdit9;
	TcxTextEdit *cxTextEdit10;
	TcxTextEdit *cxTextEdit11;
	TcxTextEdit *cxTextEdit12;
	TcxTextEdit *cxTextEdit13;
	TcxTextEdit *cxTextEdit14;
	TLabel *Label15;
	TcxButton *cxButton9;
	void __fastcall e(TObject *Sender);
	void __fastcall SectionNameComboBox1PropertiesChange(TObject *Sender);
	void __fastcall ClassNameComboBoxPropertiesChange(TObject *Sender);
	void __fastcall SectionInfoFixBTNClick(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton10Click(TObject *Sender);
	void __fastcall cxButton12Click(TObject *Sender);
	void __fastcall cxButton11Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton16Click(TObject *Sender);
	void __fastcall cxButton13Click(TObject *Sender);
	void __fastcall cxButton17Click(TObject *Sender);
	void __fastcall cxButton18Click(TObject *Sender);
	void __fastcall cxButton22Click(TObject *Sender);
	void __fastcall cxButton19Click(TObject *Sender);
	void __fastcall cxButton23Click(TObject *Sender);
	void __fastcall cxButton24Click(TObject *Sender);
	void __fastcall cxButton28Click(TObject *Sender);
	void __fastcall cxButton25Click(TObject *Sender);
	void __fastcall cxButton29Click(TObject *Sender);
	void __fastcall cxButton30Click(TObject *Sender);
	void __fastcall cxPageControl1Click(TObject *Sender);
	void __fastcall cxTabSheet4Show(TObject *Sender);
	void __fastcall cxTabSheet1Show(TObject *Sender);
	void __fastcall cxTabSheet6Show(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTabSheet5Show(TObject *Sender);
	void __fastcall cxDBTextEdit1PropertiesChange(TObject *Sender);
	void __fastcall cxDBTextEdit2PropertiesChange(TObject *Sender);
	void __fastcall cxDBTextEdit3PropertiesChange(TObject *Sender);
	void __fastcall cxDBTextEdit4PropertiesChange(TObject *Sender);
	void __fastcall cxDBTextEdit5PropertiesChange(TObject *Sender);
	void __fastcall cxDBTextEdit6PropertiesChange(TObject *Sender);
	void __fastcall cxTextEdit7KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxComboBox1Enter(TObject *Sender);
	void __fastcall cxComboBox1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TSectionInfoManageFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSectionInfoManageFRM *SectionInfoManageFRM;
//---------------------------------------------------------------------------
#endif
