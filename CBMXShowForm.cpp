//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CBMXShowForm.h"
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
TCBMXShowFrm *CBMXShowFrm;
//---------------------------------------------------------------------------
__fastcall TCBMXShowFrm::TCBMXShowFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCBMXShowFrm::CBMXExitBTNClick(TObject *Sender)
{
	CBMXADOQuery->Close();
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TCBMXShowFrm::FormShow(TObject *Sender)
{
	CBMXADOQuery->Open();
    if(!CBMXADOQuery->IsEmpty()&&CBMXADOQuery->RecordCount<=65500)
    {
        BFSUM = 0;
        BFCOUNT = 0;
        LHSUM = 0;
        LHCOUNT = 0;
        SRSUM = 0;
        SRCOUNT = 0;
        NTSUM = 0;
        NTCOUNT = 0;

    	DataGridDBTV->DataController->DataSource = CBMXDataSource;
        DataGridDBTV->ClearItems();

        TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* ZWCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFJECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SYCSCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* JYNOCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* CTNAMECol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFLXCol = DataGridDBTV->CreateColumn();
        TcxGridDBColumn* SFRQCol = DataGridDBTV->CreateColumn();

        KHCol->Caption = "卡号";
        KHCol->MinWidth = 90;
        KHCol->DataBinding->FieldName = "KH";
        BHCol->Caption = "编号";
        BHCol->MinWidth = 90;
        BHCol->DataBinding->FieldName = "BH";
        XMCol->Caption = "姓名";
        XMCol->MinWidth = 70;
        XMCol->DataBinding->FieldName = "UName";
        BMCol->Caption = "部门";
        BMCol->MinWidth = 80;
        BMCol->DataBinding->FieldName = "BUMEN";
        ZWCol->Caption = "职务";
        ZWCol->MinWidth = 80;
        ZWCol->DataBinding->FieldName = "ZW";
        SFYECol->Caption = "卡余额";
        SFYECol->MinWidth = 70;
        SFYECol->DataBinding->FieldName = "SF_YE";
        SFJECol->Caption = "消费金额";
        SFJECol->MinWidth = 60;
        SFJECol->DataBinding->FieldName = "SFJE";
        SYCSCol->Caption = "使用次数";
        SYCSCol->MinWidth = 60;
        SYCSCol->DataBinding->FieldName = "SYCS";
        JYNOCol->Caption = "机号";
        JYNOCol->MinWidth = 50;
        JYNOCol->DataBinding->FieldName = "JYNO";
        CTNAMECol->Caption = "餐厅";
        CTNAMECol->MinWidth = 100;
        CTNAMECol->DataBinding->FieldName = "CTNAME";
        SFLXCol->Caption = "消费类型";
        SFLXCol->MinWidth = 60;
        SFLXCol->DataBinding->FieldName = "SFLX";
        SFRQCol->Caption = "消费日期";
        SFRQCol->MinWidth = 140;
        SFRQCol->DataBinding->FieldName = "SFRQ";

		String SUMsqlstr = "select SUM(MXBAK.SFJE) as SFSUM from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x' and";
		String COUNTsqlstr = "select COUNT(*) as SFCOUNT from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x' and";

		if(!MSCTStr.IsEmpty()&&MSCTStr!="所有餐厅")
        {
        	SUMsqlstr += " SFJPARAM.STNAME='";
            SUMsqlstr += MSCTStr;
            SUMsqlstr += "' and SFRQ<'";
            SUMsqlstr += MSEndDateTimeStr;
            SUMsqlstr += "' and SFRQ>'";
            SUMsqlstr += MSBeginDateTimeStr;
            SUMsqlstr += "' and ";

        	COUNTsqlstr += " SFJPARAM.STNAME='";
            COUNTsqlstr += MSCTStr;
            COUNTsqlstr += "' and SFRQ<'";
            COUNTsqlstr += MSEndDateTimeStr;
            COUNTsqlstr += "' and SFRQ>'";
            COUNTsqlstr += MSBeginDateTimeStr;
            COUNTsqlstr += "' and ";
        }
        else
        {
			SUMsqlstr += " SFRQ<'";
            SUMsqlstr += MSEndDateTimeStr;
            SUMsqlstr += "' and SFRQ>'";
            SUMsqlstr += MSBeginDateTimeStr;
            SUMsqlstr += "' and ";

			COUNTsqlstr += " SFRQ<'";
            COUNTsqlstr += MSEndDateTimeStr;
            COUNTsqlstr += "' and SFRQ>'";
            COUNTsqlstr += MSBeginDateTimeStr;
            COUNTsqlstr += "' and ";
        }

        if(MSBFtag)
        {
            String BFSUMsqlstr = SUMsqlstr;
            String BFCOUNTsqlstr = COUNTsqlstr;
            BFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            BFSUMsqlstr += MSCBBFendtime;
            BFSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            BFSUMsqlstr += MSCBBFstarttime;
            BFSUMsqlstr += "')";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(BFSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                BFSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                BFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                BFCOUNTsqlstr += MSCBBFendtime;
                BFCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                BFCOUNTsqlstr += MSCBBFstarttime;
                BFCOUNTsqlstr += "')";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(BFCOUNTsqlstr);
                TJADOQuery->Open();
                BFCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	BFSUM = 0;
                BFCOUNT = 0;
            }
        }

        if(MSLHtag)
        {
            String LHSUMsqlstr = SUMsqlstr;
            String LHCOUNTsqlstr = COUNTsqlstr;
            LHSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            LHSUMsqlstr += MSCBLHendtime;
            LHSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            LHSUMsqlstr += MSCBLHstarttime;
            LHSUMsqlstr += "')";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(LHSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                LHSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                LHCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                LHCOUNTsqlstr += MSCBLHendtime;
                LHCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                LHCOUNTsqlstr += MSCBLHstarttime;
                LHCOUNTsqlstr += "')";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(LHCOUNTsqlstr);
                TJADOQuery->Open();
                LHCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	LHSUM = 0;
                LHCOUNT = 0;
            }
        }

        if(MSSRtag)
        {
            String SRSUMsqlstr = SUMsqlstr;
            String SRCOUNTsqlstr = COUNTsqlstr;
            SRSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            SRSUMsqlstr += MSCBSRendtime;
            SRSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            SRSUMsqlstr += MSCBSRstarttime;
            SRSUMsqlstr += "')";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(SRSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                SRSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                SRCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                SRCOUNTsqlstr += MSCBSRendtime;
                SRCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                SRCOUNTsqlstr += MSCBSRstarttime;
                SRCOUNTsqlstr += "')";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(SRCOUNTsqlstr);
                TJADOQuery->Open();
                SRCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	SRSUM = 0;
                SRCOUNT = 0;
            }
        }

        if(MSNTtag)
        {
            if(StrToDateTime(MSCBNTendtime)>StrToDateTime(MSCBNTstarttime))
            {
                String NTSUMsqlstr = SUMsqlstr;
                String NTCOUNTsqlstr = COUNTsqlstr;
                NTSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                NTSUMsqlstr += MSCBNTendtime;
                NTSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                NTSUMsqlstr += MSCBNTstarttime;
                NTSUMsqlstr += "')";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                    NTCOUNTsqlstr += MSCBNTendtime;
                    NTCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    NTCOUNTsqlstr += MSCBNTstarttime;
                    NTCOUNTsqlstr += "')";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
                else
                {
                    NTSUM = 0;
                    NTCOUNT = 0;
                }
            }
            else
            {
                String NTSUMsqlstr = SUMsqlstr;
                String NTCOUNTsqlstr = COUNTsqlstr;
                NTSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                NTSUMsqlstr += MSCBNTstarttime;
                NTSUMsqlstr += "')";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    NTCOUNTsqlstr += MSCBNTstarttime;
                    NTCOUNTsqlstr += "')";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
                else
                {
                    NTSUM = 0;
                    NTCOUNT = 0;
                }

                NTSUMsqlstr = SUMsqlstr;
                NTCOUNTsqlstr = COUNTsqlstr;
                NTSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                NTSUMsqlstr += MSCBNTendtime;
                NTSUMsqlstr += "')";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTSUM += TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                    NTCOUNTsqlstr += MSCBNTendtime;
                    NTCOUNTsqlstr += "')";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTCOUNT += TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
            }
        }

        String tmpoutstr = "￥";
        BFCSTextEdit->Text = BFCOUNT;
        BFZETextEdit->Text = tmpoutstr + BFSUM;
        LHCSTextEdit->Text = LHCOUNT;
        LHZETextEdit->Text = tmpoutstr + LHSUM;
        SRCSTextEdit->Text = SRCOUNT;
        SRZETextEdit->Text = tmpoutstr + SRSUM;
        NTCSTextEdit->Text = NTCOUNT;
        NTZETextEdit->Text = tmpoutstr + NTSUM;
        ZCSTextEdit->Text = BFCOUNT + LHCOUNT + SRCOUNT + NTCOUNT;
        ZZETextEdit->Text = tmpoutstr + (BFSUM + LHSUM + SRSUM + NTSUM);
        CBMXExportProgressBar->Position = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TCBMXShowFrm::CBMXExportBTNClick(TObject *Sender)
{
	if(!CBMXADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = CBMXADOQuery->SQL;
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
                TCBMXExportThread* EXThread = new TCBMXExportThread(true,
                                                                    CBMXExportProgressBar,
                                                                    ADOQInThread,
                                                                    CBMXExportBTN,
                                                                    PreviewBTN,
                                                                    CBMXExitBTN,
                                                                    savename,
                                                                    MSBeginDateTimeStr,
                                                                    MSEndDateTimeStr,
                                                                    MSCTStr,
                                                                    MSBFtag,
                                                                    MSLHtag,
                                                                    MSSRtag,
                                                                    MSNTtag,
                                                                    BFSUM,
                                                                    BFCOUNT,
                                                                    LHSUM,
                                                                    LHCOUNT,
                                                                    SRSUM,
                                                                    SRCOUNT,
                                                                    NTSUM,
                                                                    NTCOUNT,
                                                                    MSCZYStr);
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

void __fastcall TCBMXShowFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\CBMXPreview.fr3";
    frxCBMXReport->LoadFromFile(temppath.t_str(), true);

    if(MSBFtag)
    	((TfrxMemoView*)frxCBMXReport->FindObject("BFMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxCBMXReport->FindObject("BFMemo"))->Text = "N";
    ((TfrxMemoView*)frxCBMXReport->FindObject("BFCSMemo"))->Text = IntToStr(BFCOUNT);
    ((TfrxMemoView*)frxCBMXReport->FindObject("BFZEMemo"))->Text = "￥" + FloatToStr(BFSUM);

    if(MSLHtag)
    	((TfrxMemoView*)frxCBMXReport->FindObject("LHMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxCBMXReport->FindObject("LHMemo"))->Text = "N";
    ((TfrxMemoView*)frxCBMXReport->FindObject("LHCSMemo"))->Text = IntToStr(LHCOUNT);
    ((TfrxMemoView*)frxCBMXReport->FindObject("LHZEMemo"))->Text = "￥" + FloatToStr(LHSUM);

    if(MSSRtag)
    	((TfrxMemoView*)frxCBMXReport->FindObject("SRMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxCBMXReport->FindObject("SRMemo"))->Text = "N";
    ((TfrxMemoView*)frxCBMXReport->FindObject("SRCSMemo"))->Text = IntToStr(SRCOUNT);
    ((TfrxMemoView*)frxCBMXReport->FindObject("SRZEMemo"))->Text = "￥" + FloatToStr(SRSUM);

    if(MSNTtag)
    	((TfrxMemoView*)frxCBMXReport->FindObject("NTMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxCBMXReport->FindObject("NTMemo"))->Text = "N";
    ((TfrxMemoView*)frxCBMXReport->FindObject("NTCSMemo"))->Text = IntToStr(NTCOUNT);
    ((TfrxMemoView*)frxCBMXReport->FindObject("NTZEMemo"))->Text = "￥" + FloatToStr(NTSUM);//DateTimeToStr(Now());

    ((TfrxMemoView*)frxCBMXReport->FindObject("CTMemo"))->Text = MSCTStr.t_str();
    ((TfrxMemoView*)frxCBMXReport->FindObject("ZCSMemo"))->Text = IntToStr(BFCOUNT+LHCOUNT+SRCOUNT+NTCOUNT);
    ((TfrxMemoView*)frxCBMXReport->FindObject("ZZEMemo"))->Text = "￥"+FloatToStr(BFSUM+LHSUM+SRSUM+NTSUM);
    ((TfrxMemoView*)frxCBMXReport->FindObject("QSRQMemo"))->Text = MSBeginDateTimeStr.t_str();
    ((TfrxMemoView*)frxCBMXReport->FindObject("JZRQMemo"))->Text = MSEndDateTimeStr.t_str();
    ((TfrxMemoView*)frxCBMXReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxCBMXReport->FindObject("BBCZYMemo"))->Text = MSCZYStr.t_str();

    ((TfrxMemoView*)frxCBMXReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxCBMXReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxCBMXReport->FindObject("XM"))->DataField = "UNAME";
    ((TfrxMemoView*)frxCBMXReport->FindObject("BM"))->DataField = "BUMEN";
    ((TfrxMemoView*)frxCBMXReport->FindObject("SFYE"))->DataField = "SF_YE";
    ((TfrxMemoView*)frxCBMXReport->FindObject("SFJE"))->DataField = "SFJE";
    ((TfrxMemoView*)frxCBMXReport->FindObject("SYCS"))->DataField = "SYCS";
    ((TfrxMemoView*)frxCBMXReport->FindObject("JYNO"))->DataField = "JYNO";
    ((TfrxMemoView*)frxCBMXReport->FindObject("CT"))->DataField = "CTNAME";
    ((TfrxMemoView*)frxCBMXReport->FindObject("SFLX"))->DataField = "SFLX";
    ((TfrxMemoView*)frxCBMXReport->FindObject("SFRQ"))->DataField = "SFRQ";

    frxCBMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------

