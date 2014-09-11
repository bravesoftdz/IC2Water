//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "launchNewCardFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxCheckBox"
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "dxSkinscxPCPainter"
#pragma link "cxPropertiesStore"
#pragma link "cxHeader"
#pragma link "cxSpinEdit"
#pragma link "cxTimeEdit"
#pragma link "cxCalendar"
#pragma resource "*.dfm"
TLaunchNewUserCardFRM *LaunchNewUserCardFRM;
//---------------------------------------------------------------------------
__fastcall TLaunchNewUserCardFRM::TLaunchNewUserCardFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLaunchNewUserCardFRM::LaunchNewCardExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::LaunchNewCardBTNClick(TObject *Sender)
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

	Delayms = DelaySecond;
	keymode = CARDPasswordEdition;
	secnum = UsingSecNUM;

	key[0] = CARDPassword[0];
	key[1] = CARDPassword[1];
	key[2] = CARDPassword[2];
	key[3] = CARDPassword[3];
	key[4] = CARDPassword[4];
	key[5] = CARDPassword[5];
/*    //show card mm
    String chkmmrstr = "";
    for(int i = 0; i < 6; i++)
    {
        chkmmrstr += IntToHex(Byte(key[i]),2);
    }
    ShowMessage(chkmmrstr);
    //show end

    //show pwedition secnum
    chkmmrstr = "pwedition:";
    chkmmrstr += IntToHex(Byte(keymode),2);
    chkmmrstr += "  secnum:";
    chkmmrstr += IntToHex(Byte(UsingSecNUM),2);
    ShowMessage(chkmmrstr);
    //end show   */

	if(LoadHModule)
	{
		if(readwatercardinfo)//readcardinfo)
		{
		//	status = readcardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,synum,daytime,cardtype,czmm,Delayms);
        	status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！请进行“检测读写器”操作！");
				return;
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
				return;
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于200000或等于0！");
				return;
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
				return;
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
				return;
			}
			else if (0 == status)
			{
				ShowMessage("此卡不能做为新卡发行，请更换新卡！");
				return;
			}
			else
			{
				int NumberOFCard;
				AnsiString SerialNumOFCard = SerialOFCardTextEdit->Text;

				NumberOFCard = StrToInt(NumberOFCardTextEdit->Text);

				LaunchNewCardADOQ->Close();
				LaunchNewCardADOQ->SQL->Clear();
				String checksqlstr = "select * from KZT where KH=";
				checksqlstr += NumberOFCard;
				checksqlstr += " and GS='0' and SY='N'";
	  //			ShowMessage(checksqlstr);
				LaunchNewCardADOQ->SQL->Add(checksqlstr);
				LaunchNewCardADOQ->Open();
				if(LaunchNewCardADOQ->IsEmpty())
				{
					ShowMessage("该卡号已经被使用，请更换卡号!");
					return;
				}

				LaunchNewCardADOQ->Close();
				LaunchNewCardADOQ->SQL->Clear();
				checksqlstr = "select * from BHUSED where BH='";
				checksqlstr += SerialNumOFCard;
				checksqlstr += "'";
		//		ShowMessage(checksqlstr);
				LaunchNewCardADOQ->SQL->Add(checksqlstr);
				LaunchNewCardADOQ->Open();
				if(!LaunchNewCardADOQ->IsEmpty())
				{
					ShowMessage("该编号已经被使用，请更换编号!");
					return;
                }

				if((!UserNameTextEdit->Text.IsEmpty())&&(-1 != UserSexComboBox->ItemIndex)&&
					(!DepositTextEdit->Text.IsEmpty())&&(!PrepayTextEdit->Text.IsEmpty())&&
					(-1 != ConsumeRateComboBox->ItemIndex)&&(!DegreeTextEdit->Text.IsEmpty()))
				{
					WORD writestatus;
					unsigned char writedaytime[4];
					unsigned char writebalance[4];
					unsigned char writeczmm[3];
					unsigned char writecardtype[1];
					unsigned char writekh[4];
					int writetmpkh = atoi(NumberOFCardTextEdit->Text.t_str());
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
					unsigned char writesynum[2];
					writesynum[0] = 0x00;
					writesynum[1] = 0x00;
					unsigned char writemode = 0x00;
					unsigned char writeDelayms = DelaySecond;


					String writetmpstr = DateToStr(UseDateEdit->Date);
					char* writetmpdatestr = writetmpstr.t_str();
					writedaytime[0] = char(((int)writetmpdatestr[2]-48)*16+((int)writetmpdatestr[3]-48));
					writedaytime[1] = char(((int)writetmpdatestr[5]-48)*16+((int)writetmpdatestr[6]-48));
					writedaytime[2] = char(((int)writetmpdatestr[8]-48)*16+((int)writetmpdatestr[9]-48));
					writedaytime[3] = 0x00;

		 //			writesynum[0] = 0x00;
		 //			writesynum[1] = 0x00;

		 //			ShowMessage(PrepayTextEdit->Text.t_str());
					int writetmpbalance = atoi(PrepayTextEdit->Text.t_str());//-atoi(DepositTextEdit->Text.t_str());
					writetmpbalance *= 100;
					writebalance[0] = 0x00;
					writebalance[1] = (char)((int)writetmpbalance/65536);
					writetmpbalance = writetmpbalance%65536;
					writebalance[2] = (char)((int)writetmpbalance/256);
					writetmpbalance = writetmpbalance%256;
					writebalance[3] = (char)writetmpbalance;

					unsigned char writetmpczmm[5];
                    strcpy(writetmpczmm, PerPassWordTextEdit->Text.t_str());
					writetmpczmm[0] = writetmpczmm[0]<<4;
					writetmpczmm[1] = writetmpczmm[1]<<4;
					writetmpczmm[1] = writetmpczmm[1]>>4;
					writeczmm[0] = writetmpczmm[0] + writetmpczmm[1];
					writetmpczmm[2] = writetmpczmm[2]<<4;
					writetmpczmm[3] = writetmpczmm[3]<<4;
					writetmpczmm[3] = writetmpczmm[3]>>4;
					writeczmm[1] = writetmpczmm[2]+writetmpczmm[3];
					writeczmm[2] = 0x00;

					writecardtype[0] = 0x04;//atoi(DegreeTextEdit->Text.t_str());

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
													writeDelayms);     */

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
							return;
						}
						else
						{
							//判短时间限制并写卡
							if(DateCheckBox->Checked)
							{
								if(!pacarddllproc)
								{
									ClearCardInfoProc(writereadcomno,
													  writekeymode,
													  writesecnum,
													  writekey,
													  writeDelayms);
									beepofreaddll(readcomno, '10');
									ShowMessage("写卡时间限制函数加载失败!");
									return;
								}

								unsigned char limitwritedaytime[4];
								String limitwritetmpstr = DateToStr(UseDateEdit->Date);
								char* limitwritetmpdatestr = limitwritetmpstr.t_str();
								limitwritedaytime[0] = char(((int)limitwritetmpdatestr[2]-48)*16+((int)limitwritetmpdatestr[3]-48));
								limitwritedaytime[1] = char(((int)limitwritetmpdatestr[5]-48)*16+((int)limitwritetmpdatestr[6]-48));
								limitwritedaytime[2] = char(((int)limitwritetmpdatestr[8]-48)*16+((int)limitwritetmpdatestr[9]-48));
								limitwritedaytime[3] = 0x00;

								unsigned char sendbuflen = 26;
								unsigned char sendbuf[26];
								ZeroMemory(sendbuf,26);
								unsigned char recbuf[140];
								unsigned char recbuflen;
								ZeroMemory(recbuf, 140);

								sendbuf[0] = (secnum+1)*4+2;//扇区×4+块号
								sendbuf[1] = 0x60;//固定为0x60
								sendbuf[2] = 2;//命令字：1为读，2为写
								sendbuf[3] = keymode;
								sendbuf[4] = writekey[0];
								sendbuf[5] = writekey[1];
								sendbuf[6] = writekey[2];
								sendbuf[7] = writekey[3];
								sendbuf[8] = writekey[4];
								sendbuf[9] = writekey[5];

								sendbuf[23] = limitwritedaytime[0];
								sendbuf[24] = limitwritedaytime[1];
								sendbuf[25] = limitwritedaytime[2];

								WORD limitStatus = pacarddllproc(writereadcomno,sendbuflen,sendbuf,&recbuflen,recbuf,writeDelayms);

								if((0 != limitStatus)||(0 != recbuf[2]))
								{
                                	ClearCardInfoProc(writereadcomno,
													  writekeymode,
													  writesecnum,
													  writekey,
													  writeDelayms);
									beepofreaddll(readcomno, '10');
									ShowMessage("写卡时间限制失败!");
									return;
                                }
							}

                            if(WriteNameChk)
                            {
                                //写姓名
                                if(!UserNameTextEdit->Text.IsEmpty())
                                {
                                    if(!pacarddllproc)
                                    {
                                        ClearCardInfoProc(writereadcomno,
                                                          writekeymode,
                                                          writesecnum,
                                                          writekey,
                                                          writeDelayms);
                                        beepofreaddll(readcomno, '10');
                                        ShowMessage("写姓名函数加载失败!");
                                        return;
                                    }

                                    unsigned char writename[16];
                                    memset(writename, 0xA1, 16);
                                    String writenamestr = UserNameTextEdit->Text;
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
                                    sendbuf[3] = keymode;
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
                                        ClearCardInfoProc(writereadcomno,
                                                          writekeymode,
                                                          writesecnum,
                                                          writekey,
                                                          writeDelayms);
                                        beepofreaddll(readcomno, '10');
                                        ShowMessage("写姓名失败!");
                                        return;
                                    }
                                }
                                //写电话号码
                                if(!cxTextEdit1->Text.IsEmpty())
                                {
                                    if(!pacarddllproc)
                                    {
                                        ClearCardInfoProc(writereadcomno,
                                                          writekeymode,
                                                          writesecnum,
                                                          writekey,
                                                          writeDelayms);
                                        beepofreaddll(readcomno, '10');
                                        ShowMessage("写电话函数加载失败!");
                                        return;
                                    }

                                    unsigned char writephone[16];
                                    memset(writephone, 0x20, 16);
                                    String writephonestr = cxTextEdit1->Text;
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
                                    sendbuf[3] = keymode;
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
                                        ClearCardInfoProc(writereadcomno,
                                                          writekeymode,
                                                          writesecnum,
                                                          writekey,
                                                          writeDelayms);
                                        beepofreaddll(readcomno, '10');
                                        ShowMessage("写电话失败!");
                                        return;
                                    }
                                }
                            }

							String DateofLaunchCard;
							SYSTEMTIME tmpsystime;
							GetLocalTime(&tmpsystime);
							DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));
				  //			ShowMessage(DateofLaunchCard);

							int tmpdeposit = atoi(DepositTextEdit->Text.t_str());
							int tmpPrePay = atoi(PrepayTextEdit->Text.t_str());
							int moneyincard = tmpPrePay;//-tmpdeposit;

							//填写CARD表
							String tmpstr = SerialNumOFCard;
							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							String sqlstr = "insert into CARD values(:BH,:KH,:BKH,:XM,:XB,";
							sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
											":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
											":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
											":SF_KL,:USERNAME)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;
							//ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("XM")->Value = UserNameTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("XB")->Value = UserSexComboBox->Text;
							ADOQuery1->Parameters->ParamByName("SFZH")->Value = IdentityIDTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("BM")->Value = SectionNameComboBox->Text;
							ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassNameComboBox->Text;
							if(-1 != GroupNameComboBox->ItemIndex)
							{
								ADOQuery1->Parameters->ParamByName("ZB")->Value = GroupNameComboBox->Text;
							}
							ADOQuery1->Parameters->ParamByName("ZW")->Value = DegreeComboBox->Text;
							ADOQuery1->Parameters->ParamByName("JB")->Value = DegreeTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
							//ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("TYJ")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
							ADOQuery1->Parameters->ParamByName("GRMM")->Value = PerPassWordTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
							ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
							//ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("SF_FL")->Value = ConsumeRateComboBox->ItemIndex+1;
							ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
							ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
							//ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
							//ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
							ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
							ADOQuery1->ExecSQL();

							//填写CARD_F表
							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into CARD_F values(:BH,:KH,:BKH,:XM,:XB,";
							sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
							":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
							":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
							":SF_KL,:USERNAME)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
							ADOQuery1->Parameters->ParamByName("KH")->Value = (NumberOFCard);
							//ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("XM")->Value = UserNameTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("XB")->Value = UserSexComboBox->Text;
							ADOQuery1->Parameters->ParamByName("SFZH")->Value = IdentityIDTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("BM")->Value = SectionNameComboBox->Text;
							ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassNameComboBox->Text;
							if(-1 != GroupNameComboBox->ItemIndex)
							{
								ADOQuery1->Parameters->ParamByName("ZB")->Value = GroupNameComboBox->Text;
							}
							ADOQuery1->Parameters->ParamByName("ZW")->Value = DegreeComboBox->Text;
							ADOQuery1->Parameters->ParamByName("JB")->Value = DegreeTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
							//ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("TYJ")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
							ADOQuery1->Parameters->ParamByName("GRMM")->Value = PerPassWordTextEdit->Text;
							ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
							ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
							//ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("SF_FL")->Value = ConsumeRateComboBox->ItemIndex+1;
							ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
							ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
							//ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
							//ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
							ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
							ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
							ADOQuery1->ExecSQL();

							//填写操作记录表
							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;
							ADOQuery1->Parameters->ParamByName("JE")->Value = 0;
							ADOQuery1->Parameters->ParamByName("YE")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("LX")->Value = "发卡";
							ADOQuery1->Parameters->ParamByName("Operator")->Value = OperatorName;
							ADOQuery1->Parameters->ParamByName("DateTime")->Value = DateofLaunchCard;
							ADOQuery1->ExecSQL();
                			ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;
							ADOQuery1->Parameters->ParamByName("JE")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("YE")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("LX")->Value = "收押金";
							ADOQuery1->Parameters->ParamByName("Operator")->Value = OperatorName;
							ADOQuery1->Parameters->ParamByName("DateTime")->Value = DateofLaunchCard;
							ADOQuery1->ExecSQL();

							//填写MX,MXBAK表
							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("SFJE")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery1->Parameters->ParamByName("SFLX")->Value = "K";
							ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
							ADOQuery1->ExecSQL();
							ADOQuery1->Close();

							//添加扣押金记录
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SFJE")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery1->Parameters->ParamByName("SFLX")->Value = "W";
							ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
							ADOQuery1->ExecSQL();

							//添加扣押金记录
/*							ADOQuery1->SQL->Clear();
							sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SFJE")->Value = tmpdeposit;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery1->Parameters->ParamByName("SFLX")->Value = "W";
							ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
							ADOQuery1->ExecSQL();

							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
							ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("SFJE")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
							ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
							ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
							ADOQuery1->Parameters->ParamByName("SFLX")->Value = "K";
							ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
							ADOQuery1->ExecSQL();    */

							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
							sqlstr += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("kh")->Value = NumberOFCard;
							ADOQuery1->Parameters->ParamByName("bh")->Value = SerialNumOFCard;
							ADOQuery1->Parameters->ParamByName("sf_ye")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("sf_fl")->Value = 1;
							ADOQuery1->Parameters->ParamByName("ckxj")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("glf")->Value = 0;
							ADOQuery1->Parameters->ParamByName("ckje")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("lqbt")->Value = 0;
							ADOQuery1->Parameters->ParamByName("xkje")->Value = moneyincard;
							ADOQuery1->Parameters->ParamByName("sycs")->Value = 0;
							ADOQuery1->Parameters->ParamByName("sfrq")->Value = DateofLaunchCard;
							ADOQuery1->Parameters->ParamByName("jyno")->Value = 0;
							ADOQuery1->Parameters->ParamByName("gzzid")->Value = 1;
							ADOQuery1->Parameters->ParamByName("sflx")->Value = "K";
							ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
							ADOQuery1->ExecSQL();
							ADOQuery1->Close();


							//填写KZT表

					   /*	ADOQuery1->SQL->Clear();
							ADOQuery1->SQL->Add("insert into KZT values(:KH,:BH,:GS,:SY,:FKRQ,:TKRQ,:WITHCARDTK)");
							ADOQuery1->Parameters->ParamByName("KH")->Value = NumberOFCard;
							ADOQuery1->Parameters->ParamByName("BH")->Value = tmpstr;
							ADOQuery1->Parameters->ParamByName("GS")->Value = "0";
							ADOQuery1->Parameters->ParamByName("SY")->Value = "1";
							ADOQuery1->Parameters->ParamByName("FKRQ")->Value = DateofLaunchCard;
							//ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
							//ADOQuery1->Parameters->ParamByName("WITHCARDTK")->Value = NULL;
							ADOQuery1->ExecSQL();     */

					/*		LaunchNewCardADOQ->Edit();
							LaunchNewCardADOQ->FieldByName("SY")->AsString = "Y";
							LaunchNewCardADOQ->FieldByName("FKRQ")->AsString = DateofLaunchCard;
							LaunchNewCardADOQ->Post();   */
							ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							String kztsqlstr = "select * from KZT where KH=";
							kztsqlstr += NumberOFCard;
							ADOQuery1->SQL->Add(kztsqlstr);
							ADOQuery1->Open();
							if(!ADOQuery1->IsEmpty())
							{
								ADOQuery1->Edit();
								ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
								ADOQuery1->FieldByName("SY")->AsAnsiString = 'Y';
								ADOQuery1->FieldByName("FKRQ")->AsAnsiString = DateofLaunchCard;
                                ADOQuery1->FieldByName("GS")->AsAnsiString = '0';
                                ADOQuery1->FieldByName("TKRQ")->AsAnsiString = "";
                                ADOQuery1->FieldByName("WITHCARDTK")->AsAnsiString = "";
								ADOQuery1->Post();
                            }

							cxLabel20->Caption = IntToStr(moneyincard);

                            ADOQuery1->Close();
							ADOQuery1->SQL->Clear();
							sqlstr = "insert into BHUSED values(:BH)";
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
							ADOQuery1->ExecSQL();
							ADOQuery1->Close();


							//检查入库情况
							ADOQuery1->SQL->Clear();
							sqlstr = "select * from CARD where KH=";
							sqlstr += NumberOFCard;
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Open();
							if(!ADOQuery1->IsEmpty())
							{
								int chkkh = ADOQuery1->FieldByName("KH")->AsInteger;
								AnsiString chkbh = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
								String chkname = ADOQuery1->FieldByName("XM")->AsString.Trim();
								double chkje = ADOQuery1->FieldByName("SF_YE")->AsFloat;

								if(chkkh != NumberOFCard)
								{
									ADOQuery1->Edit();
									ADOQuery1->FieldByName("KH")->AsInteger = NumberOFCard;
									ADOQuery1->Post();
								}

								if(chkbh != SerialNumOFCard)
								{
									ADOQuery1->Edit();
									ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
									ADOQuery1->Post();
                                }

								if(chkname != UserNameTextEdit->Text)
								{
                                    ADOQuery1->Edit();
									ADOQuery1->FieldByName("XM")->AsString = UserNameTextEdit->Text;
									ADOQuery1->Post();
								}

								if(chkje != moneyincard)
								{
									ADOQuery1->Edit();
									ADOQuery1->FieldByName("SF_YE")->AsFloat = moneyincard;
									ADOQuery1->FieldByName("FKJE")->AsFloat = moneyincard;
									ADOQuery1->Post();
								}
							}
							ADOQuery1->Close();

							ADOQuery1->SQL->Clear();
							sqlstr = "select * from CARD_F where KH=";
							sqlstr += NumberOFCard;
							ADOQuery1->SQL->Add(sqlstr);
							ADOQuery1->Open();
							if(!ADOQuery1->IsEmpty())
							{
								int chkkh = ADOQuery1->FieldByName("KH")->AsInteger;
								AnsiString chkbh = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
								String chkname = ADOQuery1->FieldByName("XM")->AsString.Trim();
								double chkje = ADOQuery1->FieldByName("SF_YE")->AsFloat;


								if(chkkh != NumberOFCard)
								{
									ADOQuery1->Edit();
									ADOQuery1->FieldByName("KH")->AsInteger = NumberOFCard;
									ADOQuery1->Post();
								}

								if(chkbh != SerialNumOFCard)
								{
									ADOQuery1->Edit();
									ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
									ADOQuery1->Post();
                                }

								if(chkname != UserNameTextEdit->Text)
								{
                                    ADOQuery1->Edit();
									ADOQuery1->FieldByName("XM")->AsString = UserNameTextEdit->Text;
									ADOQuery1->Post();
								}

								if(chkje != moneyincard)
								{
									ADOQuery1->Edit();
									ADOQuery1->FieldByName("SF_YE")->AsFloat = moneyincard;
									ADOQuery1->FieldByName("FKJE")->AsFloat = moneyincard;
									ADOQuery1->Post();
								}
							}
							ADOQuery1->Close();

                            //写加密狗充值总额
                            if(DOGChk)
                            {
                            	SFK_ZE += moneyincard;
                                unsigned char tempbuf[8];
			 	               	UpZETable->FieldByName("SFKZE")->AsFloat += moneyincard;
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
							ShowMessage("发卡成功！");
                      //      ADOTable1->Active = false;
                      //      ADOTable1->Active = true;

                            LaunchProcessPanel->Caption = "开始发卡......";
							LaunchNewCardADOQ->Close();
							LaunchNewCardADOQ->SQL->Clear();
						  //	LaunchNewCardADOQ->SQL->Add("select min(KH) as minkh from KZT where (SY='N' or SY='T') and GS='0' and KH>0");
						  	LaunchNewCardADOQ->SQL->Add("select min(KH) as minkh from KZT where SY='N' and GS='0' and KH>0");
							LaunchNewCardADOQ->Open();
							if(!LaunchNewCardADOQ->IsEmpty())
							{
								NumberOFCard = LaunchNewCardADOQ->FieldByName("minkh")->AsInteger;
								NumberOFCardTextEdit->Text = NumberOFCard;
								SerialOFCardTextEdit->Text = "";
								SerialNumOFCard.sprintf("%010d", NumberOFCard);

								LaunchNewCardADOQ->Close();
								LaunchNewCardADOQ->SQL->Clear();

								String tmpsqlstr = "select * from BHUSED where BH='";
								tmpsqlstr += SerialNumOFCard;
								tmpsqlstr += "'";
								LaunchNewCardADOQ->SQL->Add(tmpsqlstr);
								LaunchNewCardADOQ->Open();

								if(LaunchNewCardADOQ->IsEmpty())
								{
									SerialOFCardTextEdit->Text = SerialNumOFCard;
								}
								else
								{
                                    srand((unsigned)time(NULL));
                                    int tmpint = rand()%10000000000;
                                    while(1)
                                    {
                                        SerialNumOFCard = "";
                                        SerialNumOFCard.sprintf("%010d", tmpint);

                                        tmpsqlstr = "select * from BHUSED where BH='";
                                        tmpsqlstr += SerialNumOFCard;
                                        tmpsqlstr += "'";

                                        LaunchNewCardADOQ->Close();
                                        LaunchNewCardADOQ->SQL->Clear();
                                        LaunchNewCardADOQ->SQL->Add(tmpsqlstr);
                                        LaunchNewCardADOQ->Open();
                                        if(LaunchNewCardADOQ->IsEmpty())
                                        {
                                            SerialOFCardTextEdit->Text = SerialNumOFCard;
                                            break;
                                        }
                                        else
                                        {
                                            tmpint = rand()%10000000000;
                                        }
                                    }
								}
							}
                            else
                            {
								ShowMessage("系统中已无可用卡号，请联系技术人员！");
                                LaunchNewCardADOQ->Close();
                                UserNameTextEdit->Text = "";
                                UserSexComboBox->ItemIndex = 0;
                                SectionNameComboBox->ItemIndex = -1;
                                ClassNameComboBox->ItemIndex = -1;
                                DegreeComboBox->ItemIndex = -1;
                                GroupNameComboBox->ItemIndex = -1;
                                cxTextEdit4->Text = 1;
                                IdentityIDTextEdit->Text = "";
                                DegreeTextEdit->Text = 1;
								PerPassWordTextEdit->Text = "0000";
                                DepositTextEdit->Text = IntToStr(GlobalFKYJ);
                                if(!cxCheckBox3->Checked)
                                	PrepayTextEdit->Text = "";
                                ConsumeRateComboBox->ItemIndex = 0;
                                UseDateEdit->Text = "2016-07-31";
                                LaunchNewCardBTN->Enabled = false;
                                return;
                            }
							LaunchNewCardADOQ->Close();
							UserNameTextEdit->Text = "";
							UserSexComboBox->ItemIndex = 0;
							SectionNameComboBox->ItemIndex = -1;
							ClassNameComboBox->ItemIndex = -1;
							DegreeComboBox->ItemIndex = -1;
							GroupNameComboBox->ItemIndex = -1;
							cxTextEdit4->Text = 1;
							IdentityIDTextEdit->Text = "";
							DegreeTextEdit->Text = 1;
							PerPassWordTextEdit->Text = "0000";
							DepositTextEdit->Text = IntToStr(GlobalFKYJ);
                            if(!cxCheckBox3->Checked)
								PrepayTextEdit->Text = "";
							ConsumeRateComboBox->ItemIndex = 0;
							UseDateEdit->Text = "2016-07-31";
						}
					}
					else
					{
						ShowMessage("写卡函数加载失败！");
					}
				}
				else
					ShowMessage("卡信息填写不完整，请填写完整！");

				LaunchNewCardADOQ->Close();
			}
		}
		else
		{
			ShowMessage("读卡函数加载失败！");
		}
	}
	else
	{
		ShowMessage("加载读写卡动态链接库失败！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::FormCreate(TObject *Sender)
{
/*	LaunchNewCardADOQ->Close();
	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from BUMEN");
	LaunchNewCardADOQ->Open();
	SectionNameComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		SectionNameComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("BUMEN")->AsAnsiString);
		LaunchNewCardADOQ->Next();
	}
	SectionNameComboBox->ItemIndex = -1;
	LaunchNewCardADOQ->Close();

	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from SFZW");
	LaunchNewCardADOQ->Open();
	DegreeComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		DegreeComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("ZW")->AsAnsiString);
		LaunchNewCardADOQ->Next();
	}
	DegreeComboBox->ItemIndex = -1;
	LaunchNewCardADOQ->Close();  */

	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from SFFL");
	LaunchNewCardADOQ->Open();
	ConsumeRateComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		ConsumeRateComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("FL")->AsAnsiString.Trim());
		LaunchNewCardADOQ->Next();
	}
	ConsumeRateComboBox->ItemIndex = 1;
	LaunchNewCardADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::SectionNameComboBoxPropertiesChange(TObject *Sender)
{
	LaunchNewCardADOQ->Close();
	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from BANBIE where BUMEN='"+
								(SectionNameComboBox->Text)+"'");
	LaunchNewCardADOQ->Open();
	ClassNameComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		ClassNameComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("BANBIE")->AsAnsiString.Trim());
		LaunchNewCardADOQ->Next();
	}
	ClassNameComboBox->ItemIndex = -1;
	LaunchNewCardADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::ClassNameComboBoxPropertiesChange(TObject *Sender)
{
	LaunchNewCardADOQ->Close();
	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from ZUBIE where BUMEN = '"+
								(SectionNameComboBox->Text)+"'"+"and "+
								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
	LaunchNewCardADOQ->Open();
	GroupNameComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		GroupNameComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("ZUBIE")->AsAnsiString.Trim());
		LaunchNewCardADOQ->Next();
	}
	GroupNameComboBox->ItemIndex = -1;
	LaunchNewCardADOQ->Close();
}
//---------------------------------------------------------------------------


