//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CheckIDFRM.h"
#include "SDIMAIN.h"
#include "SysConFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
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
#pragma resource "*.dfm"

TCheckIDForm *CheckIDForm;
//---------------------------------------------------------------------------
__fastcall TCheckIDForm::TCheckIDForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCheckIDForm::cxButton2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TCheckIDForm::cxButton1Click(TObject *Sender)
{
	if(2 == trycount)
    {
    	if(12 == SuperIDTextEdit->Text.Length())
        {
        	if(!strnicmp(SuperIDTextEdit->Text.t_str(), DECSuperPassword, 12))
            {
            	SystemConfigFRM->TBCardPassWord->Enabled = true;
				SystemConfigFRM->TBPasswordEdtion->Enabled = true;
				SystemConfigFRM->TBUsingSector->Enabled = true;
				SystemConfigFRM->cxGroupBox1->Height = 212;
				MessageBox(this->Handle, "ÃÜÂëÕýÈ·!", "OK", MB_OK|MB_ICONEXCLAMATION);
                this->Close();
			}
			else
			{
				MessageBox(this->Handle, "Äã³¢ÊÔ³¬¼¶ÃÜÂë´íÎó³¬¹ý3´Î£¬½«ÍË³ö!", "Error", MB_OK|MB_ICONERROR);
				trycount = 0;
			}
			this->Close();
        }
		else
		{
			MessageBox(this->Handle, "Äã³¢ÊÔ³¬¼¶ÃÜÂë´íÎó³¬¹ý3´Î£¬½«ÍË³ö!", "Error", MB_OK|MB_ICONERROR);
			this->Close();
			trycount = 0;
		}
    }
	else
    {
    	if(12 == SuperIDTextEdit->Text.Length())
        {
        	if(!strnicmp(SuperIDTextEdit->Text.t_str(), DECSuperPassword, 12))
            {
            //    ShowMessage("fited!");
            	SystemConfigFRM->TBCardPassWord->Enabled = true;
				SystemConfigFRM->TBPasswordEdtion->Enabled = true;
				SystemConfigFRM->TBUsingSector->Enabled = true;
				SystemConfigFRM->cxGroupBox1->Height = 252;
                MessageBox(this->Handle, "ÃÜÂëÕýÈ·!", "OK", MB_OK|MB_ICONEXCLAMATION);
                this->Close();
            }
            else
            {
            	MessageBox(this->Handle, "ÃÜÂë´íÎó!", "Error", MB_OK|MB_ICONERROR);
                SuperIDTextEdit->Text = "";
            }
        }
        else
        {
        	MessageBox(this->Handle, "ÃÜÂë´íÎó!", "Error", MB_OK|MB_ICONERROR);
        	SuperIDTextEdit->Text = "";
        }
        trycount++;
    }
}
//---------------------------------------------------------------------------
void __fastcall TCheckIDForm::FormShow(TObject *Sender)
{
	trycount = 0;
    SuperIDTextEdit->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TCheckIDForm::SuperIDTextEditKeyPress(TObject *Sender, wchar_t &Key)
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

void __fastcall TCheckIDForm::cxButton3Click(TObject *Sender)
{
	ChangeSPWForm->ShowModal();
}
//---------------------------------------------------------------------------

