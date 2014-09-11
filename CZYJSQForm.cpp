//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CZYJSQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
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
TCZYJSQFrm *CZYJSQFrm;
//---------------------------------------------------------------------------
__fastcall TCZYJSQFrm::TCZYJSQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCZYJSQFrm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TCZYJSQFrm::ExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCZYJSQFrm::FormShow(TObject *Sender)
{
	QueryBTN->Enabled = true;
    ExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    ExitBTN->Enabled = true;

    ACBstr = "0";
    ICBstr = "0";
    DCBstr = "0";
    CZCSstr = "0";
    CCBstr = "0";
    CZEstr = "0";
    QCBstr = "0";

	cxTextEdit1->Text = "";
    cxTextEdit2->Text = "";
    cxTextEdit3->Text = "";
    cxTextEdit4->Text = "";
    cxTextEdit5->Text = "";
    cxTextEdit6->Text = "";
    cxTextEdit7->Text = "";
    cxTextEdit8->Text = "";
    cxTextEdit9->Text = "";
    cxTextEdit10->Text = "";
    cxTextEdit11->Text = "";
    cxTextEdit12->Text = "";
    cxTextEdit13->Text = "";
    cxTextEdit14->Text = "";
    cxTextEdit15->Text = "";
    cxTextEdit16->Text = "";
    cxTextEdit17->Text = "";
    cxTextEdit18->Text = "";
    cxTextEdit19->Text = "";
    cxTextEdit20->Text = "";
    cxTextEdit21->Text = "";
    cxTextEdit22->Text = "";
    cxTextEdit23->Text = "";
    cxTextEdit24->Text = "";
    cxTextEdit25->Text = "";
    cxTextEdit26->Text = "";
    cxTextEdit27->Text = "";
    cxTextEdit28->Text = "";
    cxTextEdit29->Text = "";
    cxTextEdit30->Text = "";

//    JSBeginDateEdit->Text = "";
//    JSEndDateEdit->Text = "";
	JSBeginDateEdit->Date = Date();
	JSEndDateEdit->Date = Date();

	USERComboBox->Text = "";
    USERComboBox->Properties->Items->Clear();
    JSADOQuery->Close();
    JSADOQuery->Close();
    JSADOQuery->SQL->Clear();
    JSADOQuery->SQL->Add("select * from SYSUSER");
    JSADOQuery->Open();
    if(!JSADOQuery->IsEmpty())
    {
        JSADOQuery->First();
        while(!JSADOQuery->Eof)
        {
        	USERComboBox->Properties->Items->Add(JSADOQuery->FieldByName("USERNAME")->AsString.Trim());
        	JSADOQuery->Next();
        }
        USERComboBox->Properties->Items->Add("所有系统用户");
        USERComboBox->ItemIndex = -1;
    }
    JSADOQuery->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCZYJSQFrm::QueryBTNClick(TObject *Sender)
{
	if(JSBeginDateEdit->Text.IsEmpty()||JSEndDateEdit->Text.IsEmpty())
    {
        ShowMessage("必须完整填写查询信息!");
        return;
    }

    QSSJstr = JSBeginDateEdit->Text + " 00:00:00";
    JZSJstr = JSEndDateEdit->Text + " 23:59:59";
    QCZYstr = USERComboBox->Text;

//    String sqlstr = "select SUM(case when SFLX='K' then SF_YE else 0 end) as KZE,SUM(case when SFLX='W' then SF_YE else 0 end) as KCB,SUM(case when SFLX='K' then 1 else 0 end) as KZCS,SUM(case when SFLX='a' then SFJE else 0 end) as AZE,SUM(case when SFLX='a' then 1 else 0 end) as AZCS,SUM(case when SFLX='I' then SFJE else 0 end) as IZE,SUM(case when SFLX='I' then 1 else 0 end) as IZCS,SUM(case when SFLX='F' then SF_YE else 0 end) as GZE,SUM(case when SFLX='G' then SFJE else 0 end) as GCB,SUM(case when SFLX='G' then 1 else 0 end) as GZCS,SUM(case when SFLX='D' then SFJE else 0 end) as DZE,SUM(case when SFLX='D' then 1 else 0 end) as DZCS from MXBAK where SFRQ>='";
	String sqlstr = "select SUM(case when SFLX='K' then MXBAK.SF_YE else 0 end) as KZE,SUM(case when SFLX='W' then MXBAK.SF_YE else 0 end) as KCB,SUM(case when SFLX='K' then 1 else 0 end) as KZCS,SUM(case when SFLX='a' then MXBAK.SFJE else 0 end) as AZE,SUM(case when SFLX='a' then 1 else 0 end) as AZCS,SUM(case when SFLX='I' then MXBAK.SFJE else 0 end) as IZE,SUM(case when SFLX='I' then 1 else 0 end) as IZCS,SUM(case when SFLX='F' then MXBAK.SF_YE else 0 end) as GZE,SUM(case when SFLX='G' then MXBAK.SFJE else 0 end) as GCB,SUM(case when SFLX='G' then 1 else 0 end) as GZCS,SUM(case when SFLX='D' then -MXBAK.SFJE else 0 end) as DZE,SUM(case when SFLX='D' then 1 else 0 end) as DZCS from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFRQ>='";

	sqlstr += QSSJstr;
    sqlstr += "' and SFRQ<='";
    sqlstr += JZSJstr;
    sqlstr += "'";

//    String TKsqlstr = "select SUM(case when YW=1 then 1 else 0 end) as TZCS,SUM(case when YW=1 then TKJE else 0 end) as TZE,SUM(case when YW=1 then TKCB else 0 end) as RZE,SUM(case when YW=0 then 1 else 0 end) as QZCS,SUM(case when YW=0 then TKJE else 0 end) as QZE from CARD_T where TKRQ>='";
	String TKsqlstr = "select SUM(case when YW=1 then 1 else 0 end) as TZCS,SUM(case when YW=1 then -TKJE else 0 end) as TZE,SUM(case when YW=1 then -TKCB else 0 end) as RZE,SUM(case when YW=0 then 1 else 0 end) as QZCS,SUM(case when YW=0 then -TKJE else 0 end) as QZE from CARD_T join OperationList on CARD_T.KH=OperationList.KH where (OperationList.LX='退卡' or OperationList.LX='无卡退卡' or OperationList.LX='补发卡') and CARD_T.TKRQ>='";

	TKsqlstr += QSSJstr;
    TKsqlstr += "' and CARD_T.TKRQ<='";
    TKsqlstr += JZSJstr;
    TKsqlstr += "'";

    if(QCZYstr != "所有系统用户"&&!QCZYstr.IsEmpty())
    {
        sqlstr += " and CZY='";
        sqlstr += QCZYstr;
        sqlstr += "'";

        TKsqlstr += " and CARD_T.TKOperator='";
        TKsqlstr += QCZYstr;
        TKsqlstr += "'";
    }

	JSADOQuery->Close();
    JSADOQuery->SQL->Clear();
    JSADOQuery->SQL->Add(sqlstr);
    JSADOQuery->Open();

    KZCSstr = JSADOQuery->FieldByName("KZCS")->AsInteger;
    KCBstr = JSADOQuery->FieldByName("KCB")->AsFloat;
    KZEstr = JSADOQuery->FieldByName("KZE")->AsFloat;

    AZCSstr = JSADOQuery->FieldByName("AZCS")->AsInteger;
    AZEstr = JSADOQuery->FieldByName("AZE")->AsFloat;

    IZCSstr = JSADOQuery->FieldByName("IZCS")->AsInteger;
    IZEstr = JSADOQuery->FieldByName("IZE")->AsFloat;

    GZCSstr = JSADOQuery->FieldByName("GZCS")->AsInteger;
    GCBstr = JSADOQuery->FieldByName("GCB")->AsFloat;
	GZEstr = "0";//JSADOQuery->FieldByName("GZE")->AsFloat;

    DZCSstr = JSADOQuery->FieldByName("DZCS")->AsInteger;
    DZEstr = JSADOQuery->FieldByName("DZE")->AsFloat;

    JSADOQuery->Close();
    JSADOQuery->SQL->Clear();
    JSADOQuery->SQL->Add(TKsqlstr);
    JSADOQuery->Open();
    TZCSstr = JSADOQuery->FieldByName("TZCS")->AsInteger;
    TCBstr = JSADOQuery->FieldByName("RZE")->AsFloat;
    TZEstr = JSADOQuery->FieldByName("TZE")->AsFloat;

    QZCSstr = JSADOQuery->FieldByName("QZCS")->AsInteger;
    QZEstr = JSADOQuery->FieldByName("QZE")->AsFloat;
    JSADOQuery->Close();

	cxTextEdit1->Text = KZCSstr;
    cxTextEdit2->Text = KCBstr;
    cxTextEdit3->Text = KZEstr;
    cxTextEdit4->Text = AZCSstr;
    cxTextEdit5->Text = ACBstr;
    cxTextEdit6->Text = AZEstr;
    cxTextEdit7->Text = IZCSstr;
    cxTextEdit8->Text = ICBstr;
    cxTextEdit9->Text = IZEstr;
    cxTextEdit10->Text = GZCSstr;
    cxTextEdit11->Text = GCBstr;
	cxTextEdit12->Text = GZEstr;
    cxTextEdit13->Text = DZCSstr;
    cxTextEdit14->Text = DCBstr;
    cxTextEdit15->Text = DZEstr;
    cxTextEdit16->Text = CZCSstr;
    cxTextEdit17->Text = CCBstr;
    cxTextEdit18->Text = CZEstr;
    cxTextEdit19->Text = TZCSstr;
    cxTextEdit20->Text = TCBstr;
    cxTextEdit21->Text = TZEstr;
    cxTextEdit22->Text = QZCSstr;
    cxTextEdit23->Text = QCBstr;
    cxTextEdit24->Text = QZEstr;


    JSZCSstr = IntToStr(StrToInt(KZCSstr)+StrToInt(AZCSstr)+StrToInt(IZCSstr)+
    			StrToInt(GZCSstr)+StrToInt(DZCSstr)+StrToInt(CZCSstr)+
                StrToInt(TZCSstr)+StrToInt(QZCSstr));
    JSZCBstr = FloatToStr(StrToFloat(KCBstr)+StrToFloat(ACBstr)+StrToFloat(ICBstr)+
    			StrToFloat(GCBstr)+StrToFloat(DCBstr)+StrToFloat(CCBstr)+
                StrToFloat(TCBstr)+StrToFloat(QCBstr));
    JSZJEstr = FloatToStr(StrToFloat(KZEstr)+StrToFloat(AZEstr)+StrToFloat(IZEstr)+
				StrToFloat(GZEstr)+StrToFloat(DZEstr)+StrToFloat(CZEstr)+
				StrToFloat(TZEstr)+StrToFloat(QZEstr));

    cxTextEdit25->Text = JSZCSstr;
    cxTextEdit26->Text = JSZCBstr;
    cxTextEdit27->Text = JSZJEstr;

    ZCZJEstr = FloatToStr(StrToFloat(DZEstr)+StrToFloat(TZEstr)+StrToFloat(QZEstr)+StrToFloat(TCBstr));
    SRZJEstr = FloatToStr(StrToFloat(AZEstr)+StrToFloat(IZEstr)+StrToFloat(KZEstr)+StrToFloat(GCBstr));
    ZJSstr = FloatToStr(StrToFloat(SRZJEstr)+StrToFloat(ZCZJEstr));

    cxTextEdit28->Text = ZCZJEstr;
    cxTextEdit29->Text = SRZJEstr;
    cxTextEdit30->Text = ZJSstr;

    ExportBTN->Enabled = true;
    PreviewBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCZYJSQFrm::ExportBTNClick(TObject *Sender)
{
	QueryBTN->Enabled = false;
    ExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    ExitBTN->Enabled = false;
    String savename;

    if(SaveDialog->Execute())
    {
        if(FileExists(SaveDialog->FileName+".xls"))
        {
            QueryBTN->Enabled = true;
            ExportBTN->Enabled = true;
            PreviewBTN->Enabled = true;
            ExitBTN->Enabled = true;
            throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
            return;
        }
        else
        {
            savename = SaveDialog->FileName;
            savename += ".xls";
        }
    }

    Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(this->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
        QueryBTN->Enabled = true;
        ExportBTN->Enabled = true;
        PreviewBTN->Enabled = true;
        ExitBTN->Enabled = true;
		return;
	}

    String Templatepath = GlobalPath + "\\ExportXLSTemplate\\CZYJSTemplate.xlt";
    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
    Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
    Variant ST = WB.OlePropertyGet("Sheets", 1);

    //设置报头信息
    String tmpoutstr = "";

    tmpoutstr = QCZYstr+"操作员收支情况结算";
    ST.OlePropertyGet("Cells",1,1).OlePropertySet("Value", tmpoutstr.t_str());
    ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", OperatorName.t_str());
    ST.OlePropertyGet("Cells",2,4).OlePropertySet("Value", QSSJstr.t_str());
    ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
    ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", JZSJstr.t_str());

    tmpoutstr = KZCSstr+"人次";
    ST.OlePropertyGet("Cells",5,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+KCBstr;
    ST.OlePropertyGet("Cells",5,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+KZEstr;
    ST.OlePropertyGet("Cells",5,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = AZCSstr+"人次";
    ST.OlePropertyGet("Cells",6,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+ACBstr;
    ST.OlePropertyGet("Cells",6,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+AZEstr;
    ST.OlePropertyGet("Cells",6,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = IZCSstr+"人次";
    ST.OlePropertyGet("Cells",7,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+ICBstr;
    ST.OlePropertyGet("Cells",7,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+IZEstr;
    ST.OlePropertyGet("Cells",7,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = GZCSstr+"人次";
    ST.OlePropertyGet("Cells",8,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+GCBstr;
    ST.OlePropertyGet("Cells",8,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+GZEstr;
    ST.OlePropertyGet("Cells",8,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = DZCSstr+"人次";
    ST.OlePropertyGet("Cells",9,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+DCBstr;
    ST.OlePropertyGet("Cells",9,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+DZEstr;
    ST.OlePropertyGet("Cells",9,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = CZCSstr+"人次";
    ST.OlePropertyGet("Cells",10,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+CCBstr;
    ST.OlePropertyGet("Cells",10,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+CZEstr;
    ST.OlePropertyGet("Cells",10,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = TZCSstr+"人次";
    ST.OlePropertyGet("Cells",11,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+TCBstr;
    ST.OlePropertyGet("Cells",11,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+TZEstr;
    ST.OlePropertyGet("Cells",11,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = QZCSstr+"人次";
    ST.OlePropertyGet("Cells",12,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+QCBstr;
    ST.OlePropertyGet("Cells",12,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+QZEstr;
    ST.OlePropertyGet("Cells",12,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = JSZCSstr+"人次";
    ST.OlePropertyGet("Cells",13,2).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+JSZCBstr;
    ST.OlePropertyGet("Cells",13,3).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+JSZJEstr;
    ST.OlePropertyGet("Cells",13,4).OlePropertySet("Value", tmpoutstr.t_str());

    tmpoutstr = "￥"+ZCZJEstr;
    ST.OlePropertyGet("Cells",14,4).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+SRZJEstr;
    ST.OlePropertyGet("Cells",15,4).OlePropertySet("Value", tmpoutstr.t_str());
    tmpoutstr = "￥"+ZJSstr;
    ST.OlePropertyGet("Cells",16,4).OlePropertySet("Value", tmpoutstr.t_str());

    ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
    WB.OleFunction("SaveAs", savename.t_str());
    ExcelApp.OleFunction("Quit");
    ExcelApp = Unassigned;
    MessageBox(this->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);

    QueryBTN->Enabled = true;
    ExportBTN->Enabled = true;
    PreviewBTN->Enabled = true;
    ExitBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCZYJSQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\CZYJSMXPreview.fr3";
    frxJSReport->LoadFromFile(temppath.t_str(), true);
    ((TfrxMemoView*)frxJSReport->FindObject("HeadM"))->Text = QCZYstr+"操作员收支情况结算";
    ((TfrxMemoView*)frxJSReport->FindObject("BBCZYM"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxJSReport->FindObject("SCRQM"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxJSReport->FindObject("QSRQM"))->Text = QSSJstr.t_str();
    ((TfrxMemoView*)frxJSReport->FindObject("JZRQM"))->Text = JZSJstr.t_str();

    ((TfrxMemoView*)frxJSReport->FindObject("KCSM"))->Text = KZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("KCBM"))->Text = "￥"+KCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("KZEM"))->Text = "￥"+KZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("ACSM"))->Text = AZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("ACBM"))->Text = "￥"+ACBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("AZEM"))->Text = "￥"+AZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("ICSM"))->Text = IZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("ICBM"))->Text = "￥"+ICBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("IZEM"))->Text = "￥"+IZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("GCSM"))->Text = GZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("GCBM"))->Text = "￥"+GCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("GZEM"))->Text = "￥"+GZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("DCSM"))->Text = DZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("DCBM"))->Text = "￥"+DCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("DZEM"))->Text = "￥"+DZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("CCSM"))->Text = CZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("CCBM"))->Text = "￥"+CCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("CZEM"))->Text = "￥"+CZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("TCSM"))->Text = TZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("TCBM"))->Text = "￥"+TCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("TZEM"))->Text = "￥"+TZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("QCSM"))->Text = QZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("QCBM"))->Text = "￥"+QCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("QZEM"))->Text = "￥"+QZEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("JSCSM"))->Text = JSZCSstr+"人次";
    ((TfrxMemoView*)frxJSReport->FindObject("JSCBM"))->Text = "￥"+JSZCBstr;
    ((TfrxMemoView*)frxJSReport->FindObject("JSZEM"))->Text = "￥"+JSZJEstr;

    ((TfrxMemoView*)frxJSReport->FindObject("ZCXJM"))->Text = "￥"+ZCZJEstr;
    ((TfrxMemoView*)frxJSReport->FindObject("SRXJM"))->Text = "￥"+SRZJEstr;
    ((TfrxMemoView*)frxJSReport->FindObject("JSM"))->Text = "￥"+ZJSstr;
    frxJSReport->ShowReport(true);
}
//---------------------------------------------------------------------------

