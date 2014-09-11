//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BTDownloadForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinValentine"
#pragma link "dxSkinXmas2008Blue"
#pragma link "cxProgressBar"
#pragma link "cxLabel"
#pragma resource "*.dfm"
TBTDownloadFrm *BTDownloadFrm;
//---------------------------------------------------------------------------
__fastcall TBTDownloadFrm::TBTDownloadFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBTDownloadFrm::ExitBTNClick(TObject *Sender)
{
	DownloadBTtag = false;
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::FormShow(TObject *Sender)
{
	btcomo = 0x00;
    btcmd = 0x43;
    ZeroMemory(btreceivebuf, 16);
    btreceivelen = 16;
    btdir = "E:\\BT";
    btdirlen = strlen(btdir);
    btPosNo = 0;

	DownloadBTtag = true;
    ExitBTN->Left = (BTDownloadFrm->Width-ExitBTN->Width)/2;
    CSPanel->Caption = "下传按消费次数生成的补贴，请点击“下传消费次数补贴”！";
    JBPanel->Caption = "下传按职务生成的补贴，请点击“下传职务补贴”！";

    BTJPARAMADOQ->Close();
    BTJPARAMADOQ->SQL->Clear();
    BTJPARAMADOQ->SQL->Add("select * from BTJPARAM");
    BTJPARAMADOQ->Open();
    if(!BTJPARAMADOQ->IsEmpty())
    {
    	ComNoEdit->Text = BTJPARAMADOQ->FieldByName("SFJPORT")->AsString;
        MachNOEdit->Text = BTJPARAMADOQ->FieldByName("JH")->AsString;
        MaxNumEdit->Text = BTJPARAMADOQ->FieldByName("MAXBTNUM")->AsString;
        MaxXFEdit->Text = BTJPARAMADOQ->FieldByName("MAXXF")->AsString;
        PasswordEdit->Text = BTJPARAMADOQ->FieldByName("PASSWORD")->AsString;
        btPosNo = BTJPARAMADOQ->FieldByName("JH")->AsInteger;
        IntToChar(BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger, &btcomo);
    }
    else
    {
        CSBTDownBTN->Enabled = false;
        JBBTDownBTN->Enabled = false;
        ShowMessage("系统中无补贴机信息,请正确填写!");
    }
    BTJPARAMADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::CSBTDownBTNClick(TObject *Sender)
{
	//派生下传消费次数补贴线程

    WORD Status;
    Status = SerReceiveFunc(btcomo,(WORD)btPosNo,btcmd,btreceivebuf,btreceivelen,1,btdir,btdirlen);
    if(0 == Status)
    {
        memset(BTSendStr1, 0xff, 8192);
        memset(BTSendStr2, 0xff, 8192);
        memset(BTSendStr3, 0xff, 8192);
        memset(BTSendStr4, 0xff, 8192);
        memset(BTSendStr5, 0xff, 8192);

        if(!CSBTDownThread||CSBTDownThread->Finished)
        {
            CSBTDownThread = new TCSBTDownThread(true,
                                                CSBTDownBTN,
                                                JBBTDownBTN,
                                                ExitBTN,
                                                CSProgressBar,
                                                CSPanel,
                                                CSBTADownDOQ);
            if(CSBTDownThread)
                CSBTDownThread->Resume();
        }
    }
    else
    	MessageBox(this->Handle, "补贴机不在线，无法进行补贴数据下传!", "Error", MB_OK|MB_ICONERROR);
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::JBBTDownBTNClick(TObject *Sender)
{
	//派生下传级别补贴线程

    WORD Status;
    Status = SerReceiveFunc(btcomo,(WORD)btPosNo,btcmd,btreceivebuf,btreceivelen,1,btdir,btdirlen);
    if(0 == Status)
    {
        memset(BTSendStr1, 0xff, 8192);
        memset(BTSendStr2, 0xff, 8192);
        memset(BTSendStr3, 0xff, 8192);
        memset(BTSendStr4, 0xff, 8192);
        memset(BTSendStr5, 0xff, 8192);

        if(!JBBTDownThread||JBBTDownThread->Finished)
        {
            JBBTDownThread = new TJBBTDownThread(true,
                                                CSBTDownBTN,
                                                JBBTDownBTN,
                                                ExitBTN,
                                                JBProgressBar,
                                                JBPanel,
                                                JBBTDownADOQ);
            if(JBBTDownThread)
                JBBTDownThread->Resume();
        }
    }
    else
    	MessageBox(this->Handle, "补贴机不在线，无法进行补贴数据下传!", "Error", MB_OK|MB_ICONERROR);
}
//---------------------------------------------------------------------------


void __fastcall TBTDownloadFrm::ComNoEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::MachNOEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::MaxNumEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::MaxXFEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::PasswordEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::SaveBTJPARAMBTNClick(TObject *Sender)
{
	if(!MachNOEdit->Text.IsEmpty()&&!ComNoEdit->Text.IsEmpty()&&
    	!MaxXFEdit->Text.IsEmpty()&&!MaxNumEdit->Text.IsEmpty()&&
        !PasswordEdit->Text.IsEmpty())
    {
        BTJPARAMADOQ->Close();
        BTJPARAMADOQ->SQL->Clear();
        BTJPARAMADOQ->SQL->Add("select * from BTJPARAM");
        BTJPARAMADOQ->Open();
        if(BTJPARAMADOQ->IsEmpty())
        {
        	BTJPARAMADOQ->Insert();
            BTJPARAMADOQ->FieldByName("JH")->AsInteger = StrToInt(MachNOEdit->Text);
            BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger = StrToInt(ComNoEdit->Text);
            BTJPARAMADOQ->FieldByName("MAXXF")->AsInteger = StrToInt(MaxXFEdit->Text);
            BTJPARAMADOQ->FieldByName("MAXBTNUM")->AsInteger = StrToInt(MaxNumEdit->Text);
            BTJPARAMADOQ->FieldByName("PASSWORD")->AsInteger = StrToInt(PasswordEdit->Text);
            BTJPARAMADOQ->Post();

            btPosNo = BTJPARAMADOQ->FieldByName("JH")->AsInteger;
        	IntToChar(BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger, &btcomo);

            CSBTDownBTN->Enabled = true;
        	JBBTDownBTN->Enabled = true;
            BTJPARAMADOQ->Close();
            ShowMessage("补贴机信息保存完毕!");
        }
        else
        {
        	BTJPARAMADOQ->Edit();
            BTJPARAMADOQ->FieldByName("JH")->AsInteger = StrToInt(MachNOEdit->Text);
            BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger = StrToInt(ComNoEdit->Text);
            BTJPARAMADOQ->FieldByName("MAXXF")->AsInteger = StrToInt(MaxXFEdit->Text);
            BTJPARAMADOQ->FieldByName("MAXBTNUM")->AsInteger = StrToInt(MaxNumEdit->Text);
            BTJPARAMADOQ->FieldByName("PASSWORD")->AsInteger = StrToInt(PasswordEdit->Text);
            BTJPARAMADOQ->Post();

            btPosNo = BTJPARAMADOQ->FieldByName("JH")->AsInteger;
        	IntToChar(BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger, &btcomo);

            CSBTDownBTN->Enabled = true;
        	JBBTDownBTN->Enabled = true;
            BTJPARAMADOQ->Close();
            ShowMessage("补贴机信息保存完毕!");
        }
    }
    else
    	ShowMessage("补贴机信息填写不完整，请完整填写!");
}
//---------------------------------------------------------------------------

void __fastcall TBTDownloadFrm::DownBTJPARAMBTNClick(TObject *Sender)
{
    BTJPARAMADOQ->Close();
    BTJPARAMADOQ->SQL->Clear();
    BTJPARAMADOQ->SQL->Add("select * from BTJPARAM");
    BTJPARAMADOQ->Open();
    if(!BTJPARAMADOQ->IsEmpty())
    {
        unsigned char CMD = 0x32;
        WORD nSendStr = 126;
        WORD status;

        unsigned char SendStr[200] = "";

        SendStr[0] = UsingSecNUM;
        SendStr[1] = 0x00; //消费类型

        SendStr[2] = DWPassword[0];
        SendStr[3] = DWPassword[1];

        SendStr[4] = 0x00;
        SendStr[5] = btPosNo;

        String PW = BTJPARAMADOQ->FieldByName("PASSWORD")->AsString;
        String Hmm = "0x" + PW.SubString(1, 2);
        String Lmm = "0x" + PW.SubString(3, 2);
        SendStr[6] = (unsigned char)StrToInt(Hmm);   //操作密码
        SendStr[7] = (unsigned char)StrToInt(Lmm);   //操作密码

        for (int i = 8; i <= 37; i++)
        {
            SendStr[i] = 0x00;        //保留
        }

        SendStr[38] = CARDPasswordEdition;//0x01; 	//密码版本

        SendStr[39] = CARDPassword[0];//0x00;     //MF卡密码？？？
        SendStr[40] = CARDPassword[1];//0x00;     //MF卡密码？？？
        SendStr[41] = CARDPassword[2];//0x00;     //MF卡密码？？？
        SendStr[42] = CARDPassword[3];//0x00;     //MF卡密码？？？
        SendStr[43] = CARDPassword[4];//0x00;     //MF卡密码？？？
        SendStr[44] = CARDPassword[5];//0x00;     //MF卡密码？？？

        int tmpmax = BTJPARAMADOQ->FieldByName("MAXXF")->AsFloat*100;      //最大消费
        SendStr[45] = (unsigned char)((int)(tmpmax/65536));
        SendStr[46] = (unsigned char)((int)((tmpmax%65536)/256));
        SendStr[47] = (unsigned char)(tmpmax%256);

        SendStr[48] = 0x00;    //固定消费金额
        SendStr[49] = 0x00;    //固定消费金额
        SendStr[50] = 0x00;    //固定消费金额

        SendStr[51] = 0x00;    //单位固定消费金额
        SendStr[52] = 0x00;    //单位固定消费金额
        SendStr[53] = 0x00;    //单位固定消费金额

        int Max1 = maxconsumption*100;
        int Max2 = maxconsumption1*100;
        int Max3 = maxconsumption2*100;
        int Max4 = maxconsumption3*100;
        int Max5 = maxconsumption4*100;

        //每天最大消费begin
        SendStr[54] = (unsigned char)((int)(Max1/65536));
        SendStr[55] = (unsigned char)((int)((Max1%65536)/256));
        SendStr[56] = (unsigned char)(Max1%256);
        for (int i = 57; i <= 89; i++)
        {
            SendStr[i] = 0x00;
        }

        SendStr[90] = (unsigned char)((int)(Max2/65536));
        SendStr[91] = (unsigned char)((int)((Max2%65536)/256));
        SendStr[92] = (unsigned char)(Max2%256);

        SendStr[93] = (unsigned char)((int)(Max3/65536));
        SendStr[94] = (unsigned char)((int)((Max3%65536)/256));
        SendStr[95] = (unsigned char)(Max3%256);

        SendStr[96] = (unsigned char)((int)(Max4/65536));
        SendStr[97] = (unsigned char)((int)((Max4%65536)/256));
        SendStr[98] = (unsigned char)(Max4%256);

        SendStr[99] = (unsigned char)((int)(Max5/65536));
        SendStr[100] = (unsigned char)((int)((Max5%65536)/256));
        SendStr[101] = (unsigned char)(Max5%256);

        status = SerSendFunc((unsigned char)(BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger),
                             WORD(BTJPARAMADOQ->FieldByName("JH")->AsInteger),
                             CMD,
                             SendStr,
                             nSendStr,
                             1);
        if(0 == status)
        {
        	CMD = 0x31;
            String datestr = DateTimeToStr(Now());
            char* timepstr = datestr.t_str();

            SendStr[0] = (unsigned char)(((int)timepstr[2]-48)*16+(int)timepstr[3]-48);
            SendStr[1] = (unsigned char)(((int)timepstr[5]-48)*16+(int)timepstr[6]-48);
            SendStr[2] = (unsigned char)(((int)timepstr[8]-48)*16+(int)timepstr[9]-48);

            if(19 == datestr.Length())
            {
                SendStr[3] = (unsigned char)(((int)timepstr[11]-48)*16+(int)timepstr[12]-48);
                SendStr[4] = (unsigned char)(((int)timepstr[14]-48)*16+(int)timepstr[15]-48);
                SendStr[5] = (unsigned char)(((int)timepstr[17]-48)*16+(int)timepstr[18]-48);
            }
            else
            {
                SendStr[3] = (unsigned char)((int)timepstr[11]-48);
                SendStr[4] = (unsigned char)(((int)timepstr[13]-48)*16+(int)timepstr[14]-48);
                SendStr[5] = (unsigned char)(((int)timepstr[16]-48)*16+(int)timepstr[17]-48);
            }

            nSendStr = 8;

            status = SerSendFunc((unsigned char)(BTJPARAMADOQ->FieldByName("SFJPORT")->AsInteger),
                                WORD(BTJPARAMADOQ->FieldByName("JH")->AsInteger),
                                CMD,
                                SendStr,
                                nSendStr,
                                1);
		}
		else
		{
			MessageBox(this->Handle, "补贴机异常!", "Error", MB_OK|MB_ICONERROR);
		}
    }
	else
		MessageBox(this->Handle, "数据库没用补贴机信息!", "Error", MB_OK|MB_ICONERROR);

    BTJPARAMADOQ->Close();
}
//---------------------------------------------------------------------------


