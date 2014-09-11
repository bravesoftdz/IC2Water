//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddMPOSFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
TAddMPOSForm *AddMPOSForm;

#include "PosConFRM.h"
//---------------------------------------------------------------------------
__fastcall TAddMPOSForm::TAddMPOSForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddMPOSForm::cxTextEdit7KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::ExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::FormShow(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from STNAME");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		ADOQuery1->First();
        cxComboBox1->Properties->Items->Clear();
        cxComboBox2->Properties->Items->Clear();
		while(!ADOQuery1->Eof)
		{
			cxComboBox1->Properties->Items->Add(ADOQuery1->FieldByName("STID")->AsAnsiString.Trim());
			cxComboBox2->Properties->Items->Add(ADOQuery1->FieldByName("STNAME")->AsAnsiString.Trim());
			ADOQuery1->Next();
        }
	}
	else
	{
		ADDBTN->Enabled = false;
		ShowMessage("由于无食堂信息，无法增加POS设备，请联系技术人员!");
	}

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from STATION where SY=1");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		ADOQuery1->First();
        cxComboBox4->Properties->Items->Clear();
        cxComboBox3->Properties->Items->Clear();
		while(!ADOQuery1->Eof)
		{
			cxComboBox4->Properties->Items->Add(ADOQuery1->FieldByName("GZZID")->AsAnsiString.Trim());
			cxComboBox3->Properties->Items->Add(ADOQuery1->FieldByName("GZZMC")->AsAnsiString.Trim());
			ADOQuery1->Next();
        }
	}
	else
	{
		ADDBTN->Enabled = false;
		ShowMessage("由于无工作站信息，无法增加POS设备，请联系技术人员!");
    }
	ADOQuery1->Close();

    cxTextEdit3->Text = "";
    cxTextEdit1->Text = "";
    cxComboBox1->ItemIndex = -1;
    cxComboBox4->ItemIndex = -1;
    cxTextEdit12->Text = "";
    cxTextEdit7->Text = "";
    cxTextEdit2->Text = "";
    cxTextEdit8->Text = "";
    cxComboBox5->ItemIndex = -1;
    CheckBox1->Checked = false;
    CheckBox2->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::cxComboBox1PropertiesChange(TObject *Sender)
{
	cxComboBox2->ItemIndex = cxComboBox1->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::cxComboBox4PropertiesChange(TObject *Sender)
{
	cxComboBox3->ItemIndex = cxComboBox4->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::ADDBTNClick(TObject *Sender)
{
	if(cxTextEdit3->Text.IsEmpty()&&cxTextEdit1->Text.IsEmpty())
    {
        ShowMessage("必须输入起始机号与截止机号!");
        return;
    }

    if((cxTextEdit12->Text.IsEmpty())||(-1 == cxComboBox1->ItemIndex)
    	||(-1 == cxComboBox4->ItemIndex)||(cxTextEdit12->Text.IsEmpty())
        ||(cxTextEdit7->Text.IsEmpty())||(cxTextEdit8->Text.IsEmpty())
        ||(cxTextEdit2->Text.IsEmpty()))
    {
        ShowMessage("POS机参数填写不全!");
        return;
    }

    int beginjh = StrToInt(cxTextEdit3->Text);
    int endjh = StrToInt(cxTextEdit1->Text);

    if(beginjh > endjh)
    {
        ShowMessage("起始机号大于截至机号，错误!");
        return;
    }

    for (int i = beginjh; i <= endjh; i++)
    {
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		String tmpsql = "select * from SFJPARAM where JH='";
		tmpsql += i;
		tmpsql += "'";
		ADOQuery1->SQL->Add(tmpsql);
		ADOQuery1->Open();
		if(ADOQuery1->IsEmpty())
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			tmpsql = "insert into SFJPARAM values(:JH,:STID,:STNAME,:GZZID,:GZZMC,:CONNECT,:SFJPORT,:MAXXF,:PASSWORD,:SFJLX,:JX,:MAXZZZE,:DINGCAN,:DELBT,:MAXCSTAG,:MAXCS,:JQLX)";

			ADOQuery1->SQL->Add(tmpsql);
			ADOQuery1->Parameters->ParamByName("JH")->Value = i;
			ADOQuery1->Parameters->ParamByName("STID")->Value = cxComboBox1->ItemIndex+1;
			ADOQuery1->Parameters->ParamByName("STNAME")->Value = cxComboBox2->Text;
			ADOQuery1->Parameters->ParamByName("GZZID")->Value = StrToInt(cxComboBox4->Text);
			ADOQuery1->Parameters->ParamByName("GZZMC")->Value = cxComboBox3->Text;
			ADOQuery1->Parameters->ParamByName("CONNECT")->Value = false;
			ADOQuery1->Parameters->ParamByName("SFJPORT")->Value = StrToInt(cxTextEdit12->Text);
			ADOQuery1->Parameters->ParamByName("MAXXF")->Value = StrToInt(cxTextEdit7->Text);
			ADOQuery1->Parameters->ParamByName("PASSWORD")->Value = cxTextEdit8->Text;
			ADOQuery1->Parameters->ParamByName("SFJLX")->Value = 0;
			ADOQuery1->Parameters->ParamByName("JX")->Value = 0;
			ADOQuery1->Parameters->ParamByName("MAXZZZE")->Value = StrToInt(cxTextEdit2->Text);
            ADOQuery1->Parameters->ParamByName("DINGCAN")->Value = CheckBox1->Checked;
			ADOQuery1->Parameters->ParamByName("DELBT")->Value = CheckBox2->Checked;

			ADOQuery1->Parameters->ParamByName("MAXCSTAG")->Value = CheckBox3->Checked;
			if(CheckBox3->Checked)
			{
				if(!MaxCSEdit->Text.IsEmpty())
					ADOQuery1->Parameters->ParamByName("MAXCS")->Value = StrToInt(MaxCSEdit->Text);
				else
					ADOQuery1->Parameters->ParamByName("MAXCS")->Value = 0;
			}
			else
				ADOQuery1->Parameters->ParamByName("MAXCS")->Value = 0;

			ADOQuery1->Parameters->ParamByName("JQLX")->Value = cxComboBox5->Text;

			ADOQuery1->ExecSQL();

			String nodestr = i;
			nodestr += "号机:COM";
			nodestr += StrToInt(cxTextEdit12->Text);
			TListItem* tmp = PosConfigFRM->POSListView->Items->Add();
			tmp->Caption = nodestr;
			tmp->ImageIndex = 1;
			POSPARA* tmppospara = new POSPARA();
			tmppospara->posnum = i;
			tmppospara->comnum = StrToInt(cxTextEdit12->Text);
			tmppospara->tag = 2;
			tmp->Data = (void*)tmppospara;
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::cxComboBox4KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::cxComboBox5KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::CheckBox3Click(TObject *Sender)
{
	if(CheckBox3->Checked)
		MaxCSEdit->Enabled = true;
	else
		MaxCSEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::MaxCSEditExit(TObject *Sender)
{
	if(!MaxCSEdit->Text.IsEmpty())
	{
		int tmpint = StrToInt(MaxCSEdit->Text);
		if(tmpint>16)
		{
			MaxCSEdit->Text = "";
			ShowMessage("每天/餐最大消费次数不能大于16次!");
        }
	}
	else
		ShowMessage("必须填写“每天/餐最大消费次数”!");
}
//---------------------------------------------------------------------------

void __fastcall TAddMPOSForm::MaxCSEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

