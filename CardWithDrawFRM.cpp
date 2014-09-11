//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "CardWithDrawFRM.h"
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

#include "QKnoticeFRM.h"
#include "WithDrawERRFRM.h"
TCardWithDrawMoneyFRM *CardWithDrawMoneyFRM;


//---------------------------------------------------------------------------
__fastcall TCardWithDrawMoneyFRM::TCardWithDrawMoneyFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCardWithDrawMoneyFRM::ExitWithDrawBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::ReadCardBTNClick(TObject *Sender)
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

	Delayms = DelaySecond;
	keymode = CARDPasswordEdition;
	secnum = UsingSecNUM;

	key[0] = CARDPassword[0];
	key[1] = CARDPassword[1];
	key[2] = CARDPassword[2];
	key[3] = CARDPassword[3];
	key[4] = CARDPassword[4];
	key[5] = CARDPassword[5];

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
	cxTextEdit15->Text = "";
	cxTextEdit16->Text = "";
	cxTextEdit17->Text = "";
	cxTextEdit18->Text = "";

	if(LoadHModule)
	{
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
		//		ADOWithDrawQuery->Close();
		//		ADOWithDrawQuery->SQL->Clear();
		//   	ADOWithDrawQuery->SQL->Add("select * from XTSET");
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

		//		ADOWithDrawQuery->Close();

				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

				ADOWithDrawQuery->Close();
				ADOWithDrawQuery->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				ADOWithDrawQuery->SQL->Add(tmpstr);
				ADOWithDrawQuery->Open();
				if(!ADOWithDrawQuery->IsEmpty())
				{
					if(0 != ADOWithDrawQuery->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						ADOWithDrawQuery->Close();
						return;
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					ADOWithDrawQuery->Close();
					return;
				}
				ADOWithDrawQuery->Close();

				ADOWithDrawQuery->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				ADOWithDrawQuery->SQL->Add(tmpstr);
				ADOWithDrawQuery->Open();
				if(!ADOWithDrawQuery->IsEmpty())
				{
					cxTextEdit7->Text = ADOWithDrawQuery->FieldByName("BH")->AsString;
					cxTextEdit2->Text = ADOWithDrawQuery->FieldByName("XM")->AsString;
					cxTextEdit11->Text = ADOWithDrawQuery->FieldByName("SFZH")->AsString;
					cxTextEdit12->Text = ADOWithDrawQuery->FieldByName("GRMM")->AsString;
					cxTextEdit17->Text = ADOWithDrawQuery->FieldByName("YJ")->AsString;
					cxTextEdit3->Text = ADOWithDrawQuery->FieldByName("BM")->AsString;
					cxTextEdit15->Text = ADOWithDrawQuery->FieldByName("SF_FL")->AsString;
					cxTextEdit4->Text = ADOWithDrawQuery->FieldByName("ZW")->AsString;
					cxTextEdit10->Text = ADOWithDrawQuery->FieldByName("ZB")->AsString;
					cxTextEdit9->Text = ADOWithDrawQuery->FieldByName("BZ")->AsString;
					cxTextEdit8->Text = ADOWithDrawQuery->FieldByName("XB")->AsString;
					ADOWithDrawQuery->Close();
					cxTextEdit1->Text = tmpkh;
					//cxTextEdit16->Text = tmpsycs;
					cxTextEdit18->Text = tmpye;
					cxTextEdit6->Text = cardtype[0];   //??
                    cxTextEdit5->Text = cardtype[0];

				//	ReadCardBTN->Enabled = false;
					WithDrawBTN->Enabled = true;

					if(5<tmpye)
						WithDraw5BTN->Enabled = true;
					if(10<tmpye)
						WithDraw10BTN->Enabled = true;
					if(20<tmpye)
						WithDraw20BTN->Enabled = true;
					if(30<tmpye)
						WithDraw30BTN->Enabled = true;
					if(40<tmpye)
						WithDraw40BTN->Enabled = true;
					if(50<tmpye)
						WithDraw50BTN->Enabled = true;
					if(60<tmpye)
						WithDraw60BTN->Enabled = true;
					if(70<tmpye)
						WithDraw70BTN->Enabled = true;
					if(80<tmpye)
						WithDraw80BTN->Enabled = true;
					if(90<tmpye)
						WithDraw90BTN->Enabled = true;
					if(100<tmpye)
						WithDraw100BTN->Enabled = true;
					if(150<tmpye)
						WithDraw150BTN->Enabled = true;
					if(200<tmpye)
						WithDraw200BTN->Enabled = true;
					if(500<tmpye)
						WithDraw500BTN->Enabled = true;
					if(1000<tmpye)
						WithDraw1000BTN->Enabled = true;

					beepofreaddll(readcomno, '10');
                    cxTextEdit16->SetFocus();
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					ADOWithDrawQuery->Close();
				}
			}
		}
	}
	else
		ShowMessage("加载读写卡动态链接库失败！");
}
//---------------------------------------------------------------------------

