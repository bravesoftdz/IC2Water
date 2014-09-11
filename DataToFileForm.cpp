//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataToFileForm.h"
#include "SDIMAIN.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
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
#pragma link "cxProgressBar"
#pragma resource "*.dfm"
TDataToFileFrm *DataToFileFrm;
//---------------------------------------------------------------------------
__fastcall TDataToFileFrm::TDataToFileFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataToFileFrm::cxButton1Click(TObject *Sender)
{
    ModeOFCollect = 0;
	this->Close();
    if(ReportClick)
        SDIAppForm->dxNavBar1Group8Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDataToFileFrm::Memo1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0x00;
}
//---------------------------------------------------------------------------
void __fastcall TDataToFileFrm::FormShow(TObject *Sender)
{
    String timestr = DateToStr(Now());
    SYSTEMTIME st;
    GetSystemTime(&st);
    timestr += "_";
    timestr += (st.wHour+8)%24;
    timestr += "#";
    timestr += st.wMinute;
    timestr += "#";
    timestr += st.wSecond;
	cxTextEdit1->Text = GlobalPath + "\\SingleCollectData\\" + timestr + ".dbt";
    cxButton1->Enabled = true;
    cxButton2->Enabled = true;
    cxButton3->Enabled = true;
    cxButton4->Enabled = true;
    cxButton5->Enabled = false;
    ModeOFCollect = 4;
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxButton2Click(TObject *Sender)
{
	const SELDIRHELP = 1000;
    String Dir = "C:\\";
    if (SelectDirectory(Dir, TSelectDirOpts() << sdAllowCreate << sdPerformCreate << sdPrompt,SELDIRHELP))
    {
    	String timestr = DateToStr(Now());
    	SYSTEMTIME st;
        GetSystemTime(&st);
        timestr += "_";
        timestr += (st.wHour+8)%24;
        timestr += "#";
        timestr += st.wMinute;
        timestr += "#";
        timestr += st.wSecond;
    	cxTextEdit1->Text = Dir+"\\"+timestr+".dbt";
    }
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxButton4Click(TObject *Sender)
{
	OpenDialog1->Execute();
    cxTextEdit4->Text = OpenDialog1->FileName;
    cxButton5->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxButton3Click(TObject *Sender)
{
	if(!cxTextEdit2->Text.IsEmpty()&&!cxTextEdit3->Text.IsEmpty())
    {
    	WORD Status;
        unsigned char como = 0x00;
        unsigned char cmd = 0x43;
        unsigned char receivebuf[16];
        ZeroMemory(receivebuf, 16);
        int receivelen = 16;
        unsigned char* dir = "E:\\RAD\\2010-9-26\\Recieve";
        int dirlen = strlen(dir);
        int PosNo = StrToInt(cxTextEdit2->Text);
        int PosCom = StrToInt(cxTextEdit3->Text);
        IntToChar(PosCom, &como);

        Status = SerReceiveFunc(como,
                                (WORD)PosNo,
                                cmd,
                                receivebuf,
                                receivelen,
                                1,
                                dir,
                                dirlen);
        if(0 == Status)
        {
        	//派生采集线程:CollectToFileThread
            if(!CollectToFileThread)
            {
            	CollectToFileThread = new TCollectToFileThread(true,
                											   PosNo,
                                                               PosCom,
                                                               cxButton1,
                                                               cxButton2,
                                                               cxButton3,
                                                               cxButton4,
                                                               cxButton5,
                                                               cxTextEdit1->Text,
                                                               CollectProgressBar);
                if(CollectToFileThread)
                	CollectToFileThread->Resume();
            }
            else
            {
                if(CollectToFileThread->Finished)
                {
                    CollectToFileThread = new TCollectToFileThread(true,
                                                                   PosNo,
                                                                   PosCom,
                                                                   cxButton1,
                                                                   cxButton2,
                                                                   cxButton3,
                                                                   cxButton4,
                                                                   cxButton5,
                                                                   cxTextEdit1->Text,
                                                                   CollectProgressBar);
                    if(CollectToFileThread)
                        CollectToFileThread->Resume();
                }
            }
        }
        else
        	ShowMessage("您所填写的POS机参数有问题!");
    }
    else
    	ShowMessage("必须完整的填写POS连接参数!");
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxButton5Click(TObject *Sender)
{
    if(FileExists(cxTextEdit4->Text.t_str()))
    {
		if(!FileInDataBaseThread)
        {
            FileInDataBaseThread = new TFileInDataBaseThread(true,
            												 cxButton2,
                                                             cxButton3,
                                                             cxButton4,
                                                             cxButton5,
                                                             cxButton1,
                                                             cxTextEdit4->Text,
                                                             cxProgressBar1,
                                                             ADOQuery1);
            if(FileInDataBaseThread)
            	FileInDataBaseThread->Resume();
        }
        else
        {
            if(FileInDataBaseThread->Finished)
            {
                FileInDataBaseThread = new TFileInDataBaseThread(true,
                                                                 cxButton2,
                                                                 cxButton3,
                                                                 cxButton4,
                                                                 cxButton5,
                                                                 cxButton1,
                                                                 cxTextEdit4->Text,
                                                                 cxProgressBar1,
                                                                 ADOQuery1);
                if(FileInDataBaseThread)
                    FileInDataBaseThread->Resume();
            }
        }
    }
    else
    	ShowMessage("您指定的数据文件不存在!");
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxTextEdit2KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxTextEdit3KeyPress(TObject *Sender, wchar_t &Key)
{
	if((Key<'0'||Key>'9') && Key!='\b')
	{
		Key=0;
		ShowMessage("请输入0到9之间的数字!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxTextEdit4KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TDataToFileFrm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
	Key = 0;
}
//---------------------------------------------------------------------------


