//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CZMXShowForm.h"
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
#pragma link "cxTextEdit"
#pragma resource "*.dfm"
TCZMXShowFrm *CZMXShowFrm;
//---------------------------------------------------------------------------
__fastcall TCZMXShowFrm::TCZMXShowFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCZMXShowFrm::FormShow(TObject *Sender)
{
	CZMXADOQuery->Open();
    if(!CZMXADOQuery->IsEmpty()&&CZMXADOQuery->RecordCount<=65500)
    {
    	DataGridDBTV->DataController->DataSource = CZMXDataSource;
        DataGridDBTV->ClearItems();
//        DataGridDBTV->OptionsView->ColumnAutoWidth = true;

        TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BBCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* ZBCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFFLCol = DataGridDBTV->CreateColumn();
//        TcxGridDBColumn* CKXJCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* GLFCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* CKJECol = DataGridDBTV->CreateColumn();
//        TcxGridDBColumn* LQBTCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SYCSCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFRQCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* JYNOCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* GZZIDCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFLXCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* CZYCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* LSHCol = DataGridDBTV->CreateColumn();

        KHCol->Caption = "卡号";
        KHCol->MinWidth = 90;
        KHCol->DataBinding->FieldName = "kh";
        BHCol->Caption = "编号";
        BHCol->MinWidth = 90;
        BHCol->DataBinding->FieldName = "bh";
        BMCol->Caption = "部门";
        BMCol->MinWidth = 80;
        BMCol->DataBinding->FieldName = "BUMEN";
        BBCol->Caption = "班别";
        BBCol->MinWidth = 80;
        BBCol->DataBinding->FieldName = "BANBIE";
        ZBCol->Caption = "组别";
        ZBCol->MinWidth = 80;
        ZBCol->DataBinding->FieldName = "ZUBIE";
        XMCol->Caption = "姓名";
        XMCol->MinWidth = 70;
        XMCol->DataBinding->FieldName = "NAME";
        SFYECol->Caption = "卡余额";
        SFYECol->MinWidth = 70;
        SFYECol->DataBinding->FieldName = "sf_ye";
        SFFLCol->Caption = "费率";
        SFFLCol->MinWidth = 30;
        SFFLCol->DataBinding->FieldName = "sf_fl";
        GLFCol->Caption = "管理费";
        GLFCol->MinWidth = 50;
        GLFCol->DataBinding->FieldName = "glf";
        CKJECol->Caption = "充值金额";
        CKJECol->MinWidth = 60;
        CKJECol->DataBinding->FieldName = "ckje";
        SYCSCol->Caption = "使用次数";
        SYCSCol->MinWidth = 60;
        SYCSCol->DataBinding->FieldName = "sycs";
        SFRQCol->Caption = "充值日期";
        SFRQCol->MinWidth = 140;
        SFRQCol->DataBinding->FieldName = "sfrq";
        JYNOCol->Caption = "充值机号";
        JYNOCol->MinWidth = 60;
        JYNOCol->DataBinding->FieldName = "jyno";
        GZZIDCol->Caption = "工作组ID";
        GZZIDCol->MinWidth = 60;
        GZZIDCol->DataBinding->FieldName = "gzzid";
        SFLXCol->Caption = "消费类型";
        SFLXCol->MinWidth = 60;
        SFLXCol->DataBinding->FieldName = "sflx";
        CZYCol->Caption = "操作员";
        CZYCol->MinWidth = 80;
        CZYCol->DataBinding->FieldName = "CZY";
        LSHCol->Caption = "流水号";
        LSHCol->MinWidth = 60;
        LSHCol->DataBinding->FieldName = "pkey";
    }
}
//---------------------------------------------------------------------------
void __fastcall TCZMXShowFrm::CZMXExitBTNClick(TObject *Sender)
{
	CZMXADOQuery->Close();
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TCZMXShowFrm::CZMXExportBTNClick(TObject *Sender)
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
				TCZMXExportThread* ETXThread = new TCZMXExportThread(true,
                                                                    CZMXExportProgressBar,
                                                                    ADOQInThread,
                                                                    CZMXExportBTN,
                                                                    PreviewBTN,
                                                                    CZMXExitBTN,
                                                                    savename,
                                                                    BeginDateTimeStr,
                                                                    EndDateTimeStr,
                                                                    KHStr,
                                                                    BHStr,
                                                                    AllCKTextEdit->Text,
                                                                    BMStr,
                                                                    BBStr,
                                                                    ZBStr,
                                                                    CZCZYStr,
                                                                    DKQCZTag,
                                                                    POSCZTag,
                                                                    FKCZTag,
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
void __fastcall TCZMXShowFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\CZMXPreview.fr3";
    frxCZMXReport->LoadFromFile(temppath.t_str(), true);

//    ((TfrxMemoView*)AllInfofrxReport->FindObject("FKCS"))->Text;
    ((TfrxMemoView*)frxCZMXReport->FindObject("KHMemo"))->Text = KHStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("BHMemo"))->Text = BHStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("BMMemo"))->Text = BMStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("BBMemo"))->Text = BBStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("ZBMemo"))->Text = ZBStr.t_str();

    if(DKQCZTag)
		((TfrxMemoView*)frxCZMXReport->FindObject("DKQCZMemo"))->Text = "Y";
    else
		((TfrxMemoView*)frxCZMXReport->FindObject("DKQCZMemo"))->Text = "N";

    if(POSCZTag)
		((TfrxMemoView*)frxCZMXReport->FindObject("POSJCZMemo"))->Text = "Y";
    else
		((TfrxMemoView*)frxCZMXReport->FindObject("POSJCZMemo"))->Text = "N";

    if(FKCZTag)
		((TfrxMemoView*)frxCZMXReport->FindObject("FKCZMemo"))->Text = "Y";
    else
    	((TfrxMemoView*)frxCZMXReport->FindObject("FKCZMemo"))->Text = "N";

    ((TfrxMemoView*)frxCZMXReport->FindObject("BBCZYMemo"))->Text = CZYStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("CZCZYMemo"))->Text = CZCZYStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("CZZEMemo"))->Text = "￥" + AllCKTextEdit->Text;
    ((TfrxMemoView*)frxCZMXReport->FindObject("QSRQMemo"))->Text = BeginDateTimeStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("JZRQMemo"))->Text = EndDateTimeStr.t_str();
    ((TfrxMemoView*)frxCZMXReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();


    ((TfrxMemoView*)frxCZMXReport->FindObject("BH"))->DataField = "bh";
    ((TfrxMemoView*)frxCZMXReport->FindObject("KH"))->DataField = "kh";
    ((TfrxMemoView*)frxCZMXReport->FindObject("XM"))->DataField = "NAME";
    ((TfrxMemoView*)frxCZMXReport->FindObject("BM"))->DataField = "BUMEN";
    ((TfrxMemoView*)frxCZMXReport->FindObject("BB"))->DataField = "BANBIE";
    ((TfrxMemoView*)frxCZMXReport->FindObject("ZB"))->DataField = "ZUBIE";
    ((TfrxMemoView*)frxCZMXReport->FindObject("CKJE"))->DataField = "ckje";
    ((TfrxMemoView*)frxCZMXReport->FindObject("SFYE"))->DataField = "sf_ye";
    ((TfrxMemoView*)frxCZMXReport->FindObject("SFLX"))->DataField = "sflx";
    ((TfrxMemoView*)frxCZMXReport->FindObject("JYNO"))->DataField = "jyno";
    ((TfrxMemoView*)frxCZMXReport->FindObject("CZY"))->DataField = "CZY";
    ((TfrxMemoView*)frxCZMXReport->FindObject("PKEY"))->DataField = "pkey";
    ((TfrxMemoView*)frxCZMXReport->FindObject("SFSJ"))->DataField = "sfrq";
    frxCZMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------

