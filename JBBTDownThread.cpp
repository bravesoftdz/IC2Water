//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JBBTDownThread.h"
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
//      void __fastcall TJBBTDownThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TJBBTDownThread::TJBBTDownThread(bool CreateSuspended,
											TcxButton* CSDownBTN,
                                            TcxButton* JBDownBTN,
                                            TcxButton* EBTN,
                                            TcxProgressBar* JBProBar,
                                            TPanel* JBBTPanel,
                                            TADOQuery* JBADOQ) : TThread(CreateSuspended)
{
	ValidCSDownBTN = CSDownBTN;
    ValidJBDownBTN = JBDownBTN;
    ValidEBTN = EBTN;
    ValidJBProBar = JBProBar;
    ValidJBBTPanel = JBBTPanel;
    ValidJBADOQ = JBADOQ;
}
//---------------------------------------------------------------------------
void __fastcall TJBBTDownThread::Execute()
{
	//---- Place thread code here ----
    ValidCSDownBTN->Enabled = false;
    ValidJBDownBTN->Enabled = false;
    ValidEBTN->Enabled = false;

    unsigned char COMNUM;
    WORD BTJNUM;
    unsigned char CMD = 0x44;

    String datestr = DateToStr(Now());
    char* datestrptr = datestr.t_str();
    SYSTEMTIME st;
    DateTimeToSystemTime(Now(), st);
    unsigned char downyear = (unsigned char)(((int)datestrptr[2]-48)*16+((int)datestrptr[3]-48));
    unsigned char tmpchar = st.wMonth;
    unsigned char downmonth = 0xf0|tmpchar;

    ValidJBADOQ->Close();
    ValidJBADOQ->SQL->Clear();
    ValidJBADOQ->SQL->Add("select * from BTJPARAM");
    ValidJBADOQ->Open();
    if(1 == ValidJBADOQ->RecordCount)
    {
    	COMNUM = ValidJBADOQ->FieldByName("SFJPORT")->AsInteger;
        BTJNUM = ValidJBADOQ->FieldByName("JH")->AsInteger;
    }
    else
    {
        MessageBox(SDIAppForm->Handle, "系统数据库中不存在补贴机信息或存在多台补贴机信息，不能进行补贴数据下传，请联系技术人员!",
        			"Error", MB_OK|MB_ICONERROR);
        return;
    }

    ValidJBADOQ->Close();
    ValidJBADOQ->SQL->Clear();
    ValidJBADOQ->SQL->Add("select * from BTTemp2");
    ValidJBADOQ->Open();
    if(ValidJBADOQ->IsEmpty())
    {
        MessageBox(SDIAppForm->Handle, "系统中没有生成按职务的补贴记录，请先进行补贴生成!",
        			"Error", MB_OK|MB_ICONERROR);
        ValidJBADOQ->Close();

        ValidCSDownBTN->Enabled = true;
        ValidJBDownBTN->Enabled = true;
        ValidEBTN->Enabled = true;
        return;
    }
    else
    {
    	ValidJBBTPanel->Caption = "提取补贴记录转换成补贴机数据，操作中...";
    	ValidJBADOQ->First();
        int recordtag = 1;
        int allrecordcount = ValidJBADOQ->RecordCount;
        ValidJBProBar->Position = 0;

        while(!ValidJBADOQ->Eof)
        {
        	if(recordtag <= 1008)
            {
            	BTSendStr1[124] = (unsigned char)(recordtag/256);
                BTSendStr1[125] = (unsigned char)(recordtag%256);

                BTSendStr1[64] = 0x20;
                BTSendStr1[65] = 0x07;
                BTSendStr1[66] = 0x01;
                BTSendStr1[67] = 0x01;

                BTSendStr1[128+recordtag*8] = downyear;
				BTSendStr1[128+recordtag*8+7] = downmonth;
				BTSendStr1[128+recordtag*8+7] |= 0xa0;

                int tmpkh = ValidJBADOQ->FieldByName("KH")->AsInteger;
                BTSendStr1[128+recordtag*8+1] = (unsigned char)((tmpkh&0x00FF0000)>>16);
                BTSendStr1[128+recordtag*8+2] = (unsigned char)((tmpkh%0x0000FF00)>>8);
                BTSendStr1[128+recordtag*8+3] = (unsigned char)(tmpkh&0x000000FF);

                int tmpbonus = ValidJBADOQ->FieldByName("Bonus")->AsInteger;
                BTSendStr1[128+recordtag*8+4] = (unsigned char)((tmpbonus&0x00FF0000)>>16);
                BTSendStr1[128+recordtag*8+5] = (unsigned char)((tmpbonus%0x0000FF00)>>8);
                BTSendStr1[128+recordtag*8+6] = (unsigned char)(tmpbonus&0x000000FF);
            }
            else if((recordtag <= 2016)&&(recordtag > 1008))
            {
            	BTSendStr2[124] = (unsigned char)((recordtag-1008)/256);
                BTSendStr2[125] = (unsigned char)((recordtag-1008)%256);

                BTSendStr2[64] = 0x20;
                BTSendStr2[65] = 0x07;
                BTSendStr2[66] = 0x02;
                BTSendStr2[67] = 0x02;

                BTSendStr2[128+(recordtag-1008)*8] = downyear;
				BTSendStr2[128+(recordtag-1008)*8+7] = downmonth;
				BTSendStr2[128+(recordtag-1008)*8+7] |= 0xa0;

                int tmpkh = ValidJBADOQ->FieldByName("KH")->AsInteger;
                BTSendStr2[128+(recordtag-1008)*8+1] = (unsigned char)((tmpkh&0x00FF0000)>>16);
                BTSendStr2[128+(recordtag-1008)*8+2] = (unsigned char)((tmpkh%0x0000FF00)>>8);
                BTSendStr2[128+(recordtag-1008)*8+3] = (unsigned char)(tmpkh&0x000000FF);

                int tmpbonus = ValidJBADOQ->FieldByName("Bonus")->AsInteger;
                BTSendStr2[128+(recordtag-1008)*8+4] = (unsigned char)((tmpbonus&0x00FF0000)>>16);
                BTSendStr2[128+(recordtag-1008)*8+5] = (unsigned char)((tmpbonus%0x0000FF00)>>8);
                BTSendStr2[128+(recordtag-1008)*8+6] = (unsigned char)(tmpbonus&0x000000FF);
            }
            else if((recordtag <= 3024)&&(recordtag > 2016))
            {
            	BTSendStr3[124] = (unsigned char)((recordtag-2016)/256);
                BTSendStr3[125] = (unsigned char)((recordtag-2016)%256);

                BTSendStr3[64] = 0x20;
                BTSendStr3[65] = 0x07;
                BTSendStr3[66] = 0x03;
                BTSendStr3[67] = 0x03;

                BTSendStr3[128+(recordtag-2016)*8] = downyear;
				BTSendStr3[128+(recordtag-2016)*8+7] = downmonth;
				BTSendStr3[128+(recordtag-2016)*8+7] |= 0xa0;

                int tmpkh = ValidJBADOQ->FieldByName("KH")->AsInteger;
                BTSendStr3[128+(recordtag-2016)*8+1] = (unsigned char)((tmpkh&0x00FF0000)>>16);
                BTSendStr3[128+(recordtag-2016)*8+2] = (unsigned char)((tmpkh%0x0000FF00)>>8);
                BTSendStr3[128+(recordtag-2016)*8+3] = (unsigned char)(tmpkh&0x000000FF);

                int tmpbonus = ValidJBADOQ->FieldByName("Bonus")->AsInteger;
                BTSendStr3[128+(recordtag-2016)*8+4] = (unsigned char)((tmpbonus&0x00FF0000)>>16);
                BTSendStr3[128+(recordtag-2016)*8+5] = (unsigned char)((tmpbonus%0x0000FF00)>>8);
                BTSendStr3[128+(recordtag-2016)*8+6] = (unsigned char)(tmpbonus&0x000000FF);
            }
            else if((recordtag <= 4032)&&(recordtag > 3024))
            {
            	BTSendStr4[124] = (unsigned char)((recordtag-3024)/256);
                BTSendStr4[125] = (unsigned char)((recordtag-3024)%256);

                BTSendStr4[64] = 0x20;
                BTSendStr4[65] = 0x07;
                BTSendStr4[66] = 0x04;
                BTSendStr4[67] = 0x04;

                BTSendStr4[128+(recordtag-3024)*8] = downyear;
				BTSendStr4[128+(recordtag-3024)*8+7] = downmonth;
				BTSendStr4[128+(recordtag-3024)*8+7] |= 0xa0;

                int tmpkh = ValidJBADOQ->FieldByName("KH")->AsInteger;
                BTSendStr4[128+(recordtag-3024)*8+1] = (unsigned char)((tmpkh&0x00FF0000)>>16);
                BTSendStr4[128+(recordtag-3024)*8+2] = (unsigned char)((tmpkh%0x0000FF00)>>8);
                BTSendStr4[128+(recordtag-3024)*8+3] = (unsigned char)(tmpkh&0x000000FF);

                int tmpbonus = ValidJBADOQ->FieldByName("Bonus")->AsInteger;
                BTSendStr4[128+(recordtag-3024)*8+4] = (unsigned char)((tmpbonus&0x00FF0000)>>16);
                BTSendStr4[128+(recordtag-3024)*8+5] = (unsigned char)((tmpbonus%0x0000FF00)>>8);
                BTSendStr4[128+(recordtag-3024)*8+6] = (unsigned char)(tmpbonus&0x000000FF);
            }
            else if((recordtag <= 5040)&&(recordtag > 4032))
            {
            	BTSendStr5[124] = (unsigned char)((recordtag-4032)/256);
                BTSendStr5[125] = (unsigned char)((recordtag-4032)%256);

                BTSendStr5[64] = 0x20;
                BTSendStr5[65] = 0x07;
                BTSendStr5[66] = 0x05;
                BTSendStr5[67] = 0x05;

                BTSendStr5[128+(recordtag-4032)*8] = downyear;
				BTSendStr5[128+(recordtag-4032)*8+7] = downmonth;
				BTSendStr5[128+(recordtag-4032)*8+7] |= 0xa0;

                int tmpkh = ValidJBADOQ->FieldByName("KH")->AsInteger;
                BTSendStr5[128+(recordtag-4032)*8+1] = (unsigned char)((tmpkh&0x00FF0000)>>16);
                BTSendStr5[128+(recordtag-4032)*8+2] = (unsigned char)((tmpkh%0x0000FF00)>>8);
                BTSendStr5[128+(recordtag-4032)*8+3] = (unsigned char)(tmpkh&0x000000FF);

                int tmpbonus = ValidJBADOQ->FieldByName("Bonus")->AsInteger;
                BTSendStr5[128+(recordtag-4032)*8+4] = (unsigned char)((tmpbonus&0x00FF0000)>>16);
                BTSendStr5[128+(recordtag-4032)*8+5] = (unsigned char)((tmpbonus%0x0000FF00)>>8);
                BTSendStr5[128+(recordtag-4032)*8+6] = (unsigned char)(tmpbonus&0x000000FF);
            }
			ValidJBProBar->Position = recordtag*100/allrecordcount;
			recordtag++;
			ValidJBADOQ->Next();
		}
		Sleep(500);
		ValidJBBTPanel->Caption = "补贴机数据转换完毕，补贴数据下传中...";
        ValidJBProBar->Position = 0;
        //

		int Status = -1;
        if(allrecordcount <= 1008)
		{
			ValidJBBTPanel->Caption =  "<1008";
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr1, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 100;
        }

		if((allrecordcount <= 2016)&&(allrecordcount > 1008))
		{
			ValidJBBTPanel->Caption =  "<2016";
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr1, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 50;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr2, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
			ValidJBProBar->Position = 100;
        }

        if((allrecordcount <= 3024)&&(allrecordcount > 2016))
		{
			ValidJBBTPanel->Caption =  "<3024";
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr1, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 33;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr2, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 66;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr3, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 100;
        }

        if((allrecordcount <= 4032)&&(allrecordcount > 3024))
		{
			ValidJBBTPanel->Caption =  "<4032";
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr1, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 25;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr2, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 50;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr3, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 75;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr4, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 100;
        }

        if((allrecordcount <= 5040)&&(allrecordcount > 4032))
		{
			ValidJBBTPanel->Caption =  "<5040";
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr1, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 20;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr2, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 40;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr3, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 60;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr4, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
			Sleep(500);
            ValidJBProBar->Position = 80;
			Status = SerSendFunc(COMNUM, BTJNUM, CMD, BTSendStr5, 8192, 1);
			if(Status)
			{
				MessageBox(SDIAppForm->Handle, IntToStr(Status).t_str(), "Error", MB_OK|MB_ICONINFORMATION);
				MessageBox(SDIAppForm->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONINFORMATION);
				ValidEBTN->Enabled = true;
				return;
			}
            Sleep(500);
            ValidJBProBar->Position = 100;
        }

        ValidJBADOQ->Close();
        ValidJBADOQ->SQL->Clear();
        String Copysqlstr = "insert into BTJB select BH,KH,Bonus,ZW,CreateDate,January,February,March,April,May,June,July,August,September,October,November,December,'";
        Copysqlstr += OperatorName;
        Copysqlstr += "','";
        Copysqlstr += DateTimeToStr(Now());
        Copysqlstr += "' from BTTemp2";
        ValidJBADOQ->SQL->Add(Copysqlstr);
        ValidJBADOQ->ExecSQL();
        ValidJBADOQ->Close();
        ValidJBADOQ->SQL->Clear();
        ValidJBADOQ->SQL->Add("delete from BTTemp2");
        ValidJBADOQ->ExecSQL();
        ValidJBADOQ->Close();

        ValidJBBTPanel->Caption = "补贴数据下传完毕，请及时通知用户进行补贴充值!";
		MessageBox(SDIAppForm->Handle, "补贴数据下传成功!", "Successfully", MB_OK|MB_ICONINFORMATION);
		ValidCSDownBTN->Enabled = true;
        ValidJBDownBTN->Enabled = true;
		ValidEBTN->Enabled = true;
    }
}
//---------------------------------------------------------------------------
