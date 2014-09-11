//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ScallPosThread.h"
#include "SDIMAIN.h"
#include "GlobalParameter.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TScallPosThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TScallPosThread::TScallPosThread(bool CreateSuspended,
											bool* Scantag,
											TcxProgressBar* progress,
											TTreeView* OnLinePosTreeList,
											TcxButton* CollectBTN,
											TcxButton* EBTN,
											TcxButton* SBTN,
											TPanel* Panel,
											int* PosNum,
											TADOQuery* CDQuery) : TThread(CreateSuspended)
{
	ValidScantag = Scantag;
	progressbar = progress;
	ValidPosTreeList = OnLinePosTreeList;
	ValidCollectBTN = CollectBTN;
	ValidExitBTN = EBTN;
	ValidSBTN = SBTN;
	ValidPanel = Panel;
	validposnum = PosNum;
	ValidCDQuery = CDQuery;
}
//---------------------------------------------------------------------------

void __fastcall TScallPosThread::Execute()
{
	//---- Place thread code here ---
	ValidExitBTN->Enabled = false;
	ValidSBTN->Enabled = false;
	if(SerReceiveFunc)
	{
		*ValidScantag = true;
		ValidPosTreeList->Items->Clear();
		*validposnum = 0;
		ValidCDQuery->Close();
		ValidCDQuery->SQL->Clear();
		ValidCDQuery->SQL->Add("select * from SFJPARAM");
		ValidCDQuery->Open();
		if(!ValidCDQuery->IsEmpty())
		{
			ValidCDQuery->First();
			int count = ValidCDQuery->RecordCount;
			int currentcount = 1;
			while(!ValidCDQuery->Eof)
			{
				progressbar->Position = currentcount*100/count;
				currentcount++;
				if(!Terminated)
				{
					WORD Status;
					unsigned char como = 0x00;
					WORD NO1 = 1;
					unsigned char cmd = 0x43;
					unsigned char receivebuf[16];
					ZeroMemory(receivebuf, 16);
					int receivelen = 16;
					unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
					int dirlen = strlen(dir);

					String nodename = ValidCDQuery->FieldByName("STNAME")->AsString.Trim();
					nodename += ":";
					nodename += ValidCDQuery->FieldByName("JH")->AsInteger;
					nodename += "号机";
					como = (unsigned char)(ValidCDQuery->FieldByName("SFJPORT")->AsInteger);
					int PosNO = ValidCDQuery->FieldByName("JH")->AsInteger;
					POSPARA* tmppospara = new POSPARA();
					tmppospara->comnum = ValidCDQuery->FieldByName("SFJPORT")->AsInteger;
					tmppospara->posnum = PosNO;
					tmppospara->tag = 4;

					Status = SerReceiveFunc(como, (WORD)PosNO, cmd, receivebuf, receivelen, 1, dir, dirlen);

                    checkstatus = Status;
                    nodenamestr = nodename;
                    addtmppospara = tmppospara;

                    Synchronize(addlistitem);
		/*			if(0 == Status)
					{
						TTreeNode* tmpnode;
						tmpnode = ValidPosTreeList->Items->AddChild(NULL, nodename);
						if(tmpnode)
						{
							tmpnode->ImageIndex = 1;
							tmpnode->SelectedIndex = 1;
							tmpnode->StateIndex = 1;
							tmpnode->ExpandedImageIndex = 1;
							tmpnode->Data = (void*)tmppospara;
							(*validposnum)++;
						}
					}
					else
					{
						TTreeNode* tmpnode;
						tmpnode = ValidPosTreeList->Items->AddChild(NULL, nodename);
						if(tmpnode)
						{
							tmpnode->ImageIndex = 2;
							tmpnode->SelectedIndex = 2;
							tmpnode->StateIndex = 2;
							tmpnode->ExpandedImageIndex = 2;
							tmppospara->tag = 5;
							tmpnode->Data = (void*)tmppospara;
						}
					}     */
				}
				else
				{
					*ValidScantag = false;
					return;
                }
				ValidCDQuery->Next();
			}
		}
		ValidCDQuery->Close();
		if(0 == *validposnum)
		{
			MessageBox(SDIAppForm->Handle, "没有POS在线无法进行数据采集!", "Error", MB_OK|MB_ICONERROR);
			ValidPanel->Caption = "已完成扫描在线POS机，由于无在线POS机，无法进行数据采集!";
			ValidCollectBTN->Enabled = false;
		}
		else
		{
			ValidPanel->Caption = "已完成扫描在线POS机，请进行时数据采集!";
			ValidCollectBTN->Enabled = true;
		}
	}
	else
		MessageBox(SDIAppForm->Handle, "Error in Load SerSendFUNC!", "Error", MB_OK|MB_ICONERROR);

	*ValidScantag = false;
	ValidExitBTN->Enabled = true;
	ValidSBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TScallPosThread::addlistitem()
{
    TTreeNode* tmpnode;
    tmpnode = ValidPosTreeList->Items->AddChild(NULL, nodenamestr);
    if(tmpnode)
    {
        if(0 == checkstatus)
        {
            tmpnode->ImageIndex = 1;
            tmpnode->SelectedIndex = 1;
            tmpnode->StateIndex = 1;
            tmpnode->ExpandedImageIndex = 1;
            tmpnode->Data = (void*)addtmppospara;
            (*validposnum)++;
        }
        else
        {
            tmpnode->ImageIndex = 2;
            tmpnode->SelectedIndex = 2;
            tmpnode->StateIndex = 2;
            tmpnode->ExpandedImageIndex = 2;
            addtmppospara->tag = 5;
            tmpnode->Data = (void*)addtmppospara;
        }
    }
}

