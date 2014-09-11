//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BatchLaunchCardFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma link "cxButtons"
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
#pragma link "cxMemo"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "dxSkinscxPCPainter"
#pragma link "cxListView"
#pragma resource "*.dfm"
TBatchLaunchCardForm *BatchLaunchCardForm;
//---------------------------------------------------------------------------
__fastcall TBatchLaunchCardForm::TBatchLaunchCardForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardForm::ExitBTNClick(TObject *Sender)
{
	BatchLaunchCardtag = false;
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardForm::FormShow(TObject *Sender)
{
	BatchLaunchCardtag = true;
    cxListView1->Items->Clear();
    cxListView1->Columns->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardForm::ImportDataBTNClick(TObject *Sender)
{
	Variant ExcelApp;
	try
	{
		ExcelApp = CreateOleObject("Excel.Application");
	}
	catch(...)
	{
		MessageBox(this->Handle, "错误：您的系统中可能没有安装Excel！", "Error in launch Excel!", MB_OK|MB_ICONERROR);
		return;
	}
	String templatepath = GlobalPath + "\\Template.xls";
//	ShowMessage(templatepath);

//	ExcelApp.OlePropertySet("Left", 0);
//	ExcelApp.OlePropertySet("Top", 100);
//	ExcelApp.OlePropertySet("Width", 300);
//	ExcelApp.OlePropertySet("Height", 600);

	ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", templatepath.t_str());

	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");

	Variant ST = WB.OlePropertyGet("Sheets", 1);

	Variant RE = ST.OlePropertyGet("Range", "A1").OleFunction("Select");


	String strValue = ST.OlePropertyGet("Cells", 1, 1).OlePropertyGet("Value");




//	ExcelApp.OleFunction("Quit");

	MessageBox(this->Handle, "请参照这个模板进行数据导入!", "注意事项", MB_ICONEXCLAMATION|MB_OK);

	//	ShowMessage("请参照这个模板进行数据导入!");

	ExcelApp.OlePropertySet("Visible", (Variant)true);

	OpenDialog1->Execute();
	String ImportFilePath = OpenDialog1->FileName;

	if(!ImportFilePath.IsEmpty())
	{
		Variant ImportExcelApp;
		try
		{
			ImportExcelApp = CreateOleObject("Excel.Application");
		}
		catch(...)
		{
			MessageBox(this->Handle, "错误：您的系统中可能没有安装Excel!", "Error in launch Excel!", MB_OK|MB_ICONERROR);
			return;
		}

		ImportExcelApp.OlePropertyGet("workbooks").OleFunction("Open", ImportFilePath.t_str());

		Variant ImportWB = ImportExcelApp.OlePropertyGet("ActiveWorkBook");

		Variant ImportST = ImportWB.OlePropertyGet("Sheets", 1);

		String strImport = ImportST.OlePropertyGet("Cells", 1, 1).OlePropertyGet("Value");

		cxListView1->Clear();
		cxListView1->Columns->Clear();
		int line = 1;
		while(!strImport.IsEmpty())
		{
			TListColumn* col = cxListView1->Columns->Add();
			col->Caption = strImport;
			col->Width = 200;
			line++;
			strImport = ImportST.OlePropertyGet("Cells", 1, line).OlePropertyGet("Value");
		}
		int row = 2;

		String tmprowstr = ImportST.OlePropertyGet("Cells", row, 1).OlePropertyGet("Value");

		while(!tmprowstr.IsEmpty())
		{
			TListItem* litem = cxListView1->Items->Add();
			litem->Caption = tmprowstr;
			for(int i = 2; i <= line; i++)
			{
				litem->SubItems->Insert(i-2, ImportST.OlePropertyGet("Cells", row, i).OlePropertyGet("Value"));
			}
			row++;
			tmprowstr = ImportST.OlePropertyGet("Cells", row, 1).OlePropertyGet("Value");
		}
		ImportExcelApp.OleFunction("Quit");
        BatchBTN->Enabled = true;
	}

	ExcelApp.OleFunction("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardForm::BatchBTNClick(TObject *Sender)
{
	int allcount = cxListView1->Columns->Count;
	ChooseDataForm->cxRadioGroup1->Properties->Items->Clear();
	ChooseDataForm->cxRadioGroup2->Properties->Items->Clear();
	ChooseDataForm->cxRadioGroup3->Properties->Items->Clear();
	ChooseDataForm->cxRadioGroup4->Properties->Items->Clear();
	ChooseDataForm->cxRadioGroup5->Properties->Items->Clear();
	ChooseDataForm->cxRadioGroup6->Properties->Items->Clear();
	ChooseDataForm->cxRadioGroup7->Properties->Items->Clear();

	for(int i = 0; i < allcount; i++)
	{
		TcxRadioGroupItem* tmp1 = ChooseDataForm->cxRadioGroup1->Properties->Items->Add();
		TcxRadioGroupItem* tmp2 = ChooseDataForm->cxRadioGroup2->Properties->Items->Add();
		TcxRadioGroupItem* tmp3 = ChooseDataForm->cxRadioGroup3->Properties->Items->Add();
		TcxRadioGroupItem* tmp4 = ChooseDataForm->cxRadioGroup4->Properties->Items->Add();
		TcxRadioGroupItem* tmp5 = ChooseDataForm->cxRadioGroup5->Properties->Items->Add();
		TcxRadioGroupItem* tmp6 = ChooseDataForm->cxRadioGroup6->Properties->Items->Add();
		TcxRadioGroupItem* tmp7 = ChooseDataForm->cxRadioGroup7->Properties->Items->Add();

		tmp1->Caption = cxListView1->Columns->Items[i]->Caption;
		tmp2->Caption = cxListView1->Columns->Items[i]->Caption;
		tmp3->Caption = cxListView1->Columns->Items[i]->Caption;
		tmp4->Caption = cxListView1->Columns->Items[i]->Caption;
		tmp5->Caption = cxListView1->Columns->Items[i]->Caption;
		tmp6->Caption = cxListView1->Columns->Items[i]->Caption;
		tmp7->Caption = cxListView1->Columns->Items[i]->Caption;
	}
	ChooseDataForm->ShowModal();
}
//---------------------------------------------------------------------------


