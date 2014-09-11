//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SingleGSThread.h"
#pragma package(smart_init)
#include "SingleGSFrm.h"
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSingleGSThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSingleGSThread::TSingleGSThread(bool CreateSuspended,
											String khstr,
											TcxListView* GSListView,
											TADOQuery* GSADOQuery,
											TcxButton* GSB,
											TcxButton* EB,
											int gstag) : TThread(CreateSuspended)
{
	Validkhstr = khstr;
	ValidGSListView = GSListView;
	ValidGSADOQuery = GSADOQuery;
	ValidGSB = GSB;
	ValidEB = EB;
	Validgstag = gstag;
}
//---------------------------------------------------------------------------
void __fastcall TSingleGSThread::Execute()
{
	//---- Place thread code here ----
	ValidGSB->Enabled = false;
//	ValidEB->Enabled = false;

	String sqlstr = "select * from CMDLIST where PARA=";
	if(1 == Validgstag)
	{
		sqlstr += Validkhstr;
		sqlstr += " and CMD=1 and STATUS=0 order by SFJID asc";
	}
	else if(2 == Validgstag)
	{
		sqlstr += Validkhstr;
		sqlstr += " and CMD=2 and STATUS=0 order by SFJID asc";
    }

	ValidGSADOQuery->Close();
	ValidGSADOQuery->SQL->Clear();
	ValidGSADOQuery->SQL->Add(sqlstr);
	ValidGSADOQuery->Open();
	if(ValidGSADOQuery->IsEmpty())
	{
		ValidGSADOQuery->Close();
		MessageBox(SingleGSForm->Handle,"数据库中没有POS机记录!","提示",MB_OK|MB_ICONERROR);
		ValidGSB->Enabled = true;
		ValidEB->Enabled = true;
		return;
	}

	int GSkh;
	unsigned char SendStr[3];
	int Strlen = 3;
	unsigned char status;
	unsigned char port;
	WORD pos;
	unsigned char CMD;

	int tag = ValidGSADOQuery->RecordCount;
	for(int i = 0; i < tag; i++)
	{
		if(!Terminated)
		{
			GSkh = ValidGSADOQuery->FieldByName("PARA")->AsInteger;
			SendStr[0] = (unsigned char)(GSkh/65536);
			SendStr[1] = (unsigned char)((GSkh%65536)/256);
			SendStr[2] = (unsigned char)GSkh;
			port = (unsigned char)(ValidGSADOQuery->FieldByName("SFJPORT")->AsInteger);
			pos = WORD(ValidGSADOQuery->FieldByName("SFJID")->AsInteger);

			if(1 == Validgstag)
			{
				CMD = 0x33;
				status = SerSendFunc(port, pos, CMD, SendStr, Strlen, 1);
				if(0 == status)
				{
					ValidGSADOQuery->Delete();
					ValidGSListView->Items->Item[i]->SubItems->Strings[0] = "挂失成功!";
			   //		ValidLostInfoT->Next();
				}
				else
				{
					ValidGSADOQuery->Next();
					ValidGSListView->Items->Item[i]->SubItems->Strings[0] = "挂失失败!";
				}
				Sleep(500);
			}
			if(2 == Validgstag)
			{
				CMD = 0x38;
				status = SerSendFunc(port, pos, CMD, SendStr, Strlen, 1);
				if(0 == status)
				{
					ValidGSADOQuery->Delete();
					ValidGSListView->Items->Item[i]->SubItems->Strings[0] = "撤销挂失成功!";
			   //		ValidLostInfoT->Next();
				}
				else
				{
					ValidGSADOQuery->Next();
					ValidGSListView->Items->Item[i]->SubItems->Strings[0] = "撤销挂失失败!";
				}
				Sleep(500);
			}
		}
		else
		{
			ValidGSB->Enabled = false;
			ValidEB->Enabled = true;
			return;
        }
	}
    MessageBox(SingleGSForm->Handle,"挂失操作完成!","提示",MB_OK|MB_ICONINFORMATION);
	ValidGSB->Enabled = false;
	ValidEB->Enabled = true;
}
//---------------------------------------------------------------------------
