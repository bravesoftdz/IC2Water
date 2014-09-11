//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
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
#pragma resource "*.dfm"
TLoginFrom *LoginFrom;

//---------------------------------------------------------------------------
__fastcall TLoginFrom::TLoginFrom(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TLoginFrom::cxButton2Click(TObject *Sender)
{
	exit(1);
}
//---------------------------------------------------------------------------

void __fastcall TLoginFrom::FormCreate(TObject *Sender)
{
	LoginADOQ->Close();
	LoginADOQ->SQL->Clear();
	LoginADOQ->SQL->Add("select * from GROUPINFO");
	LoginADOQ->Open();
	cxLabel4->Caption = SYSTEMDISPLAYNAME.SubString(1, SYSTEMDISPLAYNAME.Length());
//	ShowMessage(SYSTEMDISPLAYNAME);
	cxLabel4->Left = (LoginFrom->Width-cxLabel4->Width)/2;
	if(!LoginADOQ->IsEmpty())
	{
		LoginADOQ->First();
        GroupComboBox->Properties->Items->Clear();
  //		GroupComboBox->Properties->Items->Add(LoginADOQ->FieldByName("GROUPNAME")->AsAnsiString);
		while(!LoginADOQ->Eof)
		{
			GroupComboBox->Properties->Items->Add(LoginADOQ->FieldByName("GROUPNAME")->AsString.Trim());
			LoginADOQ->Next();
		}
	}
	else
	{
		ShowMessage("该系统没有进行正确的初始化，数据库中不存在用户，请联系管理员!");
		exit(1);
    }
	LoginADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLoginFrom::cxButton1Click(TObject *Sender)
{
	if(NameEdit->Text.IsEmpty())
	{
		ShowMessage("用户名不能为空!");
	}
	else if(PassWordEdit->Text.IsEmpty())
	{
		ShowMessage("密码不能为空!");
	}
	else if(GroupComboBox->Text.IsEmpty())
	{
		ShowMessage("工作组不能为空！");
	}

	if(!(NameEdit->Text.IsEmpty())&&8==PassWordEdit->Text.Length()&&!(GroupComboBox->Text.IsEmpty()))
	{
    	char OLPW[8];
        char ENPW[9];
        ZeroMemory(OLPW, 8);
        ZeroMemory(ENPW, 9);
        String tmppwstr = PassWordEdit->Text;
        for(int i=0; i<4; i++)
        {
            int tmpint = StrToInt("0x"+tmppwstr.SubString(i*2+1, 2));
        	IntToUChar(tmpint, &OLPW[i]);
        }
        EncrptyCardMMProc(0, OLPW, ENPW);

        char Inbasechar[17];
        ZeroMemory(Inbasechar, 17);
        for(int t = 0; t<8; t++)
        {
            char tmp;
            tmp = ENPW[t]>>4;
            tmp = tmp&0x0f;
            if(tmp >= 10)
                Inbasechar[t*2] = tmp+55;
            if(tmp <10)
                Inbasechar[t*2] = tmp+48;
            tmp = ENPW[t]&0x0f;
            if(tmp >= 10)
                Inbasechar[t*2+1] = tmp+55;
            if(tmp <10)
                Inbasechar[t*2+1] = tmp+48;
        }

        String stortstr = Inbasechar;

		LoginADOQ->Close();
		LoginADOQ->SQL->Clear();
		String sqlstr = "select * from SYSUSER where USERNAME='";
		sqlstr += NameEdit->Text;
		sqlstr += "' and PASSWORD='";
		sqlstr += Inbasechar;
		sqlstr += "' and GROUPNAME='";
		sqlstr += GroupComboBox->Text;
		sqlstr += "'";
		LoginADOQ->SQL->Add(sqlstr);
 //		ShowMessage(sqlstr);
		LoginADOQ->Open();

		String DateofLogin;
		SYSTEMTIME tmpsystime;
		GetLocalTime(&tmpsystime);
		DateofLogin = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

		if(!LoginADOQ->IsEmpty())
		{
			OperatorGroupName = GroupComboBox->Text;
			OperatorName = NameEdit->Text;

			String qxstr = LoginADOQ->FieldByName("priority")->AsString.Trim();
			char* everyqx = new char[50];
			ZeroMemory(everyqx, 50);
			if(qxstr != "")
			{
				strcpy(everyqx, qxstr.t_str());
			}
			else
			{
				if(OperatorGroupName == "操作员")
					strcpy(everyqx,"00111111011111011111100111111111111111111111111");
				if(OperatorGroupName == "系统管理员")
					strcpy(everyqx,"11111111111111111111111111111111111111111111111");
            }

			ZeroMemory(globalqx, 50);
			strcpy(globalqx, everyqx);
			//分配权限
			if('1' == everyqx[0])
				SDIAppForm->dxNavBar1Item1->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item1->Enabled = false;

			if('1' == everyqx[1])
				SDIAppForm->dxNavBar1Item2->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item2->Enabled = false;

			if('1' == everyqx[2])
				SDIAppForm->dxNavBar1Item5->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item5->Enabled = false;

			if('1' == everyqx[3])
				SDIAppForm->dxNavBar1Item6->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item6->Enabled = false;

			if('1' == everyqx[4])
				SDIAppForm->dxNavBar1Item8->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item8->Enabled = false;

			if('1' == everyqx[5])
				SDIAppForm->dxNavBar1Item10->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item10->Enabled = false;

			if('1' == everyqx[6])
				SDIAppForm->dxNavBar1Item11->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item11->Enabled = false;

			if('1' == everyqx[7])
				SDIAppForm->dxNavBar1Item9->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item9->Enabled = false;

			if('1' == everyqx[8])
				SDIAppForm->dxNavBar1Item31->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item31->Enabled = false;

			if('1' == everyqx[9])
				SDIAppForm->dxNavBar1Item35->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item35->Enabled = false;

			if('1' == everyqx[10])
				SDIAppForm->dxNavBar1Item12->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item12->Enabled = false;

			if('1' == everyqx[11])
				SDIAppForm->dxNavBar1Item13->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item13->Enabled = false;

			if('1' == everyqx[12])
				SDIAppForm->dxNavBar1Item27->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item27->Enabled = false;

			if('1' == everyqx[13])
				SDIAppForm->dxNavBar1Item37->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item37->Enabled = false;

			if('1' == everyqx[14])
				SDIAppForm->dxNavBar1Item40->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item40->Enabled = false;

			if('1' == everyqx[15])
				SDIAppForm->dxNavBar1Item28->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item28->Enabled = false;

			if('1' == everyqx[16])
				SDIAppForm->dxNavBar1Item22->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item22->Enabled = false;

			if('1' == everyqx[17])
				SDIAppForm->dxNavBar1Item23->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item23->Enabled = false;

			if('1' == everyqx[18])
				SDIAppForm->dxNavBar1Item24->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item24->Enabled = false;

			if('1' == everyqx[19])
				SDIAppForm->dxNavBar1Item25->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item25->Enabled = false;

			if('1' == everyqx[20])
				SDIAppForm->dxNavBar1Item36->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item36->Enabled = false;

			if('1' == everyqx[21])
				SDIAppForm->dxNavBar1Item18->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item18->Enabled = false;

			if('1' == everyqx[22])
				SDIAppForm->dxNavBar1Item19->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item19->Enabled = false;

			if('1' == everyqx[23])
				SDIAppForm->dxNavBar1Item41->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item41->Enabled = false;

			if('1' == everyqx[24])
				SDIAppForm->dxNavBar1Item42->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item42->Enabled = false;

			if('1' == everyqx[25])
				SDIAppForm->dxNavBar1Item43->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item43->Enabled = false;

			if('1' == everyqx[26])
				SDIAppForm->dxNavBar1Item16->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item16->Enabled = false;

			if('1' == everyqx[27])
				SDIAppForm->dxNavBar1Item44->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item44->Enabled = false;

			if('1' == everyqx[28])
				SDIAppForm->dxNavBar1Item45->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item45->Enabled = false;

			if('1' == everyqx[29])
				SDIAppForm->dxNavBar1Item46->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item46->Enabled = false;

			if('1' == everyqx[30])
				SDIAppForm->dxNavBar1Item47->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item47->Enabled = false;

			if('1' == everyqx[31])
				SDIAppForm->dxNavBar1Item48->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item48->Enabled = false;

			if('1' == everyqx[32])
				SDIAppForm->dxNavBar1Item49->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item49->Enabled = false;

			if('1' == everyqx[33])
				SDIAppForm->dxNavBar1Item50->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item50->Enabled = false;

			if('1' == everyqx[34])
				SDIAppForm->dxNavBar1Item15->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item15->Enabled = false;

			if('1' == everyqx[35])
				SDIAppForm->dxNavBar1Item51->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item51->Enabled = false;

			if('1' == everyqx[36])
				SDIAppForm->dxNavBar1Item52->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item52->Enabled = false;

			if('1' == everyqx[37])
				SDIAppForm->dxNavBar1Item53->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item53->Enabled = false;

			if('1' == everyqx[38])
				SDIAppForm->dxNavBar1Item57->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item57->Enabled = false;

			if('1' == everyqx[39])
				SDIAppForm->dxNavBar1Item54->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item54->Enabled = false;

			if('1' == everyqx[40])
				SDIAppForm->dxNavBar1Item56->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item56->Enabled = false;

			if('1' == everyqx[41])
				SDIAppForm->dxNavBar1Item39->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item39->Enabled = false;

			if('1' == everyqx[42])
				SDIAppForm->dxNavBar1Item30->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item30->Enabled = false;

			if('1' == everyqx[43])
				SDIAppForm->dxNavBar1Item55->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item55->Enabled = false;

			if('1' == everyqx[44])
				SDIAppForm->dxNavBar1Item17->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item17->Enabled = false;

			if('1' == everyqx[45])
				SDIAppForm->dxNavBar1Item33->Enabled = true;
			else
				SDIAppForm->dxNavBar1Item33->Enabled = false;

            if('1' == everyqx[46])
            	SDIAppForm->dxNavBar1Item34->Enabled = true;
            else
            	SDIAppForm->dxNavBar1Item34->Enabled = false;

			//结束分配

            SDIAppForm->dxStatusBar1->Panels->Items[0]->Text = "当前用户：" + OperatorName + "   " + VersionStr + "  修改时间：2013-12-27 : N-2.1.2";

			String SucStr = "insert into SYSLOG values(:USERID,:USERNAME,:MSG,:CZRQ)";
			ErrADOQ->Close();
			ErrADOQ->SQL->Clear();
			ErrADOQ->SQL->Add(SucStr);
			ErrADOQ->Parameters->ParamByName("USERID")->Value = LoginADOQ->FieldByName("USERID")->AsString;
			ErrADOQ->Parameters->ParamByName("USERNAME")->Value = NameEdit->Text;
			ErrADOQ->Parameters->ParamByName("MSG")->Value = "Login Successfully!";
			ErrADOQ->Parameters->ParamByName("CZRQ")->Value = DateofLogin;
			ErrADOQ->ExecSQL();
			ErrADOQ->Close();

            ErrADOQ->Close();
            ErrADOQ->SQL->Clear();
            SucStr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
            ErrADOQ->SQL->Add(SucStr);
            ErrADOQ->Parameters->ParamByName("BH")->Value = -1;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
            ErrADOQ->Parameters->ParamByName("KH")->Value = -1;
            ErrADOQ->Parameters->ParamByName("JE")->Value = 0;
            ErrADOQ->Parameters->ParamByName("YE")->Value = 0;
            ErrADOQ->Parameters->ParamByName("LX")->Value = "登录";
            ErrADOQ->Parameters->ParamByName("Operator")->Value = OperatorName;
            ErrADOQ->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
			ErrADOQ->ExecSQL();

			LoginFrom->Close();
		}
		else
		{
			String SucStr = "insert into SYSLOG values(:USERID,:USERNAME,:MSG,:CZRQ)";
			ErrADOQ->Close();
			ErrADOQ->SQL->Clear();
			ErrADOQ->SQL->Add(SucStr);
			ErrADOQ->Parameters->ParamByName("USERID")->Value = "";
			ErrADOQ->Parameters->ParamByName("USERNAME")->Value = NameEdit->Text;
			ErrADOQ->Parameters->ParamByName("MSG")->Value = "Login Failed! Reason:"+PassWordEdit->Text;
			ErrADOQ->Parameters->ParamByName("CZRQ")->Value = DateofLogin;
			ErrADOQ->ExecSQL();
			ErrADOQ->Close();
			ShowMessage("用户不存在或用户名及密码错误!");
            NameEdit->Text = "";
            PassWordEdit->Text = "";
        }
		LoginADOQ->Close();
	}
    else
    {
        ShowMessage("必须选择用户组，填写用户名与密码，密码长度为8位字符!");
        NameEdit->Text = "";
        PassWordEdit->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLoginFrom::PassWordEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if(Key == 13)
		LoginFrom->cxButton1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLoginFrom::NameEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if(13 == Key)
    {
        PassWordEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TLoginFrom::FormShow(TObject *Sender)
{
	LoginADOQ->Close();
    LoginADOQ->SQL->Clear();
    LoginADOQ->SQL->Add("select * from SYSLOG join SYSUSER on SYSLOG.USERNAME=SYSUSER.USERNAME where MSG='Login Successfully!' order by CZRQ asc");
    LoginADOQ->Open();
    if(!LoginADOQ->IsEmpty())
    {
    	LoginADOQ->Last();
//    	GroupComboBox->ItemIndex = StrToInt(LoginADOQ->FieldByName("USERID")->AsString.Trim())-1;
		GroupComboBox->Text = LoginADOQ->FieldByName("GROUPNAME")->AsString.Trim();
        NameEdit->Text = LoginADOQ->FieldByName("USERNAME")->AsString.Trim();
        PassWordEdit->SetFocus();
    }
    LoginADOQ->Close();
}
//---------------------------------------------------------------------------

