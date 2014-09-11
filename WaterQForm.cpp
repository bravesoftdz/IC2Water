//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WaterQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
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
#pragma link "cxButtons"
#pragma resource "*.dfm"
TSKMXQFrm *SKMXQFrm;
//---------------------------------------------------------------------------
__fastcall TSKMXQFrm::TSKMXQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSKMXQFrm::cxButton1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TSKMXQFrm::WarmTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TSKMXQFrm::FormShow(TObject *Sender)
{
	Button1->Enabled = false;
    YFComboBox->ItemIndex = -1;
    WarmTextEdit->Text = 100;
    ListView1->Items->Clear();
    Edit2->Text = "";
    ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSKMXQFrm::QueryBTNClick(TObject *Sender)
{
    if(WarmTextEdit->Text.IsEmpty()||(YFComboBox->ItemIndex==-1))
    {
        ShowMessage("必须填写报警金额下限和查询月份!");
        return;
    }
    imonth = YFComboBox->ItemIndex+1;
    ilevel = StrToInt(WarmTextEdit->Text);

	ProgressBar1->Position = 0;
	ListView1->Items->Clear();
	unsigned short qyear;
	unsigned short qmonth;
	unsigned short qday;
	Now().DecodeDate(&qyear,&qmonth,&qday);
	String lowtimestr = qyear;
	lowtimestr += "-";
	lowtimestr += (imonth);
	lowtimestr += "-01 00:00:00";
	String sqllowstr = "select MAX(WTJ.XFZE) as xflow,WTJ.JH from WTJ where WTJ.SCSJ<'";
	sqllowstr += lowtimestr;
	sqllowstr += "' group by JH";
	String hightimestr = qyear;
	hightimestr += "-";
	hightimestr += (imonth+1);
	hightimestr += "-01 00:00:00";
	String sqlhighstr = "select MAX(WTJ.XFZE) as xfhigh,WTJ.JH from WTJ where WTJ.SCSJ<'";
	sqlhighstr += hightimestr;
	sqlhighstr += "' group by JH";

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(sqllowstr);
	ADOQuery1->Open();

	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Add(sqlhighstr);
	ADOQuery2->Open();
	if(ADOQuery2->IsEmpty())
	{
		ShowMessage("查询结果为空!");
		return;
	}

	ADOQuery3->Close();
	ADOQuery3->SQL->Clear();
	ADOQuery3->SQL->Add("select JH from WTJ group by JH");
	ADOQuery3->Open();
	if(ADOQuery3->IsEmpty())
	{
		ShowMessage("查询结果为空!");
		return;
	}

	TDisplayTJThread * DisThread = new TDisplayTJThread(true,
														ListView1,
														Button1,
                                                        QueryBTN,
                                                        cxButton1,
														Edit2,
														ADOQuery1,
														ADOQuery2,
														ADOQuery3);

	if(DisThread)
	{
		EThread = DisThread;
		DisThread->Resume();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSKMXQFrm::YFComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSKMXQFrm::Button1Click(TObject *Sender)
{
	if(SaveDialog1->Execute())
	{
		if(FileExists(SaveDialog1->FileName+".xls"))
		{
			throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
			return;
		}
		else
		{
			String savename = SaveDialog1->FileName;
			savename += ".xls";
			TTJExportThread* tjthread = new TTJExportThread(true,
															ListView1,
															Button1,
                                                            QueryBTN,
                                                            cxButton1,
															ProgressBar1,
															YFComboBox->Text,
															StrToFloat(Edit2->Text),
															savename);
			if(tjthread)
				tjthread->Resume();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSKMXQFrm::ListView1CustomDrawSubItem(TCustomListView *Sender, TListItem *Item,
          int SubItem, TCustomDrawState State, bool &DefaultDraw)
{
	try
	{
    if(Item->SubItems->Count)
		ListView1->Canvas->Brush->Color = StrToFloat(Item->SubItems->Strings[0])<ilevel? clRed : clWhite;
	}
	catch(...)
	{

    }
}
//---------------------------------------------------------------------------

