//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "BatchCollectDataFRM.h"
#include "SDIMAIN.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
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
#pragma link "cxButtons"
#pragma link "cxCustomData"
#pragma link "cxGroupBox"
#pragma link "cxInplaceContainer"
#pragma link "cxListView"
#pragma link "cxMemo"
#pragma link "cxProgressBar"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxTL"
#pragma link "cxTLdxBarBuiltInMenu"
#pragma link "cxRichEdit"
#pragma resource "*.dfm"
TBatchCollectFRM *BatchCollectFRM;

//---------------------------------------------------------------------------

__fastcall TBatchCollectFRM::TBatchCollectFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::BatchCollectBTNClick(TObject *Sender)
{
/*	if(true == FileExists(GlobalPath+"\\StroeBatchDataFile.dat"))
	{
		ShowMessage("由于上次“批量采集”的数据还未入库，请先进行“数据入库”!");
		InBaseBTN->Enabled = true;
	}
	else
	{    */
		String SaveFileName = GlobalPath;
		SaveFileName += "\\BatchOrignalData\\";
		SaveFileName += DateToStr(Date());
		SaveFileName += "_";
		SYSTEMTIME st;
		GetSystemTime(&st);
		SaveFileName += (st.wHour+8)%24;
		SaveFileName += "#";
		SaveFileName += st.wMinute;
		SaveFileName += "#";
		SaveFileName += st.wSecond;
		SaveFileName += ".bak";

		if(BatchDataSaveToFileStream.is_open())
			BatchDataSaveToFileStream.close();

		BatchDataSaveToFileStream.open(SaveFileName.t_str(), ios::app|ios::out);
		if(!BatchDataSaveToFileStream.is_open())
		{
			ShowMessage("由于无法建立批量采集数据保存文档，批量采集数据不能进行!");
			return;
		}

		if(!BatchCollectDataThread)
		{

			BatchCollectDataThread = new TBatchCollectDataThread(true,
																 &Collecting,
																 TreeView1,
																 DisPlayListView,
																 &BatchOnlinePosNum,
                                                                 CollectProgressBar,
																 BatchCollectADOQuery,
																 Panel7,
																 InBaseBTN,
																 ExitBTN,
																 cxButton1);
			if(BatchCollectDataThread)
			{
				Panel7->Caption = "正在进行“批量数据采集”程序！";
				ScallProgressBar->Visible = false;
				CollectProgressBar->Visible = true;
				BatchCollectBTN->Enabled = false;
				InBaseBTN->Enabled = false;
				BatchCollectDataThread->Resume();
				ADOQuery1->Close();
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
			if(BatchCollectDataThread->Suspended)
			{
				Panel7->Caption = "正在进行“批量数据采集”程序！";
				ScallProgressBar->Visible = false;
				CollectProgressBar->Visible = true;
				BatchCollectDataThread->Resume();
				BatchCollectBTN->Enabled = false;
				InBaseBTN->Enabled = false;
			//	PauseThreadBTN->Enabled = true;
			}
			else if(BatchCollectDataThread->Finished)
			{
				BatchCollectDataThread = new TBatchCollectDataThread(true,
																	 &Collecting,
																	 TreeView1,
																	 DisPlayListView,
																	 &BatchOnlinePosNum,
                                                                     CollectProgressBar,
																	 BatchCollectADOQuery,
																	 Panel7,
																	 InBaseBTN,
																	 ExitBTN,
																	 cxButton1);
				if(BatchCollectDataThread)
				{
					Panel7->Caption = "正在进行“批量数据采集”程序!";
					ScallProgressBar->Visible = false;
					CollectProgressBar->Visible = true;
					BatchCollectDataThread->Resume();
					BatchCollectBTN->Enabled = false;
					InBaseBTN->Enabled = false;
					ADOQuery1->Close();
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
				//	PauseThreadBTN->Enabled = true;
				}
			}
		}
	 //	else
	 //	{
	 //		ShowMessage("打开批量采集数据保存文档失败，请联系相关技术人员！");
	 //	}
 //	}
}
//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::InBaseBTNClick(TObject *Sender)
{
	if(!BatchDataInBaseThread)
	{
		ScallProgressBar->Visible = true;
		CollectProgressBar->Visible = false;
		BatchDataInBaseThread = new TBatchDataInBaseThread(true,
														   InBaseBTN,
														   BatchCollectBTN,
														   ExitBTN,
														   ScallProgressBar,
														   InBaseADOQuery,
														   DataRichEdit,
														   Panel7);
		if(BatchDataInBaseThread)
		{
			Panel7->Caption = "正在进行“批量数据入库”程序!";
			BatchDataInBaseThread->Resume();
		}
		else
			ShowMessage("BatchDataInBaseThread No Exist!");
	}
	else
	{
		if(BatchDataInBaseThread->Finished)
		{
			ScallProgressBar->Visible = true;
			CollectProgressBar->Visible = false;
			BatchDataInBaseThread = new TBatchDataInBaseThread(true,
															   InBaseBTN,
															   BatchCollectBTN,
															   ExitBTN,
															   ScallProgressBar,
															   InBaseADOQuery,
															   DataRichEdit,
															   Panel7);
			if(BatchDataInBaseThread)
			{
				Panel7->Caption = "正在进行“批量数据入库”程序!";
				BatchDataInBaseThread->Resume();
			}
			else
				ShowMessage("BatchDataInBaseThread No Exist!");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::FormCreate(TObject *Sender)
{
	BatchOnlinePosNum = 0;

	ScallProgressBar->Visible = true;
	ScallProgressBar->Position = 0;
	CollectProgressBar->Visible = false;
 //	ScallPOSBTN->Enabled = true;
	BatchCollectBTN->Enabled = false;
//	PauseThreadBTN->Enabled = false;
	ExitBTN->Enabled = true;

	Collecting = false;
	Scanning = false;
}
//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::FormShow(TObject *Sender)
{
//	SDIAppForm->dxNavBar1->Enabled = false;
//	Panel7->Caption = "请先进行“扫描在线POS机”操作！";
	if(!Collecting&&!Scanning)
	{
		Panel7->Caption = "请先进行“扫描在线机器”操作！";//"正在进行“扫描在线POS机”程序！";
		BatchOnlinePosNum = 0;
		ModeOFCollect = 2;
		DisPlayListView->Items->Clear();

	//	PosTreeList->Items[0]->DeleteChildren();
		DataRichEdit->Lines->Clear();
		ScallProgressBar->Visible = true;
		ScallProgressBar->Position = 0;
		CollectProgressBar->Visible = false;
	//	ScallPOSBTN->Enabled = true;
		BatchCollectBTN->Enabled = false;
	//	PauseThreadBTN->Enabled = false;
		ExitBTN->Enabled = true;
		TreeView1->Items->Clear();


	//	ScallPOSBTN->Enabled = false;

/*		if(!ScallPosThread)
		{
			ScallPosThread = new TScallPosThread(true,
												 &Scanning,
												 ScallProgressBar,
												 TreeView1,
												 BatchCollectBTN,
												 ExitBTN,
												 Panel7,
												 &BatchOnlinePosNum,
												 BatchCollectADOQuery);
			if(ScallPosThread)
				ScallPosThread->Resume();
		}
		else
		{
			if(ScallPosThread->Finished)
			{
				ScallPosThread = new TScallPosThread(true,
													 &Scanning,
													 ScallProgressBar,
													 TreeView1,
													 BatchCollectBTN,
													 ExitBTN,
													 Panel7,
													 &BatchOnlinePosNum,
													 BatchCollectADOQuery);
		   //		PauseThreadBTN->Enabled = true;
			}
			if(ScallPosThread)
				ScallPosThread->Resume();
		}    */
	}
}
//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::ExitBTNClick(TObject *Sender)
{
/*	int count = DisPlayListView->Items->Count;
	TListItem* tmp = DisPlayListView->Items->Item[count-1];
	ShowMessage(tmp->SubItems->Strings[1]); */

	if(mrOk == MessageBox(this->Handle, "是否确认退出批量数据采集程序？", "请确认", MB_OKCANCEL|MB_ICONQUESTION))
	{
		if(ScallPosThread)
		{
			if(!ScallPosThread->Finished)
				ScallPosThread->Terminate();
		}

		if(BatchCollectDataThread)
		{
			if(!BatchCollectDataThread->Finished)
				BatchCollectDataThread->Terminate();
		}

	//	SDIAppForm->dxNavBar1->Enabled = true;
		if(BatchCollectDataThread)
		{
			if(BatchCollectDataThread->Finished)
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
		 //	if(BatchDataSaveToFileStream)
		 //		BatchDataSaveToFileStream.close();
			this->Close();
        }
		if(ReportClick)
        	SDIAppForm->dxNavBar1Group8Click(Sender);
	}
}
//---------------------------------------------------------------------------







/*void __fastcall TBatchCollectFRM::ScallPOSBTNClick(TObject *Sender)
{
	Panel7->Caption = "正在进行“扫描在线POS机”程序！";
	ScallPOSBTN->Enabled = false;

	if(!ScallPosThread)
	{
		ScallPosThread = new TScallPosThread(true,
											 ScallProgressBar,
											 PosTreeList,
											 BatchCollectBTN,
											 PauseThreadBTN,
											 &BatchOnlinePosNum,
											 BatchCollectADOQuery);
		ScallPosThread->Resume();
	}
	else
	{
		if(ScallPosThread->Finished)
		{
			ScallPosThread = new TScallPosThread(true,
												 ScallProgressBar,
												 PosTreeList,
												 BatchCollectBTN,
												 PauseThreadBTN,
												 &BatchOnlinePosNum,
												 BatchCollectADOQuery);
			PauseThreadBTN->Enabled = true;
		}

		if(ScallPosThread->Suspended)
			PauseThreadBTN->Enabled = true;
		ScallPosThread->Resume();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::PauseThreadBTNClick(TObject *Sender)
{
/*	if(BatchCollectDataThread)
	{
		if((!BatchCollectDataThread->Suspended)&&(!BatchCollectDataThread->Finished))
		{
			BatchCollectDataThread->Suspend();
			ScallProgressBar->Visible = false;
			CollectProgressBar->Visible = true;
			BatchCollectBTN->Enabled = true;
		//	PauseThreadBTN->Enabled = false;
			Panel7->Caption = "已暂停“批量采集数据”程序！";
		}
	}

	if(ScallPosThread)
	{
		if((!ScallPosThread->Suspended)&&(!ScallPosThread->Finished))
		{
			ScallPosThread->Suspend();
			ScallProgressBar->Visible = true;
			CollectProgressBar->Visible = false;
		 //	ScallPOSBTN->Enabled = true;
		 //	PauseThreadBTN->Enabled = false;
			Panel7->Caption = "已暂停“扫描在线POS机”程序！";
		}
	}
}      */

//---------------------------------------------------------------------------

void __fastcall TBatchCollectFRM::cxButton1Click(TObject *Sender)
{
	if(!ScallPosThread)
		{
			ScallPosThread = new TScallPosThread(true,
												 &Scanning,
												 ScallProgressBar,
												 TreeView1,
												 BatchCollectBTN,
												 ExitBTN,
												 cxButton1,
												 Panel7,
												 &BatchOnlinePosNum,
												 BatchCollectADOQuery);
			if(ScallPosThread)
				ScallPosThread->Resume();
		}
		else
		{
			if(ScallPosThread->Finished)
			{
				ScallPosThread = new TScallPosThread(true,
													 &Scanning,
													 ScallProgressBar,
													 TreeView1,
													 BatchCollectBTN,
													 ExitBTN,
													 cxButton1,
													 Panel7,
													 &BatchOnlinePosNum,
													 BatchCollectADOQuery);
			}
			if(ScallPosThread)
				ScallPosThread->Resume();
		}
}
//---------------------------------------------------------------------------

