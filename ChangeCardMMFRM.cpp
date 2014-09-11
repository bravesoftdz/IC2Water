//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChangeCardMMFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
TChangeCardMMForm *ChangeCardMMForm;
//---------------------------------------------------------------------------
__fastcall TChangeCardMMForm::TChangeCardMMForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::TEOldPasswordKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b'&&(Key<'A'||Key>'F')&&(Key<'a'||Key>'f'))
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字或A至F,a至f之间的字符!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::TENewPassword1KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b'&&(Key<'A'||Key>'F')&&(Key<'a'||Key>'f'))
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字或A至F,a至f之间的字符!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::TENewPassword2KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b'&&(Key<'A'||Key>'F')&&(Key<'a'||Key>'f'))
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字或A至F,a至f之间的字符!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::TEOldPasswordExit(TObject *Sender)
{
	if(12 != TEOldPassword->Text.Length())
	{
		ShowMessage("请输入12位的旧卡片密码!");
		TEOldPassword->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::TENewPassword1Exit(TObject *Sender)
{
	if(12 != TENewPassword1->Text.Length())
	{
		ShowMessage("请输入12位的新卡片密码1!");
		TENewPassword1->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::TENewPassword2Exit(TObject *Sender)
{
	if(12 != TENewPassword2->Text.Length())
	{
		ShowMessage("请输入12位的新卡片密码2!");
		TENewPassword2->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::cxButton1Click(TObject *Sender)
{
	String Oldpwstr = TEOldPassword->Text;
	String Newpwstr1 = TENewPassword1->Text;
	String Newpwstr2 = TENewPassword2->Text;

	if("" != Oldpwstr)
	{
		if(("" != Newpwstr1)&&("" != Newpwstr2))
		{
			if(Newpwstr1 == Newpwstr2)
			{
				ADOQuery1->Close();
				ADOQuery1->SQL->Clear();
				ADOQuery1->SQL->Add("Select * from WXTSET");
				ADOQuery1->Open();
		  //		String tmpstr = ADOQuery1->FieldByName("CARDMM")->AsString;
				//ShowMessage(tmpstr);
                String oldpw = ADOQuery1->FieldByName("CARDMM")->AsString.Trim();

				unsigned int cmplen = 12;
				if(oldpw == Oldpwstr)//tmpstr == Oldpwstr)
				{
					if(Newpwstr1 == Newpwstr2)
					{
						if(12 == Newpwstr1.Length())
						{


                        	ADOQuery1->Edit();
							ADOQuery1->FieldByName("CARDMM")->AsAnsiString = Newpwstr1;
							ADOQuery1->Post();
                            ADOQuery1->Close();

                            unsigned char TCARDPassword[16];
                            AnsiString tmpCARDPassword = Newpwstr1;
                            memcpy(TCARDPassword, tmpCARDPassword.c_str(), 16);

                            for(int i = 0; i < 6; i++)
                            {
                                int tmpint = StrToInt("0x"+tmpCARDPassword.SubString(i*2+1, 2));
                                IntToUChar(tmpint, &CARDPassword[i]);
                            }

                            MessageBox(this->Handle, "密码修改成功！", "成功", MB_OK|MB_ICONEXCLAMATION);
							this->Close();
						}
						else
							MessageBox(this->Handle, "密码必须为12位", "错误", MB_OK|MB_ICONERROR);
					}
					else
						MessageBox(this->Handle, "请输入两次相同的新密码！", "错误", MB_OK|MB_ICONERROR);
				}
				else
				{
					MessageBox(this->Handle, "旧密码错误!", "错误", MB_OK|MB_ICONERROR);
				}
				ADOQuery1->Close();
			}
			else
			{
			//	ShowMessage("两次输入的密码不一致！");
				MessageBox(this->Handle, "两次输入的密码不一致！", "错误", MB_OK|MB_ICONERROR);
            }
        }
	}
	else
		MessageBox(this->Handle, "旧密码不为空！", "错误", MB_OK|MB_ICONERROR);
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardMMForm::cxButton2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

