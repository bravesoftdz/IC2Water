//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KYQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
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
#pragma link "cxProgressBar"
#pragma link "cxStyles"
#pragma link "dxSkinscxPCPainter"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TKYQFrm *KYQFrm;
//---------------------------------------------------------------------------
__fastcall TKYQFrm::TKYQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::BMComboBoxKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TKYQFrm::BHTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9')&& Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::KYExitBTNClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TKYQFrm::FormShow(TObject *Sender)
{
	KYExportProgressBar->Position = 0;
    KYExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
    ReadCardInfoBTN->Enabled = true;
    QueryBTN->Enabled = true;
    KYExitBTN->Enabled = true;
	DataGridDBTV->ClearItems();

	AllKSTextEdit->Text = "";
	AllKYTextEdit->Text = "";

    KHTextEdit->Text = "";
    BHTextEdit->Text = "";
    XMTextEdit->Text = "";

    KYADOQuery->Close();
    KYADOQuery->SQL->Clear();
    KYADOQuery->SQL->Add("select * from BUMEN");
    KYADOQuery->Open();
    if(!KYADOQuery->IsEmpty())
    {
        KYADOQuery->First();
		BMComboBox->Properties->Items->Clear();
        while(!KYADOQuery->Eof)
        {
            BMComboBox->Properties->Items->Add(KYADOQuery->FieldByName("BUMEN")->AsString.Trim());
            KYADOQuery->Next();
        }
		BMComboBox->Properties->Items->Add("所有部门");
		BMComboBox->ItemIndex = -1;
	}
	else
	{
		BMComboBox->Properties->Items->Clear();
		BMComboBox->Properties->Items->Add("所有部门");
		BMComboBox->ItemIndex = -1;
    }
    KYADOQuery->Close();

//    DataGridDBTV->DataController->DataSource = KYDataSource;
    DataGridDBTV->ClearItems();

    TcxGridDBColumn* KHCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* BHCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* XMCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* SFYECol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* XBCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* BMCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* BZCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* ZBCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* ZWCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* ZTCol = DataGridDBTV->CreateColumn();
    TcxGridDBColumn* FKRQCol = DataGridDBTV->CreateColumn();

    KHCol->Caption = "卡号";
    KHCol->MinWidth = 90;
    KHCol->DataBinding->FieldName = "KH";
    BHCol->Caption = "编号";
    BHCol->MinWidth = 90;
    BHCol->DataBinding->FieldName = "BH";
    XMCol->Caption = "姓名";
    XMCol->MinWidth = 70;
    XMCol->DataBinding->FieldName = "XM";
    SFYECol->Caption = "卡余额";
    SFYECol->MinWidth = 70;
    SFYECol->DataBinding->FieldName = "SF_YE";
    XBCol->Caption = "性别";
    XBCol->MinWidth = 40;
    XBCol->DataBinding->FieldName = "XB";
    BMCol->Caption = "部门";
    BMCol->MinWidth = 80;
    BMCol->DataBinding->FieldName = "BM";
    BZCol->Caption = "班别";
    BZCol->MinWidth = 60;
    BZCol->DataBinding->FieldName = "BZ";
    ZBCol->Caption = "组别";
    ZBCol->MinWidth = 60;
    ZBCol->DataBinding->FieldName = "ZB";
    ZWCol->Caption = "职务";
    ZWCol->MinWidth = 60;
    ZWCol->DataBinding->FieldName = "ZW";
    ZTCol->Caption = "状态";
    ZTCol->MinWidth = 40;
    ZTCol->DataBinding->FieldName = "ZT";
    FKRQCol->Caption = "最后消费日期";
    FKRQCol->MinWidth = 140;
    FKRQCol->DataBinding->FieldName = "SFYEDT";
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::ReadCardInfoBTNClick(TObject *Sender)
{
	WORD status;
	int tmpbalance;
	int tmpkh,tmpsycs;
	double tmpintye;
	double tmpye;
	unsigned char keymode,secnum,Delayms,mode;
	unsigned char key[6];
	unsigned char dwmm[6];
	unsigned char daytime[4];
	unsigned char kh[4];
	unsigned char balance[4];
	unsigned char cardtype[1];
	unsigned char czmm[3];
	unsigned char synum[3];
//	unsigned char readcomno[5] = "";

	Delayms = 0x00;
	keymode = CARDPasswordEdition;//0x03;
	secnum = UsingSecNUM;//0x01;

	key[0] = CARDPassword[0];
	key[1] = CARDPassword[1];
	key[2] = CARDPassword[2];
	key[3] = CARDPassword[3];
	key[4] = CARDPassword[4];
	key[5] = CARDPassword[5];

	if(LoadHModule)
	{
		beepofreaddll(readcomno, '10');
		if(readwatercardinfo)//readcardinfo)
		{
		//	status = readcardinfo(readcomno,keymode,secnum,key,kh,balance,
		//						dwmm,synum,daytime,cardtype,czmm,Delayms);

            status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,
            							dwmm,daytime,cardtype,Delayms);
			if(status > 99)
			{
				ShowMessage("通讯错误！");
			}
			else if (1 == status)
			{
				ShowMessage("请把卡片放好！");
			}
			else if (2 == status)
			{
				ShowMessage("卡号大于192000或等于0！");
			}
			else if (4 == status)
			{
				ShowMessage("卡片密码不对！");
			}
			else if (5 == status)
			{
				ShowMessage("读写卡不稳定！");
			}
			else if (6 == status)
			{
				ShowMessage("卡结构不对！");
			}
			else if (10 == status)
			{
				ShowMessage("卡结构不对！");
			}
			else if (0 != status)
			{
				ShowMessage("该卡未发行或已退卡！");
			}
			else
			{
            	DataGridDBTV->DataController->DataSource = NULL;

				String tmpstr;
				tmpkh = (int)kh[1]*256*256+(int)kh[2]*256+(int)kh[3];
				tmpsycs = 0;//(int)synum[0]*256+(int)synum[1];
				tmpintye = (double)balance[1]*256*256+(double)balance[2]*256+(double)balance[3];
				tmpye = tmpintye/100;

                KYExportBTN->Enabled = false;
        		PreviewBTN->Enabled = false;
				KYADOQuery->Close();
				KYADOQuery->SQL->Clear();
				tmpstr = "select * from KZT where kh=";
				tmpstr += tmpkh;
				KYADOQuery->SQL->Add(tmpstr);
				KYADOQuery->Open();
				if(!KYADOQuery->IsEmpty())
				{
					if(0 != KYADOQuery->FieldByName("GS")->AsInteger)
					{
						ShowMessage("此卡已挂失，请没收此卡！");
						KYADOQuery->Close();
					}
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					KYADOQuery->Close();
				}
				KYADOQuery->Close();

				KYADOQuery->SQL->Clear();
				tmpstr = "select * from CARD where kh=";
				tmpstr += tmpkh;
				KYADOQuery->SQL->Add(tmpstr);
				KYADOQuery->Open();
				if(!KYADOQuery->IsEmpty())
				{
					KHTextEdit->Text = tmpkh;
                    BHTextEdit->Text = KYADOQuery->FieldByName("BH")->AsString.Trim();
                    XMTextEdit->Text = KYADOQuery->FieldByName("XM")->AsString.Trim();
                    BMComboBox->Text = KYADOQuery->FieldByName("BM")->AsString.Trim();

                    KYExportBTN->Enabled = true;
                    PreviewBTN->Enabled = true;
				}
				else
				{
					ShowMessage("此卡不是本系统发出的卡！");
					KYADOQuery->Close();
				}
			}
		}
		else
		{
            ShowMessage("读卡函数加载失败！");
		}
	}
	else
		ShowMessage("加载读写卡动态链接库失败！");
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::QueryBTNClick(TObject *Sender)
{
	KYExportBTN->Enabled = false;
    PreviewBTN->Enabled = false;
	if(KHTextEdit->Text.IsEmpty()&&BHTextEdit->Text.IsEmpty()
		&&XMTextEdit->Text.IsEmpty()&&BMComboBox->Text.IsEmpty())
    {
        ShowMessage("至少填写一项查询条件!");
		return;
    }
	String sqlstr = "select * from CARD";
	String tjsqlstr = "select count(*) as allks,sum(SF_YE) as allky from CARD";// where ZT='发卡'";
    String addsqlstr = "";
    if(!KHTextEdit->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
			addsqlstr = " where KH=";
            addsqlstr += KHTextEdit->Text;
        }
    }

    if(!BHTextEdit->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
			addsqlstr = " where BH='";
            addsqlstr += BHTextEdit->Text;
            addsqlstr += "'";
        }
        else
        {
			addsqlstr += " BH='";
            addsqlstr += BHTextEdit->Text;
            addsqlstr += "'";
        }
    }

    if(!XMTextEdit->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
			addsqlstr = " where XM='";
            addsqlstr += XMTextEdit->Text;
            addsqlstr += "'";
        }
        else
        {
            addsqlstr += " and XM='";
            addsqlstr += XMTextEdit->Text;
            addsqlstr += "'";
        }
    }

    if(!BMComboBox->Text.IsEmpty())
    {
        if(addsqlstr.IsEmpty())
        {
            if(BMComboBox->Text != "所有部门"&&!BMComboBox->Text.IsEmpty())
            {
                addsqlstr = " where BM='";
                addsqlstr += BMComboBox->Text;
                addsqlstr += "'";
			}
        }
        else
        {
        	if(BMComboBox->Text != "所有部门"&&!BMComboBox->Text.IsEmpty())
            {
                addsqlstr += " and BM='";
                addsqlstr += BMComboBox->Text;
                addsqlstr += "'";
            }
        }
    }

	DataGridDBTV->DataController->DataSource = NULL;
	if(!addsqlstr.IsEmpty())
	{
		sqlstr += addsqlstr;
		tjsqlstr += addsqlstr;
		tjsqlstr += " and ZT='发卡'";
	}
	else
	{
    	tjsqlstr += " where ZT='发卡'";
    }

	KYADOQuery->Close();
	KYADOQuery->SQL->Clear();
	KYADOQuery->SQL->Add(tjsqlstr);
	KYADOQuery->Open();
	if(!KYADOQuery->IsEmpty())
	{
		AllKSTextEdit->Text = KYADOQuery->FieldByName("allks")->AsInteger;
		AllKYTextEdit->Text = KYADOQuery->FieldByName("allky")->AsFloat;
	}

    KYADOQuery->Close();
    KYADOQuery->SQL->Clear();
    KYADOQuery->SQL->Add(sqlstr);
    KYADOQuery->Open();
    if(!KYADOQuery->IsEmpty())
    {
    	if(KYADOQuery->RecordCount>65500)
        {
            KYADOQuery->Close();
            ShowMessage("符合该查询条件的记录条数大于65500条，无法正常显示，请修改查询条件!");
            return;
        }

        DataGridDBTV->DataController->DataSource = KYDataSource;

        KYExportBTN->Enabled = true;
        PreviewBTN->Enabled = true;
    }
	else
    {
    	KYADOQuery->Close();
        ShowMessage("无符合查询条件的卡片记录!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::KYExportBTNClick(TObject *Sender)
{
//导出线程
	if(!KYADOQuery->IsEmpty())
    {
    	ADOQInThread->Close();
        ADOQInThread->SQL->Clear();
		ADOQInThread->SQL = KYADOQuery->SQL;
		if(SaveDialog->Execute())
		{
			if(FileExists(SaveDialog->FileName+".xls"))
			{
				throw(Exception("该目录下存在同名文件，请重新输入文件名！"));
                return;
			}
			else
			{
				String savename = SaveDialog->FileName;
				savename += ".xls";

                TKYExportThread* EXThread = new TKYExportThread(true,
                												KYExportProgressBar,
                                                                ADOQInThread,
                                                                KYExportBTN,
                                                                PreviewBTN,
                                                                KYExitBTN,
                                                                ReadCardInfoBTN,
                                                                QueryBTN,
                                                                savename,
                                                                KHTextEdit->Text,
                                                                BHTextEdit->Text,
                                                                XMTextEdit->Text,
                                                                BMComboBox->Text,
																OperatorName,
																AllKSTextEdit->Text,
																AllKYTextEdit->Text);
                if(EXThread)
                {
                    EXThread->Resume();
                }

            }
        }
    }
	else
	{
		MessageBox(this->Handle, "没有可导出信息！", "No Record Error!", MB_OK|MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::PreviewBTNClick(TObject *Sender)
{
	String temppath = GlobalPath;
	temppath += "\\PreviewFR3\\KYPreview.fr3";
    frxKYReport->LoadFromFile(temppath.t_str(), true);

    ((TfrxMemoView*)frxKYReport->FindObject("KHMemo"))->Text = KHTextEdit->Text.t_str();
    ((TfrxMemoView*)frxKYReport->FindObject("BHMemo"))->Text = BHTextEdit->Text.t_str();
    ((TfrxMemoView*)frxKYReport->FindObject("BMMemo"))->Text = BMComboBox->Text.t_str();
	((TfrxMemoView*)frxKYReport->FindObject("XMMemo"))->Text = XMTextEdit->Text.t_str();
	((TfrxMemoView*)frxKYReport->FindObject("KZSMemo"))->Text = AllKSTextEdit->Text.t_str();
	((TfrxMemoView*)frxKYReport->FindObject("KZZMemo"))->Text = "￥" + AllKYTextEdit->Text;
    ((TfrxMemoView*)frxKYReport->FindObject("CZYMemo"))->Text = OperatorName.t_str();
    ((TfrxMemoView*)frxKYReport->FindObject("SCRQMemo"))->Text = DateTimeToStr(Now()).t_str();

    ((TfrxMemoView*)frxKYReport->FindObject("KH"))->DataField = "KH";
    ((TfrxMemoView*)frxKYReport->FindObject("BH"))->DataField = "BH";
    ((TfrxMemoView*)frxKYReport->FindObject("XM"))->DataField = "XM";
    ((TfrxMemoView*)frxKYReport->FindObject("BM"))->DataField = "BM";
    ((TfrxMemoView*)frxKYReport->FindObject("SFYE"))->DataField = "SF_YE";
    ((TfrxMemoView*)frxKYReport->FindObject("XB"))->DataField = "XB";
    ((TfrxMemoView*)frxKYReport->FindObject("BZ"))->DataField = "BZ";
    ((TfrxMemoView*)frxKYReport->FindObject("ZB"))->DataField = "ZB";
    ((TfrxMemoView*)frxKYReport->FindObject("ZT"))->DataField = "ZT";
    ((TfrxMemoView*)frxKYReport->FindObject("ZW"))->DataField = "ZW";
    ((TfrxMemoView*)frxKYReport->FindObject("RQ"))->DataField = "SFYEDT";

    frxKYReport->ShowReport(true);
}
//---------------------------------------------------------------------------
void __fastcall TKYQFrm::AllKSTextEditKeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

