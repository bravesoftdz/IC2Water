//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CheckedBatchCollectDataThread.h"
#include "SDIMAIN.h"
#pragma package(smart_init)
#include "CheckedBCFRM.h"
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCheckedBatchCollectDataThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCheckedBatchCollectDataThread::TCheckedBatchCollectDataThread(bool CreateSuspended,
																		bool* collecttag,
																		TcxCheckListBox* OnLinePosCKB,
																		TcxListView* DataListView,
																		int* PosNum,
                                                                        TcxProgressBar* CProgressBar,
																		TADOQuery* updateQuery,
																		TPanel* InfoPanel,
																		TcxButton* StoreBtn,
																		TcxButton* EBTN,
																		TcxButton* SBTN) : TThread(CreateSuspended)
{
	validcollecttag = collecttag;
	ValidDisplayListView = DataListView;
	ValidCKB = OnLinePosCKB;
	ONLinePosNum = PosNum;
	UpdateDataBaseQuery = updateQuery;
	ValidInfoPanel = InfoPanel;
	ValidStoreBtn = StoreBtn;
	ValidEBTN = EBTN;
	ValidSBTN = SBTN;
    ValidCProgressBar = CProgressBar;
}
//---------------------------------------------------------------------------
void __fastcall TCheckedBatchCollectDataThread::Execute()
{
	bool CheckedTag = false;
	ValidSBTN->Enabled = false;
	if(SerReceiveFunc&&SendAckFunc)
	{
/*		String filepathstr = GlobalPath+"\\BCStroeBatchDataFile.dat";
		hStoreToFile = CreateFile(filepathstr.t_str(),
								  GENERIC_READ | GENERIC_WRITE,
								  0,
								  NULL,
								  CREATE_ALWAYS,
								  FILE_ATTRIBUTE_NORMAL,
								  NULL);
		if(hStoreToFile)
		{     */
			*validcollecttag = true;
			ValidEBTN->Enabled = true;
			ModeOFCollect = 3;
			String CollectTime = "*CBCollectTime* ";
			CollectTime += Date();
			CollectTime += " ";
			CollectTime += Time();

			CDBatchDataSaveToFileStream<<endl<<CollectTime.t_str()<<endl;
		//	TcxCheckListBoxItem* tmpitem = ValidCKB->Items

			ValidCProgressBar->Position = 0;

			int poscount = ValidCKB->Items->Count;
			for(int i = 0; i < poscount; i++)
			{
				ValidCProgressBar->Position = 0;
				TcxCheckListBoxItem* tmpitem = ValidCKB->Items->Items[i];
				poscollectedrecordcount = 0;
				currentcount = i;
				if(!Terminated)
				{
					if(tmpitem->Checked)
					{
						CheckedTag = true;
						string ComInfoStr = tmpitem->Text.t_str();
						int tmpend = ComInfoStr.find('|', 0);
						string validInfostr = ComInfoStr.substr(0, tmpend);
						int endend = validInfostr.length();
						tmpend = validInfostr.find('-', 0);
						string JHstr = validInfostr.substr(0, tmpend);
						string COMstr = validInfostr.substr(tmpend+1, endend);

						WORD ReceiveStatus = -1;
						WORD SynchroStatus = -1;
						char temp[10] = "";
						unsigned char como = (unsigned char)(StrToInt(COMstr.c_str()));
						PosNumber = StrToInt(JHstr.c_str());
						WORD PosNO = (WORD)(StrToInt(JHstr.c_str()));
						unsigned char ReceiveCMD = 0x23;
						unsigned char SynchroCMD = 0x54;
						ZeroMemory(receivebuf, 2048);
						int receivelen = 2048;
						unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
						int dirlen = strlen(dir);

						UpdateDataBaseQuery->Close();
						UpdateDataBaseQuery->SQL->Clear();
						String tmpsql = "select * from SFJPARAM where JH=";
						tmpsql += StrToInt(JHstr.c_str());
				  //		tmpsql += "'";
						UpdateDataBaseQuery->SQL->Add(tmpsql);
						UpdateDataBaseQuery->Open();
						Place = UpdateDataBaseQuery->FieldByName("STNAME")->AsAnsiString.Trim();
						UpdateDataBaseQuery->Close();

						int recordinpos = 0;
						WORD posstatus = -1;
						WORD poscomo = como;
						unsigned char statusCMD = 0x43;
						unsigned char statusbuf[16];
						ZeroMemory(statusbuf,16);
						int statuslen = 16;
						posstatus = SerReceiveFunc(poscomo, PosNO, statusCMD, statusbuf, statuslen, 1, dir, dirlen);
						if(0 == posstatus)
						{
							int lowptr = 256*(int)statusbuf[0] + (int)statusbuf[1];
							int highptr = 256*(int)statusbuf[2] + (int)statusbuf[3];
							if(highptr >= lowptr)
							{
								recordinpos = highptr - lowptr;
							}
							else
							{
								recordinpos = highptr + 6576 - lowptr;
							}
							posallrecordcount = recordinpos;
						}
						else
						{
							tmpitem->Text = "POS机异常";
						//	currentcount++;
							continue;
						}
						tmpcaptionstr = "正在采集";
						tmpcaptionstr += StrToInt(JHstr.c_str());
						tmpcaptionstr += "号机，位于：";
						tmpcaptionstr += Place;
						tmpcaptionstr += "，该POS机含有消费记录";
						tmpcaptionstr += recordinpos;
						tmpcaptionstr += "条。";
						ValidInfoPanel->Caption = tmpcaptionstr;
						bool continued = true;
						DisplayCollectingFunc();
						while(continued)
						{
							if(!Terminated)
							{
								ReceiveStatus = SerReceiveFunc(como, PosNO, ReceiveCMD, receivebuf, receivelen, 1, dir, dirlen);
								if(0 == ReceiveStatus)
								{
									SynchroStatus = SendAckFunc(como, SynchroCMD);
									if(0 == SynchroStatus)
									{
										if((0x00 == receivebuf[10])&&(0x00 == receivebuf[11]))
											continued = false;
										if(0x00 != receivebuf[8])
										{
											Synchronize(AnalyzeDataFunc);
										}
									}
								}
								else
								{
									continued = false;
								}
								Sleep(50);
							}
							else
							{
								continued = false;
								*validcollecttag = false;
								ModeOFCollect = 0;
								CloseHandle(hStoreToFile);
								ValidStoreBtn->Enabled = true;
								ValidEBTN->Enabled = true;
					 //			if(CDBatchDataSaveToFileStream)
					  //				CDBatchDataSaveToFileStream.close();
								CheckBatchCollectFRM->Close();
								ValidSBTN->Enabled = true;
								return;
							}
						}
						DisplayEndCollectFunc();
					}
				}
				else
				{
					*validcollecttag = false;
					ModeOFCollect = 0;
					CloseHandle(hStoreToFile);
					ValidStoreBtn->Enabled = true;
					ValidEBTN->Enabled = true;
			 //		if(CDBatchDataSaveToFileStream)
			 //			CDBatchDataSaveToFileStream.close();
					CheckBatchCollectFRM->Close();
					ValidSBTN->Enabled = true;
					return;
				}

			}

			*validcollecttag = false;
			//CloseHandle(hStoreToFile);
			//ValidStoreBtn->Enabled = true;
			ValidEBTN->Enabled = true;
			if(!CheckedTag)
			{
				MessageBox(SDIAppForm->Handle, "没有选择要采集数据的POS机!", "Error", MB_OK|MB_ICONERROR);
				ValidInfoPanel->Caption = "没有选择要采集数据的POS机!";
				CheckBatchCollectFRM->BatchCollectBTN->Enabled = true;
			}
			else
			{
				ValidCProgressBar->Position = 100;
				ValidInfoPanel->Caption = "选定数据采集完毕!";
				MessageBox(SDIAppForm->Handle, "选定数据采集完毕!", "采集完毕", MB_OK);
		  /*		if(CDBatchDataSaveToFileStream)
					CDBatchDataSaveToFileStream.close();
				if(mrOk == MessageBox(SDIAppForm->Handle, "选定数据采集完毕，是否进行数据入库!", "采集完毕", MB_OKCANCEL|MB_ICONQUESTION))
					ValidStoreBtn->Click();
                else
					ValidCProgressBar->Properties->Marquee = false;  */
			}
/*		}
		else
		{
			MessageBox(SDIAppForm->Handle, "无法创建数据存储文件，请联系技术人员!", "Error", MB_OK|MB_ICONERROR);
            if(CDBatchDataSaveToFileStream)
				CDBatchDataSaveToFileStream.close();
			*validcollecttag = false;
			ModeOFCollect = 0;
			return;
		}   */
	}
	else
	{
		*validcollecttag = false;
		ModeOFCollect = 0;
//		if(CDBatchDataSaveToFileStream)
//			CDBatchDataSaveToFileStream.close();
		MessageBox(SDIAppForm->Handle, "Error in Load SerReceiveFunc Or SendAckFunc!", "Error", MB_OK|MB_ICONERROR);
	}
	ValidSBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCheckedBatchCollectDataThread::AnalyzeDataFunc()
{
	int recordNUM = (int)receivebuf[7]*256+(int)receivebuf[8];
	if((recordNUM<128)&&(recordNUM>0)&&(0x20 == receivebuf[0])&&(0x03 == receivebuf[1])
	  &&(DWPassword[0] == receivebuf[2])&&(DWPassword[1] == receivebuf[3])
	  &&(PosNumber == ((int)receivebuf[12]*256+(int)receivebuf[5]))
	  &&(0x23 == receivebuf[4]))
	{
	//分析数据
		String insqlstr = "";
        String Watersqlstr = "";
        String AddinPosinsqlstr = "";
		int PosNumber = (int)receivebuf[12]*256+(int)receivebuf[5];

		int RecordIndexPos;
		int tmpKH;
		int tmpXFCS;
		double tmpYE;
		double tmpXFJE;
		String tmpDATESTR;
		String tmpXFLX;
		String tmpSQLSTR;

		unsigned char instr[4];
		unsigned char outstr[6];
		ZeroMemory(instr, 4);
		ZeroMemory(outstr, 6);

		String updatetimestr = DateTimeToStr(Now());

		for (int i = 0; i < (int)receivebuf[8]; i++)
		{
			RecordIndexPos = 14 + i*16;
			tmpKH = (int)receivebuf[RecordIndexPos]*256*256 + (int)receivebuf[RecordIndexPos+1]*256 + (int)receivebuf[RecordIndexPos+2];
			tmpXFCS = (int)receivebuf[RecordIndexPos+3]*256+(int)receivebuf[RecordIndexPos+4];
			tmpYE = ((double)receivebuf[RecordIndexPos+5]*256*256+(double)receivebuf[RecordIndexPos+6]*256+(double)receivebuf[RecordIndexPos+7])/100;
			tmpXFJE = ((double)receivebuf[RecordIndexPos+8]*256*256+(double)receivebuf[RecordIndexPos+9]*256+(double)receivebuf[RecordIndexPos+10])/100;

			instr[0] = receivebuf[RecordIndexPos+11];
			instr[1] = receivebuf[RecordIndexPos+12];
			instr[2] = receivebuf[RecordIndexPos+13];
			instr[3] = receivebuf[RecordIndexPos+14];
			if(GetnormaldateFunc)
			{
			//这里进行时间判断  ？
				if(0 != GetnormaldateFunc(instr, outstr))
				{
				/*	outstr[0] = '0';
					outstr[1] = '1';
					outstr[2] = '1';
					outstr[3] = '0';
					outstr[4] = '0';
					outstr[5] = '0';*/
					tmpDATESTR = DateTimeToStr(Now());
				}
				else
				{
					tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
									  IntToHex((int)outstr[1], 2)+"-"+
									  IntToHex((int)outstr[2], 2)+" "+
									  IntToHex((int)outstr[3], 2)+":"+
									  IntToHex((int)outstr[4], 2)+":"+
									  IntToHex((int)outstr[5], 2);
				}
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
							 IntToHex((int)outstr[5], 2);  */
				tmpDATESTR = DateTimeToStr(Now());
			}

			String UpdateTime = updatetimestr;

			try
			{
				StrToDateTime(tmpDATESTR);
			}
			catch(...)
			{
				tmpDATESTR = DateTimeToStr(Now());
			}

			if(StrToDateTime(tmpDATESTR)>Now())
			{
				tmpDATESTR = DateTimeToStr(Now());
			}
			else
			{
				TDateTime tmpdt = StrToDateTime(tmpDATESTR);
				tmpdt = IncYear(tmpdt, 1);
				if(tmpdt<Now())
				{
					tmpDATESTR = DateTimeToStr(Now());
				}
			}

			if(0 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "X";
			else if(1 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "Y";
			else if(2 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "B";
			else if(3 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "I";
			else if(4 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "L";
			else if(5 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "M";
			else if(6 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "O";
			else if(7 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "P";
			else if(250 == receivebuf[RecordIndexPos+15])
				tmpXFLX = "Z";
			else if(65 == receivebuf[RecordIndexPos+15]) //breakfast
                tmpXFLX = "S";
			else if(66 == receivebuf[RecordIndexPos+15]) //lunch
                tmpXFLX = "D";
			else if(67 == receivebuf[RecordIndexPos+15]) //supper
				tmpXFLX = "F";
			else if(68 == receivebuf[RecordIndexPos+15]) //night
                tmpXFLX = "G";
            else if(249 == receivebuf[RecordIndexPos+15])
            	tmpXFLX = "W";
			else tmpXFLX = "E";

            if("W" == tmpXFLX)
            {
                //analyze water data;
                int jqh;
                int waterkh;
                double xf1;
                double xf2;
                xf1 = ((double)receivebuf[RecordIndexPos+0]+(double)receivebuf[RecordIndexPos+1]*256+
                        (double)receivebuf[RecordIndexPos+2]*256*256+(double)receivebuf[RecordIndexPos+3]*256*256*256)/100;
                xf2 = ((double)(receivebuf[RecordIndexPos+4]^0xff)+(double)(receivebuf[RecordIndexPos+5]^0xff)*256+
                        (double)(receivebuf[RecordIndexPos+6]^0xff)*256*256+(double)(receivebuf[RecordIndexPos+7]^0xff)*256*256*256)/100;
                if(xf1 == xf2)
                {
                    jqh = (int)receivebuf[RecordIndexPos+8]*256+(int)receivebuf[RecordIndexPos+9];
                    waterkh = (int)receivebuf[RecordIndexPos+10]*256*256*256+
                    		(int)receivebuf[RecordIndexPos+11]*256*256+(int)receivebuf[12]*256+
                            (int)receivebuf[RecordIndexPos+13];
                //    String tjsqlstr = "insert into WTJ values(:JH,:CJKH,:XFZE,:SCSJ)";
                    String watertmpsqlstr = "insert into WTJ values(";
                    watertmpsqlstr += jqh;
                    watertmpsqlstr += ",";
                    watertmpsqlstr += waterkh;
                    watertmpsqlstr += ",";
                    watertmpsqlstr += xf1;
                    watertmpsqlstr += ",'";
                    watertmpsqlstr += DateTimeToStr(Now());
                    watertmpsqlstr += "')";
                    Watersqlstr += watertmpsqlstr;
                }
                //end analyze;
            }
            else
            {
                String F_bhstr;
                bool errortag = false;
                UpdateDataBaseQuery->Close();
                tmpSQLSTR = "select * from CARD_F where KH = '";
                tmpSQLSTR += tmpKH;
                tmpSQLSTR += "'";
                UpdateDataBaseQuery->SQL->Clear();
                UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
                UpdateDataBaseQuery->Open();
                if(!UpdateDataBaseQuery->IsEmpty())
                {
                 //	SerialNum = UpdateDataBaseQuery->FieldByName("BH")->AsAnsiString.Trim();
                    String tmpsqlstr = "insert into MX Values('";
                    tmpsqlstr += UpdateDataBaseQuery->FieldByName("BH")->AsAnsiString.Trim();
                    tmpsqlstr += "',";
                    tmpsqlstr += tmpKH;
                    tmpsqlstr += ",";
                    tmpsqlstr += tmpYE;
                    tmpsqlstr += ",";
                    tmpsqlstr += tmpXFJE;
                    tmpsqlstr += ",";
                    tmpsqlstr += tmpXFCS;
                    tmpsqlstr += ",'";
                    tmpsqlstr += tmpDATESTR;
                    tmpsqlstr += "',";
                    tmpsqlstr += PosNumber;
                    tmpsqlstr += ",0,'";
                    tmpsqlstr += tmpXFLX;
                    tmpsqlstr += "','";
                    tmpsqlstr += OperatorName;
                    tmpsqlstr += "','";
                    tmpsqlstr += updatetimestr;
                    tmpsqlstr += "')";
                    insqlstr += tmpsqlstr;

                    if("I" == tmpXFLX)
                    {
                        String tempaddinpossqlstr = "insert into CK Values(";
                        tempaddinpossqlstr += tmpKH;
                        tempaddinpossqlstr += ",'";
                        tempaddinpossqlstr += UpdateDataBaseQuery->FieldByName("BH")->AsAnsiString.Trim();
                        tempaddinpossqlstr += "',";
                        tempaddinpossqlstr += tmpYE;
                        tempaddinpossqlstr += ",1,";
                        tempaddinpossqlstr += tmpXFJE;//PosNumber;
                        tempaddinpossqlstr += ",0,";
                        tempaddinpossqlstr += tmpXFJE;//tmpXFLX;
                        tempaddinpossqlstr += ",0,";
                        tempaddinpossqlstr += tmpXFJE;
                        tempaddinpossqlstr += ",";
                        tempaddinpossqlstr += tmpXFCS;
                        tempaddinpossqlstr += ",'";
                        tempaddinpossqlstr += tmpDATESTR;
                        tempaddinpossqlstr += "',";
                        tempaddinpossqlstr += PosNumber;
                        tempaddinpossqlstr += ",1,'I','";
                        tempaddinpossqlstr += OperatorName;
                        tempaddinpossqlstr += "')";
                        AddinPosinsqlstr += tempaddinpossqlstr;
                    }

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
                    F_bhstr = UpdateDataBaseQuery->FieldByName("BH")->AsString;
                }
                else
                    errortag = true;
                UpdateDataBaseQuery->Close();

                if("E"!=tmpXFLX)
                {
					tmpSQLSTR = "select * from CARD_F where KH = '";
					tmpSQLSTR += tmpKH;
					tmpSQLSTR += "' and BH='";
					tmpSQLSTR += F_bhstr;
					tmpSQLSTR += "'";
					UpdateDataBaseQuery->SQL->Clear();
					UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
					UpdateDataBaseQuery->Open();
					if(!UpdateDataBaseQuery->IsEmpty())
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
					else
						errortag = true;
					UpdateDataBaseQuery->Close();

                    tmpSQLSTR = "select * from CARD where KH = '";
					tmpSQLSTR += tmpKH;
					tmpSQLSTR += "' and BH='";
					tmpSQLSTR += F_bhstr;
					tmpSQLSTR += "'";
					UpdateDataBaseQuery->SQL->Clear();
					UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
					UpdateDataBaseQuery->Open();
					if(!UpdateDataBaseQuery->IsEmpty())
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
					else
						errortag = true;
					UpdateDataBaseQuery->Close();
				}

                //进度显示
                poscollectedrecordcount ++;//+= recordNUM;
                ValidCProgressBar->Position = 100*poscollectedrecordcount/posallrecordcount;
            }
		}
		UpdateDataBaseQuery->Close();

			//数据入库
        Sleep(100);
        if(insqlstr.Length()>0)
        {
        	UpdateDataBaseQuery->Close();
            UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(insqlstr);
            UpdateDataBaseQuery->ExecSQL();
            UpdateDataBaseQuery->Close();
        }
        Sleep(100);
        if(AddinPosinsqlstr.Length()>0)
        {
        	UpdateDataBaseQuery->Close();
        	UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(AddinPosinsqlstr);
            UpdateDataBaseQuery->ExecSQL();
            UpdateDataBaseQuery->Close();
        }

        Sleep(100);
        if(Watersqlstr.Length()>0)
        {
			UpdateDataBaseQuery->Close();
            UpdateDataBaseQuery->SQL->Clear();
            UpdateDataBaseQuery->SQL->Add(Watersqlstr);
            UpdateDataBaseQuery->ExecSQL();
            UpdateDataBaseQuery->Close();
        }

		String prooutstr = tmpcaptionstr;
		prooutstr += "已采集入库";
		prooutstr += poscollectedrecordcount;
		prooutstr += "条";
		ValidInfoPanel->Caption = prooutstr;
/*		DWORD writelen;
		WriteFile(hStoreToFile, receivebuf, 2048, &writelen, NULL);       */
		for(int i = 0; i < 2048; i++)
			CDBatchDataSaveToFileStream<<receivebuf[i];
	//	CDBatchDataSaveToFileStream<<endl;
	//	WriteFile(CDBatchDataSaveToFileStream, receivebuf, 2048, &writelen, NULL);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCheckedBatchCollectDataThread::DisplayCollectingFunc()
{
	TListItem* tmp = ValidDisplayListView->Items->Add();
	String posstr = PosNumber;
	posstr += "Pos机";
	tmp->Caption = posstr;
	tmp->SubItems->Add(Place);
	tmp->SubItems->Add("正在进行批量数据采集......");
//	tmp->SubItems->Add(DataStatusStr);

	tmp->Selected = true;
	ValidDisplayListView->SetFocus();
	ValidDisplayListView->Selected->MakeVisible(true);
	return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckedBatchCollectDataThread::DisplayEndCollectFunc()
{
	int count = ValidDisplayListView->Items->Count;
	TListItem* tmp = ValidDisplayListView->Items->Item[count-1];
	tmp->SubItems->Strings[1]= "已完成批量数据采集!";

	return;
}
//---------------------------------------------------------------------------
