//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PreOrderMXForm.h"
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
TPreOrderMXFrm *PreOrderMXFrm;
//---------------------------------------------------------------------------
__fastcall TPreOrderMXFrm::TPreOrderMXFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPreOrderMXFrm::FormShow(TObject *Sender)
{
	CBMXADOQuery->Close();
    if(!CBMXADOQuery->IsEmpty()&&CBMXADOQuery->RecordCount<=65500)
    {
        BFPSUM = 0;
        BFASUM = 0;
        BFSUM = 0;
        BFPCOUNT = 0;
        BFACOUNT = 0;

        LHPSUM = 0;
        LHASUM = 0;
        LHSUM = 0;
        LHPCOUNT = 0;
        LHACOUNT = 0;

        SRPSUM = 0;
        SRASUM = 0;
        SRSUM = 0;
        SRPCOUNT = 0;
        SRACOUNT = 0;

        NTPSUM = 0;
        NTASUM = 0;
        NTSUM = 0;
        NTPCOUNT = 0;
        NTACOUNT = 0;

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

		String SUMsqlstr = "select SUM(MXBAK.SFJE) as SFSUM from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where";
		String COUNTsqlstr = "select COUNT(*) as SFCOUNT from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where";

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

        if(!MSBMStr.IsEmpty()&&MSBMStr!="所有部门")
        {
        	SUMsqlstr += "CARD.BM='";
            SUMsqlstr += MSBMStr;
            SUMsqlstr += "' and ";
        }

        if(MSBFtag)
        {
            String BFDCSUMsqlstr = SUMsqlstr;
            String BFDCCOUNTsqlstr = COUNTsqlstr;
            String BFXFSUMsqlstr = SUMsqlstr;
            String BFXFCOUNTsqlstr = COUNTsqlstr;

            BFDCSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            BFDCSUMsqlstr += MSCBBFendtime;
            BFDCSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            BFDCSUMsqlstr += MSCBBFstarttime;
            BFDCSUMsqlstr += "') and SFLX='S'";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(BFDCSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                BFPSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                BFDCCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                BFDCCOUNTsqlstr += MSCBBFendtime;
                BFDCCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                BFDCCOUNTsqlstr += MSCBBFstarttime;
                BFDCCOUNTsqlstr += "') and SFLX='S'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(BFDCCOUNTsqlstr);
                TJADOQuery->Open();
                BFPCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	BFPSUM = 0;
                BFPCOUNT = 0;
            }

            BFXFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            BFXFSUMsqlstr += MSCBBFendtime;
            BFXFSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            BFXFSUMsqlstr += MSCBBFstarttime;
            BFXFSUMsqlstr += "') and SFLX='O'";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(BFXFSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                BFASUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                BFXFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                BFXFCOUNTsqlstr += MSCBBFendtime;
                BFXFCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                BFXFCOUNTsqlstr += MSCBBFstarttime;
                BFDCCOUNTsqlstr += "') and SFLX='O'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(BFXFCOUNTsqlstr);
                TJADOQuery->Open();
                BFACOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	BFASUM = 0;
                BFACOUNT = 0;
            }

            BFSUM = BFPSUM+BFASUM;
        }

        if(MSLHtag)
        {
            String LHDCSUMsqlstr = SUMsqlstr;
            String LHDCCOUNTsqlstr = COUNTsqlstr;

            LHDCSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            LHDCSUMsqlstr += MSCBLHendtime;
            LHDCSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            LHDCSUMsqlstr += MSCBLHstarttime;
            LHDCSUMsqlstr += "') and SFLX='D'";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(LHDCSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                LHPSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                LHDCCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                LHDCCOUNTsqlstr += MSCBLHendtime;
                LHDCCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                LHDCCOUNTsqlstr += MSCBLHstarttime;
                LHDCCOUNTsqlstr += "') and SFLX='D'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(LHDCCOUNTsqlstr);
                TJADOQuery->Open();
                LHPCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	LHPSUM = 0;
                LHPCOUNT = 0;
            }

            String LHXFSUMsqlstr = SUMsqlstr;
            String LHXFCOUNTsqlstr = COUNTsqlstr;

            LHXFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            LHXFSUMsqlstr += MSCBLHendtime;
            LHXFSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            LHXFSUMsqlstr += MSCBLHstarttime;
            LHXFSUMsqlstr += "') and SFLX='O'";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(LHXFSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                LHASUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                LHXFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                LHXFCOUNTsqlstr += MSCBLHendtime;
                LHXFCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                LHXFCOUNTsqlstr += MSCBLHstarttime;
                LHXFCOUNTsqlstr += "') and SFLX='O'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(LHXFCOUNTsqlstr);
                TJADOQuery->Open();
                LHACOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	LHASUM = 0;
                LHACOUNT = 0;
            }
        }

        if(MSSRtag)
        {
            String SRDCSUMsqlstr = SUMsqlstr;
            String SRDCCOUNTsqlstr = COUNTsqlstr;
            SRDCSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            SRDCSUMsqlstr += MSCBSRendtime;
            SRDCSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            SRDCSUMsqlstr += MSCBSRstarttime;
            SRDCSUMsqlstr += "') and SFLX='F'";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(SRDCSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                SRPSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                SRDCCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                SRDCCOUNTsqlstr += MSCBSRendtime;
                SRDCCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                SRDCCOUNTsqlstr += MSCBSRstarttime;
                SRDCCOUNTsqlstr += "') and SFLX='F'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(SRDCCOUNTsqlstr);
                TJADOQuery->Open();
                SRPCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	SRPSUM = 0;
                SRPCOUNT = 0;
            }

            String SRXFSUMsqlstr = SUMsqlstr;
            String SRXFCOUNTsqlstr = COUNTsqlstr;
            SRXFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
            SRXFSUMsqlstr += MSCBSRendtime;
            SRXFSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            SRXFSUMsqlstr += MSCBSRstarttime;
            SRXFSUMsqlstr += "') and SFLX='O'";
            TJADOQuery->Close();
            TJADOQuery->SQL->Clear();
            TJADOQuery->SQL->Add(SRXFSUMsqlstr);
            TJADOQuery->Open();
            if(!TJADOQuery->IsEmpty())
            {
                SRASUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                SRXFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                SRXFCOUNTsqlstr += MSCBSRendtime;
                SRXFCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                SRXFCOUNTsqlstr += MSCBSRstarttime;
                SRXFCOUNTsqlstr += "') and SFLX='O'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(SRXFCOUNTsqlstr);
                TJADOQuery->Open();
                SRACOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                TJADOQuery->Close();
            }
            else
            {
            	SRASUM = 0;
                SRACOUNT = 0;
            }
        }

        if(MSNTtag)
        {
            if(StrToDateTime(MSCBNTendtime)>StrToDateTime(MSCBNTstarttime))
            {
                String NTDCSUMsqlstr = SUMsqlstr;
                String NTDCCOUNTsqlstr = COUNTsqlstr;
                NTDCSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                NTDCSUMsqlstr += MSCBNTendtime;
                NTDCSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                NTDCSUMsqlstr += MSCBNTstarttime;
                NTDCSUMsqlstr += "') and SFLX='G'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTDCSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTPSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTDCCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                    NTDCCOUNTsqlstr += MSCBNTendtime;
                    NTDCCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    NTDCCOUNTsqlstr += MSCBNTstarttime;
                    NTDCCOUNTsqlstr += "') and SFLX='G'";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTDCCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTPCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
                else
                {
                    NTPSUM = 0;
                    NTPCOUNT = 0;
                }

                String NTXFSUMsqlstr = SUMsqlstr;
                String NTXFCOUNTsqlstr = COUNTsqlstr;
                NTXFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                NTXFSUMsqlstr += MSCBNTendtime;
                NTXFSUMsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                NTXFSUMsqlstr += MSCBNTstarttime;
                NTXFSUMsqlstr += "') and SFLX='O'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTXFSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTASUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTXFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='";
                    NTXFCOUNTsqlstr += MSCBNTendtime;
                    NTXFCOUNTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    NTXFCOUNTsqlstr += MSCBNTstarttime;
                    NTXFCOUNTsqlstr += "') and SFLX='O'";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTXFCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTACOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
                else
                {
                    NTASUM = 0;
                    NTACOUNT = 0;
                }
            }
            else
            {
                String NTDCSUMsqlstr = SUMsqlstr;
                String NTDCCOUNTsqlstr = COUNTsqlstr;
                NTDCSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                NTDCSUMsqlstr += MSCBNTstarttime;
                NTDCSUMsqlstr += "') and SFLX='G'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTDCSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTPSUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTDCCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    NTDCCOUNTsqlstr += MSCBNTstarttime;
                    NTDCCOUNTsqlstr += "') and SFLX='G'";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTDCCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTPCOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
                else
                {
                    NTPSUM = 0;
                    NTPCOUNT = 0;
                }

                NTDCSUMsqlstr = SUMsqlstr;
                NTDCCOUNTsqlstr = COUNTsqlstr;
                NTDCSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                NTDCSUMsqlstr += MSCBNTendtime;
                NTDCSUMsqlstr += "') and SFLX='G'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTDCSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTPSUM += TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTDCCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                    NTDCCOUNTsqlstr += MSCBNTendtime;
                    NTDCCOUNTsqlstr += "') and SFLX='G'";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTDCCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTPCOUNT += TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }

                String NTXFSUMsqlstr = SUMsqlstr;
                String NTXFCOUNTsqlstr = COUNTsqlstr;
                NTXFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                NTXFSUMsqlstr += MSCBNTstarttime;
                NTXFSUMsqlstr += "') and SFLX='O'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTXFSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTASUM = TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTXFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)<='23:59:59' and convert(varchar(100),MXBAK.SFRQ,108)>='";
                    NTXFCOUNTsqlstr += MSCBNTstarttime;
                    NTXFCOUNTsqlstr += "') and SFLX='O'";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTXFCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTACOUNT = TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
                else
                {
                    NTASUM = 0;
                    NTACOUNT = 0;
                }

                NTXFSUMsqlstr = SUMsqlstr;
                NTXFCOUNTsqlstr = COUNTsqlstr;
                NTXFSUMsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                NTXFSUMsqlstr += MSCBNTendtime;
                NTXFSUMsqlstr += "') and SFLX='O'";
                TJADOQuery->Close();
                TJADOQuery->SQL->Clear();
                TJADOQuery->SQL->Add(NTXFSUMsqlstr);
                TJADOQuery->Open();
                if(!TJADOQuery->IsEmpty())
                {
                    NTASUM += TJADOQuery->FieldByName("SFSUM")->AsFloat;
                    NTXFCOUNTsqlstr += "(convert(varchar(100),MXBAK.SFRQ,108)>='00:00:00' and convert(varchar(100),MXBAK.SFRQ,108)<='";
                    NTXFCOUNTsqlstr += MSCBNTendtime;
                    NTXFCOUNTsqlstr += "') and SFLX='G'";
                    TJADOQuery->Close();
                    TJADOQuery->SQL->Clear();
                    TJADOQuery->SQL->Add(NTXFCOUNTsqlstr);
                    TJADOQuery->Open();
                    NTACOUNT += TJADOQuery->FieldByName("SFCOUNT")->AsInteger;
                    TJADOQuery->Close();
                }
            }
        }

        String tmpoutstr = "￥";
        BFDCCSTextEdit->Text = BFPCOUNT;
        BFDCJETextEdit->Text = tmpoutstr + BFPSUM;
        BFXFCSTextEdit->Text = BFACOUNT;
        BFXFJETextEdit->Text = tmpoutstr + BFASUM;
        BFZETextEdit->Text = tmpoutstr + (BFPSUM+BFASUM);

        LHDCCSTextEdit->Text = LHPCOUNT;
        LHDCJETextEdit->Text = tmpoutstr + LHPSUM;
        LHXFCSTextEdit->Text = LHACOUNT;
        LHXFJETextEdit->Text = tmpoutstr + LHASUM;
        LHZETextEdit->Text = tmpoutstr + (LHPSUM+LHASUM);

        SPDCCSTextEdit->Text = SRPCOUNT;
        SPDCJETextEdit->Text = tmpoutstr + SRPSUM;
        SPXFCSTextEdit->Text = SRACOUNT;
        SPXFJETextEdit->Text = tmpoutstr + SRASUM;
        SPZETextEdit->Text = tmpoutstr + (SRPSUM+SRASUM);

        NTDCCSTextEdit->Text = NTPCOUNT;
        NTDCJETextEdit->Text = tmpoutstr + NTPSUM;
        NTXFCSTextEdit->Text = NTACOUNT;
        NTXFJETextEdit->Text = tmpoutstr + NTASUM;
        NTZETextEdit->Text = tmpoutstr + (NTPSUM+NTASUM);

        DCCSTextEdit->Text = BFPCOUNT+LHPCOUNT+SRPCOUNT+NTPCOUNT;
        DCJETextEdit->Text = tmpoutstr + (BFPSUM+LHPSUM+SRPSUM+NTPSUM);
        XFCSTextEdit->Text = BFACOUNT+LHACOUNT+SRACOUNT+NTACOUNT;
        XFJETextEdit->Text = tmpoutstr + (BFASUM+LHASUM+SRASUM+NTASUM);
        ZETextEdit->Text = tmpoutstr + (BFPSUM+LHPSUM+SRPSUM+NTPSUM+BFASUM+LHASUM+SRASUM+NTASUM);

        CBMXExportProgressBar->Position = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TPreOrderMXFrm::CBMXExitBTNClick(TObject *Sender)
{
	CBMXADOQuery->Close();
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TPreOrderMXFrm::CBMXExportBTNClick(TObject *Sender)
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
                TPOMXExportThread* EXThread = new TPOMXExportThread(true,
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
                                                                    BFPSUM,
                                                                    BFASUM,
                                                                    BFSUM,
                                                                    BFPCOUNT,
                                                                    BFACOUNT,
                                                                    LHPSUM,
                                                                    LHASUM,
                                                                    LHSUM,
                                                                    LHPCOUNT,
                                                                    LHACOUNT,
                                                                    SRPSUM,
                                                                    SRASUM,
                                                                    SRSUM,
                                                                    SRPCOUNT,
                                                                    SRACOUNT,
                                                                    NTPSUM,
                                                                    NTASUM,
																	NTSUM,
                                                                    NTPCOUNT,
                                                                    NTACOUNT,
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

void __fastcall TPreOrderMXFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\DCMXPreview.fr3";
    frxDCMXReport->LoadFromFile(temppath.t_str(), true);

    if(MSBFtag)
    	((TfrxMemoView*)frxDCMXReport->FindObject("BFMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxDCMXReport->FindObject("BFMemo"))->Text = "N";
    ((TfrxMemoView*)frxDCMXReport->FindObject("BFDCCSMemo"))->Text = IntToStr(BFPCOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("BFDCJEMemo"))->Text = "￥" + FloatToStr(BFPSUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("BFXFCSMemo"))->Text = IntToStr(BFACOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("BFXFJEMemo"))->Text = "￥" + FloatToStr(BFASUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("BFZEMemo"))->Text = "￥" + FloatToStr(BFPSUM+BFASUM);

    if(MSLHtag)
    	((TfrxMemoView*)frxDCMXReport->FindObject("LHMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxDCMXReport->FindObject("LHMemo"))->Text = "N";
    ((TfrxMemoView*)frxDCMXReport->FindObject("LHDCCSMemo"))->Text = IntToStr(LHPCOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("LHDCJEMemo"))->Text = "￥" + FloatToStr(LHPSUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("LHXFCSMemo"))->Text = IntToStr(LHACOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("LHXFJEMemo"))->Text = "￥" + FloatToStr(LHASUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("LHZEMemo"))->Text = "￥" + FloatToStr(LHPSUM+LHASUM);

    if(MSSRtag)
    	((TfrxMemoView*)frxDCMXReport->FindObject("SRMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxDCMXReport->FindObject("SRMemo"))->Text = "N";
    ((TfrxMemoView*)frxDCMXReport->FindObject("SRDCCSMemo"))->Text = IntToStr(SRPCOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("SRDCJEMemo"))->Text = "￥" + FloatToStr(SRPSUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("SRXFCSMemo"))->Text = IntToStr(SRACOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("SRXFJEMemo"))->Text = "￥" + FloatToStr(SRASUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("SRZEMemo"))->Text = "￥" + FloatToStr(SRPSUM+SRASUM);

    if(MSNTtag)
    	((TfrxMemoView*)frxDCMXReport->FindObject("NTMemo"))->Text = "Y";
    else
        ((TfrxMemoView*)frxDCMXReport->FindObject("NTMemo"))->Text = "N";
    ((TfrxMemoView*)frxDCMXReport->FindObject("NTDCCSMemo"))->Text = IntToStr(NTPCOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("NTDCJEMemo"))->Text = "￥" + FloatToStr(NTPSUM);//DateTimeToStr(Now());
    ((TfrxMemoView*)frxDCMXReport->FindObject("NTXFCSMemo"))->Text = IntToStr(NTACOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("NTXFJEMemo"))->Text = "￥" + FloatToStr(NTASUM);//DateTimeToStr(Now());
    ((TfrxMemoView*)frxDCMXReport->FindObject("NTZEMemo"))->Text = "￥" + FloatToStr(NTPSUM+NTASUM);//DateTimeToStr(Now());

    ((TfrxMemoView*)frxDCMXReport->FindObject("ZDCCSMemo"))->Text = IntToStr(BFPCOUNT+LHPCOUNT+SRPCOUNT+NTPCOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("ZDCZEMemo"))->Text = "￥"+FloatToStr(BFPSUM+LHPSUM+SRPSUM+NTPSUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("ZXFCSMemo"))->Text = IntToStr(BFACOUNT+LHACOUNT+SRACOUNT+NTACOUNT);
    ((TfrxMemoView*)frxDCMXReport->FindObject("XFZEMemo"))->Text = "￥"+FloatToStr(BFASUM+LHASUM+SRASUM+NTASUM);
    ((TfrxMemoView*)frxDCMXReport->FindObject("ZEMemo"))->Text = "￥"+FloatToStr(BFPSUM+LHPSUM+SRPSUM+NTPSUM+BFASUM+LHASUM+SRASUM+NTASUM);


    ((TfrxMemoView*)frxDCMXReport->FindObject("CTMemo"))->Text = MSCTStr.t_str();
    ((TfrxMemoView*)frxDCMXReport->FindObject("QSRQMemo"))->Text = MSBeginDateTimeStr.t_str();
    ((TfrxMemoView*)frxDCMXReport->FindObject("JZRQMemo"))->Text = MSEndDateTimeStr.t_str();
    ((TfrxMemoView*)frxDCMXReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();
    ((TfrxMemoView*)frxDCMXReport->FindObject("BBCZYMemo"))->Text = MSCZYStr.t_str();

    ((TfrxMemoView*)frxDCMXReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxDCMXReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxDCMXReport->FindObject("XM"))->DataField = "UNAME";
    ((TfrxMemoView*)frxDCMXReport->FindObject("BM"))->DataField = "BUMEN";
    ((TfrxMemoView*)frxDCMXReport->FindObject("SFYE"))->DataField = "SF_YE";
    ((TfrxMemoView*)frxDCMXReport->FindObject("SFJE"))->DataField = "SFJE";
    ((TfrxMemoView*)frxDCMXReport->FindObject("SYCS"))->DataField = "SYCS";
    ((TfrxMemoView*)frxDCMXReport->FindObject("JYNO"))->DataField = "JYNO";
    ((TfrxMemoView*)frxDCMXReport->FindObject("CT"))->DataField = "CTNAME";
    ((TfrxMemoView*)frxDCMXReport->FindObject("SFLX"))->DataField = "SFLX";
    ((TfrxMemoView*)frxDCMXReport->FindObject("SFRQ"))->DataField = "SFRQ";

    frxDCMXReport->ShowReport(true);
}
//---------------------------------------------------------------------------

