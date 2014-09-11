//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChangeSPWFrm.h"
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
TChangeSPWForm *ChangeSPWForm;
//---------------------------------------------------------------------------
__fastcall TChangeSPWForm::TChangeSPWForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::TENewPassword1KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b'&&(Key<'A'||Key>'F')&&(Key<'a'||Key>'f'))
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字或A至F,a至f之间的字符!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::TEOldPasswordExit(TObject *Sender)
{
	if(12 != TEOldPassword->Text.Length())
	{
		ShowMessage("请输入12位的旧超级密码!");
		TEOldPassword->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::TENewPassword1Exit(TObject *Sender)
{
	if(12 != TENewPassword1->Text.Length())
	{
		ShowMessage("请输入12位的新超级密码1!");
		TENewPassword1->Text = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::TENewPassword2Exit(TObject *Sender)
{
	if(12 != TENewPassword2->Text.Length())
	{
		ShowMessage("请输入12位的新超级密码2!");
		TENewPassword2->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::cxButton2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::cxButton1Click(TObject *Sender)
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
				ADOQuery1->SQL->Add("Select * from XTSET");
				ADOQuery1->Open();
		  //		String tmpstr = ADOQuery1->FieldByName("CARDMM")->AsString;
				//ShowMessage(tmpstr);

				unsigned int cmplen = 12;
				if(!strnicmp(DECSuperPassword, Oldpwstr.t_str(), 12))//tmpstr == Oldpwstr)
				{
					if(Newpwstr1 == Newpwstr2)
					{
						if(12 == Newpwstr1.Length())
						{
							char CDPW[8];
							char Enchar[9];
							ZeroMemory(CDPW, 8);
							ZeroMemory(Enchar, 9);

							String tmppwstr = Newpwstr1;
							for(int i = 0; i < 6; i++)
							{
								int tmpint = StrToInt("0x"+tmppwstr.SubString(i*2+1, 2));
								IntToUChar(tmpint, &CDPW[i]);
							}
							EncrptyCardMMProc(0, CDPW, Enchar);

							memcpy(SuperPasword, CDPW, 6);
							memcpy(DECSuperPassword, tmppwstr.t_str(), 12);

							char Inbasechar[16];
							ZeroMemory(Inbasechar, 16);
							for(int t = 0; t<8; t++)
							{
								char tmp;
								tmp = Enchar[t]>>4;
								tmp = tmp&0x0f;
					 //			itoa(tmp, &Inbasechar[t*2], 16);
					 			if(tmp >= 10)
									Inbasechar[t*2] = tmp+55;
								if(tmp <10)
									Inbasechar[t*2] = tmp+48;
								tmp = Enchar[t]&0x0f;
					 //			itoa(tmp, &Inbasechar[t*2+1], 16);
					 			if(tmp >= 10)
									Inbasechar[t*2+1] = tmp+55;
								if(tmp <10)
									Inbasechar[t*2+1] = tmp+48;
							}

							String stortstr = Inbasechar;
							ADOQuery1->Edit();
							ADOQuery1->FieldByName("SuperPW")->AsAnsiString = Inbasechar;
							ADOQuery1->Post();

				   /*			String tmpCARDPassword = ADOQuery1->FieldByName("CARDMM")->AsAnsiString;
							for(int i = 0; i<6; i++)
							{
								int tmpint = StrToInt("0x"+tmpCARDPassword.SubString(i*2+1, 2));
								IntToUChar(tmpint, &CARDPassword[i]);
							}        */

							MessageBox(this->Handle, "超级密码修改成功！", "成功", MB_OK|MB_ICONEXCLAMATION);
							this->Close();
						}
						else
							MessageBox(this->Handle, "超级密码必须为12位", "错误", MB_OK|MB_ICONERROR);
					}
					else
						MessageBox(this->Handle, "请输入两次相同的新密码！", "错误", MB_OK|MB_ICONERROR);
				}
				else
				{
					MessageBox(this->Handle, "旧超级密码错误!", "错误", MB_OK|MB_ICONERROR);
				}
				ADOQuery1->Close();
			}
			else
			{
			//	ShowMessage("两次输入的密码不一致！");
				MessageBox(this->Handle, "两次输入的超级密码不一致！", "错误", MB_OK|MB_ICONERROR);
            }
        }
	}
	else
		MessageBox(this->Handle, "旧超级密码不为空！", "错误", MB_OK|MB_ICONERROR);
}
//---------------------------------------------------------------------------
void __fastcall TChangeSPWForm::FormShow(TObject *Sender)
{
	TEOldPassword->Text = "";
    TENewPassword1->Text = "";
    TENewPassword2->Text = "";
}
//---------------------------------------------------------------------------

