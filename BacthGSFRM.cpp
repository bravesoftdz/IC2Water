//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BacthGSFRM.h"
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
#pragma link "cxProgressBar"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "dxSkinscxPCPainter"
#pragma resource "*.dfm"
TBatchGSForm *BatchGSForm;
//---------------------------------------------------------------------------
__fastcall TBatchGSForm::TBatchGSForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::cxButton2Click(TObject *Sender)
{
//挂失过程
	if(!BGSThread)
	{
		BGSThread = new TBatchGSThread(true,
									   ADOQuery3,
									   ADOQThread,
									   cxProgressBar1,
									   cxButton1,
									   cxButton2,
									   cxButton3,
									   sqlinthread);
		if(BGSThread)
			BGSThread->Resume();
	}
	else
	{
		if(BGSThread->Finished)
		{
			BGSThread = new TBatchGSThread(true,
										   ADOQuery3,
										   ADOQThread,
										   cxProgressBar1,
										   cxButton1,
										   cxButton2,
										   cxButton3,
										   sqlinthread);
			if(BGSThread)
				BGSThread->Resume();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::FormShow(TObject *Sender)
{
	DataGridDBTV->ClearItems();
	TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
	TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
	TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
	TcxGridDBColumn* SFRQCol = DataGridDBTV->CreateColumn();
	TcxGridDBColumn* JHCol = DataGridDBTV->CreateColumn();

	KHCol->Caption = "卡号";
//	KHCol->MinWidth = 90;
	KHCol->DataBinding->FieldName = "KH";

	BHCol->Caption = "编号";
	BHCol->DataBinding->FieldName = "BH";

	SFYECol->Caption = "姓名";
	SFYECol->DataBinding->FieldName = "XM";

	SFRQCol->Caption = "部门";
	SFRQCol->DataBinding->FieldName = "BM";

	JHCol->Caption = "班别";
	JHCol->DataBinding->FieldName = "BZ";

	cxProgressBar1->Position = 0;
	cxButton2->Enabled = false;
	cxComboBox1->Properties->Items->Clear();
	cxComboBox1->Text = "";
	cxComboBox2->Properties->Items->Clear();
	cxComboBox2->Text = "";
	ADOQuery1->Close();
	ADOQuery2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::cxButton1Click(TObject *Sender)
{
//查询要挂失的卡片
	String sqlstr;
	if(cxComboBox1->Text.IsEmpty())
	{
	//	sqlstr = "select * from CARD where ZT='发卡'";
		ShowMessage("必须输入查询条件!");
		return;
	}
	else if(!cxComboBox1->Text.IsEmpty())
	{
		sqlstr = "select * from CARD where BM='";
		sqlstr += cxComboBox1->Text;
		if(!cxComboBox2->Text.IsEmpty())
		{
			sqlstr += "' and BZ='";
			sqlstr += cxComboBox2->Text;
			sqlstr += "' and ZT='发卡'";
		}
		else
			sqlstr += "' and ZT='发卡'";
	}
	sqlinthread = sqlstr;
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(sqlstr);
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		cxButton2->Enabled = true;
	}
	else
	{
        ShowMessage("符合查询条件的卡片记录为0!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::cxComboBox1Enter(TObject *Sender)
{
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Add("select * from BUMEN");
	ADOQuery2->Open();
	if(!ADOQuery2->IsEmpty())
	{
		cxComboBox1->Properties->Items->Clear();
		ADOQuery2->First();
		while(!ADOQuery2->Eof)
		{
			cxComboBox1->Properties->Items->Add(ADOQuery2->FieldByName("BUMEN")->AsString.Trim());
			ADOQuery2->Next();
		}
		ADOQuery2->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::cxComboBox1KeyPress(TObject *Sender, wchar_t &Key)
{
	if(Key!='\b')
		Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TBatchGSForm::cxComboBox2Enter(TObject *Sender)
{
	if(cxComboBox1->Text.IsEmpty())
	{
		cxComboBox2->Properties->Items->Clear();
		cxComboBox2->Text = "";
	}
	else
	{
		ADOQuery2->Close();
		ADOQuery2->SQL->Clear();
		String sqlstr = "select * from BANBIE where BUMEN='";
		sqlstr += cxComboBox1->Text;
		sqlstr += "'";
		ADOQuery2->SQL->Add(sqlstr);
		ADOQuery2->Open();
		if(!ADOQuery2->IsEmpty())
		{
			cxComboBox2->Properties->Items->Clear();
			cxComboBox2->Text = "";
			ADOQuery2->First();
			while(!ADOQuery2->Eof)
			{
				cxComboBox2->Properties->Items->Add(ADOQuery2->FieldByName("BANBIE")->AsString.Trim());
				ADOQuery2->Next();
			}
			ADOQuery2->Close();
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::cxComboBox1Exit(TObject *Sender)
{
	if(cxComboBox1->Text.IsEmpty())
		cxComboBox2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TBatchGSForm::cxButton3Click(TObject *Sender)
{
	if(BGSThread)
	{
		if(!BGSThread->Finished)
			BGSThread->Terminate();
	}
	this->Close();
}
//---------------------------------------------------------------------------
