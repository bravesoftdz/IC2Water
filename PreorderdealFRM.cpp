//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PreorderdealFRM.h"
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
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxTimeEdit"
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
TPreorderdealForm *PreorderdealForm;
//---------------------------------------------------------------------------
__fastcall TPreorderdealForm::TPreorderdealForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPreorderdealForm::cxTextEdit1Exit(TObject *Sender)
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
void __fastcall TPreorderdealForm::cxButton1Click(TObject *Sender)
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
        !cxTextEdit7->Text.IsEmpty()&&!cxTextEdit8->Text.IsEmpty())
    {
		double bmoney11,bmoney12,lmoney11,lmoney12,smoney11,smoney12,nmoney11,nmoney12;
		try
		{
			bmoney11 = StrToFloat(cxTextEdit1->Text);
        }
		catch(...)
		{
			ShowMessage("早餐订餐消费额为不正确的数值，请更正!");
			return;
		}
		try
		{
			bmoney12 = StrToFloat(cxTextEdit2->Text);
		}
		catch(...)
		{
			ShowMessage("早餐实际消费额为不正确的数值，请更正!");
			return;
		}

		try
		{
			lmoney11 = StrToFloat(cxTextEdit3->Text);
		}
		catch(...)
		{
			ShowMessage("午餐订餐消费额为不正确的数值，请更正!");
			return;
		}
		try
		{
			lmoney12 = StrToFloat(cxTextEdit4->Text);
		}
		catch(...)
		{
			ShowMessage("午餐实际消费额为不正确的数值，请更正!");
			return;
		}


		try
		{
			smoney11 = StrToFloat(cxTextEdit5->Text);
		}
		catch(...)
		{
			ShowMessage("晚餐订餐消费额为不正确的数值，请更正!");
			return;
		}
		try
		{
			smoney12 = StrToFloat(cxTextEdit6->Text);
		}
		catch(...)
		{
			ShowMessage("晚餐实际消费额为不正确的数值，请更正!");
			return;
		}

		try
		{
			nmoney11 = StrToFloat(cxTextEdit7->Text);
		}
		catch(...)
		{
			ShowMessage("夜宵订餐消费额为不正确的数值，请更正!");
			return;
		}
		try
		{
			nmoney12 = StrToFloat(cxTextEdit8->Text);
		}
		catch(...)
		{
			ShowMessage("夜宵实际消费额为不正确的数值，请更正!");
			return;
		}

		if(bmoney11>25.5||bmoney12>25.5||lmoney11>25.5||lmoney12>25.5||
			smoney11>25.5||smoney12>25.5||nmoney11>25.5||nmoney12>25.5)
		{
			ShowMessage("消费金额不能大于25.5元，请更正!");
			return;
		}

        ADOTable1->Active = true;
        if(ADOTable1->IsEmpty())
        {
            ADOTable1->Insert();
            ADOTable1->Edit();

			ADOTable1->FieldByName("breakfaststart")->AsDateTime = cxTimeEdit1->Time; //StrToTime(cxTimeEdit1->Text);
			ADOTable1->FieldByName("breakfastend")->AsDateTime = cxTimeEdit2->Time;
			ADOTable1->FieldByName("lunchstart")->AsDateTime = cxTimeEdit3->Time;
			ADOTable1->FieldByName("lunchend")->AsDateTime = cxTimeEdit4->Time;
			ADOTable1->FieldByName("supperstart")->AsDateTime = cxTimeEdit5->Time;
			ADOTable1->FieldByName("supperend")->AsDateTime = cxTimeEdit6->Time;
			ADOTable1->FieldByName("nightstart")->AsDateTime = cxTimeEdit7->Time;
			ADOTable1->FieldByName("nightend")->AsDateTime = cxTimeEdit8->Time;

			ADOTable1->FieldByName("breakfastmoney1")->AsFloat = bmoney11;
			ADOTable1->FieldByName("breakfastmoney2")->AsFloat = bmoney12;
			ADOTable1->FieldByName("lunchmoney1")->AsFloat = lmoney11;
			ADOTable1->FieldByName("lunchmoney2")->AsFloat = lmoney12;
			ADOTable1->FieldByName("suppermoney1")->AsFloat = smoney11;
			ADOTable1->FieldByName("suppermoney2")->AsFloat = smoney12;
			ADOTable1->FieldByName("nightmoney1")->AsFloat = nmoney11;
			ADOTable1->FieldByName("nightmoney2")->AsFloat = nmoney12;

            ADOTable1->Post();
            ShowMessage("入库成功!");
            ADOTable1->Active = false;
        }
        else
        {
            ADOTable1->Edit();

			ADOTable1->FieldByName("breakfaststart")->AsDateTime = cxTimeEdit1->Time; //StrToTime(cxTimeEdit1->Text);
			ADOTable1->FieldByName("breakfastend")->AsDateTime = cxTimeEdit2->Time;
			ADOTable1->FieldByName("lunchstart")->AsDateTime = cxTimeEdit3->Time;
			ADOTable1->FieldByName("lunchend")->AsDateTime = cxTimeEdit4->Time;
			ADOTable1->FieldByName("supperstart")->AsDateTime = cxTimeEdit5->Time;
			ADOTable1->FieldByName("supperend")->AsDateTime = cxTimeEdit6->Time;
			ADOTable1->FieldByName("nightstart")->AsDateTime = cxTimeEdit7->Time;
			ADOTable1->FieldByName("nightend")->AsDateTime = cxTimeEdit8->Time;

			ADOTable1->FieldByName("breakfastmoney1")->AsFloat = bmoney11;
			ADOTable1->FieldByName("breakfastmoney2")->AsFloat = bmoney12;
			ADOTable1->FieldByName("lunchmoney1")->AsFloat = lmoney11;
			ADOTable1->FieldByName("lunchmoney2")->AsFloat = lmoney12;
			ADOTable1->FieldByName("suppermoney1")->AsFloat = smoney11;
			ADOTable1->FieldByName("suppermoney2")->AsFloat = smoney12;
			ADOTable1->FieldByName("nightmoney1")->AsFloat = nmoney11;
			ADOTable1->FieldByName("nightmoney2")->AsFloat = nmoney12;

            ADOTable1->Post();
            ShowMessage("入库成功!");
            ADOTable1->Active = false;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TPreorderdealForm::FormShow(TObject *Sender)
{
	ADOTable1->Active = true;

    cxTimeEdit1->Time = ADOTable1->FieldByName("breakfaststart")->AsDateTime;
    cxTimeEdit2->Time = ADOTable1->FieldByName("breakfastend")->AsDateTime;
    cxTimeEdit3->Time = ADOTable1->FieldByName("lunchstart")->AsDateTime;
    cxTimeEdit4->Time = ADOTable1->FieldByName("lunchend")->AsDateTime;
    cxTimeEdit5->Time = ADOTable1->FieldByName("supperstart")->AsDateTime;
    cxTimeEdit6->Time = ADOTable1->FieldByName("supperend")->AsDateTime;
    cxTimeEdit7->Time = ADOTable1->FieldByName("nightstart")->AsDateTime;
    cxTimeEdit8->Time = ADOTable1->FieldByName("nightend")->AsDateTime;

    cxTextEdit1->Text = ADOTable1->FieldByName("breakfastmoney1")->AsFloat;
    cxTextEdit2->Text = ADOTable1->FieldByName("breakfastmoney2")->AsFloat;
    cxTextEdit3->Text = ADOTable1->FieldByName("lunchmoney1")->AsFloat;
    cxTextEdit4->Text = ADOTable1->FieldByName("lunchmoney2")->AsFloat;
    cxTextEdit5->Text = ADOTable1->FieldByName("suppermoney1")->AsFloat;
    cxTextEdit6->Text = ADOTable1->FieldByName("suppermoney2")->AsFloat;
    cxTextEdit7->Text = ADOTable1->FieldByName("nightmoney1")->AsFloat;
    cxTextEdit8->Text = ADOTable1->FieldByName("nightmoney2")->AsFloat;

    ADOTable1->Active = false;

}
//---------------------------------------------------------------------------

