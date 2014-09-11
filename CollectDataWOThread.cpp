//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CollectDataWOThread.h"
#include "SDIMAIN.h"
#include "GlobalParameter.h"
#include "RealCollectWithoutInBaseForm.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCollectDataWOThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCollectDataWOThread::TCollectDataWOThread(bool CreateSuspended,
                                                      bool* collecttag,
                                                      bool GSTag,
                                                      TcxListView* DataListView,
                                                      TTreeView* OnLinePosTreeList,
                                                      int* PosNum,
                                                      TcxProgressBar* CProgressBar,
                                                      TADOQuery* updateQuery,
                                                      TADOTable* LostInfoT)	: TThread(CreateSuspended)
{
	validcollecttag = collecttag;
	ValidGSTag = GSTag;
	DisplayListView = DataListView;
	ValidPosTreeList = OnLinePosTreeList;
	ONLinePosNum = PosNum;
	UpdateDataBaseQuery = updateQuery;
	ValidLostInfoT = LostInfoT;
	ValidCProgressBar = CProgressBar;
}
//---------------------------------------------------------------------------
void __fastcall TCollectDataWOThread::Execute()
{
	//---- Place thread code here ----
	if(SerReceiveFunc&&SendAckFunc)
	{
    	String filepathstr = GlobalPath+"\\StoreRealCWOIBData.dat";
		hStoreToFile = CreateFile(filepathstr.t_str(),
								  GENERIC_READ | GENERIC_WRITE,
								  0,
								  NULL,
								  CREATE_ALWAYS,
								  FILE_ATTRIBUTE_NORMAL,
								  NULL);
        if(!hStoreToFile)
        {
            MessageBox(SDIAppForm->Handle, "无法创建数据存储文件，请联系技术人员!", "Error", MB_OK|MB_ICONERROR);
			*validcollecttag = false;
			ModeOFCollect = 0;
			return;
        }

		ValidLostInfoT->Active = false;
		ValidLostInfoT->Active = true;
		ValidLostInfoT->First();

		*validcollecttag = true;
		ModeOFCollect = 5;
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

			 /*		UpdateDataBaseQuery->Close();
					UpdateDataBaseQuery->SQL->Clear();
					String tmpsql = "select * from SFJPARAM where JH='";
					tmpsql += tmppospara->posnum;
					tmpsql += "'";
					UpdateDataBaseQuery->SQL->Add(tmpsql);
					UpdateDataBaseQuery->Open();
					Place = UpdateDataBaseQuery->FieldByName("STNAME")->AsAnsiString.Trim();
					UpdateDataBaseQuery->Close();    */

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
								//	Synchronize(UpdateDataBaseFunc);
									Synchronize(DisplayDataFunc);
								}
							}
							Sleep(50);
						}

						//挂失一条
						if(ValidGSTag)
						{
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

                        ValidCProgressBar->Properties->Marquee = false;

				  //		if(DataSaveToFileStream)
				  //			DataSaveToFileStream.close();
				  ///		RealTimeCollectFRM->Close();
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

void __fastcall TCollectDataWOThread::DisplayDataFunc()
{
	TListItem* tmp = DisplayListView->Items->Add();
	String posstr = PosNumber;
	posstr += "Pos机";
	tmp->Caption = posstr;
	tmp->SubItems->Add(CARDNO);
	tmp->SubItems->Add(YUE);
	tmp->SubItems->Add(MONEY);
	tmp->SubItems->Add(ConSumeTime);
	tmp->SubItems->Add(DSYCS);
//	tmp->SubItems->Add(OrignalDataStr);
//	tmp->SubItems->Add(DataStatusStr);

	tmp->Selected = true;
	DisplayListView->SetFocus();
	DisplayListView->Selected->MakeVisible(true);
}
//---------------------------------------------------------------------------

void __fastcall TCollectDataWOThread::SaveDataToFileFunc()
{
	DataSaveToFileStream<<OrignalDataStr.t_str()<<endl;
	DWORD writelen;
    unsigned char writebuf[18];
    ZeroMemory(writebuf, 18);
    memcpy(writebuf, receivebuf, 16);
    writebuf[16] = PosNumber/256;
    writebuf[17] = PosNumber%256;
    WriteFile(hStoreToFile, writebuf, 18, &writelen, NULL);
}
//---------------------------------------------------------------------------
