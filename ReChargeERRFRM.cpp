//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReChargeERRFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
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
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"
TReChargeERRForm *ReChargeERRForm;
#include "CardRechargeFRM.h"
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
__fastcall TReChargeERRForm::TReChargeERRForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TReChargeERRForm::FormShow(TObject *Sender)
{
	cxTextEdit1->Text = CardRechargeMoneyFRM->cxTextEdit1->Text;
	cxTextEdit2->Text = CardRechargeMoneyFRM->cxTextEdit2->Text;
	cxTextEdit3->Text = CardRechargeMoneyFRM->cxTextEdit3->Text;
	cxTextEdit4->Text = CardRechargeMoneyFRM->cxTextEdit4->Text;
	cxTextEdit5->Text = CardRechargeMoneyFRM->cxTextEdit5->Text;
	cxTextEdit6->Text = CardRechargeMoneyFRM->cxTextEdit6->Text;
	cxTextEdit7->Text = CardRechargeMoneyFRM->cxTextEdit7->Text;
	cxTextEdit8->Text = CardRechargeMoneyFRM->cxTextEdit8->Text;
	cxTextEdit9->Text = CardRechargeMoneyFRM->cxTextEdit9->Text;
	cxTextEdit10->Text = CardRechargeMoneyFRM->cxTextEdit10->Text;
	cxTextEdit11->Text = CardRechargeMoneyFRM->cxTextEdit11->Text;
	cxTextEdit12->Text = CardRechargeMoneyFRM->cxTextEdit12->Text;
	cxTextEdit15->Text = CardRechargeMoneyFRM->cxTextEdit15->Text;
	cxTextEdit16->Text = "";
	cxTextEdit17->Text = CardRechargeMoneyFRM->cxTextEdit17->Text;
	cxTextEdit18->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TReChargeERRForm::cxButton2Click(TObject *Sender)
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

	mode = 0x01;
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
				ADOReChargeQuery->Close();
				ADOReChargeQuery->SQL->Clear();
				ADOReChargeQuery->SQL->Add("select * from XTSET");
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

				ADOReChargeQuery->Close();

				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

				ADOReChargeQuery->Close();
				ADOReChargeQuery->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				ADOReChargeQuery->SQL->Add(tmpstr);
				ADOReChargeQuery->Open();
				if(!ADOReChargeQuery->IsEmpty())
				{
					if(0 != ADOReChargeQuery->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						ADOReChargeQuery->Close();
						return;
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					ADOReChargeQuery->Close();
					return;
				}
				ADOReChargeQuery->Close();

				ADOReChargeQuery->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				ADOReChargeQuery->SQL->Add(tmpstr);
				ADOReChargeQuery->Open();
				if(!ADOReChargeQuery->IsEmpty())
				{
					ADOReChargeQuery->Close();
					beepofreaddll(readcomno, '10');
					int oldkh = StrToInt(cxTextEdit1->Text.Trim());
					if(oldkh == tmpkh)
					{
						cxTextEdit18->Text = tmpye;
						HJLADOQ->Close();
						HJLADOQ->SQL->Clear();
						String Chksqlstr = "select * from HJL where KH=";
						Chksqlstr += tmpkh;
						Chksqlstr += " order by OPTIME asc";
						HJLADOQ->SQL->Add(Chksqlstr);
						HJLADOQ->Open();
						if(HJLADOQ->IsEmpty())
						{
							beepofreaddll(readcomno, '10');
							String ReChargeOutstr = "充值成功!卡余额为：";
							ReChargeOutstr += tmpye;
							ShowMessage(ReChargeOutstr);
							this->Close();
						}
						else
						{
							HJLADOQ->Last();
							if(tmpye == HJLADOQ->FieldByName("YE")->AsFloat)
							{
								beepofreaddll(readcomno, '10');
								String ReChargeOutstr = "充值成功!卡余额为：";
								ReChargeOutstr += tmpye;
								ShowMessage(ReChargeOutstr);
								HJLADOQ->Close();
								this->Close();
							}
							else
							{
								//写充值金额
								if(!LaunchWaterNewCard)//LaunchNewCard)
								{
									ShowMessage("写卡函数加载失败");
									return;
								}

								tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
								tmpsycs++;
								unsigned char writesynum[2];
								writesynum[0] = (char)(tmpsycs/256);
								writesynum[1] = (char)(tmpsycs%256);
								unsigned char writebalance[4];
						   //		ADOReChargeQuery->Last();
								int ReChargeMoney = HJLADOQ->FieldByName("JE")->AsInteger;
								double writetmpbalance = HJLADOQ->FieldByName("JE")->AsFloat;
								tmpye += writetmpbalance;
								writetmpbalance *= 100;
								writebalance[0] = 0x00;
								writebalance[1] = (unsigned char)((int)writetmpbalance/65536);
								writetmpbalance = (int)writetmpbalance%65536;
								writebalance[2] = (unsigned char)((int)writetmpbalance/256);
								writetmpbalance = (int)writetmpbalance%256;
								writebalance[3] = (unsigned char)writetmpbalance;
								WORD WriteStatus;

								String DateofLaunchCard;
								SYSTEMTIME tmpsystime;
								GetLocalTime(&tmpsystime);
								DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

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
															Delayms);     */

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
									ShowMessage("修正失败，请重试!");
									ADOReChargeQuery->Close();
									return;
								}
								else
								{
									//充值入库、入狗开始
									ADOReChargeQuery->Close();
									ADOReChargeQuery->SQL->Clear();
									String sqlstr = "insert into MX values(:BH,:KH,:SF_YE,";
									sqlstr = sqlstr + ":SFJE,:SYCS,:SFRQ,:JYNO,";
									sqlstr = sqlstr + ":GZZID,:SFLX,:CZY,:SCRQ)";
									ADOReChargeQuery->SQL->Add(sqlstr);
									ADOReChargeQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
									ADOReChargeQuery->Parameters->ParamByName("KH")->Value = tmpkh;
									ADOReChargeQuery->Parameters->ParamByName("SF_YE")->Value = tmpye;
									ADOReChargeQuery->Parameters->ParamByName("SFJE")->Value = ReChargeMoney;
									ADOReChargeQuery->Parameters->ParamByName("SYCS")->Value = tmpsycs;
									ADOReChargeQuery->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
									ADOReChargeQuery->Parameters->ParamByName("JYNO")->Value = 1001;
									ADOReChargeQuery->Parameters->ParamByName("GZZID")->Value = 1;
									ADOReChargeQuery->Parameters->ParamByName("SFLX")->Value = "a";
									ADOReChargeQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
									ADOReChargeQuery->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
									ADOReChargeQuery->ExecSQL();
									ADOReChargeQuery->Close();

									//插入CK表
									ADOReChargeQuery->SQL->Clear();
									sqlstr = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
									sqlstr += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
									ADOReChargeQuery->SQL->Add(sqlstr);
									ADOReChargeQuery->Parameters->ParamByName("kh")->Value = tmpkh;
									ADOReChargeQuery->Parameters->ParamByName("bh")->Value = cxTextEdit7->Text;
									ADOReChargeQuery->Parameters->ParamByName("sf_ye")->Value = tmpye;
									ADOReChargeQuery->Parameters->ParamByName("sf_fl")->Value = 1;
									ADOReChargeQuery->Parameters->ParamByName("ckxj")->Value = ReChargeMoney;
									ADOReChargeQuery->Parameters->ParamByName("glf")->Value = 0;
									ADOReChargeQuery->Parameters->ParamByName("ckje")->Value = ReChargeMoney;
									ADOReChargeQuery->Parameters->ParamByName("lqbt")->Value = 0;
									ADOReChargeQuery->Parameters->ParamByName("xkje")->Value = ReChargeMoney;
									ADOReChargeQuery->Parameters->ParamByName("sycs")->Value = tmpsycs;
									ADOReChargeQuery->Parameters->ParamByName("sfrq")->Value = DateofLaunchCard;
									ADOReChargeQuery->Parameters->ParamByName("jyno")->Value = 1001;
									ADOReChargeQuery->Parameters->ParamByName("gzzid")->Value = 1;
									ADOReChargeQuery->Parameters->ParamByName("sflx")->Value = "a";
									ADOReChargeQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
									ADOReChargeQuery->ExecSQL();
									ADOReChargeQuery->Close();

									//填写操作记录表
									sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
									ADOReChargeQuery->SQL->Clear();
									ADOReChargeQuery->SQL->Add(sqlstr);
									ADOReChargeQuery->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
									ADOReChargeQuery->Parameters->ParamByName("KH")->Value = tmpkh;
									ADOReChargeQuery->Parameters->ParamByName("JE")->Value = ReChargeMoney;
									ADOReChargeQuery->Parameters->ParamByName("YE")->Value = tmpye;
									ADOReChargeQuery->Parameters->ParamByName("LX")->Value = "充值";
									ADOReChargeQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
									ADOReChargeQuery->Parameters->ParamByName("DateTime")->Value = DateofLaunchCard;
									ADOReChargeQuery->ExecSQL();
									ADOReChargeQuery->Close();

									//更新CARD，CARD_F表

									sqlstr = "select * from CARD where BH='";
									sqlstr = sqlstr + cxTextEdit7->Text + "'";
									ADOReChargeQuery->SQL->Clear();
									ADOReChargeQuery->SQL->Add(sqlstr);
									ADOReChargeQuery->Open();
									if(!ADOReChargeQuery->IsEmpty())
									{
										ADOReChargeQuery->Edit();
										ADOReChargeQuery->FieldByName("SF_YE")->AsFloat = tmpye;
										ADOReChargeQuery->FieldByName("SFYEDT")->AsDateTime = StrToDateTime(DateofLaunchCard);
										ADOReChargeQuery->FieldByName("SYCS")->AsInteger = tmpsycs;
										ADOReChargeQuery->Post();
									}

									sqlstr = "select * from CARD_F where BH='";
									sqlstr = sqlstr + cxTextEdit7->Text + "'";
									ADOReChargeQuery->SQL->Clear();
									ADOReChargeQuery->SQL->Add(sqlstr);
									ADOReChargeQuery->Open();
									if(!ADOReChargeQuery->IsEmpty())
									{
										ADOReChargeQuery->Edit();
										ADOReChargeQuery->FieldByName("SF_YE")->AsFloat = tmpye;
										ADOReChargeQuery->FieldByName("SFYEDT")->AsDateTime = StrToDateTime(DateofLaunchCard);
										ADOReChargeQuery->FieldByName("SYCS")->AsInteger = tmpsycs;
										ADOReChargeQuery->Post();
									}

									ADOReChargeQuery->Close();

									//写加密狗充值总额
                                    if(DOGChk)
                                    {
                                        unsigned char tempbuf[8];
                                        SFK_ZE += ReChargeMoney;
                                        UpZETable->FieldByName("SFKZE")->AsFloat += ReChargeMoney;
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
									//充值入库、入狗结束
									beepofreaddll(readcomno, '10');
									String ReChargeOutstr = "充值成功!卡余额为：";
								//	ReChargeOutstr += tmpye;
									ReChargeOutstr += tmpye;
									ShowMessage(ReChargeOutstr);
								//	HJLADOQ->Last();
									HJLADOQ->Delete();
									HJLADOQ->Close();
									this->Close();
                                }
                            }
						}
					}
					else
					{
						beepofreaddll(readcomno, '10');
						ShowMessage("此卡不是充值出错的卡片，请更换!");
                    }

				//	ReadCardBTN->Enabled = false;
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					ADOReChargeQuery->Close();
				}
			}
		}
	}
	else
		ShowMessage("加载读写卡动态链接库失败！");
}
//---------------------------------------------------------------------------
