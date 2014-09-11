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
		//	status = ClearCardInfoProc(readcomno, keymode, secnum, key, Delayms);
        	//begin to clear card

            unsigned char sendbuf[26];
            unsigned char sendbuflen = 26;
            unsigned char senddelay = Delayms;
            unsigned char recbuf[140];
            unsigned char recbuflen;
            unsigned char pblock = (secnum+1)*4+0;
            unsigned char pmimamode = 0x60;
            unsigned char pcommand = 0x02;
            unsigned char pkeymode = keymode;
            unsigned char pkey[6];
            memcpy(pkey,CARDPassword,6);
            unsigned char comno[5];
            memcpy(comno,readcomno,5);

            ZeroMemory(sendbuf,26);
            sendbuf[0] = pblock;//扇区×4+块号
            sendbuf[1] = pmimamode;//固定为0x60
            sendbuf[2] = pcommand;//命令字：1为读，2为写
            sendbuf[3] = pkeymode;
            sendbuf[4] = pkey[0];
            sendbuf[5] = pkey[1];
            sendbuf[6] = pkey[2];
            sendbuf[7] = pkey[3];
            sendbuf[8] = pkey[4];
            sendbuf[9] = pkey[5];
            status = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
            if(status)
            {
                ShowMessage("退卡失败，请重试或联系技术人员！");
                return;
            }

            pblock = (secnum+1)*4+1;
            pmimamode = 0x60;
            pcommand = 0x02;
            pkeymode = keymode;
            memcpy(pkey,CARDPassword,6);
            memcpy(comno,readcomno,5);
            ZeroMemory(sendbuf,26);
            sendbuf[0] = pblock;//扇区×4+块号
            sendbuf[1] = pmimamode;//固定为0x60
            sendbuf[2] = pcommand;//命令字：1为读，2为写
            sendbuf[3] = pkeymode;
            sendbuf[4] = pkey[0];
            sendbuf[5] = pkey[1];
            sendbuf[6] = pkey[2];
            sendbuf[7] = pkey[3];
            sendbuf[8] = pkey[4];
            sendbuf[9] = pkey[5];
            status = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
            if(status)
            {
                ShowMessage("退卡失败，请重试或联系技术人员！");
                return;
            }

            pblock = (secnum+1)*4+2;
            pmimamode = 0x60;
            pcommand = 0x02;
            pkeymode = keymode;
            memcpy(pkey,CARDPassword,6);
            memcpy(comno,readcomno,5);
            ZeroMemory(sendbuf,26);
            sendbuf[0] = pblock;//扇区×4+块号
            sendbuf[1] = pmimamode;//固定为0x60
            sendbuf[2] = pcommand;//命令字：1为读，2为写
            sendbuf[3] = pkeymode;
            sendbuf[4] = pkey[0];
            sendbuf[5] = pkey[1];
            sendbuf[6] = pkey[2];
            sendbuf[7] = pkey[3];
            sendbuf[8] = pkey[4];
            sendbuf[9] = pkey[5];
            status = pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);
            if(status)
            {
                ShowMessage("退卡失败，请重试或联系技术人员！");
                return;
            }

            pblock = (secnum+2)*4+0;
            pmimamode = 0x60;
            pcommand = 0x02;
            pkeymode = keymode;
            memcpy(pkey,CARDPassword,6);
            memcpy(comno,readcomno,5);
            ZeroMemory(sendbuf,26);
            sendbuf[0] = pblock;//扇区×4+块号
            sendbuf[1] = pmimamode;//固定为0x60
            sendbuf[2] = pcommand;//命令字：1为读，2为写
            sendbuf[3] = pkeymode;
            sendbuf[4] = pkey[0];
            sendbuf[5] = pkey[1];
            sendbuf[6] = pkey[2];
            sendbuf[7] = pkey[3];
            sendbuf[8] = pkey[4];
            sendbuf[9] = pkey[5];
            pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

            pblock = (secnum+2)*4+1;
            pmimamode = 0x60;
            pcommand = 0x02;
            pkeymode = keymode;
            memcpy(pkey,CARDPassword,6);
            memcpy(comno,readcomno,5);
            ZeroMemory(sendbuf,26);
            sendbuf[0] = pblock;//扇区×4+块号
            sendbuf[1] = pmimamode;//固定为0x60
            sendbuf[2] = pcommand;//命令字：1为读，2为写
            sendbuf[3] = pkeymode;
            sendbuf[4] = pkey[0];
            sendbuf[5] = pkey[1];
            sendbuf[6] = pkey[2];
            sendbuf[7] = pkey[3];
            sendbuf[8] = pkey[4];
            sendbuf[9] = pkey[5];
            pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

            pblock = (secnum+2)*4+2;
            pmimamode = 0x60;
            pcommand = 0x02;
            pkeymode = keymode;
            memcpy(pkey,CARDPassword,6);
            memcpy(comno,readcomno,5);
            ZeroMemory(sendbuf,26);
            sendbuf[0] = pblock;//扇区×4+块号
            sendbuf[1] = pmimamode;//固定为0x60
            sendbuf[2] = pcommand;//命令字：1为读，2为写
            sendbuf[3] = pkeymode;
            sendbuf[4] = pkey[0];
            sendbuf[5] = pkey[1];
            sendbuf[6] = pkey[2];
            sendbuf[7] = pkey[3];
            sendbuf[8] = pkey[4];
            sendbuf[9] = pkey[5];
            pacarddllproc(comno,sendbuflen,sendbuf,&recbuflen,recbuf,senddelay);

            //end to clear card
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
