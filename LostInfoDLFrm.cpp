//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LostInfoDLFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxProgressBar"
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
TLostInfoFRM *LostInfoFRM;
//---------------------------------------------------------------------------
__fastcall TLostInfoFRM::TLostInfoFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLostInfoFRM::cxButton2Click(TObject *Sender)
{
	if(PostLostInfotoposThread)
	{
		if(PostLostInfotoposThread->Finished)
			this->Close();
		else
		{
            if(mrOk == MessageBox(this->Handle, "是否在退出挂失解挂程序?", "请确认", MB_OKCANCEL|MB_ICONQUESTION))
			{
				PostLostInfotoposThread->Terminate();
				this->Close();
			}
        }
	}
	else
	{
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TLostInfoFRM::cxButton1Click(TObject *Sender)
{
	if(!PostLostInfotoposThread)
	{
		PostLostInfotoposThread = new TPostLostInfoThread(true, cxButton1, cxButton2, ADOTable1, SCanProBar);
		if(PostLostInfotoposThread)
			PostLostInfotoposThread->Resume();
	}
	else
	{
		if(PostLostInfotoposThread->Finished)
		{
			PostLostInfotoposThread = new TPostLostInfoThread(true, cxButton1, cxButton2, ADOTable1, SCanProBar);
			if(PostLostInfotoposThread)
				PostLostInfotoposThread->Resume();
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TLostInfoFRM::FormShow(TObject *Sender)
{
	ADOTable1->Active = false;
	ADOTable1->Active = true;
	SCanProBar->Position = 0;
}
//---------------------------------------------------------------------------
