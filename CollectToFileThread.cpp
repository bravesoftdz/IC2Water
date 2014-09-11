//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CollectToFileThread.h"
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
//      void __fastcall TCollectToFileThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCollectToFileThread::TCollectToFileThread(bool CreateSuspended,
														int posnum,
                                                        int comnum,
														TcxButton* BTN1,
                                                        TcxButton* BTN2,
                                                        TcxButton* BTN3,
                                                        TcxButton* BTN4,
                                                        TcxButton* BTN5,
                                                        String filepathname,
                                                        TcxProgressBar* CollectPBar) : TThread(CreateSuspended)
{
	validposnum = posnum;
    validcomnum = comnum;
    validBTN1 = BTN1;
    validBTN2 = BTN2;
    validBTN3 = BTN3;
    validBTN4 = BTN4;
    validBTN5 = BTN5;
    validfilepathname = filepathname;
    validCollectPBar = CollectPBar;
}
//---------------------------------------------------------------------------

void __fastcall TCollectToFileThread::Execute()
{
	//---- Place thread code here ----
    if(SerReceiveFunc&&SendAckFunc)
	{
    	if(SingleCollectSaveStream.is_open())
    		SingleCollectSaveStream.close();

        SingleCollectSaveStream.open(validfilepathname.t_str(),ios::out, 0);

        if(SingleCollectSaveStream.is_open())
        {
            String CollectTime = "*CollectTime* ";
            CollectTime += Date();
            CollectTime += " ";
            CollectTime += Time();

            SingleCollectSaveStream<<endl<<CollectTime.t_str()<<endl;
//        	SingleCollectSaveStream<<"<SingleCollectToFileData>"<<endl;
            WORD ReceiveStatus = -1;
            WORD SynchroStatus = -1;
            char temp[10] = "";
            unsigned char como = (unsigned char)validcomnum;
            PosNumber = validposnum;
            WORD PosNO = (WORD)(validposnum);
            unsigned char ReceiveCMD = 0x23;
            unsigned char SynchroCMD = 0x54;

            ZeroMemory(receivebuf, 2048);
            int receivelen = 2048;
            unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
            int dirlen = strlen(dir);

            bool btnb1 = validBTN1->Enabled;
            bool btnb2 = validBTN2->Enabled;
            bool btnb3 = validBTN3->Enabled;
            bool btnb4 = validBTN4->Enabled;
            bool btnb5 = validBTN5->Enabled;

            validBTN1->Enabled = false;
            validBTN2->Enabled = false;
            validBTN3->Enabled = false;
            validBTN4->Enabled = false;
            validBTN5->Enabled = false;
            bool continued = true;
            validCollectPBar->Properties->Marquee = true;
            while(continued)
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
                Sleep(100);
            }
            validCollectPBar->Properties->Marquee = false;
            validBTN1->Enabled = btnb1;
            validBTN2->Enabled = btnb2;
            validBTN3->Enabled = btnb3;
            validBTN4->Enabled = btnb4;
            validBTN5->Enabled = btnb5;
            SingleCollectSaveStream.close();
            MessageBox(SDIAppForm->Handle, "数据采集完毕!", "OK", MB_OK);
        }
        else
        {
        	MessageBox(SDIAppForm->Handle, "无法创建数据存储文件!", "Error", MB_OK|MB_ICONERROR);
            return;
        }
    }
    else
    {
        MessageBox(SDIAppForm->Handle, "Error in Load SerReceiveFunc Or SendAckFunc!", "Error", MB_OK|MB_ICONERROR);
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCollectToFileThread::AnalyzeDataFunc()
{
	int recordNUM = (int)receivebuf[7]*256+(int)receivebuf[8];
	if((recordNUM<128)&&(recordNUM>0)&&(0x20 == receivebuf[0])&&(0x03 == receivebuf[1])
	  &&(PosNumber == ((int)receivebuf[12]*256+(int)receivebuf[5]))
	  &&(0x23 == receivebuf[4]))
	{
		for(int i = 0; i < 2048; i++)
			SingleCollectSaveStream<<receivebuf[i];
	}
}
//---------------------------------------------------------------------------
