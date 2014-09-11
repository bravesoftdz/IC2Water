//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FireLostCardFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
TFireLostCardInfoFRM *FireLostCardInfoFRM;
//---------------------------------------------------------------------------
__fastcall TFireLostCardInfoFRM::TFireLostCardInfoFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxButton3Click(TObject *Sender)
{
	ADOQuery1->Close();
	ADOQuery2->Close();
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxRadioButton1Click(TObject *Sender)
{
	cxTextEdit1->Enabled = true;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = false;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = false;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxRadioButton2Click(TObject *Sender)
{
	cxTextEdit1->Enabled = false;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = true;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = false;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = false;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxRadioButton3Click(TObject *Sender)
{
	cxTextEdit1->Enabled = false;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = true;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = false;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxRadioButton4Click(TObject *Sender)
{
	cxTextEdit1->Enabled = false;
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit2->Text = "";
	cxTextEdit3->Enabled = false;
	cxTextEdit3->Text = "";
	cxTextEdit4->Enabled = true;
	cxTextEdit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxButton1Click(TObject *Sender)
{
	int tag = 0;
	String sql = "select * from CARD where ";
	if(!cxTextEdit1->Text.IsEmpty())
	{
		sql += "BH='";
		sql += cxTextEdit1->Text;
		sql += "'";
		tag = 1;
	}
	if(!cxTextEdit2->Text.IsEmpty())
	{
		sql += "KH=";
		sql += StrToInt(cxTextEdit2->Text);
		tag = 2;
	}
	if(!cxTextEdit3->Text.IsEmpty())
	{
		sql += "XM='";
		sql += cxTextEdit3->Text;
		sql += "'";
		tag = 3;
	}
	if(!cxTextEdit4->Text.IsEmpty())
	{
		sql += "SFZH='";
		sql += cxTextEdit4->Text;
		sql += "'";
		tag = 4;
	}

	if(0 != tag)
	{
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add(sql);
		ADOQuery1->Open();
		if(!ADOQuery1->IsEmpty())
		{
			if(ADOQuery1->RecordCount > 1)
			{
				NextBTN->Enabled = true;
				NextBTN->Visible = true;
				cxButton2->Enabled = true;
				ADOQuery1->First();
				cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
				cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
				cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
				cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
				cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
				cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
				cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
				cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

				cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
				cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
				cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
				cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
				cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
				cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;

				sycs = ADOQuery1->FieldByName("SYCS")->AsInteger;
			}
			else
			{
				NextBTN->Enabled = false;
				NextBTN->Visible = false;
				cxButton2->Enabled = true;
				cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
				cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
				cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
				cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
				cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
				cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
				cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
				cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

				cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
				cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
				cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
				cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
				cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
				cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
				sycs = ADOQuery1->FieldByName("SYCS")->AsInteger;
			}
			cxButton2->Enabled = true;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::NextBTNClick(TObject *Sender)
{
	if(!ADOQuery1->Eof)
	{
		ADOQuery1->Next();
		cxTextEdit14->Text = ADOQuery1->FieldByName("KH")->AsInteger;
		cxTextEdit5->Text = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
		cxTextEdit6->Text = ADOQuery1->FieldByName("XM")->AsAnsiString.Trim();
		cxTextEdit7->Text = ADOQuery1->FieldByName("BM")->AsAnsiString.Trim();
		cxTextEdit8->Text = ADOQuery1->FieldByName("ZW")->AsAnsiString.Trim();
		cxTextEdit9->Text = ADOQuery1->FieldByName("SF_KL")->AsAnsiString.Trim();
		cxTextEdit13->Text = ADOQuery1->FieldByName("JB")->AsAnsiString.Trim();
		cxTextEdit15->Text = ADOQuery1->FieldByName("SF_FL")->AsAnsiString.Trim();

		cxTextEdit16->Text = ADOQuery1->FieldByName("XB")->AsAnsiString.Trim();
		cxTextEdit19->Text = ADOQuery1->FieldByName("BZ")->AsAnsiString.Trim();
		cxTextEdit10->Text = ADOQuery1->FieldByName("ZB")->AsAnsiString.Trim();
		cxTextEdit11->Text = ADOQuery1->FieldByName("SFZH")->AsAnsiString.Trim();
		cxTextEdit12->Text = ADOQuery1->FieldByName("GRMM")->AsAnsiString.Trim();
		cxTextEdit17->Text = ADOQuery1->FieldByName("SF_YE")->AsFloat;
		sycs = ADOQuery1->FieldByName("SYCS")->AsInteger;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxTextEdit1Exit(TObject *Sender)
{
	if(cxTextEdit1->Text.Length() > 10)
	{
		ShowMessage("编号为10位数字，请重新输入!");
		cxTextEdit1->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFireLostCardInfoFRM::cxButton2Click(TObject *Sender)
{
//	enableGS = false;
	int kh = StrToInt(cxTextEdit14->Text);
	String sql = "select * from KZT where BH='";
	sql = sql + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		if(0 == InDatabaseADOQuery->FieldByName("GS")->AsInteger)
		{
			ShowMessage("该卡还没有挂失，请先进行挂失操作!");
			InDatabaseADOQuery->Close();
			return;
        }
	}
	else
	{
		ShowMessage("数据库中没有该卡信息，无法退卡!");
		InDatabaseADOQuery->Close();
		return;
    }

	sql = "select * from CARD where BH='";
	sql = sql + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("ZT")->AsString = "挂失";
		InDatabaseADOQuery->Post();
	}

	sql = "select * from CARD_F where BH='" + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("ZT")->AsString = "挂失";
		InDatabaseADOQuery->Post();
	}
	else
	{
		ShowMessage("此卡信息不在CARD_F表中，请确认！");
		InDatabaseADOQuery->Close();
		return;
	}
	InDatabaseADOQuery->Close();



	String tmpsql;
	String datetimestr = DateTimeToStr(Now());
	//CARD
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "select * from CARD where BH='" + cxTextEdit5->Text + "'";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Open();

	if(!ADOQuery2->IsEmpty())
	{
	//填写退卡表
		String sqlstr = "insert into CARD_T values(:BH,:KH,:BKH,:XM,:XB,";
		sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
						":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
						":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
						":SF_KL,:USERNAME,:YW,:TKCB,:BKCB,:TKOperator)";
		ADOQuery3->Close();
		ADOQuery3->SQL->Clear();
		ADOQuery3->SQL->Add(sqlstr);
		ADOQuery3->Parameters->ParamByName("BH")->Value = ADOQuery2->FieldByName("BH")->Value;
		ADOQuery3->Parameters->ParamByName("KH")->Value = ADOQuery2->FieldByName("KH")->Value;
		ADOQuery3->Parameters->ParamByName("BKH")->Value = ADOQuery2->FieldByName("BKH")->Value;
		ADOQuery3->Parameters->ParamByName("XM")->Value = ADOQuery2->FieldByName("XM")->Value;
		ADOQuery3->Parameters->ParamByName("XB")->Value = ADOQuery2->FieldByName("XB")->Value;
		ADOQuery3->Parameters->ParamByName("SFZH")->Value = ADOQuery2->FieldByName("SFZH")->Value;
		ADOQuery3->Parameters->ParamByName("BM")->Value = ADOQuery2->FieldByName("BM")->Value;
		ADOQuery3->Parameters->ParamByName("BZ")->Value = ADOQuery2->FieldByName("BZ")->Value;
		ADOQuery3->Parameters->ParamByName("ZB")->Value = ADOQuery2->FieldByName("ZB")->Value;
		ADOQuery3->Parameters->ParamByName("ZW")->Value = ADOQuery2->FieldByName("ZW")->Value;
		ADOQuery3->Parameters->ParamByName("JB")->Value = ADOQuery2->FieldByName("JB")->Value;
		ADOQuery3->Parameters->ParamByName("RQ")->Value = ADOQuery2->FieldByName("RQ")->Value;
		ADOQuery3->Parameters->ParamByName("TKRQ")->Value = datetimestr;//ADOQuery2->FieldByName("TKRQ")->Value;
		ADOQuery3->Parameters->ParamByName("YJ")->Value = ADOQuery2->FieldByName("YJ")->Value;
		ADOQuery3->Parameters->ParamByName("TYJ")->Value = ADOQuery2->FieldByName("TYJ")->Value;
		ADOQuery3->Parameters->ParamByName("ZT")->Value = "退卡";//ADOQuery2->FieldByName("ZT")->Value;
		ADOQuery3->Parameters->ParamByName("GRMM")->Value = ADOQuery2->FieldByName("GRMM")->Value;
		ADOQuery3->Parameters->ParamByName("BTBZ")->Value = ADOQuery2->FieldByName("BTBZ")->Value;
		ADOQuery3->Parameters->ParamByName("BT_YE")->Value = ADOQuery2->FieldByName("BT_YE")->Value;
		ADOQuery3->Parameters->ParamByName("BTYEDT")->Value = ADOQuery2->FieldByName("BTYEDT")->Value;
		ADOQuery3->Parameters->ParamByName("BTSYCS")->Value = ADOQuery2->FieldByName("BTSYCS")->Value;
		ADOQuery3->Parameters->ParamByName("SF_YE")->Value = ADOQuery2->FieldByName("SF_YE")->Value;
		ADOQuery3->Parameters->ParamByName("SFYEDT")->Value = ADOQuery2->FieldByName("SFYEDT")->Value;
		ADOQuery3->Parameters->ParamByName("SYCS")->Value = ADOQuery2->FieldByName("SYCS")->Value;
		ADOQuery3->Parameters->ParamByName("FKSK")->Value = ADOQuery2->FieldByName("FKSK")->Value;
		ADOQuery3->Parameters->ParamByName("SF_FL")->Value = ADOQuery2->FieldByName("SF_FL")->Value;
		ADOQuery3->Parameters->ParamByName("GLF")->Value = ADOQuery2->FieldByName("GLF")->Value;
		ADOQuery3->Parameters->ParamByName("FKJE")->Value = ADOQuery2->FieldByName("FKJE")->Value;
		ADOQuery3->Parameters->ParamByName("TKJE")->Value = ADOQuery2->FieldByName("SF_YE")->Value;
		ADOQuery3->Parameters->ParamByName("TKBT")->Value = ADOQuery2->FieldByName("BT_YE")->Value;
		ADOQuery3->Parameters->ParamByName("SF_KL")->Value = ADOQuery2->FieldByName("SF_KL")->Value;
		ADOQuery3->Parameters->ParamByName("USERNAME")->Value = ADOQuery2->FieldByName("USERNAME")->Value;
		ADOQuery3->Parameters->ParamByName("YW")->Value = 0;
        ADOQuery3->Parameters->ParamByName("TKCB")->Value = 0;
        ADOQuery3->Parameters->ParamByName("BKCB")->Value = 0;
        ADOQuery3->Parameters->ParamByName("TKOperator")->Value = OperatorName;
		ADOQuery3->ExecSQL();
		ADOQuery3->Close();

		ADOQuery2->Delete();
	}

	//CARD_F
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "select * from CARD_F where BH='" + cxTextEdit5->Text + "'";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Open();
	ADOQuery2->Edit();
	ADOQuery2->FieldByName("ZT")->AsString = "退卡";
	ADOQuery2->Post();

	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "select * from CARD_F where BH='" + cxTextEdit5->Text + "'";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Open();
//	ADOQuery2->Delete();

	//KZT
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "select * from KZT where BH='" + cxTextEdit5->Text + "'";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Open();
	ADOQuery2->Edit();
	ADOQuery2->FieldByName("KH")->AsInteger = StrToInt(cxTextEdit14->Text);
	ADOQuery2->FieldByName("TKRQ")->AsString = datetimestr;
	ADOQuery2->FieldByName("WITHCARDTK")->AsString = "N";
	ADOQuery2->FieldByName("SY")->AsString = 'T';
    ADOQuery2->FieldByName("GS")->AsString = '0';
	ADOQuery2->Post();

	//MX
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "insert into MX values(:BH,:KH,:SF_YE,";
	tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
	tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = datetimestr;
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "Q";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = datetimestr;
	ADOQuery2->ExecSQL();

	//MXBAK
/*	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "insert into MXBAK values(:BH,:KH,:SF_YE,";
	tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
	tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = datetimestr;
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "Q";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = datetimestr;
	ADOQuery2->ExecSQL(); */

	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
	tmpsql += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Parameters->ParamByName("kh")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("bh")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("sf_ye")->Value = -StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("sf_fl")->Value = 1;
	ADOQuery2->Parameters->ParamByName("ckxj")->Value = -StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("glf")->Value = 0;
	ADOQuery2->Parameters->ParamByName("ckje")->Value = -StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("lqbt")->Value = 0;
	ADOQuery2->Parameters->ParamByName("xkje")->Value = -StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("sycs")->Value = 0;
	ADOQuery2->Parameters->ParamByName("sfrq")->Value = datetimestr;
	ADOQuery2->Parameters->ParamByName("jyno")->Value = 0;
	ADOQuery2->Parameters->ParamByName("gzzid")->Value = 1;
	ADOQuery2->Parameters->ParamByName("sflx")->Value = "Q";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->ExecSQL();
	ADOQuery2->Close();
/*
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "insert into MXBAK values(:BH,:KH,:SF_YE,";
	tmpsql = tmpsql + ":SFJE,:SYCS,:SFRQ,:JYNO,";
	tmpsql = tmpsql + ":GZZID,:SFLX,:CZY,:SCRQ)";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = StrToFloat(cxTextEdit18->Text);
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "R";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->ExecSQL();  */

	//填写操作记录表
  	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	tmpsql = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
	ADOQuery2->SQL->Add(tmpsql);
	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("JE")->Value = -StrToFloat(cxTextEdit17->Text);
	ADOQuery2->Parameters->ParamByName("YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("LX")->Value = "无卡退卡";
	ADOQuery2->Parameters->ParamByName("Operator")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("DateTime")->Value = datetimestr;
	ADOQuery2->ExecSQL();
	ADOQuery2->Close();

/*	ADOQuery2->Close();
    ADOQuery2->SQL->Clear();
    String deletestr = "delete from MX where BH='";
    deletestr += cxTextEdit5->Text;
    deletestr += "'";
    ADOQuery2->SQL->Add(deletestr);
    ADOQuery2->ExecSQL();
    ADOQuery2->Close();
    ADOQuery2->SQL->Clear();
    deletestr = "delete from MXBAK where BH='";
    deletestr += cxTextEdit5->Text;
    deletestr += "'";
    ADOQuery2->SQL->Add(deletestr);
    ADOQuery2->ExecSQL();
	ADOQuery2->Close();   */
/*	String wsqlstr = "select * from Wallet where KH=";
	wsqlstr += cxTextEdit14->Text;
	wsqlstr += " and BH='";
	wsqlstr += cxTextEdit5->Text;
	wsqlstr += "'";
	ADOQuery2->Close();
	ADOQuery2->SQL->Clear();
	ADOQuery2->SQL->Add(wsqlstr);
	ADOQuery2->Open();
	if(!ADOQuery2->IsEmpty())
	{
		int walletye = ADOQuery2->FieldByName("SF_YE")->AsInteger;
		String walletstr = "该卡片钱包中仍有余额￥";
		walletstr += walletye;
		walletstr += ",请将余额退还用户!";
		ShowMessage(walletstr);
		ADOQuery2->Delete();

		//大钱包清空，OperationList表
		String opsqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
		ADOQuery2->Close();
		ADOQuery2->SQL->Clear();
		ADOQuery2->SQL->Add(opsqlstr);
		ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit7->Text;
		ADOQuery2->Parameters->ParamByName("KH")->Value = StrToInt(cxTextEdit1->Text);
		ADOQuery2->Parameters->ParamByName("JE")->Value = walletye;
		ADOQuery2->Parameters->ParamByName("YE")->Value = 0;
		ADOQuery2->Parameters->ParamByName("LX")->Value = "钱包清空";
		ADOQuery2->Parameters->ParamByName("Operator")->Value = OperatorName;
		SYSTEMTIME tmpsystime;
		GetLocalTime(&tmpsystime);
		ADOQuery2->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(SystemTimeToDateTime(tmpsystime));
		ADOQuery2->ExecSQL();
		ADOQuery2->Close();
	}                    */
	ADOQuery2->Close();

	MessageBox(this->Handle, "无卡退卡成功!", "OK", MB_OK|MB_ICONINFORMATION);

	ADOQuery1->Close();
	ADOQuery2->Close();









  /*
	sql = "select * from KZT where BH='" + cxTextEdit5->Text + "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("GS")->AsInteger = 1;
		InDatabaseADOQuery->Post();
	}
	else
		ShowMessage("此卡信息不在KZT表中，请确认！");

	sql = "select * from GS where BH='";
	sql += cxTextEdit5->Text;
	sql += "' and KH=";
	sql += kh;
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(InDatabaseADOQuery->IsEmpty())
	{
		sql = "insert into GS values(:BH,:KH,:GSRQ,:USERNAME)";
		InDatabaseADOQuery->Close();
		InDatabaseADOQuery->SQL->Clear();
		InDatabaseADOQuery->SQL->Add(sql);
		InDatabaseADOQuery->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
		InDatabaseADOQuery->Parameters->ParamByName("KH")->Value = kh;
		InDatabaseADOQuery->Parameters->ParamByName("GSRQ")->Value = DateToStr(Date());
		InDatabaseADOQuery->Parameters->ParamByName("USERNAME")->Value = OperatorName;
		InDatabaseADOQuery->ExecSQL();

		InDatabaseADOQuery->Close();
		InDatabaseADOQuery->SQL->Clear();
		sql = "select * from SFJPARAM";
		InDatabaseADOQuery->SQL->Add(sql);
		InDatabaseADOQuery->Open();
		if(!InDatabaseADOQuery->IsEmpty())
		{
			int pos[2000];
			int port[2000];
			int i = 0;
			InDatabaseADOQuery->First();
			while(!InDatabaseADOQuery->Eof)
			{
				pos[i] = InDatabaseADOQuery->FieldByName("JH")->AsInteger;
				port[i] = InDatabaseADOQuery->FieldByName("SFJPORT")->AsInteger;
				i++;
				InDatabaseADOQuery->Next();
			}
			int posnum = i;
			InDatabaseADOQuery->Close();


			InDatabaseADOQuery->SQL->Clear();
			sql = "insert into CMDLIST values(:SFJPORT,:SFJD,:CMD,:PARA,:STATUS,:SENDTIME)";
			InDatabaseADOQuery->SQL->Add(sql);
			for(i = 0; i < posnum; i++)
			{
				InDatabaseADOQuery->Parameters->ParamByName("SFJPORT")->Value = port[i];
				InDatabaseADOQuery->Parameters->ParamByName("SFJD")->Value = pos[i];
				InDatabaseADOQuery->Parameters->ParamByName("CMD")->Value = 1;
				InDatabaseADOQuery->Parameters->ParamByName("PARA")->Value = kh;
				InDatabaseADOQuery->Parameters->ParamByName("STATUS")->Value = 0;
				InDatabaseADOQuery->Parameters->ParamByName("SENDTIME")->Value = NULL;
				InDatabaseADOQuery->ExecSQL();
			}
			InDatabaseADOQuery->Close();

			enableGS = true;
		//	ShowMessage("登记挂失信息成功！");

		//InDataBase

		}
		else
		{
			ShowMessage("该收费系统中没有入库的POS机！");
			InDatabaseADOQuery->Close();
			cxButton2->Enabled = false;
			cxButton3->Enabled = false;
			enableGS = true;
		}
	}

	//--------------------------------------
*/

}
//---------------------------------------------------------------------------

/*
	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "U";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->ExecSQL();

	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "W";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->ExecSQL();   */

/*			ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "U";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->ExecSQL();

	ADOQuery2->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
	ADOQuery2->Parameters->ParamByName("KH")->Value = atoi(cxTextEdit14->Text.t_str());
	ADOQuery2->Parameters->ParamByName("SF_YE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SFJE")->Value = 0;
	ADOQuery2->Parameters->ParamByName("SYCS")->Value = sycs;
	ADOQuery2->Parameters->ParamByName("SFRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->Parameters->ParamByName("JYNO")->Value = 0;
	ADOQuery2->Parameters->ParamByName("GZZID")->Value = 1;
	ADOQuery2->Parameters->ParamByName("SFLX")->Value = "W";
	ADOQuery2->Parameters->ParamByName("CZY")->Value = OperatorName;
	ADOQuery2->Parameters->ParamByName("SCRQ")->Value = DateTimeToStr(Now());
	ADOQuery2->ExecSQL();     */

	   /*			InDatabaseADOQuery->SQL->Clear();
			sql = "delete * from CMDLIST where PARA="+kh;
			InDatabaseADOQuery->SQL->Add(sql);
			InDatabaseADOQuery->ExecSQL();
			InDatabaseADOQuery->Close();   */
void __fastcall TFireLostCardInfoFRM::cxTextEdit18KeyPress(TObject *Sender, wchar_t &Key)

{
	Key = 0;
}
//---------------------------------------------------------------------------

