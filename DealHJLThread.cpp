//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DealHJLThread.h"
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
//      void __fastcall TDealHJLThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TDealHJLThread::TDealHJLThread(bool CreateSuspended,
										  TcxButton* EBTN,
										  TcxProgressBar* PBar,
										  TADOQuery* ADOQ,
										  TADOQuery* DADOQ) : TThread(CreateSuspended)
{
	ValidEBTN = EBTN;
	ValidPBar = PBar;
	ValidADOQ = ADOQ;
	ValidDADOQ = DADOQ;
}
//---------------------------------------------------------------------------
void __fastcall TDealHJLThread::Execute()
{
	//---- Place thread code here ----
	ValidEBTN->Enabled = false;
	ValidADOQ->Close();
	ValidADOQ->SQL->Clear();
	ValidADOQ->SQL->Add("select * from HJL where SFLX='a'");
	ValidADOQ->Open();
	ValidPBar->Position = 0;

	if(!ValidADOQ->IsEmpty())
	{
		int allhjlnum = ValidADOQ->RecordCount;
		ValidADOQ->First();
		int i = 0;
		while(!ValidADOQ->Eof)
		{
			i++;
			int kh = ValidADOQ->FieldByName("KH")->AsInteger;
			String bhstr = ValidADOQ->FieldByName("BH")->AsString.Trim();
			int sycs = ValidADOQ->FieldByName("SYCS")->AsInteger;
			double ye = ValidADOQ->FieldByName("YE")->AsFloat;

			String checksqlstr = "select * from MXBAK where KH=";
			checksqlstr += kh;
			checksqlstr += " and BH='";
			checksqlstr += bhstr;
			checksqlstr += "' and SYCS=";
			checksqlstr += sycs+1;

			ValidDADOQ->Close();
			ValidDADOQ->SQL->Clear();
			ValidDADOQ->SQL->Add(checksqlstr);
			ValidDADOQ->Open();
			if(!ValidDADOQ->IsEmpty())
			{
				double tmpye = ValidDADOQ->FieldByName("SF_YE")->AsFloat;
				double tmpje = ValidDADOQ->FieldByName("SFJE")->AsFloat;

				if((tmpye+tmpje) == ye)
				{
					String delstr = "delete from HJL where SFLX = 'a' and KH=";
					delstr += kh;
					delstr += " and BH='";
					delstr += bhstr;
					delstr += "' and SYCS=";
					delstr += sycs;

					ValidDADOQ->Close();
					ValidDADOQ->SQL->Clear();
					ValidDADOQ->SQL->Add(delstr);
					ValidDADOQ->ExecSQL();
                }
            }
			ValidPBar->Position = i/allhjlnum*100;
			ValidADOQ->Next();
        }
	}

	ValidPBar->Position = 100;
	MessageBox(SDIAppForm->Handle, "灰记录处理完毕!", "OK", MB_OK);

	ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------
