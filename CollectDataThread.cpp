//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CollectDataThread.h"
#include "SDIMAIN.h"
#include "GlobalParameter.h"
#include "RealTimeCollectDataFRM.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCollectDataThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCollectDataThread::TCollectDataThread(bool CreateSuspended,
												  bool* collecttag,
												  bool GSTag,
												  TcxListView* DataListView,
												  TTreeView* OnLinePosTreeList,
												  int* PosNum,
												  TADOQuery* updateQuery,
												  TADOTable* LostInfoT
										   //		  TcxTextEdit* username,
										   //		  TcxTextEdit* cardno,
										   //		  TcxTextEdit* place,
										   //		  TcxTextEdit* money
										   			) : TThread(CreateSuspended)
{
	validcollecttag = collecttag;
	ValidGSTag = GSTag;
	DisplayListView = DataListView;
	ValidPosTreeList = OnLinePosTreeList;
	ONLinePosNum = PosNum;
	UpdateDataBaseQuery = updateQuery;
	ValidLostInfoT = LostInfoT;
//	Validusername = username;
//	Validcardno = cardno;
//	Validplace = place;
//	Validmoney = money;
}
//---------------------------------------------------------------------------

void __fastcall TCollectDataThread::Execute()
{
	//---- Place thread code here ----
	if(SerReceiveFunc&&SendAckFunc)
	{
		ValidLostInfoT->Active = false;
		ValidLostInfoT->Active = true;
		ValidLostInfoT->First();

		*validcollecttag = true;
		ModeOFCollect = 1;
		String CollectTime = "*CollectTime* ";
		CollectTime += Date();
		CollectTime += " ";
		CollectTime += Time();

//		DataSaveToFileStream<<endl<<CollectTime.t_str()<<endl;

		TTreeNode* tmpnode = ValidPosTreeList->Items->GetFirstNode();
		while(tmpnode)
		{
			if(!Terminated)
			{
				tmpnode->Data;
				POSPARA* tmppospara = (POSPARA*)(tmpnode->Data);
				if(4 == tmppospara->tag)
				{
					WORD ReceiveStatus = -1;
					WORD SynchroStatus = -1;
					char temp[10] = "";
					unsigned char como = (unsigned char)(tmppospara->comnum);
					WORD PosNO = (WORD)(tmppospara->posnum);
					unsigned char ReceiveCMD = 0x25;
					unsigned char SynchroCMD = 0x54;
					ZeroMemory(receivebuf, 16);
					int receivelen = 16;
					unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
					int dirlen = strlen(dir);

			 //		unsigned char* SynchroTagbuf = new unsigned char[300];
			 //		ZeroMemory(SynchroTagbuf, *ONLinePosNum);

					String comparestr = "FFFFFF";

					UpdateDataBaseQuery->Close();
					UpdateDataBaseQuery->SQL->Clear();
					String tmpsql = "select * from SFJPARAM where JH='";
					tmpsql += tmppospara->posnum;
					tmpsql += "'";
					UpdateDataBaseQuery->SQL->Add(tmpsql);
					UpdateDataBaseQuery->Open();
					Place = UpdateDataBaseQuery->FieldByName("STNAME")->AsAnsiString.Trim();
					UpdateDataBaseQuery->Close();

					if(!Terminated)
					{
						ReceiveStatus = SerReceiveFunc(como, PosNO, ReceiveCMD, receivebuf, receivelen, 1, dir, dirlen);
						if(0 == ReceiveStatus)
						{
							SynchroStatus = SendAckFunc(como, SynchroCMD);
							if(0 == SynchroStatus)
							{
								OrignalDataStr = "";
								for (int i = 0; i < receivelen; i++)
								{
									OrignalDataStr = OrignalDataStr + (IntToHex((byte)receivebuf[i], 2));
								}

								if(comparestr != OrignalDataStr.SubString(0, 6))
								{
									PosNumber = PosNO;
									DataStatusStr = "正常";
									Synchronize(SaveDataToFileFunc);
									Synchronize(UpdateDataBaseFunc);
									Synchronize(DisplayDataFunc);
								}
							}
							Sleep(50);
						}

						//挂失一条
						if(ValidGSTag)
						{
							Sleep(50);
							int GSkh;
							unsigned char SendStr[3];
							int Strlen = 3;
							unsigned char status;
							unsigned char port;
							WORD pos;
							unsigned char CMD;

							if(!ValidLostInfoT->Eof)
							{
								GSkh = ValidLostInfoT->FieldByName("PARA")->AsInteger;
								SendStr[0] = (unsigned char)(GSkh/65536);
								SendStr[1] = (unsigned char)((GSkh%65536)/256);
								SendStr[2] = (unsigned char)GSkh;
								port = (unsigned char)(ValidLostInfoT->FieldByName("SFJPORT")->AsInteger);
								pos = WORD(ValidLostInfoT->FieldByName("SFJID")->AsInteger);

								if(1 == ValidLostInfoT->FieldByName("CMD")->AsInteger)
								{
									CMD = 0x33;
									status = SerSendFunc(port, pos, CMD, SendStr, Strlen, 1);
									if(0 == status)
									{
										ValidLostInfoT->Delete();
								   //		ValidLostInfoT->Next();
									}
									else
										ValidLostInfoT->Next();
								}
								else if(2 == ValidLostInfoT->FieldByName("CMD")->AsInteger)
								{
									CMD = 0x38;
									status = SerSendFunc(port, pos, CMD, SendStr, Strlen, 1);
									if(0 == status)
									{
										ValidLostInfoT->Delete();
									//	ValidLostInfoT->Next();
									}
									else
										ValidLostInfoT->Next();
								}
								Sleep(50);
							}
						}
					}
					else
					{
						*validcollecttag = false;
						ModeOFCollect = 0;
				  //		if(DataSaveToFileStream)
				  //			DataSaveToFileStream.close();
						RealTimeCollectFRM->Close();
						return;
					}
				}
			}
			else
			{
				*validcollecttag = false;
				ModeOFCollect = 0;
		   //		if(DataSaveToFileStream)
		   //			DataSaveToFileStream.close();
				RealTimeCollectFRM->Close();
				return;
			}
			tmpnode = tmpnode->GetNext();
			if(!tmpnode)
				tmpnode = ValidPosTreeList->Items->GetFirstNode();
		}
	}
	else
	{
		*validcollecttag = false;
		ModeOFCollect = 0;
	//	if(DataSaveToFileStream)
	//		DataSaveToFileStream.close();
		MessageBox(SDIAppForm->Handle, "Error in Load SerReceiveFunc Or SendAckFunc!", "Error", MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCollectDataThread::DisplayDataFunc()
{
	TListItem* tmp = DisplayListView->Items->Add();
	String posstr = PosNumber;
	posstr += "Pos机";
	tmp->Caption = posstr;
	tmp->SubItems->Add(USERNAME);
	tmp->SubItems->Add(CARDNO);
	tmp->SubItems->Add(YUE);
	tmp->SubItems->Add(MONEY);
	tmp->SubItems->Add(ConSumeTime);
	tmp->SubItems->Add(Place);
	tmp->SubItems->Add(DSYCS);
//	tmp->SubItems->Add(OrignalDataStr);
//	tmp->SubItems->Add(DataStatusStr);

	tmp->Selected = true;
	DisplayListView->SetFocus();
	DisplayListView->Selected->MakeVisible(true);
}
//---------------------------------------------------------------------------

void __fastcall TCollectDataThread::SaveDataToFileFunc()
{
	DataSaveToFileStream<<OrignalDataStr.t_str()<<endl;
}
//---------------------------------------------------------------------------

void __fastcall TCollectDataThread::UpdateDataBaseFunc()
{
	int tmpKH;
	int tmpXFCS;
	double tmpYE;
	double tmpXFJE;
	String tmpDATESTR;
	String tmpXFLX;
	String tmpSQLSTR;
	String username;

	bool errortag = false;

	unsigned char instr[4];
	unsigned char outstr[6];
	ZeroMemory(instr, 4);
	ZeroMemory(outstr, 6);

//begin提取卡信息----------------------------------------
	instr[0] = receivebuf[11];
	instr[1] = receivebuf[12];
	instr[2] = receivebuf[13];
	instr[3] = receivebuf[14];

	tmpKH = (int)receivebuf[0]*256*256+(int)receivebuf[1]*256+(int)receivebuf[2];
	tmpXFCS = (int)receivebuf[3]*256+(int)receivebuf[4];
	tmpYE = ((double)receivebuf[5]*256*256+(double)receivebuf[6]*256+(double)receivebuf[7])/100;
	tmpXFJE = ((double)receivebuf[8]*256*256+(double)receivebuf[9]*256+(double)receivebuf[10])/100;

	if(GetnormaldateFunc)
	{
		if(0 != GetnormaldateFunc(instr, outstr))
		{
		/*	outstr[0] = '0';
			outstr[1] = '1';
			outstr[2] = '1';
			outstr[3] = '0';
			outstr[4] = '0';
			outstr[5] = '0'; */
            tmpDATESTR = DateTimeToStr(Now());
		}
		tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
						  IntToHex((int)outstr[1], 2)+"-"+
						  IntToHex((int)outstr[2], 2)+" "+
						  IntToHex((int)outstr[3], 2)+":"+
						  IntToHex((int)outstr[4], 2)+":"+
						  IntToHex((int)outstr[5], 2);
	}
	else
	{
	/*	outstr[0] = '0';
		outstr[1] = '1';
		outstr[2] = '1';
		outstr[3] = '0';
		outstr[4] = '0';
		outstr[5] = '0';
		tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
				 IntToHex((int)outstr[1], 2)+"-"+
				 IntToHex((int)outstr[2], 2)+" "+
				 IntToHex((int)outstr[3], 2)+":"+
				 IntToHex((int)outstr[4], 2)+":"+
				 IntToHex((int)outstr[5], 2);   */
        tmpDATESTR = DateTimeToStr(Now());
	}

	ConSumeTime = tmpDATESTR;

	if(0 == receivebuf[15])
		tmpXFLX = "X";
	else if(1 == receivebuf[15])
		tmpXFLX = "Y";
	else if(2 == receivebuf[15])
		tmpXFLX = "B";
	else if(3 == receivebuf[15])
		tmpXFLX = "I";
	else if(4 == receivebuf[15])
		tmpXFLX = "L";
	else if(5 == receivebuf[15])
		tmpXFLX = "M";
	else if(6 == receivebuf[15])
		tmpXFLX = "O";
	else if(7 == receivebuf[15])
		tmpXFLX = "P";
	else if(250 == receivebuf[15])
		tmpXFLX = "Z";
    else if(65 == receivebuf[15]) //breakfast
    	tmpXFLX = "S";
    else if(66 == receivebuf[15]) //lunch
    	tmpXFLX = "D";
    else if(67 == receivebuf[15]) //supper
    	tmpXFLX = "F";
    else if(68 == receivebuf[15]) //night
    	tmpXFLX = "G";
    else if(249 == receivebuf[15])
    	tmpXFLX = "W";
	else
    	tmpXFLX = "E";
//end提取卡信息-----------------------------------------

//Begin-UpdateDatabase----------------------------------
	if("W" == tmpXFLX)
    {
        //water in base
        int jqh;
        int waterkh;
        double xf1;
        double xf2;
        xf1 = ((double)receivebuf[0]+(double)receivebuf[1]*256+
                (double)receivebuf[2]*256*256+(double)receivebuf[3]*256*256*256)/100;
        xf2 = ((double)(receivebuf[4]^0xff)+(double)(receivebuf[5]^0xff)*256+
                (double)(receivebuf[6]^0xff)*256*256+(double)(receivebuf[7]^0xff)*256*256*256)/100;
        if(xf1 == xf2)
        {
            jqh = (int)receivebuf[8]*256+(int)receivebuf[9];
            waterkh = (int)receivebuf[10]*256*256*256+(int)receivebuf[11]*256*256+(int)receivebuf[12]*256+(int)receivebuf[13];
        	UpdateDataBaseQuery->Close();
            String tjsqlstr = "insert into WTJ values(:JH,:CJKH,:XFZE,:SCSJ)";
            UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(tjsqlstr);
            UpdateDataBaseQuery->Parameters->ParamByName("JH")->Value = jqh;
            UpdateDataBaseQuery->Parameters->ParamByName("CJKH")->Value = waterkh;
            UpdateDataBaseQuery->Parameters->ParamByName("XFZE")->Value = xf1;
            UpdateDataBaseQuery->Parameters->ParamByName("SCSJ")->Value = DateTimeToStr(Now());
            UpdateDataBaseQuery->ExecSQL();
        }
        //end water in base
    }
	else
    {
        UpdateDataBaseQuery->Close();
        tmpSQLSTR = "select * from CARD where KH='";
        tmpSQLSTR += tmpKH;
        tmpSQLSTR += "'";
        UpdateDataBaseQuery->SQL->Clear();
        UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
        UpdateDataBaseQuery->Open();
        if(!UpdateDataBaseQuery->IsEmpty())
        {
        	if("E"!=tmpXFLX)
        	{
                SerialNum = UpdateDataBaseQuery->FieldByName("BH")->AsAnsiString.Trim();
                username = UpdateDataBaseQuery->FieldByName("XM")->AsAnsiString.Trim();
                if(UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger < tmpXFCS)
                {
                    UpdateDataBaseQuery->Edit();
                    UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger = tmpXFCS;
                    UpdateDataBaseQuery->FieldByName("SF_YE")->AsFloat = tmpYE;
                    UpdateDataBaseQuery->FieldByName("SFYEDT")->AsString = tmpDATESTR;
                    UpdateDataBaseQuery->Post();
                }
            }
        }
//        else
//            errortag = true;
        UpdateDataBaseQuery->Close();

        tmpSQLSTR = "select * from CARD_F where KH = '";
        tmpSQLSTR += tmpKH;
        tmpSQLSTR += "'";
        UpdateDataBaseQuery->SQL->Clear();
        UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
        UpdateDataBaseQuery->Open();
        if(!UpdateDataBaseQuery->IsEmpty())
        {
        	if("E"!=tmpXFLX)
        	{
                if(UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger < tmpXFCS)
                {
                    UpdateDataBaseQuery->Edit();
                    UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger = tmpXFCS;
                    UpdateDataBaseQuery->FieldByName("SF_YE")->AsFloat = tmpYE;
                    UpdateDataBaseQuery->FieldByName("SFYEDT")->AsString = tmpDATESTR;
                    UpdateDataBaseQuery->Post();
                }
            }
        }
        else
            errortag = true;
        UpdateDataBaseQuery->Close();

    //	Validusername->Text = username;
    //	Validcardno->Text = tmpKH;
    //	Validplace->Text = Place;
    //	Validmoney->Text = tmpXFJE;
        USERNAME = username;
        CARDNO = tmpKH;
        MONEY = tmpXFJE;
        YUE = tmpYE;
        DSYCS = tmpXFCS;

        String UpdateTime;
        if(StrToDateTime(tmpDATESTR)>Now())
        {
            tmpDATESTR = DateTimeToStr(Now());
            UpdateTime = tmpDATESTR;
        }
        else
        {
            TDateTime tmpdt = StrToDateTime(tmpDATESTR);
            tmpdt = IncYear(tmpdt, 1);
            if(tmpdt<Now())
            {
                tmpDATESTR = DateTimeToStr(Now());
            }
            UpdateTime = DateTimeToStr(Now());
        }

    //	SYSTEMTIME tmpsystime;
    //	GetLocalTime(&tmpsystime);
    //	UpdateTime = DateTimeToStr(SystemTimeToDateTime(tmpsystime));


        if(!errortag)
        {
            tmpSQLSTR = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
            UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
            UpdateDataBaseQuery->Parameters->ParamByName("BH")->Value = SerialNum;
            UpdateDataBaseQuery->Parameters->ParamByName("KH")->Value = tmpKH;
            UpdateDataBaseQuery->Parameters->ParamByName("SF_YE")->Value = tmpYE;
            UpdateDataBaseQuery->Parameters->ParamByName("SFJE")->Value = tmpXFJE;
            UpdateDataBaseQuery->Parameters->ParamByName("SYCS")->Value = tmpXFCS;
            UpdateDataBaseQuery->Parameters->ParamByName("SFRQ")->Value = tmpDATESTR;
            UpdateDataBaseQuery->Parameters->ParamByName("JYNO")->Value = PosNumber;
            UpdateDataBaseQuery->Parameters->ParamByName("GZZID")->Value = 0;
            UpdateDataBaseQuery->Parameters->ParamByName("SFLX")->Value = tmpXFLX;
            UpdateDataBaseQuery->Parameters->ParamByName("CZY")->Value = OperatorName;

            UpdateDataBaseQuery->Parameters->ParamByName("SCRQ")->Value = UpdateTime;

            UpdateDataBaseQuery->ExecSQL();
            UpdateDataBaseQuery->Close();

    /*		tmpSQLSTR = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
            UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
            UpdateDataBaseQuery->Parameters->ParamByName("BH")->Value = SerialNum;
            UpdateDataBaseQuery->Parameters->ParamByName("KH")->Value = tmpKH;
            UpdateDataBaseQuery->Parameters->ParamByName("SF_YE")->Value = tmpYE;
            UpdateDataBaseQuery->Parameters->ParamByName("SFJE")->Value = tmpXFJE;
            UpdateDataBaseQuery->Parameters->ParamByName("SYCS")->Value = tmpXFCS;
            UpdateDataBaseQuery->Parameters->ParamByName("SFRQ")->Value = tmpDATESTR;
            UpdateDataBaseQuery->Parameters->ParamByName("JYNO")->Value = PosNumber;
            UpdateDataBaseQuery->Parameters->ParamByName("GZZID")->Value = 0;
            UpdateDataBaseQuery->Parameters->ParamByName("SFLX")->Value = tmpXFLX;
            UpdateDataBaseQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
            UpdateDataBaseQuery->Parameters->ParamByName("SCRQ")->Value = UpdateTime;
            UpdateDataBaseQuery->ExecSQL();
            UpdateDataBaseQuery->Close();   */

            if("I" == tmpXFLX)
            {
                tmpSQLSTR = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
                tmpSQLSTR += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
                UpdateDataBaseQuery->SQL->Clear();
                UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
                UpdateDataBaseQuery->Parameters->ParamByName("kh")->Value = tmpKH;
                UpdateDataBaseQuery->Parameters->ParamByName("bh")->Value = SerialNum;
                UpdateDataBaseQuery->Parameters->ParamByName("sf_ye")->Value = tmpYE;
                UpdateDataBaseQuery->Parameters->ParamByName("sf_fl")->Value = 1;
                UpdateDataBaseQuery->Parameters->ParamByName("ckxj")->Value = tmpXFJE;
                UpdateDataBaseQuery->Parameters->ParamByName("glf")->Value = 0;
                UpdateDataBaseQuery->Parameters->ParamByName("ckje")->Value = tmpXFJE;
                UpdateDataBaseQuery->Parameters->ParamByName("lqbt")->Value = 0;
                UpdateDataBaseQuery->Parameters->ParamByName("xkje")->Value = tmpXFJE;
                UpdateDataBaseQuery->Parameters->ParamByName("sycs")->Value = tmpXFCS;
                UpdateDataBaseQuery->Parameters->ParamByName("sfrq")->Value = tmpDATESTR;
                UpdateDataBaseQuery->Parameters->ParamByName("jyno")->Value = 1000;
                UpdateDataBaseQuery->Parameters->ParamByName("gzzid")->Value = 1;
                UpdateDataBaseQuery->Parameters->ParamByName("sflx")->Value = "I";
                UpdateDataBaseQuery->Parameters->ParamByName("CZY")->Value = OperatorName;
                UpdateDataBaseQuery->ExecSQL();
                UpdateDataBaseQuery->Close();
            }
        }
        else
        {
            tmpSQLSTR = "insert into MX_ERROR values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
            UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
            UpdateDataBaseQuery->Parameters->ParamByName("BH")->Value = SerialNum;
            UpdateDataBaseQuery->Parameters->ParamByName("KH")->Value = tmpKH;
            UpdateDataBaseQuery->Parameters->ParamByName("SF_YE")->Value = tmpYE;
            UpdateDataBaseQuery->Parameters->ParamByName("SFJE")->Value = tmpXFJE;
            UpdateDataBaseQuery->Parameters->ParamByName("SYCS")->Value = tmpXFCS;
            UpdateDataBaseQuery->Parameters->ParamByName("SFRQ")->Value = tmpDATESTR;
            UpdateDataBaseQuery->Parameters->ParamByName("JYNO")->Value = PosNumber;
            UpdateDataBaseQuery->Parameters->ParamByName("GZZID")->Value = 0;
            UpdateDataBaseQuery->Parameters->ParamByName("SFLX")->Value = tmpXFLX;
            UpdateDataBaseQuery->Parameters->ParamByName("CZY")->Value = OperatorName;

            UpdateDataBaseQuery->Parameters->ParamByName("SCRQ")->Value = UpdateTime;

            UpdateDataBaseQuery->ExecSQL();
            UpdateDataBaseQuery->Close();
        }
    }
	//End-UpdateDatabase------------------------------------
}


//---------------------------------------------------------------------------
/*
				if(*ONLinePosNum>0)
				{
					if(getusbcomportdll)
					{
						strcpy(temp, getusbcomportdll());
						String tt = temp;
						int tempcom = StrToInt(tt.SubString(4, tt.Length()-3).c_str());
						if(tempcom>255)
						{
							MessageBox(SDIAppForm->Handle, "POS机连接的COM口不能大于255！", "Collect Error!", MB_OK);
						}
						else
						{
							IntToChar(tempcom, &como);
							ValidPauseBTN->Enabled = true;
							while (true)
							{
								if(!Terminated)
								{
									PosNumber = -1;
									OrignalDataStr = "";
									DataStatusStr = "";
									for(WORD PosNO = 1; PosNO<=300; PosNO++)
									{
										if(!Terminated)
										{
											if((0x00 == SynchroTagbuf[PosNO-1])&&(0x01 == PosInUseTag[PosNO-1]))
											{
									 //			MessageBox(NULL, "==", "==", MB_OK);
												ReceiveStatus = SerReceiveFunc(como, PosNO, ReceiveCMD, receivebuf, receivelen, 1, dir, dirlen);
												if(0 == ReceiveStatus)
												{
													SynchroStatus = SendAckFunc(como, SynchroCMD);
													if(0 == SynchroStatus)
													{
														for (int i = 0; i < receivelen; i++)
														{
															OrignalDataStr = OrignalDataStr + (IntToHex((byte)receivebuf[i], 2));
														}

														if(comparestr != OrignalDataStr.SubString(0, 20))
														{
															PosNumber = PosNO;
															DataStatusStr = "正常";
															Synchronize(SaveDataToFileFunc);
															Synchronize(UpdateDataBaseFunc);
															Synchronize(DisplayDataFunc);
														}
													}
													else
													{
														//该POS无法正常采集数据，对listview图标进行黑白化
														ValidPosTreeList->Items[0]->Items[PosNO-1]->ImageIndex = 2;
														ValidPosTreeList->Items[0]->Items[PosNO-1]->Texts[0] = "故障POS机";
														SynchroTagbuf[PosNO-1] = 0x01;
													}
												}
												else
												{
													//该POS无法正常采集数据，对listview图标进行黑白化
													ValidPosTreeList->Items[0]->Items[PosNO-1]->ImageIndex = 2;
													ValidPosTreeList->Items[0]->Items[PosNO-1]->Texts[0] = "故障POS机";
													SynchroTagbuf[PosNO-1] = 0x01;
												}
											}
										}
										else
											return;
									}
								}
								else
									return;
							}
						}
					}
				}
*/
