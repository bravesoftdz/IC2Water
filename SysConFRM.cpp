//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SysConFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
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
#pragma link "cxTextEdit"
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
#pragma link "cxStyles"
#pragma link "dxSkinscxPCPainter"
#pragma link "cxMemo"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTimeEdit"
#pragma resource "*.dfm"
TSystemConfigFRM *SystemConfigFRM;

//---------------------------------------------------------------------------
//#include "SDIMAIN.h"
#include "ChangePasswordFRM.h"
#include "ChangeCardMMFRM.h"

//---------------------------------------------------------------------------
__fastcall TSystemConfigFRM::TSystemConfigFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSystemConfigFRM::FormCreate(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("Select * from XTSET");
	ADOQuery1->Open();

	if(!ADOQuery1->IsEmpty())
	{
		TEUnitName->Text = ADOQuery1->FieldByName("DWMC")->AsString.Trim();
		TEUnitPassword->Text = ADOQuery1->FieldByName("DWMM")->AsString.Trim();
		TEDeliverCardDeposit->Text = ADOQuery1->FieldByName("FKYJ")->AsString.Trim();
		TECancelCardDeposit->Text = ADOQuery1->FieldByName("TKYJ")->AsString.Trim();
		TEMaxPosNUM->Text = ADOQuery1->FieldByName("MAXPOSNUM")->AsString.Trim();
	//	TECardPassword->Text = ADOQuery1->FieldByName("CARDMM")->AsString.Trim();
	//	TEPasswordEdtion->Text = ADOQuery1->FieldByName("MMEDITION")->AsString.Trim();
	//	TEUsingSector->Text = ADOQuery1->FieldByName("USINGSEC")->AsString.Trim();
	//	SystemNameTextEdit->Text = ADOQuery1->FieldByName("SYSTEMNAME")->AsString.Trim();
	}
//	cxGroupBox1->Height = 145;

	ADOQuery1->Close();
    ADOTable1->Active = true;

/*
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("Select * from secnum");
	ADOQuery1->Open();

	if(!ADOQuery1->IsEmpty())
	{
		TEDailyMaxConsumption->Text = ADOQuery1->FieldByName("DAYMAXXF")->AsString.Trim();
		TEDailyMaxConsumption1->Text = ADOQuery1->FieldByName("DAYMAXXF1")->AsString.Trim();
		TEDailyMaxConsumption2->Text = ADOQuery1->FieldByName("DAYMAXXF2")->AsString.Trim();
		TEDailyMaxConsumption3->Text = ADOQuery1->FieldByName("DAYMAXXF3")->AsString.Trim();
		TEDailyMaxConsumption4->Text = ADOQuery1->FieldByName("DAYMAXXF4")->AsString.Trim();
	}

	ADOQuery1->Close();

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from SUBMEALINFO");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		cxTimeEdit1->Text = ADOQuery1->FieldByName("breakfaststart")->AsString;
		cxTimeEdit2->Text = ADOQuery1->FieldByName("breakfastend")->AsString;
		cxTimeEdit3->Text = ADOQuery1->FieldByName("lunchstart")->AsString;
		cxTimeEdit4->Text = ADOQuery1->FieldByName("lunchend")->AsString;
		cxTimeEdit5->Text = ADOQuery1->FieldByName("supperstart")->AsString;
		cxTimeEdit6->Text = ADOQuery1->FieldByName("supperend")->AsString;
		cxTimeEdit7->Text = ADOQuery1->FieldByName("nightstart")->AsString;
		cxTimeEdit8->Text = ADOQuery1->FieldByName("nightend")->AsString;

		cxTextEdit1->Text = ADOQuery1->FieldByName("breakfastmoney11")->AsString;
		cxTextEdit2->Text = ADOQuery1->FieldByName("breakfastmoney12")->AsString;
		cxTextEdit3->Text = ADOQuery1->FieldByName("lunchmoney11")->AsString;
		cxTextEdit4->Text = ADOQuery1->FieldByName("lunchmoney12")->AsString;
		cxTextEdit5->Text = ADOQuery1->FieldByName("suppermoney11")->AsString;
		cxTextEdit6->Text = ADOQuery1->FieldByName("suppermoney12")->AsString;
		cxTextEdit7->Text = ADOQuery1->FieldByName("nightmoney11")->AsString;
		cxTextEdit8->Text = ADOQuery1->FieldByName("nightmoney12")->AsString;

		cxTextEdit9->Text = ADOQuery1->FieldByName("breakfastmoney21")->AsString;
		cxTextEdit10->Text = ADOQuery1->FieldByName("breakfastmoney22")->AsString;
		cxTextEdit11->Text = ADOQuery1->FieldByName("lunchmoney21")->AsString;
		cxTextEdit12->Text = ADOQuery1->FieldByName("lunchmoney22")->AsString;
		cxTextEdit13->Text = ADOQuery1->FieldByName("suppermoney21")->AsString;
		cxTextEdit14->Text = ADOQuery1->FieldByName("suppermoney22")->AsString;
		cxTextEdit15->Text = ADOQuery1->FieldByName("nightmoney21")->AsString;
		cxTextEdit16->Text = ADOQuery1->FieldByName("nightmoney22")->AsString;

		cxTextEdit17->Text = ADOQuery1->FieldByName("breakfastmoney31")->AsString;
		cxTextEdit18->Text = ADOQuery1->FieldByName("breakfastmoney32")->AsString;
		cxTextEdit19->Text = ADOQuery1->FieldByName("lunchmoney31")->AsString;
		cxTextEdit20->Text = ADOQuery1->FieldByName("lunchmoney32")->AsString;
		cxTextEdit21->Text = ADOQuery1->FieldByName("suppermoney31")->AsString;
		cxTextEdit22->Text = ADOQuery1->FieldByName("suppermoney32")->AsString;
		cxTextEdit23->Text = ADOQuery1->FieldByName("nightmoney31")->AsString;
		cxTextEdit24->Text = ADOQuery1->FieldByName("nightmoney32")->AsString;

		cxTextEdit25->Text = ADOQuery1->FieldByName("breakfastmoney41")->AsString;
		cxTextEdit26->Text = ADOQuery1->FieldByName("breakfastmoney42")->AsString;
		cxTextEdit27->Text = ADOQuery1->FieldByName("lunchmoney41")->AsString;
		cxTextEdit28->Text = ADOQuery1->FieldByName("lunchmoney42")->AsString;
		cxTextEdit29->Text = ADOQuery1->FieldByName("suppermoney41")->AsString;
		cxTextEdit30->Text = ADOQuery1->FieldByName("suppermoney42")->AsString;
		cxTextEdit31->Text = ADOQuery1->FieldByName("nightmoney41")->AsString;
		cxTextEdit32->Text = ADOQuery1->FieldByName("nightmoney42")->AsString;

        CheckBox5->Checked = ADOQuery1->FieldByName("Con1")->AsBoolean;
        CheckBox6->Checked = ADOQuery1->FieldByName("Con2")->AsBoolean;
        CheckBox7->Checked = ADOQuery1->FieldByName("Con3")->AsBoolean;
	}
	ADOQuery1->Close();     */
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::BTUnitNameClick(TObject *Sender)
{
	if(TEUnitName->EditModified)
	{
		String out = "您确认将单位名称改成\""+TEUnitName->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from xtset");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("DWMC")->AsString = TEUnitName->Text;
			ADOQuery1->Post();
			ADOQuery1->Close();
			ShowMessage("设置单位名称设置成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBUnitPasswordClick(TObject *Sender)
{
	ChangePasswordFrom->Top = 300;
	ChangePasswordFrom->Left = 450;
	ChangePasswordFrom->TEOldPassword->Text = "";
	ChangePasswordFrom->TENewPassword1->Text = "";
	ChangePasswordFrom->TENewPassword2->Text = "";
	ChangePasswordFrom->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBDeliverCardDepositClick(TObject *Sender)
{
	if(TEDeliverCardDeposit->EditModified)
	{
		String out = "您确认将发卡押金改成\""+TEDeliverCardDeposit->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from XTSET");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("FKYJ")->AsInteger = StrToInt(TEDeliverCardDeposit->Text);
			GlobalFKYJ = StrToInt(TEDeliverCardDeposit->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			ShowMessage("设置发卡押金修改成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBCancelCardDepositClick(TObject *Sender)
{
	if(TECancelCardDeposit->EditModified)
	{
		String out = "您确认将退卡押金改成\""+TECancelCardDeposit->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from XTSET");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("TKYJ")->AsInteger = StrToInt(TECancelCardDeposit->Text);
			GlobalTKYJ = StrToInt(TECancelCardDeposit->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			ShowMessage("设置退卡押金修改成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBCardPassWordClick(TObject *Sender)
{
	ChangeCardMMForm->Top = 300;
	ChangeCardMMForm->Left = 450;
	ChangeCardMMForm->TEOldPassword->Text = "";
	ChangeCardMMForm->TENewPassword1->Text = "";
	ChangeCardMMForm->TENewPassword2->Text = "";
	ChangeCardMMForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBPasswordEdtionClick(TObject *Sender)
{
	if(TEPasswordEdtion->EditModified&&!TEPasswordEdtion->Text.IsEmpty())
	{
		String out = "您确认将密码版本改成\""+TEPasswordEdtion->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("select * from WXTSET");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("MMEDITION")->AsInteger = StrToInt(TEPasswordEdtion->Text);
			ADOQuery1->Post();

			IntToUChar(ADOQuery1->FieldByName("MMEDITION")->AsInteger, &CARDPasswordEdition);

			ADOQuery1->Close();
			ShowMessage("设置密码版本成功!");
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBUsingSectorClick(TObject *Sender)
{
	if(TEUsingSector->EditModified&&!TEUsingSector->Text.IsEmpty())
	{
		String out = "您确认将使用扇区改成\""+TEUsingSector->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from WXTSET");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("SECNUM")->AsInteger = StrToInt(TEUsingSector->Text);
			ADOQuery1->Post();

			IntToUChar(ADOQuery1->FieldByName("SECNUM")->AsInteger, &UsingSecNUM);

			ADOQuery1->Close();
			ShowMessage("设置使用扇区成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBDailyMaxConsumptionClick(TObject *Sender)
{
	if(TEDailyMaxConsumption->EditModified)
	{
		String out = "您确认将每天限额改成\""+TEDailyMaxConsumption->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from secnum");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("daymaxxf")->AsFloat = StrToFloat(TEDailyMaxConsumption->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			maxconsumption = StrToFloat(TEDailyMaxConsumption->Text);
			ShowMessage("设置每天限额成功!");
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TSystemConfigFRM::TBDailyMaxConsumption1Click(TObject *Sender)
{
	if(TEDailyMaxConsumption1->EditModified&&!TEDailyMaxConsumption1->Text.IsEmpty())
	{
        if(StrToFloat(TEDailyMaxConsumption1->Text)>255)
        {
            ShowMessage("分组限额不能大于255元!");
            return;
        }

		String out = "您确认将分组一每天限额改成\""+TEDailyMaxConsumption1->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from secnum");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("daymaxxf1")->AsFloat = StrToFloat(TEDailyMaxConsumption1->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			maxconsumption1 = StrToFloat(TEDailyMaxConsumption1->Text);
			ShowMessage("设置分组一每天限额成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBDailyMaxConsumption2Click(TObject *Sender)
{
	if(TEDailyMaxConsumption2->EditModified&&!TEDailyMaxConsumption2->Text.IsEmpty())
	{
        if(StrToFloat(TEDailyMaxConsumption2->Text)>255)
        {
            ShowMessage("分组限额不能大于255元!");
            return;
        }

		String out = "您确认将分组二每天限额改成\""+TEDailyMaxConsumption2->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from secnum");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("daymaxxf2")->AsFloat = StrToFloat(TEDailyMaxConsumption2->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			maxconsumption2 = StrToFloat(TEDailyMaxConsumption2->Text);
			ShowMessage("设置分组二每天限额成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBDailyMaxConsumption3Click(TObject *Sender)
{
	if(TEDailyMaxConsumption3->EditModified&&!TEDailyMaxConsumption3->Text.IsEmpty())
	{
        if(StrToFloat(TEDailyMaxConsumption3->Text)>255)
        {
            ShowMessage("分组限额不能大于255元!");
            return;
        }

		String out = "您确认将分组三每天限额改成\""+TEDailyMaxConsumption3->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from secnum");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("daymaxxf3")->AsFloat = StrToFloat(TEDailyMaxConsumption3->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			maxconsumption3 = StrToFloat(TEDailyMaxConsumption3->Text);
			ShowMessage("设置分组三每天限额成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBDailyMaxConsumption4Click(TObject *Sender)
{
	if(TEDailyMaxConsumption4->EditModified&&!TEDailyMaxConsumption4->Text.IsEmpty())
	{
        if(StrToFloat(TEDailyMaxConsumption4->Text)>255)
        {
            ShowMessage("分组限额不能大于255元!");
            return;
        }

		String out = "您确认将分组四每天限额改成\""+TEDailyMaxConsumption4->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from secnum");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("daymaxxf4")->AsFloat = StrToFloat(TEDailyMaxConsumption4->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			maxconsumption4 = StrToFloat(TEDailyMaxConsumption4->Text);
			ShowMessage("设置分组四每天限额成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TBMaxPosNUMClick(TObject *Sender)
{
	if(TEMaxPosNUM->EditModified)
	{
		String out = "您确认将最大机器数改成\""+TEMaxPosNUM->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("select * from XTSET");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("MAXPOSNUM")->AsInteger = StrToInt(TEMaxPosNUM->Text);
			ADOQuery1->Post();
			ADOQuery1->Close();
			ShowMessage("设置最大机器数成功!");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::cxButton8Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEUnitPasswordKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEUnitPasswordExit(TObject *Sender)
{
	String tmpstr = TEUnitPassword->Text;
	if(tmpstr.Length() != 4)
	{
		ShowMessage("请输入4位的单位密码!");
		TEUnitPassword->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TECardPasswordKeyPress(TObject *Sender, wchar_t &Key)
{
/*	if((Key<'0'||Key>'9') && Key!='\b'&&(Key<'A'||Key>'F')&&(Key<'a'||Key>'f'))
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字或A至F,a至f之间的字符!");
	}  */
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TECardPasswordExit(TObject *Sender)
{
/*	String tmpstr = TECardPassword->Text;
	if(12 != tmpstr.Length())
	{
		ShowMessage("请输入12位的发卡密码!");
		TECardPassword->Text = "";
	}  */
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEPasswordEdtionExit(TObject *Sender)
{
	String tmpstr = TEPasswordEdtion->Text;
	if((2 < tmpstr.Length())&&(tmpstr.Length() > 0))
	{
		ShowMessage("请输入小于2位的发卡密码!");
		TEPasswordEdtion->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEDeliverCardDepositKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TECancelCardDepositKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEPasswordEdtionKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEUsingSectorKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEDailyMaxConsumptionKeyPress(TObject *Sender, wchar_t &Key)

{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEDailyMaxConsumption1KeyPress(TObject *Sender,
          wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEDailyMaxConsumption2KeyPress(TObject *Sender,
          wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEDailyMaxConsumption3KeyPress(TObject *Sender,
          wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEDailyMaxConsumption4KeyPress(TObject *Sender,
          wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEMaxPosNUMKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TECardPasswordKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	if(Key == VK_F11 && Shift.Contains(ssCtrl))
    {
		if(!ReaderChk)
        	CheckIDForm->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEPasswordEdtionKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	if(Key == VK_F11 && Shift.Contains(ssCtrl))
    {
    	if(!ReaderChk)
        	CheckIDForm->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::SystemNameBTNClick(TObject *Sender)
{
	if(SystemNameTextEdit->EditModified)
	{
		String out = "您确认将系统名称改成\""+SystemNameTextEdit->Text+"\"吗？";
		if(mrOk == MessageBox(this->Handle, out.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			ADOQuery1->Close();
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("Select * from XTSET");
			ADOQuery1->Open();
			ADOQuery1->Edit();
			ADOQuery1->FieldByName("SYSTEMNAME")->AsString = SystemNameTextEdit->Text;
			SYSTEMDISPLAYNAME = SystemNameTextEdit->Text;
			ADOQuery1->Post();
			ADOQuery1->Close();
			MessageBox(this->Handle, "系统名称改成功!该设置要重启系统后才能生效!", "Notice", MB_OK|MB_ICONQUESTION);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEUsingSectorKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	if(Key == VK_F11 && Shift.Contains(ssCtrl))
    {
    	if(!ReaderChk)
        	CheckIDForm->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		if(Key != '.')
		{
			Key=0;
			ShowMessage("请输入0到9之间的数字!");
      	}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::cxButton1Click(TObject *Sender)
{
	if(cxTimeEdit1->Time>=cxTimeEdit2->Time)
	{
		ShowMessage("早餐结束时间早与开始时间，请修改!");
		return;
	}

	if(cxTimeEdit3->Time>=cxTimeEdit4->Time)
	{
		ShowMessage("午餐结束时间早与开始时间，请修改!");
		return;
	}

	if(cxTimeEdit5->Time>=cxTimeEdit6->Time)
	{
		ShowMessage("晚餐结束时间早与开始时间，请修改!");
		return;
	}

    if((cxTimeEdit7->Time>=cxTimeEdit8->Time)&&(cxTimeEdit8->Time>cxTimeEdit1->Time))
    {
        ShowMessage("夜宵结束时间早与开始时间，请修改!");
        return;
    }

    if(cxTimeEdit2->Time>=cxTimeEdit3->Time)
    {
		ShowMessage("早餐结束时间与中餐开始时间冲突，请修改!");
		return;
    }

    if(cxTimeEdit4->Time>=cxTimeEdit5->Time)
    {
		ShowMessage("中餐结束时间与晚餐开始时间冲突，请修改!");
		return;
    }

    if(cxTimeEdit6->Time>=cxTimeEdit7->Time)
    {
		ShowMessage("晚餐结束时间与夜宵开始时间冲突，请修改!");
		return;
    }

    if(cxTimeEdit8->Time>=cxTimeEdit1->Time&&cxTimeEdit8->Time<=cxTimeEdit7->Time)
    {
		ShowMessage("夜宵结束时间与早餐开始时间冲突，请修改!");
		return;
    }

	if(!cxTextEdit1->Text.IsEmpty()&&!cxTextEdit2->Text.IsEmpty()&&
		!cxTextEdit3->Text.IsEmpty()&&!cxTextEdit4->Text.IsEmpty()&&
		!cxTextEdit5->Text.IsEmpty()&&!cxTextEdit6->Text.IsEmpty()&&
		!cxTextEdit7->Text.IsEmpty()&&!cxTextEdit8->Text.IsEmpty()&&
        !cxTextEdit9->Text.IsEmpty()&&!cxTextEdit10->Text.IsEmpty()&&
		!cxTextEdit11->Text.IsEmpty()&&!cxTextEdit12->Text.IsEmpty()&&
		!cxTextEdit13->Text.IsEmpty()&&!cxTextEdit14->Text.IsEmpty()&&
		!cxTextEdit15->Text.IsEmpty()&&!cxTextEdit16->Text.IsEmpty()&&
        !cxTextEdit17->Text.IsEmpty()&&!cxTextEdit18->Text.IsEmpty()&&
		!cxTextEdit19->Text.IsEmpty()&&!cxTextEdit20->Text.IsEmpty()&&
		!cxTextEdit21->Text.IsEmpty()&&!cxTextEdit22->Text.IsEmpty()&&
		!cxTextEdit23->Text.IsEmpty()&&!cxTextEdit24->Text.IsEmpty()&&
        !cxTextEdit25->Text.IsEmpty()&&!cxTextEdit26->Text.IsEmpty()&&
		!cxTextEdit27->Text.IsEmpty()&&!cxTextEdit28->Text.IsEmpty()&&
		!cxTextEdit29->Text.IsEmpty()&&!cxTextEdit30->Text.IsEmpty()&&
		!cxTextEdit31->Text.IsEmpty()&&!cxTextEdit32->Text.IsEmpty())
	{
    	//分组一
		double bmoney11,bmoney12,lmoney11,lmoney12,smoney11,smoney12,nmoney11,nmoney12;
		try
		{
			bmoney11 = StrToFloat(cxTextEdit1->Text);
        }
		catch(...)
		{
			ShowMessage("分组一早餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			bmoney12 = StrToFloat(cxTextEdit2->Text);
		}
		catch(...)
		{
			ShowMessage("分组一早餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			lmoney11 = StrToFloat(cxTextEdit3->Text);
		}
		catch(...)
		{
			ShowMessage("分组一午餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			lmoney12 = StrToFloat(cxTextEdit4->Text);
		}
		catch(...)
		{
			ShowMessage("分组一午餐二消费为不正确的数值，请更正!");
			return;
		}


		try
		{
			smoney11 = StrToFloat(cxTextEdit5->Text);
		}
		catch(...)
		{
			ShowMessage("分组一晚餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			smoney12 = StrToFloat(cxTextEdit6->Text);
		}
		catch(...)
		{
			ShowMessage("分组一晚餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			nmoney11 = StrToFloat(cxTextEdit7->Text);
		}
		catch(...)
		{
			ShowMessage("分组一夜宵一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			nmoney12 = StrToFloat(cxTextEdit8->Text);
		}
		catch(...)
		{
			ShowMessage("分组一夜宵二消费为不正确的数值，请更正!");
			return;
		}

		if(bmoney11>25.5||bmoney12>25.5||lmoney11>25.5||lmoney12>25.5||
			smoney11>25.5||smoney12>25.5||nmoney11>25.5||nmoney12>25.5)
		{
			ShowMessage("消费金额不能大于25.5元，请更正!");
			return;
		}

        //分组二
		double bmoney21,bmoney22,lmoney21,lmoney22,smoney21,smoney22,nmoney21,nmoney22;
		try
		{
			bmoney21 = StrToFloat(cxTextEdit9->Text);
        }
		catch(...)
		{
			ShowMessage("分组二早餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			bmoney22 = StrToFloat(cxTextEdit10->Text);
		}
		catch(...)
		{
			ShowMessage("分组二早餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			lmoney21 = StrToFloat(cxTextEdit11->Text);
		}
		catch(...)
		{
			ShowMessage("分组二午餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			lmoney22 = StrToFloat(cxTextEdit12->Text);
		}
		catch(...)
		{
			ShowMessage("分组二午餐二消费为不正确的数值，请更正!");
			return;
		}


		try
		{
			smoney21 = StrToFloat(cxTextEdit13->Text);
		}
		catch(...)
		{
			ShowMessage("分组二晚餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			smoney22 = StrToFloat(cxTextEdit14->Text);
		}
		catch(...)
		{
			ShowMessage("分组二晚餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			nmoney21 = StrToFloat(cxTextEdit15->Text);
		}
		catch(...)
		{
			ShowMessage("分组二夜宵一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			nmoney22 = StrToFloat(cxTextEdit16->Text);
		}
		catch(...)
		{
			ShowMessage("分组二夜宵二消费为不正确的数值，请更正!");
			return;
		}

		if(bmoney21>25.5||bmoney22>25.5||lmoney21>25.5||lmoney22>25.5||
			smoney21>25.5||smoney22>25.5||nmoney21>25.5||nmoney22>25.5)
		{
			ShowMessage("消费金额不能大于25.5元，请更正!");
			return;
		}

        //分组三
		double bmoney31,bmoney32,lmoney31,lmoney32,smoney31,smoney32,nmoney31,nmoney32;
		try
		{
			bmoney31 = StrToFloat(cxTextEdit17->Text);
        }
		catch(...)
		{
			ShowMessage("分组三早餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			bmoney32 = StrToFloat(cxTextEdit18->Text);
		}
		catch(...)
		{
			ShowMessage("分组三早餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			lmoney31 = StrToFloat(cxTextEdit19->Text);
		}
		catch(...)
		{
			ShowMessage("分组三午餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			lmoney32 = StrToFloat(cxTextEdit20->Text);
		}
		catch(...)
		{
			ShowMessage("分组三午餐二消费为不正确的数值，请更正!");
			return;
		}


		try
		{
			smoney31 = StrToFloat(cxTextEdit21->Text);
		}
		catch(...)
		{
			ShowMessage("分组三晚餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			smoney32 = StrToFloat(cxTextEdit22->Text);
		}
		catch(...)
		{
			ShowMessage("分组三晚餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			nmoney31 = StrToFloat(cxTextEdit23->Text);
		}
		catch(...)
		{
			ShowMessage("分组三夜宵一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			nmoney32 = StrToFloat(cxTextEdit24->Text);
		}
		catch(...)
		{
			ShowMessage("分组三夜宵二消费为不正确的数值，请更正!");
			return;
		}

		if(bmoney31>25.5||bmoney32>25.5||lmoney31>25.5||lmoney32>25.5||
			smoney31>25.5||smoney32>25.5||nmoney31>25.5||nmoney32>25.5)
		{
			ShowMessage("消费金额不能大于25.5元，请更正!");
			return;
		}

        //分组四
		double bmoney41,bmoney42,lmoney41,lmoney42,smoney41,smoney42,nmoney41,nmoney42;
		try
		{
			bmoney41 = StrToFloat(cxTextEdit17->Text);
        }
		catch(...)
		{
			ShowMessage("分组四早餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			bmoney42 = StrToFloat(cxTextEdit18->Text);
		}
		catch(...)
		{
			ShowMessage("分组四早餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			lmoney41 = StrToFloat(cxTextEdit19->Text);
		}
		catch(...)
		{
			ShowMessage("分组四午餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			lmoney42 = StrToFloat(cxTextEdit20->Text);
		}
		catch(...)
		{
			ShowMessage("分组四午餐二消费为不正确的数值，请更正!");
			return;
		}


		try
		{
			smoney41 = StrToFloat(cxTextEdit21->Text);
		}
		catch(...)
		{
			ShowMessage("分组四晚餐一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			smoney42 = StrToFloat(cxTextEdit22->Text);
		}
		catch(...)
		{
			ShowMessage("分组四晚餐二消费为不正确的数值，请更正!");
			return;
		}

		try
		{
			nmoney41 = StrToFloat(cxTextEdit23->Text);
		}
		catch(...)
		{
			ShowMessage("分组四夜宵一消费为不正确的数值，请更正!");
			return;
		}
		try
		{
			nmoney42 = StrToFloat(cxTextEdit24->Text);
		}
		catch(...)
		{
			ShowMessage("分组四夜宵二消费为不正确的数值，请更正!");
			return;
		}

		if(bmoney41>25.5||bmoney42>25.5||lmoney41>25.5||lmoney42>25.5||
			smoney41>25.5||smoney42>25.5||nmoney41>25.5||nmoney42>25.5)
		{
			ShowMessage("消费金额不能大于25.5元，请更正!");
			return;
		}
		//入库

		ADOTable2->Active = true;
		if(ADOTable2->IsEmpty())
		{
			ADOTable2->Insert();
			ADOTable2->Edit();

			ADOTable2->FieldByName("breakfaststart")->AsDateTime = cxTimeEdit1->Time; //StrToTime(cxTimeEdit1->Text);
			ADOTable2->FieldByName("breakfastend")->AsDateTime = cxTimeEdit2->Time;
			ADOTable2->FieldByName("lunchstart")->AsDateTime = cxTimeEdit3->Time;
			ADOTable2->FieldByName("lunchend")->AsDateTime = cxTimeEdit4->Time;
			ADOTable2->FieldByName("supperstart")->AsDateTime = cxTimeEdit5->Time;
			ADOTable2->FieldByName("supperend")->AsDateTime = cxTimeEdit6->Time;
			ADOTable2->FieldByName("nightstart")->AsDateTime = cxTimeEdit7->Time;
			ADOTable2->FieldByName("nightend")->AsDateTime = cxTimeEdit8->Time;

			ADOTable2->FieldByName("breakfastmoney11")->AsFloat = bmoney11;
			ADOTable2->FieldByName("breakfastmoney12")->AsFloat = bmoney12;
			ADOTable2->FieldByName("lunchmoney11")->AsFloat = lmoney11;
			ADOTable2->FieldByName("lunchmoney12")->AsFloat = lmoney12;
			ADOTable2->FieldByName("suppermoney11")->AsFloat = smoney11;
			ADOTable2->FieldByName("suppermoney12")->AsFloat = smoney12;
			ADOTable2->FieldByName("nightmoney11")->AsFloat = nmoney11;
			ADOTable2->FieldByName("nightmoney12")->AsFloat = nmoney12;

			ADOTable2->FieldByName("breakfastmoney21")->AsFloat = bmoney21;
			ADOTable2->FieldByName("breakfastmoney22")->AsFloat = bmoney22;
			ADOTable2->FieldByName("lunchmoney21")->AsFloat = lmoney21;
			ADOTable2->FieldByName("lunchmoney22")->AsFloat = lmoney22;
			ADOTable2->FieldByName("suppermoney21")->AsFloat = smoney21;
			ADOTable2->FieldByName("suppermoney22")->AsFloat = smoney22;
			ADOTable2->FieldByName("nightmoney21")->AsFloat = nmoney21;
			ADOTable2->FieldByName("nightmoney22")->AsFloat = nmoney22;

			ADOTable2->FieldByName("breakfastmoney31")->AsFloat = bmoney31;
			ADOTable2->FieldByName("breakfastmoney32")->AsFloat = bmoney32;
			ADOTable2->FieldByName("lunchmoney31")->AsFloat = lmoney31;
			ADOTable2->FieldByName("lunchmoney32")->AsFloat = lmoney32;
			ADOTable2->FieldByName("suppermoney31")->AsFloat = smoney31;
			ADOTable2->FieldByName("suppermoney32")->AsFloat = smoney32;
			ADOTable2->FieldByName("nightmoney31")->AsFloat = nmoney31;
			ADOTable2->FieldByName("nightmoney32")->AsFloat = nmoney32;

			ADOTable2->FieldByName("breakfastmoney41")->AsFloat = bmoney41;
			ADOTable2->FieldByName("breakfastmoney42")->AsFloat = bmoney42;
			ADOTable2->FieldByName("lunchmoney41")->AsFloat = lmoney41;
			ADOTable2->FieldByName("lunchmoney42")->AsFloat = lmoney42;
			ADOTable2->FieldByName("suppermoney41")->AsFloat = smoney41;
			ADOTable2->FieldByName("suppermoney42")->AsFloat = smoney42;
			ADOTable2->FieldByName("nightmoney41")->AsFloat = nmoney41;
			ADOTable2->FieldByName("nightmoney42")->AsFloat = nmoney42;

			ADOTable2->Post();
			ShowMessage("分餐数据入库成功!");
			ADOTable2->Active = false;
		}
		else
		{
			ADOTable2->Edit();

			ADOTable2->FieldByName("breakfaststart")->AsDateTime = cxTimeEdit1->Time; //StrToTime(cxTimeEdit1->Text);
			ADOTable2->FieldByName("breakfastend")->AsDateTime = cxTimeEdit2->Time;
			ADOTable2->FieldByName("lunchstart")->AsDateTime = cxTimeEdit3->Time;
			ADOTable2->FieldByName("lunchend")->AsDateTime = cxTimeEdit4->Time;
			ADOTable2->FieldByName("supperstart")->AsDateTime = cxTimeEdit5->Time;
			ADOTable2->FieldByName("supperend")->AsDateTime = cxTimeEdit6->Time;
			ADOTable2->FieldByName("nightstart")->AsDateTime = cxTimeEdit7->Time;
			ADOTable2->FieldByName("nightend")->AsDateTime = cxTimeEdit8->Time;

			ADOTable2->FieldByName("breakfastmoney11")->AsFloat = bmoney11;
			ADOTable2->FieldByName("breakfastmoney12")->AsFloat = bmoney12;
			ADOTable2->FieldByName("lunchmoney11")->AsFloat = lmoney11;
			ADOTable2->FieldByName("lunchmoney12")->AsFloat = lmoney12;
			ADOTable2->FieldByName("suppermoney11")->AsFloat = smoney11;
			ADOTable2->FieldByName("suppermoney12")->AsFloat = smoney12;
			ADOTable2->FieldByName("nightmoney11")->AsFloat = nmoney11;
			ADOTable2->FieldByName("nightmoney12")->AsFloat = nmoney12;

			ADOTable2->FieldByName("breakfastmoney21")->AsFloat = bmoney21;
			ADOTable2->FieldByName("breakfastmoney22")->AsFloat = bmoney22;
			ADOTable2->FieldByName("lunchmoney21")->AsFloat = lmoney21;
			ADOTable2->FieldByName("lunchmoney22")->AsFloat = lmoney22;
			ADOTable2->FieldByName("suppermoney21")->AsFloat = smoney21;
			ADOTable2->FieldByName("suppermoney22")->AsFloat = smoney22;
			ADOTable2->FieldByName("nightmoney21")->AsFloat = nmoney21;
			ADOTable2->FieldByName("nightmoney22")->AsFloat = nmoney22;

			ADOTable2->FieldByName("breakfastmoney31")->AsFloat = bmoney31;
			ADOTable2->FieldByName("breakfastmoney32")->AsFloat = bmoney32;
			ADOTable2->FieldByName("lunchmoney31")->AsFloat = lmoney31;
			ADOTable2->FieldByName("lunchmoney32")->AsFloat = lmoney32;
			ADOTable2->FieldByName("suppermoney31")->AsFloat = smoney31;
			ADOTable2->FieldByName("suppermoney32")->AsFloat = smoney32;
			ADOTable2->FieldByName("nightmoney31")->AsFloat = nmoney31;
			ADOTable2->FieldByName("nightmoney32")->AsFloat = nmoney32;

			ADOTable2->FieldByName("breakfastmoney41")->AsFloat = bmoney41;
			ADOTable2->FieldByName("breakfastmoney42")->AsFloat = bmoney42;
			ADOTable2->FieldByName("lunchmoney41")->AsFloat = lmoney41;
			ADOTable2->FieldByName("lunchmoney42")->AsFloat = lmoney42;
			ADOTable2->FieldByName("suppermoney41")->AsFloat = smoney41;
			ADOTable2->FieldByName("suppermoney42")->AsFloat = smoney42;
			ADOTable2->FieldByName("nightmoney41")->AsFloat = nmoney41;
			ADOTable2->FieldByName("nightmoney42")->AsFloat = nmoney42;

			ADOTable2->Post();
			ShowMessage("分餐数据入库成功!");
			ADOTable2->Active = false;
        }
	}
	else
	{
		ShowMessage("分餐消费金额填写不完整!");
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::CheckBox5Click(TObject *Sender)
{
	ADOTable2->Active = true;
	ADOTable2->Edit();

	if(CheckBox5->Checked)
        ADOTable2->FieldByName("Con1")->AsBoolean = 1;
    else
        ADOTable2->FieldByName("Con1")->AsBoolean = 0;

    ADOTable2->Post();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::CheckBox6Click(TObject *Sender)
{
	ADOTable2->Active = true;
    ADOTable2->Edit();

    if(CheckBox6->Checked)
        ADOTable2->FieldByName("Con2")->AsBoolean = 1;
    else
        ADOTable2->FieldByName("Con2")->AsBoolean = 0;

    ADOTable2->Post();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::CheckBox7Click(TObject *Sender)
{
	ADOTable2->Active = true;
    ADOTable2->Edit();

    if(CheckBox7->Checked)
        ADOTable2->FieldByName("Con3")->AsBoolean = 1;
    else
        ADOTable2->FieldByName("Con3")->AsBoolean = 0;

    ADOTable2->Post();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::FormShow(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("Select * from XTSET");
	ADOQuery1->Open();

	if(!ADOQuery1->IsEmpty())
	{
		TEUnitName->Text = ADOQuery1->FieldByName("DWMC")->AsString.Trim();
		TEUnitPassword->Text = ADOQuery1->FieldByName("DWMM")->AsString.Trim();
		TEDeliverCardDeposit->Text = ADOQuery1->FieldByName("FKYJ")->AsString.Trim();
		TECancelCardDeposit->Text = ADOQuery1->FieldByName("TKYJ")->AsString.Trim();
		TEMaxPosNUM->Text = ADOQuery1->FieldByName("MAXPOSNUM")->AsString.Trim();
	//	TECardPassword->Text = ADOQuery1->FieldByName("CARDMM")->AsString.Trim();
	//	TEPasswordEdtion->Text = ADOQuery1->FieldByName("MMEDITION")->AsString.Trim();
	//	TEUsingSector->Text = ADOQuery1->FieldByName("USINGSEC")->AsString.Trim();
	//	SystemNameTextEdit->Text = ADOQuery1->FieldByName("SYSTEMNAME")->AsString.Trim();
	}
//	cxGroupBox1->Height = 145;

	ADOQuery1->Close();

    ADOTable1->Active = true;

/*
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("Select * from secnum");
	ADOQuery1->Open();

	if(!ADOQuery1->IsEmpty())
	{
		TEDailyMaxConsumption->Text = ADOQuery1->FieldByName("DAYMAXXF")->AsString.Trim();
		TEDailyMaxConsumption1->Text = ADOQuery1->FieldByName("DAYMAXXF1")->AsString.Trim();
		TEDailyMaxConsumption2->Text = ADOQuery1->FieldByName("DAYMAXXF2")->AsString.Trim();
		TEDailyMaxConsumption3->Text = ADOQuery1->FieldByName("DAYMAXXF3")->AsString.Trim();
		TEDailyMaxConsumption4->Text = ADOQuery1->FieldByName("DAYMAXXF4")->AsString.Trim();
	}

	ADOQuery1->Close();

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from SUBMEALINFO");
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		cxTimeEdit1->Text = ADOQuery1->FieldByName("breakfaststart")->AsString;
		cxTimeEdit2->Text = ADOQuery1->FieldByName("breakfastend")->AsString;
		cxTimeEdit3->Text = ADOQuery1->FieldByName("lunchstart")->AsString;
		cxTimeEdit4->Text = ADOQuery1->FieldByName("lunchend")->AsString;
		cxTimeEdit5->Text = ADOQuery1->FieldByName("supperstart")->AsString;
		cxTimeEdit6->Text = ADOQuery1->FieldByName("supperend")->AsString;
		cxTimeEdit7->Text = ADOQuery1->FieldByName("nightstart")->AsString;
		cxTimeEdit8->Text = ADOQuery1->FieldByName("nightend")->AsString;

		cxTextEdit1->Text = ADOQuery1->FieldByName("breakfastmoney11")->AsString;
		cxTextEdit2->Text = ADOQuery1->FieldByName("breakfastmoney12")->AsString;
		cxTextEdit3->Text = ADOQuery1->FieldByName("lunchmoney11")->AsString;
		cxTextEdit4->Text = ADOQuery1->FieldByName("lunchmoney12")->AsString;
		cxTextEdit5->Text = ADOQuery1->FieldByName("suppermoney11")->AsString;
		cxTextEdit6->Text = ADOQuery1->FieldByName("suppermoney12")->AsString;
		cxTextEdit7->Text = ADOQuery1->FieldByName("nightmoney11")->AsString;
		cxTextEdit8->Text = ADOQuery1->FieldByName("nightmoney12")->AsString;

		cxTextEdit9->Text = ADOQuery1->FieldByName("breakfastmoney21")->AsString;
		cxTextEdit10->Text = ADOQuery1->FieldByName("breakfastmoney22")->AsString;
		cxTextEdit11->Text = ADOQuery1->FieldByName("lunchmoney21")->AsString;
		cxTextEdit12->Text = ADOQuery1->FieldByName("lunchmoney22")->AsString;
		cxTextEdit13->Text = ADOQuery1->FieldByName("suppermoney21")->AsString;
		cxTextEdit14->Text = ADOQuery1->FieldByName("suppermoney22")->AsString;
		cxTextEdit15->Text = ADOQuery1->FieldByName("nightmoney21")->AsString;
		cxTextEdit16->Text = ADOQuery1->FieldByName("nightmoney22")->AsString;

		cxTextEdit17->Text = ADOQuery1->FieldByName("breakfastmoney31")->AsString;
		cxTextEdit18->Text = ADOQuery1->FieldByName("breakfastmoney32")->AsString;
		cxTextEdit19->Text = ADOQuery1->FieldByName("lunchmoney31")->AsString;
		cxTextEdit20->Text = ADOQuery1->FieldByName("lunchmoney32")->AsString;
		cxTextEdit21->Text = ADOQuery1->FieldByName("suppermoney31")->AsString;
		cxTextEdit22->Text = ADOQuery1->FieldByName("suppermoney32")->AsString;
		cxTextEdit23->Text = ADOQuery1->FieldByName("nightmoney31")->AsString;
		cxTextEdit24->Text = ADOQuery1->FieldByName("nightmoney32")->AsString;

		cxTextEdit25->Text = ADOQuery1->FieldByName("breakfastmoney41")->AsString;
		cxTextEdit26->Text = ADOQuery1->FieldByName("breakfastmoney42")->AsString;
		cxTextEdit27->Text = ADOQuery1->FieldByName("lunchmoney41")->AsString;
		cxTextEdit28->Text = ADOQuery1->FieldByName("lunchmoney42")->AsString;
		cxTextEdit29->Text = ADOQuery1->FieldByName("suppermoney41")->AsString;
		cxTextEdit30->Text = ADOQuery1->FieldByName("suppermoney42")->AsString;
		cxTextEdit31->Text = ADOQuery1->FieldByName("nightmoney41")->AsString;
		cxTextEdit32->Text = ADOQuery1->FieldByName("nightmoney42")->AsString;

        CheckBox5->Checked = ADOQuery1->FieldByName("Con1")->AsBoolean;
        CheckBox6->Checked = ADOQuery1->FieldByName("Con2")->AsBoolean;
        CheckBox7->Checked = ADOQuery1->FieldByName("Con3")->AsBoolean;
	}
	ADOQuery1->Close();    */
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::cxButton2Click(TObject *Sender)
{
	PreorderdealForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::cxTextEdit1Exit(TObject *Sender)
{
	String tmpstr = ((TcxTextEdit*)Sender)->Text;
    char* alllen = tmpstr.t_str()+tmpstr.Length();
    char* pointloca = strchr(tmpstr.t_str(), '.');
    if(pointloca&&(alllen-pointloca)>2)
    {
    	ShowMessage("该参数只能精确到小数点后一位!");
    	((TcxTextEdit*)Sender)->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TSystemConfigFRM::TEUsingSectorExit(TObject *Sender)
{
	String tmpstr = TEUsingSector->Text;
	if((2 < tmpstr.Length())&&(tmpstr.Length() > 0))
	{
		ShowMessage("请输入小于2位的使用扇区!");
		TEUsingSector->Text = "";
	}
}
//---------------------------------------------------------------------------

