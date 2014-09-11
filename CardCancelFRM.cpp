//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "CardCancelFRM.h"
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
TCardCanceledFRM *CardCanceledFRM;
//---------------------------------------------------------------------------
__fastcall TCardCanceledFRM::TCardCanceledFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCardCanceledFRM::cxButton1Click(TObject *Sender)
{
	if(LoadHModule)
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
		  //		CardCancelADOQ->Close();
		  //		CardCancelADOQ->SQL->Clear();
		  //		CardCancelADOQ->SQL->Add("select * from XTSET");
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

		  //		CardCancelADOQ->Close();

				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

				CardCancelADOQ->Close();
				CardCancelADOQ->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				CardCancelADOQ->SQL->Add(tmpstr);
				CardCancelADOQ->Open();
				if(!CardCancelADOQ->IsEmpty())
				{
					if(0 != CardCancelADOQ->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						CardCancelADOQ->Close();
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					CardCancelADOQ->Close();
				}
				CardCancelADOQ->Close();

				CardCancelADOQ->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				CardCancelADOQ->SQL->Add(tmpstr);
				CardCancelADOQ->Open();
				if(!CardCancelADOQ->IsEmpty())
				{
					cxTextEdit7->Text = CardCancelADOQ->FieldByName("BH")->AsString.Trim();
					cxTextEdit2->Text = CardCancelADOQ->FieldByName("XM")->AsString.Trim();
					cxTextEdit11->Text = CardCancelADOQ->FieldByName("SFZH")->AsString.Trim();
					cxTextEdit12->Text = CardCancelADOQ->FieldByName("GRMM")->AsString.Trim();
					cxTextEdit18->Text = CardCancelADOQ->FieldByName("YJ")->AsString.Trim();
					cxTextEdit3->Text = CardCancelADOQ->FieldByName("BM")->AsString.Trim();
					cxTextEdit15->Text = CardCancelADOQ->FieldByName("SF_FL")->AsString.Trim();
					cxTextEdit4->Text = CardCancelADOQ->FieldByName("ZW")->AsString.Trim();
					cxTextEdit10->Text = CardCancelADOQ->FieldByName("ZB")->AsString.Trim();
					cxTextEdit9->Text = CardCancelADOQ->FieldByName("BZ")->AsString.Trim();
					cxTextEdit8->Text = CardCancelADOQ->FieldByName("XB")->AsString.Trim();
					CardCancelADOQ->Close();
					cxTextEdit1->Text = tmpkh;
					//cxTextEdit16->Text = tmpsycs;
					cxTextEdit17->Text = tmpye;
					cxTextEdit6->Text = cardtype[0];   //??
                    cxButton2->Enabled = true;
					beepofreaddll(readcomno, '10');
					cxButton2->SetFocus();
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					CardCancelADOQ->Close();
				}
			}
		}
		else
			ShowMessage("读卡函数加载失败！");
	}
	else
		ShowMessage("加载读写卡动态链接库失败！");
}
//---------------------------------------------------------------------------

