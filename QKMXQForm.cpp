//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QKMXQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
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
TQKMXQFrm *QKMXQFrm;
//---------------------------------------------------------------------------
__fastcall TQKMXQFrm::TQKMXQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQKMXQFrm::ReadCardInfoBTNClick(TObject *Sender)
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

				QKADOQ->Close();
				QKADOQ->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				QKADOQ->SQL->Add(tmpstr);
				QKADOQ->Open();
				if(!QKADOQ->IsEmpty())
				{
					if(0 != QKADOQ->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						QKADOQ->Close();
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					QKADOQ->Close();
				}
				QKADOQ->Close();

				QKADOQ->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				QKADOQ->SQL->Add(tmpstr);
				QKADOQ->Open();
				if(!QKADOQ->IsEmpty())
				{
					QKBHTextEdit->Text = "";
					QKBMComboBox->Text = "";
					QKCZYComboBox->Text = "";
					QKKHTextEdit->Text = tmpkh;
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					QKADOQ->Close();
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
void __fastcall TQKMXQFrm::QueryBTNClick(TObject *Sender)
{
	if(!QKBeginDateEdit->Text.IsEmpty()&&!QKEndDateEdit->Text.IsEmpty())
    {
		String MXsqlstr = "select CK.*,CARD_F.BM as BUMEN,CARD_F.BZ as BANBIE,CARD_F.ZB as ZUBIE,CARD_F.XM as NAME from CK join CARD_F on CK.bh=CARD_F.BH and CK.kh=CARD_F.KH where ";
		String SUMsqlstr = "select count(*) as qcs,sum(ckje) as allck from CK join CARD_F on CK.bh=CARD_F.BH and CK.kh=CARD_F.KH where ";
		String sqlstr = "sfrq>'";
		sqlstr += QKBeginDateEdit->Text;
        sqlstr += " 00:00:00";
		sqlstr += "' and sfrq<'";
		sqlstr += QKEndDateEdit->Text;
		sqlstr += " 23:59:59'";
		if(!QKKHTextEdit->Text.IsEmpty())
		{
			sqlstr += " and CK.kh=";
			sqlstr += QKKHTextEdit->Text.Trim();
		}
		if(!QKBHTextEdit->Text.IsEmpty())
		{
			sqlstr += " and CK.bh='";
			sqlstr += QKBHTextEdit->Text.Trim();
			sqlstr += "'";
		}
		if(!QKBMComboBox->Text.IsEmpty())
		{
			sqlstr += " and CARD_F.BM='";
			sqlstr += QKBMComboBox->Text.Trim();
			sqlstr += "'";
		}
		if(!QKCZYComboBox->Text.IsEmpty())
		{
			sqlstr += " and CZY='";
			sqlstr += QKCZYComboBox->Text.Trim();
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
			sflxstr += "'d'";
		}
		if(cxCheckBox2->Checked)
		{
			if(!sflxstr.IsEmpty())
				sflxstr += ",'T'";
			else
				sflxstr += "'T'";
		}


        if(sflxstr.IsEmpty())
        	sflxstr += "'d'";

		if(!sflxstr.IsEmpty())
        {
            sqlstr += " and sflx in (";
            sqlstr += sflxstr;
            sqlstr += ")";
        }

        MXsqlstr += sqlstr;
        SUMsqlstr += sqlstr;

        QKADOQ->Close();
        QKADOQ->SQL->Clear();
        QKADOQ->SQL->Add(MXsqlstr);
        QKADOQ->Open();
        if(!QKADOQ->IsEmpty())
        {
        	if(QKADOQ->RecordCount > 65500)
            {
            	QKADOQ->Close();
				ShowMessage("符合该查询条件的记录条数大于65530条，无法正常显示与导出，请修改查询条件!");
                return;
            }
            QKADOQ->Close();
            QKADOQ->SQL->Clear();
            QKADOQ->SQL->Add(SUMsqlstr);
            QKADOQ->Open();
			QKMXShowFrm->AllQKTextEdit->Text = QKADOQ->FieldByName("allck")->AsString.Trim();
			QKMXShowFrm->AllQCSTextEdit->Text = QKADOQ->FieldByName("qcs")->AsInteger;
            QKADOQ->Close();

            QKMXShowFrm->BeginDateTimeStr = QKBeginDateEdit->Text + " 00:00:00";
            QKMXShowFrm->EndDateTimeStr = QKEndDateEdit->Text + " 23:59:59";
            QKMXShowFrm->KHStr = QKKHTextEdit->Text;
            QKMXShowFrm->BHStr = QKBHTextEdit->Text;
            QKMXShowFrm->BMStr = QKBMComboBox->Text;
            QKMXShowFrm->BBStr = BBComboBox->Text;
            QKMXShowFrm->ZBStr = ZBComboBox->Text;
            QKMXShowFrm->QKCZYStr = QKCZYComboBox->Text;
            QKMXShowFrm->DKQQKTag = cxCheckBox1->Checked;
            QKMXShowFrm->TKQKTag = cxCheckBox2->Checked;
            QKMXShowFrm->CZYStr = OperatorName;
            QKMXShowFrm->QKMXExportProgressBar->Position = 0;

            QKMXShowFrm->QKMXADOQuery->Close();
            QKMXShowFrm->QKMXADOQuery->SQL->Clear();
            QKMXShowFrm->QKMXADOQuery->SQL->Add(MXsqlstr);
            QKMXShowFrm->ShowModal();
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
void __fastcall TQKMXQFrm::QKKHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TQKMXQFrm::QKBHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TQKMXQFrm::QKBMComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TQKMXQFrm::QKCZYComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TQKMXQFrm::FormShow(TObject *Sender)
{
//	QKBeginDateEdit->Text = "";
//	QKEndDateEdit->Text = "";
	QKBeginDateEdit->Date = Date();
    QKEndDateEdit->Date = Date();
	QKKHTextEdit->Text = "";
	QKBHTextEdit->Text = "";
	QKBMComboBox->Properties->Items->Clear();
	QKCZYComboBox->Properties->Items->Clear();

	QKADOQ->Close();
	QKADOQ->SQL->Clear();
	QKADOQ->SQL->Add("select * from BUMEN");
	QKADOQ->Open();
	if(!QKADOQ->IsEmpty())
	{
		QKADOQ->First();
		while(!QKADOQ->Eof)
		{
			QKBMComboBox->Properties->Items->Add(QKADOQ->FieldByName("BUMEN")->AsString.Trim());
			QKADOQ->Next();
        }
	}
	QKADOQ->Close();
	QKADOQ->SQL->Clear();
	QKADOQ->SQL->Add("select * from SYSUSER");
	QKADOQ->Open();
	if(!QKADOQ->IsEmpty())
	{
		QKADOQ->First();
		while(!QKADOQ->Eof)
		{
			QKCZYComboBox->Properties->Items->Add(QKADOQ->FieldByName("USERNAME")->AsString.Trim());
			QKADOQ->Next();
        }
	}
	QKADOQ->Close();

	QKBMComboBox->ItemIndex = -1;
	QKCZYComboBox->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TQKMXQFrm::QKBMComboBoxPropertiesChange(TObject *Sender)
{
//	BBComboBox->Properties->Items->Clear();
    BBComboBox->Text = "";
//    ZBComboBox->Properties->Items->Clear();
	ZBComboBox->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TQKMXQFrm::BBComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TQKMXQFrm::ZBComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TQKMXQFrm::BBComboBoxEnter(TObject *Sender)
{
	if(!QKBMComboBox->Text.IsEmpty()&&(QKBMComboBox->Text != "所有部门"))
	{
		BBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from BANBIE where BUMEN='";
        sqlstr += QKBMComboBox->Text;
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

void __fastcall TQKMXQFrm::ZBComboBoxEnter(TObject *Sender)
{
	if(!QKBMComboBox->Text.IsEmpty()&&(QKBMComboBox->Text != "所有部门")&&!BBComboBox->Text.IsEmpty())
	{
		ZBComboBox->Properties->Items->Clear();
        String sqlstr = "select * from ZUBIE where BUMEN='";;
        sqlstr += QKBMComboBox->Text;
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

