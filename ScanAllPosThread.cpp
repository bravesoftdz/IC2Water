//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ScanAllPosThread.h"
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
//      void __fastcall TScanAllPosThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TScanAllPosThread::TScanAllPosThread(bool CreateSuspended,
												string comstr,
												TcxProgressBar* progress,
												TcxListView* ListView,
												TcxButton* SingleBTN,
									 			TcxButton* AllBTN,
												TcxButton* PauseBTN,
												TcxButton* ScanBTN,
												TcxButton* ExitBTN,
												bool* tag,
												TADOQuery* ADOQ) : TThread(CreateSuspended)
{
	COMSTR = comstr;
	Validprogress = progress;
	ValidListView = ListView;
	ValidSingleBTN = SingleBTN;
	ValidAllBTN = AllBTN;
	ValidPBTN = PauseBTN;
	ValidSBTN = ScanBTN;
	ValidExitBTN = ExitBTN;
	Validtag = tag;
	ValidADOQ = ADOQ;

}
//---------------------------------------------------------------------------

void __fastcall TScanAllPosThread::Execute()
{
	*Validtag = true;
	WORD Status;
	unsigned char como = 0x00;
 //	WORD NO1 = 1;
	unsigned char cmd = 0x43;
	unsigned char receivebuf[16];
	ZeroMemory(receivebuf, 16);
	int receivelen = 16;
	unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
	int dirlen = strlen(dir);

	int endpos = COMSTR.find('&', 0);
	int beginpos = 0;
	Validprogress->Properties->Marquee = true;
	ValidListView->Clear();

	while(-1 != endpos)
	{
		string comstr = COMSTR.substr(beginpos, endpos-beginpos);
//		MessageBox(SDIAppForm->Handle, comstr.c_str(), "port", MB_OK);
//		MessageBox(SDIAppForm->Handle, comstr.substr(3, comstr.length()-3).c_str(), "port", MB_OK);
		int tempcom = StrToInt(comstr.substr(3, comstr.length()-3).c_str());

		if(tempcom>255)
		{
			MessageBox(SDIAppForm->Handle, "POS机连接的COM口不能大于255！", "Error", MB_OK);
		}
		else
		{
			IntToChar(tempcom, &como);
			ValidPBTN->Enabled = true;

			for(int PosNO = 1; PosNO <= 300; PosNO++)
			{
				if(!Terminated)
				{
					ValidADOQ->Close();
					ValidADOQ->SQL->Clear();
					String sqlstr = "select * from SFJPARAM where JH=";
					sqlstr += IntToStr(PosNO);
					sqlstr += " and SFJPORT=";
					sqlstr += IntToStr((int)como);
		 //			MessageBox(SDIAppForm->Handle, sqlstr.t_str(), "Error", MB_OK);
					ValidADOQ->SQL->Add(sqlstr);
					ValidADOQ->Open();
					int record = ValidADOQ->RecordCount;
					ValidADOQ->Close();

					Status = SerReceiveFunc(como, (WORD)PosNO, cmd, receivebuf, receivelen, 1, dir, dirlen);

					if(1 == record)
					{
						if(0 == Status)
						{
							String nodestr = PosNO;
							nodestr += "号POS机:COM";
							nodestr += como;
							TListItem* tmp = ValidListView->Items->Add();
							tmp->Caption = nodestr;
							tmp->ImageIndex = 0;
							POSPARA* tmppospara = new POSPARA();
							tmppospara->posnum = PosNO;
							tmppospara->comnum = (int)como;
							tmppospara->tag = 1;
							tmp->Data = (void*)tmppospara;
						}
						else
						{
							String nodestr = PosNO;
							nodestr += "号POS机:COM";
							nodestr += como;
							TListItem* tmp = ValidListView->Items->Add();
							tmp->Caption = nodestr;
							tmp->ImageIndex = 1;
							POSPARA* tmppospara = new POSPARA();
							tmppospara->posnum = PosNO;
							tmppospara->comnum = (int)como;
							tmppospara->tag = 2;
							tmp->Data = (void*)tmppospara;
                        }
					}
					else
					{
						if(0 == Status)
						{
							String nodestr = PosNO;
							nodestr += "号POS机:COM:为设置";
							nodestr += como;
							TListItem* tmp = ValidListView->Items->Add();
							tmp->Caption = nodestr;
							tmp->ImageIndex = 2;
							POSPARA* tmppospara = new POSPARA();
							tmppospara->posnum = PosNO;
							tmppospara->comnum = (int)como;
							tmppospara->tag = 3;
							tmp->Data = (void*)tmppospara;
                        }
					}
					Sleep(100);
				}
				else
				{
					Validprogress->Properties->Marquee = false;
					ValidPBTN->Enabled = false;
					ValidSBTN->Enabled = true;
					if(ValidListView->Items->Count > 0)
					{
						ValidSingleBTN->Enabled = true;
						ValidAllBTN->Enabled = true;
					}
					MessageBox(SDIAppForm->Handle, "扫描在线POS机结束!", "Scan End!", MB_OK);
					return;
				}
			}
		}
		beginpos = endpos+1;
		endpos = COMSTR.find('&', endpos+1);
	}
	Validprogress->Properties->Marquee = false;
	ValidPBTN->Enabled = false;
	ValidSBTN->Enabled = true;
	if(ValidListView->Items->Count > 0)
	{
		ValidSingleBTN->Enabled = true;
		ValidAllBTN->Enabled = true;
	}
	ValidExitBTN->Enabled = true;
	MessageBox(SDIAppForm->Handle, "扫描在线POS机结束!", "Scan End!", MB_OK);
	*Validtag = false;
}
//---------------------------------------------------------------------------
