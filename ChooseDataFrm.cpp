//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChooseDataFrm.h"
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
#pragma link "cxMemo"
#pragma link "cxRadioGroup"
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
TChooseDataForm *ChooseDataForm;
//---------------------------------------------------------------------------
__fastcall TChooseDataForm::TChooseDataForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChooseDataForm::cxButton3Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChooseDataForm::cxButton1Click(TObject *Sender)
{
	cxRadioGroup1->ItemIndex = -1;
	cxRadioGroup2->ItemIndex = -1;
	cxRadioGroup3->ItemIndex = -1;
	cxRadioGroup4->ItemIndex = -1;
	cxRadioGroup5->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TChooseDataForm::FormShow(TObject *Sender)
{
	cxRadioGroup1->ItemIndex = -1;
	cxRadioGroup2->ItemIndex = -1;
	cxRadioGroup3->ItemIndex = -1;
	cxRadioGroup4->ItemIndex = -1;
    cxRadioGroup5->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TChooseDataForm::cxButton2Click(TObject *Sender)
{
	if((-1 != cxRadioGroup1->ItemIndex)&&(-1 != cxRadioGroup4->ItemIndex)
		&&(-1 != cxRadioGroup5->ItemIndex)&&(-1 != cxRadioGroup6->ItemIndex)
		&&(-1 != cxRadioGroup7->ItemIndex))
	{
		int Index1 = cxRadioGroup1->ItemIndex;
		int Index2 = cxRadioGroup2->ItemIndex;
		int Index3 = cxRadioGroup3->ItemIndex;
		int Index4 = cxRadioGroup4->ItemIndex;
		int Index5 = cxRadioGroup5->ItemIndex;
		int Index6 = cxRadioGroup6->ItemIndex;
		int Index7 = cxRadioGroup7->ItemIndex;


        if(-1 != Index3)
        {
			if((0 == (Index1-Index2))||(0 == (Index1-Index3))||
			   (0 == (Index1-Index4))||(0 == (Index1-Index5))||
			   (0 == (Index1-Index6))||(0 == (Index1-Index7))||
			   (0 == (Index2-Index3))||(0 == (Index2-Index4))||
			   (0 == (Index2-Index5))||(0 == (Index2-Index6))||
			   (0 == (Index2-Index7))||(0 == (Index3-Index4))||
			   (0 == (Index3-Index5))||(0 == (Index3-Index6))||
			   (0 == (Index3-Index7))||(0 == (Index4-Index5))||
			   (0 == (Index4-Index6))||(0 == (Index4-Index7))||
			   (0 == (Index5-Index6))||(0 == (Index5-Index7))||
			   (0 == (Index6-Index7)))
			{
                ShowMessage("不要重复选择数据项!");
				cxRadioGroup1->ItemIndex = -1;
				cxRadioGroup2->ItemIndex = -1;
                cxRadioGroup3->ItemIndex = -1;
                cxRadioGroup4->ItemIndex = -1;
				cxRadioGroup5->ItemIndex = -1;
				cxRadioGroup6->ItemIndex = -1;
				cxRadioGroup7->ItemIndex = -1;
            }
            else
            {
				BatchLaunchCardProcessForm->Nameindex = Index4;
				BatchLaunchCardProcessForm->Moneyindex = Index1;
				BatchLaunchCardProcessForm->Groupindex = Index3;
				BatchLaunchCardProcessForm->Classindex = Index2;
				BatchLaunchCardProcessForm->ZWindex = Index5;
				BatchLaunchCardProcessForm->KHindex = Index6;
				BatchLaunchCardProcessForm->BHindex = Index7;
				BatchLaunchCardProcessForm->KHTextEdit->Text = "";
				BatchLaunchCardProcessForm->BHTextEdit->Text = "";
				BatchLaunchCardProcessForm->NameTextEdit->Text = "";
				BatchLaunchCardProcessForm->ClassTextEdit->Text = "";
				BatchLaunchCardProcessForm->GroupTextEdit->Text = "";
				BatchLaunchCardProcessForm->MoneyTextEdit->Text = "";
				BatchLaunchCardProcessForm->ZWTextEdit->Text = "";
                BatchLaunchCardProcessForm->ShowModal();
            }
        }
        else if(-1 == Index3)
        {
			if((0 == (Index1-Index2))||(0 == (Index2-Index7))||(0 == (Index1-Index4))||
			   (0 == (Index1-Index5))||(0 == (Index1-Index6))||(0 == (Index1-Index7))||
			   (0 == (Index2-Index4))||(0 == (Index2-Index5))||(0 == (Index2-Index6))||
			   (0 == (Index4-Index5))||(0 == (Index4-Index6))||(0 == (Index4-Index7))||
			   (0 == (Index5-Index6))||(0 == (Index5-Index7))||(0 == (Index6-Index7)))
			{
				ShowMessage("不要重复选择数据项!");
				cxRadioGroup1->ItemIndex = -1;
                cxRadioGroup2->ItemIndex = -1;
				cxRadioGroup3->ItemIndex = -1;
                cxRadioGroup4->ItemIndex = -1;
				cxRadioGroup5->ItemIndex = -1;
				cxRadioGroup6->ItemIndex = -1;
				cxRadioGroup7->ItemIndex = -1;
            }
            else
            {
                BatchLaunchCardProcessForm->Nameindex = Index4;
                BatchLaunchCardProcessForm->Moneyindex = Index1;
				BatchLaunchCardProcessForm->Groupindex = Index3;
				BatchLaunchCardProcessForm->Classindex = -1;
				BatchLaunchCardProcessForm->ZWindex = Index5;
				BatchLaunchCardProcessForm->KHindex = Index6;
				BatchLaunchCardProcessForm->BHindex = Index7;
				BatchLaunchCardProcessForm->KHTextEdit->Text = "";
				BatchLaunchCardProcessForm->BHTextEdit->Text = "";
				BatchLaunchCardProcessForm->NameTextEdit->Text = "";
				BatchLaunchCardProcessForm->ClassTextEdit->Text = "";
				BatchLaunchCardProcessForm->GroupTextEdit->Text = "";
				BatchLaunchCardProcessForm->MoneyTextEdit->Text = "";
				BatchLaunchCardProcessForm->ZWTextEdit->Text = "";
                BatchLaunchCardProcessForm->ShowModal();
            }
        }
	}
	else
	{
		ShowMessage("请选择数据项匹配，“姓名”“性别”“金额”“卡号”“编号”五项必须选择!");
		cxRadioGroup1->ItemIndex = -1;
		cxRadioGroup2->ItemIndex = -1;
		cxRadioGroup3->ItemIndex = -1;
		cxRadioGroup4->ItemIndex = -1;
		cxRadioGroup5->ItemIndex = -1;
		cxRadioGroup6->ItemIndex = -1;
		cxRadioGroup7->ItemIndex = -1;
	}
}
//---------------------------------------------------------------------------



