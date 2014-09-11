//---------------------------------------------------------------------------


#pragma hdrstop

#include "GlobalParameter.h"

//---------------------------------------------------------------------------
RY_HANDLE doghandle = NULL;
HINSTANCE LoadHModule = NULL;
beepofread beepofreaddll = NULL;
readinfo readcardinfo = NULL;
readwaterinfo readwatercardinfo = NULL;
readserial readserialfun = NULL;
LaunchCard LaunchNewCard = NULL;
LaunchWaterCard LaunchWaterNewCard = NULL;
ClearCardInfo ClearCardInfoProc = NULL;
EncrptyCardMM EncrptyCardMMProc = NULL;
unsigned char readcomno[5] = "";

TADOTable *UpZETable = NULL;

bool timetag = false;
int times = 0;
bool checktime = false;
bool goontag = false;
bool usetag = false;
double SFK_ZE = 0;
double SK_ZE = 0;
char timebuf[17];
char randbuf[32];
char goonpw[12];
char relvpw[12];
char CCH[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char globalqx[50];


unsigned char PosInUseTag[300];
int ModeOFCollect = 0;
int ReportClick = 0;
bool PosContag = false;
bool PostLostInfotag = false;
bool enableGS = false;
bool fixrecordtag = false;
bool DOGChk = false;
bool ReaderChk = false;
bool WriteNameChk = false;

HINSTANCE LoadCOMHModule = NULL;
SerReceiveOFdll SerReceiveFunc = NULL;
SerSendOFdll SerSendFunc = NULL;
SendAckOFdll SendAckFunc = NULL;
GetnormaldateOFdll GetnormaldateFunc = NULL;
Ppacarddll pacarddllproc = NULL;
Ppacarddll pacarddllprocreader = NULL;

HINSTANCE LoadUSBHModule = NULL;
GETUSBCOMPORT getusbcomportdll = NULL;

ofstream DataSaveToFileStream;
ofstream DataWOSaveToFileStream;
ofstream BatchDataSaveToFileStream;
ofstream CDBatchDataSaveToFileStream;

ofstream CQKLogStream;
//ofstream CollectDataLogStream;

String ActiveTableName = "";

String DataBaseNameStr = "";

//初始化参数
String OperatorName;
String OperatorGroupName;
String GlobalPath;
String SYSTEMDISPLAYNAME;
String VersionStr;

//String DWPassword;
//String CARDPassword;
unsigned char DWPassword[2];
unsigned char CARDPassword[6];
char DECCARDPassword[12];
unsigned char SuperPasword[6];
char DECSuperPassword[12];
unsigned char CARDPasswordEdition;
unsigned char UsingSecNUM;
unsigned char DelaySecond;

int maxconsumption;
int maxconsumption1;
int maxconsumption2;
int maxconsumption3;
int maxconsumption4;

int GlobalFKYJ;
int GlobalTKYJ;

int* BTGArray;
int BTGArraylen;

char** BTGmonthArray;
int BTGmonthArraylen;

char** JBNameArray;
int JBNameArraylen;


//int CardNoPtr[5040];
//int BonusPtr[5040];
//int AllCardNum;

unsigned char BTSendStr1[8192];
unsigned char BTSendStr2[8192];
unsigned char BTSendStr3[8192];
unsigned char BTSendStr4[8192];
unsigned char BTSendStr5[8192];


bool CreateBTtag = false;
bool DownloadBTtag = false;

bool BatchLaunchCardtag = false;
bool BatchGStag = false;

SHELLEXECUTEINFO e1;
String DataBaseServerName;
String DataBaseName;
#pragma package(smart_init)


