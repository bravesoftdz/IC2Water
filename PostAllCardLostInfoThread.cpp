//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PostAllCardLostInfoThread.h"
#pragma package(smart_init)
#include "SDIMAIN.h"
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TPostAllCardLostInfoThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TPostAllCardLostInfoThread::TPostAllCardLostInfoThread(bool CreateSuspended,
																  TcxButton* AllBTN,
																  TcxButton* GSBTN,
																  TcxButton* EBTN,
																  TcxProgressBar* ProBar,
																  TcxListView* ListV,
																  TADOQuery* ADOQ) : TThread(CreateSuspended)
{
	ValidAllBTN = AllBTN;
	ValidGSBTN = GSBTN;
	ValidExitBTN = EBTN;
	ValidPorBar = ProBar;
	ValidListV = ListV;
	ValidADOQ = ADOQ;
}
//---------------------------------------------------------------------------
void __fastcall TPostAllCardLostInfoThread::Execute()
{
	//---- Place thread code here ----
	ValidGSBTN->Enabled = false;
	ValidAllBTN->Enabled = false;
	ValidExitBTN->Enabled = false;
	unsigned char SendStr1[9000];
	unsigned char SendStr2[9000];
	unsigned char SendStr3[9000];
	WORD nSendStr = 8192;
	unsigned char CMD = 0x44;

	int tmpkh;
	int khbit;
	int khbyte;

	unsigned char GSCODE[8];
	GSCODE[0] = 1;
	GSCODE[1] = 2;
	GSCODE[2] = 4;
	GSCODE[3] = 8;
	GSCODE[4] = 16;
	GSCODE[5] = 32;
	GSCODE[6] = 64;
	GSCODE[7] = 128;

	ValidPorBar->Position = 0;
	//第一包
	ZeroMemory(SendStr1, 9000);
	SendStr1[64] = 0x20;
	SendStr1[65] = 0x03;
	SendStr1[66] = 0x01;
	SendStr1[67] = 0x01;

	enableGS = false;
	ValidADOQ->Close();
	ValidADOQ->SQL->Clear();
	ValidADOQ->SQL->Add("select * from gs where KH<64513 order by KH asc");
	ValidADOQ->Open();
	if(!ValidADOQ->IsEmpty())
	{
		ValidADOQ->First();
		while(!ValidADOQ->Eof)
		{
			tmpkh = ValidADOQ->FieldByName("KH")->AsInteger;
			khbit = (tmpkh-1)%8;
			khbyte = (tmpkh-1)/8;
			SendStr1[128+khbyte] = (unsigned char)(SendStr1[128+khbyte]+GSCODE[khbit]);
			ValidADOQ->Next();
		}
	}
	ValidADOQ->Close();

	//第二包
	ZeroMemory(SendStr2, 9000);
	SendStr2[64] = 0x20;
	SendStr2[65] = 0x03;
	SendStr2[66] = 0x02;
	SendStr2[67] = 0x02;
	ValidADOQ->SQL->Clear();
	ValidADOQ->SQL->Add("select * from gs where KH>64512 and KH<129025 order by KH asc");
	ValidADOQ->Open();
	if(!ValidADOQ->IsEmpty())
	{
		ValidADOQ->First();
		while(!ValidADOQ->Eof)
		{
			tmpkh = ValidADOQ->FieldByName("KH")->AsInteger;
			khbit = (tmpkh-1-64512)%8;
			khbyte = (tmpkh-1-64512)/8;
			SendStr2[128+khbyte] = (unsigned char)(SendStr2[128+khbyte]+GSCODE[khbit]);
			ValidADOQ->Next();
		}
	}
	ValidADOQ->Close();

	//第三包
	ZeroMemory(SendStr3, 9000);
	SendStr3[64] = 0x20;
	SendStr3[65] = 0x03;
	SendStr3[66] = 0x03;
	SendStr3[67] = 0x03;
	ValidADOQ->SQL->Clear();
	ValidADOQ->SQL->Add("select * from gs where KH>129024 and KH<193537 order by KH asc");
	ValidADOQ->Open();
	if(!ValidADOQ->IsEmpty())
	{
		ValidADOQ->First();
		while(!ValidADOQ->Eof)
		{
			tmpkh = ValidADOQ->FieldByName("KH")->AsInteger;
			khbit = (tmpkh-1-129024)%8;
			khbyte = (tmpkh-1-129024)/8;
			SendStr3[128+khbyte] = (unsigned char)(SendStr3[128+khbyte]+GSCODE[khbit]);
			ValidADOQ->Next();
		}
	}
	ValidADOQ->Close();

//	ValidAllBTN->Enabled = false;
	int itemcount = ValidListV->Items->Count;
	for(int i = 0; i<itemcount; i++)
	{
		if(!Terminated)
		{
			TListItem* tmpitem = ValidListV->Items->Item[i];
			if(tmpitem->Checked)
			{
				POSPARA* para = (POSPARA*)(tmpitem->Data);
				if(1 == para->tag)
				{
					//挂失所有卡分三个包
					SerSendFunc((unsigned char)(para->comnum),
								WORD(para->posnum),
								CMD,
								SendStr1,
								nSendStr,
								1);

					Sleep(200);

					SerSendFunc((unsigned char)(para->comnum),
								WORD(para->posnum),
								CMD,
								SendStr2,
								nSendStr,
								1);

					Sleep(200);

					SerSendFunc((unsigned char)(para->comnum),
								WORD(para->posnum),
								CMD,
								SendStr3,
								nSendStr,
								1);
				}
			}
			ValidPorBar->Position = (i+1)*100/itemcount;
		}
		else
		{
			ValidPorBar->Position = 0;
			ValidAllBTN->Enabled = true;
			ValidGSBTN->Enabled = true;
			return;
        }
	}

//	ValidPorBar->Position = 100;
	ValidAllBTN->Enabled = true;
	ValidGSBTN->Enabled = true;
	ValidExitBTN->Enabled = true;
	MessageBox(SDIAppForm->Handle, "信息补齐完毕，如果有不在线POS机，请先检查POS再进行此项功能，确保数据整齐!", "提示信息", MB_OK);
	enableGS = true;

//	ShowMessage("信息补齐完毕，如果有不在线POS机，请先检查POS再进行此项功能，确保数据整齐!");
}
//---------------------------------------------------------------------------
