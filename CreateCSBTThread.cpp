//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CreateCSBTThread.h"
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
//      void __fastcall TCreateCSBTThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCreateCSBTThread::TCreateCSBTThread(bool CreateSuspended,
												TcxButton* CSBTN,
                                                TcxButton* JEBTN,
                                                TcxButton* JBBTN,
                                                TcxButton* EBTN,
                                                TcxProgressBar* CSProBar,
                                                TADOQuery* CSADOQ,
                                				TADOQuery* CSInADOQ,
                                                String Beginstr,
                                                String Endstr,
                                                int everytimeje,
                                				int maxtime) : TThread(CreateSuspended)
{
	ValidCSBTN = CSBTN;
    ValidJEBTN = JEBTN;
    ValidJBBTN = JBBTN;
    ValidEBTN = EBTN;
    ValidCSProBar = CSProBar;
    ValidCSADOQ = CSADOQ;
    ValidCSInADOQ = CSInADOQ;
    ValidBeginstr = Beginstr;
    ValidEndstr = Endstr;
    Valideverytimeje = everytimeje;
    Validmaxtime = maxtime;
}
//---------------------------------------------------------------------------
void __fastcall TCreateCSBTThread::Execute()
{
	//---- Place thread code here ----
    //select MX.KH,Count(MX.KH) as cns from MXBAK join CARD on MX.BH=CARD.BH where CARD.ZT='发卡' group by MX.KH

    ValidCSBTN->Enabled = false;
    ValidJEBTN->Enabled = false;
    ValidJBBTN->Enabled = false;
    ValidEBTN->Enabled = false;

    String checksqlstr = "select count(*) as testcns from BTTemp1";
    ValidCSADOQ->Close();
    ValidCSADOQ->SQL->Clear();
    ValidCSADOQ->SQL->Add(checksqlstr);
    ValidCSADOQ->Open();
    if(ValidCSADOQ->FieldByName("testcns")->AsInteger>0)
    {
        if(IDOK == MessageBox(SDIAppForm->Handle, "系统中存有上次生成且未下传的补贴,如继续生成将删除上次生成的补贴!", "Error",
        						MB_OKCANCEL|MB_ICONERROR))
        {
        	String delsqlstr = "delete from BTTemp1";
            ValidCSADOQ->Close();
            ValidCSADOQ->SQL->Clear();
            ValidCSADOQ->SQL->Add(delsqlstr);
            ValidCSADOQ->ExecSQL();
            ValidCSADOQ->Close();
            ValidCSADOQ->SQL->Clear();
            ValidCSADOQ->SQL->Add("select * from BTTemp1");
            if(!ValidCSADOQ->IsEmpty())
            {
            	MessageBox(SDIAppForm->Handle, "无法删除一次生成且未下传的补贴，无法继续生成补贴!",
                			"Error", MB_OK|MB_ICONERROR);
                ValidCSBTN->Enabled = true;
                ValidJEBTN->Enabled = true;
                ValidJBBTN->Enabled = true;
                ValidEBTN->Enabled = true;
                ValidCSADOQ->Close();
                return;
            }
            ValidCSADOQ->Close();
        }
        else
        {
            ValidCSADOQ->Close();
            ValidCSBTN->Enabled = true;
            ValidJEBTN->Enabled = true;
            ValidJBBTN->Enabled = true;
            ValidEBTN->Enabled = true;
            return;
        }
    }

	String Fresqlstr = "select MXBAK.KH,MXBAK.BH,Count(MXBAK.KH) as cns from MXBAK join CARD_F on MXBAK.BH=CARD_F.BH where CARD_F.ZT='发卡' and MXBAK.SFRQ>'";
    Fresqlstr += ValidBeginstr;
    Fresqlstr += "' and  MXBAK.SFRQ<'";
    Fresqlstr += ValidEndstr;
    Fresqlstr += "' and MXBAK.SFLX='X' group by MXBAK.KH,MXBAK.BH order by MXBAK.KH";

    ValidCSADOQ->Close();
    ValidCSADOQ->SQL->Clear();
    ValidCSADOQ->SQL->Add(Fresqlstr);
    ValidCSADOQ->Open();
    if(!ValidCSADOQ->IsEmpty())
    {
        BTCreatetimestr = DateTimeToStr(Now());
        int allrec = ValidCSADOQ->RecordCount;
        int currentrec = 0;
        insertsqlstr = "insert into BTTemp1 values(:BH,:KH,:Bonus,:CreateDate,:UserName)";
        ValidCSADOQ->First();
        ValidCSProBar->Position = 0;
        while(!ValidCSADOQ->Eof)
        {
        	Synchronize(CreateOneBonusFunc);
            currentrec++;
            ValidCSProBar->Position = currentrec*100/allrec;
            ValidCSADOQ->Next();
        }
    }
    else
    {
        MessageBox(SDIAppForm->Handle, "该时间范围内没有消费记录，所以没有按消费次数的补贴!", "Error", MB_OK|MB_ICONERROR);
    }
    ValidCSADOQ->Close();
    MessageBox(SDIAppForm->Handle, "生成消费次数补贴成功!", "Successfully", MB_OK|MB_ICONINFORMATION);
    ValidCSBTN->Enabled = true;
    ValidJEBTN->Enabled = true;
    ValidJBBTN->Enabled = true;
    ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCreateCSBTThread::CreateOneBonusFunc()
{
	int Bonus = 0;
    String BHstr = ValidCSADOQ->FieldByName("BH")->AsAnsiString.Trim();
    int KH = ValidCSADOQ->FieldByName("KH")->AsInteger;

    int XFCS = ValidCSADOQ->FieldByName("cns")->AsInteger;
    if(XFCS>=Validmaxtime)
    {
        Bonus = Valideverytimeje*Validmaxtime;
    }
    else
    {
        Bonus = Valideverytimeje*XFCS;
    }

    ValidCSInADOQ->Close();
    ValidCSInADOQ->SQL->Clear();
    ValidCSInADOQ->SQL->Add(insertsqlstr);
    ValidCSInADOQ->Parameters->ParamByName("BH")->Value = BHstr;
    ValidCSInADOQ->Parameters->ParamByName("KH")->Value = KH;
    ValidCSInADOQ->Parameters->ParamByName("Bonus")->Value = Bonus;
    ValidCSInADOQ->Parameters->ParamByName("CreateDate")->Value = BTCreatetimestr;
    ValidCSInADOQ->Parameters->ParamByName("UserName")->Value = OperatorName;
    ValidCSInADOQ->ExecSQL();
    return;
}