void TCardWithDrawMoneyFRM::Function_WithDraw(double WDMoney)
{
//	ShowMessage("WithDraw Money!");
	String Moutstr = "您确认对该卡取款";
    Moutstr += WDMoney;
    Moutstr += "元吗?";
	if(mrOk != MessageBox(this->Handle, Moutstr.t_str(), "确认取款金额", MB_OKCANCEL))
    	return;

	WORD status;
	WORD WriteStatus;
//	double tmpbalance;
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

	Delayms = DelaySecond;
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
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
                int chkkh = StrToInt(cxTextEdit1->Text);
                if(chkkh != tmpkh)
                {
                    ShowMessage("卡号与读卡卡号不匹配，请不要更换卡片!");
                	ReadCardBTN->Enabled = true;
                    WithDrawBTN->Enabled = false;
                    WithDraw5BTN->Enabled = false;
                    WithDraw10BTN->Enabled = false;
                    WithDraw20BTN->Enabled = false;
                    WithDraw30BTN->Enabled = false;
                    WithDraw40BTN->Enabled = false;
                    WithDraw50BTN->Enabled = false;
                    WithDraw60BTN->Enabled = false;
                    WithDraw70BTN->Enabled = false;
                    WithDraw80BTN->Enabled = false;
                    WithDraw90BTN->Enabled = false;
                    WithDraw100BTN->Enabled = false;
                    WithDraw150BTN->Enabled = false;
                    WithDraw200BTN->Enabled = false;
                    WithDraw500BTN->Enabled = false;
                    WithDraw1000BTN->Enabled = false;
                    return;
                }

				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpsycs++;
				unsigned char writesynum[2];
				writesynum[0] = (char)(tmpsycs/256);
				writesynum[1] = (char)(tmpsycs%256);

				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];

				tmpye = tmpintye/100-WDMoney;

				if(tmpye >= 0)
				{
					unsigned char writebalance[4];
					double writetmpbalance = tmpye;
					writetmpbalance *= 100;
					writebalance[0] = 0x00;
					writebalance[1] = (char)((int)writetmpbalance/65536);
					writetmpbalance = (int)writetmpbalance%65536;
					writebalance[2] = (char)((int)writetmpbalance/256);
					writetmpbalance = (int)writetmpbalance%256;
					writebalance[3] = (int)writetmpbalance;

                    //begin pacarddll
                    unsigned char sendbuf[26];
                    unsigned char sendbuflen = 26;
                    unsigned char senddelay = Delayms;
                    unsigned char recbuf[140];
                    unsigned char recbuflen;
                    unsigned char pblock = (secnum+1)*4+2;
                    unsigned char pmimamode = 0x60;
                    unsigned char pcommand = 0x01;
                    unsigned char pkeymode = CARDPasswordEdition;
                    unsigned char pkey[6];
                    memcpy(pkey,CARDPassword,6);
                    unsigned char comno[5];
                    memcpy(comno,readcomno,5);
                    pblock = (secnum+1)*4+2;
                    pmimamode = 0x60;
                    pcommand = 0x01;
                    pkeymode = CARDPasswordEdition;
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

                    WORD pstatus;
                    pstatus = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
                    if((0 == pstatus)&&(0 == recbuf[2]))
                    {
                        //入库
                        unsigned char precbuf[16];
                        ZeroMemory(precbuf, 16);
                        memcpy(precbuf, &recbuf[10], 16);
                        if((0x55 == precbuf[14])&&(0xaa == precbuf[15]))
                        {
                            double xf1;
                            double xf2;
                            int jqh;
                            int cjkh;
                            xf1 = ((double)precbuf[0]+(double)precbuf[1]*256+
                                    (double)precbuf[2]*256*256+(double)precbuf[3]*256*256*256)/100;
                            xf2 = ((double)(precbuf[4]^0xff)+(double)(precbuf[5]^0xff)*256+
                                    (double)(precbuf[6]^0xff)*256*256+(double)(precbuf[7]^0xff)*256*256*256)/100;
                            if(xf1 == xf2)
                            {
                                jqh = (int)precbuf[8]*256+(int)precbuf[9];
                                cjkh = (int)precbuf[10]*256*256*256+(int)precbuf[11]*256*256+
                                        (int)precbuf[12]*256+(int)precbuf[13];
                                //入库操作
                                ADOWithDrawQuery->Close();
                                String tjsqlstr = "insert into WTJ values(:JH,:CJKH,:XFZE,:SCSJ)";
                                ADOWithDrawQuery->SQL->Clear();
                                ADOWithDrawQuery->SQL->Add(tjsqlstr);
                                ADOWithDrawQuery->Parameters->ParamByName("JH")->Value = jqh;
                                ADOWithDrawQuery->Parameters->ParamByName("CJKH")->Value = cjkh;
                            //    ReChargeADOQ->Parameters->ParamByName("KS")->Value = cardks;
                                ADOWithDrawQuery->Parameters->ParamByName("XFZE")->Value = xf1;
                                ADOWithDrawQuery->Parameters->ParamByName("SCSJ")->Value = DateTimeToStr(Now());
                                ADOWithDrawQuery->ExecSQL();
                            }
                        }
                    }
                    //end pacarddll

					if(LaunchWaterNewCard)//LaunchNewCard)
					{
						String DateofLaunchCard;
						SYSTEMTIME tmpsystime;
						GetLocalTime(&tmpsystime);
						DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

						ADOTable1->TableName = "HJL";
						ADOTable1->Active = true;
						ADOTable1->InsertRecord(ARRAYOFCONST((cxTextEdit7->Text,tmpkh,tmpye,WDMoney,tmpsycs,"d",OperatorName,DateofLaunchCard)));

		  /*				String hjlsqlstr = "insert into HJL values(:BH,:KH,:YE,:JE,:SFLX,:CZY,:OPTIME)";
                        HJLADOQ->Close();
						HJLADOQ->SQL->Clear();
						HJLADOQ->SQL->Add(hjlsqlstr);
						HJLADOQ->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
						HJLADOQ->Parameters->ParamByName("KH")->Value = tmpkh;
						HJLADOQ->Parameters->ParamByName("YE")->Value = tmpye;
						HJLADOQ->Parameters->ParamByName("JE")->Value = WDMoney;
						HJLADOQ->Parameters->ParamByName("SFLX")->Value = "d";
						HJLADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
						HJLADOQ->Parameters->ParamByName("OPTIME")->Value = DateofLaunchCard;
						HJLADOQ->ExecSQL();     */

				  /*		WriteStatus = LaunchNewCard(readcomno,
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
													Delayms);      */
                  		cardtype[0] = 0x04;
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
							WORD chkstatus;
							WORD chkWriteStatus;
							int chktmpbalance;
							int chktmpkh,chktmpsycs;
							double chktmpintye;
							double chktmpye;
							unsigned char chkkeymode,chksecnum,chkDelayms,chkmode;
							unsigned char chkkey[6];
							unsigned char chkdwmm[6];
							unsigned char chkdaytime[4];
							unsigned char chkkh[4];
							unsigned char chkbalance[4];
							unsigned char chkcardtype[1];
							unsigned char chkczmm[3];
							unsigned char chksynum[3];

							chkDelayms = DelaySecond;//0x00;
							chkkeymode = CARDPasswordEdition;
							chkmode = 0x01;
							chksecnum = UsingSecNUM;

							chkkey[0] = CARDPassword[0];
							chkkey[1] = CARDPassword[1];
							chkkey[2] = CARDPassword[2];
							chkkey[3] = CARDPassword[3];
							chkkey[4] = CARDPassword[4];
							chkkey[5] = CARDPassword[5];

				   //			chkstatus = readcardinfo(readcomno,chkkeymode,chksecnum,chkkey,chkkh,chkbalance,
				   //					chkdwmm,chksynum,chkdaytime,chkcardtype,chkczmm,chkDelayms);
                   			chkstatus = readwatercardinfo(readcomno,chkkeymode,chksecnum,chkkey,chkkh,chkbalance,
                            								chkdwmm,chkdaytime,chkcardtype,chkDelayms);
							if(chkstatus > 99)
							{
								ShowMessage("取款操作有误!");
							}
							else if (1 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (2 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (4 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (5 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (6 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (10 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (0 != chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else
							{
                                double chktmpintye = ((double)chkbalance[1]*256*256+(double)chkbalance[2]*256+(double)chkbalance[3])/100;
								if(tmpye == chktmpintye)
								{
									//MX
									ADOWithDrawQuery->Close();
									ADOWithDrawQuery->SQL->Clear();
									String sqlstr = "insert into MX values(:BH,:KH,:SF_YE,";
									sqlstr = sqlstr + ":SFJE,:SYCS,:SFRQ,:JYNO,";
									sqlstr = sqlstr + ":GZZID,:SFLX,:CZY,:SCRQ)";
									ADOWithDrawQuery->SQL->Add(sqlstr);
									ADOWithDrawQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
									ADOWithDrawQuery->Parameters->ParamByName("KH")->Value = tmpkh;
									ADOWithDrawQuery->Parameters->ParamByName("SF_YE")->Value = tmpye;
									ADOWithDrawQuery->Parameters->ParamByName("SFJE")->Value = WDMoney;
									ADOWithDrawQuery->Parameters->ParamByName("SYCS")->Value = tmpsycs;
									ADOWithDrawQuery->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
									ADOWithDrawQuery->Parameters->ParamByName("JYNO")->Value = 1001;
									ADOWithDrawQuery->Parameters->ParamByName("GZZID")->Value = 1;
									ADOWithDrawQuery->Parameters->ParamByName("SFLX")->Value = "d";
									ADOWithDrawQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
									ADOWithDrawQuery->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
									ADOWithDrawQuery->ExecSQL();
									ADOWithDrawQuery->Close();

									//CK

									ADOWithDrawQuery->SQL->Clear();
									sqlstr = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
									sqlstr += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
									ADOWithDrawQuery->SQL->Add(sqlstr);
									ADOWithDrawQuery->Parameters->ParamByName("kh")->Value = tmpkh;
									ADOWithDrawQuery->Parameters->ParamByName("bh")->Value = cxTextEdit7->Text;
									ADOWithDrawQuery->Parameters->ParamByName("sf_ye")->Value = tmpye;
									ADOWithDrawQuery->Parameters->ParamByName("sf_fl")->Value = 1;
									ADOWithDrawQuery->Parameters->ParamByName("ckxj")->Value = -WDMoney;
									ADOWithDrawQuery->Parameters->ParamByName("glf")->Value = 0;
									ADOWithDrawQuery->Parameters->ParamByName("ckje")->Value = -WDMoney;
									ADOWithDrawQuery->Parameters->ParamByName("lqbt")->Value = 0;
									ADOWithDrawQuery->Parameters->ParamByName("xkje")->Value = -WDMoney;
									ADOWithDrawQuery->Parameters->ParamByName("sycs")->Value = tmpsycs;
									ADOWithDrawQuery->Parameters->ParamByName("sfrq")->Value = DateofLaunchCard;
									ADOWithDrawQuery->Parameters->ParamByName("jyno")->Value = 1001;
									ADOWithDrawQuery->Parameters->ParamByName("gzzid")->Value = 1;
									ADOWithDrawQuery->Parameters->ParamByName("sflx")->Value = "d";
									ADOWithDrawQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
									ADOWithDrawQuery->ExecSQL();
									ADOWithDrawQuery->Close();

									//填写操作记录表
									sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
									ADOWithDrawQuery->SQL->Clear();
									ADOWithDrawQuery->SQL->Add(sqlstr);
									ADOWithDrawQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
									ADOWithDrawQuery->Parameters->ParamByName("KH")->Value = tmpkh;
									ADOWithDrawQuery->Parameters->ParamByName("JE")->Value = -WDMoney;
									ADOWithDrawQuery->Parameters->ParamByName("YE")->Value = tmpye;
									ADOWithDrawQuery->Parameters->ParamByName("LX")->Value = "取款";
									ADOWithDrawQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
									ADOWithDrawQuery->Parameters->ParamByName("DateTime")->Value = DateofLaunchCard;
									ADOWithDrawQuery->ExecSQL();
									ADOWithDrawQuery->Close();
									//更新CARD，CARD_F表

									sqlstr = "select * from CARD where BH='";
									sqlstr = sqlstr + cxTextEdit7->Text + "'";
									ADOWithDrawQuery->SQL->Clear();
									ADOWithDrawQuery->SQL->Add(sqlstr);
									ADOWithDrawQuery->Open();
									if(!ADOWithDrawQuery->IsEmpty())
									{
										ADOWithDrawQuery->Edit();
										ADOWithDrawQuery->FieldByName("SF_YE")->AsFloat = tmpye;
										ADOWithDrawQuery->FieldByName("SFYEDT")->AsDateTime = StrToDateTime(DateofLaunchCard);
										ADOWithDrawQuery->FieldByName("SYCS")->AsInteger = tmpsycs;
										ADOWithDrawQuery->Post();
									}

									sqlstr = "select * from CARD_F where BH='";
									sqlstr = sqlstr + cxTextEdit7->Text + "'";
									ADOWithDrawQuery->SQL->Clear();
									ADOWithDrawQuery->SQL->Add(sqlstr);
									ADOWithDrawQuery->Open();
									if(!ADOWithDrawQuery->IsEmpty())
									{
										ADOWithDrawQuery->Edit();
										ADOWithDrawQuery->FieldByName("SF_YE")->AsFloat = tmpye;
										ADOWithDrawQuery->FieldByName("SFYEDT")->AsDateTime = StrToDateTime(DateofLaunchCard);
										ADOWithDrawQuery->FieldByName("SYCS")->AsInteger = tmpsycs;
										ADOWithDrawQuery->Post();
									}

									ADOWithDrawQuery->Close();

									ADOTable1->Delete();
									CQKLogStream<<"QK,"<<tmpkh<<","<<WDMoney<<","<<DateofLaunchCard.t_str()<<","<<OperatorName.t_str()<<endl;
									beepofreaddll(readcomno, '10');
									String noticestr = "取款成功!现在卡内余额为：";
									noticestr += tmpye;
									QKnoticeform->Panel1->Caption = noticestr;
									QKnoticeform->ShowModal();
								}
								else
								{
									ShowMessage("写卡错误，取款失败，请修正!");
									WithDrawERRForm->ShowModal();
                                }
							}
						}
						else
						{
							WORD chkstatus;
							WORD chkWriteStatus;
							int chktmpbalance;
							int chktmpkh,chktmpsycs;
							double chktmpintye;
							double chktmpye;
							unsigned char chkkeymode,chksecnum,chkDelayms,chkmode;
							unsigned char chkkey[6];
							unsigned char chkdwmm[6];
							unsigned char chkdaytime[4];
							unsigned char chkkh[4];
							unsigned char chkbalance[4];
							unsigned char chkcardtype[1];
							unsigned char chkczmm[3];
							unsigned char chksynum[3];

							chkDelayms = DelaySecond;//0x00;
							chkkeymode = CARDPasswordEdition;
							chkmode = 0x01;
							chksecnum = UsingSecNUM;

							chkkey[0] = CARDPassword[0];
							chkkey[1] = CARDPassword[1];
							chkkey[2] = CARDPassword[2];
							chkkey[3] = CARDPassword[3];
							chkkey[4] = CARDPassword[4];
							chkkey[5] = CARDPassword[5];

					  //		chkstatus = readcardinfo(readcomno,chkkeymode,chksecnum,chkkey,chkkh,chkbalance,
					  //				chkdwmm,chksynum,chkdaytime,chkcardtype,chkczmm,chkDelayms);
                      		chkstatus = readwatercardinfo(readcomno,chkkeymode,chksecnum,chkkey,chkkh,chkbalance,
                            								chkdwmm,chkdaytime,chkcardtype,chkDelayms);
							if(chkstatus > 99)
							{
								ShowMessage("取款操作有误!");
							}
							else if (1 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (2 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (4 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (5 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (6 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (10 == chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else if (0 != chkstatus)
							{
								ShowMessage("取款操作有误!");
							}
							else
							{
								//MX
								ADOWithDrawQuery->Close();
								ADOWithDrawQuery->SQL->Clear();
								String sqlstr = "insert into MX values(:BH,:KH,:SF_YE,";
								sqlstr = sqlstr + ":SFJE,:SYCS,:SFRQ,:JYNO,";
								sqlstr = sqlstr + ":GZZID,:SFLX,:CZY,:SCRQ)";
								ADOWithDrawQuery->SQL->Add(sqlstr);
								ADOWithDrawQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
								ADOWithDrawQuery->Parameters->ParamByName("KH")->Value = tmpkh;
								ADOWithDrawQuery->Parameters->ParamByName("SF_YE")->Value = tmpye;
								ADOWithDrawQuery->Parameters->ParamByName("SFJE")->Value = WDMoney;
								ADOWithDrawQuery->Parameters->ParamByName("SYCS")->Value = tmpsycs;
								ADOWithDrawQuery->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
								ADOWithDrawQuery->Parameters->ParamByName("JYNO")->Value = 1001;
								ADOWithDrawQuery->Parameters->ParamByName("GZZID")->Value = 1;
								ADOWithDrawQuery->Parameters->ParamByName("SFLX")->Value = "d";
								ADOWithDrawQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
								ADOWithDrawQuery->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
								ADOWithDrawQuery->ExecSQL();
								ADOWithDrawQuery->Close();

								//MXBAK
						 /*		ADOWithDrawQuery->SQL->Clear();
								sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,";
								sqlstr = sqlstr + ":SFJE,:SYCS,:SFRQ,:JYNO,";
								sqlstr = sqlstr + ":GZZID,:SFLX,:CZY,:SCRQ)";
								ADOWithDrawQuery->SQL->Add(sqlstr);
								ADOWithDrawQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
								ADOWithDrawQuery->Parameters->ParamByName("KH")->Value = tmpkh;
								ADOWithDrawQuery->Parameters->ParamByName("SF_YE")->Value = tmpye;
								ADOWithDrawQuery->Parameters->ParamByName("SFJE")->Value = WDMoney;
								ADOWithDrawQuery->Parameters->ParamByName("SYCS")->Value = tmpsycs;
								ADOWithDrawQuery->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
								ADOWithDrawQuery->Parameters->ParamByName("JYNO")->Value = 1001;
								ADOWithDrawQuery->Parameters->ParamByName("GZZID")->Value = 1;
								ADOWithDrawQuery->Parameters->ParamByName("SFLX")->Value = "d";
								ADOWithDrawQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
								ADOWithDrawQuery->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
								ADOWithDrawQuery->ExecSQL();
								ADOWithDrawQuery->Close();  */


								//CK

								ADOWithDrawQuery->SQL->Clear();
								sqlstr = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
								sqlstr += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
								ADOWithDrawQuery->SQL->Add(sqlstr);
								ADOWithDrawQuery->Parameters->ParamByName("kh")->Value = tmpkh;
								ADOWithDrawQuery->Parameters->ParamByName("bh")->Value = cxTextEdit7->Text;
								ADOWithDrawQuery->Parameters->ParamByName("sf_ye")->Value = tmpye;
								ADOWithDrawQuery->Parameters->ParamByName("sf_fl")->Value = 1;
								ADOWithDrawQuery->Parameters->ParamByName("ckxj")->Value = -WDMoney;
								ADOWithDrawQuery->Parameters->ParamByName("glf")->Value = 0;
								ADOWithDrawQuery->Parameters->ParamByName("ckje")->Value = -WDMoney;
								ADOWithDrawQuery->Parameters->ParamByName("lqbt")->Value = 0;
								ADOWithDrawQuery->Parameters->ParamByName("xkje")->Value = -WDMoney;
								ADOWithDrawQuery->Parameters->ParamByName("sycs")->Value = tmpsycs;
								ADOWithDrawQuery->Parameters->ParamByName("sfrq")->Value = DateofLaunchCard;
								ADOWithDrawQuery->Parameters->ParamByName("jyno")->Value = 1001;
								ADOWithDrawQuery->Parameters->ParamByName("gzzid")->Value = 1;
								ADOWithDrawQuery->Parameters->ParamByName("sflx")->Value = "d";
								ADOWithDrawQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
								ADOWithDrawQuery->ExecSQL();
								ADOWithDrawQuery->Close();

								//填写操作记录表
								sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
								ADOWithDrawQuery->SQL->Clear();
								ADOWithDrawQuery->SQL->Add(sqlstr);
								ADOWithDrawQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
								ADOWithDrawQuery->Parameters->ParamByName("KH")->Value = tmpkh;
								ADOWithDrawQuery->Parameters->ParamByName("JE")->Value = -WDMoney;
								ADOWithDrawQuery->Parameters->ParamByName("YE")->Value = tmpye;
								ADOWithDrawQuery->Parameters->ParamByName("LX")->Value = "取款";
								ADOWithDrawQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
								ADOWithDrawQuery->Parameters->ParamByName("DateTime")->Value = DateofLaunchCard;
								ADOWithDrawQuery->ExecSQL();
								ADOWithDrawQuery->Close();
								//更新CARD，CARD_F表

								sqlstr = "select * from CARD where BH='";
								sqlstr = sqlstr + cxTextEdit7->Text + "'";
								ADOWithDrawQuery->SQL->Clear();
								ADOWithDrawQuery->SQL->Add(sqlstr);
								ADOWithDrawQuery->Open();
								if(!ADOWithDrawQuery->IsEmpty())
								{
									ADOWithDrawQuery->Edit();
									ADOWithDrawQuery->FieldByName("SF_YE")->AsFloat = tmpye;
									ADOWithDrawQuery->FieldByName("SFYEDT")->AsDateTime = StrToDateTime(DateofLaunchCard);
									ADOWithDrawQuery->FieldByName("SYCS")->AsInteger = tmpsycs;
									ADOWithDrawQuery->Post();
								}

								sqlstr = "select * from CARD_F where BH='";
								sqlstr = sqlstr + cxTextEdit7->Text + "'";
								ADOWithDrawQuery->SQL->Clear();
								ADOWithDrawQuery->SQL->Add(sqlstr);
								ADOWithDrawQuery->Open();
								if(!ADOWithDrawQuery->IsEmpty())
								{
									ADOWithDrawQuery->Edit();
									ADOWithDrawQuery->FieldByName("SF_YE")->AsFloat = tmpye;
									ADOWithDrawQuery->FieldByName("SFYEDT")->AsDateTime = StrToDateTime(DateofLaunchCard);
									ADOWithDrawQuery->FieldByName("SYCS")->AsInteger = tmpsycs;
									ADOWithDrawQuery->Post();
								}

								ADOWithDrawQuery->Close();

								//写加密狗减去取款
                                if(DOGChk)
                                {
                                    unsigned char tempbuf[8];
                                    SFK_ZE -= WDMoney;
                                    UpZETable->FieldByName("SFKZE")->AsFloat -= WDMoney;
                                    memcpy(tempbuf,&SFK_ZE,8);
                                    unsigned char hightempchar1;
                                    unsigned char lowtempchar1;
                                    for(int t = 0; t < 8; t++)
                                    {
                                        hightempchar1 = tempbuf[t]&0xf0;
                                        lowtempchar1 = tempbuf[t]&0x0f;

                                        hightempchar1 = hightempchar1>>4;
                                        hightempchar1 = hightempchar1&0x0f;

                                        lowtempchar1 = lowtempchar1<<4;
                                        lowtempchar1 = lowtempchar1&0xf0;

                                        tempbuf[t] = hightempchar1|lowtempchar1;
                                    }
                                    int dogoffset = 0x0034;
                                    int doglen = 8;
                                    RY3_Write(doghandle,dogoffset,tempbuf,doglen);
                                }
								//写加密狗完毕

								double chktmpintye = ((double)chkbalance[1]*256*256+(double)chkbalance[2]*256+(double)chkbalance[3])/100;
								if(tmpye == chktmpintye)
								{
									ADOTable1->Delete();
									CQKLogStream<<"QK,"<<tmpkh<<","<<WDMoney<<","<<DateofLaunchCard.t_str()<<","<<OperatorName.t_str()<<endl;
									beepofreaddll(readcomno, '10');
									String noticestr = "取款成功!现在卡内余额为：";
									noticestr += tmpye;
									QKnoticeform->Panel1->Caption = noticestr;
									QKnoticeform->ShowModal();
								//	ShowMessage(noticestr);
								}
							}
						}
					}
					else
					{
						ShowMessage("写卡函数加载失败!");
					}
				}
				else
				{
					ShowMessage("取款钱数不能大于卡内余额!");
                }
			}
		}
	}

	ReadCardBTN->Enabled = true;
	WithDrawBTN->Enabled = false;
	WithDraw5BTN->Enabled = false;
	WithDraw10BTN->Enabled = false;
	WithDraw20BTN->Enabled = false;
	WithDraw30BTN->Enabled = false;
	WithDraw40BTN->Enabled = false;
	WithDraw50BTN->Enabled = false;
	WithDraw60BTN->Enabled = false;
	WithDraw70BTN->Enabled = false;
	WithDraw80BTN->Enabled = false;
	WithDraw90BTN->Enabled = false;
	WithDraw100BTN->Enabled = false;
	WithDraw150BTN->Enabled = false;
	WithDraw200BTN->Enabled = false;
	WithDraw500BTN->Enabled = false;
	WithDraw1000BTN->Enabled = false;

	cxTextEdit18->Text = tmpye;
	return;
}

//---------------------------------------------------------------------------
void __fastcall TCardWithDrawMoneyFRM::WithDrawBTNClick(TObject *Sender)
{
	if(!cxTextEdit16->Text.IsEmpty())
	{
		if(!cxTextEdit18->Text.IsEmpty())
		{
			double MoneyInCard = StrToFloat(cxTextEdit18->Text);
			double MoneyWithDraw = StrToFloat(cxTextEdit16->Text);
			if(MoneyInCard >= MoneyWithDraw)
			{
				Function_WithDraw(MoneyWithDraw);
			}
			else
				ShowMessage("取款金额不能大于卡余额！");
		}
	}
	else
	{
		ShowMessage("请输入取款金额！");
    }
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw5BTNClick(TObject *Sender)
{
	Function_WithDraw(5);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw10BTNClick(TObject *Sender)
{
	Function_WithDraw(10);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw20BTNClick(TObject *Sender)
{
	Function_WithDraw(20);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw30BTNClick(TObject *Sender)
{
	Function_WithDraw(30);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw40BTNClick(TObject *Sender)
{
	Function_WithDraw(40);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw50BTNClick(TObject *Sender)
{
	Function_WithDraw(50);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw60BTNClick(TObject *Sender)
{
	Function_WithDraw(60);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw70BTNClick(TObject *Sender)
{
	Function_WithDraw(70);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw80BTNClick(TObject *Sender)
{
	Function_WithDraw(80);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw90BTNClick(TObject *Sender)
{
	Function_WithDraw(90);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw100BTNClick(TObject *Sender)
{
	Function_WithDraw(100);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw150BTNClick(TObject *Sender)
{
	Function_WithDraw(150);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw200BTNClick(TObject *Sender)
{
	Function_WithDraw(200);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw500BTNClick(TObject *Sender)
{
	Function_WithDraw(500);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::WithDraw1000BTNClick(TObject *Sender)
{
	Function_WithDraw(1000);
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::cxTextEdit16KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b' && Key == VK_RETURN)
	{
		if(Key != '.' && Key != VK_RETURN)
		{
			Key=0;
			ShowMessage("请输入0到9之间的数字!");
        }

        if(Key == VK_RETURN)
        	WithDrawBTN->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TCardWithDrawMoneyFRM::cxTextEdit16Exit(TObject *Sender)
{
	if(!cxTextEdit16->Text.IsEmpty())
    {
        double trydouble;
        try
        {
            trydouble = StrToFloat(cxTextEdit16->Text);
        }
        catch(...)
        {
            ShowMessage("您输入的取款金额有问题，请重新输入!");
            cxTextEdit16->Text = "";
            return;
        }
    }
}
//---------------------------------------------------------------------------

