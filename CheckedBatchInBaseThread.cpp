//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CheckedBatchInBaseThread.h"
#include "SDIMAIN.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TCheckBatchInBaseThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TCheckBatchInBaseThread::TCheckBatchInBaseThread(bool CreateSuspended,
														  TcxButton* InBTN,
														  TcxButton* BCBTN,
														  TcxButton* EBTN,
														  TcxProgressBar* ProgressBar,
														  TADOQuery* updateQuery,
														  TPanel *DPanel)
	: TThread(CreateSuspended)
{
	ValidInBTN = InBTN;
	ValidBCBTN = BCBTN;
	ValidEBTN = EBTN;
	ValidProgressBar = ProgressBar;
	UpdateDataBaseQuery = updateQuery;
	ValidPanel = DPanel;
}
//---------------------------------------------------------------------------
void __fastcall TCheckBatchInBaseThread::Execute()
{
	ValidInBTN->Enabled = false;
	ValidBCBTN->Enabled = false;
	ValidProgressBar->Properties->Marquee = false;
	ValidProgressBar->Position = 0;

	//In Base Code
	if(true == FileExists(GlobalPath+"\\BCStroeBatchDataFile.dat"))
	{
		String filepathstr = GlobalPath+"\\BCStroeBatchDataFile.dat";
    	HANDLE HFILE = CreateFile(filepathstr.t_str(),
								  GENERIC_READ,
								  0,
								  NULL,
								  OPEN_EXISTING,
								  FILE_ATTRIBUTE_NORMAL,
								  NULL);
		ValidEBTN->Enabled = false;
		int filesize = GetFileSize(HFILE, NULL);
		if(0 == filesize)
		{
			CloseHandle(HFILE);
			DeleteFileA(filepathstr.t_str());
			ValidProgressBar->Position = 100;
			MessageBox(SDIAppForm->Handle, "批量数据入库完毕，现在可以开始批量数据采集!", "OK", MB_OK|MB_ICONEXCLAMATION);
			ValidBCBTN->Enabled = true;
			ValidInBTN->Enabled = false;
			ValidEBTN->Enabled = true;
			ValidPanel->Caption = "批量数据入库完毕!";
			return;
		}
		else
		{
			String tmpfilepath = GlobalPath+"\\BCWaitForInsertToMX.dat";
			TmpSaveInsertRecordFile.open(tmpfilepath.t_str(), ios::app);

			String tmperrfilepath = GlobalPath+"\\BCWaitForInsertToErrMX.dat";
			TmpSaveInsertErrRecFile.open(tmperrfilepath.t_str(), ios::app);

			int LineInFile = filesize/2048;

			bool Readresult;
			DWORD nBytesRead;
			ZeroMemory(BufferFromFile, 2048);
			Readresult = ReadFile(HFILE, BufferFromFile, 2048, &nBytesRead, NULL);
			int i = 1;
			while(Readresult&&nBytesRead)
			{
				if(Readresult&&nBytesRead)
				{
					Synchronize(AnalyzeDataFunc);
					Synchronize(DisplayDataFunc);
				}
				ValidProgressBar->Position = i*100/LineInFile;
				ZeroMemory(BufferFromFile, 2048);
				Readresult = ReadFile(HFILE, BufferFromFile, 2048, &nBytesRead, NULL);
				i++;
			}
			TmpSaveInsertRecordFile.close();
			TmpSaveInsertErrRecFile.close();
			CloseHandle(HFILE);
		//	MessageBox(SDIAppForm->Handle, "Before InBase", "Notice!", MB_OK);
			UpdateDataBaseFunc();
			DeleteFileA(filepathstr.t_str());
		}
		ValidEBTN->Enabled = true;
	}
	else
	{
		MessageBox(SDIAppForm->Handle, "没有批量数据存储文件，请联系技术人员!", "Error", MB_OK|MB_ICONERROR);
		ValidBCBTN->Enabled = true;
		ValidEBTN->Enabled = true;
		return;
	}
	MessageBox(SDIAppForm->Handle, "批量数据入库完毕，现在可以开始批量数据采集!", "OK", MB_OK|MB_ICONEXCLAMATION);
    ValidPanel->Caption = "批量数据入库完毕!";
	ValidBCBTN->Enabled = true;
	ValidInBTN->Enabled = false;
	ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchInBaseThread::AnalyzeDataFunc()
{
	int recordNUM = (int)BufferFromFile[7]*256+(int)BufferFromFile[8];
	if((recordNUM<128)&&(recordNUM>0)&&(0x20 == BufferFromFile[0])&&(0x03 == BufferFromFile[1])
	  &&(DWPassword[0] == BufferFromFile[2])&&(DWPassword[1] == BufferFromFile[3])
	  &&(0x23 == BufferFromFile[4]))
	{
//		String tmpfilepath = GlobalPath+"\\WaitForInsertToMX.dat";
//		ofstream TmpSaveInsertRecordFile(tmpfilepath.t_str(), ios::app);

		OrignalDataStr = "";
		PosNumber = (int)BufferFromFile[12]*256+(int)BufferFromFile[5];

		int RecordIndexPos;
		int tmpKH;
		int tmpXFCS;
		double tmpYE;
		double tmpXFJE;
		String tmpDATESTR;
		String tmpXFLX;
		String tmpSQLSTR;

		unsigned char instr[4];
		unsigned char outstr[6];
		ZeroMemory(instr, 4);
		ZeroMemory(outstr, 6);

		for (int t = 0; t < 14; t++)
			OrignalDataStr = OrignalDataStr + (IntToHex((byte)BufferFromFile[t], 2));

		for (int i = 0; i < (int)BufferFromFile[8]; i++)
		{
			RecordIndexPos = 14 + i*16;
			for (int p = 0; p < 16; p++)
			{
				OrignalDataStr = OrignalDataStr + (IntToHex((byte)BufferFromFile[RecordIndexPos + p], 2));
			}

			tmpKH = (int)BufferFromFile[RecordIndexPos]*256*256 + (int)BufferFromFile[RecordIndexPos+1]*256 + (int)BufferFromFile[RecordIndexPos+2];
			tmpXFCS = (int)BufferFromFile[RecordIndexPos+3]*256+(int)BufferFromFile[RecordIndexPos+4];
			tmpYE = ((double)BufferFromFile[RecordIndexPos+5]*256*256+(double)BufferFromFile[RecordIndexPos+6]*256+(double)BufferFromFile[RecordIndexPos+7])/100;
			tmpXFJE = ((double)BufferFromFile[RecordIndexPos+8]*256*256+(double)BufferFromFile[RecordIndexPos+9]*256+(double)BufferFromFile[RecordIndexPos+10])/100;

			instr[0] = BufferFromFile[RecordIndexPos+11];
			instr[1] = BufferFromFile[RecordIndexPos+12];
			instr[2] = BufferFromFile[RecordIndexPos+13];
			instr[3] = BufferFromFile[RecordIndexPos+14];
			if(GetnormaldateFunc)
			{
				if(0 != GetnormaldateFunc(instr, outstr))
				{
					outstr[0] = '0';
					outstr[1] = '1';
					outstr[2] = '1';
					outstr[3] = '0';
					outstr[4] = '0';
					outstr[5] = '0';
				}
				tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
								  IntToHex((int)outstr[1], 2)+"-"+
								  IntToHex((int)outstr[2], 2)+" "+
								  IntToHex((int)outstr[3], 2)+":"+
								  IntToHex((int)outstr[4], 2)+":"+
								  IntToHex((int)outstr[5], 2);
			}
			else
			{
				outstr[0] = '0';
				outstr[1] = '1';
				outstr[2] = '1';
				outstr[3] = '0';
				outstr[4] = '0';
				outstr[5] = '0';
				tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
							 IntToHex((int)outstr[1], 2)+"-"+
							 IntToHex((int)outstr[2], 2)+" "+
							 IntToHex((int)outstr[3], 2)+":"+
							 IntToHex((int)outstr[4], 2)+":"+
						 	 IntToHex((int)outstr[5], 2);
			}

			if(0 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "X";
			else if(1 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "Y";
			else if(2 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "B";
			else if(3 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "A";
			else if(4 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "L";
			else if(5 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "M";
			else if(6 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "O";
			else if(7 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "P";
			else if(250 == BufferFromFile[RecordIndexPos+15])
				tmpXFLX = "Z";
            else if(65 == BufferFromFile[15]) //breakfast
                tmpXFLX = "S";
            else if(66 == BufferFromFile[15]) //lunch
                tmpXFLX = "D";
            else if(67 == BufferFromFile[15]) //supper
                tmpXFLX = "F";
            else if(68 == BufferFromFile[15]) //night
                tmpXFLX = "G";
			else tmpXFLX = "D";

			bool errortag = false;
			UpdateDataBaseQuery->Close();
			tmpSQLSTR = "select * from CARD where KH = '";
			tmpSQLSTR += tmpKH;
			tmpSQLSTR += "'";
			UpdateDataBaseQuery->SQL->Clear();
			UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
			UpdateDataBaseQuery->Open();
			if(!UpdateDataBaseQuery->IsEmpty())
			{
				SerialNum = UpdateDataBaseQuery->FieldByName("BH")->AsAnsiString.Trim();
				if(UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger < tmpXFCS)
				{
					UpdateDataBaseQuery->Edit();
					UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger = tmpXFCS;
					UpdateDataBaseQuery->FieldByName("SF_YE")->AsFloat = tmpYE;
					UpdateDataBaseQuery->Post();
				}
			}
			else
				errortag = true;
			UpdateDataBaseQuery->Close();

			tmpSQLSTR = "select * from CARD_F where KH = '";
			tmpSQLSTR += tmpKH;
			tmpSQLSTR += "'";
			UpdateDataBaseQuery->SQL->Clear();
			UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
			UpdateDataBaseQuery->Open();
			if(!UpdateDataBaseQuery->IsEmpty())
			{
				UpdateDataBaseQuery->Edit();
				UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger = tmpXFCS;
				UpdateDataBaseQuery->FieldByName("SF_YE")->AsFloat = tmpYE;
				UpdateDataBaseQuery->Post();
			}
			else
				errortag = true;
			UpdateDataBaseQuery->Close();

			String UpdateTime;
			SYSTEMTIME tmpsystime;
			GetLocalTime(&tmpsystime);
			UpdateTime = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

			if(!errortag)
			{
				TmpSaveInsertRecordFile<<SerialNum.t_str()<<","<<tmpKH<<","<<tmpYE<<","<<tmpXFJE<<",";
				TmpSaveInsertRecordFile<<tmpXFCS<<","<<tmpDATESTR.t_str()<<","<<PosNumber<<",0,";
				TmpSaveInsertRecordFile<<tmpXFLX.t_str()<<","<<OperatorName.t_str()<<","<<UpdateTime.t_str()<<endl;
			}
			else
			{
				TmpSaveInsertErrRecFile<<SerialNum.t_str()<<","<<tmpKH<<","<<tmpYE<<","<<tmpXFJE<<",";
				TmpSaveInsertErrRecFile<<tmpXFCS<<","<<tmpDATESTR.t_str()<<","<<PosNumber<<",0,";
				TmpSaveInsertErrRecFile<<tmpXFLX.t_str()<<","<<OperatorName.t_str()<<","<<UpdateTime.t_str()<<endl;
			}
		}
		SaveDataToFileFunc();
	//	MessageBox(SDIAppForm->Handle, OrignalDataStr.t_str(), "test", MB_OK);
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchInBaseThread::DisplayDataFunc()
{
//
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchInBaseThread::UpdateDataBaseFunc()
{
	String tmppath = GlobalPath + "\\BCWaitForInsertToMX.dat";
	String tmpSQLSTR = "bulk insert MX from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();

/*	tmpSQLSTR = "bulk insert MXBAK from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
//	tmpSQLSTR = "bulk insert MXBAK from 'WaitForInsertToMX.dat' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();  */

	DeleteFileA(tmppath);

	tmppath = GlobalPath + "\\BCWaitForInsertToErrMX.dat";
	tmpSQLSTR = "bulk insert MX_ERROR from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();
	return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckBatchInBaseThread::SaveDataToFileFunc()
{
	CDBatchDataSaveToFileStream<<PosNumber<<"号POS机数据："<<endl;
	CDBatchDataSaveToFileStream<<OrignalDataStr.t_str()<<endl;
}
//---------------------------------------------------------------------------
