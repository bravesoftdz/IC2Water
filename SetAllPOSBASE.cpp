//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetAllPOSBASE.h"
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
//      void __fastcall TSetAllPOSBaseThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSetAllPOSBaseThread::TSetAllPOSBaseThread(bool CreateSuspended,
													  int comn,
													  int max,
													  int dmax,
													  String pw,
													  bool dinc,
													  bool qkbt,
													  bool mmax,
													  int mmaxcs,
													  TADOQuery* ADOQ,
													  TcxButton* SABTN,
													  TcxButton* SSBTN,
													  TcxButton* DelBTN,
													  TcxButton* AddBTN,
													  TcxButton* AddMBTN,
													  TcxButton* ScanBTN,
													  TcxButton* EndBTN,
													  TcxButton* ExitBTN,
													  TcxButton* SelABTN,
													  TcxButton* CalSABTN,
													  TcxButton* SABPBTN,
													  TcxProgressBar* ProBar,
													  TcxListView* LV) : TThread(CreateSuspended)
{
	Validcomn = comn;
	Validmax = max;
	Validdmax = dmax;
	Validpw = pw;
	Validdinc = dinc;
	Validqkbt = qkbt;
	Validmmax = mmax;
	Validmmaxcs = mmaxcs;
	ValidADOQ = ADOQ;
	ValidSABTN = SABTN;
	ValidSSBTN = SSBTN;
	ValidDelBTN = DelBTN;
	ValidAddBTN = AddBTN;
	ValidAddMBTN = AddMBTN;
	ValidScanBTN = ScanBTN;
	ValidEndBTN = EndBTN;
	ValidExitBTN = ExitBTN;
	ValidSelABTN = SelABTN;
	ValidCalSABTN = CalSABTN;
	ValidSABPBTN = SABPBTN;
	ValidProBar = ProBar;
	ValidLV = LV;
}
//---------------------------------------------------------------------------
void __fastcall TSetAllPOSBaseThread::Execute()
{
	//---- Place thread code here ----
	ValidProBar->Position = 0;
	ValidSABTN->Enabled = false;
	ValidSSBTN->Enabled = false;
	ValidDelBTN->Enabled = false;
	ValidAddBTN->Enabled = false;
	ValidAddMBTN->Enabled = false;
	ValidScanBTN->Enabled = false;
	ValidEndBTN->Enabled = false;
	ValidExitBTN->Enabled = false;
	ValidSelABTN->Enabled = false;
	ValidCalSABTN->Enabled = false;
	ValidSABPBTN->Enabled = false;
	ValidADOQ->Close();
	ValidADOQ->SQL->Clear();
	ValidADOQ->SQL->Add("select * from SFJPARAM");
	ValidADOQ->Open();
	if(ValidADOQ->IsEmpty())
	{
		ValidProBar->Position = 100;
		ValidADOQ->Close();
		MessageBox(SDIAppForm->Handle, "POS机参数设置完毕", "设置", MB_OK|MB_ICONEXCLAMATION);
		ValidSABTN->Enabled = true;
		ValidSSBTN->Enabled = true;
		ValidDelBTN->Enabled = true;
		ValidAddBTN->Enabled = true;
		ValidAddMBTN->Enabled = true;
		ValidScanBTN->Enabled = true;
		ValidEndBTN->Enabled = true;
		ValidExitBTN->Enabled = true;
		ValidSelABTN->Enabled = true;
		ValidCalSABTN->Enabled = true;
		ValidSABPBTN->Enabled = true;
		return;
	}
	int allpos = ValidADOQ->RecordCount;
	int currentpos = 0;
	ValidADOQ->First();
	while(!ValidADOQ->Eof)
	{
		ValidADOQ->Edit();

		ValidADOQ->FieldByName("MAXXF")->AsInteger = Validmax;
		ValidADOQ->FieldByName("MAXZZZE")->AsInteger = Validdmax;
		ValidADOQ->FieldByName("SFJPORT")->AsInteger = Validcomn;
		ValidADOQ->FieldByName("PASSWORD")->AsString = Validpw;
		ValidADOQ->FieldByName("DINGCAN")->AsBoolean = Validdinc;
		ValidADOQ->FieldByName("DELBT")->AsBoolean = Validqkbt;

		ValidADOQ->FieldByName("MAXCSTAG")->AsBoolean = Validmmax;

		if(Validmmax)
		{
			ValidADOQ->FieldByName("MAXCS")->AsInteger = Validmmaxcs;
		}
		else
		{
			ValidADOQ->FieldByName("MAXCS")->AsInteger = 0;
		}

		ValidADOQ->Post();
		ValidADOQ->Next();
		currentpos++;
		ValidProBar->Position = currentpos*100/allpos;
	}

	int count = ValidLV->Items->Count;
	for (int i = 0; i < count; i++)
	{
		TListItem* tmpitem = ValidLV->Items->Item[i];
		POSPARA* para = (POSPARA*)tmpitem->Data;
		String nodestr = para->posnum;
		nodestr += "号POS机:COM";
		nodestr += Validcomn;
		tmpitem->Caption = nodestr;
		para->comnum = Validcomn;
	}
	ValidProBar->Position = 100;
	ValidADOQ->Close();
	MessageBox(SDIAppForm->Handle, "POS机参数设置完毕", "设置", MB_OK|MB_ICONEXCLAMATION);
	ValidSABTN->Enabled = true;
	ValidSSBTN->Enabled = true;
	ValidDelBTN->Enabled = true;
	ValidAddBTN->Enabled = true;
	ValidAddMBTN->Enabled = true;
	ValidScanBTN->Enabled = true;
	ValidEndBTN->Enabled = true;
	ValidExitBTN->Enabled = true;
	ValidSelABTN->Enabled = true;
	ValidCalSABTN->Enabled = true;
	ValidSABPBTN->Enabled = true;
}
//---------------------------------------------------------------------------
