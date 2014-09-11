//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QKMXShowForm.h"
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
TQKMXShowFrm *QKMXShowFrm;
//---------------------------------------------------------------------------
__fastcall TQKMXShowFrm::TQKMXShowFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQKMXShowFrm::QKMXExitBTNClick(TObject *Sender)
{
	QKMXADOQuery->Close();
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TQKMXShowFrm::QKMXExportBTNClick(TObject *Sender)
{
	if(!QKMXADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = QKMXADOQuery->SQL;
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
                TQKMXExportThread* ETXThread = new TQKMXExportThread(true,
                                                                     QKMXExportProgressBar,
                                                                     ADOQInThread,
                                                                     QKMXExportBTN,
                                                                     PreviewBTN,
                                                                     QKMXExitBTN,
                                                                     savename,
                                                                     BeginDateTimeStr,
                                                                     EndDateTimeStr,
                                                                     KHStr,
                                                                     BHStr,
																	 AllQKTextEdit->Text,
																	 AllQCSTextEdit->Text,
                                                                     BMStr,
                                                                     BBStr,
                                                                     ZBStr,
                                                                     QKCZYStr,
                                                                     DKQQKTag,
                                                                     TKQKTag,
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
void __fastcall TQKMXShowFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\QKMXPreview.fr3";
    frxQKMXReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxQKMXReport->FindObject("KHMemo"))->Text = KHStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("BHMemo"))->Text = BHStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("BMMemo"))->Text = BMStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("BBMemo"))->Text = BBStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("ZBMemo"))->Text = ZBStr.t_str();

    if(DKQQKTag)
    	((TfrxMemoView*)frxQKMXReport->FindObject("DKQQKMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxQKMXReport->FindObject("DKQQKMemo"))->Text = "N";

    if(TKQKTag)
        ((TfrxMemoView*)frxQKMXReport->FindObject("TKQKMemo"))->Text = "Y";
    else
    	((TfrxMemoView*)frxQKMXReport->FindObject("TKQKMemo"))->Text = "N";

	((TfrxMemoView*)frxQKMXReport->FindObject("QKZEMemo"))->Text = "￥" + AllQKTextEdit->Text;
	((TfrxMemoView*)frxQKMXReport->FindObject("QKZCSMemo"))->Text = AllQCSTextEdit->Text.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("BBCZYMemo"))->Text = CZYStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("QKCZYMemo"))->Text = QKCZYStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("QSRQMemo"))->Text = BeginDateTimeStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("JZRQMemo"))->Text = EndDateTimeStr.t_str();
    ((TfrxMemoView*)frxQKMXReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();

    ((TfrxMemoView*)frxQKMXReport->FindObject("BH"))->DataField = "bh";
    ((TfrxMemoView*)frxQKMXReport->FindObject("KH"))->DataField = "kh";
    ((TfrxMemoView*)frxQKMXReport->FindObject("XM"))->DataField = "NAME";
    ((TfrxMemoView*)frxQKMXReport->FindObject("BM"))->DataField = "BUMEN";
    ((TfrxMemoView*)frxQKMXReport->FindObject("BB"))->DataField = "BANBIE";
    ((TfrxMemoView*)frxQKMXReport->FindObject("ZB"))->DataField = "ZUBIE";
    ((TfrxMemoView*)frxQKMXReport->FindObject("CKJE"))->DataField = "ckje";
    ((TfrxMemoView*)frxQKMXReport->FindObject("SFYE"))->DataField = "sf_ye";
    ((TfrxMemoView*)frxQKMXReport->FindObject("SFLX"))->DataField = "sflx";
    ((TfrxMemoView*)frxQKMXReport->FindObject("JYNO"))->DataField = "jyno";
    ((TfrxMemoView*)frxQKMXReport->FindObject("CZY"))->DataField = "CZY";
    ((TfrxMemoView*)frxQKMXReport->FindObject("PKEY"))->DataField = "pkey";
    ((TfrxMemoView*)frxQKMXReport->FindObject("SFSJ"))->DataField = "sfrq";
    frxQKMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------
void __fastcall TQKMXShowFrm::FormShow(TObject *Sender)
{
	QKMXADOQuery->Open();
    if(!QKMXADOQuery->IsEmpty()&&QKMXADOQuery->RecordCount<=65500)
    {
    	DataGridDBTV->DataController->DataSource = QKMXDataSource;
        DataGridDBTV->ClearItems();

        TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFFLCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* GLFCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* CKJECol = DataGridDBTV->CreateColumn();
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
        CKJECol->Caption = "取款金额";
        CKJECol->MinWidth = 60;
        CKJECol->DataBinding->FieldName = "ckje";
        SYCSCol->Caption = "使用次数";
        SYCSCol->MinWidth = 60;
        SYCSCol->DataBinding->FieldName = "sycs";
        SFRQCol->Caption = "取款日期";
        SFRQCol->MinWidth = 140;
        SFRQCol->DataBinding->FieldName = "sfrq";
        JYNOCol->Caption = "取款机号";
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
void __fastcall TQKMXShowFrm::AllQKTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
	Key = 0;
}
//---------------------------------------------------------------------------