void __fastcall TCardCanceledFRM::cxButton3Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCardCanceledFRM::cxButton2Click(TObject *Sender)
{
/*	double moneyindatebase;
	if(!cxTextEdit1->Text.IsEmpty())
	{
		CardCancelADOQ->Close();
		CardCancelADOQ->SQL->Clear();
		String checksqlstr = "select * from CARD where BH='";
		checksqlstr += cxTextEdit7->Text;
		checksqlstr += "'";
		CardCancelADOQ->SQL->Add(checksqlstr);
		CardCancelADOQ->Open();
		if(!CardCancelADOQ->IsEmpty())
		{
			moneyindatebase = CardCancelADOQ->FieldByName("SF_YE")->AsFloat;
		}
		else
		{
			ShowMessage("数据库中没有该卡片，无法退卡!");
        }
	}
	else
	{
		ShowMessage("无卡片信息，无法退卡!");
		return;
	}   */

	if(LoadHModule)
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

				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

				CardCancelADOQ->Close();
				CardCancelADOQ->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				CardCancelADOQ->SQL->Add(tmpstr);
				CardCancelADOQ->Open();
				if(!CardCancelADOQ->IsEmpty())
				{
					if(0 != CardCancelADOQ->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						CardCancelADOQ->Close();
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					CardCancelADOQ->Close();
				}

				CardCancelADOQ->Close();
				CardCancelADOQ->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				CardCancelADOQ->SQL->Add(tmpstr);
				CardCancelADOQ->Open();
				if(!CardCancelADOQ->IsEmpty())
				{
					int tmpyj = CardCancelADOQ->FieldByName("TYJ")->AsInteger;
					cxTextEdit7->Text = CardCancelADOQ->FieldByName("BH")->AsString.Trim();
					cxTextEdit2->Text = CardCancelADOQ->FieldByName("XM")->AsString.Trim();
					cxTextEdit11->Text = CardCancelADOQ->FieldByName("SFZH")->AsString.Trim();
					cxTextEdit12->Text = CardCancelADOQ->FieldByName("GRMM")->AsString.Trim();
					cxTextEdit18->Text = CardCancelADOQ->FieldByName("YJ")->AsString.Trim();
					cxTextEdit3->Text = CardCancelADOQ->FieldByName("BM")->AsString.Trim();
					cxTextEdit15->Text = CardCancelADOQ->FieldByName("SF_FL")->AsString.Trim();
					cxTextEdit4->Text = CardCancelADOQ->FieldByName("ZW")->AsString.Trim();
					cxTextEdit10->Text = CardCancelADOQ->FieldByName("ZB")->AsString.Trim();
					cxTextEdit9->Text = CardCancelADOQ->FieldByName("BZ")->AsString.Trim();
					cxTextEdit8->Text = CardCancelADOQ->FieldByName("XB")->AsString.Trim();
					double moneyindatabase = CardCancelADOQ->FieldByName("SF_YE")->AsFloat;
					CardCancelADOQ->Close();
					cxTextEdit1->Text = tmpkh;
					//cxTextEdit16->Text = tmpsycs;
					cxTextEdit17->Text = tmpye;
					cxTextEdit6->Text = cardtype[0];   //??


		/*			if(moneyindatabase > tmpye)
					{
						if((moneyindatabase-tmpye)>=0.01)
						{
							ShowMessage("该卡的消费记录没有被完全采集，无法退卡，请在采集完数据后进行退卡!");
							return;
						}
					}
					else if(moneyindatabase < tmpye)
					{
						if((tmpye- moneyindatabase)>=0.01)
						{
							ShowMessage("该卡的消费记录没有被完全采集，无法退卡，请在采集完数据后进行退卡!");
							return;
						}
                    }         */
                    //使用pacarddll获取最近消费记录
                    unsigned char sendbuf[26];
                    unsigned char sendbuflen = 26;
                    unsigned char senddelay = Delayms;
                    unsigned char recbuf[140];
                    unsigned char recbuflen;
                    unsigned char pblock = (secnum+1)*4+2;
                    unsigned char pmimamode = 0x60;
                    unsigned char pcommand = 0x01;
                    unsigned char pkeymode = 0x03;
                    unsigned char pkey[6];
                    memcpy(pkey,CARDPassword,6);
                    unsigned char comno[5];
                    memcpy(comno,readcomno,5);


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
                                CardCancelADOQ->Close();
                                String tjsqlstr = "insert into WTJ values(:JH,:CJKH,:XFZE,:SCSJ)";
                                CardCancelADOQ->SQL->Clear();
                                CardCancelADOQ->SQL->Add(tjsqlstr);
                                CardCancelADOQ->Parameters->ParamByName("JH")->Value = jqh;
                                CardCancelADOQ->Parameters->ParamByName("CJKH")->Value = cjkh;
                                CardCancelADOQ->Parameters->ParamByName("XFZE")->Value = xf1;
                                CardCancelADOQ->Parameters->ParamByName("SCSJ")->Value = DateTimeToStr(Now());
                                CardCancelADOQ->ExecSQL();
                            }
                        }
                    }
                    //end pacarddll

					//status = ClearCardInfoProc(readcomno, keymode, secnum, key, Delayms);
                    //begin to clear card

                    pblock = (secnum+1)*4+0;
                    pmimamode = 0x60;
                    pcommand = 0x02;
                    pkeymode = keymode;
                    memcpy(pkey,CARDPassword,6);
                    memcpy(comno,readcomno,5);
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
                    status = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
                    if(status)
                    {
                        ShowMessage("退卡失败，请重试或联系技术人员！");
                        return;
                    }

                    pblock = (secnum+1)*4+1;
                    pmimamode = 0x60;
                    pcommand = 0x02;
                    pkeymode = keymode;
                    memcpy(pkey,CARDPassword,6);
                    memcpy(comno,readcomno,5);
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
                    status = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
                    if(status)
                    {
                        ShowMessage("退卡失败，请重试或联系技术人员！");
                        return;
                    }

                    pblock = (secnum+1)*4+2;
                    pmimamode = 0x60;
                    pcommand = 0x02;
                    pkeymode = keymode;
                    memcpy(pkey,CARDPassword,6);
                    memcpy(comno,readcomno,5);
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
                    status = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
                    if(status)
                    {
                        ShowMessage("退卡失败，请重试或联系技术人员！");
                        return;
                    }

                    pblock = (secnum+2)*4+0;
                    pmimamode = 0x60;
                    pcommand = 0x02;
                    pkeymode = keymode;
                    memcpy(pkey,CARDPassword,6);
                    memcpy(comno,readcomno,5);
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
                    pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

                    pblock = (secnum+2)*4+1;
                    pmimamode = 0x60;
                    pcommand = 0x02;
                    pkeymode = keymode;
                    memcpy(pkey,CARDPassword,6);
                    memcpy(comno,readcomno,5);
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
                    pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

                    pblock = (secnum+2)*4+2;
                    pmimamode = 0x60;
                    pcommand = 0x02;
                    pkeymode = keymode;
                    memcpy(pkey,CARDPassword,6);
                    memcpy(comno,readcomno,5);
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
                    pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

                    //end to clear card


					if(0 == status)
					{
						String DateofCancelCard;
						SYSTEMTIME tmpsystime;
						GetLocalTime(&tmpsystime);
						DateofCancelCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						String sqlstr = "insert into MX values(:BH,:KH,:SF_YE,";
						sqlstr = sqlstr + ":SFJE,:SYCS,:SFRQ,:JYNO,";
						sqlstr = sqlstr + ":GZZID,:SFLX,:CZY,:SCRQ)";
						CardCancelADOQ->SQL->Add(sqlstr);
						CardCancelADOQ->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
						CardCancelADOQ->Parameters->ParamByName("KH")->Value = tmpkh;
						CardCancelADOQ->Parameters->ParamByName("SF_YE")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("SFJE")->Value = tmpye;
						CardCancelADOQ->Parameters->ParamByName("SYCS")->Value = tmpsycs;
						CardCancelADOQ->Parameters->ParamByName("SFRQ")->Value = DateofCancelCard;
						CardCancelADOQ->Parameters->ParamByName("JYNO")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("GZZID")->Value = 1;
						CardCancelADOQ->Parameters->ParamByName("SFLX")->Value = "T";
						CardCancelADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
						CardCancelADOQ->Parameters->ParamByName("SCRQ")->Value = DateofCancelCard;
						CardCancelADOQ->ExecSQL();

						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						sqlstr = "insert into MX values(:BH,:KH,:SF_YE,";
						sqlstr = sqlstr + ":SFJE,:SYCS,:SFRQ,:JYNO,";
						sqlstr = sqlstr + ":GZZID,:SFLX,:CZY,:SCRQ)";
						CardCancelADOQ->SQL->Add(sqlstr);
						CardCancelADOQ->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
						CardCancelADOQ->Parameters->ParamByName("KH")->Value = tmpkh;
						CardCancelADOQ->Parameters->ParamByName("SF_YE")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("SFJE")->Value = tmpyj;
						CardCancelADOQ->Parameters->ParamByName("SYCS")->Value = tmpsycs;
						CardCancelADOQ->Parameters->ParamByName("SFRQ")->Value = DateofCancelCard;
						CardCancelADOQ->Parameters->ParamByName("JYNO")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("GZZID")->Value = 1;
						CardCancelADOQ->Parameters->ParamByName("SFLX")->Value = "R";
						CardCancelADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
						CardCancelADOQ->Parameters->ParamByName("SCRQ")->Value = DateofCancelCard;
						CardCancelADOQ->ExecSQL();


						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						sqlstr = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
						sqlstr += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
						CardCancelADOQ->SQL->Add(sqlstr);
						CardCancelADOQ->Parameters->ParamByName("kh")->Value = tmpkh;
						CardCancelADOQ->Parameters->ParamByName("bh")->Value = cxTextEdit7->Text;
						CardCancelADOQ->Parameters->ParamByName("sf_ye")->Value = -tmpye;
						CardCancelADOQ->Parameters->ParamByName("sf_fl")->Value = 1;
						CardCancelADOQ->Parameters->ParamByName("ckxj")->Value = -tmpye;
						CardCancelADOQ->Parameters->ParamByName("glf")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("ckje")->Value = -tmpye;
						CardCancelADOQ->Parameters->ParamByName("lqbt")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("xkje")->Value = -tmpye;
						CardCancelADOQ->Parameters->ParamByName("sycs")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("sfrq")->Value = DateofCancelCard;
						CardCancelADOQ->Parameters->ParamByName("jyno")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("gzzid")->Value = 1;
						CardCancelADOQ->Parameters->ParamByName("sflx")->Value = "T";
						CardCancelADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
						CardCancelADOQ->ExecSQL();
						CardCancelADOQ->Close();

						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
						CardCancelADOQ->SQL->Add(sqlstr);
						CardCancelADOQ->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
						CardCancelADOQ->Parameters->ParamByName("KH")->Value = tmpkh;
						CardCancelADOQ->Parameters->ParamByName("JE")->Value = -tmpye;
						CardCancelADOQ->Parameters->ParamByName("YE")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("LX")->Value = "退卡";
						CardCancelADOQ->Parameters->ParamByName("Operator")->Value = OperatorName;
						CardCancelADOQ->Parameters->ParamByName("DateTime")->Value = DateofCancelCard;
						CardCancelADOQ->ExecSQL();

						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
						CardCancelADOQ->SQL->Add(sqlstr);
						CardCancelADOQ->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
						CardCancelADOQ->Parameters->ParamByName("KH")->Value = tmpkh;
						CardCancelADOQ->Parameters->ParamByName("JE")->Value = -tmpyj;
						CardCancelADOQ->Parameters->ParamByName("YE")->Value = 0;
						CardCancelADOQ->Parameters->ParamByName("LX")->Value = "退押金";
						CardCancelADOQ->Parameters->ParamByName("Operator")->Value = OperatorName;
						CardCancelADOQ->Parameters->ParamByName("DateTime")->Value = DateofCancelCard;
						CardCancelADOQ->ExecSQL();


						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						CardCancelADOQ->SQL->Add("select * from CARD where KH=" + IntToStr(tmpkh));
						CardCancelADOQ->Open();
						if(!CardCancelADOQ->IsEmpty())
						{
							//填写退卡表
							sqlstr = "insert into CARD_T values(:BH,:KH,:BKH,:XM,:XB,";
							sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
											":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
											":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
											":SF_KL,:USERNAME,:YW,:TKCB,:BKCB,:TKOperator)";
							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = CardCancelADOQ->FieldByName("BH")->Value;
							ADOQuery1->Parameters->ParamByName("KH")->Value = CardCancelADOQ->FieldByName("KH")->Value;
							ADOQuery1->Parameters->ParamByName("BKH")->Value = CardCancelADOQ->FieldByName("BKH")->Value;
							ADOQuery1->Parameters->ParamByName("XM")->Value = CardCancelADOQ->FieldByName("XM")->Value;
							ADOQuery1->Parameters->ParamByName("XB")->Value = CardCancelADOQ->FieldByName("XB")->Value;
							ADOQuery1->Parameters->ParamByName("SFZH")->Value = CardCancelADOQ->FieldByName("SFZH")->Value;
							ADOQuery1->Parameters->ParamByName("BM")->Value = CardCancelADOQ->FieldByName("BM")->Value;
							ADOQuery1->Parameters->ParamByName("BZ")->Value = CardCancelADOQ->FieldByName("BZ")->Value;
							ADOQuery1->Parameters->ParamByName("ZB")->Value = CardCancelADOQ->FieldByName("ZB")->Value;
							ADOQuery1->Parameters->ParamByName("ZW")->Value = CardCancelADOQ->FieldByName("ZW")->Value;
							ADOQuery1->Parameters->ParamByName("JB")->Value = CardCancelADOQ->FieldByName("JB")->Value;
							ADOQuery1->Parameters->ParamByName("RQ")->Value = CardCancelADOQ->FieldByName("RQ")->Value;
							ADOQuery1->Parameters->ParamByName("TKRQ")->Value = DateTimeToStr(Now());
							ADOQuery1->Parameters->ParamByName("YJ")->Value = CardCancelADOQ->FieldByName("YJ")->Value;
							ADOQuery1->Parameters->ParamByName("TYJ")->Value = CardCancelADOQ->FieldByName("TYJ")->Value;
							ADOQuery1->Parameters->ParamByName("ZT")->Value = "退卡";//CardCancelADOQ->FieldByName("ZT")->Value;
							ADOQuery1->Parameters->ParamByName("GRMM")->Value = CardCancelADOQ->FieldByName("GRMM")->Value;
							ADOQuery1->Parameters->ParamByName("BTBZ")->Value = CardCancelADOQ->FieldByName("BTBZ")->Value;
							ADOQuery1->Parameters->ParamByName("BT_YE")->Value = CardCancelADOQ->FieldByName("BT_YE")->Value;
							ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = CardCancelADOQ->FieldByName("BTYEDT")->Value;
							ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = CardCancelADOQ->FieldByName("BTSYCS")->Value;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = tmpye;//CardCancelADOQ->FieldByName("SF_YE")->Value;
							ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = CardCancelADOQ->FieldByName("SFYEDT")->Value;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = CardCancelADOQ->FieldByName("SYCS")->Value;
							ADOQuery1->Parameters->ParamByName("FKSK")->Value = CardCancelADOQ->FieldByName("FKSK")->Value;
							ADOQuery1->Parameters->ParamByName("SF_FL")->Value = CardCancelADOQ->FieldByName("SF_FL")->Value;
							ADOQuery1->Parameters->ParamByName("GLF")->Value = CardCancelADOQ->FieldByName("GLF")->Value;
							ADOQuery1->Parameters->ParamByName("FKJE")->Value = CardCancelADOQ->FieldByName("FKJE")->Value;
							ADOQuery1->Parameters->ParamByName("TKJE")->Value = tmpye;//CardCancelADOQ->FieldByName("SF_YE")->Value;
							ADOQuery1->Parameters->ParamByName("TKBT")->Value = CardCancelADOQ->FieldByName("BT_YE")->Value;
							ADOQuery1->Parameters->ParamByName("SF_KL")->Value = CardCancelADOQ->FieldByName("SF_KL")->Value;
							ADOQuery1->Parameters->ParamByName("USERNAME")->Value = CardCancelADOQ->FieldByName("USERNAME")->Value;
							ADOQuery1->Parameters->ParamByName("YW")->Value = 1;
                            ADOQuery1->Parameters->ParamByName("TKCB")->Value = StrToInt(cxTextEdit18->Text);
                            ADOQuery1->Parameters->ParamByName("BKCB")->Value = 0;
                            ADOQuery1->Parameters->ParamByName("TKOperator")->Value = OperatorName;
							ADOQuery1->ExecSQL();
							ADOQuery1->Close();

							CardCancelADOQ->Delete();
						}
						CardCancelADOQ->Close();

						CardCancelADOQ->SQL->Clear();
						CardCancelADOQ->SQL->Add("select * from CARD_F where KH=" + IntToStr(tmpkh));
						CardCancelADOQ->Open();
						if(!CardCancelADOQ->IsEmpty())
						{
						//	CardCancelADOQ->Delete();
							CardCancelADOQ->Edit();
							CardCancelADOQ->FieldByName("ZT")->AsAnsiString = "退卡";
							CardCancelADOQ->Post();
						}
						CardCancelADOQ->Close();

						CardCancelADOQ->SQL->Clear();
						CardCancelADOQ->SQL->Add("select * from KZT where KH=" + IntToStr(tmpkh));
						CardCancelADOQ->Open();
						if(!CardCancelADOQ->IsEmpty())
						{
							CardCancelADOQ->Edit();
                            CardCancelADOQ->FieldByName("GS")->AsString = '0';
							CardCancelADOQ->FieldByName("SY")->AsString = 'T';
							CardCancelADOQ->FieldByName("TKRQ")->AsString = DateofCancelCard;
							CardCancelADOQ->FieldByName("WITHCARDTK")->AsString = 'Y';
							CardCancelADOQ->Post();
						}
						CardCancelADOQ->Close();

						//写加密狗减去取款
                        if(DOGChk)
                        {
                            unsigned char tempbuf[8];
                            SFK_ZE -= tmpye;
                            UpZETable->FieldByName("SFKZE")->AsFloat -= tmpye;
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

						beepofreaddll(readcomno, '10');

						CardCancelADOQ->SQL->Clear();
					 //   CardCancelADOQ->SQL->Add("select")
						String sql = "select * from GS where BH='";
						sql += cxTextEdit7->Text;
						sql += "' and KH=";
						sql += cxTextEdit1->Text;
						CardCancelADOQ->Close();
						CardCancelADOQ->SQL->Clear();
						CardCancelADOQ->SQL->Add(sql);
						CardCancelADOQ->Open();

						if(CardCancelADOQ->IsEmpty())
						{
							sql = "insert into GS values(:BH,:KH,:GSRQ,:USERNAME)";
							CardCancelADOQ->Close();
							CardCancelADOQ->SQL->Clear();
							CardCancelADOQ->SQL->Add(sql);
							CardCancelADOQ->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
							CardCancelADOQ->Parameters->ParamByName("KH")->Value = StrToInt(cxTextEdit1->Text);
							CardCancelADOQ->Parameters->ParamByName("GSRQ")->Value = DateToStr(Date());
							CardCancelADOQ->Parameters->ParamByName("USERNAME")->Value = OperatorName;
							CardCancelADOQ->ExecSQL();
						}

                		ShowMessage("请退还用户卡上的卡余额与发卡押金!");
					}
					else
					{
                        ShowMessage("退卡失败，请重试或联系技术人员！");
                    }
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					CardCancelADOQ->Close();

                    //lab change test
				}
			}
		}
		else
			ShowMessage("读卡函数加载失败！");
	}
	else
		ShowMessage("加载读写卡动态链接库失败！");

	cxButton2->Enabled = false;
	cxButton1->Enabled = true;
}
//---------------------------------------------------------------------------

