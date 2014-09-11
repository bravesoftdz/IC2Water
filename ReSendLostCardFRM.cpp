//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReSendLostCardFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
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
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
TResendLostCardnewFRM *ResendLostCardnewFRM;
//---------------------------------------------------------------------------
__fastcall TResendLostCardnewFRM::TResendLostCardnewFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxButton4Click(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery2->Close();
	InDatabaseADOQuery->Close();
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxRadioButton1Click(TObject *Sender)
{
	cxTextEdit1->Enabled = true;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = false;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = false;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxRadioButton2Click(TObject *Sender)
{
	cxTextEdit1->Enabled = false;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = true;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = false;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = false;
	cxTextEdit4->Text = "";
}

//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxRadioButton3Click(TObject *Sender)
{
	cxTextEdit1->Enabled = false;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = true;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = false;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxRadioButton4Click(TObject *Sender)
{
	cxTextEdit1->Enabled = false;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = false;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = true;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxButton1Click(TObject *Sender)
{
	int tag = 0;
	int usingtag = -1;

	String sql = "select * from CARD where ";
	if(!cxTextEdit1->Text.IsEmpty())
	{
		sql += "BH='";
		sql += cxTextEdit1->Text;
		sql += "'";
		tag = 1;
	}
	if(!cxTextEdit2->Text.IsEmpty())
	{
		sql += "KH=";
		sql += StrToInt(cxTextEdit2->Text);
		tag = 2;
	}
	if(!cxTextEdit3->Text.IsEmpty())
	{
		sql += "XM='";
		sql += cxTextEdit3->Text;
		sql += "'";
		tag = 3;
	}
	if(!cxTextEdit4->Text.IsEmpty())
	{
		sql += "SFZH='";
		sql += cxTextEdit4->Text;
		sql += "'";
		tag = 4;
	}

	if(0 == cxRadioGroup1->ItemIndex)
	{
		sql += " and ZT='发卡'";
		usingtag = 0;
	}
	else if(1 == cxRadioGroup1->ItemIndex)
	{
		sql += " and ZT='挂失'";
		usingtag = 1;
    }

	if(0 != tag)
	{
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(sql);
		ADOQuery1->Open();
		if(!ADOQuery1->IsEmpty())
		{
			InDatabaseADOQuery->Close();
			InDatabaseADOQuery->SQL->Clear();
			String findkhstr = "select max(KH) as minkh from KZT where GS='0' and SY = 'N' and KH>0";
			InDatabaseADOQuery->SQL->Add(findkhstr);
			InDatabaseADOQuery->Open();
			if(!InDatabaseADOQuery->IsEmpty())
				cxTextEdit18->Text = InDatabaseADOQuery->FieldByName("minkh")->AsInteger;
			InDatabaseADOQuery->Close();

			if(0 == usingtag)
			{
				ShowMessage("此卡未挂失，必须先挂失!");
				return;
            }

			if(1 == usingtag)
                cxButton3->Enabled = true;

			if(ADOQuery1->RecordCount > 1)
			{
				NextBTN->Enabled = true;
				NextBTN->Visible = true;

				ADOQuery1->First();
				cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
				cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
				cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
				cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
				cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
				cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
				cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
				cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

				cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
				cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
				cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
				cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
				cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
				cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
			}
			else if(1 == ADOQuery1->RecordCount)
			{
				NextBTN->Enabled = false;
				NextBTN->Visible = false;

				cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
				cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
				cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
				cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
				cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
				cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
				cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
				cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

				cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
				cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
				cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
				cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
				cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
				cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
			}
		}
		else
		{
			sql = "select * from CARD where ";
			if(!cxTextEdit1->Text.IsEmpty())
			{
				sql += "BH='";
				sql += cxTextEdit1->Text;
				sql += "'";
				tag = 1;
			}
			if(!cxTextEdit2->Text.IsEmpty())
			{
				sql += "KH=";
				sql += StrToInt(cxTextEdit2->Text);
				tag = 2;
			}
			if(!cxTextEdit3->Text.IsEmpty())
			{
				sql += "XM='";
				sql += cxTextEdit3->Text;
				sql += "'";
				tag = 3;
			}
			if(!cxTextEdit4->Text.IsEmpty())
			{
				sql += "SFZH='";
				sql += cxTextEdit4->Text;
				sql += "'";
				tag = 4;
			}

			int checktag = cxRadioGroup1->ItemIndex;
			if(0 == checktag)
			{
				sql += " and ZT='挂失'";
				cxRadioGroup1->ItemIndex = 1;
				usingtag = 1;
			}
			else if(1 == checktag)
			{
				sql += " and ZT='发卡'";
				cxRadioGroup1->ItemIndex = 0;
				usingtag = 0;
			}

			if(0 != tag)
			{
				ADOQuery1->Close();
				ADOQuery1->SQL->Clear();
				ADOQuery1->SQL->Add(sql);
				ADOQuery1->Open();
				if(!ADOQuery1->IsEmpty())
				{
					InDatabaseADOQuery->Close();
					InDatabaseADOQuery->SQL->Clear();
					String findkhstr = "select max(KH) as minkh from KZT where GS='0' and SY = 'N' and KH>0";
					InDatabaseADOQuery->SQL->Add(findkhstr);
					InDatabaseADOQuery->Open();
					if(!InDatabaseADOQuery->IsEmpty())
						cxTextEdit18->Text = InDatabaseADOQuery->FieldByName("minkh")->AsInteger;
					InDatabaseADOQuery->Close();

					if(0 == usingtag)
					{
						ShowMessage("此卡未挂失，必须先挂失!");
						return;
					}

					if(1 == usingtag)
						cxButton3->Enabled = true;

					if(ADOQuery1->RecordCount > 1)
					{
						NextBTN->Enabled = true;
						NextBTN->Visible = true;

						ADOQuery1->First();
						cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
						cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
						cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
						cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
						cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
						cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
						cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
						cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

						cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
						cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
						cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
						cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
						cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
						cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
					}
					else if(1 == ADOQuery1->RecordCount)
					{
						NextBTN->Enabled = false;
						NextBTN->Visible = false;

						cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
						cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
						cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
						cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
						cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
						cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
						cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
						cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

						cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
						cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
						cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
						cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
						cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
						cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
					}
				}
				else
				{
                    ShowMessage("没有符合查询条件的卡片!");
                }
			}
		}
	}
	else
	{
        ShowMessage("请输入查询条件!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::NextBTNClick(TObject *Sender)
{
	if(!ADOQuery1->Eof)
	{
		ADOQuery1->Next();
		cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
		cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
		cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
		cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
		cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
		cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
		cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
		cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

		cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
		cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
		cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
		cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
		cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
		cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
    }
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxButton2Click(TObject *Sender)
{
	enableGS = false;
	int kh = StrToInt(cxTextEdit14->Text);
	String sql = "select * from CARD where BH='";
	sql = sql + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("ZT")->AsString = "挂失";
		InDatabaseADOQuery->Post();
	}
    else
    {

    }

	sql = "select * from CARD_F where BH='" + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("ZT")->AsString = "挂失";
		InDatabaseADOQuery->Post();
	}
	else
		ShowMessage("此卡信息不在CARD_F表中，请确认！");

	sql = "select * from KZT where BH='" + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("GS")->AsInteger = 1;
		InDatabaseADOQuery->Post();
	}
	else
		ShowMessage("此卡信息不在KZT表中，请确认！");

	sql = "insert into GS values(:BH,:KH,:GSRQ,:USERNAME)";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	InDatabaseADOQuery->Parameters->ParamByName("KH")->Value = kh;
	InDatabaseADOQuery->Parameters->ParamByName("GSRQ")->Value = DateToStr(Date());
	InDatabaseADOQuery->Parameters->ParamByName("USERNAME")->Value = OperatorName;
	InDatabaseADOQuery->ExecSQL();

	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	sql = "select * from SFJPARAM";
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		int pos[2000];
		int port[2000];
		int i = 0;
		InDatabaseADOQuery->First();
		while(!InDatabaseADOQuery->Eof)
		{
			pos[i] = InDatabaseADOQuery->FieldByName("JH")->AsInteger;
			port[i] = InDatabaseADOQuery->FieldByName("SFJPORT")->AsInteger;
			i++;
			InDatabaseADOQuery->Next();
		}
		int posnum = i;

		InDatabaseADOQuery->Close();
		InDatabaseADOQuery->SQL->Clear();
		sql = "delete from CMDLIST where PARA=";
        sql += kh;
		sql += " and status=0";
		InDatabaseADOQuery->SQL->Add(sql);
		InDatabaseADOQuery->ExecSQL();
		InDatabaseADOQuery->Close();

		InDatabaseADOQuery->SQL->Clear();
		sql = "insert into CMDLIST values(:SFJPORT,:SFJD,:CMD,:PARA,:STATUS,:SENDTIME)";
		InDatabaseADOQuery->SQL->Add(sql);
		for(i = 0; i < posnum; i++)
		{
			InDatabaseADOQuery->Parameters->ParamByName("SFJPORT")->Value = port[i];
			InDatabaseADOQuery->Parameters->ParamByName("SFJD")->Value = pos[i];
			InDatabaseADOQuery->Parameters->ParamByName("CMD")->Value = 1;
			InDatabaseADOQuery->Parameters->ParamByName("PARA")->Value = kh;
			InDatabaseADOQuery->Parameters->ParamByName("STATUS")->Value = 0;
			InDatabaseADOQuery->Parameters->ParamByName("SENDTIME")->Value = NULL;
			InDatabaseADOQuery->ExecSQL();
		}
		InDatabaseADOQuery->Close();

		//填写操作记录表
		InDatabaseADOQuery->SQL->Clear();
		sql =  "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
		InDatabaseADOQuery->SQL->Add(sql);
		InDatabaseADOQuery->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
		InDatabaseADOQuery->Parameters->ParamByName("KH")->Value = kh;
		InDatabaseADOQuery->Parameters->ParamByName("JE")->Value = 0;
		InDatabaseADOQuery->Parameters->ParamByName("YE")->Value = StrToFloat(cxTextEdit17->Text);
		InDatabaseADOQuery->Parameters->ParamByName("LX")->Value = "挂失";
		InDatabaseADOQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
		InDatabaseADOQuery->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Date());
		InDatabaseADOQuery->ExecSQL();
		InDatabaseADOQuery->Close();

		cxButton2->Enabled = false;
		cxButton3->Enabled = true;
		enableGS = true;
		if(mrOk == MessageBox(this->Handle, "登记挂失信息成功，是否将单条挂失记录下传!", "请选择", MB_OKCANCEL|MB_ICONQUESTION))
		{
			SingleGSForm->cxTextEdit1->Text = cxTextEdit14->Text;
			SingleGSForm->ShowModal();
		}
	}
	else
	{
		ShowMessage("登记挂失信息成功,该收费系统中没有入库的POS机！");
		InDatabaseADOQuery->Close();
		cxButton2->Enabled = false;
		cxButton3->Enabled = false;
		enableGS = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxButton3Click(TObject *Sender)
{
	//New Card
/*	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Add("select min(KH) as maxkh from KZT where SY='N' and GS=0");
	ADOQuery2->Open();
	if(!ADOQuery2->IsEmpty())
	{
		cxTextEdit18->Text = ADOQuery2->FieldByName("maxkh")->AsInteger; */
	if(cxTextEdit18->Text.IsEmpty())
	{
		ShowMessage("必须输入补卡号!");
		return;
	}
	int tmpbkh = StrToInt(cxTextEdit18->Text);
	if(tmpbkh > 189999)
	{
		ShowMessage("补卡号不能大于189999!");
		return;
	}

    int middlekh;
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	String tmpsqlstr = "select * from KZT where KH=";
	tmpsqlstr += cxTextEdit18->Text;
	tmpsqlstr += " and SY='N' and GS='0'";
	ADOQuery2->SQL->Add(tmpsqlstr);
	ADOQuery2->Open();

	if(!ADOQuery2->IsEmpty())
	{
		ADOQuery2->Edit();
		ADOQuery2->FieldByName("KH")->AsInteger = -1;
		ADOQuery2->Post();

		//launchnewcard
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

		Delayms = DelaySecond;
		keymode = CARDPasswordEdition;
		secnum = UsingSecNUM;

		key[0] = CARDPassword[0];
		key[1] = CARDPassword[1];
		key[2] = CARDPassword[2];
		key[3] = CARDPassword[3];
		key[4] = CARDPassword[4];
		key[5] = CARDPassword[5];

		if(LoadHModule)
		{
			if(readwatercardinfo)//readcardinfo)
			{
			//	status = readcardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,synum,daytime,cardtype,czmm,Delayms);
            	status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
				if(status > 99)
				{
					ShowMessage("通讯错误！");
                    ADOQuery2->Edit();
                    ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                    ADOQuery2->Post();
				}
				else if (1 == status)
				{
					ShowMessage("请把卡片放好！");
                    ADOQuery2->Edit();
                    ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                    ADOQuery2->Post();
				}
				else if (2 == status)
				{
					ShowMessage("卡号大于192000或等于0！");
                    cxButton3->Enabled = false;
                    ADOQuery2->Edit();
                    ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                    ADOQuery2->Post();
				}
				else if (4 == status)
				{
					ShowMessage("卡片密码不对！");
                    cxButton3->Enabled = false;
                    ADOQuery2->Edit();
                    ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                    ADOQuery2->Post();
				}
				else if (5 == status)
				{
					ShowMessage("读写卡不稳定！");
                    cxButton3->Enabled = false;
                    ADOQuery2->Edit();
                    ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                    ADOQuery2->Post();
				}
				else if (0 == status)
				{
					ShowMessage("此卡不能做为新卡发行，请更换新卡！");
                    cxButton3->Enabled = false;
                    ADOQuery2->Edit();
                    ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                    ADOQuery2->Post();
				}
				else
				{
					unsigned char writesynum[2];
					writesynum[0] = 0x00;
					writesynum[1] = 0x00;

					int maxsycs1 = 0;
					int maxsycs2 = 0;
					int maxsycs;
					String maxsycssqlstr = "select MAX(sycs) as maxsycs from MX where BH='";
					maxsycssqlstr += cxTextEdit5->Text;
					maxsycssqlstr += "'";
					ADOQuery3->Close();
					ADOQuery3->SQL->Clear();
					ADOQuery3->SQL->Add(maxsycssqlstr);
					ADOQuery3->Open();
					if(!ADOQuery3->IsEmpty())
					{
						maxsycs1 = ADOQuery3->FieldByName("maxsycs")->AsInteger;
					}
					ADOQuery3->Close();
					maxsycssqlstr = "select MAX(sycs) as maxsycs from MXBAK where BH='";
					maxsycssqlstr += cxTextEdit5->Text;
					maxsycssqlstr += "'";
					ADOQuery3->SQL->Clear();
					ADOQuery3->SQL->Add(maxsycssqlstr);
					ADOQuery3->Open();
					if(!ADOQuery3->IsEmpty())
					{
						maxsycs2 = ADOQuery3->FieldByName("maxsycs")->AsInteger;
					}
					ADOQuery3->Close();
					if(maxsycs1 < maxsycs2)
						maxsycs = maxsycs2;
					else
						maxsycs = maxsycs1;

					writesynum[0] = (unsigned char)(maxsycs/256);
					writesynum[1] = (unsigned char)(maxsycs%256);

					WORD writestatus;
					unsigned char writedaytime[4];
					unsigned char writebalance[4];
					unsigned char writeczmm[3];
					unsigned char writecardtype[1];
					unsigned char writekh[4];
					int writetmpkh = atoi(cxTextEdit18->Text.t_str());
					writekh[0] = (char)(writetmpkh/256/256/256);
					writekh[1] = (char)((writetmpkh%(256*256*256))/256/256);
					writekh[2] = (char)((writetmpkh%(256*256))/256);
					writekh[3] = (char)writetmpkh;

					unsigned char writereadcomno[5] = readcomno;
					unsigned char writekeymode = keymode;
					unsigned char writesecnum = secnum;

					unsigned char writekey[6];// = key;
					writekey[0] = CARDPassword[0];
					writekey[1] = CARDPassword[1];
					writekey[2] = CARDPassword[2];
					writekey[3] = CARDPassword[3];
					writekey[4] = CARDPassword[4];
					writekey[5] = CARDPassword[5];

					unsigned char writedwmm[2];
					writedwmm[0] = DWPassword[0];
					writedwmm[1] = DWPassword[1];

					unsigned char writemode = 0x00;
					unsigned char writeDelayms = DelaySecond;

					String writetmpstr = DateToStr(UseDateEdit->Date);
					char* writetmpdatestr = writetmpstr.t_str();
					writedaytime[0] = char(((int)writetmpdatestr[2]-48)*16+((int)writetmpdatestr[3]-48));
					writedaytime[1] = char(((int)writetmpdatestr[5]-48)*16+((int)writetmpdatestr[6]-48));
					writedaytime[2] = char(((int)writetmpdatestr[8]-48)*16+((int)writetmpdatestr[9]-48));
					writedaytime[3] = 0x00;

		 //			ShowMessage(PrepayTextEdit->Text.t_str());

					double writetmpbalance = StrToFloat(cxTextEdit17->Text);
					writetmpbalance *= 100;
					writebalance[0] = 0x00;
					writebalance[1] = (char)((int)writetmpbalance/65536);
					writetmpbalance = (int)writetmpbalance%65536;
					writebalance[2] = (char)((int)writetmpbalance/256);
					writetmpbalance = (int)writetmpbalance%256;
					writebalance[3] = (char)writetmpbalance;

					unsigned char writetmpczmm[5];
					strcpy(writetmpczmm, cxTextEdit12->Text.t_str());
					writetmpczmm[0] = writetmpczmm[0]<<4;
					writetmpczmm[1] = writetmpczmm[1]<<4;
					writetmpczmm[1] = writetmpczmm[1]>>4;
					writeczmm[0] = writetmpczmm[0] + writetmpczmm[1];
					writetmpczmm[2] = writetmpczmm[2]<<4;
					writetmpczmm[3] = writetmpczmm[3]<<4;
					writetmpczmm[3] = writetmpczmm[3]>>4;
					writeczmm[1] = writetmpczmm[2]+writetmpczmm[3];
					writeczmm[2] = 0x00;

					writecardtype[0] = atoi(cxTextEdit13->Text.t_str());

					if(LaunchWaterNewCard)//LaunchNewCard)
					{
					/*	writestatus = LaunchNewCard(writereadcomno,
													writekeymode,
													writesecnum,
													writekey,
													writekh,
													writebalance,
													writedwmm,
													writesynum,
													writedaytime,
													writecardtype,
													writeczmm,
													writemode,
													writeDelayms);   */

                    	writestatus = LaunchWaterNewCard(writereadcomno,
                        								 writekeymode,
                                                         writesecnum,
                                                         writekey,
                                                         writekh,
                                                         writebalance,
                                                         writedwmm,
                                                         writedaytime,
                                                         writecardtype,
                                                         writemode,
                                                         writeDelayms);
						if(writestatus)
						{
							ShowMessage("写卡失败！");
                            ADOQuery2->Edit();
                            ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
                            ADOQuery2->Post();
						}
						else
						{
							String tmpsql;
							String tmpsql2 = "insert into CARD_F values(:BH,:KH,:BKH,:XM,:XB,";;

                            //填写退卡表
							tmpsql = "insert into CARD_T values(:BH,:KH,:BKH,:XM,:XB,";
							tmpsql = tmpsql+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
											":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
											":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
											":SF_KL,:USERNAME,:YW,:TKCB,:BKCB,:TKOperator)";

							tmpsql2 = tmpsql2 + ":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
												":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
												":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
												":SF_KL,:USERNAME)";
							ADOQuery3->Close();
							ADOQuery3->SQL->Clear();
							ADOQuery3->SQL->Add(tmpsql);

                            ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							String stmpsql = "select * from CARD where BH='" + cxTextEdit5->Text + "'";
							ADOQuery2->SQL->Add(stmpsql);
							ADOQuery2->Open();
                            if(!ADOQuery2->IsEmpty())
							{
								//补发卡不计退卡记录
								ADOQuery3->Parameters->ParamByName("BH")->Value = ADOQuery2->FieldByName("BH")->Value;
								ADOQuery3->Parameters->ParamByName("KH")->Value = ADOQuery2->FieldByName("KH")->Value;
								ADOQuery3->Parameters->ParamByName("BKH")->Value = ADOQuery2->FieldByName("BKH")->Value;
								ADOQuery3->Parameters->ParamByName("XM")->Value = ADOQuery2->FieldByName("XM")->Value;
								ADOQuery3->Parameters->ParamByName("XB")->Value = ADOQuery2->FieldByName("XB")->Value;
								ADOQuery3->Parameters->ParamByName("SFZH")->Value = ADOQuery2->FieldByName("SFZH")->Value;
								ADOQuery3->Parameters->ParamByName("BM")->Value = ADOQuery2->FieldByName("BM")->Value;
								ADOQuery3->Parameters->ParamByName("BZ")->Value = ADOQuery2->FieldByName("BZ")->Value;
								ADOQuery3->Parameters->ParamByName("ZB")->Value = ADOQuery2->FieldByName("ZB")->Value;
								ADOQuery3->Parameters->ParamByName("ZW")->Value = ADOQuery2->FieldByName("ZW")->Value;
								ADOQuery3->Parameters->ParamByName("JB")->Value = ADOQuery2->FieldByName("JB")->Value;
								ADOQuery3->Parameters->ParamByName("RQ")->Value = ADOQuery2->FieldByName("RQ")->Value;
								ADOQuery3->Parameters->ParamByName("TKRQ")->Value = DateTimeToStr(Now());
								ADOQuery3->Parameters->ParamByName("YJ")->Value = ADOQuery2->FieldByName("YJ")->Value;
								ADOQuery3->Parameters->ParamByName("TYJ")->Value = ADOQuery2->FieldByName("TYJ")->Value;
								ADOQuery3->Parameters->ParamByName("ZT")->Value = "挂补";//ADOQuery2->FieldByName("ZT")->Value;
                                ADOQuery3->Parameters->ParamByName("GRMM")->Value = ADOQuery2->FieldByName("GRMM")->Value;
                                ADOQuery3->Parameters->ParamByName("BTBZ")->Value = ADOQuery2->FieldByName("BTBZ")->Value;
                                ADOQuery3->Parameters->ParamByName("BT_YE")->Value = ADOQuery2->FieldByName("BT_YE")->Value;
                                ADOQuery3->Parameters->ParamByName("BTYEDT")->Value = ADOQuery2->FieldByName("BTYEDT")->Value;
                                ADOQuery3->Parameters->ParamByName("BTSYCS")->Value = ADOQuery2->FieldByName("BTSYCS")->Value;
                                ADOQuery3->Parameters->ParamByName("SF_YE")->Value = ADOQuery2->FieldByName("SF_YE")->Value;
                                ADOQuery3->Parameters->ParamByName("SFYEDT")->Value = ADOQuery2->FieldByName("SFYEDT")->Value;
                                ADOQuery3->Parameters->ParamByName("SYCS")->Value = ADOQuery2->FieldByName("SYCS")->Value;
                                ADOQuery3->Parameters->ParamByName("FKSK")->Value = ADOQuery2->FieldByName("FKSK")->Value;
                                ADOQuery3->Parameters->ParamByName("SF_FL")->Value = ADOQuery2->FieldByName("SF_FL")->Value;
                                ADOQuery3->Parameters->ParamByName("GLF")->Value = ADOQuery2->FieldByName("GLF")->Value;
                                ADOQuery3->Parameters->ParamByName("FKJE")->Value = ADOQuery2->FieldByName("FKJE")->Value;
                                ADOQuery3->Parameters->ParamByName("TKJE")->Value = 0;//ADOQuery2->FieldByName("TKJE")->Value;
                                ADOQuery3->Parameters->ParamByName("TKBT")->Value = 0;//ADOQuery2->FieldByName("TKBT")->Value;
                                ADOQuery3->Parameters->ParamByName("SF_KL")->Value = ADOQuery2->FieldByName("SF_KL")->Value;
                                ADOQuery3->Parameters->ParamByName("USERNAME")->Value = ADOQuery2->FieldByName("USERNAME")->Value;
                                ADOQuery3->Parameters->ParamByName("YW")->Value = 0;
                                ADOQuery3->Parameters->ParamByName("TKCB")->Value = 0;
                                ADOQuery3->Parameters->ParamByName("BKCB")->Value = StrToInt(cxTextEdit20->Text);
								ADOQuery3->Parameters->ParamByName("TKOperator")->Value = OperatorName;
                                ADOQuery3->ExecSQL();
								ADOQuery3->Close();
                            }

							//Wallet修改大钱包数据
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "select * from CARD where BH='" + cxTextEdit5->Text + "'";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Open();
							if(!ADOQuery2->IsEmpty())
							{
								ADOQuery2->Edit();
								ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit18->Text);
								ADOQuery2->Post();
							}

							//CARD
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "select * from CARD where BH='" + cxTextEdit5->Text + "'";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Open();

							ADOQuery2->Edit();
							ADOQuery2->FieldByName("KH")->AsInteger = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->FieldByName("ZT")->AsString = "发卡";
							ADOQuery2->Post();


							//CARD_F
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "select * from CARD_F where BH='" + cxTextEdit5->Text + "'";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Open();

							ADOQuery3->SQL->Clear();
							ADOQuery3->SQL->Add(tmpsql2);
							ADOQuery3->Parameters->ParamByName("BH")->Value = ADOQuery2->FieldByName("BH")->Value;
							ADOQuery3->Parameters->ParamByName("KH")->Value = ADOQuery2->FieldByName("KH")->Value;
							ADOQuery3->Parameters->ParamByName("BKH")->Value = ADOQuery2->FieldByName("BKH")->Value;
							ADOQuery3->Parameters->ParamByName("XM")->Value = ADOQuery2->FieldByName("XM")->Value;
							ADOQuery3->Parameters->ParamByName("XB")->Value = ADOQuery2->FieldByName("XB")->Value;
							ADOQuery3->Parameters->ParamByName("SFZH")->Value = ADOQuery2->FieldByName("SFZH")->Value;
							ADOQuery3->Parameters->ParamByName("BM")->Value = ADOQuery2->FieldByName("BM")->Value;
							ADOQuery3->Parameters->ParamByName("BZ")->Value = ADOQuery2->FieldByName("BZ")->Value;
							ADOQuery3->Parameters->ParamByName("ZB")->Value = ADOQuery2->FieldByName("ZB")->Value;
							ADOQuery3->Parameters->ParamByName("ZW")->Value = ADOQuery2->FieldByName("ZW")->Value;
							ADOQuery3->Parameters->ParamByName("JB")->Value = ADOQuery2->FieldByName("JB")->Value;
							ADOQuery3->Parameters->ParamByName("RQ")->Value = ADOQuery2->FieldByName("RQ")->Value;
							ADOQuery3->Parameters->ParamByName("TKRQ")->Value = DateTimeToStr(Now());
							ADOQuery3->Parameters->ParamByName("YJ")->Value = ADOQuery2->FieldByName("YJ")->Value;
							ADOQuery3->Parameters->ParamByName("TYJ")->Value = ADOQuery2->FieldByName("TYJ")->Value;
							ADOQuery3->Parameters->ParamByName("ZT")->Value = ADOQuery2->FieldByName("ZT")->Value;
							ADOQuery3->Parameters->ParamByName("GRMM")->Value = ADOQuery2->FieldByName("GRMM")->Value;
							ADOQuery3->Parameters->ParamByName("BTBZ")->Value = ADOQuery2->FieldByName("BTBZ")->Value;
							ADOQuery3->Parameters->ParamByName("BT_YE")->Value = ADOQuery2->FieldByName("BT_YE")->Value;
							ADOQuery3->Parameters->ParamByName("BTYEDT")->Value = ADOQuery2->FieldByName("BTYEDT")->Value;
							ADOQuery3->Parameters->ParamByName("BTSYCS")->Value = ADOQuery2->FieldByName("BTSYCS")->Value;
							ADOQuery3->Parameters->ParamByName("SF_YE")->Value = ADOQuery2->FieldByName("SF_YE")->Value;
							ADOQuery3->Parameters->ParamByName("SFYEDT")->Value = ADOQuery2->FieldByName("SFYEDT")->Value;
							ADOQuery3->Parameters->ParamByName("SYCS")->Value = ADOQuery2->FieldByName("SYCS")->Value;
							ADOQuery3->Parameters->ParamByName("FKSK")->Value = ADOQuery2->FieldByName("FKSK")->Value;
							ADOQuery3->Parameters->ParamByName("SF_FL")->Value = ADOQuery2->FieldByName("SF_FL")->Value;
							ADOQuery3->Parameters->ParamByName("GLF")->Value = ADOQuery2->FieldByName("GLF")->Value;
							ADOQuery3->Parameters->ParamByName("FKJE")->Value = ADOQuery2->FieldByName("FKJE")->Value;
							ADOQuery3->Parameters->ParamByName("TKJE")->Value = ADOQuery2->FieldByName("TKJE")->Value;
							ADOQuery3->Parameters->ParamByName("TKBT")->Value = ADOQuery2->FieldByName("TKBT")->Value;
							ADOQuery3->Parameters->ParamByName("SF_KL")->Value = ADOQuery2->FieldByName("SF_KL")->Value;
							ADOQuery3->Parameters->ParamByName("USERNAME")->Value = ADOQuery2->FieldByName("USERNAME")->Value;

							ADOQuery2->Edit();
							ADOQuery2->FieldByName("KH")->AsInteger = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->FieldByName("ZT")->AsString = "发卡";
							ADOQuery2->Post();
							ADOQuery3->ExecSQL();
							ADOQuery3->Close();

							//KZT
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "select * from KZT where BH='" + cxTextEdit5->Text + "'";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Open();
							ADOQuery2->Edit();
							ADOQuery2->FieldByName("KH")->AsInteger = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->FieldByName("GS")->AsInteger = 0;
							ADOQuery2->FieldByName("SY")->AsString = "Y";
							ADOQuery2->FieldByName("FKRQ")->AsString = DateTimeToStr(Now());
							ADOQuery2->Post();

							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "select * from KZT where KH=-1";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Open();
							ADOQuery2->Edit();
							ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit14->Text);
							ADOQuery2->FieldByName("GS")->AsInteger = 1;
							ADOQuery2->Post();

							//填写操作记录表
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
							ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->Parameters->ParamByName("JE")->Value = 0;
							ADOQuery2->Parameters->ParamByName("YE")->Value = StrToFloat(cxTextEdit17->Text);;
							ADOQuery2->Parameters->ParamByName("LX")->Value = "补发卡";
							ADOQuery2->Parameters->ParamByName("Operator")->Value = OperatorName;
							ADOQuery2->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
							ADOQuery2->ExecSQL();
							ADOQuery2->Close();

                            //补发卡明细
                 /*           ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "insert into BFKMX values(:BH,:KH,:BKH,:JE,:YE,:LX,:Operator,:DateTime)";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
							ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
                            ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->Parameters->ParamByName("JE")->Value = 0;
							ADOQuery2->Parameters->ParamByName("YE")->Value = StrToFloat(cxTextEdit17->Text);;
							ADOQuery2->Parameters->ParamByName("LX")->Value = "补发卡";
							ADOQuery2->Parameters->ParamByName("Operator")->Value = OperatorName;
							ADOQuery2->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
							ADOQuery2->ExecSQL();
							ADOQuery2->Close();      */

							//MX
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "insert into MX values(:BH,:KH,:SF_YE,";
							tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
							tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
							ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SF_YE")->Value = StrToFloat(cxTextEdit17->Text);
							ADOQuery2->Parameters->ParamByName("SFJE")->Value = 0;//atoi(cxTextEdit20->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery2->Parameters->ParamByName("SFLX")->Value = "F";
							ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->ExecSQL();
							ADOQuery2->Close();

							int bkf = 0;
							if(!cxTextEdit20->Text.IsEmpty())
								bkf = StrToInt(cxTextEdit20->Text);
							//补卡费
							ADOQuery2->Close();
							ADOQuery2->SQL->Clear();
							tmpsql = "insert into MX values(:BH,:KH,:SF_YE,";
							tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
							tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
							ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
							ADOQuery2->Parameters->ParamByName("SFJE")->Value = bkf;
							ADOQuery2->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery2->Parameters->ParamByName("SFLX")->Value = "G";
							ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->ExecSQL();
							ADOQuery2->Close();

							//MXBAK
/*							ADOQuery2->SQL->Clear();
							tmpsql = "insert into MXBAK values(:BH,:KH,:SF_YE,";
							tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
							tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
							ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SF_YE")->Value = StrToFloat(cxTextEdit17->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SFJE")->Value = 0;//atoi(cxTextEdit20->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery2->Parameters->ParamByName("SFLX")->Value = "F";
							ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->ExecSQL();
							ADOQuery2->Close();

							ADOQuery2->SQL->Clear();
							tmpsql = "insert into MXBAK values(:BH,:KH,:SF_YE,";
							tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
							tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery2->SQL->Add(tmpsql);
							ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
							ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit18->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
							ADOQuery2->Parameters->ParamByName("SFJE")->Value = atoi(cxTextEdit20->Text.t_str());
							ADOQuery2->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery2->Parameters->ParamByName("SFLX")->Value = "G";
							ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
							ADOQuery2->ExecSQL();
							ADOQuery2->Close();         */


                            beepofreaddll(readcomno, '10');
							ShowMessage("挂失补发新卡成功!");

							ADOQuery1->Close();
							InDatabaseADOQuery->Close();
						//	this->Close();
						}
					}
				}
			}
		}
	}
    else
    {
        ShowMessage("此卡号已经被使用，请更换卡号!");
    }
	cxButton3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxTextEdit1Exit(TObject *Sender)
{
	if(cxTextEdit1->Text.Length() > 10)
	{
		ShowMessage("编号为10位数字，请重新输入!");
		cxTextEdit1->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::FormCreate(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from XTSET");
	ADOQuery1->Open();
//	ShowMessage(IntToStr(ADOQuery1->FieldByName("FKYJ")->AsInteger));
	cxTextEdit20->Text = IntToStr(ADOQuery1->FieldByName("FKYJ")->AsInteger);
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxTextEdit14KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TResendLostCardnewFRM::cxButton5Click(TObject *Sender)
{
	if(cxTextEdit14->Text.IsEmpty())
    {
        ShowMessage("必须填写原卡号!");
        return;
    }

    int ykh = StrToInt(cxTextEdit14->Text);

    String sql = "select * from CARD where kh=";
    sql += ykh;
    sql += " and ZT='发卡'";

	ADOQuery1->Close();
    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Add(sql);
    ADOQuery1->Open();
    if(!ADOQuery1->IsEmpty())
    {
        cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
        cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
        cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
        cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
        cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
        cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
        cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

        cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
        cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
        cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
        cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
        cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
        cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
        cxButton3->Enabled = true;
    }
    else
    {
        ShowMessage("没有此卡号的卡片!");
        cxButton3->Enabled = false;
    }
    ADOQuery1->Close();
}
//---------------------------------------------------------------------------

