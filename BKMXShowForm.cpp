//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BKMXShowForm.h"
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
TBKMXShowFrm *BKMXShowFrm;
//---------------------------------------------------------------------------
__fastcall TBKMXShowFrm::TBKMXShowFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBKMXShowFrm::FormShow(TObject *Sender)
{
	CZMXADOQuery->Open();
    if(!CZMXADOQuery->IsEmpty()&&CZMXADOQuery->RecordCount<=65500)
    {
    	DataGridDBTV->DataController->DataSource = CZMXDataSource;
        DataGridDBTV->ClearItems();
        DataGridDBTV->OptionsView->ColumnAutoWidth = true;

        TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFLXCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* CZYCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* DTCol = DataGridDBTV->CreateColumn();

        KHCol->Caption = "卡号";
        KHCol->MinWidth = 90;
        KHCol->DataBinding->FieldName = "kh";
        BHCol->Caption = "编号";
        BHCol->MinWidth = 90;
        BHCol->DataBinding->FieldName = "bh";
        BMCol->Caption = "部门";
        BMCol->MinWidth = 180;
        BMCol->DataBinding->FieldName = "BUMEN";
        XMCol->Caption = "姓名";
        XMCol->MinWidth = 70;
        XMCol->DataBinding->FieldName = "NAME";
        SFYECol->Caption = "卡余额";
        SFYECol->MinWidth = 70;
        SFYECol->DataBinding->FieldName = "YE";
        SFLXCol->Caption = "操作类型";
        SFLXCol->MinWidth = 60;
        SFLXCol->DataBinding->FieldName = "LX";
        CZYCol->Caption = "操作员";
        CZYCol->MinWidth = 80;
        CZYCol->DataBinding->FieldName = "Operator";
        DTCol->Caption = "操作日期";
        DTCol->MinWidth = 100;
        DTCol->DataBinding->FieldName = "DateTime";
    }
}
//---------------------------------------------------------------------------
void __fastcall TBKMXShowFrm::CZMXExportBTNClick(TObject *Sender)
{
	if(!CZMXADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = CZMXADOQuery->SQL;
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
				TBKMXExportThread* ETXThread = new TBKMXExportThread(true,
                                                                    CZMXExportProgressBar,
                                                                    ADOQInThread,
                                                                    CZMXExportBTN,
                                                                    PreviewBTN,
                                                                    CZMXExitBTN,
                                                                    savename,
                                                                    BeginDateTimeStr,
                                                                    EndDateTimeStr,
                                                                    CZCZYStr,
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

void __fastcall TBKMXShowFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\BKMXPreview.fr3";
    frxCZMXReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxCZMXReport->FindObject("BBCZYMemo"))->Text = CZYStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("CZCZYMemo"))->Text = CZCZYStr.t_str();
   ((TfrxMemoView*)frxCZMXReport->FindObject("QSRQMemo"))->Text = BeginDateTimeStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("JZRQMemo"))->Text = EndDateTimeStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();


    ((TfrxMemoView*)frxCZMXReport->FindObject("BH"))->DataField = "bh";
    ((TfrxMemoView*)frxCZMXReport->FindObject("KH"))->DataField = "kh";
    ((TfrxMemoView*)frxCZMXReport->FindObject("XM"))->DataField = "NAME";
    ((TfrxMemoView*)frxCZMXReport->FindObject("BM"))->DataField = "BUMEN";
    ((TfrxMemoView*)frxCZMXReport->FindObject("SFYE"))->DataField = "YE";
    ((TfrxMemoView*)frxCZMXReport->FindObject("SFLX"))->DataField = "LX";
    ((TfrxMemoView*)frxCZMXReport->FindObject("CZY"))->DataField = "Operator";
    ((TfrxMemoView*)frxCZMXReport->FindObject("SFSJ"))->DataField = "DateTime";
    frxCZMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------

void __fastcall TBKMXShowFrm::CZMXExitBTNClick(TObject *Sender)
{
	CZMXADOQuery->Close();
    this->Close();
}
//---------------------------------------------------------------------------
