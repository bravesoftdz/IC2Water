//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CheckWRMachFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
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
TCheckWriteReadMachineFRM *CheckWriteReadMachineFRM;
//---------------------------------------------------------------------------
__fastcall TCheckWriteReadMachineFRM::TCheckWriteReadMachineFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCheckWriteReadMachineFRM::cxButton2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCheckWriteReadMachineFRM::cxButton1Click(TObject *Sender)
{
/*	if(-1 != cxRadioGroup1->ItemIndex)
	{
		if(beepofreaddll)
		{
			unsigned char tmpcomstr[5] = "COM0";
			unsigned char tmptime = '1';
			unsigned char tmpi[2] = "";
			itoa(cxRadioGroup1->ItemIndex+1, tmpi, 10);
			tmpcomstr[3] = tmpi[0];

			if(0 == beepofreaddll(tmpcomstr, tmptime))
			{
				String outstr = "读卡器连接在COM";
				outstr += (cxRadioGroup1->ItemIndex+1);
				ShowMessage(outstr);
			}
			else
			{
 				String outstr = "读卡器没有连接在COM";
				outstr += (cxRadioGroup1->ItemIndex+1);
				ShowMessage(outstr);
			}
		}
	}
	else
	{
        ShowMessage("请选择要测试的COM接口!");
	}*/

	for(int i = 1; i < 9; i++)
	{
		if(beepofreaddll)
		{
			unsigned char tmpcomstr[5] = "COM0";
			unsigned char tmptime = '1';
			unsigned char tmpi[2] = "";
			itoa(i, tmpi, 10);
			tmpcomstr[3] = tmpi[0];

			if(0 == beepofreaddll(tmpcomstr, tmptime))
			{
				String outstr = "读卡器连接在COM";
				outstr += i;
				ShowMessage(outstr);
				cxRadioGroup1->ItemIndex = i-1;
				strcpy(readcomno, tmpcomstr);
				return;
			}
		}
	}
	ShowMessage("系统中没有读卡器接入!");

/*
	//读取读卡器中的卡密码，密码版本及使用扇区
	String tmpReadercode;
	char ReadercodeStr[16];
	unsigned char tmpsendlen = 0x03;
	unsigned char tmpdelay = 0x00;
	unsigned char tmpsendbuf[140];
	ZeroMemory(tmpsendbuf, 140);
	unsigned char tmprecbuf[140];
	ZeroMemory(tmprecbuf, 140);
	unsigned char tmpreclen;
	tmpsendbuf[0] = 0xC0;
	tmpsendbuf[1] = 0x08;
	tmpsendbuf[2] = 0x22;
	WORD tmpstatus = pacarddllprocreader(readcomno, tmpsendlen, tmpsendbuf, &tmpreclen, tmprecbuf,tmpdelay);
	if(!tmpstatus)
	{
		for(int m = 3; m < (int)tmpreclen; m++)
		{
			tmpReadercode += IntToHex(Byte(tmprecbuf[m]),2);
		}
	}
	if(tmpReadercode.Length() != 16)
	{
		ShowMessage("收费机密码长度不对!");
		return;
	}

	//inbase
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from XTSET");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		if(tmpReadercode.Length() == 16)
		{
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("CARDMM")->AsString = tmpReadercode.SubString(1, 12);
			ADOQuery1->FieldByName("MMEDITION")->AsInteger = StrToInt("0x"+tmpReadercode.SubString(13, 2));
			ADOQuery1->FieldByName("USINGSEC")->AsInteger = StrToInt("0x"+tmpReadercode.SubString(15, 2));
			ADOQuery1->Post();
		}
	}
	memcpy(ReadercodeStr, tmpReadercode.t_str(), 16);

	//end

	//解密卡片密码
	unsigned char oldpassword[8];
	unsigned char newpassword[8];
	int hpassword,lpassword;
	for(int i = 0; i < 8; i++)
	{
		if(ReadercodeStr[i*2]>0x2f&&ReadercodeStr[i*2]<0x3a)
			hpassword = ((byte)ReadercodeStr[i*2]-0x30)*16;
		else if(ReadercodeStr[i*2]>0x40&&ReadercodeStr[i*2]<0x47)
			hpassword = ((byte)ReadercodeStr[i*2]-0x41+10)*16;
		else if(ReadercodeStr[i*2]>0x60&&ReadercodeStr[i*2]<0x67)
			hpassword = ((byte)ReadercodeStr[i*2]-0x61+10)*16;
		else
		{
			//wrong code
			memset(oldpassword, 0xff, 8);
			break;
		}

		if(ReadercodeStr[i*2+1]>0x2f&&ReadercodeStr[i*2+1]<0x3a)
			hpassword = hpassword+((byte)ReadercodeStr[i*2+1]-0x30);
		else if(ReadercodeStr[i*2+1]>0x40&&ReadercodeStr[i*2+1]<0x47)
			hpassword = hpassword+((byte)ReadercodeStr[i*2+1]-0x41+10);
		else if(ReadercodeStr[i*2+1]>0x60&&ReadercodeStr[i*2+1]<0x67)
			hpassword = hpassword+((byte)ReadercodeStr[i*2+1]-0x61+10);
		else
		{
			//wrong code
			memset(oldpassword, 0xff, 8);
			break;
		}

		oldpassword[i] = (unsigned char)hpassword;
	}

	EncrptyCardMMProc(0x01, oldpassword, newpassword);
	for(int i = 0; i < 6; i++)
	{
		CARDPassword[i] = newpassword[i];
	}

	CARDPasswordEdition = newpassword[6];
	UsingSecNUM = newpassword[7];
	//end

	ShowMessage("检测读卡器成功!");     */
}
//---------------------------------------------------------------------------

