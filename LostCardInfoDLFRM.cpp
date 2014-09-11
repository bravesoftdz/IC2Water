//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LostCardInfoDLFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxListView"
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
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxRadioGroup"
#pragma link "cxProgressBar"
#pragma resource "*.dfm"

TLostCardInfoDownloadFRM *LostCardInfoDownloadFRM;
//---------------------------------------------------------------------------
__fastcall TLostCardInfoDownloadFRM::TLostCardInfoDownloadFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TLostCardInfoDownloadFRM::FormCreate(TObject *Sender)
{
	FOriginalcxListViewWindowProc = POSListView->InnerListView->WindowProc;
	POSListView->InnerListView->WindowProc = cxListViewWindowProcEx;
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::GABTNClick(TObject *Sender)
{
//挂失全部：判断是否为管理员！
	int tagint = 0;
    for(int i = 0; i < POSListView->Items->Count; i++)
    {
        TListItem* tmpitem = POSListView->Items->Item[i];
        if(tmpitem->Checked)
        {
        	tagint++;
        	break;
        }
    }

    if(!tagint)
    {
        ShowMessage("请选择要下载参数的POS机!");
        return;
	}

	if(!PostACLIThread)
	{
		PostACLIThread = new TPostAllCardLostInfoThread(true,
														GABTN,
														DGSBTN,
														ExitBTN,
														SCanProBar,
														POSListView,
														LIDLADOQ);
		if(PostACLIThread)
			PostACLIThread->Resume();
	}
	else
	{
		if(PostACLIThread->Finished)
		{
			PostACLIThread = new TPostAllCardLostInfoThread(true,
															GABTN,
															DGSBTN,
															ExitBTN,
															SCanProBar,
															POSListView,
															LIDLADOQ);
			if(PostACLIThread)
				PostACLIThread->Resume();
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::DGSBTNClick(TObject *Sender)
{
/*	if(!PostLIThread)
	{
		PostLIThread = new TPostLostInfoThread(true, DGSBTN, GABTN, ExitBTN, GSADOT, SCanProBar);
		if(PostLIThread)
			PostLIThread->Resume();
	}
	else
	{
		if(PostLIThread->Finished)
		{
			PostLIThread = new TPostLostInfoThread(true, DGSBTN, GABTN, ExitBTN, GSADOT, SCanProBar);
			if(PostLIThread)
				PostLIThread->Resume();
        }
	}*/
	LostInfoFRM->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::ExitBTNClick(TObject *Sender)
{
	if(SCanPosThread)
	{
		if(!SCanPosThread->Finished)
			SCanPosThread->Terminate();
	}

	if(PostACLIThread)
	{
		if(!PostACLIThread->Finished)
			PostACLIThread->Terminate();
	}

	if(PostLIThread)
	{
		if(!PostLIThread->Finished)
			PostLIThread->Terminate();
    }

	this->Close();
	PostLostInfotag = false;
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::FormShow(TObject *Sender)
{
	PostLostInfotag = true;
/*	if(!SCanPosThread)
	{
		SCanPosThread = new TDLSCanPosThread(true,
											 LIDLADOQ,
											 GABTN,
											 DGSBTN,
											 ExitBTN,
											 SCanProBar,
											 POSListView,
											 &existtag,
											 &scantag,
											 SELALLBTN,
											 CLSELALLBTN);
		if(SCanPosThread)
			SCanPosThread->Resume();
	}
	else
	{
		if(SCanPosThread->Finished)
		{
			SCanPosThread = new TDLSCanPosThread(true,
												 LIDLADOQ,
												 GABTN,
												 DGSBTN,
												 ExitBTN,
												 SCanProBar,
												 POSListView,
												 &existtag,
												 &scantag,
												 SELALLBTN,
												 CLSELALLBTN);
			if(SCanPosThread)
				SCanPosThread->Resume();
		}
	}   */
}
//---------------------------------------------------------------------------


void __fastcall TLostCardInfoDownloadFRM::cxListViewWindowProcEx(TMessage &message)
{
	if(CN_NOTIFY == message.Msg)
	{
		if(PNMHdr(message.LParam)->code == LVN_ITEMCHANGED)
		{
			if(PNMListView(message.LParam)->uChanged&&LVIF_STATE)
			{
				DWORD dw1 = PNMListView(message.LParam)->uOldState;//&&LVIS_STATEIMAGEMASK;
				DWORD dw2 = PNMListView(message.LParam)->uNewState;//&&LVIS_STATEIMAGEMASK;
				if((dw1!=dw2)&&(dw1 != 0))
                {
                    //ShowMessage("check click");
                    if(8192 == dw2)
                    	POSListView->Items[0].Item[PNMListView(message.LParam)->iItem]->Selected = true;
                    else if(4096 == dw2)
                        POSListView->Items[0].Item[PNMListView(message.LParam)->iItem]->Selected = false;
                }
            }
        }
    }
    FOriginalcxListViewWindowProc(message);
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::POSListViewSelectItem(TObject *Sender, TListItem *Item,
          bool Selected)
{
	if(!scantag)
	{
		TListItem* tmpitem = POSListView->Selected;
		if(tmpitem)
		{
			tmpitem->Checked = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::SELALLBTNClick(TObject *Sender)
{
    int allitem = POSListView->Items->Count;
    for(int i = 0; i < allitem; i++)
    {
    	POSListView->Items[0].Item[i]->Checked = true;
    }
    POSListView->SelectAll();
	POSListView->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TLostCardInfoDownloadFRM::CLSELALLBTNClick(TObject *Sender)
{
	int allitem = POSListView->Items->Count;
    for(int i = 0; i < allitem; i++)
    {
    	POSListView->Items[0].Item[i]->Checked = false;
        POSListView->Items[0].Item[i]->Selected = false;
    }
    POSListView->SetFocus();
}
//---------------------------------------------------------------------------



void __fastcall TLostCardInfoDownloadFRM::cxButton1Click(TObject *Sender)
{
	if(!SCanPosThread)
	{
		SCanPosThread = new TDLSCanPosThread(true,
											 LIDLADOQ,
											 GABTN,
											 DGSBTN,
											 ExitBTN,
											 SCanProBar,
											 POSListView,
											 &existtag,
											 &scantag,
											 SELALLBTN,
											 CLSELALLBTN,
											 cxButton1);
		if(SCanPosThread)
			SCanPosThread->Resume();
	}
	else
	{
		if(SCanPosThread->Finished)
		{
			SCanPosThread = new TDLSCanPosThread(true,
												 LIDLADOQ,
												 GABTN,
												 DGSBTN,
												 ExitBTN,
												 SCanProBar,
												 POSListView,
												 &existtag,
												 &scantag,
												 SELALLBTN,
												 CLSELALLBTN,
												 cxButton1);
			if(SCanPosThread)
				SCanPosThread->Resume();
		}
	}
}
//---------------------------------------------------------------------------

