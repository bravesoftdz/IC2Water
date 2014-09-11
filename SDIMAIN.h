//----------------------------------------------------------------------------
#ifndef SDIMainH
#define SDIMainH
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxNavBar.hpp"
#include "dxNavBarBase.hpp"
#include "dxNavBarCollns.hpp"

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
#include "dxSkinsdxNavBar2Painter.hpp"
#include "dxSkinsdxStatusBarPainter.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinXmas2008Blue.hpp"

#include "dxStatusBar.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>

#include <ADODB.hpp>
#include <DB.hpp>

#include "GlobalParameter.h"

//挂失现场头文件
#include "PostLostInfoThread.h"

//系统管理头文件
#include "SysConFRM.h"
#include "PosConFRM.h"
#include "cxContainer.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <jpeg.hpp>
#include "CheckWRMachFRM.h"
#include "SectionInfoMngFRM.h"
#include "ConfirmStoreData.h"

//卡片管理头文件
#include "LaunchNewCardFRM.h"
#include "BatchLaunchCardFRM.h"
#include "ReadCardFRM.h"
#include "CardRechargeFRM.h"
#include "CardWithDrawFRM.h"
#include "CardCancelFRM.h"
#include "RecordloseCardFRM.h"
#include "LostCardInfoDLFRM.h"
#include "LostInfoDLFrm.h"
#include "ReSendLostCardFRM.h"
#include "FireLostCardFRM.h"
#include "DeleteCardInfoFRM.h"
#include "DealHJLForm.h"
#include "cxContainer.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxTimeEdit.hpp"
#include <jpeg.hpp>
#include "cxImage.hpp"
#include "dxGDIPlusClasses.hpp"
#include "FixLimitTimeFrm.h"

//采集数据头文件
#include "RealTimeCollectDataFRM.h"
#include "RealCollectWithoutInBaseForm.h"
#include "BatchCollectDataFRM.h"
#include "CheckedBCFRM.h"
#include "DataToFileForm.h"

//登录窗口
#include "LoginFRM.h"
#include "FixTitleFRM.h"
#include "GoonPWFRM.h"
#include "ModeSetFrm.h"

//数据导出窗口
//#include "CommonUseReportFRM.h"
//#include "OrgInfoExportFRM.h"
#include "ChangeCardInfoFRM.h"
//#include "CardInfoExportFRM.h"
//#include "DeviceInfoExportFRM.h"
//#include "ConsumeInfoExportFRM.h"
#include "BonusInfoExportFRM.h"


//数据备份窗口
#include "BackUpDateFrm.h"

//补贴窗口
#include "MakeAssistanceFRM.h"
#include "BTDownloadForm.h"

//大钱包窗口
#include "BigWalletForm.h"

//报表统计窗口
#include "CZMXQForm.h"
#include "QKMXQForm.h"
#include "XFMXQForm.h"
#include "CARDQForm.h"
#include "CBQForm.h"
#include "CTQForm.h"
#include "JHQForm.h"
#include "BMQForm.h"
#include "KYQForm.h"
#include "TKQForm.h"
#include "GSQForm.h"
#include "EMXQForm.h"
#include "CZLForm.h"
#include "CZYJSQForm.h"
#include "SZHZQForm.h"
#include "XFTJQForm.h"
#include "PreOrderQueryForm.h"
#include "BKMXQueryForm.h"

#include "PosStatusFRM.h"
#include "DealMistakFRM.h"
#include "WaterQForm.h"
#include "BTXFMXQForm.h"
#include "FixRecordForm.h"
#include "PXFXMQery.h"
#include "StopConsumeQForm.h"

//批量挂失头文件
#include "BacthGSFRM.h"

