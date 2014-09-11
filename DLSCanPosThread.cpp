//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DLSCanPosThread.h"
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
//      void __fastcall TDLSCanPosThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TDLSCanPosThread::TDLSCanPosThread(bool CreateSuspended,
											  TADOQuery* Query,
											  TcxButton* AllBTN,
											  TcxButton* DGBTN,
											  TcxButton* EBTN,
											  TcxProgressBar* ProBar,
											  TcxListView* ListV,
											  bool* tag,
											  bool* stag,
											  TcxButton* SABTN,
											  TcxButton* CSABTN,
											  TcxButton* SBTN) : TThread(CreateSuspended)
{
	ValidQuery = Query;
	ValidAllBTN = AllBTN;
	ValidDGBTN = DGBTN;
	ValidEBTN = EBTN,
	ValidSBTN = SBTN;
	ValidProBar = ProBar;
	ValidListV = ListV;

	Validtag = tag;
	Validstag = stag;
	ValidSABTN = SABTN;
	ValidCSABTN = CSABTN;
}
//---------------------------------------------------------------------------

void __fastcall TDLSCanPosThread::Execute()
{
//	SDIAppForm->dxNavBar1->Enabled = false;
	*Validstag = true;
	ValidListV->Clear();
//	ValidScanBTN->Enabled = false;
//	ValidEBTN->Enabled = false;
	ValidQuery->Close();
	ValidQuery->SQL->Clear();
	ValidQuery->SQL->Add("select * from SFJPARAM");
	ValidQuery->Open();
	if(!ValidQuery->IsEmpty())
	{
		ValidAllBTN->Enabled = false;
		ValidDGBTN->Enabled = false;
		ValidEBTN->Enabled = false;
		ValidSABTN->Enabled = false;
		ValidCSABTN->Enabled = false;
		ValidSBTN->Enabled = false;
		*Validtag = false;

		WORD Status;
		unsigned char como = 0x00;
		WORD posnum = -1;
		unsigned char cmd = 0x43;
		unsigned char receivebuf[16];
		ZeroMemory(receivebuf, 16);
		int receivelen = 16;
		unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
		int dirlen = strlen(dir);
		int allposcount = ValidQuery->RecordCount;
		int tag = 0;

		ValidQuery->First();
		ValidProBar->Position = 0;
		while(!ValidQuery->Eof)
		{
			if(!Terminated)
			{
				como = (unsigned char)(ValidQuery->FieldByName("SFJPORT")->AsInteger);
				posnum = (WORD)(ValidQuery->FieldByName("JH")->AsInteger);
				Status = SerReceiveFunc(como, posnum, cmd, receivebuf, receivelen, 1, dir, dirlen);
				if(0 == Status)
				{
					String nodestr = posnum;
					nodestr += "号POS机:COM";
					nodestr += como;
					TListItem* tmp = ValidListV->Items->Add();
					tmp->Checked = false;
					tmp->Caption = nodestr;
					tmp->ImageIndex = 0;
					ValidProBar->Position = (tag+1)*100/allposcount;
					POSPARA* tmppospara = new POSPARA();
					tmppospara->posnum = posnum;
					tmppospara->comnum = (int)como;
					tmppospara->tag = 1;
					tmp->Data = (void*)tmppospara;
					*Validtag = true;
				}
				else
				{
					String nodestr = posnum;
					nodestr += "号POS机:COM";
					nodestr += como;
					TListItem* tmp = ValidListV->Items->Add();
					tmp->Checked = false;
					tmp->Caption = nodestr;
					tmp->ImageIndex = 1;
					ValidProBar->Position = (tag+1)*100/allposcount;
					POSPARA* tmppospara = new POSPARA();
					tmppospara->posnum = posnum;
					tmppospara->comnum = (int)como;
					tmppospara->tag = 2;
					tmp->Data = (void*)tmppospara;

					if(false == *Validtag)
						*Validtag = false;
				}
				tag++;
				ValidQuery->Next();
			}
			else
			{
				ValidAllBTN->Enabled = true;
				ValidDGBTN->Enabled = true;
				ValidEBTN->Enabled = true;
				ValidSABTN->Enabled = true;
				ValidCSABTN->Enabled = true;
				ValidSBTN->Enabled = true;
				return;
            }
		}
		MessageBox(SDIAppForm->Handle,"已完成检查POS机!","Detect POS OVER!",MB_OK|MB_ICONEXCLAMATION);
		if(*Validtag)
		{
			ValidAllBTN->Enabled = true;
			ValidDGBTN->Enabled = true;
			ValidEBTN->Enabled = true;
			ValidSABTN->Enabled = true;
			ValidCSABTN->Enabled = true;
			ValidSBTN->Enabled = true;
		}
		else
		{
			MessageBox(SDIAppForm->Handle,"未检测到在线POS机，无法使用该功能!","Detect POS OVER!",MB_OK|MB_ICONEXCLAMATION);

			ValidAllBTN->Enabled = false;
			ValidDGBTN->Enabled = false;
			ValidEBTN->Enabled = true;
			ValidSABTN->Enabled = false;
			ValidCSABTN->Enabled = false;
			ValidSBTN->Enabled = true;
        }
	}
	else
		MessageBox(SDIAppForm->Handle,"该系统无注册POS机!","No POS Error!",MB_OK|MB_ICONERROR);
	ValidQuery->Close();
	ValidEBTN->Enabled = true;
	ValidSBTN->Enabled = true;

	*Validstag = false;
//	SDIAppForm->dxNavBar1->Enabled = true;
//	ValidScanBTN->Enabled = true;
}
//---------------------------------------------------------------------------
