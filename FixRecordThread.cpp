//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SDIMAIN.h"
#include "GlobalParameter.h"

#include "FixRecordThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TFixRecordThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TFixRecordThread::TFixRecordThread(bool CreateSuspended,
											  TADOQuery* AllCardADOQ,
											  TADOQuery* AllRecordADOQ,
											  TADOQuery* AddRecordADOQ,
											  TProgressBar* ProBar,
											  TButton* BTN)
	: TThread(CreateSuspended)
{
	ValidAllCardADOQ = AllCardADOQ;
	ValidAllRecordADOQ = AllRecordADOQ;
	ValidAddRecordADOQ = AddRecordADOQ;
	ValidProBar = ProBar;
	ValidBTN = BTN;
}
//---------------------------------------------------------------------------
void __fastcall TFixRecordThread::Execute()
{
	//---- Place thread code here ----
	ValidBTN->Enabled = false;
	ValidProBar->Position = 0;
	ValidAllCardADOQ->Close();
	ValidAllCardADOQ->SQL->Clear();
	ValidAllCardADOQ->SQL->Add("select * from CARD_F order by BH asc");
	ValidAllCardADOQ->Open();
	if(ValidAllCardADOQ->IsEmpty())
	{
		MessageBox(SDIAppForm->Handle, "系统中无卡片记录!", "Error", MB_OK);
		ValidAllCardADOQ->Close();
		ValidBTN->Enabled = true;
		return;
	}

	int allcards = ValidAllCardADOQ->RecordCount;
	int currentcard = 0;
	String tmpSQLSTR = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";

	//begin to query records of every card
	ValidAllCardADOQ->First();
	while(!ValidAllCardADOQ->Eof)
	{
		String BHStr = ValidAllCardADOQ->FieldByName("BH")->AsString.Trim();
		String sqlstr = "select * from MXBAK where BH='";
		sqlstr += BHStr;
		sqlstr += "' order by SYCS asc";

		ValidAllRecordADOQ->Close();
		ValidAllRecordADOQ->SQL->Clear();
		ValidAllRecordADOQ->SQL->Add(sqlstr);
		ValidAllRecordADOQ->Open();
		if(!ValidAllRecordADOQ->IsEmpty())
		{
			//fix record process
			ValidAllRecordADOQ->Last();
			int tail = ValidAllRecordADOQ->FieldByName("SYCS")->AsInteger;
			ValidAllRecordADOQ->First();
			int head = ValidAllRecordADOQ->FieldByName("SYCS")->AsInteger;
			if((tail+2) > ValidAllRecordADOQ->RecordCount)
			{
				int currentrec;
				float currentsf;
				float tmpcurrentsf;
				int nextrec;
				float nextsf;
				int addcount;
				while(!ValidAllRecordADOQ->Eof)
				{
					currentrec = ValidAllRecordADOQ->FieldByName("SYCS")->AsInteger;
					currentsf = ValidAllRecordADOQ->FieldByName("SF_YE")->AsFloat;
					tmpcurrentsf = currentsf;
					ValidAllRecordADOQ->Next();
					if(!ValidAllRecordADOQ->Eof)
					{
						nextrec = ValidAllRecordADOQ->FieldByName("SYCS")->AsInteger;
						nextsf = ValidAllRecordADOQ->FieldByName("SF_YE")->AsFloat;
						if(1 < (nextrec-currentrec))
						{
							//add record
							addcount = nextrec-currentrec-1;
							int everysf;
							double margin;
							if(("I" == ValidAllRecordADOQ->FieldByName("SFLX")->AsString.Trim().UpperCase())||("A" == ValidAllRecordADOQ->FieldByName("SFLX")->AsString.Trim().UpperCase()))
							{
								margin = currentsf+ValidAllRecordADOQ->FieldByName("SFJE")->AsInteger-nextsf;
								everysf = ((int)margin)/addcount;
							}
							else
							{
								margin = currentsf-nextsf-ValidAllRecordADOQ->FieldByName("SFJE")->AsFloat;
								everysf = ((int)margin)/addcount;
							}

							if(margin > 0)
							{
								for(int i = 0; i < addcount; i++)
								{
									if((i == addcount-1)&&(addcount>2))
									{
										float sf = margin-everysf*(addcount-1);
										ValidAddRecordADOQ->Close();
										ValidAddRecordADOQ->SQL->Clear();
										ValidAddRecordADOQ->SQL->Add(tmpSQLSTR);
										ValidAddRecordADOQ->Parameters->ParamByName("BH")->Value = ValidAllRecordADOQ->FieldByName("BH")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("KH")->Value = ValidAllRecordADOQ->FieldByName("KH")->Value;
										tmpcurrentsf -= sf;
										ValidAddRecordADOQ->Parameters->ParamByName("SF_YE")->Value = tmpcurrentsf;
										ValidAddRecordADOQ->Parameters->ParamByName("SFJE")->Value = sf;
										ValidAddRecordADOQ->Parameters->ParamByName("SYCS")->Value = ++currentrec;
										ValidAddRecordADOQ->Parameters->ParamByName("SFRQ")->Value = ValidAllRecordADOQ->FieldByName("SFRQ")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("JYNO")->Value = ValidAllRecordADOQ->FieldByName("JYNO")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("GZZID")->Value = 0;
										ValidAddRecordADOQ->Parameters->ParamByName("SFLX")->Value = "X";
										ValidAddRecordADOQ->Parameters->ParamByName("CZY")->Value = ValidAllRecordADOQ->FieldByName("CZY")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("SCRQ")->Value = ValidAllRecordADOQ->FieldByName("SCRQ")->Value;
										ValidAddRecordADOQ->ExecSQL();
										ValidAddRecordADOQ->Close();
									}
									else if((i == addcount-1)&&(1 == addcount))
									{
										ValidAddRecordADOQ->Close();
										ValidAddRecordADOQ->SQL->Clear();
										ValidAddRecordADOQ->SQL->Add(tmpSQLSTR);
										ValidAddRecordADOQ->Parameters->ParamByName("BH")->Value = ValidAllRecordADOQ->FieldByName("BH")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("KH")->Value = ValidAllRecordADOQ->FieldByName("KH")->Value;
										tmpcurrentsf -= margin;
										ValidAddRecordADOQ->Parameters->ParamByName("SF_YE")->Value = tmpcurrentsf;
										ValidAddRecordADOQ->Parameters->ParamByName("SFJE")->Value = margin;
										ValidAddRecordADOQ->Parameters->ParamByName("SYCS")->Value = ++currentrec;
										ValidAddRecordADOQ->Parameters->ParamByName("SFRQ")->Value = ValidAllRecordADOQ->FieldByName("SFRQ")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("JYNO")->Value = ValidAllRecordADOQ->FieldByName("JYNO")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("GZZID")->Value = 0;
										ValidAddRecordADOQ->Parameters->ParamByName("SFLX")->Value = "X";
										ValidAddRecordADOQ->Parameters->ParamByName("CZY")->Value = ValidAllRecordADOQ->FieldByName("CZY")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("SCRQ")->Value = ValidAllRecordADOQ->FieldByName("SCRQ")->Value;
										ValidAddRecordADOQ->ExecSQL();
										ValidAddRecordADOQ->Close();
									}
									else if((i < addcount-1)&&(addcount>2))
									{
										ValidAddRecordADOQ->Close();
										ValidAddRecordADOQ->SQL->Clear();
										ValidAddRecordADOQ->SQL->Add(tmpSQLSTR);
										ValidAddRecordADOQ->Parameters->ParamByName("BH")->Value = ValidAllRecordADOQ->FieldByName("BH")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("KH")->Value = ValidAllRecordADOQ->FieldByName("KH")->Value;
										tmpcurrentsf -= everysf;
										ValidAddRecordADOQ->Parameters->ParamByName("SF_YE")->Value = tmpcurrentsf;
										ValidAddRecordADOQ->Parameters->ParamByName("SFJE")->Value = everysf;
										ValidAddRecordADOQ->Parameters->ParamByName("SYCS")->Value = ++currentrec;
										ValidAddRecordADOQ->Parameters->ParamByName("SFRQ")->Value = ValidAllRecordADOQ->FieldByName("SFRQ")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("JYNO")->Value = ValidAllRecordADOQ->FieldByName("JYNO")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("GZZID")->Value = 0;
										ValidAddRecordADOQ->Parameters->ParamByName("SFLX")->Value = "X";
										ValidAddRecordADOQ->Parameters->ParamByName("CZY")->Value = ValidAllRecordADOQ->FieldByName("CZY")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("SCRQ")->Value = ValidAllRecordADOQ->FieldByName("SCRQ")->Value;
										ValidAddRecordADOQ->ExecSQL();
										ValidAddRecordADOQ->Close();
									}
								}
							}
							else if(margin < 0)
							{
								margin = -margin;
								everysf = ((int)margin)/addcount;
								for(int i = 0; i < addcount; i++)
								{
									if((i == addcount-1)&&(addcount>2))
									{
										float sf = margin-everysf*(addcount-1);
										ValidAddRecordADOQ->Close();
										ValidAddRecordADOQ->SQL->Clear();
										ValidAddRecordADOQ->SQL->Add(tmpSQLSTR);
										ValidAddRecordADOQ->Parameters->ParamByName("BH")->Value = ValidAllRecordADOQ->FieldByName("BH")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("KH")->Value = ValidAllRecordADOQ->FieldByName("KH")->Value;
										tmpcurrentsf += sf;
										ValidAddRecordADOQ->Parameters->ParamByName("SF_YE")->Value = tmpcurrentsf;
										ValidAddRecordADOQ->Parameters->ParamByName("SFJE")->Value = sf;
										ValidAddRecordADOQ->Parameters->ParamByName("SYCS")->Value = ++currentrec;
										ValidAddRecordADOQ->Parameters->ParamByName("SFRQ")->Value = ValidAllRecordADOQ->FieldByName("SFRQ")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("JYNO")->Value = ValidAllRecordADOQ->FieldByName("JYNO")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("GZZID")->Value = 0;
										ValidAddRecordADOQ->Parameters->ParamByName("SFLX")->Value = "I";
										ValidAddRecordADOQ->Parameters->ParamByName("CZY")->Value = ValidAllRecordADOQ->FieldByName("CZY")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("SCRQ")->Value = ValidAllRecordADOQ->FieldByName("SCRQ")->Value;
										ValidAddRecordADOQ->ExecSQL();
										ValidAddRecordADOQ->Close();
									}
									else if((i == addcount-1)&&(1 == addcount))
									{
										ValidAddRecordADOQ->Close();
										ValidAddRecordADOQ->SQL->Clear();
										ValidAddRecordADOQ->SQL->Add(tmpSQLSTR);
										ValidAddRecordADOQ->Parameters->ParamByName("BH")->Value = ValidAllRecordADOQ->FieldByName("BH")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("KH")->Value = ValidAllRecordADOQ->FieldByName("KH")->Value;
										tmpcurrentsf += margin;
										ValidAddRecordADOQ->Parameters->ParamByName("SF_YE")->Value = tmpcurrentsf;
										ValidAddRecordADOQ->Parameters->ParamByName("SFJE")->Value = margin;
										ValidAddRecordADOQ->Parameters->ParamByName("SYCS")->Value = ++currentrec;
										ValidAddRecordADOQ->Parameters->ParamByName("SFRQ")->Value = ValidAllRecordADOQ->FieldByName("SFRQ")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("JYNO")->Value = ValidAllRecordADOQ->FieldByName("JYNO")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("GZZID")->Value = 0;
										ValidAddRecordADOQ->Parameters->ParamByName("SFLX")->Value = "I";
										ValidAddRecordADOQ->Parameters->ParamByName("CZY")->Value = ValidAllRecordADOQ->FieldByName("CZY")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("SCRQ")->Value = ValidAllRecordADOQ->FieldByName("SCRQ")->Value;
										ValidAddRecordADOQ->ExecSQL();
										ValidAddRecordADOQ->Close();
									}
									else if((i < addcount-1)&&(addcount>2))
									{
										ValidAddRecordADOQ->Close();
										ValidAddRecordADOQ->SQL->Clear();
										ValidAddRecordADOQ->SQL->Add(tmpSQLSTR);
										ValidAddRecordADOQ->Parameters->ParamByName("BH")->Value = ValidAllRecordADOQ->FieldByName("BH")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("KH")->Value = ValidAllRecordADOQ->FieldByName("KH")->Value;
										tmpcurrentsf += everysf;
										ValidAddRecordADOQ->Parameters->ParamByName("SF_YE")->Value = tmpcurrentsf;
										ValidAddRecordADOQ->Parameters->ParamByName("SFJE")->Value = everysf;
										ValidAddRecordADOQ->Parameters->ParamByName("SYCS")->Value = ++currentrec;
										ValidAddRecordADOQ->Parameters->ParamByName("SFRQ")->Value = ValidAllRecordADOQ->FieldByName("SFRQ")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("JYNO")->Value = ValidAllRecordADOQ->FieldByName("JYNO")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("GZZID")->Value = 0;
										ValidAddRecordADOQ->Parameters->ParamByName("SFLX")->Value = "X";
										ValidAddRecordADOQ->Parameters->ParamByName("CZY")->Value = ValidAllRecordADOQ->FieldByName("CZY")->Value;
										ValidAddRecordADOQ->Parameters->ParamByName("SCRQ")->Value = ValidAllRecordADOQ->FieldByName("SCRQ")->Value;
										ValidAddRecordADOQ->ExecSQL();
										ValidAddRecordADOQ->Close();
									}
								}
							}
                        }
					}
				}
			}
			//end fix record
            currentcard++;
			ValidProBar->Position = currentcard*100/allcards;
			ValidAllRecordADOQ->Close();
		}
		else
		{
			currentcard++;
			ValidProBar->Position = currentcard*100/allcards;
			ValidAllRecordADOQ->Close();
		}
		ValidAllCardADOQ->Next();
	}

	ValidAllCardADOQ->Close();
	MessageBox(SDIAppForm->Handle, "数据修复完成!", "OK", MB_OK);
//	ShowMessage("数据修复完成!");
	ValidBTN->Enabled = false;
}
//---------------------------------------------------------------------------
