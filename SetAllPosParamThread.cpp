//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetAllPosParamThread.h"
#include "SDIMAIN.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSetAllPosParamThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSetAllPosParamThread::TSetAllPosParamThread(bool CreateSuspended,
														 TADOQuery* ADOQ,
														 TcxListView* LV,
														 TcxButton* SABTN,
														 TcxButton* SSBTN,
														 TcxButton* DelBTN,
														 TcxButton* AddBTN,
                                                         TcxButton* AddMBTN,
														 TcxButton* ScanBTN,
														 TcxButton* EndBTN,
														 TcxButton* ExitBTN,
                                                         TcxButton* SelABTN,
														 TcxButton* CalSABTN,
														 TcxButton* SABPBTN,
														 TcxProgressBar* ProBar,
                                                         TCheckBox* CheckBox) : TThread(CreateSuspended)
{
	ValidADOQ = ADOQ;
	ValidLV = LV;
	ValidSABTN = SABTN;
	ValidSSBTN = SSBTN;
	ValidDelBTN = DelBTN;
	ValidAddBTN = AddBTN;
    ValidAddMBTN = AddMBTN;
	ValidScanBTN = ScanBTN;
	ValidEndBTN = EndBTN;
	ValidExitBTN = ExitBTN;
	ValidProBar = ProBar;
	ValidSelABTN = SelABTN;
	ValidSABPBTN = SABPBTN;
    ValidCalSABTN = CalSABTN;
    ValidCheckBox = CheckBox;
}
//---------------------------------------------------------------------------
void __fastcall TSetAllPosParamThread::Execute()
{
	//---- Place thread code here ----
	ValidSABTN->Enabled = false;
	ValidSSBTN->Enabled = false;
	ValidDelBTN->Enabled = false;
	ValidAddBTN->Enabled = false;
	ValidScanBTN->Enabled = false;
	ValidEndBTN->Enabled = false;
	ValidExitBTN->Enabled = false;
    ValidSelABTN->Enabled = false;
	ValidCalSABTN->Enabled = false;
	ValidSABPBTN->Enabled = false;
    ValidAddMBTN->Enabled = false;
	ValidProBar->Position = 0;

/*	bool gtag,atag,ltag;
	gtag = ValidGroupCheckBox->Checked;
	atag = ValidAutoChangeCheckBox->Checked;
	ltag = ValidLimitTimeCheckBox->Checked; */

	int count = ValidLV->Items->Count;
//	int currentpos = 1;
	int allpos = count;

    unsigned char preorderpar[17];
    ZeroMemory(preorderpar, 17);

//    if(ValidCheckBox->Checked)
    {
    	ValidADOQ->Close();
        ValidADOQ->SQL->Clear();
        ValidADOQ->SQL->Add("select * from PreOderMEAlINFO");
        ValidADOQ->Open();
        if(!ValidADOQ->IsEmpty())
        {
        	preorderpar[0] = 0x5a;
			String bsstr = ValidADOQ->FieldByName("breakfaststart")->AsString.Trim();
            String bestr = ValidADOQ->FieldByName("breakfastend")->AsString.Trim();
            String lsstr = ValidADOQ->FieldByName("lunchstart")->AsString.Trim();
            String lestr = ValidADOQ->FieldByName("lunchend")->AsString.Trim();
            String ssstr = ValidADOQ->FieldByName("supperstart")->AsString.Trim();
            String sestr = ValidADOQ->FieldByName("supperend")->AsString.Trim();
            String nsstr = ValidADOQ->FieldByName("nightstart")->AsString.Trim();
            String nestr = ValidADOQ->FieldByName("nightend")->AsString.Trim();

            IntToUChar(StrToInt("0x"+bsstr.SubString(1, 2)), &preorderpar[1]);
            IntToUChar(StrToInt("0x"+bestr.SubString(1, 2)), &preorderpar[2]);
            IntToUChar(StrToInt("0x"+lsstr.SubString(1, 2)), &preorderpar[3]);
            IntToUChar(StrToInt("0x"+lestr.SubString(1, 2)), &preorderpar[4]);
            IntToUChar(StrToInt("0x"+ssstr.SubString(1, 2)), &preorderpar[5]);
            IntToUChar(StrToInt("0x"+sestr.SubString(1, 2)), &preorderpar[6]);
            IntToUChar(StrToInt("0x"+nsstr.SubString(1, 2)), &preorderpar[7]);
            IntToUChar(StrToInt("0x"+nestr.SubString(1, 2)), &preorderpar[8]);

            preorderpar[9] = ValidADOQ->FieldByName("breakfastmoney1")->AsFloat*10;
            preorderpar[10] = ValidADOQ->FieldByName("breakfastmoney2")->AsFloat*10;
            preorderpar[11] = ValidADOQ->FieldByName("lunchmoney1")->AsFloat*10;
            preorderpar[12] = ValidADOQ->FieldByName("lunchmoney2")->AsFloat*10;
            preorderpar[13] = ValidADOQ->FieldByName("suppermoney1")->AsFloat*10;
            preorderpar[14] = ValidADOQ->FieldByName("suppermoney2")->AsFloat*10;
            preorderpar[15] = ValidADOQ->FieldByName("nightmoney1")->AsFloat*10;
            preorderpar[16] = ValidADOQ->FieldByName("nightmoney2")->AsFloat*10;
        }
        ValidADOQ->Close();
    }

    unsigned char submealpar[53];
    ZeroMemory(submealpar,53);

    bool submealtag = false;
    ValidADOQ->Close();
    ValidADOQ->SQL->Clear();
    ValidADOQ->SQL->Add("select * from SUBMEALINFO");
    ValidADOQ->Open();
    if(!ValidADOQ->IsEmpty())
    {
    	submealtag = true;
        if(ValidADOQ->FieldByName("Con1")->AsBoolean)
        	submealpar[0] = submealpar[0]|0x01;

        if(ValidADOQ->FieldByName("Con2")->AsBoolean)
        	submealpar[0] = submealpar[0]|0x02;

        if(ValidADOQ->FieldByName("Con3")->AsBoolean)
        	submealpar[0] = submealpar[0]|0x04;

        submealpar[1] = maxconsumption1;
        submealpar[2] = maxconsumption2;
        submealpar[3] = maxconsumption3;
        submealpar[4] = maxconsumption4;

        String bsstr = TimeToStr(ValidADOQ->FieldByName("breakfaststart")->AsDateTime);
        String bestr = TimeToStr(ValidADOQ->FieldByName("breakfastend")->AsDateTime);
        String lsstr = TimeToStr(ValidADOQ->FieldByName("lunchstart")->AsDateTime);
        String lestr = TimeToStr(ValidADOQ->FieldByName("lunchend")->AsDateTime);
        String ssstr = TimeToStr(ValidADOQ->FieldByName("supperstart")->AsDateTime);
        String sestr = TimeToStr(ValidADOQ->FieldByName("supperend")->AsDateTime);
        String nsstr = TimeToStr(ValidADOQ->FieldByName("nightstart")->AsDateTime);
        String nestr = TimeToStr(ValidADOQ->FieldByName("nightend")->AsDateTime);

        IntToUChar(StrToInt("0x"+bsstr.SubString(1, 2)), &submealpar[5]);
        IntToUChar(StrToInt("0x"+bsstr.SubString(4, 2)), &submealpar[6]);
        IntToUChar(StrToInt("0x"+bestr.SubString(1, 2)), &submealpar[7]);
        IntToUChar(StrToInt("0x"+bestr.SubString(4, 2)), &submealpar[8]);

        IntToUChar(StrToInt("0x"+lsstr.SubString(1, 2)), &submealpar[9]);
        IntToUChar(StrToInt("0x"+lsstr.SubString(4, 2)), &submealpar[10]);
        IntToUChar(StrToInt("0x"+lestr.SubString(1, 2)), &submealpar[11]);
        IntToUChar(StrToInt("0x"+lestr.SubString(4, 2)), &submealpar[12]);

        IntToUChar(StrToInt("0x"+ssstr.SubString(1, 2)), &submealpar[13]);
        IntToUChar(StrToInt("0x"+ssstr.SubString(4, 2)), &submealpar[14]);
        IntToUChar(StrToInt("0x"+sestr.SubString(1, 2)), &submealpar[15]);
        IntToUChar(StrToInt("0x"+sestr.SubString(4, 2)), &submealpar[16]);

        IntToUChar(StrToInt("0x"+nsstr.SubString(1, 2)), &submealpar[17]);
        IntToUChar(StrToInt("0x"+nsstr.SubString(4, 2)), &submealpar[18]);
        IntToUChar(StrToInt("0x"+nestr.SubString(1, 2)), &submealpar[19]);
        IntToUChar(StrToInt("0x"+nestr.SubString(4, 2)), &submealpar[20]);

        submealpar[21] = ValidADOQ->FieldByName("breakfastmoney11")->AsFloat*10;
        submealpar[22] = ValidADOQ->FieldByName("breakfastmoney21")->AsFloat*10;
        submealpar[23] = ValidADOQ->FieldByName("breakfastmoney31")->AsFloat*10;
        submealpar[24] = ValidADOQ->FieldByName("breakfastmoney41")->AsFloat*10;
        submealpar[25] = ValidADOQ->FieldByName("breakfastmoney12")->AsFloat*10;
        submealpar[26] = ValidADOQ->FieldByName("breakfastmoney22")->AsFloat*10;
        submealpar[27] = ValidADOQ->FieldByName("breakfastmoney32")->AsFloat*10;
        submealpar[28] = ValidADOQ->FieldByName("breakfastmoney42")->AsFloat*10;

        submealpar[29] = ValidADOQ->FieldByName("lunchmoney11")->AsFloat*10;
        submealpar[30] = ValidADOQ->FieldByName("lunchmoney21")->AsFloat*10;
        submealpar[31] = ValidADOQ->FieldByName("lunchmoney31")->AsFloat*10;
        submealpar[32] = ValidADOQ->FieldByName("lunchmoney41")->AsFloat*10;
        submealpar[33] = ValidADOQ->FieldByName("lunchmoney12")->AsFloat*10;
        submealpar[34] = ValidADOQ->FieldByName("lunchmoney22")->AsFloat*10;
        submealpar[35] = ValidADOQ->FieldByName("lunchmoney32")->AsFloat*10;
        submealpar[36] = ValidADOQ->FieldByName("lunchmoney42")->AsFloat*10;

        submealpar[37] = ValidADOQ->FieldByName("suppermoney11")->AsFloat*10;
        submealpar[38] = ValidADOQ->FieldByName("suppermoney21")->AsFloat*10;
        submealpar[39] = ValidADOQ->FieldByName("suppermoney31")->AsFloat*10;
        submealpar[40] = ValidADOQ->FieldByName("suppermoney41")->AsFloat*10;
        submealpar[41] = ValidADOQ->FieldByName("suppermoney12")->AsFloat*10;
        submealpar[42] = ValidADOQ->FieldByName("suppermoney22")->AsFloat*10;
        submealpar[43] = ValidADOQ->FieldByName("suppermoney32")->AsFloat*10;
        submealpar[44] = ValidADOQ->FieldByName("suppermoney42")->AsFloat*10;

        submealpar[45] = ValidADOQ->FieldByName("nightmoney11")->AsFloat*10;
        submealpar[46] = ValidADOQ->FieldByName("nightmoney21")->AsFloat*10;
        submealpar[47] = ValidADOQ->FieldByName("nightmoney31")->AsFloat*10;
        submealpar[48] = ValidADOQ->FieldByName("nightmoney41")->AsFloat*10;
        submealpar[49] = ValidADOQ->FieldByName("nightmoney21")->AsFloat*10;
        submealpar[50] = ValidADOQ->FieldByName("nightmoney22")->AsFloat*10;
        submealpar[51] = ValidADOQ->FieldByName("nightmoney32")->AsFloat*10;
        submealpar[52] = ValidADOQ->FieldByName("nightmoney42")->AsFloat*10;
    }
    ValidADOQ->Close();

//    MessageBox(SDIAppForm->Handle, "note",IntToStr(count).t_str() , MB_OK);
//    ShowMessage(IntToStr(count));
	for(int i = 0; i < count; i++)
	{
		if(!Terminated)
		{
			TListItem* tmpitem = ValidLV->Items->Item[i];
//            MessageBox(SDIAppForm->Handle, "note", ValidLV->Items->Item[i]->Caption.t_str(), MB_OK);
            if(tmpitem->Checked)
            {
                POSPARA* para = (POSPARA*)tmpitem->Data;

                ValidProBar->Position = (i+1)*100/allpos;
         //       currentpos++;
                //设置POS机

                unsigned char CMD = 0x32;
                WORD nSendStr = 126;
                WORD status;

                unsigned char SendStr[200] = "";


                SendStr[0] = UsingSecNUM;//0x01; //扇区号
                SendStr[1] = 0x00; //消费类型

                SendStr[2] = DWPassword[0];
                SendStr[3] = DWPassword[1];

                SendStr[4] = 0x00;    //保留
                SendStr[5] = para->posnum; //ValidADOQ->FieldByName("JH")->AsInteger;//0x00;    //机号不改变下面值？？？

                ValidADOQ->Close();
                ValidADOQ->SQL->Clear();
                String sqlstr = "select * from SFJPARAM where JH=";
                sqlstr += para->posnum;
                sqlstr += " and SFJPORT=";
                sqlstr += para->comnum;

                ValidADOQ->SQL->Add(sqlstr);
                ValidADOQ->Open();
                if(!ValidADOQ->IsEmpty())
                {
                    Sleep(100);
                    String PW = ValidADOQ->FieldByName("PASSWORD")->AsString;
                    String Hmm = "0x" + PW.SubString(1, 2);
                    String Lmm = "0x" + PW.SubString(3, 2);
                    SendStr[6] = (unsigned char)StrToInt(Hmm);   //操作密码
                    SendStr[7] = (unsigned char)StrToInt(Lmm);   //操作密码

                    bool dingcantag = ValidADOQ->FieldByName("DINGCAN")->AsBoolean;
					bool DELBTtag = ValidADOQ->FieldByName("DELBT")->AsBoolean;
					bool maxtag = ValidADOQ->FieldByName("MAXCSTAG")->AsBoolean;

                    for (int i = 8; i <= 37; i++)
                    {
                        SendStr[i] = 0x00;        //保留
					}

					if(maxtag)
					{
						SendStr[8] = ValidADOQ->FieldByName("MAXCS")->AsInteger;
						SendStr[8] = SendStr[8]<<4;
                    }

                    SendStr[38] = CARDPasswordEdition;//0x01; 	//密码版本

                    SendStr[39] = CARDPassword[0];//0x00;     //MF卡密码？？？
                    SendStr[40] = CARDPassword[1];//0x00;     //MF卡密码？？？
                    SendStr[41] = CARDPassword[2];//0x00;     //MF卡密码？？？
                    SendStr[42] = CARDPassword[3];//0x00;     //MF卡密码？？？
                    SendStr[43] = CARDPassword[4];//0x00;     //MF卡密码？？？
                    SendStr[44] = CARDPassword[5];//0x00;     //MF卡密码？？？

                    int tmpmax = ValidADOQ->FieldByName("MAXXF")->AsFloat*100;      //最大消费
                    SendStr[45] = (unsigned char)((int)(tmpmax/65536));
                    SendStr[46] = (unsigned char)((int)((tmpmax%65536)/256));
                    SendStr[47] = (unsigned char)(tmpmax%256);

                    SendStr[48] = 0x00;    //固定消费金额
                    SendStr[49] = 0x00;    //固定消费金额
                    SendStr[50] = 0x00;    //固定消费金额

                    SendStr[51] = 0x00;    //单位固定消费金额
                    SendStr[52] = 0x00;    //单位固定消费金额
                    SendStr[53] = 0x00;    //单位固定消费金额

                    int Max1 = ValidADOQ->FieldByName("MAXZZZE")->AsFloat*100;
                    int Max2 = maxconsumption1*100;
                    int Max3 = maxconsumption2*100;
                    int Max4 = maxconsumption3*100;
                    int Max5 = maxconsumption4*100;

                    //每天最大消费begin
                    SendStr[54] = (unsigned char)((int)(Max1/65536));
                    SendStr[55] = (unsigned char)((int)((Max1%65536)/256));
                    SendStr[56] = (unsigned char)(Max1%256);
                    for (int i = 57; i <= 89; i++)
                    {
                        SendStr[i] = 0x00;
                    }

                    SendStr[9] = submealpar[0];
                    SendStr[10] = submealpar[1];
                    SendStr[11] = submealpar[2];
                    SendStr[12] = submealpar[3];
                    SendStr[13] = submealpar[4];

                    for(int tt = 0; tt<16; tt++)
                    {
                        SendStr[14+tt] = submealpar[5+tt];
                    }

                    for(int tt = 0; tt<32; tt++)
                    {
                        SendStr[86+tt] = submealpar[21+tt];
                    }

/*                  SendStr[90] = (unsigned char)((int)(Max2/65536));
                    SendStr[91] = (unsigned char)((int)((Max2%65536)/256));
                    SendStr[92] = (unsigned char)(Max2%256);

                    SendStr[93] = (unsigned char)((int)(Max3/65536));
                    SendStr[94] = (unsigned char)((int)((Max3%65536)/256));
                    SendStr[95] = (unsigned char)(Max3%256);

                    SendStr[96] = (unsigned char)((int)(Max4/65536));
                    SendStr[97] = (unsigned char)((int)((Max4%65536)/256));
                    SendStr[98] = (unsigned char)(Max4%256);

                    SendStr[99] = (unsigned char)((int)(Max5/65536));
                    SendStr[100] = (unsigned char)((int)((Max5%65536)/256));
                    SendStr[101] = (unsigned char)(Max5%256);   */
                    //每天最大消费end

                    if(dingcantag)
                    	SendStr[35] = preorderpar[0];
                    else
                    	SendStr[35] = 0x00;

                    if(DELBTtag)
                    	SendStr[36] = 0xa5;
                    else
                    	SendStr[36] = 0x00;

                    for(int tt = 0; tt<8; tt++)
                    {
                    	SendStr[57+tt] = preorderpar[1+tt];
					}

                    for(int tt = 0; tt<8; tt++)
                    {
                    	SendStr[118+tt] = preorderpar[1+tt];
					}

                    status = SerSendFunc((unsigned char)(ValidADOQ->FieldByName("SFJPORT")->AsInteger),
                                         WORD(ValidADOQ->FieldByName("JH")->AsInteger),
                                         CMD,
                                         SendStr,
                                         nSendStr,
                                         1);
                    if(0 == status)
                    {
                        //设置时间
                        tmpitem->ImageIndex = 2;
                        CMD = 0x31;
                        String datestr = DateTimeToStr(Now());
                        char* timepstr = datestr.t_str();

                        SendStr[0] = (unsigned char)(((int)timepstr[2]-48)*16+(int)timepstr[3]-48);
                        SendStr[1] = (unsigned char)(((int)timepstr[5]-48)*16+(int)timepstr[6]-48);
                        SendStr[2] = (unsigned char)(((int)timepstr[8]-48)*16+(int)timepstr[9]-48);

                        if(19 == datestr.Length())
                        {
                            SendStr[3] = (unsigned char)(((int)timepstr[11]-48)*16+(int)timepstr[12]-48);
                            SendStr[4] = (unsigned char)(((int)timepstr[14]-48)*16+(int)timepstr[15]-48);
                            SendStr[5] = (unsigned char)(((int)timepstr[17]-48)*16+(int)timepstr[18]-48);
                        }
                        else
                        {
                            SendStr[3] = (unsigned char)((int)timepstr[11]-48);
                            SendStr[4] = (unsigned char)(((int)timepstr[13]-48)*16+(int)timepstr[14]-48);
                            SendStr[5] = (unsigned char)(((int)timepstr[16]-48)*16+(int)timepstr[17]-48);
                        }

                        nSendStr = 8;

                        status = SerSendFunc((unsigned char)(ValidADOQ->FieldByName("SFJPORT")->AsInteger),
                                            WORD(ValidADOQ->FieldByName("JH")->AsInteger),
                                            CMD,
                                            SendStr,
                                            nSendStr,
                                            1);
                    }
                    else
                    {
                        tmpitem->ImageIndex = 3;
                    }
                }
                ValidADOQ->Close();
            }
		}
	}

    ValidProBar->Position = 100;
	MessageBox(SDIAppForm->Handle, "POS机参数下传完毕!", "设置所有POS机", MB_OK|MB_ICONEXCLAMATION);
	ValidSABTN->Enabled = true;
	ValidSSBTN->Enabled = true;
	ValidDelBTN->Enabled = true;
	ValidAddBTN->Enabled = true;
    ValidAddMBTN->Enabled = true;
	ValidScanBTN->Enabled = true;
	ValidEndBTN->Enabled = true;
	ValidExitBTN->Enabled = true;
	ValidSelABTN->Enabled = true;
	ValidSABPBTN->Enabled = true;
    ValidCalSABTN->Enabled = true;
	return;
}
//---------------------------------------------------------------------------
