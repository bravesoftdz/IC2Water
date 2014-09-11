//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TKQForm.h"
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
TTKQFrm *TKQFrm;
//---------------------------------------------------------------------------
__fastcall TTKQFrm::TTKQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTKQFrm::FormShow(TObject *Sender)
{
	TKExportProgressBar->Position = 0;
    TKExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    QueryBTN->Enabled = true;
    TKExitBTN->Enabled = true;
    DataGridDBTV->ClearItems();

    KHTextEdit->Text = "";
    BHTextEdit->Text = "";
    XMTextEdit->Text = "";
//    TKBeginDateEdit->Text = "";
//    TKEndDateEdit->Text = "";

	TKBeginDateEdit->Date = Date();
	TKEndDateEdit->Date = Date();

    AllTKCSTextEdit->Text = "";
    AllTKJETextEdit->Text = "";
    AllTKCBTextEdit->Text = "";

    CZYComboBox->Properties->Items->Clear();
    TKADOQuery->Close();
    TKADOQuery->SQL->Clear();
    TKADOQuery->SQL->Add("select * from SYSUSER");
    TKADOQuery->Open();
    if(!TKADOQuery->IsEmpty())
    {
        TKADOQuery->First();
        while(!TKADOQuery->Eof)
        {
        	CZYComboBox->Properties->Items->Add(TKADOQuery->FieldByName("USERNAME")->AsString.Trim());
        	TKADOQuery->Next();
        }
        CZYComboBox->Properties->Items->Add("所有系统用户");
        CZYComboBox->ItemIndex = -1;
    }
    TKADOQuery->Close();
    BMComboBox->Properties->Items->Clear();
    TKADOQuery->SQL->Clear();
    TKADOQuery->SQL->Add("select * from BUMEN");
    TKADOQuery->Open();
    if(!TKADOQuery->IsEmpty())
    {
        TKADOQuery->First();
        while(!TKADOQuery->Eof)
        {
            BMComboBox->Properties->Items->Add(TKADOQuery->FieldByName("BUMEN")->AsString.Trim());
            TKADOQuery->Next();
        }
        BMComboBox->Properties->Items->Add("所有部门");
        BMComboBox->ItemIndex = -1;
    }
    TKADOQuery->Close();

    DataGridDBTV->ClearItems();

    TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* XBCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* TKJECol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* TKCBCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* ZWCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* ZTCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* CZYCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* TKRQCol = DataGridDBTV->CreateColumn();

    KHCol->Caption = "卡号";
    KHCol->MinWidth = 90;
    KHCol->DataBinding->FieldName = "KH";
    BHCol->Caption = "编号";
    BHCol->MinWidth = 90;
    BHCol->DataBinding->FieldName = "BH";
    XMCol->Caption = "姓名";
    XMCol->MinWidth = 70;
    XMCol->DataBinding->FieldName = "XM";
    XBCol->Caption = "性别";
    XBCol->MinWidth = 40;
    XBCol->DataBinding->FieldName = "XB";
    TKJECol->Caption = "退卡金额";
    TKJECol->MinWidth = 70;
    TKJECol->DataBinding->FieldName = "TKJE";
    TKCBCol->Caption = "退卡成本";
    TKCBCol->MinWidth = 60;
    TKCBCol->DataBinding->FieldName = "TKCB";
    BMCol->Caption = "部门";
    BMCol->MinWidth = 80;
    BMCol->DataBinding->FieldName = "BM";
    ZWCol->Caption = "职务";
    ZWCol->MinWidth = 60;
    ZWCol->DataBinding->FieldName = "ZW";
    ZTCol->Caption = "状态";
    ZTCol->MinWidth = 40;
    ZTCol->DataBinding->FieldName = "ZT";
    CZYCol->Caption = "操作员";
    CZYCol->MinWidth = 60;
    CZYCol->DataBinding->FieldName = "TKOperator";
    TKRQCol->Caption = "退卡日期";
    TKRQCol->MinWidth = 140;
    TKRQCol->DataBinding->FieldName = "TKRQ";
}
//---------------------------------------------------------------------------
void __fastcall TTKQFrm::TKBeginDateEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TTKQFrm::BHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TTKQFrm::QueryBTNClick(TObject *Sender)
{
	TKExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;

	String sqlstr = "";
    String TJsqlstr = "";
	if(TKBeginDateEdit->Text.IsEmpty()&&TKEndDateEdit->Text.IsEmpty()
    	&&CZYComboBox->Text.IsEmpty()&&BMComboBox->Text.IsEmpty()
        &&KHTextEdit->Text.IsEmpty()&&BHTextEdit->Text.IsEmpty()&&XMTextEdit->Text.IsEmpty())
    {
        sqlstr = "select * from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡')";//"select * from CARD_T";
        TJsqlstr = "select SUM(CARD_T.TKJE) as alltkje,SUM(CARD_T.TKCB) as alltkcb,COUNT(*) as allcs from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡')";
        BeginStr = "";
        EndStr = "";
        KHStr = "";
        BHStr = "";
        XMStr = "";
        BMStr = "";
        CZYStr = "";
    }
    else
    {
        sqlstr = "select * from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡') and";//"select * from CARD_T where";
        TJsqlstr = "select SUM(CARD_T.TKJE) as alltkje,SUM(CARD_T.TKCB) as alltkcb,COUNT(*) as allcs from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡') and";//"select SUM(TKJE) as alltkje,SUM(TKCB) as alltkcb,COUNT(*) as allcs from CARD_T where";
        String addsqlstr = "";
        if(!TKBeginDateEdit->Text.IsEmpty())
        {
            addsqlstr = " CARD_T.TKRQ>='";
            addsqlstr += TKBeginDateEdit->Text;
            addsqlstr += " 00:00:00'";
            BeginStr = TKBeginDateEdit->Text + " 00:00:00";
        }

        if(!TKEndDateEdit->Text.IsEmpty())
        {
            if(addsqlstr.IsEmpty())
            {
                addsqlstr = " CARD_T.TKRQ<='";
                addsqlstr += TKEndDateEdit->Text;
                addsqlstr += " 23:59:59'";
            }
            else
            {
            	addsqlstr += " and TKRQ<='";
                addsqlstr += TKEndDateEdit->Text;
                addsqlstr += " 23:59:59'";
			}
			EndStr = TKEndDateEdit->Text + " 23:59:59";
        }

        if(!CZYComboBox->Text.IsEmpty())
        {
        	if(CZYComboBox->Text != "所有系统用户"&&!CZYComboBox->Text.IsEmpty())
            {
                if(addsqlstr.IsEmpty())
                {
                    addsqlstr = " CARD_T.TKOperator='";
                    addsqlstr += CZYComboBox->Text;
                    addsqlstr += "'";
                }
                else
                {
                    addsqlstr += " and CARD_T.TKOperator='";
                    addsqlstr += CZYComboBox->Text;
                    addsqlstr += "'";
                }
            }
            CZYStr = CZYComboBox->Text;
        }

        if(!BMComboBox->Text.IsEmpty())
        {
        	if(BMComboBox->Text != "所有部门"&&!BMComboBox->Text.IsEmpty())
            {
                if(addsqlstr.IsEmpty())
                {
                    addsqlstr = " CARD_T.BM='";
                    addsqlstr += BMComboBox->Text;
                    addsqlstr += "'";
                }
                else
                {
                    addsqlstr += " and CARD_T.BM='";
                    addsqlstr += BMComboBox->Text;
                    addsqlstr += "'";
                }
            }
            BMStr = BMComboBox->Text;
        }

        if(!KHTextEdit->Text.IsEmpty())
        {
            if(addsqlstr.IsEmpty())
            {
                addsqlstr = " CARD_T.KH=";
                addsqlstr += KHTextEdit->Text;
            }
            else
            {
                addsqlstr += " and CARD_T.KH=";
                addsqlstr += KHTextEdit->Text;
            }
            KHStr = KHTextEdit->Text;
        }

        if(!BHTextEdit->Text.IsEmpty())
        {
            if(addsqlstr.IsEmpty())
            {
                addsqlstr = " CARD_T.BH='";
                addsqlstr += BHTextEdit->Text;
                addsqlstr += "'";
            }
            else
            {
                addsqlstr += " and CARD_T.BH='";
                addsqlstr += BHTextEdit->Text;
                addsqlstr += "'";
            }
            BHStr = BHTextEdit->Text;
        }

        if(!XMTextEdit->Text.IsEmpty())
        {
            if(addsqlstr.IsEmpty())
            {
                addsqlstr = " CARD_T.XM='";
                addsqlstr += XMTextEdit->Text;
                addsqlstr += "'";
            }
            else
            {
                addsqlstr += " and CARD_T.XM='";
                addsqlstr += XMTextEdit->Text;
                addsqlstr += "'";
            }
            XMStr = XMTextEdit->Text;
        }

        sqlstr += addsqlstr;
        TJsqlstr += addsqlstr;
	}

    DataGridDBTV->DataController->DataSource = NULL;
    TKADOQuery->Close();
    TKADOQuery->SQL->Clear();
    TKADOQuery->SQL->Add(sqlstr);
    TKADOQuery->Open();
    if(!TKADOQuery->IsEmpty())
    {
    	if(TKADOQuery->RecordCount>65500)
        {
            TKADOQuery->Close();
            ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示，请修改查询条件!");
            return;
        }

        DataGridDBTV->DataController->DataSource = TKDataSource;

        TJADOQuery->Close();
        TJADOQuery->SQL->Clear();
        TJADOQuery->SQL->Add(TJsqlstr);
        TJADOQuery->Open();
        if(!TJADOQuery->IsEmpty())
        {
        	AllTKCSTextEdit->Text = TJADOQuery->FieldByName("allcs")->AsString + "人次";
            AllTKJETextEdit->Text = "￥" + TJADOQuery->FieldByName("alltkje")->AsString;
            AllTKCBTextEdit->Text = "￥" + TJADOQuery->FieldByName("alltkcb")->AsString;

            AllCSStr = AllTKCSTextEdit->Text;
            AllTKJEStr = AllTKJETextEdit->Text;
            AllTKCBStr = AllTKCBTextEdit->Text;
        }
        TJADOQuery->Close();

        TKExportBTN->Enabled = true;
    	PreviewBTN->Enabled = true;
    }
    else
    {
    	TKADOQuery->Close();
        ShowMessage("无符合查询条件的卡片记录!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TTKQFrm::TKExportBTNClick(TObject *Sender)
{
	if(!TKADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = TKADOQuery->SQL;
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

                TTKExportThread* EXThread = new TTKExportThread(true,
                												TKExportProgressBar,
                                                                ADOQInThread,
                                                                TKExportBTN,
                                                                PreviewBTN,
                                                                TKExitBTN,
                                                                QueryBTN,
                                                                savename,
                                                                BeginStr,
                                                                EndStr,
                                                                KHStr,
                                                                BHStr,
                                                                XMStr,
                                                                BMStr,
                                                                CZYStr,
                                                                AllCSStr,
                                                                AllTKJEStr,
                                                                AllTKCBStr);
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
void __fastcall TTKQFrm::TKExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TTKQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\TKMXPreview.fr3";
    frxTKReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxTKReport->FindObject("KHMemo"))->Text = KHStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("BHMemo"))->Text = BHStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("BMMemo"))->Text = BMStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("XMMemo"))->Text = XMStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("TKCZYM"))->Text = CZYStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("CZYMemo"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("BBSRM"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("QSSJM"))->Text = BeginStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("JZSJM"))->Text = EndStr.t_str();

    ((TfrxMemoView*)frxTKReport->FindObject("TKZCSM"))->Text = AllCSStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("TKZJEM"))->Text = AllTKJEStr.t_str();
    ((TfrxMemoView*)frxTKReport->FindObject("TKZCBM"))->Text = AllTKCBStr.t_str();


    ((TfrxMemoView*)frxTKReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxTKReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxTKReport->FindObject("XM"))->DataField = "XM";
    ((TfrxMemoView*)frxTKReport->FindObject("XB"))->DataField = "XB";
    ((TfrxMemoView*)frxTKReport->FindObject("TKJE"))->DataField = "TKJE";
    ((TfrxMemoView*)frxTKReport->FindObject("TKCB"))->DataField = "TKCB";
    ((TfrxMemoView*)frxTKReport->FindObject("BM"))->DataField = "BM";
    ((TfrxMemoView*)frxTKReport->FindObject("ZW"))->DataField = "ZW";
    ((TfrxMemoView*)frxTKReport->FindObject("ZT"))->DataField = "ZT";
    ((TfrxMemoView*)frxTKReport->FindObject("TKOperator"))->DataField = "TKOperator";
    ((TfrxMemoView*)frxTKReport->FindObject("TKRQ"))->DataField = "TKRQ";

    frxTKReport->ShowReport(true);
}
//---------------------------------------------------------------------------