void __fastcall TLaunchNewUserCardFRM::UserNameTextEditExit(TObject *Sender)
{
/*	String tmpstr = UserNameTextEdit->Text;
	if((tmpstr.Length()==0)||(tmpstr.Length()>=10))
	{
		ShowMessage("您输入的姓名长度不能为0，同时不能大与5的字！");
		UserNameTextEdit->Text = "";
    }  */
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::UserSexComboBoxExit(TObject *Sender)
{
	if(-1 == UserSexComboBox->ItemIndex)
	{
		ShowMessage("请选择用户性别！");
		UserSexComboBox->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::SectionNameComboBoxExit(TObject *Sender)
{
/*	if(-1 == SectionNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在部门！");
		SectionNameComboBox->Text = "";
	}  */
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::DegreeComboBoxExit(TObject *Sender)
{
/*	if(-1 == DegreeComboBox->ItemIndex)
	{
		ShowMessage("请选择用户身份！");
		DegreeComboBox->Text = "";
	}     */
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::IdentityIDTextEditExit(TObject *Sender)
{
	String tmpstr = IdentityIDTextEdit->Text;
	if(tmpstr.Length()>18)
	{
		ShowMessage("输入的身份证号位数应该大于0，小于19，请重新输入");
		IdentityIDTextEdit->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::PerPassWordTextEditExit(TObject *Sender)
{
	String tmpstr = PerPassWordTextEdit->Text;
	if(tmpstr.Length() != 4)
	{
		ShowMessage("请输入四位的个人密码！");
		PerPassWordTextEdit->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::DegreeTextEditExit(TObject *Sender)
{
	String tmpstr = DegreeTextEdit->Text;
	if((tmpstr.Length() > 1)||(tmpstr.Length() == 0))
	{
		ShowMessage("卡级别必须为一位数字!");
		DegreeTextEdit->Text = "1";
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::IdentityIDTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
    	if(13 == Key)
        {
        	DegreeTextEdit->SetFocus();
        	Key = 0;
        }
        else
        {
			Key=0;
			ShowMessage("请输入0到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::PerPassWordTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
    	if(13 == Key)
        {
        	Key = 0;
            DepositTextEdit->SetFocus();
        }
        else
        {
			Key=0;
			ShowMessage("请输入0到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::PrepayTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
    	if(13 == Key)
        {
            Key = 0;
            ConsumeRateComboBox->SetFocus();
        }
        else
        {
            Key=0;
            ShowMessage("请输入0到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------


void __fastcall TLaunchNewUserCardFRM::FormShow(TObject *Sender)
{
//	ShowMessage("Launch Show!");
	UseDateEdit->Date = IncYear(Date(), 3);
	DepositTextEdit->Text = IntToStr(GlobalFKYJ);
//	ADOTable1->Active = true;
	GetNumADOQ->Close();
	GetNumADOQ->SQL->Clear();
	int NumberOFCard;
//				char SerialNumOFCard[10]="";
	AnsiString SerialNumOFCard;

	LaunchProcessPanel->Caption = "开始发卡......";
	LaunchNewCardADOQ->Close();
	LaunchNewCardADOQ->SQL->Clear();
    LaunchNewCardADOQ->SQL->Add("select min(KH) as minkh from KZT where SY='N' and GS='0' and KH>0");
 //	LaunchNewCardADOQ->SQL->Add("select min(KH) as minkh from KZT where (SY='N' or SY='T') and GS='0' and KH>0");
	LaunchNewCardADOQ->Open();
	if(!LaunchNewCardADOQ->IsEmpty())
	{
    	LaunchNewCardBTN->Enabled = true;
		NumberOFCard = LaunchNewCardADOQ->FieldByName("minkh")->AsInteger;
		NumberOFCardTextEdit->Text = NumberOFCard;
		SerialNumOFCard.sprintf("%010d", NumberOFCard);

		LaunchNewCardADOQ->Close();
		LaunchNewCardADOQ->SQL->Clear();
		String tmpsqlstr = "select * from BHUSED where BH='";
		tmpsqlstr += SerialNumOFCard;
		tmpsqlstr += "'";
		LaunchNewCardADOQ->SQL->Add(tmpsqlstr);
		LaunchNewCardADOQ->Open();

		if(LaunchNewCardADOQ->IsEmpty())
		{
			SerialOFCardTextEdit->Text = SerialNumOFCard;
        }
		else
		{
			srand((unsigned)time(NULL));
            int tmpint = rand()%10000000000;
            while(1)
            {
                SerialNumOFCard = "";
                SerialNumOFCard.sprintf("%010d", tmpint);

                tmpsqlstr = "select * from BHUSED where BH='";
                tmpsqlstr += SerialNumOFCard;
                tmpsqlstr += "'";

                LaunchNewCardADOQ->Close();
                LaunchNewCardADOQ->SQL->Clear();
                LaunchNewCardADOQ->SQL->Add(tmpsqlstr);
                LaunchNewCardADOQ->Open();
                if(LaunchNewCardADOQ->IsEmpty())
                {
                    SerialOFCardTextEdit->Text = SerialNumOFCard;
                    break;
                }
                else
                {
                    tmpint = rand()%10000000000;
                }
            }
            LaunchNewCardADOQ->Close();
		}
	}
    else
    {
        ShowMessage("系统已无可用卡号，请联系技术人员！");
        UserNameTextEdit->Text = "";
		UserSexComboBox->ItemIndex = 0;
        SectionNameComboBox->ItemIndex = -1;
        ClassNameComboBox->ItemIndex = -1;
        DegreeComboBox->ItemIndex = -1;
        GroupNameComboBox->ItemIndex = -1;
        cxTextEdit4->Text = 1;
        IdentityIDTextEdit->Text = "";
        DegreeTextEdit->Text = 1;
        PerPassWordTextEdit->Text = "0000";
        DepositTextEdit->Text = IntToStr(GlobalFKYJ);
        PrepayTextEdit->Text = "";
		ConsumeRateComboBox->ItemIndex = 0;
		cxTextEdit1->Text = "";
//		UseDateEdit->Date = IncYear(Now(), 3);
//		UseDateEdit->Text = "2016-07-31";
		LaunchNewCardBTN->Enabled = false;
        return;
    }
	LaunchNewCardADOQ->Close();

	UserNameTextEdit->Text = "";
	UserSexComboBox->ItemIndex = 0;
	SectionNameComboBox->ItemIndex = -1;
	ClassNameComboBox->ItemIndex = -1;
	DegreeComboBox->ItemIndex = -1;
	GroupNameComboBox->ItemIndex = -1;
	cxTextEdit4->Text = 1;
	IdentityIDTextEdit->Text = "";
	DegreeTextEdit->Text = 1;
	PerPassWordTextEdit->Text = "0000";
	DepositTextEdit->Text = IntToStr(GlobalFKYJ);
	PrepayTextEdit->Text = "";
	ConsumeRateComboBox->ItemIndex = 0;
	cxTextEdit1->Text = "";
//	UseDateEdit->Date = IncYear(Now(), 3);
//	UseDateEdit->Text = "2016-07-31";
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::NumberOFCardTextEditKeyPress(TObject *Sender,
		  wchar_t &Key)
{
	if((Key<'0'||Key>'9'||(127 == Key)||(8 == Key)) && Key!='\b')
	{
    	if(13 == Key)
        {
        	SerialOFCardTextEdit->SetFocus();
        }
        else
        {
			Key=0;
			ShowMessage("请输入0到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::NumberOFCardTextEditExit(TObject *Sender)
{
	String tmpstr = NumberOFCardTextEdit->Text;
	if(tmpstr.Length()>0)
	{
		int cardno = StrToInt(tmpstr);

		if(cardno > 200000)
		{
			ShowMessage("卡号不能大于200000，请重新输入!");
			NumberOFCardTextEdit->Text = "";
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TLaunchNewUserCardFRM::SerialOFCardTextEditKeyPress(TObject *Sender,
		  wchar_t &Key)
{
	if((Key<'0'||Key>'9'||(127 == Key)||(8 == Key)) && Key!='\b')
	{
    	if(13 == Key)
        {
			UserNameTextEdit->SetFocus();
        }
        else
        {
			Key=0;
			ShowMessage("请输入0到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::SerialOFCardTextEditExit(TObject *Sender)
{
	String tmpstr = SerialOFCardTextEdit->Text;
	if(10 != tmpstr.Length())
	{
		ShowMessage("编号长度必须为10位!");
		SerialOFCardTextEdit->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::SectionNameComboBoxEnter(TObject *Sender)
{
	LaunchNewCardADOQ->Close();
	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from BUMEN");
	LaunchNewCardADOQ->Open();
	SectionNameComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		SectionNameComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("BUMEN")->AsAnsiString.Trim());
		LaunchNewCardADOQ->Next();
	}
	SectionNameComboBox->ItemIndex = -1;
	LaunchNewCardADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::DegreeComboBoxEnter(TObject *Sender)
{
	LaunchNewCardADOQ->SQL->Clear();
	LaunchNewCardADOQ->SQL->Add("select * from SFZW");
	LaunchNewCardADOQ->Open();
	DegreeComboBox->Properties->Items->Clear();
	while(!LaunchNewCardADOQ->Eof)
	{
		DegreeComboBox->Properties->Items->Add(LaunchNewCardADOQ->FieldByName("ZW")->AsAnsiString.Trim());
		LaunchNewCardADOQ->Next();
	}
	DegreeComboBox->ItemIndex = -1;
	LaunchNewCardADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::PrepayTextEditExit(TObject *Sender)
{
	if(!PrepayTextEdit->Text.IsEmpty())
	{
		if(StrToInt(PrepayTextEdit->Text) >= 100000)
		{
			ShowMessage("发卡金额不能超过100000，请重新输入!");
			PrepayTextEdit->Text = "";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::GroupNameComboBoxExit(TObject *Sender)
{
/*	if(-1 == GroupNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在组别！");
		GroupNameComboBox->Text = "";
	}      */
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::ClassNameComboBoxExit(TObject *Sender)
{
/*	if(-1 == ClassNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在班别！");
		ClassNameComboBox->Text = "";
	}*/
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::SectionNameComboBoxKeyPress(TObject *Sender,
          wchar_t &Key)
{
    if(13 == Key)
    	ClassNameComboBox->SetFocus();
	Key = 0;
}
//---------------------------------------------------------------------------
/*								UpdateInfoADOTable->TableName = "CARD";
								UpdateInfoADOTable->Active = true;
								TVarRec InsRecord[32];
								InsRecord[0] = tmpstr;
								InsRecord[1] = NumberOFCard;
								InsRecord[2] = NULL;
								InsRecord[3] = UserNameTextEdit->Text;
								InsRecord[4] = UserSexComboBox->Text;
								InsRecord[5] = IdentityIDTextEdit->Text;
								InsRecord[6] = SectionNameComboBox->Text;
								InsRecord[7] = ClassNameComboBox->Text;
								InsRecord[8] = GroupNameComboBox->Text;
								InsRecord[9] = DegreeComboBox->Text;
								InsRecord[10] = DegreeTextEdit->Text;
								InsRecord[11] = DateofLaunchCard;
								InsRecord[12] = NULL;
								InsRecord[13] = DepositTextEdit->Text;
								InsRecord[14] = 0;
								InsRecord[15] = "发卡";
								InsRecord[16] = PerPassWordTextEdit->Text;
								InsRecord[17] = 1;
								InsRecord[18] = 0;
								InsRecord[19] = DateofLaunchCard;
								InsRecord[20] = 0;
								InsRecord[21] = moneyincard;
								InsRecord[22] = DateofLaunchCard;
								InsRecord[23] = 0;
								InsRecord[24] = moneyincard;
								InsRecord[25] = ConsumeRateComboBox->ItemIndex+1;
								InsRecord[26] = 0;
								InsRecord[27] = moneyincard;
								InsRecord[28] = NULL;
								InsRecord[29] = NULL;
								InsRecord[30] = writecardtype;
								InsRecord[31] = "SuperVisor";

								UpdateInfoADOTable->InsertRecord(InsRecord, 32); */

/*CARD
								ADOCommand1->CommandText = "insert into CARD values('"+tmpstr+"',"+
															IntToStr(NumberOFCard)+",NULL,'"+
															UserNameTextEdit->Text+"','"+
															UserSexComboBox->Text+"','"+
															IdentityIDTextEdit->Text+"','"+
															SectionNameComboBox->Text+"','"+
															ClassNameComboBox->Text+"','"+
															GroupNameComboBox->Text+"','"+
															DegreeComboBox->Text+"','"+
															DegreeTextEdit->Text+"','"+
															DateofLaunchCard+"',NULL,"+
															tmpPrePay+",0,'发卡','"+
															PerPassWordTextEdit->Text+
															"',1,0,'"+DateofLaunchCard+
															"',0,"+moneyincard+",'"+
															DateofLaunchCard+"',0,"+moneyincard+
															",'"+(ConsumeRateComboBox->ItemIndex+1)+
															"',0,"+moneyincard+",NULL,NULL,'1','SuperVisor')";
								ADOCommand1->Execute();
*/

/*CARD_F
								ADOCommand1->CommandText = "";
								ADOCommand1->CommandText = "insert into CARD_F values('"+tmpstr+"',"+
															IntToStr(NumberOFCard)+",NULL,'"+
															UserNameTextEdit->Text+"','"+
															UserSexComboBox->Text+"','"+
															IdentityIDTextEdit->Text+"','"+
															SectionNameComboBox->Text+"','"+
															ClassNameComboBox->Text+"','"+
															GroupNameComboBox->Text+"','"+
															DegreeComboBox->Text+"','"+
															DegreeTextEdit->Text+"','"+
															DateofLaunchCard+"',NULL,"+
															tmpPrePay+",0,'发卡','"+
															PerPassWordTextEdit->Text+
															"',1,0,'"+DateofLaunchCard+
															"',0,"+moneyincard+",'"+
															DateofLaunchCard+"',0,"+moneyincard+
															",'"+(ConsumeRateComboBox->ItemIndex+1)+
															"',0,"+moneyincard+",NULL,NULL,'1','SuperVisor')";
								ADOCommand1->Execute();
*/

/*
					//此时系统没有发行新卡，数据库为空
					NumberOFCard = 1;
					SerialNumOFCard.sprintf("%010d", NumberOFCard);
					NumberOFCardTextEdit->Text = NumberOFCard;
					SerialOFCardTextEdit->Text = SerialNumOFCard;

					NumberOFCardTextEdit->Text = NumberOFCard;
					SerialOFCardTextEdit->Text = SerialNumOFCard;

					if((!UserNameTextEdit->Text.IsEmpty())&&(-1 != UserSexComboBox->ItemIndex)&&
						(-1 != SectionNameComboBox->ItemIndex)&&(-1 != ClassNameComboBox->ItemIndex)&&
						(-1 != DegreeComboBox->ItemIndex)&&(!IdentityIDTextEdit->Text.IsEmpty())&&
						(!PerPassWordTextEdit->Text.IsEmpty())&&(!DepositTextEdit->Text.IsEmpty())&&
						(!PrepayTextEdit->Text.IsEmpty())&&(-1 != ConsumeRateComboBox->ItemIndex))
					{
						WORD writestatus;
						unsigned char writedaytime[4];
						unsigned char writebalance[4];
						unsigned char writeczmm[3];
						unsigned char writecardtype[1];
						unsigned char writekh[4];
						int writetmpkh = atoi(NumberOFCardTextEdit->Text.t_str());
						writekh[0] = (char)(writetmpkh/256/256/256);
						writekh[1] = (char)((writetmpkh%(256*256*256))/256/256);
						writekh[2] = (char)((writetmpkh%(256*256))/256);
						writekh[3] = (char)writetmpkh;

						unsigned char writereadcomno[5] = readcomno;
						unsigned char writekeymode = keymode;
						unsigned char writesecnum = secnum;
						unsigned char writekey[6] = key;
						unsigned char writedwmm[2];
						writedwmm[0] = DWPassword[0];
						writedwmm[1] = DWPassword[1];
						unsigned char writesynum[2];
						writesynum[0] = 0x00;
						writesynum[1] = 0x00;
						unsigned char writemode = 0x00;
						unsigned char writeDelayms = DelaySecond;

						String writetmpstr = DateToStr(UseDateEdit->Date);
						char* writetmpdatestr = writetmpstr.t_str();
						writedaytime[0] = char(((int)writetmpdatestr[2]-48)*16+((int)writetmpdatestr[3]-48));
						writedaytime[1] = char(((int)writetmpdatestr[5]-48)*16+((int)writetmpdatestr[6]-48));
						writedaytime[2] = char(((int)writetmpdatestr[8]-48)*16+((int)writetmpdatestr[9]-48));
						writedaytime[3] = 0x00;

						writesynum[0] = 0x00;
						writesynum[1] = 0x00;

						ShowMessage(PrepayTextEdit->Text.t_str());
						int writetmpbalance = atoi(PrepayTextEdit->Text.t_str())-atoi(DepositTextEdit->Text.t_str());
						writetmpbalance *= 100;
						writebalance[0] = 0x00;
						writebalance[1] = (char)((int)writetmpbalance/65536);
						writetmpbalance = writetmpbalance%65536;
						writebalance[2] = (char)((int)writetmpbalance/256);
						writetmpbalance = writetmpbalance%256;
						writebalance[3] = (char)writetmpbalance;

						unsigned char writetmpczmm[5];
						strcpy(writetmpczmm, PerPassWordTextEdit->Text.t_str());
						writetmpczmm[0] = writetmpczmm[0]<<4;
						writetmpczmm[1] = writetmpczmm[1]<<4;
						writetmpczmm[1] = writetmpczmm[1]>>4;
						writeczmm[0] = writetmpczmm[0] + writetmpczmm[1];
						writetmpczmm[2] = writetmpczmm[2]<<4;
						writetmpczmm[3] = writetmpczmm[3]<<4;
						writetmpczmm[3] = writetmpczmm[3]>>4;
						writeczmm[1] = writetmpczmm[2]+writetmpczmm[3];
						writeczmm[2] = 0x00;

						writecardtype[0] = atoi(DegreeTextEdit->Text.t_str());

						if(LaunchNewCard)
						{
							writestatus = LaunchNewCard(writereadcomno,
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
														writeDelayms);
							if(writestatus)
							{
								ShowMessage("写卡失败！");
							}
							else
							{
								String DateofLaunchCard;
								SYSTEMTIME tmpsystime;
								GetLocalTime(&tmpsystime);
								DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

								int tmpdeposit = atoi(DepositTextEdit->Text.t_str());
								int tmpPrePay = atoi(PrepayTextEdit->Text.t_str());
								int moneyincard = tmpPrePay-tmpdeposit;

								//填写CARD表
								String tmpstr = SerialNumOFCard;
								ADOQuery1->Close();
								ADOQuery1->SQL->Clear();
								String sqlstr = "insert into CARD values(:BH,:KH,:BKH,:XM,:XB,";
								sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
												":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
												":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
												":SF_KL,:USERNAME)";
								ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
								ADOQuery1->Parameters->ParamByName("KH")->Value = (NumberOFCard);
								//ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("XM")->Value = UserNameTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("XB")->Value = UserSexComboBox->Text;
								ADOQuery1->Parameters->ParamByName("SFZH")->Value = IdentityIDTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("BM")->Value = SectionNameComboBox->Text;
								ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassNameComboBox->Text;
								if(-1 != GroupNameComboBox->ItemIndex)
								{
									ADOQuery1->Parameters->ParamByName("ZB")->Value = GroupNameComboBox->Text;
								}
								ADOQuery1->Parameters->ParamByName("ZW")->Value = DegreeComboBox->Text;
								ADOQuery1->Parameters->ParamByName("JB")->Value = DegreeTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
								//ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
								ADOQuery1->Parameters->ParamByName("TYJ")->Value = 0;
								ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
								ADOQuery1->Parameters->ParamByName("GRMM")->Value = PerPassWordTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
								ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
								//ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
								ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
								ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
								ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("SF_FL")->Value = ConsumeRateComboBox->ItemIndex+1;
								ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
								ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
								//ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
								//ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
								ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
								ADOQuery1->ExecSQL();

								//填写CARD_F表
								ADOQuery1->SQL->Clear();
								sqlstr = "insert into CARD_F values(:BH,:KH,:BKH,:XM,:XB,";
								sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
								":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
								":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
								":SF_KL,:USERNAME)";
								ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
								ADOQuery1->Parameters->ParamByName("KH")->Value = (NumberOFCard);
								//ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("XM")->Value = UserNameTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("XB")->Value = UserSexComboBox->Text;
								ADOQuery1->Parameters->ParamByName("SFZH")->Value = IdentityIDTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("BM")->Value = SectionNameComboBox->Text;
								ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassNameComboBox->Text;
								if(-1 != GroupNameComboBox->ItemIndex)
								{
									ADOQuery1->Parameters->ParamByName("ZB")->Value = GroupNameComboBox->Text;
								}
								ADOQuery1->Parameters->ParamByName("ZW")->Value = DegreeComboBox->Text;
								ADOQuery1->Parameters->ParamByName("JB")->Value = DegreeTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
								//ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
								ADOQuery1->Parameters->ParamByName("TYJ")->Value = 0;
								ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
								ADOQuery1->Parameters->ParamByName("GRMM")->Value = PerPassWordTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
								ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
								//ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
								ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
								ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
								ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("SF_FL")->Value = ConsumeRateComboBox->ItemIndex+1;
								ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
								ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
								//ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
								//ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
								ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
								ADOQuery1->ExecSQL();

								//填写MX,MXBAK表
								ADOQuery1->SQL->Clear();
								sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
								ADOQuery1->Parameters->ParamByName("BH")->Value = LaunchNewCardADOQ->FieldByName("BH")->AsString;

								//填写KZT表
								LaunchNewCardADOQ->Edit();
								LaunchNewCardADOQ->FieldByName("SY")->AsString = "Y";
								LaunchNewCardADOQ->FieldByName("FKRQ")->AsString = DateofLaunchCard;
								LaunchNewCardADOQ->Post();

								cxLabel20->Caption = IntToStr(moneyincard);
								ShowMessage("发卡成功！");
								beepofreaddll(readcomno, '10');
							}
						}
						else
						{
							ShowMessage("写卡函数加载失败！");
						}
					}
					else
						ShowMessage("卡信息填写不完整，请填写完整！");*/
















void __fastcall TLaunchNewUserCardFRM::UserNameTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if(13 == Key)
    	UserSexComboBox->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::UserSexComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	if(13 == Key)
    	SectionNameComboBox->SetFocus();
    Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::ClassNameComboBoxKeyPress(TObject *Sender,
          wchar_t &Key)
{
	if(13 == Key)
    	DegreeComboBox->SetFocus();
    Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::DegreeComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	if(13 == Key)
    	GroupNameComboBox->SetFocus();
    Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::GroupNameComboBoxKeyPress(TObject *Sender,
          wchar_t &Key)
{
	if(13 == Key)
    	cxTextEdit4->SetFocus();
    Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<='0'||Key>'9'||(127 == Key)||(8 == Key)) && Key!='\b')
	{
    	if(13 == Key)
        {
            Key = 0;
        	IdentityIDTextEdit->SetFocus();
        }
        else
        {
			Key=0;
			ShowMessage("请输入1到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::DegreeTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<='0'||Key>'9'||(127 == Key)||(8 == Key)) && Key!='\b')
	{
    	if(13 == Key)
        {
            Key = 0;
        	PerPassWordTextEdit->SetFocus();
        }
        else
        {
			Key=0;
			ShowMessage("请输入1到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::DepositTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<='0'||Key>'9'||(127 == Key)||(8 == Key)) && Key!='\b')
	{
    	if(13 == Key)
        {
            Key = 0;
        	PrepayTextEdit->SetFocus();
        }
        else
        {
			Key=0;
			ShowMessage("请输入1到9之间的数字！");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::ConsumeRateComboBoxKeyPress(TObject *Sender,
          wchar_t &Key)
{
	if(13 == Key)
    	LaunchNewCardBTN->Focused();
    Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TLaunchNewUserCardFRM::Button1Click(TObject *Sender)
{
	unsigned char test[4];
	test[0] = 0xff;
	test[1] = 0xff;
	test[2] = 0xff;
	test[3] = 0xff;

	unsigned int testint = (unsigned int)test[0]*256*256*256+
							(unsigned int)test[1]*256*256+
							(unsigned int)test[2]*256+
							(unsigned int)test[3];


	AnsiString SerialNumOFCard;
	SerialNumOFCard.sprintf("%010u", testint);
	ShowMessage(SerialNumOFCard);
}
//---------------------------------------------------------------------------


void __fastcall TLaunchNewUserCardFRM::cxButton1Click(TObject *Sender)
{
	//读取卡片序列号作为编号
	WORD readserialstatus;
	unsigned char readserialdelayms;
	unsigned char readserial[4];
	ZeroMemory(readserial, 4);
	readserialdelayms = 0x01;
	readserialstatus = readserialfun(readcomno, readserial);
	if(readserialstatus)
	{
		ShowMessage("无法获取该卡片的序列号，请更换卡片!");
		return;
	}
	else
	{
		unsigned int serialnum = readserial[3]*256*256*256
								 + readserial[2]*256*256
								 + readserial[1]*256
								 + readserial[0];

		AnsiString SerialNumOFCard;

		SerialNumOFCard.sprintf("%010u", serialnum);
		SerialOFCardTextEdit->Text = SerialNumOFCard;

	//	SerialNumOFCard = SerialOFCardTextEdit->Text;
	}
}
//---------------------------------------------------------------------------
unsigned char CRCLo_arry[256] = {0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41,
								0x0, 0xC1, 0x81, 0x40, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0,
								0x80, 0x41, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1, 0x81, 0x40,
								0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1,
								0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0, 0x80, 0x41,
								0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1,
								0x81, 0x40, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41,
								0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x0, 0xC1, 0x81, 0x40,
								0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1,
								0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1, 0x81, 0x40,
								0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x0, 0xC1, 0x81, 0x40,
								0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0,
								0x80, 0x41, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1, 0x81, 0x40,
								0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41,
								0x0, 0xC1, 0x81, 0x40, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41,
								0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40, 0x0, 0xC1, 0x81, 0x40,
								0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0, 0x80, 0x41, 0x0, 0xC1,
								0x81, 0x40, 0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41,
								0x0, 0xC1, 0x81, 0x40, 0x1, 0xC0, 0x80, 0x41, 0x1, 0xC0,
								0x80, 0x41, 0x0, 0xC1, 0x81, 0x40};

unsigned char CRCHi_arry[256] = {0x0, 0xC0, 0xC1, 0x1, 0xC3, 0x3, 0x2, 0xC2, 0xC6, 0x6,
								0x7, 0xC7, 0x5, 0xC5, 0xC4, 0x4, 0xCC, 0xC, 0xD, 0xCD,
								0xF, 0xCF, 0xCE, 0xE, 0xA, 0xCA, 0xCB, 0xB, 0xC9, 0x9,
								0x8, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
								0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
								0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
								0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
								0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
								0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
								0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
								0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
								0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
								0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
								0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
								0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
								0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
								0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
								0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
								0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
								0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
								0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
								0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
								0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
								0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
								0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
								0x43, 0x83, 0x41, 0x81, 0x80, 0x40};

void __fastcall TLaunchNewUserCardFRM::CRCProc(unsigned char* InData, int len, unsigned char* CRCData)
{
	unsigned char CRC16Hi=0xff,CRC16Lo=0xff;
	int  i;
	unsigned char iIndex;
	for (i=0;i<len;i++)
	{
		iIndex = CRC16Lo ^ InData[i];
		CRC16Lo = CRC16Hi ^ CRCLo_arry[iIndex] ;
		CRC16Hi = CRCHi_arry[iIndex];
	}
	CRCData[0]=CRC16Hi;
	CRCData[1]=CRC16Lo;
}


void __fastcall TLaunchNewUserCardFRM::LaunchFLBTNClick(TObject *Sender)
{
	if(LoadHModule)
	{
		if(readwatercardinfo)
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

			Delayms = DelaySecond;
			keymode = CARDPasswordEdition;
			secnum = UsingSecNUM;

			key[0] = CARDPassword[0];
			key[1] = CARDPassword[1];
			key[2] = CARDPassword[2];
			key[3] = CARDPassword[3];
			key[4] = CARDPassword[4];
			key[5] = CARDPassword[5];
			status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！");
				return;
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
				return;
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于200000或等于0！");
				return;
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
				return;
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
				return;
			}
			else if (0 == status)
			{
				ShowMessage("此卡不能做为新卡发行，请更换新卡！");
				return;
			}
		}
	}

	if(Edit3->Text.IsEmpty()||Edit4->Text.IsEmpty()
		||Edit7->Text.IsEmpty()||Edit8->Text.IsEmpty())
	{
		MessageBox(this->Handle, "请完整的输入参数!", "ERROR", MB_ICONERROR);
		return;
	}

	unsigned char comno[5];
	unsigned char secnum,Delayms,mode,mimamode;
	WORD Status;
	unsigned char dwmm[2];
	unsigned char datetime[6];
	String datestr;
	char* pdatestr;
	unsigned char cardtype;
	unsigned char kh[4];
	unsigned char balance[6];
	unsigned char password[6];

	memcpy(comno,readcomno,5);
	secnum = UsingSecNUM;
	mimamode = CARDPasswordEdition;
	memcpy(password,CARDPassword,6);

	datestr = DateTimeToStr(Now());
	pdatestr = datestr.t_str();
	datetime[0] = (unsigned char)(((int)pdatestr[2]-48)*16+(int)pdatestr[3]-48);
	datetime[1] = (unsigned char)(((int)pdatestr[5]-48)*16+(int)pdatestr[6]-48);
	datetime[2] = (unsigned char)(((int)pdatestr[8]-48)*16+(int)pdatestr[9]-48);
	if(19 == datestr.Length())
	{
		datetime[3] = (unsigned char)(((int)pdatestr[11]-48)*16+(int)pdatestr[12]-48);
	}
	else
	{
    	datetime[3] = (unsigned char)((int)pdatestr[11]-48);
	}
	datetime[4] = 0x00;

	cardtype = 0x03;
	Delayms = 0x00;
	mode = 0x00;
	dwmm[0] = 0x12;
	dwmm[1] = 0x34;

	balance[0] = (unsigned char)(StrToInt(Edit8->Text));
	balance[1] = (unsigned char)(StrToInt(Edit4->Text));
	balance[2] = (unsigned char)(StrToInt(Edit7->Text));
	balance[3] = (unsigned char)(StrToInt(Edit3->Text));

	int tmpkh = 0;
	String khsqlstr = "select MAX(KS) as mkh from WCARD_S";
	SuperInDBADOQ->Close();
	SuperInDBADOQ->SQL->Clear();
	SuperInDBADOQ->SQL->Add(khsqlstr);
	SuperInDBADOQ->Open();
	if(SuperInDBADOQ->IsEmpty())
	{
		tmpkh = 0;
	}
	else
	{
		tmpkh = SuperInDBADOQ->FieldByName("mkh")->AsInteger;
		tmpkh++;
	}
	SuperInDBADOQ->Close();
	kh[0] = (char)(tmpkh/256/256/256);
	kh[1] = (char)((tmpkh%(256*256*256))/256/256);
	kh[2] = (char)((tmpkh%(256*256))/256);
	kh[3] = (char)tmpkh;
	AnsiString SerialNumOFCard;
	SerialNumOFCard.sprintf("%010u", tmpkh);

	//使用pacarddll写卡

	unsigned char sendbuf[26];
	unsigned char sendbuflen = 26;
	unsigned char senddelay = Delayms;
	unsigned char recbuf[140];
	unsigned char recbuflen;
	unsigned char pblock = secnum*4+0;
	unsigned char pmimamode = 0x60;
	unsigned char pcommand = 0x02;
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

	sendbuf[10] = 0x03;//卡类型
	sendbuf[11] = 0xff;//单位代码
	sendbuf[12] = 0xff;//单位代码
	sendbuf[13] = 0xff;//单位代码
	sendbuf[14] = kh[0];
	sendbuf[15] = kh[1];
	sendbuf[16] = kh[2];
	sendbuf[17] = kh[3];
	sendbuf[18] = 0xff;//保留字
	sendbuf[19] = datetime[0];
	sendbuf[20] = datetime[1];
	sendbuf[21] = datetime[2];
	sendbuf[22] = datetime[3];
	sendbuf[23] = datetime[4];
	unsigned char createCRC[16];
	unsigned char CRC[2];
	ZeroMemory(createCRC, 16);
	ZeroMemory(CRC, 2);
	memcpy(createCRC, &sendbuf[10],16);
	CRCProc(createCRC, 14, CRC);
	sendbuf[24] = CRC[0];
	sendbuf[25] = CRC[1];
	Status = pacarddllprocreader(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

	if((0 == Status)&&(0 == recbuf[2]))
	{
		pblock = secnum*4+1;
		ZeroMemory(sendbuf,26);
		ZeroMemory(recbuf,140);
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
		sendbuf[10] = (unsigned char)(StrToInt(Edit3->Text));
		sendbuf[11] = (unsigned char)(StrToInt(Edit7->Text));
		sendbuf[12] = (unsigned char)(StrToInt(Edit4->Text));
		sendbuf[13] = (unsigned char)(StrToInt(Edit8->Text));
		Status = pacarddllprocreader(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

		if((0 == Status)&&(0 == recbuf[2]))
		{
				//入库
			String sqlstr = "insert into WCARD_S values(:BH,:KS,:FL1,:FL2,:SJ1,:SJ2,:RQ,:LX,:CZY)";
			SuperInDBADOQ->Close();
			SuperInDBADOQ->SQL->Clear();
			SuperInDBADOQ->SQL->Add(sqlstr);
			SuperInDBADOQ->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
			SuperInDBADOQ->Parameters->ParamByName("KS")->Value = tmpkh;
			SuperInDBADOQ->Parameters->ParamByName("FL1")->Value = StrToInt(Edit3->Text);
			SuperInDBADOQ->Parameters->ParamByName("FL2")->Value = StrToInt(Edit4->Text);
			SuperInDBADOQ->Parameters->ParamByName("SJ1")->Value = StrToInt(Edit7->Text);
			SuperInDBADOQ->Parameters->ParamByName("SJ2")->Value = StrToInt(Edit8->Text);
			SuperInDBADOQ->Parameters->ParamByName("RQ")->Value = DateTimeToStr(Now());
			SuperInDBADOQ->Parameters->ParamByName("LX")->Value = "费率";
			SuperInDBADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
			SuperInDBADOQ->ExecSQL();
			beepofreaddll(readcomno, '10');
			MessageBox(this->Handle, "发费率卡成功!", "OK", MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			MessageBox(this->Handle, "发费率卡失败!", "ERROR", MB_ICONERROR);
		}
	}
	else
	{
		MessageBox(this->Handle, "发费率卡失败!", "ERROR", MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::LaunchTimeBTNClick(TObject *Sender)
{
	if(LoadHModule)
	{
		if(readwatercardinfo)
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

			Delayms = DelaySecond;
			keymode = CARDPasswordEdition;
			secnum = UsingSecNUM;

			key[0] = CARDPassword[0];
			key[1] = CARDPassword[1];
			key[2] = CARDPassword[2];
			key[3] = CARDPassword[3];
			key[4] = CARDPassword[4];
			key[5] = CARDPassword[5];
			status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！");
				return;
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
				return;
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于200000或等于0！");
				return;
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
				return;
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
				return;
			}
			else if (0 == status)
			{
				ShowMessage("此卡不能做为新卡发行，请更换新卡！");
				return;
			}
		}
	}

	if(Edit3->Text.IsEmpty()||Edit4->Text.IsEmpty()
		||Edit7->Text.IsEmpty()||Edit8->Text.IsEmpty())
	{
		MessageBox(this->Handle, "请完整的输入参数!", "ERROR", MB_ICONERROR);
		return;
	}

	unsigned char comno[5];
	unsigned char secnum,Delayms,mode,mimamode;
	WORD Status;
	unsigned char dwmm[2];
	unsigned char datetime[6];
	String datestr;
	char* pdatestr;
	unsigned char cardtype;
	unsigned char kh[4];
	unsigned char balance[6];
	unsigned char password[6];

	memcpy(comno,readcomno,5);
	secnum = UsingSecNUM;
	mimamode = CARDPasswordEdition;
	memcpy(password,CARDPassword,6);

	datestr = DateTimeToStr(Now());
	pdatestr = datestr.t_str();
	datetime[0] = (unsigned char)(((int)pdatestr[2]-48)*16+(int)pdatestr[3]-48);
	datetime[1] = (unsigned char)(((int)pdatestr[5]-48)*16+(int)pdatestr[6]-48);
	datetime[2] = (unsigned char)(((int)pdatestr[8]-48)*16+(int)pdatestr[9]-48);
	if(19 == datestr.Length())
	{
		datetime[3] = (unsigned char)(((int)pdatestr[11]-48)*16+(int)pdatestr[12]-48);
	}
	else
	{
    	datetime[3] = (unsigned char)((int)pdatestr[11]-48);
	}
	if(19 == datestr.Length())
	{
		datetime[4] = (unsigned char)(((int)pdatestr[14]-48)*16+(int)pdatestr[15]-48);
	}
	else
	{
    	datetime[4] = (unsigned char)((int)pdatestr[14]-48);
	}

	cardtype = 0x00;
	Delayms = 0x00;
	mode = 0x00;
	dwmm[0] = 0x12;
	dwmm[1] = 0x34;
	kh[0] = 0x00;
	kh[1] = 0x00;
	kh[2] = 0x00;
	kh[3] = 0x00;

	balance[0] = (unsigned char)(StrToInt(Edit8->Text));
	balance[1] = (unsigned char)(StrToInt(Edit4->Text));
	balance[2] = (unsigned char)(StrToInt(Edit7->Text));
	balance[3] = (unsigned char)(StrToInt(Edit3->Text));

	int tmpkh = 0;
	String khsqlstr = "select MAX(KS) as mkh from WCARD_S";
	SuperInDBADOQ->Close();
	SuperInDBADOQ->SQL->Clear();
	SuperInDBADOQ->SQL->Add(khsqlstr);
	SuperInDBADOQ->Open();
	if(SuperInDBADOQ->IsEmpty())
	{
		tmpkh = 0;
	}
	else
	{
		tmpkh = SuperInDBADOQ->FieldByName("mkh")->AsInteger;
		tmpkh++;
	}
	SuperInDBADOQ->Close();
	kh[0] = (char)(tmpkh/256/256/256);
	kh[1] = (char)((tmpkh%(256*256*256))/256/256);
	kh[2] = (char)((tmpkh%(256*256))/256);
	kh[3] = (char)tmpkh;
	AnsiString SerialNumOFCard;
	SerialNumOFCard.sprintf("%010u", tmpkh);

	//使用pacarddll写卡

	unsigned char sendbuf[26];
	unsigned char sendbuflen = 26;
	unsigned char senddelay = Delayms;
	unsigned char recbuf[140];
	unsigned char recbuflen;
	unsigned char pblock = secnum*4+0;
	unsigned char pmimamode = 0x60;
	unsigned char pcommand = 0x02;
	unsigned char pkeymode = 0x03;
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

	sendbuf[10] = 0x00;//卡类型
	sendbuf[11] = 0xff;//单位代码
	sendbuf[12] = 0xff;//单位代码
	sendbuf[13] = 0xff;//单位代码
	sendbuf[14] = kh[0];
	sendbuf[15] = kh[1];
	sendbuf[16] = kh[2];
	sendbuf[17] = kh[3];
	sendbuf[18] = 0xff;//保留字
	sendbuf[19] = datetime[0];
	sendbuf[20] = datetime[1];
	sendbuf[21] = datetime[2];
	sendbuf[22] = datetime[3];
	sendbuf[23] = datetime[4];
	unsigned char createCRC[16];
	unsigned char CRC[2];
	ZeroMemory(createCRC, 16);
	ZeroMemory(CRC, 2);
	memcpy(createCRC, &sendbuf[10],16);
	CRCProc(createCRC, 14, CRC);
	sendbuf[24] = CRC[0];
	sendbuf[25] = CRC[1];
	Status = pacarddllprocreader(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

	if((0 == Status)&&(0 == recbuf[2]))
	{
		pblock = secnum*4+1;
		ZeroMemory(sendbuf,26);
		ZeroMemory(recbuf, 140);
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
		sendbuf[10] = (unsigned char)(StrToInt(Edit3->Text));
		sendbuf[11] = (unsigned char)(StrToInt(Edit7->Text));
		sendbuf[12] = (unsigned char)(StrToInt(Edit4->Text));
		sendbuf[13] = (unsigned char)(StrToInt(Edit8->Text));

		Status = pacarddllprocreader(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

		if((0 == Status)&&(0 == recbuf[2]))
		{
			String sqlstr = "insert into WCARD_S values(:BH,:KS,:FL1,:FL2,:SJ1,:SJ2,:RQ,:LX,:CZY)";
			SuperInDBADOQ->Close();
			SuperInDBADOQ->SQL->Clear();
			SuperInDBADOQ->SQL->Add(sqlstr);
			SuperInDBADOQ->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
			SuperInDBADOQ->Parameters->ParamByName("KS")->Value = tmpkh;
			SuperInDBADOQ->Parameters->ParamByName("FL1")->Value = StrToInt(Edit3->Text);
			SuperInDBADOQ->Parameters->ParamByName("FL2")->Value = StrToInt(Edit4->Text);
			SuperInDBADOQ->Parameters->ParamByName("SJ1")->Value = StrToInt(Edit7->Text);
			SuperInDBADOQ->Parameters->ParamByName("SJ2")->Value = StrToInt(Edit8->Text);
			SuperInDBADOQ->Parameters->ParamByName("RQ")->Value = DateTimeToStr(Now());
			SuperInDBADOQ->Parameters->ParamByName("LX")->Value = "时间";
			SuperInDBADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
			SuperInDBADOQ->ExecSQL();
			beepofreaddll(readcomno, '10');
			MessageBox(this->Handle, "发时间卡成功!", "OK", MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			MessageBox(this->Handle, "发时间卡失败!", "ERROR", MB_ICONERROR);
		}
	}
	else
	{
		MessageBox(this->Handle, "发时间卡失败!", "ERROR", MB_ICONERROR);
	}

}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::LaunchClearBTNClick(TObject *Sender)
{
	if(LoadHModule)
	{
		if(readwatercardinfo)
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

			Delayms = DelaySecond;
			keymode = CARDPasswordEdition;
			secnum = UsingSecNUM;

			key[0] = CARDPassword[0];
			key[1] = CARDPassword[1];
			key[2] = CARDPassword[2];
			key[3] = CARDPassword[3];
			key[4] = CARDPassword[4];
			key[5] = CARDPassword[5];
			status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！");
				return;
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
				return;
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于200000或等于0！");
				return;
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
				return;
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
				return;
			}
			else if (0 == status)
			{
				ShowMessage("此卡不能做为新卡发行，请更换新卡！");
				return;
			}
		}
	}
	if(Edit3->Text.IsEmpty()||Edit4->Text.IsEmpty()
		||Edit7->Text.IsEmpty()||Edit8->Text.IsEmpty())
	{
		MessageBox(this->Handle, "请完整的输入参数!", "ERROR", MB_ICONERROR);
		return;
	}

	unsigned char comno[5];
	unsigned char secnum,Delayms,mode,mimamode;
	WORD Status;
	unsigned char dwmm[2];
	unsigned char datetime[6];
	String datestr;
	char* pdatestr;
	unsigned char cardtype;
	unsigned char kh[4];
	unsigned char balance[6];
	unsigned char password[6];

	memcpy(comno,readcomno,5);
	secnum = UsingSecNUM;
	mimamode = CARDPasswordEdition;
	memcpy(password,CARDPassword,6);

	datestr = DateTimeToStr(Now());
	pdatestr = datestr.t_str();
	datetime[0] = (unsigned char)(((int)pdatestr[2]-48)*16+(int)pdatestr[3]-48);
	datetime[1] = (unsigned char)(((int)pdatestr[5]-48)*16+(int)pdatestr[6]-48);
	datetime[2] = (unsigned char)(((int)pdatestr[8]-48)*16+(int)pdatestr[9]-48);
	if(19 == datestr.Length())
	{
		datetime[3] = (unsigned char)(((int)pdatestr[11]-48)*16+(int)pdatestr[12]-48);
	}
	else
	{
    	datetime[3] = (unsigned char)((int)pdatestr[11]-48);
	}
	datetime[4] = 0x00;

	cardtype = 0x02;
	Delayms = 0x00;
	mode = 0x00;
	dwmm[0] = 0x12;
	dwmm[1] = 0x34;
	kh[0] = 0x00;
	kh[1] = 0x00;
	kh[2] = 0x00;
	kh[3] = 0x00;

	balance[0] = (unsigned char)(StrToInt(Edit8->Text));
	balance[1] = (unsigned char)(StrToInt(Edit4->Text));
	balance[2] = (unsigned char)(StrToInt(Edit7->Text));
	balance[3] = (unsigned char)(StrToInt(Edit3->Text));

	int tmpkh = 0;
	String khsqlstr = "select MAX(KS) as mkh from WCARD_S";
	SuperInDBADOQ->Close();
	SuperInDBADOQ->SQL->Clear();
	SuperInDBADOQ->SQL->Add(khsqlstr);
	SuperInDBADOQ->Open();
	if(SuperInDBADOQ->IsEmpty())
	{
		tmpkh = 0;
	}
	else
	{
		tmpkh = SuperInDBADOQ->FieldByName("mkh")->AsInteger;
		tmpkh++;
	}
	SuperInDBADOQ->Close();
	kh[0] = (char)(tmpkh/256/256/256);
	kh[1] = (char)((tmpkh%(256*256*256))/256/256);
	kh[2] = (char)((tmpkh%(256*256))/256);
	kh[3] = (char)tmpkh;
	AnsiString SerialNumOFCard;
	SerialNumOFCard.sprintf("%010u", tmpkh);

	//使用pacarddll写卡

	unsigned char sendbuf[26];
	unsigned char sendbuflen = 26;
	unsigned char senddelay = Delayms;
	unsigned char recbuf[140];
	unsigned char recbuflen;
	unsigned char pblock = secnum*4+0;
	unsigned char pmimamode = 0x60;
	unsigned char pcommand = 0x02;
	unsigned char pkeymode = 0x03;
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

	sendbuf[10] = 0x02;//卡类型
	sendbuf[11] = 0xff;//单位代码
	sendbuf[12] = 0xff;//单位代码
	sendbuf[13] = 0xff;//单位代码
	sendbuf[14] = kh[0];
	sendbuf[15] = kh[1];
	sendbuf[16] = kh[2];
	sendbuf[17] = kh[3];
	sendbuf[18] = 0xff;//保留字
	sendbuf[19] = datetime[0];
	sendbuf[20] = datetime[1];
	sendbuf[21] = datetime[2];
	sendbuf[22] = datetime[3];
	sendbuf[23] = datetime[4];
	unsigned char createCRC[16];
	unsigned char CRC[2];
	ZeroMemory(createCRC, 16);
	ZeroMemory(CRC, 2);
	memcpy(createCRC, &sendbuf[10],16);
	CRCProc(createCRC, 14, CRC);
	sendbuf[24] = CRC[0];
	sendbuf[25] = CRC[1];
	Status = pacarddllprocreader(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

	if((0 == Status)&&(0 == recbuf[2]))
	{
		pblock = secnum*4+1;
		ZeroMemory(sendbuf,26);
		ZeroMemory(recbuf,140);
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
		sendbuf[10] = (unsigned char)(StrToInt(Edit3->Text));
		sendbuf[11] = (unsigned char)(StrToInt(Edit7->Text));
		sendbuf[12] = (unsigned char)(StrToInt(Edit4->Text));
		sendbuf[13] = (unsigned char)(StrToInt(Edit8->Text));
		Status = pacarddllprocreader(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

		if((0 == Status)&&(0 == recbuf[2]))
		{
			String sqlstr = "insert into WCARD_S values(:BH,:KS,:FL1,:FL2,:SJ1,:SJ2,:RQ,:LX,:CZY)";
			SuperInDBADOQ->Close();
			SuperInDBADOQ->SQL->Clear();
			SuperInDBADOQ->SQL->Add(sqlstr);
			SuperInDBADOQ->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
			SuperInDBADOQ->Parameters->ParamByName("KS")->Value = tmpkh;
			SuperInDBADOQ->Parameters->ParamByName("FL1")->Value = StrToInt(Edit3->Text);
			SuperInDBADOQ->Parameters->ParamByName("FL2")->Value = StrToInt(Edit4->Text);
			SuperInDBADOQ->Parameters->ParamByName("SJ1")->Value = StrToInt(Edit7->Text);
			SuperInDBADOQ->Parameters->ParamByName("SJ2")->Value = StrToInt(Edit8->Text);
			SuperInDBADOQ->Parameters->ParamByName("RQ")->Value = DateTimeToStr(Now());
			SuperInDBADOQ->Parameters->ParamByName("LX")->Value = "清除";
			SuperInDBADOQ->Parameters->ParamByName("CZY")->Value = OperatorName;
			SuperInDBADOQ->ExecSQL();
			beepofreaddll(readcomno, '10');
			MessageBox(this->Handle, "发清除卡成功!", "OK", MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			MessageBox(this->Handle, "发清除卡失败!", "ERROR", MB_ICONERROR);
		}
	}
	else
	{
		MessageBox(this->Handle, "发清除卡失败!", "ERROR", MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TLaunchNewUserCardFRM::ReadSupCardBTNClick(TObject *Sender)
{
//读特权卡信息
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
		if(readwatercardinfo)
		{
			status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！请进行“检测读写器”操作！");
				return;
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
				return;
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于200000或等于0！");
				return;
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
				return;
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
				return;
			}
			else if (0 == status)
			{
				//从数据库中寻找可用卡号
				if(cardtype[0] == 0x04)
				{
					MessageBox(this->Handle, "此卡是用户卡!", "Notice", MB_OK|MB_ICONINFORMATION);
					return;
				}

				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				String superchecksqlstr = "select * from WCARD_S where KS=";
				superchecksqlstr += tmpkh;
				ADOQuery1->Close();
				ADOQuery1->SQL->Clear();
				ADOQuery1->SQL->Add(superchecksqlstr);
				ADOQuery1->Open();
				if(!ADOQuery1->IsEmpty())
				{
					String outstr = "此卡为";
					outstr += ADOQuery1->FieldByName("LX")->AsString.Trim();
					outstr += "卡，卡号为";
					outstr += tmpkh;
					if("费率" == ADOQuery1->FieldByName("LX")->AsString.Trim())
					{
						outstr += "! 费率一（单位分）为：";
						outstr += StrToInt(ADOQuery1->FieldByName("FL1")->AsString.Trim());
						outstr += "，脉冲数为：";
						outstr += StrToInt(ADOQuery1->FieldByName("SJ1")->AsString.Trim());
					//	outstr += "，费率二为：";
					//	outstr += StrToInt(ADOQuery1->FieldByName("FL2")->AsString.Trim());
					}
					outstr += "。";
					MessageBox(this->Handle, outstr.t_str(), "Notice",MB_OK|MB_ICONINFORMATION);
					ADOQuery1->Close();
					return;
				}
				else
				{
					MessageBox(this->Handle, "此卡不属于本系统!", "Notice", MB_OK|MB_ICONINFORMATION);
					ADOQuery1->Close();
					return;
                }
			}
		}
	}
}
//---------------------------------------------------------------------------


