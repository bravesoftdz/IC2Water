//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SectionInfoMngFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
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
#pragma link "dxSkinscxPCPainter"
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
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxContainer"
#pragma link "cxDropDownEdit"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBEdit"
#pragma resource "*.dfm"
TSectionInfoManageFRM *SectionInfoManageFRM;

//---------------------------------------------------------------------------
__fastcall TSectionInfoManageFRM::TSectionInfoManageFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::e(TObject *Sender)
{
//	ShowMessage(SectionNameComboBox->Text);
	if(!SectionNameComboBox->Text.IsEmpty())
	{
		SubSectionInfoADOQ->Close();
		SubSectionInfoADOQ->SQL->Clear();
		SubSectionInfoADOQ->SQL->Add("select * from BANBIE where BUMEN='"+
									(SectionNameComboBox->Text)+"'");
		SubSectionInfoADOQ->Open();
		SubSectionInfoGridTVNUMCol->DataBinding->FieldName = "DM";
		SubSectionInfoGridTVSNameCol->DataBinding->FieldName = "BUMEN";
		SubSectionInfoGridTVBnameCol->DataBinding->FieldName = "BANBIE";

		ClassNameDBTextEdit->DataBinding->DataField = "BANBIE";
		cxDBTextEdit2->DataBinding->DataField = "BANBIE";
	}
//	SubSectionInfoADOQ->Close();
}

