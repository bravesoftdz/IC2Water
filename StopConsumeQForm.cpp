//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopConsumeQForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStopConsumeQFrm *StopConsumeQFrm;
//---------------------------------------------------------------------------
__fastcall TStopConsumeQFrm::TStopConsumeQFrm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStopConsumeQFrm::Button1Click(TObject *Sender)
{
	if(0 == RadioGroup1->ItemIndex)
    {
    	//不消费查询
        TDate date = Now();
        date = IncMonth(date, -3);
        String checktimestr = DateToStr(date) + " 00:00:00";
        String sqlstr = "select * from CARD_F where SFYEDT<'";
        sqlstr += checktimestr;
		sqlstr += "' and ZT= '发卡' order by kh";
        CARDADOQ->Close();
        CARDADOQ->SQL->Clear();
        CARDADOQ->SQL->Add(sqlstr);
        CARDADOQ->Open();
        if(!CARDADOQ->IsEmpty())
        {
            if(CARDADOQ->RecordCount > 65500)
            {
                CARDADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65530条，无法正常显示与导出，请修改查询条件!");
                return;
            }
            CARDADOQ->Close();
            StopConsumeShowFRM->checktagstr = "三个月不消费";
            StopConsumeShowFRM->CZYStr = OperatorName;
            StopConsumeShowFRM->CARDADOQuery->Close();
            StopConsumeShowFRM->CARDADOQuery->SQL->Clear();
            StopConsumeShowFRM->CARDADOQuery->SQL->Add(sqlstr);
            StopConsumeShowFRM->ShowModal();
        }
        else
            ShowMessage("符合该查询条件的记录条数为0!");
    }
    else if(1 == RadioGroup1->ItemIndex)
    {
    	//不充值查询
        //select ck.kh,ck.bh,CARD_F.XM,max(sfrq) as lastrq from ck left join CARD_F on CARD_F.kh=ck.kh and CARD_F.ZT= '发卡' where ck.sfrq<'2014-03-12 00:00:00' group by ck.kh,ck.bh,CARD_F.XM order by ck.kh
        TDate date = Now();
        date = IncMonth(date, -3);
        String checktimestr = DateToStr(date) + " 00:00:00";
        String sqlstr = "select ck.kh as KH,ck.bh as BH,CARD_F.XM as XM,CARD_F.SF_YE as SF_YE,CARD_F.XB as XB,CARD_F.BM as BM,CARD_F.BZ as BZ,CARD_F.ZB as ZB,CARD_F.ZW as ZW,CARD_F.ZT as ZT,max(sfrq) as RQ ";
        sqlstr += "from ck join CARD_F on CARD_F.kh=ck.kh and CARD_F.ZT= '发卡' where ck.sfrq<'";
        sqlstr += checktimestr;
        sqlstr += "' group by ck.kh,ck.bh,CARD_F.XM,CARD_F.SF_YE,CARD_F.XB,CARD_F.BM,CARD_F.BZ,CARD_F.ZB,CARD_F.ZW,CARD_F.ZT order by ck.kh";

        CARDADOQ->Close();
        CARDADOQ->SQL->Clear();
        CARDADOQ->SQL->Add(sqlstr);
        CARDADOQ->Open();
        if(!CARDADOQ->IsEmpty())
        {
            if(CARDADOQ->RecordCount > 65500)
            {
                CARDADOQ->Close();
                ShowMessage("符合该查询条件的记录条数大于65530条，无法正常显示与导出，请修改查询条件!");
                return;
            }
            CARDADOQ->Close();
            StopConsumeShowFRM->checktagstr = "三个月不充值";
            StopConsumeShowFRM->CZYStr = OperatorName;
            StopConsumeShowFRM->CARDADOQuery->Close();
            StopConsumeShowFRM->CARDADOQuery->SQL->Clear();
            StopConsumeShowFRM->CARDADOQuery->SQL->Add(sqlstr);
            StopConsumeShowFRM->ShowModal();
        }
        else
            ShowMessage("符合该查询条件的记录条数为0!");
    }
    else
    {
        ShowMessage("错误选项!");
    }
}
//---------------------------------------------------------------------------
