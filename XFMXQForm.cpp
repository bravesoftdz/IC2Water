//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XFMXQForm.h"
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
#pragma resource "*.dfm"
TXFMXQFrm *XFMXQFrm;
//---------------------------------------------------------------------------
__fastcall TXFMXQFrm::TXFMXQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TXFMXQFrm::FormShow(TObject *Sender)
{
//	XFBeginDateEdit->Text = "";
//  XFEndDateEdit->Text = "";
	XFBeginDateEdit->Date = Date();
    XFEndDateEdit->Date = Date();
    XFKHTextEdit->Text = "";
    XFBHTextEdit->Text = "";
    XFBMComboBox->Properties->Items->Clear();
    XFXMTextEdit->Text = "";
    XFJHTextEdit->Text = "";
    XFCTComboBox->Properties->Items->Clear();

	XFADOQ->Close();
    XFADOQ->SQL->Clear();
    XFADOQ->SQL->Add("select * from BUMEN");
    XFADOQ->Open();
    if(!XFADOQ->IsEmpty())
    {
    	XFADOQ->First();
        while(!XFADOQ->Eof)
        {
            XFBMComboBox->Properties->Items->Add(XFADOQ->FieldByName("BUMEN")->AsString.Trim());
            XFADOQ->Next();
        }
    }
    XFADOQ->Close();
    XFADOQ->SQL->Clear();
    XFADOQ->SQL->Add("select * from STNAME");
    XFADOQ->Open();
    if(!XFADOQ->IsEmpty())
    {
        XFADOQ->First();
        while(!XFADOQ->Eof)
        {
            XFCTComboBox->Properties->Items->Add(XFADOQ->FieldByName("STNAME")->AsString.Trim());
            XFADOQ->Next();
        }
    }
    XFADOQ->Close();
    XFBMComboBox->ItemIndex = -1;
    XFCTComboBox->ItemIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall TXFMXQFrm::XFCTComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TXFMXQFrm::XFBHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TXFMXQFrm::ReadCardInfoBTNClick(TObject *Sender)
{
	WORD status;
	int tmpbalance;
	int tmpkh,tmpsycs;
	double tmpintye;
	double tmpye;
	unsigned char keymode,secnum,Delayms,mode;
	unsigned char key[6];
	unsigned char dwmm[6];
	unsigned char daytime[4];
	unsigned char kh[4];
	unsigned char balance[4];
	unsigned char cardtype[1];
	unsigned char czmm[3];
	unsigned char synum[3];
//	unsigned char readcomno[5] = "";

	Delayms = 0x00;
	keymode = CARDPasswordEdition;//0x03;
	secnum = UsingSecNUM;//0x01;

	key[0] = CARDPassword[0];
	key[1] = CARDPassword[1];
	key[2] = CARDPassword[2];
	key[3] = CARDPassword[3];
	key[4] = CARDPassword[4];
	key[5] = CARDPassword[5];

	if(LoadHModule)
	{
		beepofreaddll(readcomno, '10');
		if(readwatercardinfo)//readcardinfo)
		{
		//	status = readcardinfo(readcomno,keymode,secnum,key,kh,balance,
		//						dwmm,synum,daytime,cardtype,czmm,Delayms);

        	status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,
            							dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！");
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于192000或等于0！");
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
			}
			else if (6 == status)
			{
				ShowMessage("卡结构不对！");
			}
			else if (10 == status)
			{
				ShowMessage("卡结构不对！");
			}
			else if (0 != status)
			{
				ShowMessage("该卡未发行或已退卡！");
			}
			else
			{
				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

				XFADOQ->Close();
				XFADOQ->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				XFADOQ->SQL->Add(tmpstr);
				XFADOQ->Open();
				if(!XFADOQ->IsEmpty())
				{
					if(0 != XFADOQ->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						XFADOQ->Close();
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					XFADOQ->Close();
				}
				XFADOQ->Close();

				XFADOQ->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				XFADOQ->SQL->Add(tmpstr);
				XFADOQ->Open();
				if(!XFADOQ->IsEmpty())
				{
					XFBHTextEdit->Text = "";
					XFBMComboBox->Text = "";
                    XFXMTextEdit->Text = "";
					XFJHTextEdit->Text = "";
                    XFCTComboBox->Text = "";
					XFKHTextEdit->Text = tmpkh;
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					XFADOQ->Close();
				}
			}
		}
		else
		{
            ShowMessage("读卡函数加载失败！");
		}
	}
	else
		ShowMessage("加载读写卡动态链接库失败！");
}
//---------------------------------------------------------------------------
void __fastcall TXFMXQFrm::QueryBTNClick(TObject *Sender)
{
	if(!XFBeginDateEdit->Text.IsEmpty()&&!XFEndDateEdit->Text.IsEmpty())
	{
		String displaysqlstr = "select TOP 1000 MXBAK.*,CARD_F.XM as UName,CARD_F.BM as BUMEN,CARD_F.BZ as BANBIE,CARD_F.ZB as ZUBIE,CARD_F.ZW as ZW,SFJPARAM.STNAME as CTNAME from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x'";
		String MXsqlstr = "select MXBAK.*,CARD_F.XM as UName,CARD_F.BM as BUMEN,CARD_F.BZ as BANBIE,CARD_F.ZB as ZUBIE,CARD_F.ZW as ZW,SFJPARAM.STNAME as CTNAME from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x'";
		String SUMsqlstr = "select SUM(MXBAK.SFJE) as SFZE from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x'";
		String Allcssqlstr = "select count(*) as allcs from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH and MXBAK.KH=CARD_F.KH join SFJPARAM on MXBAK.JYNO=SFJPARAM.JH where SFLX='x'";
		String sqlstr = " and SFRQ>'";
        sqlstr += XFBeginDateEdit->Text;
        sqlstr += " 00:00:00' and SFRQ<'";
        sqlstr += XFEndDateEdit->Text;
        sqlstr += " 23:59:59'";
        if(!XFKHTextEdit->Text.IsEmpty())
        {
            sqlstr += " and MXBAK.KH=";
            sqlstr += XFKHTextEdit->Text;
        }
        if(!XFBHTextEdit->Text.IsEmpty())
        {
            sqlstr += " and MXBAK.BH='";
            sqlstr += XFBHTextEdit->Text;
            sqlstr += "'";
        }
        if(!XFBMComboBox->Text.IsEmpty())
        {
			sqlstr += " and CARD_F.BM='";
            sqlstr += XFBMComboBox->Text;
            sqlstr += "'";
        }
        if(!XFXMTextEdit->Text.IsEmpty())
        {
            sqlstr += " and CARD_F.XM='";
            sqlstr += XFXMTextEdit->Text;
            sqlstr += "'";
        }
        if(!XFJHTextEdit->Text.IsEmpty())
        {
            sqlstr += " and JYNO=";
            sqlstr += XFJHTextEdit->Text;
        }
        if(!XFCTComboBox->Text.IsEmpty())
        {
            sqlstr += " and SFJPARAM.STNAME='";
            sqlstr += XFCTComboBox->Text;
            sqlstr += "'";
        }
        if(!BBComboBox->Text.IsEmpty())
        {
            sqlstr += " and CARD_F.BZ='";
            sqlstr += BBComboBox->Text;
            sqlstr += "'";
        }

        if(!ZBComboBox->Text.IsEmpty())
        {
            sqlstr += " and CARD_F.ZB='";
            sqlstr += ZBComboBox->Text;
            sqlstr += "'";
        }

		displaysqlstr += sqlstr;
        MXsqlstr += sqlstr;
		SUMsqlstr += sqlstr;
		Allcssqlstr += sqlstr;
        XFADOQ->Close();
        XFADOQ->SQL->Clear();
		XFADOQ->SQL->Add(MXsqlstr);
        XFADOQ->Open();
        if(!XFADOQ->IsEmpty())
        {
		/*	if(XFADOQ->RecordCount > 65500)
            {
            	XFADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示与导出，请修改查询条件!");
                return;
            }    */
            XFADOQ->Close();
            XFADOQ->SQL->Clear();
            XFADOQ->SQL->Add(SUMsqlstr);
			XFADOQ->Open();
			XFMXShowFrm->AllXFTextEdit->Text = XFADOQ->FieldByName("SFZE")->AsString.Trim();
			XFADOQ->Close();

			XFADOQ->Close();
			XFADOQ->SQL->Clear();
			XFADOQ->SQL->Add(Allcssqlstr);
			XFADOQ->Open();
			XFMXShowFrm->AllCSTextEdit->Text = XFADOQ->FieldByName("allcs")->AsInteger;
			XFADOQ->Close();

            XFMXShowFrm->BeginDateTimeStr = XFBeginDateEdit->Text + " 00:00:00";
            XFMXShowFrm->EndDateTimeStr = XFEndDateEdit->Text + " 23:59:59";
            XFMXShowFrm->KHStr = XFKHTextEdit->Text;
            XFMXShowFrm->BHStr = XFBHTextEdit->Text;
            XFMXShowFrm->BMStr = XFBMComboBox->Text;
            XFMXShowFrm->BBStr = BBComboBox->Text;
            XFMXShowFrm->ZBStr = ZBComboBox->Text;
            XFMXShowFrm->XMStr = XFXMTextEdit->Text;
            XFMXShowFrm->JHStr = XFJHTextEdit->Text;
            XFMXShowFrm->CTStr = XFCTComboBox->Text;
            XFMXShowFrm->CZYStr = OperatorName;
            XFMXShowFrm->XFMXExportProgressBar->Position = 0;

			XFMXShowFrm->allsqlstr = MXsqlstr;
            XFMXShowFrm->XFMXADOQuery->Close();
            XFMXShowFrm->XFMXADOQuery->SQL->Clear();
			XFMXShowFrm->XFMXADOQuery->SQL->Add(displaysqlstr);
            XFMXShowFrm->ShowModal();
        }
        else
        	ShowMessage("符合该查询条件的记录条数为0!");
    }
    else
	{
        ShowMessage("必须填写查询起止日期!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TXFMXQFrm::XFBMComboBoxPropertiesChange(TObject *Sender)
{
//	BBComboBox->Properties->Items->Clear();
    BBComboBox->Text = "";
//    ZBComboBox->Properties->Items->Clear();
	ZBComboBox->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TXFMXQFrm::BBComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TXFMXQFrm::ZBComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TXFMXQFrm::BBComboBoxEnter(TObject *Sender)
{
	if(!XFBMComboBox->Text.IsEmpty()&&(XFBMComboBox->Text != "所有部门"))
	{
		BBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from BANBIE where BUMEN='";
        sqlstr += XFBMComboBox->Text;
        sqlstr += "'";
		QADOQ->Close();
        QADOQ->SQL->Clear();
        QADOQ->SQL->Add(sqlstr);
        QADOQ->Open();
        if(!QADOQ->IsEmpty())
		{
            QADOQ->First();
            while(!QADOQ->Eof)
            {
                BBComboBox->Properties->Items->Add(QADOQ->FieldByName("BANBIE")->AsString.Trim());
                QADOQ->Next();
			}
			BBComboBox->Properties->Items->Add("所有班别");
        }
        QADOQ->Close();
	}
	else
	{
        BBComboBox->Properties->Items->Clear();
    }
}
//---------------------------------------------------------------------------

void __fastcall TXFMXQFrm::ZBComboBoxEnter(TObject *Sender)
{
	if(!XFBMComboBox->Text.IsEmpty()&&(XFBMComboBox->Text != "所有部门")&&!BBComboBox->Text.IsEmpty())
	{
		ZBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from ZUBIE where BUMEN='";;
        sqlstr += XFBMComboBox->Text;
        sqlstr += "' and BANBIE='";
        sqlstr += BBComboBox->Text;
        sqlstr += "'";
        QADOQ->Close();
        QADOQ->SQL->Clear();
        QADOQ->SQL->Add(sqlstr);
        QADOQ->Open();
        if(!QADOQ->IsEmpty())
		{
			QADOQ->First();
            while(!QADOQ->Eof)
            {
                ZBComboBox->Properties->Items->Add(QADOQ->FieldByName("ZUBIE")->AsString.Trim());
                QADOQ->Next();
			}
			ZBComboBox->Properties->Items->Add("所有组别");
        }
        QADOQ->Close();
	}
	else
	{
        ZBComboBox->Properties->Items->Clear();
    }
}
//---------------------------------------------------------------------------