//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::SectionNameComboBox1PropertiesChange(TObject *Sender)
{
	if(!SectionNameComboBox1->Text.IsEmpty())
	{
		GroupInfoGridTVNumCol->DataBinding->FieldName = "";
		GroupInfoGridTVSNameCol->DataBinding->FieldName = "";
		GroupInfoGridTVCNameCol->DataBinding->FieldName = "";
		GroupInfoGridTVGNameCol->DataBinding->FieldName = "";
		GroupNameDBTextEdit->DataBinding->DataField = "";
		cxDBTextEdit3->DataBinding->DataField = "";
		GroupInfoADOQ->Close();
		GroupInfoADOQ->SQL->Clear();
		GroupInfoADOQ->SQL->Add("select * from BANBIE where BUMEN = '"+
								(SectionNameComboBox1->Text)+"'");
		GroupInfoADOQ->Open();
		ClassNameComboBox->Properties->Items->Clear();
		while(!GroupInfoADOQ->Eof)
		{
			ClassNameComboBox->Properties->Items->Add(GroupInfoADOQ->FieldByName("BANBIE")->AsString);
			GroupInfoADOQ->Next();
		}
		ClassNameComboBox->ItemIndex = -1;
		GroupInfoADOQ->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::ClassNameComboBoxPropertiesChange(TObject *Sender)
{
	if((!ClassNameComboBox->Text.IsEmpty())&&(!SectionNameComboBox1->Text.IsEmpty()))
	{
		GroupInfoADOQ->Close();
		GroupInfoADOQ->SQL->Clear();
		GroupInfoADOQ->SQL->Add("select * from ZUBIE where BUMEN = '"+
								(SectionNameComboBox1->Text)+"'"+"and "+
								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
//		ShowMessage("select * from ZUBIE where BUMEN = '"+
//								(SectionNameComboBox1->Text)+"'"+"and "+
//								"BANBIE = '"+(ClassNameComboBox->Text)+"'");
		GroupInfoADOQ->Open();
//		if(!GroupInfoADOQ->IsEmpty())
//		{
			GroupInfoGridTVNumCol->DataBinding->FieldName = "DM";
			GroupInfoGridTVSNameCol->DataBinding->FieldName = "BUMEN";
			GroupInfoGridTVCNameCol->DataBinding->FieldName = "BANBIE";
			GroupInfoGridTVGNameCol->DataBinding->FieldName = "ZUBIE";
			GroupNameDBTextEdit->DataBinding->DataField = "ZUBIE";
			cxDBTextEdit3->DataBinding->DataField = "ZUBIE";
//		}
//		GroupInfoADOQ->Close();//del
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::SectionInfoFixBTNClick(TObject *Sender)
{
//	SectionInfoFixFROM->SectionInfoFixEdit->Text = SectionInfoADOT->FieldByName("BUMEN")->AsString;
//	SectionInfoFixFROM->ShowModal();
	if(!cxTextEdit8->Text.IsEmpty())
	{
		SectionInfoADOT->Edit();
		SectionInfoADOT->FieldByName("BUMEN")->AsString = cxTextEdit8->Text;
		SectionInfoADOT->Post();
		ShowMessage("部门名称修改成功!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton3Click(TObject *Sender)
{
	String itemstr = "您确认删除\"" + SectionInfoADOT->FieldByName("BUMEN")->AsString + "\"吗?";
	if(mrOk == MessageBox(this->Handle, itemstr.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
	{
		SectionInfoADOT->Delete();
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton4Click(TObject *Sender)
{
	if(!cxTextEdit1->Text.IsEmpty())
	{
		SectionInfoADOT->InsertRecord(ARRAYOFCONST((cxTextEdit1->Text)));
		cxTextEdit1->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton6Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton10Click(TObject *Sender)
{
	if(!cxTextEdit3->Text.IsEmpty())
	{
		if(SectionNameComboBox->ItemIndex != -1)
		{
			SubSectionInfoADOQ->InsertRecord(ARRAYOFCONST((SectionNameComboBox->Text, cxTextEdit3->Text)));
			cxTextEdit3->Text = "";
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton12Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton11Click(TObject *Sender)
{
	if(!SubSectionInfoADOQ->IsEmpty())
	{
		String itemstr = "您确认删除\"" + SubSectionInfoADOQ->FieldByName("BANBIE")->AsString + "\"吗?";
		if(mrOk == MessageBox(this->Handle, itemstr.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			SubSectionInfoADOQ->Delete();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton7Click(TObject *Sender)
{
	if(!cxTextEdit9->Text.IsEmpty())
	{
		SubSectionInfoADOQ->Edit();
		SubSectionInfoADOQ->FieldByName("BANBIE")->AsString = cxTextEdit9->Text;
		SubSectionInfoADOQ->Post();
		ShowMessage("分部门名称修改成功!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton16Click(TObject *Sender)
{
	if(!SectionNameComboBox1->Text.IsEmpty()&&!ClassNameComboBox->Text.IsEmpty()&&!cxTextEdit2->Text.IsEmpty())
	{
		GroupInfoADOQ->InsertRecord(ARRAYOFCONST((SectionNameComboBox1->Text, ClassNameComboBox->Text, cxTextEdit2->Text)));
		cxTextEdit2->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton13Click(TObject *Sender)
{
	if(!cxTextEdit10->Text.IsEmpty())
	{
		GroupInfoADOQ->Edit();
		GroupInfoADOQ->FieldByName("ZUBIE")->AsString = cxTextEdit10->Text;
		GroupInfoADOQ->Post();
		ShowMessage("组别名称修改成功!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton17Click(TObject *Sender)
{
	if(!GroupInfoADOQ->IsEmpty())
	{
		String itemstr = "您确认删除\"" + GroupInfoADOQ->FieldByName("ZUBIE")->AsString + "\"吗?";
		if(mrOk == MessageBox(this->Handle, itemstr.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			GroupInfoADOQ->Delete();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton18Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton22Click(TObject *Sender)
{
	if(!cxTextEdit4->Text.IsEmpty())
	{
		SFADOT->InsertRecord(ARRAYOFCONST((cxTextEdit4->Text)));
		cxTextEdit4->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton19Click(TObject *Sender)
{
	if(!cxTextEdit11->Text.IsEmpty())
	{
		SFADOT->Edit();
		SFADOT->FieldByName("ZW")->AsString = cxTextEdit11->Text;
		SFADOT->Post();
		ShowMessage("身份名称修改成功!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton23Click(TObject *Sender)
{
	if(!SFADOT->IsEmpty())
	{
		String itemstr = "您确认删除\"" + SFADOT->FieldByName("ZW")->AsString + "\"吗?";
		if(mrOk == MessageBox(this->Handle, itemstr.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			SFADOT->Delete();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton24Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton28Click(TObject *Sender)
{
	if(!cxTextEdit5->Text.IsEmpty())
	{
		STADOT->InsertRecord(ARRAYOFCONST((cxTextEdit5->Text)));
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton25Click(TObject *Sender)
{
	if(!cxTextEdit12->Text.IsEmpty())
	{
		STADOT->Edit();
		STADOT->FieldByName("STNAME")->AsString = cxTextEdit12->Text;
		STADOT->Post();
		ShowMessage("消费地点名称修改成功!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton29Click(TObject *Sender)
{
	if(!STADOT->IsEmpty())
	{
		String itemstr = "您确认删除\"" + STADOT->FieldByName("STNAME")->AsString + "\"吗?";
		if(mrOk == MessageBox(this->Handle, itemstr.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
			STADOT->Delete();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton30Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxPageControl1Click(TObject *Sender)
{
	if(1 == cxPageControl1->ActivePageIndex)
	{
		cxDBTextEdit2->DataBinding->DataField = "";
		ClassNameDBTextEdit->DataBinding->DataField = "";
		SubSectionInfoADOQ->Close();
		SubSectionInfoADOQ->SQL->Clear();
		SubSectionInfoADOQ->SQL->Add("select * from BUMEN");
		SubSectionInfoADOQ->Open();
		SectionNameComboBox->Properties->Items->Clear();
		while(!SubSectionInfoADOQ->Eof)
		{
			SectionNameComboBox->Properties->Items->Add(SubSectionInfoADOQ->FieldByName("BUMEN")->AsString);
			SubSectionInfoADOQ->Next();
		}
		SectionNameComboBox->ItemIndex = -1;
		SectionNameComboBox->Text = "";
		SubSectionInfoADOQ->Close();
	}

	if(2 == cxPageControl1->ActivePageIndex)
	{
		cxDBTextEdit3->DataBinding->DataField = "";
		GroupNameDBTextEdit->DataBinding->DataField = "";
		GroupInfoADOQ->Close();
		GroupInfoADOQ->SQL->Clear();
		GroupInfoADOQ->SQL->Add("select * from BUMEN");
		GroupInfoADOQ->Open();
		SectionNameComboBox1->Properties->Items->Clear();
		while(!GroupInfoADOQ->Eof)
		{
			SectionNameComboBox1->Properties->Items->Add(GroupInfoADOQ->FieldByName("BUMEN")->AsString);
			GroupInfoADOQ->Next();
		}
		SectionNameComboBox1->ItemIndex = -1;
		SectionNameComboBox1->Text = "";
		ClassNameComboBox->ItemIndex = -1;
		ClassNameComboBox->Text = "";
		GroupInfoADOQ->Close();
	}

	if(5 == cxPageControl1->ActivePageIndex)
	{
		USERADOQ->Close();
		USERADOQ->SQL->Clear();
		USERADOQ->SQL->Add("select * from GROUPINFO");
		USERADOQ->Open();
		cxComboBox1->Properties->Items->Clear();
		while(!USERADOQ->Eof)
		{
			cxComboBox1->Properties->Items->Add(USERADOQ->FieldByName("GROUPNAME")->AsString);
			USERADOQ->Next();
		}
		cxComboBox1->ItemIndex = -1;
		cxComboBox1->Text = "";
		USERADOQ->Close();
	}

    if(6 == cxPageControl1->ActivePageIndex)
    {
        if("系统管理员" == OperatorGroupName)
		{
			cxButton2->Enabled = true;
			cxButton1->Enabled = true;
			cxButton5->Enabled = true;
		}
		else
		{
			cxButton2->Enabled = false;
			cxButton1->Enabled = false;
			cxButton5->Enabled = false;
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxTabSheet4Show(TObject *Sender)
{
	SFADOT->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxTabSheet1Show(TObject *Sender)
{
	SectionInfoADOT->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxTabSheet6Show(TObject *Sender)
{
	USERADOT->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton2Click(TObject *Sender)
{
	if((!cxTextEdit6->Text.IsEmpty())&&(!cxTextEdit14->Text.IsEmpty())&&(-1 != cxComboBox1->ItemIndex))
	{
        USERADOQ->Close();
        String checksqlstr = "select * from SYSUSER where USERNAME='";
        checksqlstr += cxTextEdit6->Text;
        checksqlstr += "'";
        USERADOQ->SQL->Clear();
        USERADOQ->SQL->Add(checksqlstr);
        USERADOQ->Open();
        if(!USERADOQ->IsEmpty())
        {
            ShowMessage("该用户名已经存在，请更换!");
            USERADOQ->Close();
            return;
        }
        USERADOQ->Close();
		if(cxTextEdit14->Text.IsEmpty()||(8!=cxTextEdit14->Text.Length()))
        {
            ShowMessage("密码不能为空，且密码长度必须为8位!");
            return;
        }

        char OLPW[8];
        char ENPW[9];
        ZeroMemory(OLPW, 8);
        ZeroMemory(ENPW, 9);
        String tmppwstr = cxTextEdit14->Text;
        for(int i=0; i<4; i++)
        {
            int tmpint = StrToInt("0x"+tmppwstr.SubString(i*2+1, 2));
        	IntToUChar(tmpint, &OLPW[i]);
        }
        EncrptyCardMMProc(0, OLPW, ENPW);

		char Inbasechar[17];
        ZeroMemory(Inbasechar, 17);
        for(int t = 0; t<8; t++)
        {
            char tmp;
            tmp = ENPW[t]>>4;
            tmp = tmp&0x0f;
            if(tmp >= 10)
                Inbasechar[t*2] = tmp+55;
            if(tmp <10)
                Inbasechar[t*2] = tmp+48;
            tmp = ENPW[t]&0x0f;
            if(tmp >= 10)
                Inbasechar[t*2+1] = tmp+55;
            if(tmp <10)
                Inbasechar[t*2+1] = tmp+48;
        }

        String stortstr = Inbasechar;

		USERADOT->InsertRecord(ARRAYOFCONST((cxTextEdit6->Text, Inbasechar, cxComboBox1->ItemIndex+1, cxComboBox1->Text)));
	}
	else
	{
        ShowMessage("必须完整的填写用户名，用户组及密码!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton5Click(TObject *Sender)
{
	if(!USERADOT->IsEmpty())
	{
		String itemstr = "您确认删除\"" + USERADOT->FieldByName("USERNAME")->AsString.Trim() + "\"吗?";
		if(mrOk == MessageBox(this->Handle, itemstr.t_str(), "请确认", MB_OKCANCEL|MB_ICONQUESTION))
		{
        	if(USERADOT->FieldByName("USERNAME")->AsString.Trim() == "ADMIN")
            {
                ShowMessage("ADMIN为默认系统管理员，不能删除!");
                return;
            }
			USERADOT->Delete();
            ShowMessage("用户删除成功!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton1Click(TObject *Sender)
{
	if(cxTextEdit14->Text.IsEmpty()||(8 != cxTextEdit14->Text.Length()))
	{
		ShowMessage("必须输入8位的原始密码!");
		return;
	}
	else
	{
		char OLPW1[8];
		char ENPW1[9];
		ZeroMemory(OLPW1, 8);
		ZeroMemory(ENPW1, 9);
		String tmppwstr1 = cxTextEdit14->Text;
		for(int i=0; i<4; i++)
		{
			int tmpint = StrToInt("0x"+tmppwstr1.SubString(i*2+1, 2));
			IntToUChar(tmpint, &OLPW1[i]);
		}
		EncrptyCardMMProc(0, OLPW1, ENPW1);
		char Inbasechar1[17];
		ZeroMemory(Inbasechar1, 17);
		for(int t = 0; t<8; t++)
		{
			char tmp;
			tmp = ENPW1[t]>>4;
			tmp = tmp&0x0f;
			if(tmp >= 10)
				Inbasechar1[t*2] = tmp+55;
			if(tmp <10)
				Inbasechar1[t*2] = tmp+48;
			tmp = ENPW1[t]&0x0f;
			if(tmp >= 10)
				Inbasechar1[t*2+1] = tmp+55;
			if(tmp <10)
				Inbasechar1[t*2+1] = tmp+48;
		}

		String stortstr = Inbasechar1;
		if(stortstr != USERADOT->FieldByName("PASSWORD")->AsString.Trim())
		{
			ShowMessage("原始密码不正确!");
			return;
        }
	}

	if(!cxTextEdit13->Text.IsEmpty())
	{
    	if((8==cxTextEdit7->Text.Length())||(cxTextEdit7->Text.IsEmpty()))
        {
        	if(cxTextEdit7->Text.IsEmpty())
            {
				if("ADMIN" == USERADOT->FieldByName("USERNAME")->AsString.Trim())
				{
                    ShowMessage("不能修改超级用户名称!");
                    return;
                }
                USERADOT->Edit();
                USERADOT->FieldByName("USERNAME")->AsString = cxTextEdit13->Text;
                USERADOT->Post();
                cxTextEdit7->Text = "";
                ShowMessage("系统用户名修改成功!");
				return;
			}

			char OLPW[8];
			char ENPW[9];
			ZeroMemory(OLPW, 8);
			ZeroMemory(ENPW, 9);
			String tmppwstr = cxTextEdit7->Text;
			for(int i=0; i<4; i++)
			{
				int tmpint = StrToInt("0x"+tmppwstr.SubString(i*2+1, 2));
				IntToUChar(tmpint, &OLPW[i]);
			}
			EncrptyCardMMProc(0, OLPW, ENPW);

			char Inbasechar[17];
            ZeroMemory(Inbasechar, 17);
            for(int t = 0; t<8; t++)
            {
                char tmp;
                tmp = ENPW[t]>>4;
                tmp = tmp&0x0f;
                if(tmp >= 10)
                    Inbasechar[t*2] = tmp+55;
                if(tmp <10)
                    Inbasechar[t*2] = tmp+48;
                tmp = ENPW[t]&0x0f;
                if(tmp >= 10)
                    Inbasechar[t*2+1] = tmp+55;
                if(tmp <10)
                    Inbasechar[t*2+1] = tmp+48;
            }

            String stortstr = Inbasechar;

            if("ADMIN" == cxTextEdit13->Text)
            {
            	ofstream upwout;
                String upwoutfilepath = GlobalPath + "\\UPW.xml";
                upwout.open(upwoutfilepath.t_str());
                upwout<<stortstr.t_str();
                upwout.close();
            }

            USERADOT->Edit();

            if("ADMIN" != USERADOT->FieldByName("USERNAME")->AsString)
            	USERADOT->FieldByName("USERNAME")->AsString = cxTextEdit13->Text;

            USERADOT->FieldByName("PASSWORD")->AsString = stortstr;
            USERADOT->Post();
            cxTextEdit7->Text = "";
            ShowMessage("系统用户名,密码修改成功!");
        }
        else
        {
            ShowMessage("必须输入8位密码!");
            return;
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxTabSheet5Show(TObject *Sender)
{
	STADOT->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxDBTextEdit1PropertiesChange(TObject *Sender)

{
	cxTextEdit8->Text = cxDBTextEdit1->Text.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxDBTextEdit2PropertiesChange(TObject *Sender)

{
	cxTextEdit9->Text = cxDBTextEdit2->Text.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxDBTextEdit3PropertiesChange(TObject *Sender)

{
	cxTextEdit10->Text = cxDBTextEdit3->Text.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxDBTextEdit4PropertiesChange(TObject *Sender)

{
	cxTextEdit11->Text = cxDBTextEdit4->Text.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxDBTextEdit5PropertiesChange(TObject *Sender)

{
	cxTextEdit12->Text = cxDBTextEdit5->Text.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxDBTextEdit6PropertiesChange(TObject *Sender)

{
	cxTextEdit13->Text = cxDBTextEdit6->Text.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxTextEdit7KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b'&&(Key<'A'||Key>'F')&&(Key<'a'||Key>'f'))
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字或A至F,a至f之间的字符!");
	}
}
//---------------------------------------------------------------------------


void __fastcall TSectionInfoManageFRM::cxComboBox1Enter(TObject *Sender)
{
	cxComboBox1->Properties->Items->Clear();
	USERADOQ->Close();
    USERADOQ->SQL->Clear();
    USERADOQ->SQL->Add("select * from GROUPINFO");
    USERADOQ->Open();
    if(!USERADOQ->IsEmpty())
    {
        USERADOQ->First();
        while(!USERADOQ->Eof)
        {
        	cxComboBox1->Properties->Items->Add(USERADOQ->FieldByName("GROUPNAME")->AsString.Trim());
            USERADOQ->Next();
        }
    }
    USERADOQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxComboBox1KeyPress(TObject *Sender, wchar_t &Key)

{
	Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::FormShow(TObject *Sender)
{
	if("系统管理员" == OperatorGroupName)
	{
		cxButton2->Enabled = true;
		cxButton1->Enabled = true;
		cxButton5->Enabled = true;
		cxButton9->Visible = true;
		cxButton9->Enabled = true;
	}
	else
	{
		cxButton2->Enabled = false;
		cxButton1->Enabled = false;
		cxButton5->Enabled = false;
		cxButton9->Visible = false;
		cxButton9->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSectionInfoManageFRM::cxButton9Click(TObject *Sender)
{
	qxfpform->username = USERADOT->FieldByName("USERNAME")->AsString.Trim();
	qxfpform->usergroup = USERADOT->FieldByName("GROUPNAME")->AsString.Trim();
	qxfpform->ShowModal();
}
//---------------------------------------------------------------------------

