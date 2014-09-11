//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GoonPWFRM.h"
#include "GlobalParameter.h"
#include "SDIMAIN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGoonPWForm *GoonPWForm;
//---------------------------------------------------------------------------
__fastcall TGoonPWForm::TGoonPWForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGoonPWForm::Button1Click(TObject *Sender)
{
//判断继续使用密码，写狗
	if(!goontag)
	{
		ShowMessage("您已使用了继续密码，如需获得软件使用权请输入开放使用密码!");
		return;
    }
	char tmppw[12];
	memcpy(tmppw, Edit1->Text.t_str(), 12);
	for(int i = 0; i < 12; i++)
	{
		if(tmppw[i] != goonpw[i])
		{
			ShowMessage("继续使用密码错误，程序退出!");
			exit(1);
		}
	}
	//write dog
	unsigned char writebuf = 0x00;

	int writeoffset = 0x0044;
	int writelen = 1;
	DWORD writeretcode = RY3_Write(doghandle,writeoffset,&writebuf,writelen);
	if(writeretcode)
	{
		ShowMessage("写加密狗错误，程序无法运行!");
		exit(1);
	}
	ShowMessage("继续使用密码正确，您可以延期使用一个月!");
}
//---------------------------------------------------------------------------
void __fastcall TGoonPWForm::Button2Click(TObject *Sender)
{
//判读开放使用密码，写狗
	char tmppw[12];
	memcpy(tmppw, Edit2->Text.t_str(), 12);
	for(int i = 0; i < 12; i++)
	{
		if(tmppw[i] != relvpw[i])
		{
			ShowMessage("开放使用密码错误，程序退出!");
			exit(1);
		}
	}
	//write dog
	unsigned char writebuf = 0x00;

	int writeoffset = 0x0045;
	int writelen = 1;
	DWORD writeretcode = RY3_Write(doghandle,writeoffset,&writebuf,writelen);
	if(writeretcode)
	{
		ShowMessage("写加密狗错误，程序无法运行!");
		exit(1);
	}
	ShowMessage("开放使用密码正确，您已获得软件的使用权!");
}
//---------------------------------------------------------------------------
void __fastcall TGoonPWForm::Button3Click(TObject *Sender)
{
	exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TGoonPWForm::FormShow(TObject *Sender)
{
	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------
