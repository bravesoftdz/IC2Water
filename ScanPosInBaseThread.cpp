//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ScanPosInBaseThread.h"
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
//      void __fastcall TSCanPosInBaseThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSCanPosInBaseThread::TSCanPosInBaseThread(bool CreateSuspended,
													  TADOQuery* ADOQ,
													  TcxListView* LV,
													  TcxButton* SSBTN,
													  TcxButton* SABTN,
													  TcxButton* AddBTN,
                                                      TcxButton* AddmBTN,
													  TcxButton* DelBTN,
													  TcxButton* ExitBTN,
													  TcxButton* ScanBTN,
                                                      TcxButton* SelABTN,
													  TcxButton* CalSABTN,
													  TcxButton* SABPBTN,
													  bool* tag,
													  TcxProgressBar* ProBar) : TThread(CreateSuspended)
{
	ValidADOQ = ADOQ;
	ValidLV = LV;
	ValidSSBTN = SSBTN;
	ValidSABTN = SABTN;
	ValidAddBTN = AddBTN;
    ValidAddmBTN = AddmBTN;
	ValidDelBTN = DelBTN;
	ValidExitBTN = ExitBTN;
	ValidScanBTN = ScanBTN;
    ValidSelABTN = SelABTN;
	ValidCalSABTN = CalSABTN;
	ValidSABPBTN = SABPBTN;
	Validtag = tag;
	ValidProBar = ProBar;
}
//---------------------------------------------------------------------------
void __fastcall TSCanPosInBaseThread::Execute()
{
	//---- Place thread code here ----
	*Validtag = true;
	ValidLV->Items->Clear();
	ValidSSBTN->Enabled = false;
	ValidSABTN->Enabled = false;
	ValidAddBTN->Enabled = false;
    ValidAddmBTN->Enabled = false;
	ValidDelBTN->Enabled = false;
	ValidExitBTN->Enabled = false;
    ValidSelABTN->Enabled = false;
	ValidCalSABTN->Enabled = false;
	ValidSABPBTN->Enabled = false;
	double allposje = 0;
	int allposrec = 0;

	ValidADOQ->Close();
	ValidADOQ->SQL->Clear();
	ValidADOQ->SQL->Add("select * from SFJPARAM");
	ValidADOQ->Open();
	if(!ValidADOQ->IsEmpty())
	{
		Synchronize(PosStatusForm->TreeView1->Items->Clear);
		ValidADOQ->First();
		int count = ValidADOQ->RecordCount;
		int currencount = 1;
		while(!ValidADOQ->Eof)
		{
			ValidProBar->Position = currencount*100/count;
			if(!Terminated)
			{
				WORD Status;
				unsigned char como = 0x00;
				unsigned char cmd = 0x43;
				unsigned char receivebuf[16];
				ZeroMemory(receivebuf, 16);
				int receivelen = 16;
				unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
				int dirlen = strlen(dir);
				int PosNo = ValidADOQ->FieldByName("JH")->AsInteger;
				IntToChar(ValidADOQ->FieldByName("SFJPORT")->AsInteger, &como);

				Status = SerReceiveFunc(como,
										(WORD)PosNo,
										cmd,
										receivebuf,
										receivelen,
										1,
										dir,
										dirlen);

                checkstatus = Status;
				if(0 == Status)
				{
					String nodestr = PosNo;
					nodestr += "号POS机:COM";
					nodestr += como;
                    nodenamestr = nodestr;


					POSPARA* tmppospara = new POSPARA();
					tmppospara->posnum = PosNo;
					tmppospara->comnum = (int)como;
					tmppospara->tag = 1;

                    nodepospara = tmppospara;

                    Synchronize(additemfun);

                    /*
                    TListItem* tmp = ValidLV->Items->Add();
					tmp->Caption = nodestr;
					tmp->ImageIndex = 0;
					tmp->Data = (void*)tmppospara;*/

					int lowptr = 256*(int)receivebuf[0] + (int)receivebuf[1];
					int highptr = 256*(int)receivebuf[2] + (int)receivebuf[3];

					double posje = ((double)(256*256*256*(int)receivebuf[4] + 256*256*(int)receivebuf[5] + 256*(int)receivebuf[6] +(int)receivebuf[7]))/100;
					int allrec;
					if(highptr >= lowptr)
					{
						allrec = highptr - lowptr;
					}
					else
						allrec = highptr + 6576 - lowptr;
					nodestr += " 在线，含有消费记录";
					nodestr += allrec;
					nodestr += "条，消费金额为：￥";
					nodestr += posje;

					allposrec += allrec;
					allposje += posje;

                    displaynodenamestr = nodestr;
                    Synchronize(adddisplayitemfun);
                    /*
					TTreeNode* statustmp = PosStatusForm->TreeView1->Items->Add(NULL, nodestr);
					statustmp->ImageIndex = 0;
					statustmp->SelectedIndex = 0; */
				}
				else
				{
					String nodestr = PosNo;
					nodestr += "号POS机:COM";
					nodestr += como;
                    nodenamestr = nodestr;

					POSPARA* tmppospara = new POSPARA();
					tmppospara->posnum = PosNo;
					tmppospara->comnum = (int)como;
					tmppospara->tag = 2;
                    nodepospara = tmppospara;

                    Synchronize(additemfun);
                    /*
                    TListItem* tmp = ValidLV->Items->Add();
					tmp->Caption = nodestr;
					tmp->ImageIndex = 1;
					tmp->Data = (void*)tmppospara;   */

					nodestr += " 离线，无法查询消费记录条数";
                    displaynodenamestr = nodestr;
                    Synchronize(adddisplayitemfun);
                    /*
					TTreeNode* statustmp = PosStatusForm->TreeView1->Items->Add(NULL, nodestr);
					statustmp->ImageIndex = 1;
                    statustmp->SelectedIndex = 1;   */
				}
				Sleep(100);
			}
			ValidADOQ->Next();
			currencount++;
        }
		MessageBox(SDIAppForm->Handle, "扫描完毕", "扫描完毕", MB_OK);
    }
	ValidADOQ->Close();

	if("系统管理员" == OperatorGroupName)
	{
		ValidSSBTN->Enabled = true;
		ValidSABTN->Enabled = true;
		ValidAddBTN->Enabled = true;
        ValidAddmBTN->Enabled = true;
		ValidDelBTN->Enabled = true;
		ValidScanBTN->Enabled = true;
        ValidSelABTN->Enabled = true;
		ValidCalSABTN->Enabled = true;
		ValidSABPBTN->Enabled = true;
	}
	else
	{
		ValidSSBTN->Enabled = false;
		ValidSABTN->Enabled = false;
		ValidAddBTN->Enabled = false;
        ValidAddmBTN->Enabled = false;
		ValidDelBTN->Enabled = false;
		ValidScanBTN->Enabled = false;
        ValidSelABTN->Enabled = false;
		ValidCalSABTN->Enabled = false;
		ValidSABPBTN->Enabled = false;
	}
	ValidExitBTN->Enabled = true;
	*Validtag = false;

	String statustr = "所有POS机中含有消费记录总条数为：";
	statustr += allposrec;
	statustr += "条。总消费金额为：￥";
	statustr += allposje;
	PosStatusForm->Panel3->Caption = statustr;
	Synchronize(SDIAppForm->ShowStatus);
}
//---------------------------------------------------------------------------

void __fastcall TSCanPosInBaseThread::additemfun()
{
	TListItem* tmp = ValidLV->Items->Add();
    tmp->Caption = nodenamestr;
    if(checkstatus)
    	tmp->ImageIndex = 1;
    else
    	tmp->ImageIndex = 0;
    tmp->Data = (void*)nodepospara;
}
//---------------------------------------------------------------------------

void __fastcall TSCanPosInBaseThread::adddisplayitemfun()
{
	TTreeNode* statustmp = PosStatusForm->TreeView1->Items->Add(NULL, displaynodenamestr);
    if(checkstatus)
    {
    	statustmp->ImageIndex = 1;
    	statustmp->SelectedIndex = 1;
    }
    else
    {
        statustmp->ImageIndex = 0;
    	statustmp->SelectedIndex = 0;
    }
}

