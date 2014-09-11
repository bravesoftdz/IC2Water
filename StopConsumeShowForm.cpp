//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopConsumeShowForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxProgressBar"
#pragma link "cxStyles"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinscxPCPainter"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinValentine"
#pragma link "dxSkinXmas2008Blue"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TStopConsumeShowFRM *StopConsumeShowFRM;
//---------------------------------------------------------------------------
__fastcall TStopConsumeShowFRM::TStopConsumeShowFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStopConsumeShowFRM::FormShow(TObject *Sender)
{
	CARDADOQuery->Open();
    if(!CARDADOQuery->IsEmpty()&&CARDADOQuery->RecordCount<=65500)
    {
    	DataGridDBTV->DataController->DataSource = CARDDataSource;
        DataGridDBTV->ClearItems();

        TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* XBCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BZCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* ZBCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* ZWCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* ZTCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* FKRQCol = DataGridDBTV->CreateColumn();

        KHCol->Caption = "卡号";
        KHCol->MinWidth = 90;
        KHCol->DataBinding->FieldName = "KH";
        BHCol->Caption = "编号";
        BHCol->MinWidth = 90;
        BHCol->DataBinding->FieldName = "BH";
        XMCol->Caption = "姓名";
        XMCol->MinWidth = 70;
        XMCol->DataBinding->FieldName = "XM";
        SFYECol->Caption = "卡余额";
        SFYECol->MinWidth = 70;
        SFYECol->DataBinding->FieldName = "SF_YE";
        XBCol->Caption = "性别";
        XBCol->MinWidth = 40;
        XBCol->DataBinding->FieldName = "XB";
        BMCol->Caption = "部门";
        BMCol->MinWidth = 80;
        BMCol->DataBinding->FieldName = "BM";
        BZCol->Caption = "班别";
        BZCol->MinWidth = 100;
        BZCol->DataBinding->FieldName = "BZ";
        ZBCol->Caption = "组别";
        ZBCol->MinWidth = 60;
        ZBCol->DataBinding->FieldName = "ZB";
        ZWCol->Caption = "职务";
        ZWCol->MinWidth = 60;
        ZWCol->DataBinding->FieldName = "ZW";
        ZTCol->Caption = "状态";
        ZTCol->MinWidth = 40;
        ZTCol->DataBinding->FieldName = "ZT";
        FKRQCol->Caption = "发卡日期";
        FKRQCol->MinWidth = 140;
        FKRQCol->DataBinding->FieldName = "RQ";
    }
}
//---------------------------------------------------------------------------

void __fastcall TStopConsumeShowFRM::CARDExitBTNClick(TObject *Sender)
{
	CARDADOQuery->Close();
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStopConsumeShowFRM::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\STPreview.fr3";
    frxCARDReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxCARDReport->FindObject("CZYMemo"))->Text = CZYStr.t_str();
    ((TfrxMemoView*)frxCARDReport->FindObject("SCRQMemo"))->Text = checktagstr.t_str();

    ((TfrxMemoView*)frxCARDReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxCARDReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxCARDReport->FindObject("XM"))->DataField = "XM";
    ((TfrxMemoView*)frxCARDReport->FindObject("BM"))->DataField = "BM";
    ((TfrxMemoView*)frxCARDReport->FindObject("SFYE"))->DataField = "SF_YE";
    ((TfrxMemoView*)frxCARDReport->FindObject("XB"))->DataField = "XB";
    ((TfrxMemoView*)frxCARDReport->FindObject("BZ"))->DataField = "BZ";
    ((TfrxMemoView*)frxCARDReport->FindObject("ZB"))->DataField = "ZB";
    ((TfrxMemoView*)frxCARDReport->FindObject("ZT"))->DataField = "ZT";
    ((TfrxMemoView*)frxCARDReport->FindObject("ZW"))->DataField = "ZW";
    ((TfrxMemoView*)frxCARDReport->FindObject("RQ"))->DataField = "RQ";

    frxCARDReport->ShowReport(true);
}
//---------------------------------------------------------------------------
void __fastcall TStopConsumeShowFRM::CARDExportBTNClick(TObject *Sender)
{
	if(!CARDADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = CARDADOQuery->SQL;
		if(SaveDialog->Execute())
		{
			if(FileExists(SaveDialog->FileName+".xls"))
			{
				throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
                return;
			}
			else
			{
				String savename = SaveDialog->FileName;
				savename += ".xls";

                TStopConsumeExportThread* ETXThread = new TStopConsumeExportThread(true,
                													 XFMXExportProgressBar,
                                                                     ADOQInThread,
                                                                     CARDExportBTN,
                                                                     PreviewBTN,
                                                                     CARDExitBTN,
                                                                     savename,
                                                                     checktagstr,
                                                                     CZYStr);
                if(ETXThread)
                {
                    ETXThread->Resume();
                }
            }
        }
    }
	else
	{
		MessageBox(this->Handle, "没有可导出信息！", "No Record Error!", MB_OK|MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------