//----------------------------------------------------------------------------
/*#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>  */
//----------------------------------------------------------------------------
class TSDIAppForm : public TForm
{
__published:
	TcxImageList *cxImageGroupList;
	TcxImageList *cxImageItemList;
	TdxStatusBar *dxStatusBar1;
	TPanel *Panel1;
	TdxNavBar *dxNavBar1;
	TdxNavBarGroup *dxNavBar1Group1;
	TdxNavBarGroup *dxNavBar1Group2;
	TdxNavBarGroup *dxNavBar1Group3;
	TdxNavBarGroup *dxNavBar1Group4;
	TdxNavBarGroup *dxNavBar1Group5;
	TdxNavBarGroup *dxNavBar1Group6;
	TdxNavBarItem *dxNavBar1Item1;
	TdxNavBarItem *dxNavBar1Item2;
	TdxNavBarItem *dxNavBar1Item5;
	TdxNavBarItem *dxNavBar1Item6;
	TdxNavBarItem *dxNavBar1Item8;
	TdxNavBarItem *dxNavBar1Item9;
	TdxNavBarItem *dxNavBar1Item10;
	TdxNavBarItem *dxNavBar1Item11;
	TdxNavBarItem *dxNavBar1Item12;
	TdxNavBarItem *dxNavBar1Item17;
	TdxNavBarItem *dxNavBar1Item18;
	TdxNavBarItem *dxNavBar1Item19;
	TdxNavBarItem *dxNavBar1Item20;
	TdxNavBarItem *dxNavBar1Item21;
	TdxNavBarItem *dxNavBar1Item22;
	TdxNavBarItem *dxNavBar1Item23;
	TdxNavBarItem *dxNavBar1Item24;
	TdxNavBarItem *dxNavBar1Item25;
	TdxNavBarItem *dxNavBar1Item26;
	TdxNavBarItem *dxNavBar1Item27;
	TdxNavBarItem *dxNavBar1Item28;
	TdxNavBarItem *dxNavBar1Item29;
	TPanel *Panel2;
	TPanel *Panel5;
	TPanel *Panel11;
	TADOConnection *ADOConnection1;
	TADOQuery *InitADOQ;
	TcxMaskEdit *cxMaskEdit1;
	TPanel *Panel3;
	TPanel *Panel4;
	TTimer *Timer1;
	TImage *Image1;
	TADOTable *GSADOT;
	TdxNavBarItem *dxNavBar1Item35;
	TdxNavBarItem *dxNavBar1Item36;
	TADOQuery *BackUpADOQ;
	TdxNavBarItem *dxNavBar1Item37;
	TdxNavBarItem *dxNavBar1Item39;
	TADOQuery *ReStoreADOQ;
	TdxNavBarItem *dxNavBar1Item40;
	TdxNavBarGroup *dxNavBar1Group8;
	TdxNavBarItem *dxNavBar1Item41;
	TdxNavBarItem *dxNavBar1Item42;
	TdxNavBarItem *dxNavBar1Item43;
	TdxNavBarItem *dxNavBar1Item44;
	TdxNavBarItem *dxNavBar1Item45;
	TdxNavBarItem *dxNavBar1Item46;
	TdxNavBarItem *dxNavBar1Item47;
	TdxNavBarItem *dxNavBar1Item48;
	TdxNavBarItem *dxNavBar1Item49;
	TdxNavBarItem *dxNavBar1Item50;
	TdxNavBarItem *dxNavBar1Item51;
	TdxNavBarItem *dxNavBar1Item52;
	TdxNavBarItem *dxNavBar1Item53;
	TdxNavBarItem *dxNavBar1Item54;
	TdxNavBarItem *dxNavBar1Item55;
	TdxNavBarItem *dxNavBar1Item56;
	TdxNavBarItem *dxNavBar1Item57;
	TADOQuery *MXTOBAKADOQ;
	TdxNavBarItem *dxNavBar1Item3;
	TADOQuery *StoreMXADOQ;
	TdxNavBarItem *dxNavBar1Item4;
	TdxNavBarItem *dxNavBar1Item7;
	TdxNavBarItem *dxNavBar1Item13;
	TdxNavBarItem *dxNavBar1Item14;
	TADOTable *UpdateZETable;
	TdxNavBarItem *dxNavBar1Item15;
	TdxNavBarItem *dxNavBar1Item16;
	TdxNavBarItem *dxNavBar1Item30;
	TdxNavBarItem *dxNavBar1Item31;
	TdxNavBarItem *dxNavBar1Item32;
	TdxNavBarItem *dxNavBar1Item33;
	TdxNavBarItem *dxNavBar1Item34;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall dxNavBar1Item1Click(TObject *Sender);
	void __fastcall dxNavBar1Item2Click(TObject *Sender);
	void __fastcall dxNavBar1Item5Click(TObject *Sender);
	void __fastcall dxNavBar1Item6Click(TObject *Sender);
	void __fastcall dxNavBar1Item8Click(TObject *Sender);
	void __fastcall dxNavBar1Item9Click(TObject *Sender);
	void __fastcall dxNavBar1Item10Click(TObject *Sender);
	void __fastcall dxNavBar1Item11Click(TObject *Sender);
	void __fastcall dxNavBar1Item12Click(TObject *Sender);
	void __fastcall dxNavBar1Item17Click(TObject *Sender);
	void __fastcall dxNavBar1Item18Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall dxNavBar1Item22Click(TObject *Sender);
	void __fastcall dxNavBar1Item23Click(TObject *Sender);
	void __fastcall dxNavBar1Item24Click(TObject *Sender);
	void __fastcall dxNavBar1Item25Click(TObject *Sender);
	void __fastcall dxNavBar1Item26Click(TObject *Sender);
	void __fastcall dxNavBar1Item27Click(TObject *Sender);
	void __fastcall dxNavBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          								int X, int Y);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall dxNavBar1Item35Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall dxNavBar1Item37Click(TObject *Sender);
	void __fastcall dxNavBar1Item19Click(TObject *Sender);
	void __fastcall dxNavBar1Item39Click(TObject *Sender);
	void __fastcall dxNavBar1Item40Click(TObject *Sender);
	void __fastcall dxNavBar1Item41Click(TObject *Sender);
	void __fastcall dxNavBar1Item42Click(TObject *Sender);
	void __fastcall dxNavBar1Item43Click(TObject *Sender);
	void __fastcall dxNavBar1Item44Click(TObject *Sender);
	void __fastcall dxNavBar1Item45Click(TObject *Sender);
	void __fastcall dxNavBar1Item46Click(TObject *Sender);
	void __fastcall dxNavBar1Item47Click(TObject *Sender);
	void __fastcall dxNavBar1Item48Click(TObject *Sender);
	void __fastcall dxNavBar1Item49Click(TObject *Sender);
	void __fastcall dxNavBar1Item50Click(TObject *Sender);
	void __fastcall dxNavBar1Item51Click(TObject *Sender);
	void __fastcall dxNavBar1Item52Click(TObject *Sender);
	void __fastcall dxNavBar1Item54Click(TObject *Sender);
	void __fastcall dxNavBar1Item55Click(TObject *Sender);
	void __fastcall dxNavBar1Item53Click(TObject *Sender);
	void __fastcall dxNavBar1Item57Click(TObject *Sender);
	void __fastcall dxNavBar1Group8Click(TObject *Sender);
	void __fastcall dxNavBar1Group1Click(TObject *Sender);
	void __fastcall dxNavBar1Group2Click(TObject *Sender);
	void __fastcall dxNavBar1Group6Click(TObject *Sender);
	void __fastcall dxNavBar1Group5Click(TObject *Sender);
	void __fastcall dxNavBar1Group3Click(TObject *Sender);
	void __fastcall dxNavBar1Group4Click(TObject *Sender);
	void __fastcall Panel3DblClick(TObject *Sender);
	void __fastcall dxNavBar1Item3Click(TObject *Sender);
	void __fastcall dxNavBar1Item4Click(TObject *Sender);
	void __fastcall dxNavBar1Item7Click(TObject *Sender);
	void __fastcall dxNavBar1Item13Click(TObject *Sender);
	void __fastcall dxNavBar1Item14Click(TObject *Sender);
	void __fastcall ShowStatus();
	void __fastcall dxNavBar1Item36Click(TObject *Sender);
	void __fastcall dxNavBar1Item28Click(TObject *Sender);
	void __fastcall dxNavBar1Item15Click(TObject *Sender);
	void __fastcall dxNavBar1Item16Click(TObject *Sender);
	void __fastcall dxNavBar1Item30Click(TObject *Sender);
	void __fastcall dxNavBar1Item31Click(TObject *Sender);
	void __fastcall dxNavBar1Item32Click(TObject *Sender);
	void __fastcall dxNavBar1Item33Click(TObject *Sender);
	void __fastcall dxNavBar1Item34Click(TObject *Sender);
//	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
private:
	TPostLostInfoThread* PostLostInfoThead;
public:
    virtual __fastcall TSDIAppForm(TComponent *AOwner);
};
//----------------------------------------------------------------------------
extern TSDIAppForm *SDIAppForm;
//----------------------------------------------------------------------------
#endif
