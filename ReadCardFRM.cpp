//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "ReadCardFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
TReadCardInfoFRM *ReadCardInfoFRM;

//---------------------------------------------------------------------------
__fastcall TReadCardInfoFRM::TReadCardInfoFRM(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TReadCardInfoFRM::ReadCardInfoBTNClick(TObject *Sender)
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
				ADOCardInfoQuery->Close();
				ADOCardInfoQuery->SQL->Clear();
				ADOCardInfoQuery->SQL->Add("select * from XTSET");
				String mmstr = "";

				unsigned char tmpchar;
				tmpchar = dwmm[0];
				tmpchar = tmpchar>>4;
				mmstr += (int)tmpchar;

				tmpchar = dwmm[0];
				tmpchar = tmpchar<<4;
				tmpchar = tmpchar>>4;
				mmstr += (int)tmpchar;

				tmpchar = dwmm[1];
				tmpchar = tmpchar>>4;
				mmstr += (int)tmpchar;

				tmpchar = dwmm[1];
				tmpchar = tmpchar<<4;
				tmpchar = tmpchar>>4;
				mmstr += (int)tmpchar;

				ADOCardInfoQuery->Close();

				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

				ADOCardInfoQuery->Close();
				ADOCardInfoQuery->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				ADOCardInfoQuery->SQL->Add(tmpstr);
				ADOCardInfoQuery->Open();
				if(!ADOCardInfoQuery->IsEmpty())
				{
					if(0 != ADOCardInfoQuery->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						ADOCardInfoQuery->Close();
                        return;
					}
				}
				else
				{
					String checkgstmpstr = "select * from GS where KH=";
					checkgstmpstr += tmpkh;
					ADOCardInfoQuery->Close();
					ADOCardInfoQuery->SQL->Clear();
					ADOCardInfoQuery->SQL->Add(checkgstmpstr);
					ADOCardInfoQuery->Open();
					if(!ADOCardInfoQuery->IsEmpty())
					{
                    	ShowMessage("此卡为挂失的卡！");
					}
					else
					{
						ShowMessage("此卡不是本系统发出的卡！");
					}
					ADOCardInfoQuery->Close();
                    return;
				}
				ADOCardInfoQuery->Close();

				ADOCardInfoQuery->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				ADOCardInfoQuery->SQL->Add(tmpstr);
				ADOCardInfoQuery->Open();
				if(!ADOCardInfoQuery->IsEmpty())
				{
					cxTextEdit7->Text = ADOCardInfoQuery->FieldByName("BH")->AsString.Trim();
					cxTextEdit2->Text = ADOCardInfoQuery->FieldByName("XM")->AsString.Trim();
					cxTextEdit11->Text = ADOCardInfoQuery->FieldByName("SFZH")->AsString.Trim();
					cxTextEdit12->Text = ADOCardInfoQuery->FieldByName("GRMM")->AsString.Trim();
					cxTextEdit17->Text = ADOCardInfoQuery->FieldByName("YJ")->AsString.Trim();
					SectionNameComboBox->Text = ADOCardInfoQuery->FieldByName("BM")->AsString.Trim();
					cxTextEdit15->Text = ADOCardInfoQuery->FieldByName("SF_FL")->AsString.Trim();
					DegreeComboBox->Text = ADOCardInfoQuery->FieldByName("ZW")->AsString.Trim();
					ClassNameComboBox->Text = ADOCardInfoQuery->FieldByName("BZ")->AsString.Trim();
					GroupNameComboBox->Text = ADOCardInfoQuery->FieldByName("ZB")->AsString.Trim();
					SexComboBox->Text = ADOCardInfoQuery->FieldByName("XB")->AsString.Trim();


					ADOCardInfoQuery->Close();
					cxTextEdit1->Text = tmpkh;
					cxTextEdit16->Text = tmpsycs;
					cxTextEdit18->Text = tmpye;
					cxTextEdit6->Text = cardtype[0];
					cxTextEdit5->Text = cardtype[0];

                    /*
					//读电话号码
					WORD Status;
					int tmpbalance;
					int tmpkh,tmpsycs;
					int oldks,cardks;
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
					unsigned char createCRC[16];
					unsigned char CRC[2];
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

					unsigned char sendbuf[26];
					unsigned char sendbuflen = 26;
					unsigned char senddelay = Delayms;
					unsigned char recbuf[140];
					unsigned char recbuflen;
					unsigned char pblock = secnum*4+2;
					unsigned char pmimamode = 0x60;
					unsigned char pcommand = 0x01;
					unsigned char pkeymode = CARDPasswordEdition;
					unsigned char pkey[6];
					memcpy(pkey,CARDPassword,6);

					ZeroMemory(sendbuf,26);
					sendbuf[0] = pblock;//扇区×4+块号
					sendbuf[1] = pmimamode;//固定为0x60
					sendbuf[2] = pcommand;//命令字：1为读，2为写
					sendbuf[3] = pkeymode;
					sendbuf[4] = pkey[0];
					sendbuf[5] = pkey[1];
					sendbuf[6] = pkey[2];
					sendbuf[7] = pkey[3];
					sendbuf[8] = pkey[4];
					sendbuf[9] = pkey[5];
					Status = pacarddllproc(readcomno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
					if((0 == Status)&&(0 == recbuf[2]))
					{
						char phonearray[16];
						ZeroMemory(phonearray, 16);
						for(int i  = 10; i < 26; i++)
						{
							if(0x20 == recbuf[i])
								break;
							else
								phonearray[i-10] = recbuf[i];
						}
						cxTextEdit8->Text = phonearray;
					}
					else
					{
                        cxTextEdit8->Text = "";
                    }   */


					//phone end
					MXBTN->Enabled = true;
					cxButton1->Enabled = true;
					cxButton2->Enabled = true;
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					ADOCardInfoQuery->Close();
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

void __fastcall TReadCardInfoFRM::CloseFormBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::cxButton1Click(TObject *Sender)
{
	if(!SexComboBox->Text.IsEmpty())
	{
		if(!cxTextEdit1->Text.IsEmpty()&&!cxTextEdit7->Text.IsEmpty())
		{
			if(SexComboBox->Text == "女"||SexComboBox->Text == "男")
			{
				ADOQuery1->Close();
				ADOQuery1->SQL->Clear();
				String sqlstr = "select * from CARD where KH=";
				sqlstr += cxTextEdit1->Text;
				ADOQuery1->SQL->Add(sqlstr);
				ADOQuery1->Open();
				if(!ADOQuery1->IsEmpty())
				{
					ADOQuery1->Edit();
					ADOQuery1->FieldByName("XM")->AsString = cxTextEdit2->Text;
					ADOQuery1->FieldByName("XB")->AsString = SexComboBox->Text;
					ADOQuery1->FieldByName("BM")->AsString = SectionNameComboBox->Text;
					ADOQuery1->FieldByName("BZ")->AsString = ClassNameComboBox->Text;
					ADOQuery1->FieldByName("ZB")->AsString = GroupNameComboBox->Text;
					ADOQuery1->FieldByName("ZW")->AsString = DegreeComboBox->Text;
					ADOQuery1->FieldByName("GRMM")->AsString = cxTextEdit12->Text;
					ADOQuery1->FieldByName("SFZH")->AsString = cxTextEdit11->Text;

					ADOQuery1->Post();

					ADOQuery1->Close();
					ADOQuery1->SQL->Clear();
					sqlstr = "select * from CARD_F where KH=";
					sqlstr += cxTextEdit1->Text;
					ADOQuery1->SQL->Add(sqlstr);
					ADOQuery1->Open();
					if(!ADOQuery1->IsEmpty())
					{
						ADOQuery1->Edit();
						ADOQuery1->FieldByName("XM")->AsString = cxTextEdit2->Text;
						ADOQuery1->FieldByName("XB")->AsString = SexComboBox->Text;
						ADOQuery1->FieldByName("BM")->AsString = SectionNameComboBox->Text;
						ADOQuery1->FieldByName("BZ")->AsString = ClassNameComboBox->Text;
						ADOQuery1->FieldByName("ZB")->AsString = GroupNameComboBox->Text;
						ADOQuery1->FieldByName("ZW")->AsString = DegreeComboBox->Text;
						ADOQuery1->FieldByName("GRMM")->AsString = cxTextEdit12->Text;
						ADOQuery1->FieldByName("SFZH")->AsString = cxTextEdit11->Text;

						ADOQuery1->Post();
						ShowMessage("卡片信息修改成功!");
						ADOQuery1->Close();
					}
					ADOQuery1->Close();

					unsigned char writereadcomno[5] = readcomno;
					unsigned char writekeymode = CARDPasswordEdition;
					unsigned char writesecnum = UsingSecNUM;
					unsigned char writeDelayms = DelaySecond;
					unsigned char secnum = UsingSecNUM;

					unsigned char writekey[6];// = key;
					writekey[0] = CARDPassword[0];
					writekey[1] = CARDPassword[1];
					writekey[2] = CARDPassword[2];
					writekey[3] = CARDPassword[3];
					writekey[4] = CARDPassword[4];
					writekey[5] = CARDPassword[5];

					//写姓名
					if(!cxTextEdit2->Text.IsEmpty())
					{
						if(!pacarddllproc)
						{
							ShowMessage("写姓名函数加载失败!");
							return;
						}

						unsigned char writename[16];
						memset(writename, 0xA1, 16);
						String writenamestr = cxTextEdit2->Text;
						char* writenametmpstr = writenamestr.t_str();

						for(int j = 0; j <writenamestr.Length(); j++)
						{
							writename[j] = writenametmpstr[j];
						}

						unsigned char sendbuflen = 26;
						unsigned char sendbuf[26];
						ZeroMemory(sendbuf,26);
						unsigned char recbuf[140];
						unsigned char recbuflen;
						ZeroMemory(recbuf, 140);

						sendbuf[0] = secnum*4+1;//扇区×4+块号
						sendbuf[1] = 0x60;//固定为0x60
						sendbuf[2] = 2;//命令字：1为读，2为写
						sendbuf[3] = writekeymode;
						sendbuf[4] = writekey[0];
						sendbuf[5] = writekey[1];
						sendbuf[6] = writekey[2];
						sendbuf[7] = writekey[3];
						sendbuf[8] = writekey[4];
						sendbuf[9] = writekey[5];

						for(int n = 10; n < 26; n++)
						{
							sendbuf[n] = writename[n - 10];
						}

						WORD limitStatus = pacarddllproc(writereadcomno,sendbuflen,sendbuf,&recbuflen,recbuf,writeDelayms);

						if((0 != limitStatus)||(0 != recbuf[2]))
						{
							beepofreaddll(readcomno, '10');
							ShowMessage("写姓名失败!");
							return;
						}
					}
					//写电话号码
					if(!cxTextEdit8->Text.IsEmpty())
					{
						if(!pacarddllproc)
						{
							beepofreaddll(readcomno, '10');
							ShowMessage("写电话函数加载失败!");
							return;
						}

						unsigned char writephone[16];
						memset(writephone, 0x20, 16);
						String writephonestr = cxTextEdit8->Text;
						char* writephonetmpstr = writephonestr.t_str();

						for(int j = 0; j <writephonestr.Length(); j++)
						{
							writephone[j] = writephonetmpstr[j];
						}

						unsigned char sendbuflen = 26;
						unsigned char sendbuf[26];
						ZeroMemory(sendbuf,26);
						unsigned char recbuf[140];
						unsigned char recbuflen;
						ZeroMemory(recbuf, 140);

						sendbuf[0] = secnum*4+2;//扇区×4+块号
						sendbuf[1] = 0x60;//固定为0x60
						sendbuf[2] = 2;//命令字：1为读，2为写
						sendbuf[3] = writekeymode;
						sendbuf[4] = writekey[0];
						sendbuf[5] = writekey[1];
						sendbuf[6] = writekey[2];
						sendbuf[7] = writekey[3];
						sendbuf[8] = writekey[4];
						sendbuf[9] = writekey[5];

						for(int n = 10; n < 26; n++)
						{
							sendbuf[n] = writephone[n - 10];
						}

						WORD limitStatus = pacarddllproc(writereadcomno,sendbuflen,sendbuf,&recbuflen,recbuf,writeDelayms);

						if((0 != limitStatus)||(0 != recbuf[2]))
						{
							beepofreaddll(readcomno, '10');
							ShowMessage("写电话失败!");
							return;
						}
					}
				}
				ADOQuery1->Close();
			}
			else
			{
				ShowMessage("性别输入有误!");
				return;
			}
		}
		else
		{
            ShowMessage("没有卡号或编号信息!");
        }
	}
	else
		ShowMessage("请填写性别!");
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::SectionNameComboBoxEnter(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from BUMEN");
	ADOQuery1->Open();
	SectionNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		SectionNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("BUMEN")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	SectionNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::SectionNameComboBoxExit(TObject *Sender)
{
	if(-1 == SectionNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在部门！");
		SectionNameComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::SectionNameComboBoxPropertiesChange(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from BANBIE where BUMEN='"+
								(SectionNameComboBox->Text)+"'");
	ADOQuery1->Open();
	ClassNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		ClassNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("BANBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	ClassNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}

//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::ClassNameComboBoxExit(TObject *Sender)
{
	if(-1 == ClassNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在班别！");
		ClassNameComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::ClassNameComboBoxPropertiesChange(TObject *Sender)

{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from ZUBIE where BUMEN = '"+
								(SectionNameComboBox->Text)+"'"+"and "+
								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
	ADOQuery1->Open();
	GroupNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		GroupNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("ZUBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	GroupNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::GroupNameComboBoxExit(TObject *Sender)
{
	if(-1 == GroupNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在组别！");
		GroupNameComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::DegreeComboBoxEnter(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from SFZW");
	ADOQuery1->Open();
	DegreeComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		DegreeComboBox->Properties->Items->Add(ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	DegreeComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::DegreeComboBoxExit(TObject *Sender)
{
	if(-1 == DegreeComboBox->ItemIndex)
	{
		ShowMessage("请选择用户身份！");
		DegreeComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::ClassNameComboBoxEnter(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from BANBIE where BUMEN='"+
								(SectionNameComboBox->Text)+"'");
	ADOQuery1->Open();
	ClassNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		ClassNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("BANBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	ClassNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::GroupNameComboBoxEnter(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from ZUBIE where BUMEN = '"+
								(SectionNameComboBox->Text)+"'"+"and "+
								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
	ADOQuery1->Open();
	GroupNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		GroupNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("ZUBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	GroupNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::MXBTNClick(TObject *Sender)
{
	MXForm->cxTextEdit5->Text = "";
    MXForm->cxTextEdit6->Text = "";
    MXForm->cxTextEdit2->Text = "";
    MXForm->cxTextEdit1->Text = "";
    MXForm->cxTextEdit3->Text = "";
    MXForm->cxTextEdit4->Text = "";

	MXForm->cxTextEdit5->Text = cxTextEdit1->Text;
    MXForm->cxTextEdit6->Text = cxTextEdit7->Text;
    MXForm->cxTextEdit2->Text = cxTextEdit2->Text;
    MXForm->cxTextEdit1->Text = ClassNameComboBox->Text;
    MXForm->cxTextEdit3->Text = SectionNameComboBox->Text;
    MXForm->cxTextEdit4->Text = GroupNameComboBox->Text;

    if(!MXForm->cxTextEdit5->Text.IsEmpty())
    {
    	int tempkh = -1;
        try
        {
        	tempkh = StrToInt(MXForm->cxTextEdit5->Text);
            String sqlstr = "select * from MX where KH=";
            sqlstr += tempkh;
            MXForm->ADOQuery1->Close();
            MXForm->ADOQuery1->SQL->Clear();
            MXForm->ADOQuery1->SQL->Add(sqlstr);
            MXForm->ADOQuery1->Open();
            if(!MXForm->ADOQuery1->IsEmpty())
            {
            	MXForm->DataGridDBTV->DataController->DataSource = MXForm->DataSource1;
                MXForm->DataGridDBTV->ClearItems();
                TcxGridDBColumn* BHDCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* KHCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* SFYECol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* SFJECol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* SYCSCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* SFRQCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* JYNOCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* GZZIDCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* SFLXCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* CZYCol = MXForm->DataGridDBTV->CreateColumn();
                TcxGridDBColumn* SCRQCol = MXForm->DataGridDBTV->CreateColumn();

                BHDCol->Caption = "编号";
                BHDCol->DataBinding->FieldName = "BH";
                KHCol->Caption = "卡号";
                KHCol->DataBinding->FieldName = "KH";
                SFYECol->Caption = "卡余额";
                SFYECol->DataBinding->FieldName = "SF_YE";
                SFJECol->Caption = "消费金额";
                SFJECol->DataBinding->FieldName = "SFJE";
                SYCSCol->Caption = "使用次数";
                SYCSCol->DataBinding->FieldName = "SYCS";
                SFRQCol->Caption = "消费日期";
                SFRQCol->DataBinding->FieldName = "SFRQ";
                JYNOCol->Caption = "交易机号";
                JYNOCol->DataBinding->FieldName = "JYNO";
                GZZIDCol->Caption = "工作站号";
                GZZIDCol->DataBinding->FieldName = "GZZID";
                SFLXCol->Caption = "交易类型";
                SFLXCol->DataBinding->FieldName = "SFLX";
                CZYCol->Caption = "操作员";
                CZYCol->DataBinding->FieldName = "CZY";
                SCRQCol->Caption = "上传日期";
                SCRQCol->DataBinding->FieldName = "SCRQ";
            }
            else
            {
            	MXForm->ADOQuery1->Close();
                ShowMessage("无该卡号的消费信息!");
                return;
            }
        }
        catch(...)
        {
            ShowMessage("卡号异常!");
            return;
        }
    }
    MXBTN->Enabled = false;
	MXForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::cxButton2Click(TObject *Sender)
{
	WORD status;
	WORD WriteStatus;
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

	Delayms = DelaySecond;//0x00;
	keymode = CARDPasswordEdition;
	mode = 0x00;
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
 //			ShowMessage("begin read card!");
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
				int oldkh = StrToInt(cxTextEdit1->Text);
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				if(oldkh != tmpkh)
				{
					cxButton1->Enabled = false;
					cxButton2->Enabled = false;
					MXBTN->Enabled = false;
                    ShowMessage("不能更换卡片!");
                }


				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				unsigned char writesynum[2];
				writesynum[0] = (char)(tmpsycs/256);
				writesynum[1] = (char)(tmpsycs%256);

				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
		  //		tmpye = tmpintye/100+ReChargeMoney;
				tmpye = tmpintye/100;

				unsigned char writebalance[4];
				double writetmpbalance = tmpye;
				writetmpbalance *= 100;
				writebalance[0] = 0x00;
				writebalance[1] = (unsigned char)((int)writetmpbalance/65536);
				writetmpbalance = (int)writetmpbalance%65536;
				writebalance[2] = (unsigned char)((int)writetmpbalance/256);
				writetmpbalance = (int)writetmpbalance%256;
				writebalance[3] = (unsigned char)writetmpbalance;

				int kjb = StrToInt(cxTextEdit6->Text);
				cardtype[0] = kjb;

				if(LaunchWaterNewCard)//LaunchNewCard)
				{
 //					ShowMessage("begin write card");
					String DateofLaunchCard;
					SYSTEMTIME tmpsystime;
					GetLocalTime(&tmpsystime);
					DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

				/*	WriteStatus = LaunchNewCard(readcomno,
												keymode,
												secnum,
												key,
												kh,
												writebalance,
												dwmm,
												writesynum,
												daytime,
												cardtype,
												czmm,
												mode,
												Delayms);    */

                	WriteStatus = LaunchWaterNewCard(readcomno,
                    								 keymode,
                                                     secnum,
                                                     key,
                                                     kh,
                                                     writebalance,
                                                     dwmm,
                                                     daytime,
                                                     cardtype,
                                                     mode,
                                                     Delayms);
					if(WriteStatus)
					{
						ShowMessage("写卡错误，修改级别失败!");
                        return;
					}
					else
					{
						//填写操作记录表
						String sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
						ADOQuery1->SQL->Clear();
						ADOQuery1->SQL->Add(sqlstr);
						ADOQuery1->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
						ADOQuery1->Parameters->ParamByName("KH")->Value = tmpkh;
						ADOQuery1->Parameters->ParamByName("JE")->Value = 0;
						ADOQuery1->Parameters->ParamByName("YE")->Value = tmpye;
						ADOQuery1->Parameters->ParamByName("LX")->Value = "改级别";
						ADOQuery1->Parameters->ParamByName("Operator")->Value = OperatorName;
						ADOQuery1->Parameters->ParamByName("DateTime")->Value = DateofLaunchCard;
						ADOQuery1->ExecSQL();
						ADOQuery1->Close();

						//更新CARD，CARD_F表

						sqlstr = "select * from CARD where BH='";
						sqlstr = sqlstr + cxTextEdit7->Text + "'";
						ADOQuery1->SQL->Clear();
						ADOQuery1->SQL->Add(sqlstr);
						ADOQuery1->Open();
						if(!ADOQuery1->IsEmpty())
						{
							ADOQuery1->Edit();
							ADOQuery1->FieldByName("JB")->AsFloat = kjb;
							ADOQuery1->Post();
						}

						ADOQuery1->Close();
						sqlstr = "select * from CARD_F where BH='";
						sqlstr = sqlstr + cxTextEdit7->Text + "'";
						ADOQuery1->SQL->Clear();
						ADOQuery1->SQL->Add(sqlstr);
						ADOQuery1->Open();
						if(!ADOQuery1->IsEmpty())
						{
							ADOQuery1->Edit();
							ADOQuery1->FieldByName("JB")->AsFloat = kjb;
							ADOQuery1->Post();
						}

						ShowMessage("卡级别修改成功!");
					}
				}
				else
				{
					ShowMessage("写卡函数加载失败！");
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TReadCardInfoFRM::cxTextEdit6KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<='0'||Key>'9'||(127 == Key)||(8 == Key)) && Key!='\b')
	{
    	if(13 == Key)
        {
            Key = 0;
        }
        else
        {
			Key=0;
			ShowMessage("请输入1到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------


