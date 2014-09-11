//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChangeCardInfoFRM.h"
#include "SDIMAIN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
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
TChangeCardInfoForm *ChangeCardInfoForm;
//---------------------------------------------------------------------------
__fastcall TChangeCardInfoForm::TChangeCardInfoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChangeCardInfoForm::cxButton2Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TChangeCardInfoForm::FormShow(TObject *Sender)
{
	cxTextEdit1->Text = "";
	cxTextEdit7->Text = "";

	cxTextEdit2->Text = "";
	SexComboBox->Text = "";
	SectionNameComboBox->Text = "";
	ClassNameComboBox->Text = "";
	DegreeComboBox->Text = "";
	GroupNameComboBox->Text = "";
	cxTextEdit12->Text = "";
	cxTextEdit11->Text = "";

	cxTextEdit6->Text = "";
	cxTextEdit17->Text = "";
	cxTextEdit18->Text = "";
	cxTextEdit15->Text = "";
	cxTextEdit16->Text = "";

	ChangeCardInfoADOQ->Close();
	ChangeCardInfoADOQ->SQL->Clear();
	String sqlstr = "select * from CARD where BH='";
	sqlstr += BHStr;
	sqlstr += "'";
	ChangeCardInfoADOQ->SQL->Add(sqlstr);
	ChangeCardInfoADOQ->Open();
	if(!ChangeCardInfoADOQ->IsEmpty())
	{
		cxButton1->Enabled = true;
		cxTextEdit1->Text = ChangeCardInfoADOQ->FieldByName("KH")->AsString.Trim();
		cxTextEdit7->Text = ChangeCardInfoADOQ->FieldByName("BH")->AsString.Trim();

		cxTextEdit2->Text = ChangeCardInfoADOQ->FieldByName("XM")->AsString.Trim();
		SexComboBox->Text = ChangeCardInfoADOQ->FieldByName("XB")->AsString.Trim();
		SectionNameComboBox->Text = ChangeCardInfoADOQ->FieldByName("BM")->AsString.Trim();
		ClassNameComboBox->Text = ChangeCardInfoADOQ->FieldByName("BZ")->AsString.Trim();
		DegreeComboBox->Text = ChangeCardInfoADOQ->FieldByName("ZW")->AsString.Trim();
		GroupNameComboBox->Text = ChangeCardInfoADOQ->FieldByName("ZB")->AsString.Trim();
		cxTextEdit12->Text = ChangeCardInfoADOQ->FieldByName("GRMM")->AsString.Trim();
		cxTextEdit11->Text = ChangeCardInfoADOQ->FieldByName("SFZH")->AsString.Trim();

		cxTextEdit6->Text = ChangeCardInfoADOQ->FieldByName("JB")->AsString.Trim();
		cxTextEdit17->Text = ChangeCardInfoADOQ->FieldByName("YJ")->AsString.Trim();
		cxTextEdit18->Text = ChangeCardInfoADOQ->FieldByName("SF_YE")->AsString.Trim();
		cxTextEdit15->Text = ChangeCardInfoADOQ->FieldByName("SF_FL")->AsString.Trim();
		cxTextEdit16->Text = ChangeCardInfoADOQ->FieldByName("SYCS")->AsString.Trim();
		ChangeCardInfoADOQ->Close();
	}
	else
	{
        cxButton1->Enabled = false;
	}
	ChangeCardInfoADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::cxButton1Click(TObject *Sender)
{
	ChangeCardInfoADOQ->Close();
	ChangeCardInfoADOQ->SQL->Clear();
	String sqlstr = "select * from CARD where BH='";
	sqlstr += BHStr;
	sqlstr += "'";
	ChangeCardInfoADOQ->SQL->Add(sqlstr);
	ChangeCardInfoADOQ->Open();
	if(!ChangeCardInfoADOQ->IsEmpty())
	{
		ChangeCardInfoADOQ->Edit();
		ChangeCardInfoADOQ->FieldByName("XM")->AsString = cxTextEdit2->Text;
		ChangeCardInfoADOQ->FieldByName("XB")->AsString = SexComboBox->Text;
		ChangeCardInfoADOQ->FieldByName("BM")->AsString = SectionNameComboBox->Text;
		ChangeCardInfoADOQ->FieldByName("BZ")->AsString = ClassNameComboBox->Text;
		ChangeCardInfoADOQ->FieldByName("ZW")->AsString = DegreeComboBox->Text;
		ChangeCardInfoADOQ->FieldByName("ZB")->AsString = GroupNameComboBox->Text;
		ChangeCardInfoADOQ->FieldByName("GRMM")->AsString = cxTextEdit12->Text;
		ChangeCardInfoADOQ->FieldByName("SFZH")->AsString = cxTextEdit11->Text;
		ChangeCardInfoADOQ->Post();

		GBView->Controller->SelectedRecords[0]->Values[2] = cxTextEdit2->Text;
		GBView->Controller->SelectedRecords[0]->Values[4] = SexComboBox->Text;
		GBView->Controller->SelectedRecords[0]->Values[5] = SectionNameComboBox->Text;
		GBView->Controller->SelectedRecords[0]->Values[6] = ClassNameComboBox->Text;
		GBView->Controller->SelectedRecords[0]->Values[8] = DegreeComboBox->Text;
		GBView->Controller->SelectedRecords[0]->Values[7] = GroupNameComboBox->Text;
//		GBView->Controller->SelectedRecords[0]->Values[16] = cxTextEdit12->Text;
//		GBView->Controller->SelectedRecords[0]->Values[5] = cxTextEdit11->Text;

		sqlstr = "select * from CARD_F where BH='";
		sqlstr += BHStr;
		sqlstr += "'";
		ChangeCardInfoADOQ->Close();
		ChangeCardInfoADOQ->SQL->Clear();
		ChangeCardInfoADOQ->SQL->Add(sqlstr);
		ChangeCardInfoADOQ->Open();
		if(!ChangeCardInfoADOQ->IsEmpty())
		{
			ChangeCardInfoADOQ->Edit();
			ChangeCardInfoADOQ->FieldByName("XM")->AsString = cxTextEdit2->Text;
			ChangeCardInfoADOQ->FieldByName("XB")->AsString = SexComboBox->Text;
			ChangeCardInfoADOQ->FieldByName("BM")->AsString = SectionNameComboBox->Text;
			ChangeCardInfoADOQ->FieldByName("BZ")->AsString = ClassNameComboBox->Text;
			ChangeCardInfoADOQ->FieldByName("ZW")->AsString = DegreeComboBox->Text;
			ChangeCardInfoADOQ->FieldByName("ZB")->AsString = GroupNameComboBox->Text;
			ChangeCardInfoADOQ->FieldByName("GRMM")->AsString = cxTextEdit12->Text;
			ChangeCardInfoADOQ->FieldByName("SFZH")->AsString = cxTextEdit11->Text;
			ChangeCardInfoADOQ->Post();
		}
		ChangeCardInfoADOQ->Close();

		ShowMessage("卡片信息修改成功!");

		this->Close();
	}
	ChangeCardInfoADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::SectionNameComboBoxEnter(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from BUMEN");
	ADOQuery1->Open();
	SectionNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		SectionNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("BUMEN")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	SectionNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::SectionNameComboBoxExit(TObject *Sender)
{
	if(-1 == SectionNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在部门！");
		SectionNameComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::SectionNameComboBoxPropertiesChange(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from BANBIE where BUMEN='"+
								(SectionNameComboBox->Text)+"'");
	ADOQuery1->Open();
	ClassNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		ClassNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("BANBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	ClassNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::ClassNameComboBoxExit(TObject *Sender)
{
	if(-1 == ClassNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在班别！");
		ClassNameComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::ClassNameComboBoxPropertiesChange(TObject *Sender)

{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from ZUBIE where BUMEN = '"+
								(SectionNameComboBox->Text)+"'"+"and "+
								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
	ADOQuery1->Open();
	GroupNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		GroupNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("ZUBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	GroupNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::DegreeComboBoxEnter(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from SFZW");
	ADOQuery1->Open();
	DegreeComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		DegreeComboBox->Properties->Items->Add(ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	DegreeComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::DegreeComboBoxExit(TObject *Sender)
{
	if(-1 == DegreeComboBox->ItemIndex)
	{
		ShowMessage("请选择用户身份！");
		DegreeComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::GroupNameComboBoxExit(TObject *Sender)
{
	if(-1 == GroupNameComboBox->ItemIndex)
	{
		ShowMessage("请选择用户所在组别！");
		GroupNameComboBox->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::ClassNameComboBoxEnter(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from BANBIE where BUMEN='"+
								(SectionNameComboBox->Text)+"'");
	ADOQuery1->Open();
	ClassNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		ClassNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("BANBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	ClassNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TChangeCardInfoForm::GroupNameComboBoxEnter(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from ZUBIE where BUMEN = '"+
								(SectionNameComboBox->Text)+"'"+"and "+
								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
	ADOQuery1->Open();
	GroupNameComboBox->Properties->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		GroupNameComboBox->Properties->Items->Add(ADOQuery1->FieldByName("ZUBIE")->AsAnsiString.Trim());
		ADOQuery1->Next();
	}
	GroupNameComboBox->ItemIndex = -1;
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

