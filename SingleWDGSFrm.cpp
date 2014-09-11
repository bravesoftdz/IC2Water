//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SingleWDGSFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxListView"
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
TSingleWDGSForm *SingleWDGSForm;
//---------------------------------------------------------------------------
__fastcall TSingleWDGSForm::TSingleWDGSForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSingleWDGSForm::FormShow(TObject *Sender)
{
	cxListView1->Items->Clear();
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from SFJPARAM order by JH asc");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		ADOQuery1->First();
		while(!ADOQuery1->Eof)
		{
			TListItem* tmp = cxListView1->Items->Add();
			String posstr;
			posstr = ADOQuery1->FieldByName("JH")->AsInteger;
			posstr += "号POS机";
			tmp->Caption = posstr;
			tmp->SubItems->Add("挂失下传状态显示");
			ADOQuery1->Next();
		}
		GSBTN->Enabled = true;
	}
	else
	{
		ShowMessage("数据库中没有POS收费机记录!");
	}
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TSingleWDGSForm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSingleWDGSForm::ExitBTNClick(TObject *Sender)
{
	if(vaildgsthread)
	{
		if(vaildgsthread->Finished)
			this->Close();
		else
		{
			if(mrOk == MessageBox(this->Handle, "是否在退出解挂程序?", "请确认", MB_OKCANCEL|MB_ICONQUESTION))
			{
				vaildgsthread->Terminate();
				this->Close();
			}
		}
	}
	else
		this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSingleWDGSForm::GSBTNClick(TObject *Sender)
{
	TSingleGSThread* gsthread = new TSingleGSThread(true,
													cxTextEdit1->Text,
													cxListView1,
													ADOInThread,
													GSBTN,
													ExitBTN,
													2);
	if(gsthread)
		gsthread->Resume();
	else
	{
        ShowMessage("挂失信息未能下传!");
	}
}
//---------------------------------------------------------------------------
