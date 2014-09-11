//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "DeleteCardInfoFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma resource "*.dfm"
TDeleteCardInfoFrom *DeleteCardInfoFrom;
//---------------------------------------------------------------------------
__fastcall TDeleteCardInfoFrom::TDeleteCardInfoFrom(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDeleteCardInfoFrom::DeleteCardInfoBTNClick(TObject *Sender)
{
	WORD status;
	unsigned char keymode,secnum,Delayms;
	keymode = CARDPasswordEdition;//0x03;//CARDPasswordEdition;//0x03;
	secnum = UsingSecNUM;//0x01;
	Delayms = DelaySecond;

	unsigned char key[6];
	key[0] = CARDPassword[0];
	key[1] = CARDPassword[1];
	key[2] = CARDPassword[2];
	key[3] = CARDPassword[3];
	key[4] = CARDPassword[4];
	key[5] = CARDPassword[5];

	if(LoadHModule)
	{
		if(ClearCardInfoProc)
		{
			status = ClearCardInfoProc(readcomno, keymode, secnum, key, Delayms);
			if(0 == status)
			{
				beepofreaddll(readcomno, '10');
				DeleteCardInfoMemo->Lines->Add("清卡信息成功！");
			}
			else
			{
                DeleteCardInfoMemo->Lines->Add("清卡信息失败！");
            }
		}
		else
		{
			ShowMessage("清卡函数加载失败！");
        }
	}
	else
		ShowMessage("加载读写动态链接库失败！");
}
//---------------------------------------------------------------------------

void __fastcall TDeleteCardInfoFrom::ExitDeleteCardInfoBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
