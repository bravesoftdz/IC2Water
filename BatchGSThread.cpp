//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BatchGSThread.h"
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
//      void __fastcall TBatchGSThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TBatchGSThread::TBatchGSThread(bool CreateSuspended,
										  TADOQuery* GSQuery,
										  TADOQuery* OPQuery,
										  TcxProgressBar* CProgressBar,
										  TcxButton* QBTN,
										  TcxButton* GBTN,
										  TcxButton* EBTN,
										  String sqlinthread) : TThread(CreateSuspended)
{
	ValidGSQuery = GSQuery;
	ValidOPQuery = OPQuery;
	ValidCProgressBar = CProgressBar;
	ValidQBTN = QBTN;
	ValidGBTN = GBTN;
	ValidEBTN = EBTN;
	Validsqlinthread = sqlinthread;
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSThread::Execute()
{
	//---- Place thread code here ----
	ValidQBTN->Enabled = false;
	ValidGBTN->Enabled = false;
//	ValidEBTN->Enabled = false;

	ValidGSQuery->Close();
	ValidGSQuery->SQL->Clear();
	ValidGSQuery->SQL->Add(Validsqlinthread);
	ValidGSQuery->Open();
	int allgsrec = ValidGSQuery->RecordCount;
	int currentgs = 0;
	ValidCProgressBar->Position = 0;
	ValidGSQuery->First();
	while(!ValidGSQuery->Eof)
	{
		if(Terminated)
			return;
		enableGS = false;
		int kh = ValidGSQuery->FieldByName("KH")->AsInteger;
		String bhstr = ValidGSQuery->FieldByName("BH")->AsString.Trim();
		double sfye = ValidGSQuery->FieldByName("SF_YE")->AsFloat;

		String sql = "select * from CARD where BH='";
		sql += bhstr;
		sql += "'";

		ValidOPQuery->Close();
		ValidOPQuery->SQL->Clear();
		ValidOPQuery->SQL->Add(sql);
		ValidOPQuery->Open();
		if(!ValidOPQuery->IsEmpty())
		{
			ValidOPQuery->Edit();
			ValidOPQuery->FieldByName("ZT")->AsString = "¹ÒÊ§";
			ValidOPQuery->Post();
		}

		sql = "select * from CARD_F where BH='";
		sql += bhstr;
		sql += "'";

		ValidOPQuery->Close();
		ValidOPQuery->SQL->Clear();
		ValidOPQuery->SQL->Add(sql);
		ValidOPQuery->Open();
		if(!ValidOPQuery->IsEmpty())
		{
			ValidOPQuery->Edit();
			ValidOPQuery->FieldByName("ZT")->AsString = "¹ÒÊ§";
			ValidOPQuery->Post();
		}

		sql = "select * from KZT where BH='";
		sql += bhstr;
		sql += "'";
		ValidOPQuery->Close();
		ValidOPQuery->SQL->Clear();
		ValidOPQuery->SQL->Add(sql);
		ValidOPQuery->Open();
		if(!ValidOPQuery->IsEmpty())
		{
			ValidOPQuery->Edit();
			ValidOPQuery->FieldByName("GS")->AsInteger = 1;
			ValidOPQuery->Post();
		}

		sql = "select * from GS where BH='";
		sql += bhstr;
		sql += "' and KH=";
		sql += kh;
		ValidOPQuery->Close();
		ValidOPQuery->SQL->Clear();
		ValidOPQuery->SQL->Add(sql);
		ValidOPQuery->Open();

		if(ValidOPQuery->IsEmpty())
		{
			sql = "insert into GS values(:BH,:KH,:GSRQ,:USERNAME)";
			ValidOPQuery->Close();
			ValidOPQuery->SQL->Clear();
			ValidOPQuery->SQL->Add(sql);
			ValidOPQuery->Parameters->ParamByName("BH")->Value = bhstr;
			ValidOPQuery->Parameters->ParamByName("KH")->Value = kh;
			ValidOPQuery->Parameters->ParamByName("GSRQ")->Value = DateTimeToStr(Now());
			ValidOPQuery->Parameters->ParamByName("USERNAME")->Value = OperatorName;
			ValidOPQuery->ExecSQL();


			ValidOPQuery->Close();
			ValidOPQuery->SQL->Clear();
			sql = "select * from SFJPARAM";
			ValidOPQuery->SQL->Add(sql);
			ValidOPQuery->Open();
			if(!ValidOPQuery->IsEmpty())
			{
				int pos[2000];
				int port[2000];
				int i = 0;
				ValidOPQuery->First();
				while(!ValidOPQuery->Eof)
				{
					pos[i] = ValidOPQuery->FieldByName("JH")->AsInteger;
					port[i] = ValidOPQuery->FieldByName("SFJPORT")->AsInteger;
					i++;
					ValidOPQuery->Next();
				}
				int posnum = i;
				ValidOPQuery->Close();
				ValidOPQuery->SQL->Clear();
				ValidOPQuery->Close();
				ValidOPQuery->SQL->Clear();
				sql = "delete from CMDLIST where PARA=";
				sql += kh;
				sql += " and status=0";
		   //		ShowMessage(sql);
				ValidOPQuery->SQL->Add(sql);
				ValidOPQuery->ExecSQL();
				ValidOPQuery->Close();

				ValidOPQuery->SQL->Clear();
				sql = "insert into CMDLIST values(:SFJID,:SFJPORT,:CMD,:PARA,:STATUS,:SENDTIME)";
				ValidOPQuery->SQL->Add(sql);
				for(i = 0; i < posnum; i++)
				{
					ValidOPQuery->Parameters->ParamByName("SFJID")->Value = pos[i];
					ValidOPQuery->Parameters->ParamByName("SFJPORT")->Value = port[i];
					ValidOPQuery->Parameters->ParamByName("CMD")->Value = 1;
					ValidOPQuery->Parameters->ParamByName("PARA")->Value = kh;
					ValidOPQuery->Parameters->ParamByName("STATUS")->Value = 0;
					ValidOPQuery->Parameters->ParamByName("SENDTIME")->Value = NULL;
					ValidOPQuery->ExecSQL();
				}
				ValidOPQuery->Close();

				//ÌîÐ´²Ù×÷¼ÇÂ¼±í
				ValidOPQuery->SQL->Clear();
				sql =  "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
				ValidOPQuery->SQL->Add(sql);
				ValidOPQuery->Parameters->ParamByName("BH")->Value = bhstr;
				ValidOPQuery->Parameters->ParamByName("KH")->Value = kh;
				ValidOPQuery->Parameters->ParamByName("JE")->Value = 0;
				ValidOPQuery->Parameters->ParamByName("YE")->Value = sfye;
				ValidOPQuery->Parameters->ParamByName("LX")->Value = "¹ÒÊ§";
				ValidOPQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
				ValidOPQuery->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
				ValidOPQuery->ExecSQL();
				ValidOPQuery->Close();
			}
		}

		enableGS = true;
		ValidCProgressBar->Position = currentgs/allgsrec*100;
		currentgs++;
		ValidGSQuery->Next();
	}
	ValidCProgressBar->Position = 100;

	MessageBox(SDIAppForm->Handle,"¹ÒÊ§Íê±Ï","ÌáÊ¾",MB_OK);

	ValidQBTN->Enabled = true;
	ValidGBTN->Enabled = true;
	ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------
