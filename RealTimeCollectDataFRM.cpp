// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalParameter.h"
#include "RealTimeCollectDataFRM.h"
#include "SDIMAIN.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxEdit"
#pragma link "cxInplaceContainer"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxTL"
#pragma link "cxTLdxBarBuiltInMenu"
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
#pragma link "cxGroupBox"
#pragma link "cxListView"
#pragma link "cxProgressBar"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"
TRealTimeCollectFRM *RealTimeCollectFRM;

// ---------------------------------------------------------------------------
__fastcall TRealTimeCollectFRM::TRealTimeCollectFRM(TComponent* Owner) : TForm
(Owner)
{
}
// ---------------------------------------------------------------------------

void __fastcall TRealTimeCollectFRM::RealCollectBTNClick(TObject *Sender)
{
//	double test;
//	int a = 333;
//	test = a/100;

//	ShowMessage(FloatToStr(test));
	String SaveFileName = GlobalPath;
	SaveFileName += "\\RealOrignalData\\";
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

//	ShowMessage(SaveFileName.c_str());

	if(DataSaveToFileStream.is_open())
		DataSaveToFileStream.close();

	DataSaveToFileStream.open(SaveFileName.t_str(), ios::app|ios::out, 0);


	if(DataSaveToFileStream.is_open())
	{
		if (!CollectdataThread)
		{
			CollectdataThread = new TCollectDataThread(true,
													   &Collecting,
													   cxCheckBox1->Checked,
													   DataDisplayView,
													   TreeView1,
													   &OnlinePosNum,
													   CollectDataADOQuery,
													   GSADOT
												  //	   UserNameTE,
												  //	   CardNoTE,
												  //	   PlaceTE,
												  //	   MoneyTE
												  );

			if (CollectdataThread)
			{
				Panel7->Caption = "正在进行“实时数据采集”程序！";
				ScallProgressBar->Visible = false;
				CollectProgressBar->Visible = true;
				RealCollectBTN->Enabled = false;
				CollectdataThread->Resume();
			}
			else
				ShowMessage("CollectdataThread No Exist!");
		}
		else
		{
			if (CollectdataThread->Suspended)
			{
				Panel7->Caption = "正在进行“实时数据采集”程序！";
				ScallProgressBar->Visible = false;
				CollectProgressBar->Visible = true;
				CollectdataThread->Resume();
				RealCollectBTN->Enabled = false;
			//	PauseThreadBTN->Enabled = true;
			}
			else if(CollectdataThread->Finished)
			{
				CollectdataThread = new TCollectDataThread(true,
														   &Collecting,
														   cxCheckBox1->Checked,
														   DataDisplayView,
														   TreeView1,
														   &OnlinePosNum,
														   CollectDataADOQuery,
														   GSADOT
													 //	   UserNameTE,
													 //	   CardNoTE,
													 //	   PlaceTE,
													 //	   MoneyTE
													 );
				if (CollectdataThread)
				{
					Panel7->Caption = "正在进行“实时数据采集”程序！";
					ScallProgressBar->Visible = false;
					CollectProgressBar->Visible = true;
					CollectdataThread->Resume();
					RealCollectBTN->Enabled = false;
			   //		PauseThreadBTN->Enabled = true;
				}
			}
		}
	}
	else
	{
		ShowMessage("打开实时采集数据保存文档失败，请联系相关技术人员！");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TRealTimeCollectFRM::FormShow(TObject *Sender)
{
//	SDIAppForm->dxNavBar1->Enabled = false;
	if(!Collecting&&!Scanning)
	{
		Panel7->Caption = "正在进行“扫描在线POS机”操作！";
		OnlinePosNum = 0;
   		ModeOFCollect = 1;

		DataDisplayView->Items->Clear();
		ScallProgressBar->Visible = true;
		ScallProgressBar->Position = 0;
		CollectProgressBar->Visible = false;
		RealCollectBTN->Enabled = false;
		ExitBTN->Enabled = true;

		if(!ScallPosThread)
		{
			ScallPosThread = new TScallPosThread(true,
												 &Scanning,
												 ScallProgressBar,
												 TreeView1,
												 RealCollectBTN,
												 ExitBTN,
												 cxButton1,
												 Panel7,
												 &OnlinePosNum,
												 CollectDataADOQuery);
			if(ScallPosThread)
			{
				ScallPosThread->Resume();
			}
		}
		else
		{
			if(ScallPosThread->Finished)
			{
				ScallPosThread = new TScallPosThread(true,
				                                     &Scanning,
													 ScallProgressBar,
													 TreeView1,
													 RealCollectBTN,
													 ExitBTN,
													 cxButton1,
													 Panel7,
													 &OnlinePosNum,
													 CollectDataADOQuery);
			}
			if(ScallPosThread)
				ScallPosThread->Resume();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TRealTimeCollectFRM::FormCreate(TObject *Sender)
{
	OnlinePosNum = 0;

	ScallProgressBar->Visible = true;
	ScallProgressBar->Position = 0;
	CollectProgressBar->Visible = false;
	RealCollectBTN->Enabled = false;
	ExitBTN->Enabled = true;

	Collecting = false;
	Scanning = false;
}
// ---------------------------------------------------------------------------

void __fastcall TRealTimeCollectFRM::ExitBTNClick(TObject *Sender)
{
	if(mrOk == MessageBox(this->Handle, "是否确认退出实时数据采集入库程序？", "请确认", MB_OKCANCEL|MB_ICONQUESTION))
	{
		if(ScallPosThread)
		{
			if(!ScallPosThread->Finished)
				ScallPosThread->Terminate();
		}

		if(CollectdataThread)
		{
			if(!CollectdataThread->Finished)
            {
				CollectdataThread->Terminate();
                this->Close();
            }
			if(CollectdataThread->Finished)
			{
				ModeOFCollect = 0;
				ZeroMemory(PosInUseTag, 300);
	  //			if(DataSaveToFileStream)
	  //				DataSaveToFileStream.close();
				this->Close();
			}
		}

		if(!CollectdataThread)
		{
			this->Close();
		}
	//	SDIAppForm->dxNavBar1->Enabled = true;

		ModeOFCollect = 0;
		ZeroMemory(PosInUseTag, 300);

    	if(ReportClick)
        	SDIAppForm->dxNavBar1Group8Click(Sender);
	//	if(DataSaveToFileStream)
	//		DataSaveToFileStream.close();

	//	SDIAppForm->dxNavBar1->Enabled = true;
	//	ModeOFCollect = 0;
	//	ZeroMemory(PosInUseTag, 300);
	//	Sleep(1000);
	//	this->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TRealTimeCollectFRM::InBaseBTNClick(TObject *Sender)
{
	//In Base Thread
}
//---------------------------------------------------------------------------


/* TListItem* tmp = DataDisplayView->Items->Add();
tmp->Caption = "hello!";
tmp->SubItems->Add("1");
tmp->SubItems->Add("2");
tmp->SubItems->Add("3");
tmp->Selected = true;
DataDisplayView->SetFocus();
DataDisplayView->Selected->MakeVisible(true); 	/*加Record表项

TcxTreeListNode* tmpnode = PosTreeList->Items[0]->AddChild();
tmpnode->ImageIndex = 1;
tmpnode->Texts[0] = "On line!";
tmpnode->Selected = true;
PosTreeList->SetFocus();
PosTreeList->Selections[0]->MakeVisible();      POS树节点滚动*

TcxTreeListNode* tmpnode;
tmpnode = PosTreeList->Items[0]->AddChild();
tmpnode->ImageIndex = 2;
tmpnode->Texts[0] = "OFF Line!"; 加POS树节点

//---------------------------------------------------------------------------
有用代码，主要用于采集消费记录！
void __fastcall TRealTimeCollectFRM::cxButton1Click(TObject *Sender)
{
if(SerReceiveFunc)
{
ShowMessage("load function successfully!");
WORD Status;
unsigned char como = 0x05;
WORD NO1 = 1;
unsigned char cmd = 0x25;
unsigned char receivebuf[16];
ZeroMemory(receivebuf, 16);
int receivelen = 16;
unsigned char* dir = "F:\\RAD\\2010819\\Recieve";
int dirlen = strlen(dir);

Status = SerReceiveFunc(como, NO1, cmd, receivebuf, receivelen, 1);
if(0 == Status)
{
ShowMessage("Collect Data successfully!");
}
}
}

//---------------------------------------------------------------------------
void __fastcall TRealTimeCollectFRM::cxButton2Click(TObject *Sender)
{
int tmpkh;
int tmpsycs;
int tmpye;
int tmpxfje;
String tmpdatestr;
String tmpxflx;

unsigned char receivebuf[16];
unsigned char instr[4];
unsigned char outstr[6];

ZeroMemory(receivebuf, 16);
ZeroMemory(instr, 4);
ZeroMemory(outstr, 6);

receivebuf[0] = 0x00;
receivebuf[1] = 0x00;
receivebuf[2] = 0x0b;
receivebuf[3] = 0x00;
receivebuf[4] = 0x0f;
receivebuf[5] = 0x01;
receivebuf[6] = 0x98;
receivebuf[7] = 0xfc;
receivebuf[8] = 0x00;
receivebuf[9] = 0x00;
receivebuf[10] = 0x64;
receivebuf[11] = 0xf6;
receivebuf[12] = 0xd6;
receivebuf[13] = 0xc9;
receivebuf[14] = 0xa6;
receivebuf[15] = 0x00;

if((receivebuf[0] != 0xFF)||(receivebuf[1] != 0xFF)||(receivebuf[2] != 0xFF))
{
ShowMessage("Valid Record");
tmpkh = (int)receivebuf[0]*256*256+(int)receivebuf[1]*256+(int)receivebuf[2];
tmpsycs = (int)receivebuf[3]*256+(int)receivebuf[4];
tmpye = ((int)receivebuf[5]*256*256+(int)receivebuf[6]*256+(int)receivebuf[7])/100;
tmpxfje = ((int)receivebuf[8]*256*256+(int)receivebuf[9]*256+(int)receivebuf[10])/100;

instr[0] = receivebuf[11];
instr[1] = receivebuf[12];
instr[2] = receivebuf[13];
instr[3] = receivebuf[14];

if(GetnormaldateFunc(instr, outstr) != 0)
{
ShowMessage("error in get normal date!");
outstr[0] = '0';
outstr[1] = '1';
outstr[2] = '1';
outstr[3] = '0';
outstr[4] = '0';
outstr[5] = '0';
}
else
{
tmpdatestr = "20"+IntToHex((int)outstr[0], 2)+"-"+
IntToHex((int)outstr[1], 2)+"-"+
IntToHex((int)outstr[2], 2)+" "+
IntToHex((int)outstr[3], 2)+":"+
IntToHex((int)outstr[4], 2)+":"+
IntToHex((int)outstr[5], 2);
ShowMessage(tmpdatestr);
}

if('0' == receivebuf[15])
tmpxflx = "X";
if('1' == receivebuf[15])
tmpxflx = "Y";
if('2' == receivebuf[15])
tmpxflx = "B";
if('3' == receivebuf[15])
tmpxflx = "A";
if('4' == receivebuf[15])
tmpxflx = "L";
if('5' == receivebuf[15])
tmpxflx = "M";
if('6' == receivebuf[15])
tmpxflx = "O";
if('7' == receivebuf[15])
tmpxflx = "P";
if('250' == receivebuf[15])
tmpxflx = "Z";

//查询CARD表，
}
}
//--------------------------------------------------------------------------- */

// ---------------------------------------------------------------------------
// 扫描在线POS机
/* PosTreeList->Items[0]->DeleteChildren();
WORD Status;
char temp[10] = "";
unsigned char como = 0x00;
WORD NO1 = 1;
unsigned char cmd = 0x43;
unsigned char receivebuf[16];
ZeroMemory(receivebuf, 16);
int receivelen = 16;
unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
int dirlen = strlen(dir);

if(getusbcomportdll)
{
strcpy(temp, getusbcomportdll());
String tt = temp;
//		ShowMessage(tt.SubString(4, tt.Length()-3));
if(tt.IsEmpty())
{
ShowMessage("没有POS设备接入！");
}
else
{
int tempcom = StrToInt(tt.SubString(4, tt.Length()-3).c_str());
if(tempcom>255)
{
ShowMessage("POS机连接的COM口不能大于255！");
}
else
{
IntToChar(tempcom, &como);
for(WORD PosNO = 1; PosNO<300; PosNO++)
{
Status = SerReceiveFunc(como, PosNO, cmd, receivebuf, receivelen, 1);
if(0 == Status)
{
ShowMessage("Add treenode successfully!");
TcxTreeListNode* tmpnode;
tmpnode = PosTreeList->Items[0]->AddChild();
tmpnode->ImageIndex = 1;
tmpnode->Texts[0] = "ON Line!";
OnlinePosNum++;
}
}
if(OnlinePosNum > 0)
{
PosTreeList->Items[0]->Expand(true);
RealCollectBTN->Enabled = true;
ScallPOSBTN->Enabled = false;
CollectdataThread = new TCollectDataThread(true, DataDisplayView, PosTreeList, OnlinePosNum);
}
}
}
}
else
{
ShowMessage("Error in Load FUNC!");
} */

/*	if(ScallPosThread)
	{
		if((ScallPosThread->Suspended) && (!ScallPosThread->Finished))
		{
			ScallPOSBTN->Enabled = true;
		}
	}


	if(CollectdataThread)
	{
		if(CollectdataThread->Suspended)
		{
			Panel7->Caption = "请继续进行“实时数据采集”程序！";
			RealCollectBTN->Enabled = true;
		}
	}  */

	// ---------------------------------------------------------------------------
/*
void __fastcall TRealTimeCollectFRM::PauseThreadBTNClick(TObject *Sender)
{
	if(CollectdataThread)
	{
		if((!CollectdataThread->Suspended)&&(!CollectdataThread->Finished))
		{
			CollectdataThread->Suspend();
			ScallProgressBar->Visible = false;
			CollectProgressBar->Visible = true;
			RealCollectBTN->Enabled = true;
			Panel7->Caption = "已暂停“实时采集数据”程序！";
		}
	}

	if(ScallPosThread)
	{
		if((!ScallPosThread->Suspended)&&(!ScallPosThread->Finished))
		{
			ScallPosThread->Suspend();
			ScallProgressBar->Visible = true;
			CollectProgressBar->Visible = false;
			Panel7->Caption = "已暂停“扫描在线POS机”程序！";
		}
	}
} */



