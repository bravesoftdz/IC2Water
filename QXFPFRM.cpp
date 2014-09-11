//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QXFPFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tqxfpform *qxfpform;
//---------------------------------------------------------------------------
__fastcall Tqxfpform::Tqxfpform(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tqxfpform::FormShow(TObject *Sender)
{
	Edit1->Text = username;
	Edit2->Text = usergroup;

	String sqlstr = "select * from SYSUSER where USERNAME='";
	sqlstr += Edit1->Text;
	sqlstr += "' and GROUPNAME='";
	sqlstr += Edit2->Text;
	sqlstr += "'";

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(sqlstr);
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		String qxstr = ADOQuery1->FieldByName("priority")->AsString.Trim();
		if(qxstr == "")
		{
			CheckBox1->Checked = true;
			CheckBox2->Checked = true;
			CheckBox3->Checked = true;
			CheckBox4->Checked = true;
			CheckBox5->Checked = true;
			CheckBox6->Checked = true;
			CheckBox7->Checked = true;
			CheckBox8->Checked = true;
			CheckBox9->Checked = true;
			CheckBox10->Checked = true;
			CheckBox11->Checked = true;
			CheckBox12->Checked = true;
			CheckBox13->Checked = true;
			CheckBox14->Checked = true;
			CheckBox15->Checked = true;
			CheckBox16->Checked = true;
			CheckBox17->Checked = true;
			CheckBox18->Checked = true;
			CheckBox19->Checked = true;
			CheckBox20->Checked = true;
			CheckBox21->Checked = true;
			CheckBox22->Checked = true;
			CheckBox23->Checked = true;
			CheckBox24->Checked = true;
			CheckBox25->Checked = true;
			CheckBox26->Checked = true;
			CheckBox27->Checked = true;
			CheckBox28->Checked = true;
			CheckBox29->Checked = true;
			CheckBox30->Checked = true;
			CheckBox31->Checked = true;
			CheckBox32->Checked = true;
			CheckBox33->Checked = true;
			CheckBox34->Checked = true;
			CheckBox35->Checked = true;
			CheckBox36->Checked = true;
			CheckBox37->Checked = true;
			CheckBox38->Checked = true;
			CheckBox39->Checked = true;
			CheckBox40->Checked = true;
			CheckBox41->Checked = true;
			CheckBox42->Checked = true;
			CheckBox43->Checked = true;
			CheckBox44->Checked = true;
			CheckBox45->Checked = true;
			CheckBox46->Enabled = true;
		}
		else
		{
			char everyqx[50];
			ZeroMemory(everyqx, 50);
			strcpy(everyqx, qxstr.t_str());

			if('1' == everyqx[0])
				CheckBox1->Checked = true;
			else
				CheckBox1->Checked = false;

			if('1' == everyqx[1])
				CheckBox2->Checked = true;
			else
				CheckBox2->Checked = false;

			if('1' == everyqx[2])
				CheckBox3->Checked = true;
			else
				CheckBox3->Checked = false;

			if('1' == everyqx[3])
				CheckBox4->Checked = true;
			else
				CheckBox4->Checked = false;

			if('1' == everyqx[4])
				CheckBox5->Checked = true;
			else
				CheckBox5->Checked = false;

			if('1' == everyqx[5])
				CheckBox6->Checked = true;
			else
				CheckBox6->Checked = false;

			if('1' == everyqx[6])
				CheckBox7->Checked = true;
			else
				CheckBox7->Checked = false;

            if('1' == everyqx[7])
				CheckBox8->Checked = true;
			else
				CheckBox8->Checked = false;

			if('1' == everyqx[8])
				CheckBox9->Checked = true;
			else
				CheckBox9->Checked = false;

			if('1' == everyqx[9])
				CheckBox10->Checked = true;
			else
				CheckBox10->Checked = false;

			if('1' == everyqx[10])
				CheckBox11->Checked = true;
			else
				CheckBox11->Checked = false;

			if('1' == everyqx[11])
				CheckBox12->Checked = true;
			else
				CheckBox12->Checked = false;

			if('1' == everyqx[12])
				CheckBox13->Checked = true;
			else
				CheckBox13->Checked = false;

			if('1' == everyqx[13])
				CheckBox14->Checked = true;
			else
				CheckBox14->Checked = false;

			if('1' == everyqx[14])
				CheckBox15->Checked = true;
			else
				CheckBox15->Checked = false;

			if('1' == everyqx[15])
				CheckBox16->Checked = true;
			else
				CheckBox16->Checked = false;

			if('1' == everyqx[16])
				CheckBox17->Checked = true;
			else
				CheckBox17->Checked = false;

			if('1' == everyqx[17])
				CheckBox18->Checked = true;
			else
				CheckBox18->Checked = false;

			if('1' == everyqx[18])
				CheckBox19->Checked = true;
			else
				CheckBox19->Checked = false;

			if('1' == everyqx[19])
				CheckBox20->Checked = true;
			else
				CheckBox20->Checked = false;

			if('1' == everyqx[20])
				CheckBox21->Checked = true;
			else
				CheckBox21->Checked = false;

			if('1' == everyqx[21])
				CheckBox22->Checked = true;
			else
				CheckBox22->Checked = false;

			if('1' == everyqx[22])
				CheckBox23->Checked = true;
			else
				CheckBox23->Checked = false;

			if('1' == everyqx[23])
				CheckBox24->Checked = true;
			else
				CheckBox24->Checked = false;

			if('1' == everyqx[24])
				CheckBox25->Checked = true;
			else
				CheckBox25->Checked = false;

			if('1' == everyqx[25])
				CheckBox26->Checked = true;
			else
				CheckBox26->Checked = false;

			if('1' == everyqx[26])
				CheckBox27->Checked = true;
			else
				CheckBox27->Checked = false;

			if('1' == everyqx[27])
				CheckBox28->Checked = true;
			else
				CheckBox28->Checked = false;

			if('1' == everyqx[28])
				CheckBox29->Checked = true;
			else
				CheckBox29->Checked = false;

			if('1' == everyqx[29])
				CheckBox30->Checked = true;
			else
				CheckBox30->Checked = false;

			if('1' == everyqx[30])
				CheckBox31->Checked = true;
			else
				CheckBox31->Checked = false;

			if('1' == everyqx[31])
				CheckBox32->Checked = true;
			else
				CheckBox32->Checked = false;

			if('1' == everyqx[32])
				CheckBox33->Checked = true;
			else
				CheckBox33->Checked = false;

			if('1' == everyqx[33])
				CheckBox34->Checked = true;
			else
				CheckBox34->Checked = false;

			if('1' == everyqx[34])
				CheckBox35->Checked = true;
			else
				CheckBox35->Checked = false;

			if('1' == everyqx[35])
				CheckBox36->Checked = true;
			else
				CheckBox36->Checked = false;

			if('1' == everyqx[36])
				CheckBox37->Checked = true;
			else
				CheckBox37->Checked = false;

			if('1' == everyqx[37])
				CheckBox38->Checked = true;
			else
				CheckBox38->Checked = false;

			if('1' == everyqx[38])
				CheckBox39->Checked = true;
			else
				CheckBox39->Checked = false;

			if('1' == everyqx[39])
				CheckBox40->Checked = true;
			else
				CheckBox40->Checked = false;

			if('1' == everyqx[40])
				CheckBox41->Checked = true;
			else
				CheckBox41->Checked = false;

			if('1' == everyqx[41])
				CheckBox42->Checked = true;
			else
				CheckBox42->Checked = false;

			if('1' == everyqx[42])
				CheckBox43->Checked = true;
			else
				CheckBox43->Checked = false;

			if('1' == everyqx[43])
				CheckBox44->Checked = true;
			else
				CheckBox44->Checked = false;

			if('1' == everyqx[44])
				CheckBox45->Checked = true;
			else
				CheckBox45->Checked = false;

			if('1' == everyqx[45])
				CheckBox46->Checked = true;
			else
				CheckBox46->Checked = false;
		}
	}
	else
	{
		ShowMessage("系统中无该账户的信息!");
    }

	if("操作员" == usergroup)
	{
		CheckBox1->Checked = false;
		CheckBox1->Enabled = false;
		CheckBox2->Checked = false;
		CheckBox2->Enabled = false;
		CheckBox9->Checked = false;
		CheckBox9->Enabled = false;
		CheckBox15->Checked = false;
		CheckBox15->Enabled = false;
		CheckBox22->Checked = false;
		CheckBox22->Enabled = false;
		CheckBox23->Checked = false;
		CheckBox23->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tqxfpform::Button1Click(TObject *Sender)
{
	String qxstr = "";
	if(CheckBox1->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox2->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox3->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox4->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox5->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox6->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox7->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox8->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox9->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox10->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox11->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox12->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox13->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox14->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox15->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox16->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox17->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox18->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox19->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox20->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox21->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox22->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox23->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox24->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox25->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox26->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox27->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox28->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox29->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox30->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox31->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox32->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox33->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox34->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox35->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox36->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox37->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox38->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox39->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox40->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox41->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox42->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox43->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox44->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox45->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	if(CheckBox46->Checked)
		qxstr += "1";
	else
		qxstr += "0";

	String sqlstr = "select * from SYSUSER where USERNAME='";
	sqlstr += Edit1->Text;
	sqlstr += "' and GROUPNAME='";
	sqlstr += Edit2->Text;
	sqlstr += "'";

	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(sqlstr);
	ADOQuery1->Open();
	if(!ADOQuery1->IsEmpty())
	{
		ADOQuery1->Edit();
		ADOQuery1->FieldByName("priority")->AsString = qxstr;
		ADOQuery1->Post();
	}
	else
	{
		ShowMessage("系统中无该账户的信息!");
	}
	ShowMessage("权限分配成功!");
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------

