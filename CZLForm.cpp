//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CZLForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDropDownEdit"
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
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxProgressBar"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
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
TCZLQFrm *CZLQFrm;
//---------------------------------------------------------------------------
__fastcall TCZLQFrm::TCZLQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCZLQFrm::CZLExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCZLQFrm::FormShow(TObject *Sender)
{
	CZLExportProgressBar->Position = 0;
    QueryBTN->Enabled = true;
    CZLExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    CZLExitBTN->Enabled = true;
    DataGridDBTV->ClearItems();
    CZLADOQuery->Close();
//    CZLBeginDateEdit->Text = "";
//    CZLEndDateEdit->Text = "";
	CZLBeginDateEdit->Date = Date();
    CZLEndDateEdit->Date = Date();
    USERComboBox->Properties->Items->Clear();
    CZLADOQuery->Close();
    CZLADOQuery->SQL->Clear();
    CZLADOQuery->SQL->Add("select * from SYSUSER");
    CZLADOQuery->Open();
    if(!CZLADOQuery->IsEmpty())
    {
        CZLADOQuery->First();
        while(!CZLADOQuery->Eof)
        {
        	USERComboBox->Properties->Items->Add(CZLADOQuery->FieldByName("USERNAME")->AsString.Trim());
        	CZLADOQuery->Next();
        }
        USERComboBox->Properties->Items->Add("所有系统用户");
        USERComboBox->ItemIndex = -1;
    }
    CZLADOQuery->Close();

/*    TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* JECol = DataGridDBTV->CreateColumn();
	TcxGridDBColumn* YECol = DataGridDBTV->CreateColumn();  */
	TcxGridDBColumn* OperatorCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* LXCol = DataGridDBTV->CreateColumn();

    TcxGridDBColumn* DateTimeCol = DataGridDBTV->CreateColumn();


/*    KHCol->Caption = "卡号";
    KHCol->MinWidth = 90;
    KHCol->DataBinding->FieldName = "KH";
    BHCol->Caption = "编号";
    BHCol->MinWidth = 90;
    BHCol->DataBinding->FieldName = "BH";
    JECol->Caption = "金额";
    JECol->MinWidth = 70;
    JECol->DataBinding->FieldName = "JE";
    YECol->Caption = "卡余额";
    YECol->MinWidth = 70;
	YECol->DataBinding->FieldName = "YE";   */
    LXCol->Caption = "操作类型";
    LXCol->MinWidth = 120;
    LXCol->DataBinding->FieldName = "LX";
    OperatorCol->Caption = "操作员";
    OperatorCol->MinWidth = 90;
    OperatorCol->DataBinding->FieldName = "Operator";
    DateTimeCol->Caption = "操作时间";
    DateTimeCol->MinWidth = 160;
    DateTimeCol->DataBinding->FieldName = "DateTime";
}
//---------------------------------------------------------------------------
void __fastcall TCZLQFrm::QueryBTNClick(TObject *Sender)
{
	if(!CZLBeginDateEdit->Text.IsEmpty()&&!CZLEndDateEdit->Text.IsEmpty())
    {
        CZLExportBTN->Enabled = false;
        PreviewBTN->Enabled = false;
    	String sqlstr = "select * from OperationList where DateTime<='";
        sqlstr += CZLEndDateEdit->Text;
        sqlstr += " 23:59:59' and DateTime>='";
        sqlstr += CZLBeginDateEdit->Text;
        sqlstr += " 00:00:00'";
    	if(!USERComboBox->Text.IsEmpty())
        {
            if(USERComboBox->Text != "所有系统用户"&&!USERComboBox->Text.IsEmpty())
            {
            	sqlstr += " and Operator='";
                sqlstr += USERComboBox->Text;
                sqlstr += "'";
            }
        }

        DataGridDBTV->DataController->DataSource = NULL;
        CZLADOQuery->Close();
        CZLADOQuery->SQL->Clear();
        CZLADOQuery->SQL->Add(sqlstr);
        CZLADOQuery->Open();
        if(!CZLADOQuery->IsEmpty())
    	{
            if(CZLADOQuery->RecordCount>65500)
            {
                CZLADOQuery->Close();
                ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示，请修改查询条件!");
                return;
            }

            BeginStr = CZLBeginDateEdit->Text + " 00:00:00";
            EndStr = CZLEndDateEdit->Text + " 23:59:59";
            USERStr = USERComboBox->Text;
            CZYStr = OperatorName;
            DataGridDBTV->DataController->DataSource = CZLDataSource;
            CZLExportBTN->Enabled = true;
    		PreviewBTN->Enabled = true;
        }
        else
        {
            CZLADOQuery->Close();
            ShowMessage("无符合查询条件的卡片记录!");
        }
    }
    else
    	ShowMessage("必须填写查询起始于截至日期!");
}
//---------------------------------------------------------------------------
void __fastcall TCZLQFrm::CZLExportBTNClick(TObject *Sender)
{
	if(!CZLADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = CZLADOQuery->SQL;
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
                TCZLExportThread* EXThread = new TCZLExportThread(true,
                												  CZLExportProgressBar,
                                                                  ADOQInThread,
                                                                  CZLExportBTN,
                                                                  PreviewBTN,
                                                                  CZLExitBTN,
                                                                  QueryBTN,
                                                                  savename,
                                                                  BeginStr,
                                                                  EndStr,
                                                                  USERStr);
                if(EXThread)
                {
                    EXThread->Resume();
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
void __fastcall TCZLQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\CZLMXPreview.fr3";
    frxCZLReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxCZLReport->FindObject("USERM"))->Text = USERStr.t_str();
    ((TfrxMemoView*)frxCZLReport->FindObject("BBCZYM"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxCZLReport->FindObject("SCRQM"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxCZLReport->FindObject("QSRQM"))->Text = BeginStr.t_str();
    ((TfrxMemoView*)frxCZLReport->FindObject("JZRQM"))->Text = EndStr.t_str();

/*    ((TfrxMemoView*)frxCZLReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxCZLReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxCZLReport->FindObject("JE"))->DataField = "JE";
	((TfrxMemoView*)frxCZLReport->FindObject("YE"))->DataField = "YE";   */
    ((TfrxMemoView*)frxCZLReport->FindObject("LX"))->DataField = "LX";
    ((TfrxMemoView*)frxCZLReport->FindObject("Operator"))->DataField = "Operator";
    ((TfrxMemoView*)frxCZLReport->FindObject("DateTime"))->DataField = "DateTime";

    frxCZLReport->ShowReport(true);
}
//---------------------------------------------------------------------------
