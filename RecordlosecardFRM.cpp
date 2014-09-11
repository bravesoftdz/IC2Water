//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecordlosecardFRM.h"
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
TRecordLostCardFRM *RecordLostCardFRM;
//---------------------------------------------------------------------------
__fastcall TRecordLostCardFRM::TRecordLostCardFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRecordLostCardFRM::cxRadioButton1Click(TObject *Sender)
{
	cxTextEdit1->Enabled = true;
	cxTextEdit1->Text = "";
	cxTextEdit2->Text = "";
	cxTextEdit3->Text = "";
	cxTextEdit4->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit3->Enabled = false;
	cxTextEdit4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxRadioButton2Click(TObject *Sender)
{
	cxTextEdit2->Enabled = true;
	cxTextEdit2->Text = "";
	cxTextEdit1->Text = "";
	cxTextEdit3->Text = "";
	cxTextEdit4->Text = "";
	cxTextEdit1->Enabled = false;
	cxTextEdit3->Enabled = false;
	cxTextEdit4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxRadioButton3Click(TObject *Sender)
{
	cxTextEdit3->Enabled = true;
	cxTextEdit3->Text = "";
	cxTextEdit2->Text = "";
	cxTextEdit1->Text = "";
	cxTextEdit4->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit1->Enabled = false;
	cxTextEdit4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxRadioButton4Click(TObject *Sender)
{
	cxTextEdit4->Enabled = true;
	cxTextEdit4->Text = "";
	cxTextEdit2->Text = "";
	cxTextEdit3->Text = "";
	cxTextEdit1->Text = "";
	cxTextEdit2->Enabled = false;
	cxTextEdit3->Enabled = false;
	cxTextEdit1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::QueryBTNClick(TObject *Sender)
{
	if(!(cxRadioButton1->Checked)&&!(cxRadioButton2->Checked)
		&&!(cxRadioButton3->Checked)&&!(cxRadioButton4->Checked))
	{
		ShowMessage("请填写查询信息！");
	}
	else
	{
		String QueryStr = "";
		if(cxRadioButton1->Checked)
			QueryStr = cxTextEdit1->Text;
		if(cxRadioButton2->Checked)
			QueryStr = cxTextEdit2->Text;
		if(cxRadioButton3->Checked)
			QueryStr = cxTextEdit3->Text;
		if(cxRadioButton4->Checked)
			QueryStr = cxTextEdit4->Text;

		if(QueryStr.IsEmpty())
		{
			ShowMessage("请填写查询信息！");
		}
		else
		{
			String sql = "select * from CARD where ";

			if(cxRadioButton1->Checked)
			{
				AnsiString tmpstr;
				tmpstr.sprintf("%010I64d", StrToInt64(cxTextEdit1->Text));
				sql = sql + "BH='" + tmpstr + "'";
			}
			if(cxRadioButton2->Checked)
				sql = sql + "KH=" + cxTextEdit2->Text;
			if(cxRadioButton3->Checked)
				sql = sql + "XM='" + cxTextEdit3->Text + "'";
			if(cxRadioButton4->Checked)
				sql = sql + "SFZH='" + cxTextEdit4->Text + "'";

			if(0 == cxRadioGroup1->ItemIndex)
				sql += " and ZT='发卡'";
			if(1 == cxRadioGroup1->ItemIndex)
				sql += " and ZT='挂失'";

			LostCardADOQuery->Close();
			LostCardADOQuery->SQL->Clear();
			LostCardADOQuery->SQL->Add(sql);
			LostCardADOQuery->Open();

			if(!LostCardADOQuery->IsEmpty())
			{
				if(LostCardADOQuery->RecordCount > 1)
				{
					NextBTN->Visible = true;
					NextBTN->Enabled = true;
					LostCardADOQuery->First();
					cxTextEdit5->Text = LostCardADOQuery->FieldByName("BH")->AsString;
					cxTextEdit6->Text = LostCardADOQuery->FieldByName("XM")->AsString;
					cxTextEdit7->Text = LostCardADOQuery->FieldByName("BM")->AsString;
					cxTextEdit8->Text = LostCardADOQuery->FieldByName("ZW")->AsString;
					cxTextEdit9->Text = LostCardADOQuery->FieldByName("SF_KL")->AsString;
					cxTextEdit13->Text = LostCardADOQuery->FieldByName("JB")->AsString;
					cxTextEdit15->Text = LostCardADOQuery->FieldByName("SF_FL")->AsString;
					cxTextEdit16->Text = LostCardADOQuery->FieldByName("XB")->AsString;
					cxTextEdit19->Text = LostCardADOQuery->FieldByName("BZ")->AsString;
					cxTextEdit10->Text = LostCardADOQuery->FieldByName("ZB")->AsString;
					cxTextEdit11->Text = LostCardADOQuery->FieldByName("SFZH")->AsString;
					cxTextEdit12->Text = LostCardADOQuery->FieldByName("GRMM")->AsString;
					cxTextEdit17->Text = LostCardADOQuery->FieldByName("SF_YE")->AsString;
					cxTextEdit14->Text = LostCardADOQuery->FieldByName("KH")->AsString;
				}
				else if(LostCardADOQuery->RecordCount == 1)
				{
					NextBTN->Visible = false;
					NextBTN->Enabled = false;
					cxTextEdit5->Text = LostCardADOQuery->FieldByName("BH")->AsString;
					cxTextEdit6->Text = LostCardADOQuery->FieldByName("XM")->AsString;
					cxTextEdit7->Text = LostCardADOQuery->FieldByName("BM")->AsString;
					cxTextEdit8->Text = LostCardADOQuery->FieldByName("ZW")->AsString;
					cxTextEdit9->Text = LostCardADOQuery->FieldByName("SF_KL")->AsString;
					cxTextEdit13->Text = LostCardADOQuery->FieldByName("JB")->AsString;
					cxTextEdit15->Text = LostCardADOQuery->FieldByName("SF_FL")->AsString;
					cxTextEdit16->Text = LostCardADOQuery->FieldByName("XB")->AsString;
					cxTextEdit19->Text = LostCardADOQuery->FieldByName("BZ")->AsString;
					cxTextEdit10->Text = LostCardADOQuery->FieldByName("ZB")->AsString;
					cxTextEdit11->Text = LostCardADOQuery->FieldByName("SFZH")->AsString;
					cxTextEdit12->Text = LostCardADOQuery->FieldByName("GRMM")->AsString;
					cxTextEdit17->Text = LostCardADOQuery->FieldByName("SF_YE")->AsString;
					cxTextEdit14->Text = LostCardADOQuery->FieldByName("KH")->AsString;
				}
				PutLostInfoBTN->Enabled = true;
				DelLostInfoBTN->Enabled = true;
			}
			else
			{
				sql = "select * from CARD where ";

				if(cxRadioButton1->Checked)
				{
					AnsiString tmpstr;
					tmpstr.sprintf("%010I64d", StrToInt64(cxTextEdit1->Text));
					sql = sql + "BH='" + tmpstr + "'";
				}
				if(cxRadioButton2->Checked)
					sql = sql + "KH=" + cxTextEdit2->Text;
				if(cxRadioButton3->Checked)
					sql = sql + "XM='" + cxTextEdit3->Text + "'";
				if(cxRadioButton4->Checked)
					sql = sql + "SFZH='" + cxTextEdit4->Text + "'";

				if(0 == cxRadioGroup1->ItemIndex)
				{
					cxRadioGroup1->ItemIndex = 1;
					sql += " and ZT='挂失'";
				}
				else if(1 == cxRadioGroup1->ItemIndex)
				{
					cxRadioGroup1->ItemIndex = 0;
					sql += " and ZT='发卡'";
				}
				LostCardADOQuery->Close();
				LostCardADOQuery->SQL->Clear();
				LostCardADOQuery->SQL->Add(sql);
				LostCardADOQuery->Open();

				if(!LostCardADOQuery->IsEmpty())
				{
					if(LostCardADOQuery->RecordCount > 1)
					{
						NextBTN->Visible = true;
						NextBTN->Enabled = true;
						LostCardADOQuery->First();
						cxTextEdit5->Text = LostCardADOQuery->FieldByName("BH")->AsString;
						cxTextEdit6->Text = LostCardADOQuery->FieldByName("XM")->AsString;
						cxTextEdit7->Text = LostCardADOQuery->FieldByName("BM")->AsString;
						cxTextEdit8->Text = LostCardADOQuery->FieldByName("ZW")->AsString;
						cxTextEdit9->Text = LostCardADOQuery->FieldByName("SF_KL")->AsString;
						cxTextEdit13->Text = LostCardADOQuery->FieldByName("JB")->AsString;
						cxTextEdit15->Text = LostCardADOQuery->FieldByName("SF_FL")->AsString;
						cxTextEdit16->Text = LostCardADOQuery->FieldByName("XB")->AsString;
						cxTextEdit19->Text = LostCardADOQuery->FieldByName("BZ")->AsString;
						cxTextEdit10->Text = LostCardADOQuery->FieldByName("ZB")->AsString;
						cxTextEdit11->Text = LostCardADOQuery->FieldByName("SFZH")->AsString;
						cxTextEdit12->Text = LostCardADOQuery->FieldByName("GRMM")->AsString;
						cxTextEdit17->Text = LostCardADOQuery->FieldByName("SF_YE")->AsString;
						cxTextEdit14->Text = LostCardADOQuery->FieldByName("KH")->AsString;
					}
					else if(LostCardADOQuery->RecordCount == 1)
					{
						NextBTN->Visible = false;
						NextBTN->Enabled = false;
						cxTextEdit5->Text = LostCardADOQuery->FieldByName("BH")->AsString;
						cxTextEdit6->Text = LostCardADOQuery->FieldByName("XM")->AsString;
						cxTextEdit7->Text = LostCardADOQuery->FieldByName("BM")->AsString;
						cxTextEdit8->Text = LostCardADOQuery->FieldByName("ZW")->AsString;
						cxTextEdit9->Text = LostCardADOQuery->FieldByName("SF_KL")->AsString;
						cxTextEdit13->Text = LostCardADOQuery->FieldByName("JB")->AsString;
						cxTextEdit15->Text = LostCardADOQuery->FieldByName("SF_FL")->AsString;
						cxTextEdit16->Text = LostCardADOQuery->FieldByName("XB")->AsString;
						cxTextEdit19->Text = LostCardADOQuery->FieldByName("BZ")->AsString;
						cxTextEdit10->Text = LostCardADOQuery->FieldByName("ZB")->AsString;
						cxTextEdit11->Text = LostCardADOQuery->FieldByName("SFZH")->AsString;
						cxTextEdit12->Text = LostCardADOQuery->FieldByName("GRMM")->AsString;
						cxTextEdit17->Text = LostCardADOQuery->FieldByName("SF_YE")->AsString;
						cxTextEdit14->Text = LostCardADOQuery->FieldByName("KH")->AsString;
					}
					PutLostInfoBTN->Enabled = true;
					DelLostInfoBTN->Enabled = true;
				}
				else
					ShowMessage("没有符合查询条件的卡片!");
			}
		}
	}
//	QueryBTN->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::NextBTNClick(TObject *Sender)
{
	if(!LostCardADOQuery->Eof)
	{
		LostCardADOQuery->Next();
		cxTextEdit5->Text = LostCardADOQuery->FieldByName("BH")->AsString;
		cxTextEdit6->Text = LostCardADOQuery->FieldByName("XM")->AsString;
		cxTextEdit7->Text = LostCardADOQuery->FieldByName("BM")->AsString;
		cxTextEdit8->Text = LostCardADOQuery->FieldByName("ZW")->AsString;
		cxTextEdit9->Text = LostCardADOQuery->FieldByName("SF_KL")->AsString;
		cxTextEdit13->Text = LostCardADOQuery->FieldByName("JB")->AsString;
		cxTextEdit15->Text = LostCardADOQuery->FieldByName("SF_FL")->AsString;
		cxTextEdit16->Text = LostCardADOQuery->FieldByName("XB")->AsString;
		cxTextEdit19->Text = LostCardADOQuery->FieldByName("BZ")->AsString;
		cxTextEdit10->Text = LostCardADOQuery->FieldByName("ZB")->AsString;
		cxTextEdit11->Text = LostCardADOQuery->FieldByName("SFZH")->AsString;
		cxTextEdit12->Text = LostCardADOQuery->FieldByName("GRMM")->AsString;
		cxTextEdit17->Text = LostCardADOQuery->FieldByName("SF_YE")->AsString;
		cxTextEdit14->Text = LostCardADOQuery->FieldByName("KH")->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::PutLostInfoBTNClick(TObject *Sender)
{
	enableGS = false;
	int kh = StrToInt(cxTextEdit14->Text);
	String sql = "select * from CARD where BH='";
	sql = sql + cxTextEdit5->Text;
	sql += "'";
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

	sql = "select * from CARD_F where BH='";
	sql += cxTextEdit5->Text;
	sql += "'";
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
		ShowMessage("此卡信息不在CARD_F表中，请确认！");

	sql = "select * from KZT where BH='";
	sql += cxTextEdit5->Text;
	sql += "'";
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
		InDatabaseADOQuery->Parameters->ParamByName("GSRQ")->Value = DateTimeToStr(Now());
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
			InDatabaseADOQuery->Close();
			InDatabaseADOQuery->SQL->Clear();
			sql = "delete from CMDLIST where PARA=";
			sql += kh;
			sql += " and status=0";
	   //		ShowMessage(sql);
			InDatabaseADOQuery->SQL->Add(sql);
			InDatabaseADOQuery->ExecSQL();
			InDatabaseADOQuery->Close();

			InDatabaseADOQuery->SQL->Clear();
			sql = "insert into CMDLIST values(:SFJID,:SFJPORT,:CMD,:PARA,:STATUS,:SENDTIME)";
			InDatabaseADOQuery->SQL->Add(sql);
			for(i = 0; i < posnum; i++)
			{
				InDatabaseADOQuery->Parameters->ParamByName("SFJID")->Value = pos[i];
				InDatabaseADOQuery->Parameters->ParamByName("SFJPORT")->Value = port[i];
				InDatabaseADOQuery->Parameters->ParamByName("CMD")->Value = 1;
				InDatabaseADOQuery->Parameters->ParamByName("PARA")->Value = kh;
				InDatabaseADOQuery->Parameters->ParamByName("STATUS")->Value = 0;
				InDatabaseADOQuery->Parameters->ParamByName("SENDTIME")->Value = NULL;
				InDatabaseADOQuery->ExecSQL();
			}
			InDatabaseADOQuery->Close();

			//填写操作记录表
			InDatabaseADOQuery->SQL->Clear();
			sql =  "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
			InDatabaseADOQuery->SQL->Add(sql);
			InDatabaseADOQuery->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
			InDatabaseADOQuery->Parameters->ParamByName("KH")->Value = kh;
			InDatabaseADOQuery->Parameters->ParamByName("JE")->Value = 0;
			InDatabaseADOQuery->Parameters->ParamByName("YE")->Value = StrToFloat(cxTextEdit17->Text);
			InDatabaseADOQuery->Parameters->ParamByName("LX")->Value = "挂失";
			InDatabaseADOQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
			InDatabaseADOQuery->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
			InDatabaseADOQuery->ExecSQL();
			InDatabaseADOQuery->Close();
		}
		else
		{
			ShowMessage("该收费系统中没有入库的POS机！");
			InDatabaseADOQuery->Close();
		}
	}

	PutLostInfoBTN->Enabled = false;
	enableGS = true;
	if(mrOk == MessageBox(this->Handle, "登记挂失信息成功，是否将单条挂失记录下传!", "请选择", MB_OKCANCEL|MB_ICONQUESTION))
	{
		SingleGSForm->cxTextEdit1->Text = cxTextEdit14->Text;
        SingleGSForm->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::DelLostInfoBTNClick(TObject *Sender)
{
	enableGS = false;
	int kh = StrToInt(cxTextEdit14->Text);
	String sql = "select * from CARD where BH='";
	sql = sql + cxTextEdit5->Text;
	sql += "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("ZT")->AsString = "发卡";
		InDatabaseADOQuery->Post();
	}
	else
		ShowMessage("此卡信息不在CARD表中，请确认！");

	sql = "select * from CARD_F where BH='" + cxTextEdit5->Text;
	sql += "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("ZT")->AsString = "发卡";
		InDatabaseADOQuery->Post();
	}
	else
		ShowMessage("此卡信息不在CARD_F表中，请确认！");

	sql = "select * from KZT where BH='" + cxTextEdit5->Text;
	sql += "'";
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Edit();
		InDatabaseADOQuery->FieldByName("GS")->AsInteger = 0;
		InDatabaseADOQuery->FieldByName("SY")->AsString = "Y";
		InDatabaseADOQuery->Post();
	}
	else
		ShowMessage("此卡信息不在KZT表中，请确认！");

	sql = "select * from GS where BH='" + cxTextEdit5->Text;
	sql += "' and KH=";
	sql += kh;
	InDatabaseADOQuery->Close();
	InDatabaseADOQuery->SQL->Clear();
	InDatabaseADOQuery->SQL->Add(sql);
	InDatabaseADOQuery->Open();
	if(!InDatabaseADOQuery->IsEmpty())
	{
		InDatabaseADOQuery->Delete();
	}

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
 /*		InDatabaseADOQuery->Close();
		InDatabaseADOQuery->SQL->Clear();
		sql = "delete * from CMDLIST where PARA="+kh;
		InDatabaseADOQuery->SQL->Add(sql);
		InDatabaseADOQuery->Open();
		InDatabaseADOQuery->Close();  */

		InDatabaseADOQuery->SQL->Clear();
		sql = "insert into CMDLIST values(:SFJID,:SFJPORT,:CMD,:PARA,:STATUS,:SENDTIME)";
		InDatabaseADOQuery->SQL->Add(sql);
		for(i = 0; i < posnum; i++)
		{
			InDatabaseADOQuery->Parameters->ParamByName("SFJID")->Value = pos[i];
			InDatabaseADOQuery->Parameters->ParamByName("SFJPORT")->Value = port[i];
			InDatabaseADOQuery->Parameters->ParamByName("CMD")->Value = 2;
			InDatabaseADOQuery->Parameters->ParamByName("PARA")->Value = kh;
			InDatabaseADOQuery->Parameters->ParamByName("STATUS")->Value = 0;
			InDatabaseADOQuery->Parameters->ParamByName("SENDTIME")->Value = NULL;
			InDatabaseADOQuery->ExecSQL();
		}
		InDatabaseADOQuery->Close();

		InDatabaseADOQuery->SQL->Clear();
		sql =  "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
		InDatabaseADOQuery->SQL->Add(sql);
		InDatabaseADOQuery->Parameters->ParamByName("BH")->Value = cxTextEdit5->Text;
		InDatabaseADOQuery->Parameters->ParamByName("KH")->Value = kh;
		InDatabaseADOQuery->Parameters->ParamByName("JE")->Value = 0;
		InDatabaseADOQuery->Parameters->ParamByName("YE")->Value = StrToFloat(cxTextEdit17->Text);
		InDatabaseADOQuery->Parameters->ParamByName("LX")->Value = "解挂";
		InDatabaseADOQuery->Parameters->ParamByName("Operator")->Value = OperatorName;
		InDatabaseADOQuery->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
		InDatabaseADOQuery->ExecSQL();
		InDatabaseADOQuery->Close();

		DelLostInfoBTN->Enabled = false;
		enableGS = true;
		if(mrOk == MessageBox(this->Handle, "登记撤销挂失信息成功，是否将单条撤销挂失记录下传!", "请选择", MB_OKCANCEL|MB_ICONQUESTION))
		{
			SingleWDGSForm->cxTextEdit1->Text = cxTextEdit14->Text;
			SingleWDGSForm->ShowModal();
		}
	}
	else
	{
		ShowMessage("该收费系统中没有入库的POS机！");
		InDatabaseADOQuery->Close();
		DelLostInfoBTN->Enabled = false;
		enableGS = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxButton1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxTextEdit1Exit(TObject *Sender)
{
	if(cxTextEdit1->Text.Length() > 10)
	{
		ShowMessage("编号为10位数字，请重新输入!");
		cxTextEdit1->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TRecordLostCardFRM::cxTextEdit5KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

