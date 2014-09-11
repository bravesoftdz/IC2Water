//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BatchLaunchCardProcessFrm.h"
#include "SDIMAIN.h"
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
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
TBatchLaunchCardProcessForm *BatchLaunchCardProcessForm;
//---------------------------------------------------------------------------
__fastcall TBatchLaunchCardProcessForm::TBatchLaunchCardProcessForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBatchLaunchCardProcessForm::cxButton2Click(TObject *Sender)
{
	//异常信息导出
	BLTime->Enabled = false;
	cxButton1->Enabled = false;
	cxButton2->Enabled = false;

    Variant ExcelApp;
    try
    {
        ExcelApp = CreateOleObject("Excel.Application");
    }
    catch(...)
    {
        ShowMessage( "错误：您的系统中可能没有安装Excel,无法进行错误信息导出!");
		this->Close();
    }

    String TempPath = GlobalPath;

    TempPath += "\\ExportXLSTemplate\\BLCardErrInfo.xlt";

    ExcelApp.OlePropertyGet("workbooks").OleFunction("Open", TempPath.t_str());

	Variant WB = ExcelApp.OlePropertyGet("ActiveWorkBook");

	Variant ST = WB.OlePropertyGet("Sheets", 1);

	if((startindex == alllinecount)&&(startindex != -1))
	{
		TcxListView* LV =	BatchLaunchCardForm->cxListView1;
		for (int i = 0; i < LV->Columns->Count; i++)
		{
			ST.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value", LV->Columns->Items[i]->Caption.t_str());
		}
    	Variant RE = ST.OlePropertyGet("Range", "A2").OleFunction("Select");
        Clipboard()->Clear();
		Clipboard()->SetTextBuf(errstr.c_str());
        ST.OleFunction("Paste");
        Clipboard()->Clear();

    	ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
        ShowMessage("批量发卡错误信息将以xls的形式显示，请手动保存！");
        ExcelApp.OlePropertySet("Visible", (Variant)true);
    }
    else if((startindex < alllinecount)&&(startindex != -1))
    {
		TcxListView* LV =	BatchLaunchCardForm->cxListView1;
		TListItem* LI;// = LV->Items->Item[startindex];

		for (int i = 0; i < LV->Columns->Count; i++)
		{
			ST.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value", LV->Columns->Items[i]->Caption.t_str());
		}

		int colscount = LV->Columns->Count-1;

		while(startindex < alllinecount)
        {
        	LI = LV->Items->Item[startindex];
            errstr += LI->Caption;
			errstr += "\t";
            for(int i = 0; i < colscount; i++)
            {
				errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
					errstr += "\t";
			}
			errstr += "\n";

			startindex++;
        }

        Variant RE = ST.OlePropertyGet("Range", "A2").OleFunction("Select");
        Clipboard()->Clear();
        Clipboard()->SetTextBuf(errstr.c_str());
        ST.OleFunction("Paste");
        Clipboard()->Clear();

    	ExcelApp.OlePropertyGet("Columns").OleFunction("AutoFit");
        ShowMessage("批量发卡错误信息将以xls的形式显示，请手动保存！");
        ExcelApp.OlePropertySet("Visible", (Variant)true);
	}
    cxButton1->Enabled = true;
	cxButton2->Enabled = true;
	BatchLaunchCardtag = false;
	this->Close();
	ChooseDataForm->Close();
	BatchLaunchCardForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardProcessForm::cxButton1Click(TObject *Sender)
{
	UseDateEdit->Enabled = false;
	CheckBox1->Enabled = false;
	BLTime->Enabled = true;
    cxButton1->Enabled = false;
    startindex = 0;
    alllinecount = BatchLaunchCardForm->cxListView1->Items->Count;

    Panel2->Caption = "正在提取发卡信息，请稍候!";
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardProcessForm::BLTimeTimer(TObject *Sender)
{
	if(startindex >= alllinecount)
	{
		BLTime->Enabled = false;
		cxButton1->Enabled = true;
		ShowMessage("批量发卡结束，请留意发卡未成功的信息！");
        return;
    }
	TcxListView* LV = BatchLaunchCardForm->cxListView1;
	TListItem* LI = LV->Items->Item[startindex];


	if(0 == Nameindex)
	{
		NameTextEdit->Text = LI->Caption;
	}
	else if(-1 != Nameindex)
	{
		NameTextEdit->Text = LI->SubItems->Strings[Nameindex-1];
	}

    if(0 == ZWindex)
	{
		String sexstr = LI->Caption;
		if(sexstr!="男"&&sexstr!="女")
			ZWTextEdit->Text = "男";
        else
			ZWTextEdit->Text = sexstr;
    }
    else if(-1 != ZWindex)
	{
		String sexstr = LI->SubItems->Strings[ZWindex-1];
		if(sexstr!="男"&&sexstr!="女")
			ZWTextEdit->Text = "男";
        else
			ZWTextEdit->Text = sexstr;
	}

	if(0 == Moneyindex)
	{
		MoneyTextEdit->Text = LI->Caption;
	}
	else if(-1 != Moneyindex)
	{
		MoneyTextEdit->Text = LI->SubItems->Strings[Moneyindex-1];
	}

	if(0 == KHindex)
	{
		KHTextEdit->Text = LI->Caption;
	}
	else if(-1 != KHindex)
	{
		KHTextEdit->Text = LI->SubItems->Strings[KHindex-1];
	}

	if(0 == BHindex)
	{
		BHTextEdit->Text = LI->Caption;
	}
	else if(-1 != BHindex)
	{
        BHTextEdit->Text = LI->SubItems->Strings[BHindex-1];
    }

	if(0 == Groupindex)
	{
//		GroupTextEdit->Text = LI->Caption;
		int bmdm;
		try
        {
			bmdm = StrToInt(LI->Caption);
		}
		catch(...)
		{
			int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
            {
            	errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
                	errstr += "\t";
            }
            errstr += "\n";

            startindex++;
            return;
        }

        ADOQuery2->Close();
        String bmsqlstr = "select * from BUMEN where dm=";
        bmsqlstr += bmdm;
        ADOQuery2->SQL->Clear();
        ADOQuery2->SQL->Add(bmsqlstr);
        ADOQuery2->Open();
        if(!ADOQuery2->IsEmpty())
        	GroupTextEdit->Text = ADOQuery2->FieldByName("BUMEN")->AsString.Trim();
        else
			GroupTextEdit->Text = "";
		ADOQuery2->Close();
	}
	else if(-1 != Groupindex)
	{
		int bmdm;
		try
		{
			bmdm = StrToInt(LI->SubItems->Strings[Groupindex-1]);
        }
		catch(...)
		{
			int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
            {
            	errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
                	errstr += "\t";
            }
            errstr += "\n";

            startindex++;
            return;
        }

		ADOQuery2->Close();
		String bmsqlstr = "select * from BUMEN where dm=";
		bmsqlstr += bmdm;
		ADOQuery2->SQL->Clear();
		ADOQuery2->SQL->Add(bmsqlstr);
		ADOQuery2->Open();
		if(!ADOQuery2->IsEmpty())
			GroupTextEdit->Text = ADOQuery2->FieldByName("BUMEN")->AsString.Trim();
        else
			GroupTextEdit->Text = "";
		ADOQuery2->Close();
	}

	if(0 == Classindex)
	{
//		GroupTextEdit->Text = LI->Caption;
		int bbdm;
		try
        {
			bbdm = StrToInt(LI->Caption);
		}
		catch(...)
		{
			int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
            {
            	errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
                	errstr += "\t";
            }
            errstr += "\n";

            startindex++;
            return;
        }

        ADOQuery2->Close();
		String bmsqlstr = "select * from BANBIE where DM=";
		bmsqlstr += bbdm;
		bmsqlstr += " and BUMEN='";
		bmsqlstr += GroupTextEdit->Text;
		bmsqlstr += "'";
        ADOQuery2->SQL->Clear();
        ADOQuery2->SQL->Add(bmsqlstr);
        ADOQuery2->Open();
        if(!ADOQuery2->IsEmpty())
			ClassTextEdit->Text = ADOQuery2->FieldByName("BANBIE")->AsString.Trim();
        else
			ClassTextEdit->Text = "";
		ADOQuery2->Close();
	}
	else if(-1 != Classindex)
	{
		int bbdm;
		try
		{
			bbdm = StrToInt(LI->SubItems->Strings[Classindex-1]);
        }
		catch(...)
		{
			int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
            {
            	errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
                	errstr += "\t";
            }
            errstr += "\n";

            startindex++;
            return;
        }

		ADOQuery2->Close();
		String bmsqlstr = "select * from BANBIE where dm=";
		bmsqlstr += bbdm;
		bmsqlstr += " and BUMEN='";
		bmsqlstr += GroupTextEdit->Text;
		bmsqlstr += "'";
		ADOQuery2->SQL->Clear();
		ADOQuery2->SQL->Add(bmsqlstr);
		ADOQuery2->Open();
		if(!ADOQuery2->IsEmpty())
			ClassTextEdit->Text = ADOQuery2->FieldByName("BANBIE")->AsString.Trim();
        else
			ClassTextEdit->Text = "";
		ADOQuery2->Close();
    }


    //发卡过程
	if(!NameTextEdit->Text.IsEmpty()&&!MoneyTextEdit->Text.IsEmpty()&&!ZWTextEdit->Text.IsEmpty()
		&&!KHTextEdit->Text.IsEmpty()&&!BHTextEdit->Text.IsEmpty())
    {
    	if(NameTextEdit->Text.Length() > 10)
        {
        	//异常处理
            int colscount = LV->Columns->Count-1;
            errstr += LI->Caption;
            errstr += "\t";
			for(int i = 0; i < colscount; i++)
            {
            	errstr += LI->SubItems->Strings[i];
                if(i != (colscount-1))
                	errstr += "\t";
            }
            errstr += "\n";

            startindex++;
            return;
        }
        if(ZWTextEdit->Text.Length() > 1)
        {
        	//异常处理
            int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
            errstr += "\t";
			for(int i = 0; i < colscount; i++)
            {
            	errstr += LI->SubItems->Strings[i];
                if(i != (colscount-1))
                	errstr += "\t";
            }
            errstr += "\n";

            startindex++;
            return;
        }

		double moneylaunch;
		try
		{
			moneylaunch = StrToFloat(MoneyTextEdit->Text);
		}
		catch(...)
		{
			//异常处理
			int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
			{
				errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
					errstr += "\t";
			}
			errstr += "\n";

			startindex++;
			return;
		}

		int  khint;
		try
		{
			khint = StrToInt(KHTextEdit->Text);
		}
		catch(...)
		{
			//异常处理
			int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
			{
				errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
					errstr += "\t";
			}
			errstr += "\n";

			startindex++;
			return;
		}

		String BHstring = BHTextEdit->Text;
		int BHint;

		if((BHstring.Length()>10)||(0 ==BHstring.Length()))
		{
            int colscount = LV->Columns->Count-1;
			errstr += LI->Caption;
			errstr += "\t";
			for(int i = 0; i < colscount; i++)
			{
				errstr += LI->SubItems->Strings[i];
				if(i != (colscount-1))
					errstr += "\t";
			}
			errstr += "\n";

			startindex++;
			return;
		}
		else
		{
			try
			{
				BHint = StrToInt(BHTextEdit->Text);
			}
			catch(...)
			{
				//异常处理
				int colscount = LV->Columns->Count-1;
				errstr += LI->Caption;
				errstr += "\t";
				for(int i = 0; i < colscount; i++)
				{
					errstr += LI->SubItems->Strings[i];
					if(i != (colscount-1))
						errstr += "\t";
				}
				errstr += "\n";

				startindex++;
				return;
			}
		}

		//正常信息，进行发卡
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

        Delayms = DelaySecond;
        keymode = CARDPasswordEdition;
        secnum = UsingSecNUM;

        key[0] = CARDPassword[0];
        key[1] = CARDPassword[1];
        key[2] = CARDPassword[2];
        key[3] = CARDPassword[3];
        key[4] = CARDPassword[4];
        key[5] = CARDPassword[5];

        if(LoadHModule)
		{
            if(readwatercardinfo&&LaunchWaterNewCard)//LaunchNewCard)//readcardinfo&&LaunchNewCard)
            {
            //    status = readcardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,synum,daytime,cardtype,czmm,Delayms);
            	status = readwatercardinfo(readcomno,keymode,secnum,key,kh,balance,dwmm,daytime,cardtype,Delayms);
                if(status > 99)
                {
				//    ShowMessage("通讯错误！");
                	Panel2->Caption = "通讯错误！";
                    return;
                }
                else if (1 == status)
                {
                //    ShowMessage("请把卡片放好！");
                	Panel2->Caption = "请把卡片放好！";
                    return;
                }
                else if (2 == status)
                {
                //    ShowMessage("卡号大于200000或等于0！");
                	Panel2->Caption = "卡号大于200000或等于0！";
                    return;
                }
                else if (4 == status)
                {
                //    ShowMessage("卡片密码不对！");
                	Panel2->Caption = "卡片密码不对，请更换新卡！";
                    return;
                }
                else if (5 == status)
                {
                //    ShowMessage("读写卡不稳定！");
                	Panel2->Caption = "读写卡不稳定！";
                    return;
                }
                else if (0 == status)
                {
				//    ShowMessage("此卡已发行，请更换新卡！");
					Panel2->Caption = "此卡不能做为新卡发行，请更换新卡！";
                    return;
                }
                else
                {
                	BLCADOQ->Close();
                    BLCADOQ->SQL->Clear();
			   //		BLCADOQ->SQL->Add("select min(KH) as minkh from KZT where (SY='N' or SY='T') and GS='0' and KH>0");
                    BLCADOQ->SQL->Add("select min(KH) as minkh from KZT where SY='N' and GS='0' and KH>0");
					BLCADOQ->Open();
                    if(!BLCADOQ->IsEmpty())
					{
						int bltmpkh = BLCADOQ->FieldByName("minkh")->AsInteger;

						String checkkhstr = "select * from KZT where SY='N' and GS='0' and KH=";
						checkkhstr += khint;
						BLCADOQ->Close();
						BLCADOQ->SQL->Clear();
						BLCADOQ->SQL->Add(checkkhstr);
						BLCADOQ->Open();
						if(!BLCADOQ->IsEmpty())
							bltmpkh=khint;
						else
						{
							KHTextEdit->Text = bltmpkh;
							Panel2->Caption = "自动生成可用卡号!";
						}

						AnsiString SerialNumOFCard = "";
						WORD readserialstatus;
						unsigned char readserialdelayms;
						unsigned char readserial[4];
						ZeroMemory(readserial, 4);
						readserialdelayms = 0x01;
						readserialstatus = readserialfun(readcomno, readserial);
						if(readserialstatus)
						{
							Panel2->Caption = "此卡不能做为新卡发行，请更换新卡！";
							return;
						}
						else
						{
						 /*	unsigned int serialnum = readserial[3]*256*256*256
													 + readserial[2]*256*256
													 + readserial[1]*256
													 + readserial[0];     */
							unsigned int serialnum = BHint;

							SerialNumOFCard.sprintf("%010u", serialnum);
						}

						String tmpsqlstr = "select * from BHUSED where BH='";
						tmpsqlstr += SerialNumOFCard;
						tmpsqlstr += "'";
                        BLCADOQ->Close();
                    	BLCADOQ->SQL->Clear();
						BLCADOQ->SQL->Add(tmpsqlstr);
						BLCADOQ->Open();
                        if(BLCADOQ->IsEmpty())
                        {
                            //发卡
                            WORD writestatus;
                            unsigned char writedaytime[4];
                            unsigned char writebalance[4];
                            unsigned char writeczmm[3];
                            unsigned char writecardtype[1];
                            unsigned char writekh[4];
                            int writetmpkh = bltmpkh;
                            writekh[0] = (char)(writetmpkh/256/256/256);
                            writekh[1] = (char)((writetmpkh%(256*256*256))/256/256);
                            writekh[2] = (char)((writetmpkh%(256*256))/256);
                            writekh[3] = (char)writetmpkh;

                            unsigned char writereadcomno[5] = readcomno;
                            unsigned char writekeymode = keymode;
                            unsigned char writesecnum = secnum;

                            unsigned char writekey[6];// = key;
                            writekey[0] = CARDPassword[0];
                            writekey[1] = CARDPassword[1];
                            writekey[2] = CARDPassword[2];
                            writekey[3] = CARDPassword[3];
                            writekey[4] = CARDPassword[4];
                            writekey[5] = CARDPassword[5];

                            unsigned char writedwmm[2];
                            writedwmm[0] = DWPassword[0];
                            writedwmm[1] = DWPassword[1];
                            unsigned char writesynum[2];
                            writesynum[0] = 0x00;
                            writesynum[1] = 0x00;
                            unsigned char writemode = 0x00;
                            unsigned char writeDelayms = DelaySecond;

                            String writetmpstr = DateToStr(UseDateEdit->Date);
                            char* writetmpdatestr = writetmpstr.t_str();
                            writedaytime[0] = char(((int)writetmpdatestr[2]-48)*16+((int)writetmpdatestr[3]-48));
                            writedaytime[1] = char(((int)writetmpdatestr[5]-48)*16+((int)writetmpdatestr[6]-48));
                            writedaytime[2] = char(((int)writetmpdatestr[8]-48)*16+((int)writetmpdatestr[9]-48));
                            writedaytime[3] = 0x00;

                 //			writesynum[0] = 0x00;
                 //			writesynum[1] = 0x00;

                 //			ShowMessage(PrepayTextEdit->Text.t_str());
                            double blwritetmpbalance = StrToFloat(MoneyTextEdit->Text);//-atoi(DepositTextEdit->Text.t_str());
                            int writetmpbalance = blwritetmpbalance*100;
                            writebalance[0] = 0x00;
                            writebalance[1] = (char)((int)writetmpbalance/65536);
                            writetmpbalance = writetmpbalance%65536;
                            writebalance[2] = (char)((int)writetmpbalance/256);
                            writetmpbalance = writetmpbalance%256;
                            writebalance[3] = (char)writetmpbalance;

                            unsigned char writetmpczmm[5];
                            strcpy(writetmpczmm, "1234");
                            writetmpczmm[0] = writetmpczmm[0]<<4;
                            writetmpczmm[1] = writetmpczmm[1]<<4;
                            writetmpczmm[1] = writetmpczmm[1]>>4;
                            writeczmm[0] = writetmpczmm[0] + writetmpczmm[1];
                            writetmpczmm[2] = writetmpczmm[2]<<4;
                            writetmpczmm[3] = writetmpczmm[3]<<4;
                            writetmpczmm[3] = writetmpczmm[3]>>4;
                            writeczmm[1] = writetmpczmm[2]+writetmpczmm[3];
                            writeczmm[2] = 0x00;

                            writecardtype[0] = 0x04;//atoi(DegreeTextEdit->Text.t_str());

                     /*       writestatus = LaunchNewCard(writereadcomno,
                                                        writekeymode,
                                                        writesecnum,
                                                        writekey,
                                                        writekh,
                                                        writebalance,
                                                        writedwmm,
                                                        writesynum,
                                                        writedaytime,
                                                        writecardtype,
                                                        writeczmm,
                                                        writemode,
                                                        writeDelayms);     */
                     		writestatus = LaunchWaterNewCard(writereadcomno,
                            								 writekeymode,
                                                             writesecnum,
                                                             writekey,
                                                             writekh,
                                                             writebalance,
                                                             writedwmm,
                                                             writedaytime,
                                                             writecardtype,
                                                             writemode,
                                                             writeDelayms);
                            if(writestatus)
                            {
                            //    ShowMessage("写卡失败！");
                            //    return;
                            	//写卡失败,进行错误信息保存
                                int colscount = LV->Columns->Count-1;
								errstr += LI->Caption;
                                errstr += "\t";
								for(int i = 0; i < colscount; i++)
                                {
                                    errstr += LI->SubItems->Strings[i];
                                    if(i != (colscount-1))
                                        errstr += "\t";
                                }
                                errstr += "\n";

                                startindex++;
                                return;
                            }
                            else
                            {
								//写卡成功
								if(CheckBox1->Checked)
								{
									if(!pacarddllproc)
									{
										ClearCardInfoProc(writereadcomno,
														  writekeymode,
														  writesecnum,
														  writekey,
														  writeDelayms);
										beepofreaddll(readcomno, '10');

										Panel2->Caption = "写卡时间限制函数加载失败!";

										int colscount = LV->Columns->Count-1;
										errstr += LI->Caption;
										errstr += "\t";
										for(int i = 0; i < colscount; i++)
										{
											errstr += LI->SubItems->Strings[i];
											if(i != (colscount-1))
												errstr += "\t";
										}
										errstr += "\n";

										startindex++;

										return;
									}

									unsigned char limitwritedaytime[4];
									String limitwritetmpstr = DateToStr(UseDateEdit->Date);
									char* limitwritetmpdatestr = limitwritetmpstr.t_str();
									limitwritedaytime[0] = char(((int)limitwritetmpdatestr[2]-48)*16+((int)limitwritetmpdatestr[3]-48));
									limitwritedaytime[1] = char(((int)limitwritetmpdatestr[5]-48)*16+((int)limitwritetmpdatestr[6]-48));
									limitwritedaytime[2] = char(((int)limitwritetmpdatestr[8]-48)*16+((int)limitwritetmpdatestr[9]-48));
									limitwritedaytime[3] = 0x00;

									unsigned char sendbuflen = 26;
									unsigned char sendbuf[26];
									ZeroMemory(sendbuf,26);
									unsigned char recbuf[140];
									unsigned char recbuflen;
									ZeroMemory(recbuf, 140);

									sendbuf[0] = (secnum+1)*4+2;//扇区×4+块号
									sendbuf[1] = 0x60;//固定为0x60
									sendbuf[2] = 2;//命令字：1为读，2为写
									sendbuf[3] = keymode;
									sendbuf[4] = writekey[0];
									sendbuf[5] = writekey[1];
									sendbuf[6] = writekey[2];
									sendbuf[7] = writekey[3];
									sendbuf[8] = writekey[4];
									sendbuf[9] = writekey[5];

									sendbuf[23] = limitwritedaytime[0];
									sendbuf[24] = limitwritedaytime[1];
									sendbuf[25] = limitwritedaytime[2];

									WORD limitStatus = pacarddllproc(writereadcomno,sendbuflen,sendbuf,&recbuflen,recbuf,writeDelayms);

									if((0 != limitStatus)||(0 != recbuf[2]))
									{
										ClearCardInfoProc(writereadcomno,
														  writekeymode,
														  writesecnum,
														  writekey,
														  writeDelayms);
										beepofreaddll(readcomno, '10');

										Panel2->Caption = "写卡时间限制失败!";

										int colscount = LV->Columns->Count-1;
										errstr += LI->Caption;
										errstr += "\t";
										for(int i = 0; i < colscount; i++)
										{
											errstr += LI->SubItems->Strings[i];
											if(i != (colscount-1))
												errstr += "\t";
										}
										errstr += "\n";

										startindex++;

										return;
									}
								}

                                Panel2->Caption = "写卡成功，正在信息入库，请勿将卡从读卡器上移走！";
                                Sleep(200);
								String DateofLaunchCard;
								SYSTEMTIME tmpsystime;
                                GetLocalTime(&tmpsystime);
                                DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

                                int tmpdeposit = GlobalFKYJ;
                                double tmpPrePay = StrToFloat(MoneyTextEdit->Text);
                                double moneyincard = tmpPrePay;//-tmpdeposit;

                                //填写CARD表
								String tmpstr = SerialNumOFCard;
                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
								String sqlstr = "insert into CARD values(:BH,:KH,:BKH,:XM,:XB,";
								sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
												":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
												":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
												":SF_KL,:USERNAME)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;
                                //ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("XM")->Value = NameTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("XB")->Value = ZWTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("SFZH")->Value = NULL;
								if(GroupTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BM")->Value = GroupTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BM")->Value = "";

								if(ClassTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BZ")->Value = "";

                                ADOQuery1->Parameters->ParamByName("ZB")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("ZW")->Value = "";
                                ADOQuery1->Parameters->ParamByName("JB")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
                                //ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("TYJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
                                ADOQuery1->Parameters->ParamByName("GRMM")->Value = "1234";
                                ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
                                //ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SF_FL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
                                //ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
                                //ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
                                ADOQuery1->ExecSQL();

                                //填写CARD_F表
								ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into CARD_F values(:BH,:KH,:BKH,:XM,:XB,";
                                sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
                                ":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
                                ":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
                                ":SF_KL,:USERNAME)";
                                ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;
                                //ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("XM")->Value = NameTextEdit->Text;
                                ADOQuery1->Parameters->ParamByName("XB")->Value = ZWTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("SFZH")->Value = NULL;
								if(GroupTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BM")->Value = GroupTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BM")->Value = "";

                                if(ClassTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BZ")->Value = "";

                                ADOQuery1->Parameters->ParamByName("ZB")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("ZW")->Value = "";
                                ADOQuery1->Parameters->ParamByName("JB")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
                                //ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("TYJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
                                ADOQuery1->Parameters->ParamByName("GRMM")->Value = "1234";
                                ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
                                //ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SF_FL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
                                //ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
                                //ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
                                ADOQuery1->ExecSQL();

                                //填写MX,MXBAK表
                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
								ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
								ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
								ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "K";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();
								ADOQuery1->Close();

								//添加扣押金记录
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
								ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = 0;
								ADOQuery1->Parameters->ParamByName("SFJE")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "W";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();

                                //添加扣押金记录
/*                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "W";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();

                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "K";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
								ADOQuery1->ExecSQL();        */

								//发卡入CK表
 								ADOQuery1->Close();
								ADOQuery1->SQL->Clear();
								sqlstr = "insert into CK values(:kh,:bh,:sf_ye,:sf_fl,:ckxj,";
								sqlstr += ":glf,:ckje,:lqbt,:xkje,:sycs,:sfrq,:jyno,:gzzid,:sflx,:CZY)";
								ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Parameters->ParamByName("kh")->Value = bltmpkh;
								ADOQuery1->Parameters->ParamByName("bh")->Value = SerialNumOFCard;
								ADOQuery1->Parameters->ParamByName("sf_ye")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("sf_fl")->Value = 1;
								ADOQuery1->Parameters->ParamByName("ckxj")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("glf")->Value = 0;
								ADOQuery1->Parameters->ParamByName("ckje")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("lqbt")->Value = 0;
								ADOQuery1->Parameters->ParamByName("xkje")->Value = moneyincard;
								ADOQuery1->Parameters->ParamByName("sycs")->Value = 0;
								ADOQuery1->Parameters->ParamByName("sfrq")->Value = DateofLaunchCard;
								ADOQuery1->Parameters->ParamByName("jyno")->Value = 0;
								ADOQuery1->Parameters->ParamByName("gzzid")->Value = 1;
								ADOQuery1->Parameters->ParamByName("sflx")->Value = "K";
								ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
								ADOQuery1->ExecSQL();
								ADOQuery1->Close();

                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                String kztsqlstr = "select * from KZT where KH=";
                                kztsqlstr += bltmpkh;
                                ADOQuery1->SQL->Add(kztsqlstr);
                                ADOQuery1->Open();
                                if(!ADOQuery1->IsEmpty())
                                {
                                    ADOQuery1->Edit();
									ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
                                    ADOQuery1->FieldByName("SY")->AsAnsiString = 'Y';
                                    ADOQuery1->FieldByName("FKRQ")->AsAnsiString = DateofLaunchCard;
                                    ADOQuery1->FieldByName("GS")->AsAnsiString = '0';
                                	ADOQuery1->FieldByName("TKRQ")->AsAnsiString = "";
                                	ADOQuery1->FieldByName("WITHCARDTK")->AsAnsiString = "";
                                    ADOQuery1->Post();
                                }
                                ADOQuery1->Close();

                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into BHUSED values(:BH)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->ExecSQL();
								ADOQuery1->Close();

								//写加密狗增加充值
                                if(DOGChk)
                                {
                                    unsigned char tempbuf[8];
                                    SFK_ZE += moneyincard;
                                    UpZETable->FieldByName("SFKZE")->AsFloat += moneyincard;
                                    memcpy(tempbuf,&SFK_ZE,8);
                                    unsigned char hightempchar1;
                                    unsigned char lowtempchar1;
                                    for(int t = 0; t < 8; t++)
                                    {
                                        hightempchar1 = tempbuf[t]&0xf0;
                                        lowtempchar1 = tempbuf[t]&0x0f;

                                        hightempchar1 = hightempchar1>>4;
                                        hightempchar1 = hightempchar1&0x0f;

                                        lowtempchar1 = lowtempchar1<<4;
                                        lowtempchar1 = lowtempchar1&0xf0;

                                        tempbuf[t] = hightempchar1|lowtempchar1;
                                    }
                                    int dogoffset = 0x0034;
                                    int doglen = 8;
                                    RY3_Write(doghandle,dogoffset,tempbuf,doglen);
                                }
								//写加密狗完毕

                                beepofreaddll(readcomno, '10');

						  //		ShowMessage("发卡成功！请更换一张待发的新卡！");
								Panel2->Caption = "发卡成功！请更换一张待发的新卡！";

                                startindex++;
                            }
                        }
                        else
                        {
                            //生成可用编号再发卡
                            srand((unsigned)time(NULL));
                            int tmpint = rand()%10000000000;

                            while(1)
                            {
								SerialNumOFCard = "";
                                SerialNumOFCard.sprintf("%010d", tmpint);
                                tmpsqlstr = "select * from BHUSED where BH='";
                                tmpsqlstr += SerialNumOFCard;
                        		tmpsqlstr += "'";
                                BLCADOQ->Close();
                                BLCADOQ->SQL->Clear();
                                BLCADOQ->SQL->Add(tmpsqlstr);
                                BLCADOQ->Open();
                                if(BLCADOQ->IsEmpty())
                                {
                                    break;
                                }
                                else
                                {
                                	tmpint = rand()%10000000000;
                                }
							}
							BHTextEdit->Text = SerialNumOFCard;
							Panel2->Caption = "自动生成可用编号!";
                            //发卡
                            WORD writestatus;
                            unsigned char writedaytime[4];
                            unsigned char writebalance[4];
                            unsigned char writeczmm[3];
                            unsigned char writecardtype[1];
                            unsigned char writekh[4];
                            int writetmpkh = bltmpkh;
							writekh[0] = (char)(writetmpkh/256/256/256);
                            writekh[1] = (char)((writetmpkh%(256*256*256))/256/256);
                            writekh[2] = (char)((writetmpkh%(256*256))/256);
                            writekh[3] = (char)writetmpkh;

                            unsigned char writereadcomno[5] = readcomno;
                            unsigned char writekeymode = keymode;
                            unsigned char writesecnum = secnum;

                            unsigned char writekey[6];// = key;
                            writekey[0] = CARDPassword[0];
                            writekey[1] = CARDPassword[1];
                            writekey[2] = CARDPassword[2];
                            writekey[3] = CARDPassword[3];
                            writekey[4] = CARDPassword[4];
                            writekey[5] = CARDPassword[5];

                            unsigned char writedwmm[2];
                            writedwmm[0] = DWPassword[0];
                            writedwmm[1] = DWPassword[1];
                            unsigned char writesynum[2];
                            writesynum[0] = 0x00;
                            writesynum[1] = 0x00;
                            unsigned char writemode = 0x00;
                            unsigned char writeDelayms = DelaySecond;

                            String writetmpstr = DateToStr(UseDateEdit->Date);
                            char* writetmpdatestr = writetmpstr.t_str();
                            writedaytime[0] = char(((int)writetmpdatestr[2]-48)*16+((int)writetmpdatestr[3]-48));
                            writedaytime[1] = char(((int)writetmpdatestr[5]-48)*16+((int)writetmpdatestr[6]-48));
                            writedaytime[2] = char(((int)writetmpdatestr[8]-48)*16+((int)writetmpdatestr[9]-48));
                            writedaytime[3] = 0x00;

                 //			writesynum[0] = 0x00;
                 //			writesynum[1] = 0x00;

                 //			ShowMessage(PrepayTextEdit->Text.t_str());
                            double blwritetmpbalance = StrToFloat(MoneyTextEdit->Text);//-atoi(DepositTextEdit->Text.t_str());
                            int writetmpbalance = blwritetmpbalance*100;
                            writebalance[0] = 0x00;
                            writebalance[1] = (char)((int)writetmpbalance/65536);
                            writetmpbalance = writetmpbalance%65536;
                            writebalance[2] = (char)((int)writetmpbalance/256);
                            writetmpbalance = writetmpbalance%256;
                            writebalance[3] = (char)writetmpbalance;

                            unsigned char writetmpczmm[5];
                            strcpy(writetmpczmm, "1234");
                            writetmpczmm[0] = writetmpczmm[0]<<4;
                            writetmpczmm[1] = writetmpczmm[1]<<4;
                            writetmpczmm[1] = writetmpczmm[1]>>4;
                            writeczmm[0] = writetmpczmm[0] + writetmpczmm[1];
                            writetmpczmm[2] = writetmpczmm[2]<<4;
                            writetmpczmm[3] = writetmpczmm[3]<<4;
                            writetmpczmm[3] = writetmpczmm[3]>>4;
                            writeczmm[1] = writetmpczmm[2]+writetmpczmm[3];
                            writeczmm[2] = 0x00;

                            writecardtype[0] = 1;//atoi(DegreeTextEdit->Text.t_str());

                        /*    writestatus = LaunchNewCard(writereadcomno,
                                                        writekeymode,
                                                        writesecnum,
                                                        writekey,
                                                        writekh,
                                                        writebalance,
                                                        writedwmm,
                                                        writesynum,
                                                        writedaytime,
                                                        writecardtype,
                                                        writeczmm,
                                                        writemode,
                                                        writeDelayms);    */

                        	writestatus = LaunchWaterNewCard(writereadcomno,
                            								 writekeymode,
                                                             writesecnum,
                                                             writekey,
                                                             writekh,
                                                             writebalance,
                                                             writedwmm,
                                                             writedaytime,
                                                             writecardtype,
                                                             writemode,
                                                             writeDelayms);
                            if(writestatus)
                            {
                            //    ShowMessage("写卡失败！");
                            //    return;
                            	//写卡失败,进行错误信息保存
                                int colscount = LV->Columns->Count-1;
                                errstr += LI->Caption;
                                errstr += "\t";
								for(int i = 0; i < colscount; i++)
                                {
                                    errstr += LI->SubItems->Strings[i];
                                    if(i != (colscount-1))
                                        errstr += "\t";
                                }
								errstr += "\n";

                                startindex++;
                                return;
                            }
                            else
                            {
								//写卡成功
								//写卡成功
								if(CheckBox1->Checked)
								{
									if(!pacarddllproc)
									{
										ClearCardInfoProc(writereadcomno,
														  writekeymode,
														  writesecnum,
														  writekey,
														  writeDelayms);
										beepofreaddll(readcomno, '10');

										Panel2->Caption = "写卡时间限制函数加载失败!";

										int colscount = LV->Columns->Count-1;
										errstr += LI->Caption;
										errstr += "\t";
										for(int i = 0; i < colscount; i++)
										{
											errstr += LI->SubItems->Strings[i];
											if(i != (colscount-1))
												errstr += "\t";
										}
										errstr += "\n";

										startindex++;

										return;
									}

									unsigned char limitwritedaytime[4];
									String limitwritetmpstr = DateToStr(UseDateEdit->Date);
									char* limitwritetmpdatestr = limitwritetmpstr.t_str();
									limitwritedaytime[0] = char(((int)limitwritetmpdatestr[2]-48)*16+((int)limitwritetmpdatestr[3]-48));
									limitwritedaytime[1] = char(((int)limitwritetmpdatestr[5]-48)*16+((int)limitwritetmpdatestr[6]-48));
									limitwritedaytime[2] = char(((int)limitwritetmpdatestr[8]-48)*16+((int)limitwritetmpdatestr[9]-48));
									limitwritedaytime[3] = 0x00;

									unsigned char sendbuflen = 26;
									unsigned char sendbuf[26];
									ZeroMemory(sendbuf,26);
									unsigned char recbuf[140];
									unsigned char recbuflen;
									ZeroMemory(recbuf, 140);

									sendbuf[0] = (secnum+1)*4+2;//扇区×4+块号
									sendbuf[1] = 0x60;//固定为0x60
									sendbuf[2] = 2;//命令字：1为读，2为写
									sendbuf[3] = keymode;
									sendbuf[4] = writekey[0];
									sendbuf[5] = writekey[1];
									sendbuf[6] = writekey[2];
									sendbuf[7] = writekey[3];
									sendbuf[8] = writekey[4];
									sendbuf[9] = writekey[5];

									sendbuf[23] = limitwritedaytime[0];
									sendbuf[24] = limitwritedaytime[1];
									sendbuf[25] = limitwritedaytime[2];

									WORD limitStatus = pacarddllproc(writereadcomno,sendbuflen,sendbuf,&recbuflen,recbuf,writeDelayms);

									if((0 != limitStatus)||(0 != recbuf[2]))
									{
										ClearCardInfoProc(writereadcomno,
														  writekeymode,
														  writesecnum,
														  writekey,
														  writeDelayms);
										beepofreaddll(readcomno, '10');

										Panel2->Caption = "写卡时间限制失败!";

										int colscount = LV->Columns->Count-1;
										errstr += LI->Caption;
										errstr += "\t";
										for(int i = 0; i < colscount; i++)
										{
											errstr += LI->SubItems->Strings[i];
											if(i != (colscount-1))
												errstr += "\t";
										}
										errstr += "\n";

										startindex++;

										return;
									}
								}

                                Panel2->Caption = "写卡成功，正在信息入库，请勿将卡从读卡器上移走！";
								Sleep(200);
                                String DateofLaunchCard;
                                SYSTEMTIME tmpsystime;
                                GetLocalTime(&tmpsystime);
                                DateofLaunchCard = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

                                int tmpdeposit = GlobalFKYJ;
                                double tmpPrePay = StrToFloat(MoneyTextEdit->Text);
                                double moneyincard = tmpPrePay;//-tmpdeposit;

                                //填写CARD表
								String tmpstr = SerialNumOFCard;
                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                String sqlstr = "insert into CARD values(:BH,:KH,:BKH,:XM,:XB,";
                                sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
                                                ":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
                                                ":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
                                                ":SF_KL,:USERNAME)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;
                                //ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("XM")->Value = NameTextEdit->Text;
                                ADOQuery1->Parameters->ParamByName("XB")->Value = ZWTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("SFZH")->Value = NULL;
								if(GroupTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BM")->Value = GroupTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BM")->Value = "";

                                if(ClassTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BZ")->Value = "";

                                ADOQuery1->Parameters->ParamByName("ZB")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("ZW")->Value = "";
                                ADOQuery1->Parameters->ParamByName("JB")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
                                //ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("TYJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
                                ADOQuery1->Parameters->ParamByName("GRMM")->Value = "1234";
                                ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
                                //ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SF_FL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
                                //ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
                                //ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
								ADOQuery1->ExecSQL();

                                //填写CARD_F表
                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into CARD_F values(:BH,:KH,:BKH,:XM,:XB,";
                                sqlstr = sqlstr+":SFZH,:BM,:BZ,:ZB,:ZW,:JB,:RQ,:TKRQ,:YJ,:TYJ,"+
                                ":ZT,:GRMM,:BTBZ,:BT_YE,:BTYEDT,:BTSYCS,:SF_YE,"+
                                ":SFYEDT,:SYCS,:FKSK,:SF_FL,:GLF,:FKJE,:TKJE,:TKBT,"+
                                ":SF_KL,:USERNAME)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;
								ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;
                                //ADOQuery1->Parameters->ParamByName("BKH")->Value = NULL;
								ADOQuery1->Parameters->ParamByName("XM")->Value = NameTextEdit->Text;
                                ADOQuery1->Parameters->ParamByName("XB")->Value = ZWTextEdit->Text;
								ADOQuery1->Parameters->ParamByName("SFZH")->Value = NULL;
								if(GroupTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BM")->Value = GroupTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BM")->Value = "";

								if(ClassTextEdit->Text.Length() > 0)
									ADOQuery1->Parameters->ParamByName("BZ")->Value = ClassTextEdit->Text;
								else
									ADOQuery1->Parameters->ParamByName("BZ")->Value = "";

                                ADOQuery1->Parameters->ParamByName("ZB")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("ZW")->Value = "";
                                ADOQuery1->Parameters->ParamByName("JB")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("RQ")->Value = DateofLaunchCard;
                                //ADOQuery1->Parameters->ParamByName("TKRQ")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("YJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("TYJ")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("ZT")->Value = "发卡";
                                ADOQuery1->Parameters->ParamByName("GRMM")->Value = "1234";
                                ADOQuery1->Parameters->ParamByName("BTBZ")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("BT_YE")->Value = 0;
                                //ADOQuery1->Parameters->ParamByName("BTYEDT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("BTSYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFYEDT")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKSK")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SF_FL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("GLF")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("FKJE")->Value = moneyincard;
                                //ADOQuery1->Parameters->ParamByName("TKJE")->Value = NULL;
                                //ADOQuery1->Parameters->ParamByName("TKBT")->Value = NULL;
                                ADOQuery1->Parameters->ParamByName("SF_KL")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("USERNAME")->Value = OperatorName;
                                ADOQuery1->ExecSQL();

                                //填写MX,MXBAK表
                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "K";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();
                                ADOQuery1->Close();

                                //添加扣押金记录
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MX values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "W";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();

                                //添加扣押金记录
/*                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = tmpdeposit;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "W";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();

                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into MXBAK values(:BH,:KH,:SF_YE,:SFJE,:SYCS,:SFRQ,:JYNO,:GZZID,:SFLX,:CZY,:SCRQ)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->Parameters->ParamByName("KH")->Value = bltmpkh;//LaunchNewCardADOQ->FieldByName("KH")->AsInteger;
                                ADOQuery1->Parameters->ParamByName("SF_YE")->Value = moneyincard;
                                ADOQuery1->Parameters->ParamByName("SFJE")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SYCS")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("SFRQ")->Value = DateofLaunchCard;
                                ADOQuery1->Parameters->ParamByName("JYNO")->Value = 0;
                                ADOQuery1->Parameters->ParamByName("GZZID")->Value = 1;
                                ADOQuery1->Parameters->ParamByName("SFLX")->Value = "K";
                                ADOQuery1->Parameters->ParamByName("CZY")->Value = OperatorName;
                                ADOQuery1->Parameters->ParamByName("SCRQ")->Value = DateofLaunchCard;
                                ADOQuery1->ExecSQL();      */

                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                String kztsqlstr = "select * from KZT where KH=";
                                kztsqlstr += bltmpkh;
                                ADOQuery1->SQL->Add(kztsqlstr);
                                ADOQuery1->Open();
                                if(!ADOQuery1->IsEmpty())
                                {
                                    ADOQuery1->Edit();
                                    ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
                                    ADOQuery1->FieldByName("SY")->AsAnsiString = 'Y';
                                    ADOQuery1->FieldByName("FKRQ")->AsAnsiString = DateofLaunchCard;
                                    ADOQuery1->FieldByName("GS")->AsAnsiString = '0';
                                	ADOQuery1->FieldByName("TKRQ")->AsAnsiString = "";
                                	ADOQuery1->FieldByName("WITHCARDTK")->AsAnsiString = "";
                                    ADOQuery1->Post();
                                }
                                ADOQuery1->Close();
                                ADOQuery1->SQL->Clear();
                                sqlstr = "insert into BHUSED values(:BH)";
                                ADOQuery1->SQL->Add(sqlstr);
                                ADOQuery1->Parameters->ParamByName("BH")->Value = SerialNumOFCard;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
                                ADOQuery1->ExecSQL();
								ADOQuery1->Close();

								//检查入库情况
								ADOQuery1->SQL->Clear();
								sqlstr = "select * from CARD where KH=";
								sqlstr += bltmpkh;
								ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Open();
								if(!ADOQuery1->IsEmpty())
								{
									int chkkh = ADOQuery1->FieldByName("KH")->AsInteger;
									AnsiString chkbh = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
									String chkname = ADOQuery1->FieldByName("XM")->AsString.Trim();
									double chkje = ADOQuery1->FieldByName("SF_YE")->AsFloat;

									if(chkkh != bltmpkh)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("KH")->AsInteger = bltmpkh;
										ADOQuery1->Post();
									}

									if(chkbh != SerialNumOFCard)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
										ADOQuery1->Post();
									}

									if(chkname != NameTextEdit->Text)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("XM")->AsString = NameTextEdit->Text;
										ADOQuery1->Post();
									}

									if(chkje != moneyincard)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("SF_YE")->AsFloat = moneyincard;
										ADOQuery1->FieldByName("FKJE")->AsFloat = moneyincard;
										ADOQuery1->Post();
									}
								}
								ADOQuery1->Close();

								ADOQuery1->SQL->Clear();
								sqlstr = "select * from CARD_F where KH=";
								sqlstr += bltmpkh;
								ADOQuery1->SQL->Add(sqlstr);
								ADOQuery1->Open();
								if(!ADOQuery1->IsEmpty())
								{
									int chkkh = ADOQuery1->FieldByName("KH")->AsInteger;
									AnsiString chkbh = ADOQuery1->FieldByName("BH")->AsAnsiString.Trim();
									String chkname = ADOQuery1->FieldByName("XM")->AsString.Trim();
									double chkje = ADOQuery1->FieldByName("SF_YE")->AsFloat;

									if(chkkh != bltmpkh)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("KH")->AsInteger = bltmpkh;
										ADOQuery1->Post();
									}

									if(chkbh != SerialNumOFCard)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("BH")->AsAnsiString = SerialNumOFCard;
										ADOQuery1->Post();
									}

									if(chkname != NameTextEdit->Text)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("XM")->AsString = NameTextEdit->Text;
										ADOQuery1->Post();
									}

									if(chkje != moneyincard)
									{
										ADOQuery1->Edit();
										ADOQuery1->FieldByName("SF_YE")->AsFloat = moneyincard;
										ADOQuery1->FieldByName("FKJE")->AsFloat = moneyincard;
										ADOQuery1->Post();
									}
								}
								ADOQuery1->Close();

                                beepofreaddll(readcomno, '10');

                                //写加密狗增加充值
                                if(DOGChk)
                                {
                                    unsigned char tempbuf[8];
                                    SFK_ZE += moneyincard;
                                    UpZETable->FieldByName("SFKZE")->AsFloat += moneyincard;
                                    memcpy(tempbuf,&SFK_ZE,8);
                                    unsigned char hightempchar1;
                                    unsigned char lowtempchar1;
                                    for(int t = 0; t < 8; t++)
                                    {
                                        hightempchar1 = tempbuf[t]&0xf0;
                                        lowtempchar1 = tempbuf[t]&0x0f;

                                        hightempchar1 = hightempchar1>>4;
                                        hightempchar1 = hightempchar1&0x0f;

                                        lowtempchar1 = lowtempchar1<<4;
                                        lowtempchar1 = lowtempchar1&0xf0;

                                        tempbuf[t] = hightempchar1|lowtempchar1;
                                    }
                                    int dogoffset = 0x0034;
                                    int doglen = 8;
                                    RY3_Write(doghandle,dogoffset,tempbuf,doglen);
                                }
								//写加密狗完毕

						//		ShowMessage("发卡成功！请更换一张待发的新卡！");
                                Panel2->Caption = "发卡成功！请更换一张待发的新卡！";

                                startindex++;
                            }
                        }
                    }
                    else
                    {
                        ShowMessage("系统中已无可用卡号，请联系技术人员!");
                        Panel2->Caption = "系统中已无可用卡号，请联系技术人员!";
                        BLTime->Enabled = false;
                        cxButton1->Enabled = true;
                    //    this->Close();
                    }
                }
            }
            else
            {
                ShowMessage("读卡函数加载失败！");
                BLTime->Enabled = false;
                cxButton1->Enabled = true;
                Panel2->Caption = "读卡函数加载失败！";
            //    this->Close();
            }
        }
        else
        {
            ShowMessage("加载读写卡动态链接库失败！");
            BLTime->Enabled = false;
            cxButton1->Enabled = true;
            Panel2->Caption = "加载读写卡动态链接库失败！";
        //    this->Close();
        }
	}
	else
	{
		int colscount = LV->Columns->Count-1;
		errstr += LI->Caption;
		errstr += "\t";
		for(int i = 0; i < colscount; i++)
		{
			errstr += LI->SubItems->Strings[i];
			if(i != (colscount-1))
				errstr += "\t";
		}
		errstr += "\n";

		startindex++;
		return;
/*		ShowMessage("至少得填写姓名，职务，金额，卡号，编号五项!");
		BLTime->Enabled = false;    */
	}
}
//---------------------------------------------------------------------------

void __fastcall TBatchLaunchCardProcessForm::FormShow(TObject *Sender)
{
	UseDateEdit->Enabled = true;
	CheckBox1->Enabled = true;
	CheckBox1->Checked = false;
	startindex = -1;
    alllinecount = -1;
	errstr = "";
    cxButton1->Enabled = true;
    Panel2->Caption = "请放置一张空白卡于发卡器上!";
	NameTextEdit->Text = "";
	MoneyTextEdit->Text = "";
	GroupTextEdit->Text = "";
	ClassTextEdit->Text = "";
	UseDateEdit->Date = IncYear(Date(), 3);
}
//---------------------------------------------------------------------------

