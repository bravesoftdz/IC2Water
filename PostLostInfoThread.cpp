//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LostInfoDLFrm.h"
#include "PostLostInfoThread.h"
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
//      void __fastcall TPostLostInfoThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TPostLostInfoThread::TPostLostInfoThread(bool CreateSuspended,
													TcxButton* GSBTN,
													TcxButton* EBTN,
													TADOTable* LostInfoT,
													TcxProgressBar* ProBar) : TThread(CreateSuspended)
{
	ValidGSBTN = GSBTN;
	ValidExitBTN = EBTN;
	ValidLostInfoT = LostInfoT;
	ValidProBar = ProBar;
}
//---------------------------------------------------------------------------
void __fastcall TPostLostInfoThread::Execute()
{
	//---- Place thread code here ----
	ValidGSBTN->Enabled = false;
//	ValidExitBTN->Enabled = false;
	int GSkh;
	unsigned char SendStr[3];
	int Strlen = 3;
	unsigned char status;
	unsigned char port;
	WORD pos;
	unsigned char CMD;
//	while(true)
//	{
//	if(enableGS)
//	{
	ValidLostInfoT->Active = false;
	Sleep(100);
	ValidLostInfoT->Active = true;
	ValidLostInfoT->First();
	int Allcount = ValidLostInfoT->RecordCount;
	ValidProBar->Position = 0;
	int currentpos = 0;

	while(!ValidLostInfoT->Eof)
	{
		if(!Terminated)
		{
			Sleep(100);
			GSkh = ValidLostInfoT->FieldByName("PARA")->AsInteger;
			SendStr[0] = (unsigned char)(GSkh/65536);
			SendStr[1] = (unsigned char)((GSkh%65536)/256);
			SendStr[2] = (unsigned char)GSkh;
			port = (unsigned char)(ValidLostInfoT->FieldByName("SFJPORT")->AsInteger);
			pos = WORD(ValidLostInfoT->FieldByName("SFJID")->AsInteger);

			int checktag = ValidLostInfoT->FieldByName("CMD")->AsInteger;

			if(1 == checktag)
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

				currentpos++;
			}
			else if(2 == checktag)
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

				currentpos++;
			}
			ValidProBar->Position = currentpos*100/Allcount;
			Sleep(100);
		}
		else
		{
			enableGS = false;
			ValidGSBTN->Enabled = false;
			ValidExitBTN->Enabled = true;
            return;
        }
	}

	ValidProBar->Position = 100;

	enableGS = false;
	ValidGSBTN->Enabled = true;
	ValidExitBTN->Enabled = true;
//	MessageBox(SDIAppForm->Handle, "按挂失记录挂失完毕，如果有不在线POS机，请先检查POS再进行此项功能，确保数据整齐!", "提示信息", MB_OK|MB_ICONEXCLAMATION);
	if(ValidLostInfoT->IsEmpty())
	{
		MessageBox(LostInfoFRM->Handle, "按挂失记录挂失完毕，如果有不在线POS机，请先检查POS再进行此项功能，确保数据整齐!", "提示信息", MB_OK|MB_ICONEXCLAMATION);
	}
	else
	{
		MessageBox(LostInfoFRM->Handle, "数据库中仍有挂失解挂数据未下传，请注意!", "提示信息", MB_OK|MB_ICONEXCLAMATION);
	}
//	}
	//	Sleep(60000);
//    }
}
//---------------------------------------------------------------------------
