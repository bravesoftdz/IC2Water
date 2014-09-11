//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "CheckedBCFRM.h"
#include "SDIMAIN.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxListView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxProgressBar"
#pragma link "cxRichEdit"
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
#pragma link "cxCheckGroup"
#pragma link "cxCheckListBox"
#pragma resource "*.dfm"
TCheckBatchCollectFRM *CheckBatchCollectFRM;
//---------------------------------------------------------------------------
__fastcall TCheckBatchCollectFRM::TCheckBatchCollectFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCheckBatchCollectFRM::ExitBTNClick(TObject *Sender)
{
	if(mrOk == MessageBox(this->Handle, "是否确认退出选定批量数据采集程序？", "请确认", MB_OKCANCEL))
	{
		if(ScanPCBThread)
		{
			if(!ScanPCBThread->Finished)
				ScanPCBThread->Terminate();
		}

		if(CBCDThread)
		{
			if(!CBCDThread->Finished)
				CBCDThread->Terminate();
		}

	//	SDIAppForm->dxNavBar1->Enabled = true;
		if(CBCDThread)
		{
			if(CBCDThread->Finished)
			{
				ModeOFCollect = 0;
				ZeroMemory(PosInUseTag, 300);
			 //	if(BatchDataSaveToFileStream)
			 //		BatchDataSaveToFileStream.close();
				this->Close();
			}
		}
		else
		{
			ModeOFCollect = 0;
			ZeroMemory(PosInUseTag, 300);
	   //		if(BatchDataSaveToFileStream)
	   //			BatchDataSaveToFileStream.close();
			this->Close();
        }
    	if(ReportClick)
        	SDIAppForm->dxNavBar1Group8Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchCollectFRM::FormCreate(TObject *Sender)
{
	CBatchOnlinePosNum = 0;

	ScallProgressBar->Visible = true;
	ScallProgressBar->Position = 0;
	CollectProgressBar->Visible = false;
	BatchCollectBTN->Enabled = false;
	ExitBTN->Enabled = true;

	Collecting = false;
	Scanning = false;
}
//---------------------------------------------------------------------------
void __fastcall TCheckBatchCollectFRM::FormShow(TObject *Sender)
{
	if(!Collecting&&!Scanning)
	{
		Panel7->Caption = "请先进行“扫描在线机器”操作！";//"正在进行“扫描在线POS机”程序！";
		CBatchOnlinePosNum = 0;
		ModeOFCollect = 3;
/*		cxCheckListBox1->Items->Clear();

		TcxCheckListBoxItem* tmpitem = cxCheckListBox1->Items->Add();
		tmpitem->ImageIndex = 1;
		tmpitem->Text = "testing";
		ShowMessage(tmpitem->DisplayName);   */
		DataRichEdit->Lines->Clear();
		ScallProgressBar->Visible = true;
		ScallProgressBar->Position = 0;
		CollectProgressBar->Visible = false;
		BatchCollectBTN->Enabled = false;
		ExitBTN->Enabled = true;
		cxCheckListBox1->Items->Clear();
		DisPlayListView->Items->Clear();

 /*		if(!ScanPCBThread)
		{
			ScanPCBThread = new TScanPosCheckBatchThread(true,
														 &Scanning,
														 ScallProgressBar,
														 cxCheckListBox1,
														 BatchCollectBTN,
														 ExitBTN,
														 Panel7,
														 &CBatchOnlinePosNum,
														 CheckBCADOQ);
			if(ScanPCBThread)
				ScanPCBThread->Resume();
		}
		else
		{
			if(ScanPCBThread->Finished)
			{
				ScanPCBThread = new TScanPosCheckBatchThread(true,
															 &Scanning,
															 ScallProgressBar,
															 cxCheckListBox1,
															 BatchCollectBTN,
															 ExitBTN,
															 Panel7,
															 &CBatchOnlinePosNum,
															 CheckBCADOQ);
			}

			if(ScanPCBThread)
				ScanPCBThread->Resume();
		}     */
	}
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchCollectFRM::BatchCollectBTNClick(TObject *Sender)
{
/*	if(true == FileExists(GlobalPath+"\\StroeBatchDataFile.dat"))
	{
		ShowMessage("由于上次“批量采集”的数据还未入库，请先进行“数据入库”!");
		InBaseBTN->Enabled = true;
	}
	else
	{       */
		String SaveFileName = GlobalPath;
		SaveFileName += "\\BatchOrignalData\\";
		SaveFileName += DateToStr(Date());
		SaveFileName += "_";
		SYSTEMTIME st;
		GetSystemTime(&st);
 //		SaveFileName += TimeToStr(Now());
		SaveFileName += (st.wHour+8)%24;
		SaveFileName += "#";
		SaveFileName += st.wMinute;
		SaveFileName += "#";
		SaveFileName += st.wSecond;
		SaveFileName += ".bak";

		if(CDBatchDataSaveToFileStream.is_open())
			CDBatchDataSaveToFileStream.close();

		CDBatchDataSaveToFileStream.open(SaveFileName.t_str(), ios::app);
		if(!CDBatchDataSaveToFileStream.is_open())
		{
			ShowMessage("由于无法建立选定批量采集数据保存文档，选定批量采集数据不能进行!");
			return;
		}

		if(!CBCDThread)
		{
			CBCDThread = new TCheckedBatchCollectDataThread(true,
														 &Collecting,
														 cxCheckListBox1,
														 DisPlayListView,
														 &CBatchOnlinePosNum,
                                                         CollectProgressBar,
														 CheckBCADOQ,
														 Panel7,
														 InBaseBTN,
														 ExitBTN,
														 cxButton1);
			if(CBCDThread)
			{
				Panel7->Caption = "正在进行“批量数据采集”程序！";
				ScallProgressBar->Visible = false;
				CollectProgressBar->Visible = true;
				BatchCollectBTN->Enabled = false;
				InBaseBTN->Enabled = false;
				CBCDThread->Resume();
				ADOQuery1->SQL->Clear();
				String sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
				ADOQuery1->SQL->Add(sqlstr);
				ADOQuery1->Parameters->ParamByName("BH")->Value = -1;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
				ADOQuery1->Parameters->ParamByName("KH")->Value = -1;
				ADOQuery1->Parameters->ParamByName("JE")->Value = -1;
				ADOQuery1->Parameters->ParamByName("YE")->Value = -1;
				ADOQuery1->Parameters->ParamByName("LX")->Value = "批量采集";
				ADOQuery1->Parameters->ParamByName("Operator")->Value = OperatorName;
				ADOQuery1->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
				ADOQuery1->ExecSQL();
				ADOQuery1->Close();
			}
			else
				ShowMessage("BatchCollectdataThread No Exist!");
		}
		else
		{
			if(CBCDThread->Suspended)
			{
				Panel7->Caption = "正在进行“批量数据采集”程序！";
				ScallProgressBar->Visible = false;
				CollectProgressBar->Visible = true;
				CBCDThread->Resume();
				BatchCollectBTN->Enabled = false;
				InBaseBTN->Enabled = false;
			}
			else if(CBCDThread->Finished)
			{
				CBCDThread = new TCheckedBatchCollectDataThread(true,
															 &Collecting,
															 cxCheckListBox1,
															 DisPlayListView,
															 &CBatchOnlinePosNum,
                                                             CollectProgressBar,
															 CheckBCADOQ,
															 Panel7,
															 InBaseBTN,
															 ExitBTN,
															 cxButton1);
				if(CBCDThread)
				{
					Panel7->Caption = "正在进行“批量数据采集”程序!";
					ScallProgressBar->Visible = false;
					CollectProgressBar->Visible = true;
					CBCDThread->Resume();
					BatchCollectBTN->Enabled = false;
					InBaseBTN->Enabled = false;
					ADOQuery1->SQL->Clear();
					String sqlstr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
					ADOQuery1->SQL->Add(sqlstr);
					ADOQuery1->Parameters->ParamByName("BH")->Value = -1;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
					ADOQuery1->Parameters->ParamByName("KH")->Value = -1;
					ADOQuery1->Parameters->ParamByName("JE")->Value = -1;
					ADOQuery1->Parameters->ParamByName("YE")->Value = -1;
					ADOQuery1->Parameters->ParamByName("LX")->Value = "批量采集";
					ADOQuery1->Parameters->ParamByName("Operator")->Value = OperatorName;
					ADOQuery1->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
					ADOQuery1->ExecSQL();
					ADOQuery1->Close();
				}
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchCollectFRM::InBaseBTNClick(TObject *Sender)
{
	if(!CBIBThread)
	{
		ScallProgressBar->Visible = true;
		CollectProgressBar->Visible = false;
		CBIBThread = new TCheckBatchInBaseThread(true,
											   InBaseBTN,
											   BatchCollectBTN,
											   ExitBTN,
											   ScallProgressBar,
											   CheckIBADOQ,
											   Panel7);
		if(CBIBThread)
		{
			Panel7->Caption = "正在进行“批量数据入库”程序!";
			CBIBThread->Resume();
		}
		else
			ShowMessage("BatchDataInBaseThread No Exist!");
	}
	else
	{
		if(CBIBThread->Finished)
		{
			ScallProgressBar->Visible = true;
			CollectProgressBar->Visible = false;
			CBIBThread = new TCheckBatchInBaseThread(true,
												   InBaseBTN,
												   BatchCollectBTN,
												   ExitBTN,
												   ScallProgressBar,
												   CheckIBADOQ,
												   Panel7);
			if(CBIBThread)
			{
				Panel7->Caption = "正在进行“批量数据入库”程序!";
				CBIBThread->Resume();
			}
			else
				ShowMessage("BatchDataInBaseThread No Exist!");
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TCheckBatchCollectFRM::cxButton1Click(TObject *Sender)
{
	if(!ScanPCBThread)
	{
		ScanPCBThread = new TScanPosCheckBatchThread(true,
													 &Scanning,
													 ScallProgressBar,
													 cxCheckListBox1,
													 BatchCollectBTN,
													 ExitBTN,
													 cxButton1,
													 Panel7,
													 &CBatchOnlinePosNum,
													 CheckBCADOQ);
		if(ScanPCBThread)
			ScanPCBThread->Resume();
	}
	else
	{
		if(ScanPCBThread->Finished)
		{
			ScanPCBThread = new TScanPosCheckBatchThread(true,
														 &Scanning,
														 ScallProgressBar,
														 cxCheckListBox1,
														 BatchCollectBTN,
														 ExitBTN,
														 cxButton1,
														 Panel7,
														 &CBatchOnlinePosNum,
														 CheckBCADOQ);
		}

		if(ScanPCBThread)
			ScanPCBThread->Resume();
	}
}
//---------------------------------------------------------------------------

