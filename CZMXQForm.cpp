//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CZMXQForm.h"
#include "ReChargePosMXQueryForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"
TCZMXQFrm *CZMXQFrm;
//---------------------------------------------------------------------------
__fastcall TCZMXQFrm::TCZMXQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::CZKHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::CZBHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::CZBMComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::CZCZYComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::FormShow(TObject *Sender)
{
	CZBeginDateEdit->Date = Date();
	CZEndDateEdit->Date = Date();
//	CZBeginDateEdit->Text = "";
//	CZEndDateEdit->Text = "";
	CZKHTextEdit->Text = "";
	CZBHTextEdit->Text = "";
	CZBMComboBox->Properties->Items->Clear();
	CZCZYComboBox->Properties->Items->Clear();

	CKADOQ->Close();
	CKADOQ->SQL->Clear();
	CKADOQ->SQL->Add("select * from BUMEN");
	CKADOQ->Open();
	if(!CKADOQ->IsEmpty())
	{
		CKADOQ->First();
		while(!CKADOQ->Eof)
		{
			CZBMComboBox->Properties->Items->Add(CKADOQ->FieldByName("BUMEN")->AsString.Trim());
			CKADOQ->Next();
        }
	}
	CKADOQ->Close();
	CKADOQ->SQL->Clear();
	CKADOQ->SQL->Add("select * from SYSUSER");
	CKADOQ->Open();
	if(!CKADOQ->IsEmpty())
	{
		CKADOQ->First();
		while(!CKADOQ->Eof)
		{
			CZCZYComboBox->Properties->Items->Add(CKADOQ->FieldByName("USERNAME")->AsString.Trim());
			CKADOQ->Next();
        }
	}
	CKADOQ->Close();

	CZBMComboBox->ItemIndex = -1;
	CZCZYComboBox->ItemIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::ReadCardInfoBTNClick(TObject *Sender)
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

				CKADOQ->Close();
				CKADOQ->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				CKADOQ->SQL->Add(tmpstr);
				CKADOQ->Open();
				if(!CKADOQ->IsEmpty())
				{
					if(0 != CKADOQ->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						CKADOQ->Close();
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					CKADOQ->Close();
				}
				CKADOQ->Close();

				CKADOQ->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				CKADOQ->SQL->Add(tmpstr);
				CKADOQ->Open();
				if(!CKADOQ->IsEmpty())
				{
					CZBHTextEdit->Text = "";
					CZBMComboBox->Text = "";
					CZCZYComboBox->Text = "";
					CZKHTextEdit->Text = tmpkh;
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					CKADOQ->Close();
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
void __fastcall TCZMXQFrm::QueryBTNClick(TObject *Sender)
{
	cxButton1->Enabled = false;
	if(!CZBeginDateEdit->Text.IsEmpty()&&!CZEndDateEdit->Text.IsEmpty())
	{
		String MXsqlstr = "select CK.*,CARD_F.BM as BUMEN,CARD_F.BZ as BANBIE,CARD_F.ZB as ZUBIE,CARD_F.XM as NAME from CK join CARD_F on CK.bh=CARD_F.BH and CK.kh=CARD_F.KH where ";
		String SUMsqlstr = "select sum(ckje) as allck from CK join CARD_F on CK.bh=CARD_F.BH and CK.kh=CARD_F.KH where ";
		String sqlstr = "sfrq>'";
		sqlstr += CZBeginDateEdit->Text;
        sqlstr += " 00:00:00";
		sqlstr += "' and sfrq<'";
		sqlstr += CZEndDateEdit->Text;
		sqlstr += " 23:59:59'";
		if(!CZKHTextEdit->Text.IsEmpty())
		{
			sqlstr += " and CK.kh=";
			sqlstr += CZKHTextEdit->Text.Trim();
		}
		if(!CZBHTextEdit->Text.IsEmpty())
		{
			sqlstr += " and CK.bh='";
			sqlstr += CZBHTextEdit->Text.Trim();
			sqlstr += "'";
		}
		if(!CZBMComboBox->Text.IsEmpty())
		{
			sqlstr += " and CARD_F.BM='";
			sqlstr += CZBMComboBox->Text.Trim();
			sqlstr += "'";
		}
		if(!CZCZYComboBox->Text.IsEmpty())
		{
			sqlstr += " and CZY='";
			sqlstr += CZCZYComboBox->Text.Trim();
			sqlstr += "'";
		}
        if(!BBComboBox->Text.IsEmpty())
        {
            sqlstr += " and BZ='";
            sqlstr += BBComboBox->Text;
            sqlstr += "'";
        }

        if(!ZBComboBox->Text.IsEmpty())
        {
            sqlstr += " and ZB='";
            sqlstr += ZBComboBox->Text;
            sqlstr += "'";
        }

		String sflxstr = "";
		if(cxCheckBox1->Checked)
		{
			sflxstr += "'a'";
		}
		if(cxCheckBox2->Checked)
		{
			if(!sflxstr.IsEmpty())
				sflxstr += ",'I'";
			else
				sflxstr += "'I'";
		}
		if(cxCheckBox3->Checked)
		{
			if(!sflxstr.IsEmpty())
				sflxstr += ",'K'";
			else
				sflxstr += "'K'";
		}

        if(sflxstr.IsEmpty())
        	sflxstr += "'a'";

		if(!sflxstr.IsEmpty())
        {
            sqlstr += " and sflx in (";
            sqlstr += sflxstr;
            sqlstr += ")";
        }

//        sqlstr += " group by CK.kh order by CK.kh";

		MXsqlstr += sqlstr;
		MXsqlstr += " order by sfrq desc";
        SUMsqlstr += sqlstr;
		CKADOQ->Close();
        CKADOQ->SQL->Clear();
        CKADOQ->SQL->Add(MXsqlstr);
        CKADOQ->Open();
        if(!CKADOQ->IsEmpty())
        {
        	if(CKADOQ->RecordCount > 65500)
            {
            	CKADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示与导出，请修改查询条件!");
				cxButton1->Enabled = true;
				return;
            }
            CKADOQ->Close();
            CKADOQ->SQL->Clear();
            CKADOQ->SQL->Add(SUMsqlstr);
            CKADOQ->Open();
            CZMXShowFrm->AllCKTextEdit->Text = CKADOQ->FieldByName("allck")->AsString.Trim();
            CKADOQ->Close();

            CZMXShowFrm->BeginDateTimeStr = CZBeginDateEdit->Text + " 00:00:00";
            CZMXShowFrm->EndDateTimeStr = CZEndDateEdit->Text + " 23:59:59";
            CZMXShowFrm->KHStr = CZKHTextEdit->Text;
            CZMXShowFrm->BHStr = CZBHTextEdit->Text;
            CZMXShowFrm->BMStr = CZBMComboBox->Text;
            CZMXShowFrm->BBStr = BBComboBox->Text;
            CZMXShowFrm->ZBStr = ZBComboBox->Text;
            CZMXShowFrm->CZCZYStr = CZCZYComboBox->Text;
            CZMXShowFrm->DKQCZTag = cxCheckBox1->Checked;
            CZMXShowFrm->POSCZTag = cxCheckBox2->Checked;
            CZMXShowFrm->FKCZTag = cxCheckBox3->Checked;
            CZMXShowFrm->CZYStr = OperatorName;
            CZMXShowFrm->CZMXExportProgressBar->Position = 0;

            CZMXShowFrm->CZMXADOQuery->Close();
            CZMXShowFrm->CZMXADOQuery->SQL->Clear();
            CZMXShowFrm->CZMXADOQuery->SQL->Add(MXsqlstr);
            CZMXShowFrm->ShowModal();
        }
        else
        	ShowMessage("符合该查询条件的记录条数为0!");
	}
	else
	{
        ShowMessage("必须填写查询起止日期!");
	}
	cxButton1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::CZEndDateEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TCZMXQFrm::CZBeginDateEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TCZMXQFrm::cxButton1Click(TObject *Sender)
{
	ReChargePosForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TCZMXQFrm::CZBMComboBoxPropertiesChange(TObject *Sender)
{
//	BBComboBox->Properties->Items->Clear();
    BBComboBox->Text = "";
//    ZBComboBox->Properties->Items->Clear();
	ZBComboBox->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TCZMXQFrm::BBComboBoxEnter(TObject *Sender)
{
	if(!CZBMComboBox->Text.IsEmpty()&&(CZBMComboBox->Text != "所有部门"))
	{
		BBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from BANBIE where BUMEN='";
        sqlstr += CZBMComboBox->Text;
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

void __fastcall TCZMXQFrm::BBComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TCZMXQFrm::ZBComboBoxEnter(TObject *Sender)
{
	if(!CZBMComboBox->Text.IsEmpty()&&(CZBMComboBox->Text != "所有部门")&&!BBComboBox->Text.IsEmpty())
	{
		ZBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from ZUBIE where BUMEN='";;
        sqlstr += CZBMComboBox->Text;
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

