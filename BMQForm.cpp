//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BMQForm.h"
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
#pragma resource "*.dfm"
TBMQFrm *BMQFrm;
//---------------------------------------------------------------------------
__fastcall TBMQFrm::TBMQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBMQFrm::BMComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TBMQFrm::FormShow(TObject *Sender)
{
	QueryBTN->Enabled = false;
//	BMBeginDateEdit->Text = "";
//    BMEndDateEdit->Text = "";
	BMBeginDateEdit->Date = Date();
	BMEndDateEdit->Date = Date();

    CTComboBox->Text = "";
    BMComboBox->Text = "";
    CheckBox1->Checked = true;
    CheckBox2->Checked = true;
    CheckBox3->Checked = true;
    CheckBox4->Checked = true;
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
    BFtag = false;
    LHtag = false;
    SRtag = false;
    NTtag = false;

    BFCS = 0;
    BFZE = 0;
    LHCS = 0;
    LHZE = 0;
    SRCS = 0;
    SRZE = 0;
    NTCS = 0;
    NTZE = 0;
    ALLCS = 0;
    ALLZE = 0;

    ExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;

    BMADOQ->Close();
    BMADOQ->SQL->Clear();
    BMADOQ->SQL->Add("select * from STNAME");
    BMADOQ->Open();
    if(!BMADOQ->IsEmpty())
    {
        BMADOQ->First();
        CTComboBox->Properties->Items->Clear();
        while(!BMADOQ->Eof)
        {
        	CTComboBox->Properties->Items->Add(BMADOQ->FieldByName("STNAME")->AsString.Trim());
            BMADOQ->Next();
        }
        CTComboBox->Properties->Items->Add("所有餐厅");
        CTComboBox->ItemIndex = -1;
	}

    BMADOQ->Close();
    BMADOQ->SQL->Clear();
    BMADOQ->SQL->Add("select * from BUMEN");
    BMADOQ->Open();
    if(!BMADOQ->IsEmpty())
    {
        BMADOQ->First();
        BMComboBox->Properties->Items->Clear();
        while(!BMADOQ->Eof)
        {
            BMComboBox->Properties->Items->Add(BMADOQ->FieldByName("BUMEN")->AsString.Trim());
            BMADOQ->Next();
        }
        BMComboBox->Properties->Items->Add("所有部门");
        BMComboBox->ItemIndex = -1;
	}

    BMADOQ->Close();
    BMADOQ->SQL->Clear();
    BMADOQ->SQL->Add("select * from SUBMEALINFO");
    BMADOQ->Open();
    if(!BMADOQ->IsEmpty())
    {
    	if(BMADOQ->FieldByName("breakfaststart")->AsDateTime<"10:00:00")
			BFstarttime = BMADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();
        else
        	BFstarttime = BMADOQ->FieldByName("breakfaststart")->AsDateTime.TimeString();

		if(BMADOQ->FieldByName("breakfastend")->AsDateTime<"10:00:00")
			BFendtime = BMADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();
        else
            BFendtime = BMADOQ->FieldByName("breakfastend")->AsDateTime.TimeString();

        if(BMADOQ->FieldByName("lunchstart")->AsDateTime<"10:00:00")
			LHstarttime = BMADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();
        else
        	LHstarttime = BMADOQ->FieldByName("lunchstart")->AsDateTime.TimeString();

        if(BMADOQ->FieldByName("lunchend")->AsDateTime<"10:00:00")
			LHendtime = BMADOQ->FieldByName("lunchend")->AsDateTime.TimeString();
        else
        	LHendtime = BMADOQ->FieldByName("lunchend")->AsDateTime.TimeString();

        if(BMADOQ->FieldByName("supperstart")->AsDateTime<"10:00:00")
			SRstarttime = BMADOQ->FieldByName("supperstart")->AsDateTime.TimeString();
        else
            SRstarttime = BMADOQ->FieldByName("supperstart")->AsDateTime.TimeString();

        if(BMADOQ->FieldByName("supperend")->AsDateTime<"10:00:00")
			SRendtime = BMADOQ->FieldByName("supperend")->AsDateTime.TimeString();
        else
        	SRendtime = BMADOQ->FieldByName("supperend")->AsDateTime.TimeString();

        if(BMADOQ->FieldByName("nightstart")->AsDateTime<"10:00:00")
			NTstarttime = BMADOQ->FieldByName("nightstart")->AsDateTime.TimeString();
        else
        	NTstarttime = BMADOQ->FieldByName("nightstart")->AsDateTime.TimeString();

        if(BMADOQ->FieldByName("nightend")->AsDateTime<"10:00:00")
			NTendtime = BMADOQ->FieldByName("nightend")->AsDateTime.TimeString();
        else
        	NTendtime = BMADOQ->FieldByName("nightend")->AsDateTime.TimeString();
    }
    BMADOQ->Close();

	QueryBTN->Enabled = true;
	/*
    if(BFstarttime!="00:00:00"&&BFendtime!="00:00:00"&&LHstarttime!="00:00:00"
    	&&LHendtime!="00:00:00"&&SRstarttime!="00:00:00"&&SRendtime!="00:00:00"
        &&NTstarttime!="00:00:00")
	{
		QueryBTN->Enabled = true;
    }
    else
    {
        ShowMessage("必须正确设置餐别时间才能使用该报表，请在“系统参数设置”中进行设置!");
        QueryBTN->Enabled = false;
    }        */
}
//---------------------------------------------------------------------------
void __fastcall TBMQFrm::QueryBTNClick(TObject *Sender)
{
	if(!BMBeginDateEdit->Text.IsEmpty()&&!BMEndDateEdit->Text.IsEmpty())
    {
		BeginDatestr = BMBeginDateEdit->Text;
        EndDatestr = BMEndDateEdit->Text;
        CTStr = CTComboBox->Text;
		BMStr = BMComboBox->Text;
		String Allsqlstr = "select sum(SFJE) as allsfje,count(*) as allcount from MXBAK join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='x' and";

        if(BMComboBox->Text != "所有部门"&&!BMComboBox->Text.IsEmpty())
        {
        	Allsqlstr += " CARD_F.BM='";
            Allsqlstr += BMComboBox->Text;
            Allsqlstr += "' and";
        }

        if(CTComboBox->Text != "所有餐厅"&&!CTComboBox->Text.IsEmpty())
        {
            Allsqlstr += " SFJPARAM.STNAME='";
            Allsqlstr += CTComboBox->Text;
            Allsqlstr += "' and SFRQ>='";
            Allsqlstr += BMBeginDateEdit->Text;
            Allsqlstr += " 00:00:00' and SFRQ<='";
            Allsqlstr += BMEndDateEdit->Text;
			Allsqlstr += " 23:59:59'";
			BMADOQ->Close();
            BMADOQ->SQL->Clear();
            BMADOQ->SQL->Add(Allsqlstr);
            BMADOQ->Open();
            ALLZE = BMADOQ->FieldByName("allsfje")->AsFloat;
            ALLCS = BMADOQ->FieldByName("allcount")->AsInteger;
            BMADOQ->Close();
        }
        else
        {
            Allsqlstr += " SFRQ>='";
            Allsqlstr += BeginDatestr;
            Allsqlstr += " 00:00:00' and SFRQ<='";
            Allsqlstr += EndDatestr;
            Allsqlstr += " 23:59:59'";
            BMADOQ->Close();
            BMADOQ->SQL->Clear();
            BMADOQ->SQL->Add(Allsqlstr);
            BMADOQ->Open();
            ALLZE = BMADOQ->FieldByName("allsfje")->AsFloat;
            ALLCS = BMADOQ->FieldByName("allcount")->AsInteger;
            BMADOQ->Close();
        }

        cxTextEdit17->Text = ALLCS;
		cxTextEdit18->Text = "￥" + FloatToStr(ALLZE);
		if(ALLCS)
			cxTextEdit19->Text = "￥" + FloatToStr(ALLZE/ALLCS);
		else
            cxTextEdit19->Text = "￥0";
        cxTextEdit20->Text = "查询";

		String tempsqlstr = "select sum(SFJE) as fcsfje,count(*) as fccount from MXBAK join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH where SFLX='x' and";
        if(BMStr != "所有部门"&&!BMStr.IsEmpty())
        {
        	tempsqlstr += " CARD_F.BM='";
            tempsqlstr += BMStr;
            tempsqlstr += "' and";
        }

        if(CTComboBox->Text!="所有餐厅"&&!CTComboBox->Text.IsEmpty())
		{
            tempsqlstr += " SFJPARAM.STNAME='";
            tempsqlstr += CTComboBox->Text;
            tempsqlstr += "' and SFRQ>='";
            tempsqlstr += BeginDatestr;
            tempsqlstr += " 00:00:00' and SFRQ<='";
            tempsqlstr += EndDatestr;
            tempsqlstr += " 23:59:59' and";
        }
        else
        {
            tempsqlstr += " SFRQ>='";
            tempsqlstr += BeginDatestr;
            tempsqlstr += " 00:00:00' and SFRQ<='";
            tempsqlstr += EndDatestr;
            tempsqlstr += " 23:59:59' and";
        }

        if(CheckBox1->Checked)
        {
            String BFsqlstr = tempsqlstr;
            BFsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            BFsqlstr += BFendtime;
            BFsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            BFsqlstr += BFstarttime;
            BFsqlstr += "')";

            BMADOQ->Close();
            BMADOQ->SQL->Clear();
            BMADOQ->SQL->Add(BFsqlstr);
            BMADOQ->Open();
            BFCS = BMADOQ->FieldByName("fccount")->AsInteger;
            BFZE = BMADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit4->Text = "查询";
            cxTextEdit1->Text = IntToStr(BFCS);
            cxTextEdit2->Text = "￥" + FloatToStr(BFZE);
            if(BFCS)
                cxTextEdit3->Text = "￥" + FloatToStr(BFZE/BFCS);
            else
                cxTextEdit3->Text = "￥0";
        }
        else
        {
            cxTextEdit4->Text = "未查询";
            cxTextEdit1->Text = 0;
            cxTextEdit2->Text = "￥0";
            cxTextEdit3->Text = "￥0";
        }

        if(CheckBox2->Checked)
        {
            String LHsqlstr = tempsqlstr;
            LHsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            LHsqlstr += LHendtime;
            LHsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            LHsqlstr += LHstarttime;
            LHsqlstr += "')";

            BMADOQ->Close();
            BMADOQ->SQL->Clear();
            BMADOQ->SQL->Add(LHsqlstr);
            BMADOQ->Open();
            LHCS = BMADOQ->FieldByName("fccount")->AsInteger;
            LHZE = BMADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit8->Text = "查询";
            cxTextEdit5->Text = IntToStr(LHCS);
            cxTextEdit6->Text = "￥" + FloatToStr(LHZE);
            if(LHCS)
                cxTextEdit7->Text = "￥" + FloatToStr(LHZE/LHCS);
            else
                cxTextEdit7->Text = "￥0";
        }
        else
        {
            cxTextEdit8->Text = "未查询";
            cxTextEdit5->Text = 0;
            cxTextEdit6->Text = "￥0";
            cxTextEdit7->Text = "￥0";
        }

        if(CheckBox3->Checked)
        {
            String SRsqlstr = tempsqlstr;
            SRsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            SRsqlstr += SRendtime;
            SRsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            SRsqlstr += SRstarttime;
            SRsqlstr += "')";

            BMADOQ->Close();
            BMADOQ->SQL->Clear();
            BMADOQ->SQL->Add(SRsqlstr);
            BMADOQ->Open();
            SRCS = BMADOQ->FieldByName("fccount")->AsInteger;
            SRZE = BMADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit12->Text = "查询";
            cxTextEdit9->Text = IntToStr(SRCS);
            cxTextEdit10->Text = "￥" + FloatToStr(SRZE);
            if(SRCS)
                cxTextEdit11->Text = "￥" + FloatToStr(SRZE/SRCS);
            else
                cxTextEdit11->Text = "￥0";
        }
        else
        {
            cxTextEdit12->Text = "未查询";
            cxTextEdit9->Text = 0;
            cxTextEdit10->Text = "￥0";
            cxTextEdit11->Text = "￥0";
        }

        if(CheckBox4->Checked)
        {
            String NTsqlstr = tempsqlstr;
            NTsqlstr += " (convert(varchar(100),MXBAK.SFRQ,108)<='";
            NTsqlstr += NTendtime;
            NTsqlstr += "' and convert(varchar(100),MXBAK.SFRQ,108)>='";
            NTsqlstr += NTstarttime;
            NTsqlstr += "')";

            BMADOQ->Close();
            BMADOQ->SQL->Clear();
            BMADOQ->SQL->Add(NTsqlstr);
            BMADOQ->Open();
            NTCS = BMADOQ->FieldByName("fccount")->AsInteger;
            NTZE = BMADOQ->FieldByName("fcsfje")->AsFloat;
            cxTextEdit16->Text = "查询";
            cxTextEdit13->Text = IntToStr(NTCS);
            cxTextEdit14->Text = "￥" + FloatToStr(NTZE);
            if(NTCS)
                cxTextEdit15->Text = "￥" + FloatToStr(NTZE/NTCS);
            else
                cxTextEdit15->Text = "￥0";
        }
        else
        {
            cxTextEdit16->Text = "未查询";
            cxTextEdit13->Text = 0;
            cxTextEdit14->Text = "￥0";
            cxTextEdit15->Text = "￥0";
        }

        if(BFZE||LHZE||SRZE||NTZE||ALLZE)
        {
            ExportBTN->Enabled = true;
            PreviewBTN->Enabled = true;
        }
    }
    else
    	ShowMessage("必须完整填写查询条件!");
}
//---------------------------------------------------------------------------
void __fastcall TBMQFrm::ExportBTNClick(TObject *Sender)
{
	if(SaveDialog->Execute())
    {
    	ExportBTN->Enabled = false;
        PreviewBTN->Enabled = false;
        if(FileExists(SaveDialog->FileName+".xls"))
        {
            ExportBTN->Enabled = true;
        	PreviewBTN->Enabled = true;
            throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
            return;
        }
        else
        {
            String savename = SaveDialog->FileName;
            savename += ".xls";
            Variant ExcelApp;
            try
            {
                ExcelApp = CreateOleObject("Excel.Application");
            }
            catch(...)
            {
                MessageBox(this->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
                return;
            }

            String Templatepath = GlobalPath + "\\ExportXLSTemplate\\BMTJTemplate.xlt";
            ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", Templatepath.t_str());
            Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");
            Variant ST = WB.OlePropertyGet("Sheets", 1);

            ST.OlePropertyGet("Cells",2,2).OlePropertySet("Value", BMStr.t_str());
            ST.OlePropertyGet("Cells",2,5).OlePropertySet("Value", CTStr.t_str());
            ST.OlePropertyGet("Cells",2,8).OlePropertySet("Value", DateTimeToStr(Now()).t_str());
            ST.OlePropertyGet("Cells",3,2).OlePropertySet("Value", OperatorName.t_str());
            ST.OlePropertyGet("Cells",3,4).OlePropertySet("Value", (BeginDatestr+" 00:00:00").t_str());
            ST.OlePropertyGet("Cells",3,8).OlePropertySet("Value", (EndDatestr+" 23:59:59").t_str());

            ST.OlePropertyGet("Cells",6,2).OlePropertySet("Value", cxTextEdit1->Text.t_str());
            ST.OlePropertyGet("Cells",7,2).OlePropertySet("Value", cxTextEdit2->Text.t_str());
            ST.OlePropertyGet("Cells",8,2).OlePropertySet("Value", cxTextEdit3->Text.t_str());
            ST.OlePropertyGet("Cells",9,2).OlePropertySet("Value", cxTextEdit4->Text.t_str());

            ST.OlePropertyGet("Cells",6,4).OlePropertySet("Value", cxTextEdit5->Text.t_str());
            ST.OlePropertyGet("Cells",7,4).OlePropertySet("Value", cxTextEdit6->Text.t_str());
            ST.OlePropertyGet("Cells",8,4).OlePropertySet("Value", cxTextEdit7->Text.t_str());
            ST.OlePropertyGet("Cells",9,4).OlePropertySet("Value", cxTextEdit8->Text.t_str());

            ST.OlePropertyGet("Cells",6,6).OlePropertySet("Value", cxTextEdit9->Text.t_str());
            ST.OlePropertyGet("Cells",7,6).OlePropertySet("Value", cxTextEdit10->Text.t_str());
            ST.OlePropertyGet("Cells",8,6).OlePropertySet("Value", cxTextEdit11->Text.t_str());
            ST.OlePropertyGet("Cells",9,6).OlePropertySet("Value", cxTextEdit12->Text.t_str());

            ST.OlePropertyGet("Cells",6,8).OlePropertySet("Value", cxTextEdit13->Text.t_str());
            ST.OlePropertyGet("Cells",7,8).OlePropertySet("Value", cxTextEdit14->Text.t_str());
            ST.OlePropertyGet("Cells",8,8).OlePropertySet("Value", cxTextEdit15->Text.t_str());
            ST.OlePropertyGet("Cells",9,8).OlePropertySet("Value", cxTextEdit16->Text.t_str());

            ST.OlePropertyGet("Cells",6,10).OlePropertySet("Value", cxTextEdit17->Text.t_str());
            ST.OlePropertyGet("Cells",7,10).OlePropertySet("Value", cxTextEdit18->Text.t_str());
            ST.OlePropertyGet("Cells",8,10).OlePropertySet("Value", cxTextEdit19->Text.t_str());
            ST.OlePropertyGet("Cells",9,10).OlePropertySet("Value", cxTextEdit20->Text.t_str());

            ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
            WB.OleFunction("SaveAs", savename.t_str());
            ExcelApp.OleFunction("Quit");
            ExcelApp = Unassigned;
            MessageBox(this->Handle, "数据已完成导出！", "Successfully!", MB_OK|MB_ICONINFORMATION);
        }
        ExportBTN->Enabled = true;
        PreviewBTN->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TBMQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\BMTJPreview.fr3";
    frxBMTJReport->LoadFromFile(temppath.t_str(), true);
    ((TfrxMemoView*)frxBMTJReport->FindObject("QSRQM"))->Text = BeginDatestr+" 00:00:00";
    ((TfrxMemoView*)frxBMTJReport->FindObject("JZRQM"))->Text = EndDatestr+" 23:59:59";
    ((TfrxMemoView*)frxBMTJReport->FindObject("CTM"))->Text = CTStr.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("BMM"))->Text = BMStr.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("BBCZYM"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("SCRQM"))->Text = DateTimeToStr(Now()).t_str();

    ((TfrxMemoView*)frxBMTJReport->FindObject("BFCSM"))->Text = cxTextEdit1->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("BFZEM"))->Text = cxTextEdit2->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("BFPJM"))->Text = cxTextEdit3->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("BFBZM"))->Text = cxTextEdit4->Text.t_str();

    ((TfrxMemoView*)frxBMTJReport->FindObject("LHCSM"))->Text = cxTextEdit5->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("LHZEM"))->Text = cxTextEdit6->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("LHPJM"))->Text = cxTextEdit7->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("LHBZM"))->Text = cxTextEdit8->Text.t_str();

    ((TfrxMemoView*)frxBMTJReport->FindObject("SRCSM"))->Text = cxTextEdit9->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("SRZEM"))->Text = cxTextEdit10->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("SRPJM"))->Text = cxTextEdit11->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("SRBZM"))->Text = cxTextEdit12->Text.t_str();

    ((TfrxMemoView*)frxBMTJReport->FindObject("NTCSM"))->Text = cxTextEdit13->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("NTZEM"))->Text = cxTextEdit14->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("NTPJM"))->Text = cxTextEdit15->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("NTBZM"))->Text = cxTextEdit16->Text.t_str();

    ((TfrxMemoView*)frxBMTJReport->FindObject("ZJCSM"))->Text = cxTextEdit17->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("ZJZEM"))->Text = cxTextEdit18->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("ZJPJM"))->Text = cxTextEdit19->Text.t_str();
    ((TfrxMemoView*)frxBMTJReport->FindObject("ZJBZM"))->Text = cxTextEdit20->Text.t_str();

    frxBMTJReport->ShowReport(true);
}
//---------------------------------------------------------------------------
