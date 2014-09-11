//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfirmStoreData.h"
#include "SDIMAIN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
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
#pragma link "cxButtons"
#pragma resource "*.dfm"
TConfirmDataFrm *ConfirmDataFrm;
//---------------------------------------------------------------------------
__fastcall TConfirmDataFrm::TConfirmDataFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfirmDataFrm::cxButton3Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TConfirmDataFrm::cxButton1Click(TObject *Sender)
{
	if(2 == trycount)
    {
		if(12 == cxTextEdit1->Text.Length())
        {
			if(!strnicmp(cxTextEdit1->Text.t_str(), DECSuperPassword, 12))
			{
				if(IDOK == MessageBox(this->Handle, "密码正确,点击确定进行旧数据备份!", "OK", MB_OK|MB_ICONEXCLAMATION|MB_OKCANCEL))
				{
					SDIAppForm->StoreMXADOQ->Close();
					SDIAppForm->StoreMXADOQ->SQL->Clear();
					SDIAppForm->StoreMXADOQ->SQL->Add("insert into OLDMX(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MXBAK");
					SDIAppForm->StoreMXADOQ->ExecSQL();
					SDIAppForm->StoreMXADOQ->Close();
					SDIAppForm->StoreMXADOQ->SQL->Clear();
					SDIAppForm->StoreMXADOQ->SQL->Add("truncate table MXBAK");
					SDIAppForm->StoreMXADOQ->ExecSQL();
					SDIAppForm->StoreMXADOQ->Close();
					MessageBox(this->Handle, "旧数据备份成功,备份数据保存在数据库OLDMX表中,无特殊情况请不要对OLDMX表进行操作!", "提示", MB_OK);
				}
			}
			else
			{
				MessageBox(this->Handle, "你尝试超级密码错误超过3次，将退出!", "Error", MB_OK|MB_ICONERROR);
				trycount = 0;
			}
			this->Close();
        }
        else
        {
            MessageBox(this->Handle, "你尝试超级密码错误超过3次，将退出!", "Error", MB_OK|MB_ICONERROR);
            this->Close();
            trycount = 0;
        }
    }
	else
    {
		if(12 == cxTextEdit1->Text.Length())
        {
			if(!strnicmp(cxTextEdit1->Text.t_str(), DECSuperPassword, 12))
			{
				if(IDOK == MessageBox(this->Handle, "密码正确,点击确定进行旧数据备份!", "OK", MB_OK|MB_ICONEXCLAMATION|MB_OKCANCEL))
				{
					SDIAppForm->StoreMXADOQ->Close();
					SDIAppForm->StoreMXADOQ->SQL->Clear();
					SDIAppForm->StoreMXADOQ->SQL->Add("insert into OLDMX(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MXBAK");
					try
					{
						SDIAppForm->StoreMXADOQ->ExecSQL();
						SDIAppForm->StoreMXADOQ->Close();
					}
					catch(...)
					{
                        return;
                    }
					SDIAppForm->StoreMXADOQ->SQL->Clear();
					SDIAppForm->StoreMXADOQ->SQL->Add("truncate table MXBAK");
					SDIAppForm->StoreMXADOQ->ExecSQL();
					SDIAppForm->StoreMXADOQ->Close();
					MessageBox(this->Handle, "旧数据备份成功,备份数据保存在数据库OLDMX表中,无特殊情况请不要对OLDMX表进行操作!", "提示", MB_OK);
                }
                this->Close();
            }
            else
            {
            	MessageBox(this->Handle, "密码错误!", "Error", MB_OK|MB_ICONERROR);
				cxTextEdit1->Text = "";
            }
        }
        else
        {
        	MessageBox(this->Handle, "密码错误!", "Error", MB_OK|MB_ICONERROR);
			cxTextEdit1->Text = "";
		}
        trycount++;
	}
}
//---------------------------------------------------------------------------
void __fastcall TConfirmDataFrm::FormShow(TObject *Sender)
{
	trycount=0;
	cxTextEdit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TConfirmDataFrm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)

{
	if(VK_RETURN == Key)
    {
        cxButton1->Click();
    }
	if(VK_ESCAPE == Key)
    {
        this->Close();
    }
}
//---------------------------------------------------------------------------
