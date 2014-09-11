//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DisplayTJThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TDisplayTJThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TDisplayTJThread::TDisplayTJThread(bool CreateSuspended,
											  TListView *LV,
											  TButton *EBTN,
                                              TcxButton *QBTN,
                                              TcxButton *ExitBTN,
											  TEdit* TJEdit,
											  TADOQuery* ADOQL,
											  TADOQuery* ADOQH,
											  TADOQuery* ADOQJH) : TThread(CreateSuspended)
{
	ValidLV = LV;
	ValidEBTN = EBTN;
    ValidQBTN = QBTN;
    ValidExitBTN = ExitBTN;
	ValidTJEdit = TJEdit;
	ValidADOQL = ADOQL;
	ValidADOQH = ADOQH;
	ValidADOQJH = ADOQJH;
}
//---------------------------------------------------------------------------
void __fastcall TDisplayTJThread::Execute()
{
	//---- Place thread code here ----
    ValidEBTN->Enabled = false;
    ValidQBTN->Enabled = false;
    ValidExitBTN->Enabled = false;
	double ze = 0;
	ValidADOQL->First();
	ValidADOQH->First();
	ValidADOQJH->First();
	while(!ValidADOQJH->Eof)
	{
		if(!Terminated)
		{
			int ljh = ValidADOQL->FieldByName("JH")->AsInteger;
			int hjh = ValidADOQH->FieldByName("JH")->AsInteger;
			int jh = ValidADOQJH->FieldByName("JH")->AsInteger;
			if((jh == hjh)&&(jh == ljh))
			{
				//正常消费数据,all->next
				double lxf = ValidADOQL->FieldByName("xflow")->AsFloat;
				double hxf = ValidADOQH->FieldByName("xfhigh")->AsFloat;

				TListItem* tmpitem = ValidLV->Items->Add();
				tmpitem->Caption = IntToStr(jh);
				if((hxf-lxf)>0)
				{
					tmpitem->SubItems->Add(FloatToStr(hxf-lxf));
					ze += (hxf-lxf);
				}
				else
				{
					tmpitem->SubItems->Add("0");
					ValidLV->Canvas->Font->Color = clRed;
				}
				ValidADOQL->Next();
				ValidADOQH->Next();
				ValidADOQJH->Next();
			}
			else if((jh < hjh)&&(jh < ljh)&&(hjh == ljh))
			{
				//ValidADOQJH->next
				TListItem* tmpitem = ValidLV->Items->Add();
				tmpitem->Caption = IntToStr(jh);
				tmpitem->SubItems->Add("0");
				ValidLV->Canvas->Font->Color = clRed;
				ValidADOQJH->Next();
			}
			else if((jh >hjh)&&(jh > ljh)&&(hjh == ljh))
			{
				//ValidADOQL,ValidADOQH->next
				TListItem* tmpitem = ValidLV->Items->Add();
				tmpitem->Caption = IntToStr(jh);
				tmpitem->SubItems->Add("0");
				ValidLV->Canvas->Font->Color = clRed;
				ValidADOQL->Next();
				ValidADOQH->Next();
			}
			else if((jh == hjh)&&(jh <ljh))
			{
				//ValidADOQJH,ValidADOQH->next
				double hxf = ValidADOQH->FieldByName("xfhigh")->AsFloat;
				ze += hxf;

				TListItem* tmpitem = ValidLV->Items->Add();
				tmpitem->Caption = IntToStr(jh);
				tmpitem->SubItems->Add(FloatToStr(hxf));
				ValidADOQH->Next();
				ValidADOQJH->Next();
			}
			else if((jh == hjh)&&(0 == ljh))
			{
				double hxf = ValidADOQH->FieldByName("xfhigh")->AsFloat;
				ze += hxf;

				TListItem* tmpitem = ValidLV->Items->Add();
				tmpitem->Caption = IntToStr(jh);
				tmpitem->SubItems->Add(FloatToStr(hxf));
				ValidADOQH->Next();
				ValidADOQJH->Next();
			}
            else if((jh == hjh)&&(jh > ljh))
            {
				double hxf = ValidADOQH->FieldByName("xfhigh")->AsFloat;
				ze += hxf;

				TListItem* tmpitem = ValidLV->Items->Add();
				tmpitem->Caption = IntToStr(jh);
				tmpitem->SubItems->Add(FloatToStr(hxf));
				ValidADOQH->Next();
				ValidADOQJH->Next();
            }
			ValidTJEdit->Text = ze;
		}
		else
		{
			ValidADOQL->Close();
			ValidADOQH->Close();
			ValidADOQJH->Close();
			return;
		}
	}
	ValidADOQL->Close();
	ValidADOQH->Close();
	ValidADOQJH->Close();
	if(ValidLV->Items->Count > 0)
	{
    	ValidEBTN->Enabled = true;
	}
    ValidQBTN->Enabled = true;
    ValidExitBTN->Enabled = true;
}
//---------------------------------------------------------------------------
