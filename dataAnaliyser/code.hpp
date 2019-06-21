#pragma once
#include "io.h"
#include "direct.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class IDataReader
{
public:
	virtual BYTE* ReadData(DWORD ptr, int nSize) = 0;
	virtual void ReleaseData(BYTE *) = 0;
	virtual bool LoadString(UINT id, char* buf, int nbufSize) = 0;
};


char * aBooklist	= "booklist";
char * aCalnames	= "calnames";
char * aLibcal		= "libcal";
char * aLibhead		= "libhead";
char * aLibcolor	= "libcolor";
char * aCollec		= "collec";
char * aCalstram_0	= "calstram";
char * aColcode		= "colcode";
char * aFactory_1	= "factory";
char * aHeadsbrt_0	= "headsbrt";
char * aLibcollec	= "libcollec";
char * aLibfact		= "libfact";

char g_dataPath[250];

#pragma pack(1)
struct gItem_0x27	//39
{
	DWORD dwId_0x0;
	DWORD dwId2_0x4;
	DWORD dwDataLen_0x08;
	BYTE byteType_0x0c;
	BYTE byteSubType_0x0d;
	DWORD dwUnkown_0x0e;
	DWORD dwFlag_0x12;
	DWORD dwBaseResId_0x16;
	DWORD dwIdx_0x1a;
	BYTE byteUnkown_0x1e;
	DWORD dwUnkown_0x1f;
	BYTE byteUnkown_0x23;
	WORD wUnkown_0x24;
	BYTE byteUnkown_0x26;
};

struct gItem_0xEC;
struct sItem_subNode
{
	DWORD dwUnkown_0x0;
	DWORD dwUnkown_0x4;
	gItem_0xEC * pItem_0x8;
	DWORD dwCnt_0x0c;
	DWORD dwUnkown_0x10;
};

struct gItem_0xEC	//236
{
	DWORD dwUnkown_0x0;
	char str_unkown_0x6a[0x30];
	char str_unkown_0x9b[0x30];
	int dwUnkonw_0xcc;
	int dwUnkonw_0xd0;
	int dwUnkonw_0xd4;
	int dwSubLen_0xdc;
	gItem_0x27 * dwItemx27_0xe0;
	int nNodeIdx_0xe4;
	sItem_subNode * pSubNode_0xe8;
};

struct gItem_Data;
struct gItem_subData
{
	DWORD dwUnkown_0x00;
	DWORD dwDataCnt_0x04;
	gItem_Data ** pDataPtr_0x08;
};

struct gItem_0x122	//290
{
	int				dwUnkown_0x0;
	char *			strName_0x04;
	short			itemSize_0x08;
	int				dwDataNodeCnt_0x0a;
	gItem_0x27 *	pData_0x0e;
	gItem_0xEC *	pData2_0x12;
	int		dwIdRes_0x16;
	int		dwUnkown_0x1a;
	int		dwIdx_0x1e;
	void*	funTrimEnd_0x22;
	int		dwUnkown_0x26;
	int		dwUnkownCnt_0x2a;
	int		dwUnkown_0x2e;
	int		dwUnkown_0x32;
	int		dwUnkown_0x36;
	int		dwUnkown_0x3a;
	int		dwUnkown_0x3e;
	int		dwUnkown_0x42;
	int		dwUnkown_0x46;
	int		dwUnkown_0x4a;

	int		dwUnkownCnt_0x8e;
	int		dwUnkown_0x92;
	int		dwUnkown_0x96;
	int		dwUnkown_0x9a;
	int		dwUnkown_0x9e;
	int		dwUnkown_0xa2;
	int		dwUnkown_0xa6;
};

struct gItem_0x258
{
	gItem_0x27 * pItem27_0x0;
	char sKey_0x4[64];
	char sValue_0x44[0x200];
	DWORD dwUnkown_0x244;
	DWORD dwUnkown_0x248;
	DWORD dwUnkown_0x24c;
};

struct gItem_Data
{
	int nFileIdx_0x0;
	int nNodeIdx_0x4;
	char sDir_0x8[0x1a];
	DWORD dwUnkown_0x23;
	BYTE byteData_0x64[0x20];
	DWORD dwUnkown_0x88;
	DWORD dwUnkown_0x98;
	gItem_Data * pNextData_0x9c;
	DWORD dwUnkown_0xa0[0x30];
	gItem_Data * dwUnkown_0xd0[0x30];	
	gItem_subData subData_0x100[0x30];
	BYTE * pNodeData_0x190;
};


struct gItem_0x2C
{
	DWORD hwnd_parent_0;
	DWORD hwnd_0x4;
	DWORD hListWnd_0xc;
	DWORD hFont_0x18;
	gItem_Data * dwData_0x1c;
	WORD wType_0x20;
	DWORD dwUnkown_0x28;	
};

struct gItem_FileHeader_0xCE
{
	DWORD dwSubNodeSize_0x0;	
	DWORD dwKeyTypePtr_0x4;		
	DWORD dwUnkown_0x8;   
	DWORD dwNodeSize_0xC; 
	FILE * fHandle_0x10;
	WORD  wFileOpenFlag_0x14; 	  
	DWORD dwNodeCnt_0x16;
	DWORD dwUnkown_0x1A;
	DWORD dwUnkown_0x1E;
	DWORD dwUnkown_0x22;
	WORD  wIdxMax_0x26;
	DWORD dataArr_0x28[0x0a];	
	BYTE  data_0x50[0x31];	

	WORD  wUnkown_0x86;
	DWORD dwUnkown_0x88;
	char sFile_0x8C[0x42];
};

struct gItem_0x20
{
	DWORD dwUnknow_0x08;
	gItem_0xEC * pItem_0x0c;		
	DWORD dwDataCnt_0x10;
	gItem_Data ** pDataPtr_0x1c;
};

struct gItem_0x20A_4F2D10
{
	DWORD dwUnkown_0x0;
	DWORD dwUnkown_0x04;
	DWORD dwUnkown_0x08;
	DWORD dwUnkown_0x0c;
	char  byteRecordData_0x10[0xc28];//3112
};

struct sItem_t1
{
	int			nCnt_0x0;
	gItem_0xEC * pItem_0x4;
	DWORD		dwUnkown_0x8;
	DWORD		dwUnkown_0xc;

	DWORD		dwUnkown_0x10;
	BYTE *		pData_0x14;
	DWORD		dwUnkown_0x18;
	DWORD		dwUnkown_0x1c;
	
	DWORD		dwUnkown_0x20;
	DWORD		dwUnkown_0x24;
	DWORD		dwUnkown_0x28;
	DWORD		dwUnkown_0x2c;
};

struct gItemSubFileNode
{
	WORD wPos;
	WORD wSize;
};

struct gDBFile_0xE6
{
	byte bIsUseSubFile_4FE1F8;
	char fileName_4FE1FA[0x36];
	DWORD dwSubFileOpenIdx_4FE23C[14];	//子文件打开序号列表
	DWORD dwOpenFileIdx_4FE274;		//文件打开序号
	DWORD subFileIdx_4FE278;
	WORD subFileCnt_4FE27C;				//子文件个数
	gItemSubFileNode subFileNode[14];	
	WORD  word_4FE2B6;
	DWORD basePtr_dataPtr_4FE2B8;
	DWORD dwNodeIdx_4FE2BC;
};

struct gItemFileOpenInfo
{
	DWORD nFileIdx_4FD8A8;
	DWORD nFileOpenCnt;
};

struct sParam2
{
	char * strval_0x0;
	DWORD dwKnown_0x04;
	DWORD dwKnown_0x08;
};

struct sParam1
{
	__int16 wCnt_0x0;
	int nUnkown_0x02;
	sParam2 sP2Data_0x6[14];
};


struct sParam3_0xA3 {
	DWORD dwUnkown_0x0;
	DWORD dwUnkown_0x4;
	char ch_0x8;
	char sbuf_0x9[0x96];
	DWORD dwUnkown_0x9f;
};



sParam1 g_data_4EE0E8;

gDBFile_0xE6 g_ItemDBfile_0xE6[12];

gItem_0x122	g_ItemDatas_0x122[12];

gItem_FileHeader_0xCE g_ItemFileHeader_0xCE[0x100];

gItem_0x20A_4F2D10 g_fileData_0x30A_4F2D10[0x100];

IDataReader * g_dataReader = NULL;

gItemFileOpenInfo g_openInfo[22];

void * dword_4EE0E0 = 0;
DWORD dword_4F2C88 = 0;
DWORD dword_4DC040 = 0;
DWORD dword_4EE0EA = 0;
WORD word_4F2D0A = 0;
WORD word_4F3C42 = 0;
WORD word_4F2C8C = 0;
WORD word_4F3C7C = 0;

int dword_4FEF04 = 0;
DWORD dword_4E085F = 1;

__int64 dword_4E0240 = 0;

struct sIds{
	DWORD dwId1;
	DWORD dwId2;
};
sIds dword_4FD898[10];
DWORD	dword_4FD890;
DWORD	dword_4FD894;

DWORD dword_4FD3E8 = 0;
BYTE byte_4F2BA0[0x38];

BYTE unk_4F2B9D[0x100];

char byte_4F5A28[0x60];

struct sItem_0x10_4E0C60{
	WORD wUnkown_0x0;
	DWORD dwItemCnt_0x2;
	sParam3_0xA3 * pItem_0x6;
};
sItem_0x10_4E0C60 g_Item_4E0C60[50];

WORD word_4F2C92[0x3c];
DWORD dword_4F2C94[19];
bool bInitFlag = false;
BYTE subFileWordBuffer0x30[0x30];

BYTE tbuf[100];
sParam2 dword_4F2BD8;

int __cdecl sub_462B29(HWND hWndParent, char *a2, int a3, gItem_0xEC * a4, 
	int a5,		//1
	gItem_0x20 * a6,
	int a7,		//0
	int a8,		//0 
	int a9		//0
	);
BOOL __cdecl sub_4645D6(sItem_t1 *a1, BYTE* a2, void* a3, BYTE * a4, bool *a5, int a6, char* a7, int a8);
void __cdecl sub_45E51F(gItem_Data* a1);

void *InitGlobleBuffer()
{
	void *result; // eax

	if ( !bInitFlag )
	{
		memset(&g_ItemFileHeader_0xCE[0], 0, 0x50 * sizeof(gItem_FileHeader_0xCE));// 92*206
		result = memset(word_4F2C92, 0, 0x78u);
		bInitFlag = 1;
		//dword_4F2BD8 = (int)&unk_4F3C44;
	}
	return result;
}

void GetFileNameOnly(char * sFile, char * sFileName, int n)
{
	int nLen = strlen(sFile);
	for (int i = nLen - 1; i >=0; i--)
	{
		if (sFile[i] == '\\' || sFile[i] == '/')
		{
			strcpy(sFileName, &sFile[i+1]);
			break;
		}
	}	
}

signed int __cdecl getTypeDataCnt(int nType)      //获取类别对应的数据项个数
{
  signed int v2; // [esp+4h] [ebp-4h]

  v2 = 0;
  switch ( nType )
  {
    case 0:
      v2 = 73;
      break;
    case 1:
      v2 = 28;
      break;
    case 2:
      v2 = 26;
      break;
    case 3:
      v2 = 139;
      break;
    case 4:
      v2 = 26;
      break;
    case 5:
      v2 = 3;
      break;
    case 6:
      v2 = 8;
      break;
    case 7:
      v2 = 8;
      break;
    case 8:
      v2 = 8;
      break;
    case 9:
      v2 = 8;
      break;
    case 10:
      v2 = 8;
      break;
    case 11:
      v2 = 3;
      break;
    default:
      return v2;
  }
  return v2;
}


BOOL __cdecl getTypeDataByIdx(int nType, int nIdx, gItem_0x27 *& pIdRes)
{
	DWORD dwPtr = 0;
	switch ( nType )
	{
	case 0:
		dwPtr = 0x4E6DC8;
		break;
	case 1:
		dwPtr = 0x4E7FF0;
		break;
	case 2:
		dwPtr = 0x4E69D0;
		break;
	case 3:
		dwPtr = 0x4E8438;
		break;
	case 4:
		dwPtr = 0x4E9968;
		break;
	case 5:
		dwPtr = 0x4E78E8;
		break;
	case 6:
		dwPtr = 0x4E79D8;
		break;
	case 7:
		dwPtr = 0x4E7B10;
		break;
	case 8:
		dwPtr = 0x4E7C48;
		break;
	case 9:
		dwPtr = 0x4E7D80;
		break;
	case 10:
		dwPtr = 0x4E7EB8;
		break;
	case 11:
		dwPtr = 0x4E7960;
		break;
	}

	if (dwPtr > 0)
	{
		pIdRes = &((gItem_0x27 *)g_dataReader->ReadData(dwPtr, 39))[nIdx];
	}

	return pIdRes != 0;
}


// 感觉像个管理文件打开的池子，打开文件数上限为92个，返回在文件池里的idx
int __cdecl InitFile(char* lpPathName, int a2)
{
	int result; // eax

	int i = a2;

	char sHeader[0xa0];		
	memset(sHeader, 0, 0x9Eu);

	for ( i = 0; i < 92 && g_ItemFileHeader_0xCE[i].fHandle_0x10; ++i )
		;

	if (i == 92)
	{
		ASSERT(0);
		return -1;
	}

	FILE * fp = fopen(lpPathName, "rb");
	if (fp)
	{
		fread(sHeader, 1, 0x9e, fp);
		GetFileNameOnly(lpPathName, g_ItemFileHeader_0xCE[i].sFile_0x8C, 0x41);	//004F2BE8 from file
		g_ItemFileHeader_0xCE[i].dwKeyTypePtr_0x4 = *(WORD*)&sHeader[0x44];
		g_ItemFileHeader_0xCE[i].dwSubNodeSize_0x0 = *(WORD*)&sHeader[0x46];
		g_ItemFileHeader_0xCE[i].dwNodeSize_0xC = *(WORD*)&sHeader[0x4c];	
		g_ItemFileHeader_0xCE[i].dwNodeCnt_0x16 = *(DWORD*)&sHeader[0x56];
		g_ItemFileHeader_0xCE[i].wFileOpenFlag_0x14  = 0;	
		g_ItemFileHeader_0xCE[i].fHandle_0x10 = fp;		

		g_ItemFileHeader_0xCE[i].dwUnkown_0x1E = *(DWORD*)&sHeader[0x4F2C30 - 0x4F2BE8];
		g_ItemFileHeader_0xCE[i].dwUnkown_0x1A = *(DWORD*)&sHeader[0x4F2C3A - 0x4F2BE8];
		g_ItemFileHeader_0xCE[i].dwUnkown_0x22 = *(DWORD*)&sHeader[0x4F2C36 - 0x4F2BE8];
		g_ItemFileHeader_0xCE[i].wUnkown_0x86 = *(WORD*)&sHeader[0x4F2C80 - 0x4F2BE8];
		g_ItemFileHeader_0xCE[i].dwUnkown_0x88 = *(DWORD*)&sHeader[0x4F2C82 - 0x4F2BE8];
	}

	return i;
}

void InitAddr(void * ptr, DWORD dwAddr, int nSize)
{
	BYTE * pBuf = g_dataReader->ReadData(dwAddr, nSize);
	memcpy(ptr, pBuf, nSize);
}

int __cdecl sub_46BCEA(int nType, int ncnt1, gItem_0x27 * pBaseAddr)
{
	//memset(pBaseAddr, 0, ncnt1 * sizeof(gItem_0x27));
	InitAddr(pBaseAddr, pBaseAddr->dwId_0x0, ncnt1 * sizeof(gItem_0x27));

	int result; // eax
	int ncnt; // [esp+10h] [ebp-8h]
	gItem_0x27 *v9; // [esp+14h] [ebp-4h]
	DWORD * dwPtrV4 = 0;
	result = getTypeDataCnt(nType);
	ncnt = result;
	for (int i = 0; i < ncnt1; ++i )
	{
		for (int j = 0; j < ncnt; ++j )
		{
			if ( getTypeDataByIdx(nType, j, v9) && pBaseAddr[i].dwId_0x0 == v9->dwId2_0x4 )
			{
				dwPtrV4 = (DWORD*)v9;
				result = 0x27 * i;
				char *v5 = (char*)&pBaseAddr[i];
				memcpy(v5, v9, 0x24u);
				dwPtrV4 += 9;
				v5 += 0x24;
				*(WORD *)v5 = *(WORD *)dwPtrV4;
				v5[2] = *((BYTE *)dwPtrV4 + 2);
				break;


// 				result = 39 * i;
// 				memcpy(&pBaseAddr[i], v9, sizeof(gItem_0x27));
// 				break;
			}
			result = j + 1;
		}
	}
	return result;
}

signed int __cdecl sub_462933(int a1, int a2)
{
	for (int i = 0; i < g_ItemDatas_0x122[a1].dwDataNodeCnt_0x0a; ++i )
	{
		if (a2 == g_ItemDatas_0x122[a1].pData_0x0e[i].dwId_0x0)
		{
			return i;
		}
	}
	return -1;
}

int __cdecl sub_46B9D8(int a1, int a2)
{
	for (int i = 0; i < g_ItemDatas_0x122[a1].dwDataNodeCnt_0x0a; ++i )
	{
		if (a2 == g_ItemDatas_0x122[a1].pData_0x0e[i].byteUnkown_0x1e)
		{
			return i;
		}			
	}
	return 0;
}

signed int __cdecl TrimEnd(char *a1)
{
	signed int result; // eax
	signed int i; // [esp+0h] [ebp-4h]
	int v3; // [esp+0h] [ebp-4h]

	result = strlen(a1);
	for ( i = result; i > 0 && *a1 == 32; --i )
	{
		memcpy(a1, a1 + 1, i + 1);
		result = i - 1;
	}
	v3 = i - 1;
	if ( v3 > 0 )
	{
		while ( 1 )
		{
			result = (unsigned __int8)a1[v3];
			if ( result != 32 )
				break;
			a1[v3--] = 0;
		}
	}
	return result;
}

int GetUnitsFromReg()
{
	return 2;
}

gItem_0x27 * __cdecl sub_45C4F0(gItem_0xEC * a1)
{
	gItem_0x27 * v3 = 0; // [esp+0h] [ebp-4h]

	if ( !a1 || !a1->dwItemx27_0xe0 )
		return 0;

	if (a1->dwItemx27_0xe0->byteType_0x0c != 9)
		return a1->dwItemx27_0xe0;

	getTypeDataByIdx(a1->dwItemx27_0xe0->byteUnkown_0x1e, a1->dwItemx27_0xe0->dwIdx_0x1a, v3);

	return v3;
}

gItem_0x27 * __cdecl sub_46BC83(gItem_0xEC * a1, gItem_0x27 * a2)
{
	gItem_0x27 * result = 0; // eax

	if (a2->byteType_0x0c == 2)
	{
		strcpy((char *)(a1 + 8), "0");
	}

	if ( a2->dwFlag_0x12 & 0x20000 )
	{
		a1->dwUnkonw_0xd0 = 1;
	}

	result = a2;

	if ( a2->dwFlag_0x12 & 0x20 )
	{
		result = (gItem_0x27 *)(a1->dwUnkonw_0xd0 + 0x578);	//1400
		a1->dwUnkonw_0xd0 = (DWORD)result;
	}
	return result;
}

void sub_46BA36()
{

	signed int v0; // eax
	gItem_0x27 * v1 = 0; // eax
	CHAR v2[0x100]; // [esp+4h] [ebp-210h]
//	CHAR OutputString; // [esp+104h] [ebp-110h]
	gItem_0x27 *v4 = 0;
	int i; // [esp+208h] [ebp-Ch]
	int j; // [esp+20Ch] [ebp-8h]
	int v7; // [esp+210h] [ebp-4h]

	for ( i = 0; i < 12; ++i )
	{
		v7 = getTypeDataCnt(i);
		getTypeDataByIdx(i, 0, v4);
		for ( j = 0; j < v7; ++j )
		{
			memset(&g_ItemDatas_0x122[i].pData2_0x12[j], 0, sizeof(gItem_0xEC));

			g_ItemDatas_0x122[i].pData2_0x12[j].dwUnkonw_0xcc = (DWORD)GetUnitsFromReg();	//注册表信息：HKEY_LOCAL_MACHINE/Preferences---Units，类型DWORD
			
			g_ItemDatas_0x122[i].pData2_0x12[j].dwItemx27_0xe0 = &v4[j];
	
			g_ItemDatas_0x122[i].pData2_0x12[j].nNodeIdx_0xe4 = sub_462933(i, v4[j].dwId_0x0);

			if ( g_ItemDatas_0x122[i].pData2_0x12[j].nNodeIdx_0xe4 != -1 )
			{
				if ( memcmp( &g_ItemDatas_0x122[i].pData_0x0e[g_ItemDatas_0x122[i].pData2_0x12[j].nNodeIdx_0xe4], (const void *)&v4[j],0x27u) != 0)
				{
					ASSERT(0);
// 					wsprintfA(&OutputString, "Oops key for %d\n" , i);
// 					OutputDebugStringA(&OutputString);
// 					wsprintfA(&v2, "key %d\n", j);
// 					OutputDebugStringA(&v2);
				}
			}
			v1 = sub_45C4F0(&g_ItemDatas_0x122[i].pData2_0x12[j]);
			sub_46BC83(&g_ItemDatas_0x122[i].pData2_0x12[j], v1);
		}
	}
}

signed int InitGlobleMem_46A695()
{
  signed int v1; // [esp+0h] [ebp-8h]
     
  gItem_0x27 * unk_4E06F0 = new gItem_0x27[5];
  gItem_0x27 * unk_4E04C8 = new gItem_0x27[14];
  gItem_0x27 * unk_4E0250 = new gItem_0x27[10];
  gItem_0x27 * unk_4E0AD8 = new gItem_0x27[10];
  gItem_0x27 * unk_4E03D8 = new gItem_0x27[6];
  gItem_0x27 * unk_4E07B8 = new gItem_0x27[3];
  gItem_0x27 * unk_4E0880 = new gItem_0x27[3];
  gItem_0x27 * unk_4E08F8 = new gItem_0x27[3];
  gItem_0x27 * unk_4E0970 = new gItem_0x27[3];
  gItem_0x27 * unk_4E09E8 = new gItem_0x27[3];
  gItem_0x27 * unk_4E0A60 = new gItem_0x27[3];
  gItem_0x27 * unk_4E0830 = new gItem_0x27[2];

	unk_4E06F0->dwId_0x0 = 0x4e06f0;
	unk_4E04C8->dwId_0x0 = 0x4E04C8;
	unk_4E0250->dwId_0x0 = 0x4E0250;
	unk_4E0AD8->dwId_0x0 = 0x4E0AD8;
	unk_4E03D8->dwId_0x0 = 0x4E03D8;
	unk_4E07B8->dwId_0x0 = 0x4E07B8;
	unk_4E0880->dwId_0x0 = 0x4E0880;
	unk_4E08F8->dwId_0x0 = 0x4E08F8;
	unk_4E0970->dwId_0x0 = 0x4E0970;
	unk_4E09E8->dwId_0x0 = 0x4E09E8;
	unk_4E0A60->dwId_0x0 = 0x4E0A60;
	unk_4E0830->dwId_0x0 = 0x4E0830;

  v1 = 1;
  sub_46BCEA(0, 5,  unk_4E06F0);
  sub_46BCEA(1, 14, unk_4E04C8);
  sub_46BCEA(2, 10, unk_4E0250);
  sub_46BCEA(3, 10, unk_4E0AD8);
  sub_46BCEA(4, 6, unk_4E03D8);
  sub_46BCEA(5, 3, unk_4E07B8);
  sub_46BCEA(6, 3, unk_4E0880);
  sub_46BCEA(7, 3, unk_4E08F8);
  sub_46BCEA(8, 3, unk_4E0970);
  sub_46BCEA(9, 3, unk_4E09E8);
  sub_46BCEA(10, 3, unk_4E0A60);
  sub_46BCEA(11, 2, unk_4E0830);



  gItem_0xEC * unk_50AF20 = new gItem_0xEC[getTypeDataCnt(0)];	//0xec
  gItem_0xEC * unk_506E98 = new gItem_0xEC[getTypeDataCnt(1)];
  gItem_0xEC * unk_508FC8 = new gItem_0xEC[getTypeDataCnt(2)];
  gItem_0xEC * unk_50F270 = new gItem_0xEC[getTypeDataCnt(3)];
  gItem_0xEC * unk_517298 = new gItem_0xEC[getTypeDataCnt(4)];
  gItem_0xEC * unk_519958 = new gItem_0xEC[getTypeDataCnt(5)];
  gItem_0xEC * unk_5191F0 = new gItem_0xEC[getTypeDataCnt(6)];
  gItem_0xEC * unk_506470 = new gItem_0xEC[getTypeDataCnt(7)];
  gItem_0xEC * unk_50A7C0 = new gItem_0xEC[getTypeDataCnt(8)];
  gItem_0xEC * unk_518A90 = new gItem_0xEC[getTypeDataCnt(9)];
  gItem_0xEC * unk_508868 = new gItem_0xEC[getTypeDataCnt(10)];
  gItem_0xEC * unk_506BD0 = new gItem_0xEC[getTypeDataCnt(11)];

    {
		g_ItemDatas_0x122[11].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[11].strName_0x04 = aBooklist;
		g_ItemDatas_0x122[11].itemSize_0x08 = 163;
		g_ItemDatas_0x122[11].dwDataNodeCnt_0x0a	= 2;
		g_ItemDatas_0x122[11].pData_0x0e	= unk_4E0830;
		g_ItemDatas_0x122[11].pData2_0x12	= unk_506BD0;
		g_ItemDatas_0x122[11].dwIdRes_0x16	= 2131;
		g_ItemDatas_0x122[11].dwUnkown_0x1a	= 9;
		g_ItemDatas_0x122[11].dwIdx_0x1e		= 11;
		g_ItemDatas_0x122[11].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[11].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[11].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[11].dwUnkownCnt_0x8e= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[11].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[5].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[5].strName_0x04 = aCalnames;
		g_ItemDatas_0x122[5].itemSize_0x08 = 71;
		g_ItemDatas_0x122[5].dwDataNodeCnt_0x0a	= 3;
		g_ItemDatas_0x122[5].pData_0x0e	= unk_4E07B8;
		g_ItemDatas_0x122[5].pData2_0x12	= unk_519958;
		g_ItemDatas_0x122[5].dwIdRes_0x16	= 2101;
		g_ItemDatas_0x122[5].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[5].dwIdx_0x1e	= 5;
		g_ItemDatas_0x122[5].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[5].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[5].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[5].dwUnkownCnt_0x8e	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[5].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[6].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[6].strName_0x04 = aLibcal;
		g_ItemDatas_0x122[6].itemSize_0x08 = 137;
		g_ItemDatas_0x122[6].dwDataNodeCnt_0x0a	= 3;
		g_ItemDatas_0x122[6].pData_0x0e	= unk_4E0880;
		g_ItemDatas_0x122[6].pData2_0x12	= unk_5191F0;
		g_ItemDatas_0x122[6].dwIdRes_0x16	= 2127;
		g_ItemDatas_0x122[6].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[6].dwIdx_0x1e	= 6;
		g_ItemDatas_0x122[6].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[6].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[6].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[6].dwUnkownCnt_0x8e	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[6].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[7].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[7].strName_0x04 = aLibhead;
		g_ItemDatas_0x122[7].itemSize_0x08 = 137;
		g_ItemDatas_0x122[7].dwDataNodeCnt_0x0a	= 3;
		g_ItemDatas_0x122[7].pData_0x0e	= unk_4E08F8;
		g_ItemDatas_0x122[7].pData2_0x12	= unk_506470;
		g_ItemDatas_0x122[7].dwIdRes_0x16	= 2128;
		g_ItemDatas_0x122[7].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[7].dwIdx_0x1e		= 7;
		g_ItemDatas_0x122[7].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[7].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[7].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[7].dwUnkownCnt_0x8e	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[7].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[8].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[8].strName_0x04 = aLibcolor;
		g_ItemDatas_0x122[8].itemSize_0x08 = 137;
		g_ItemDatas_0x122[8].dwDataNodeCnt_0x0a	= 3;
		g_ItemDatas_0x122[8].pData_0x0e	= unk_4E0970;
		g_ItemDatas_0x122[8].pData2_0x12	= unk_50A7C0;
		g_ItemDatas_0x122[8].dwIdRes_0x16	= 2129;
		g_ItemDatas_0x122[8].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[8].dwIdx_0x1e		= 8;
		g_ItemDatas_0x122[8].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[8].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[8].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[8].dwUnkownCnt_0x8e	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[8].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[9].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[9].strName_0x04 = aLibcollec;
		g_ItemDatas_0x122[9].itemSize_0x08 = 137;
		g_ItemDatas_0x122[9].dwDataNodeCnt_0x0a	= 3;
		g_ItemDatas_0x122[9].pData_0x0e	= unk_4E09E8;
		g_ItemDatas_0x122[9].pData2_0x12	= unk_518A90;
		g_ItemDatas_0x122[9].dwIdRes_0x16	= 2130;
		g_ItemDatas_0x122[9].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[9].dwIdx_0x1e		= 9;
		g_ItemDatas_0x122[9].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[9].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[9].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[9].dwUnkownCnt_0x8e	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[9].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[10].dwUnkown_0x0 = 0;
		g_ItemDatas_0x122[10].strName_0x04 = aLibfact;
		g_ItemDatas_0x122[10].itemSize_0x08 = 137;
		g_ItemDatas_0x122[10].dwDataNodeCnt_0x0a	= 3;
		g_ItemDatas_0x122[10].pData_0x0e	= unk_4E0A60;
		g_ItemDatas_0x122[10].pData2_0x12	= unk_508868;
		g_ItemDatas_0x122[10].dwIdRes_0x16	= 2140;
		g_ItemDatas_0x122[10].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[10].dwIdx_0x1e		= 10;
		g_ItemDatas_0x122[10].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[10].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[10].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[10].dwUnkownCnt_0x8e	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x92	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x96	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x9a	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[10].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[4].dwUnkown_0x0 = 2004;
		g_ItemDatas_0x122[4].strName_0x04 = aFactory_1;
		g_ItemDatas_0x122[4].itemSize_0x08 = 2460;
		g_ItemDatas_0x122[4].dwDataNodeCnt_0x0a	= 6;
		g_ItemDatas_0x122[4].pData_0x0e	= unk_4E03D8;
		g_ItemDatas_0x122[4].pData2_0x12	= unk_517298;
		g_ItemDatas_0x122[4].dwIdRes_0x16	= 2139;
		g_ItemDatas_0x122[4].dwUnkown_0x1a	= 8;
		g_ItemDatas_0x122[4].dwIdx_0x1e	= 4;
		g_ItemDatas_0x122[4].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[4].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[4].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[4].dwUnkownCnt_0x8e	= 1;
		g_ItemDatas_0x122[4].dwUnkown_0x92	= 10;
		g_ItemDatas_0x122[4].dwUnkown_0x96	= sub_462933(4, 100);
		g_ItemDatas_0x122[4].dwUnkown_0x9a	= sub_462933(10, 344);
		g_ItemDatas_0x122[4].dwUnkown_0x9e	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0xa2	= 0;
		g_ItemDatas_0x122[4].dwUnkown_0xa6	= 0;

		g_ItemDatas_0x122[0].dwUnkown_0x0 = 2000;
		g_ItemDatas_0x122[0].strName_0x04 = aCalstram_0;
		g_ItemDatas_0x122[0].itemSize_0x08 = 2682;
		g_ItemDatas_0x122[0].dwDataNodeCnt_0x0a	= 5;
		g_ItemDatas_0x122[0].pData_0x0e	= unk_4E06F0;
		g_ItemDatas_0x122[0].pData2_0x12	= unk_50AF20;
		g_ItemDatas_0x122[0].dwIdRes_0x16	= 2015;
		g_ItemDatas_0x122[0].dwUnkown_0x1a	= 8;
		g_ItemDatas_0x122[0].dwIdx_0x1e	= 0;
		g_ItemDatas_0x122[0].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[0].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[0].dwUnkownCnt_0x2a	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x32	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[0].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[0].dwUnkownCnt_0x8e= 2;
		g_ItemDatas_0x122[0].dwUnkown_0x92	= 5;
		g_ItemDatas_0x122[0].dwUnkown_0x96	= sub_462933(0, 100);
		g_ItemDatas_0x122[0].dwUnkown_0x9a	= sub_462933(5, 311);
		g_ItemDatas_0x122[0].dwUnkown_0x9e  = 6;
		g_ItemDatas_0x122[0].dwUnkown_0xa2  = sub_462933(0, 100);
		g_ItemDatas_0x122[0].dwUnkown_0xa6  = sub_462933(6, 340);


		g_ItemDatas_0x122[1].dwUnkown_0x0 = 2002;
		g_ItemDatas_0x122[1].strName_0x04 = aHeadsbrt_0;
		g_ItemDatas_0x122[1].itemSize_0x08 = 1675;
		g_ItemDatas_0x122[1].dwDataNodeCnt_0x0a	= 14;
		g_ItemDatas_0x122[1].pData_0x0e	= unk_4E04C8;
		g_ItemDatas_0x122[1].pData2_0x12	= unk_506E98;
		g_ItemDatas_0x122[1].dwIdRes_0x16	= 2013;
		g_ItemDatas_0x122[1].dwUnkown_0x1a	= 18;
		g_ItemDatas_0x122[1].dwIdx_0x1e	= 1;
		g_ItemDatas_0x122[1].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[1].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[1].dwUnkownCnt_0x2a= 1;
		g_ItemDatas_0x122[1].dwUnkown_0x2e	= 4;
		g_ItemDatas_0x122[1].dwUnkown_0x32	= sub_46B9D8(1, 4);
		g_ItemDatas_0x122[1].dwUnkown_0x36	= 0;
		g_ItemDatas_0x122[1].dwUnkown_0x3a	= 0;
		g_ItemDatas_0x122[1].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[1].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[1].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[1].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[1].dwUnkownCnt_0x8e	= 1;
		g_ItemDatas_0x122[1].dwUnkown_0x92	= 7;
		g_ItemDatas_0x122[1].dwUnkown_0x96	= sub_462933(1, 100);
		g_ItemDatas_0x122[1].dwUnkown_0x9a	= sub_462933(7, 341);
		g_ItemDatas_0x122[1].dwUnkown_0x9e  = 0;
		g_ItemDatas_0x122[1].dwUnkown_0xa2  = 0;
		g_ItemDatas_0x122[1].dwUnkown_0xa6  = 0;


		g_ItemDatas_0x122[2].dwUnkown_0x0 = 2003;
		g_ItemDatas_0x122[2].strName_0x04 = aColcode;
		g_ItemDatas_0x122[2].itemSize_0x08 = 1356;
		g_ItemDatas_0x122[2].dwDataNodeCnt_0x0a	= 10;
		g_ItemDatas_0x122[2].pData_0x0e	= unk_4E0250;
		g_ItemDatas_0x122[2].pData2_0x12	= unk_508FC8;
		g_ItemDatas_0x122[2].dwIdRes_0x16	= 2014;
		g_ItemDatas_0x122[2].dwUnkown_0x1a	= 16;
		g_ItemDatas_0x122[2].dwIdx_0x1e	= 2;
		g_ItemDatas_0x122[2].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[2].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[2].dwUnkownCnt_0x2a	= 2;
		g_ItemDatas_0x122[2].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[2].dwUnkown_0x32	= sub_46B9D8(2, 0);
		g_ItemDatas_0x122[2].dwUnkown_0x36	= 1;
		g_ItemDatas_0x122[2].dwUnkown_0x3a	= -1;
		g_ItemDatas_0x122[2].dwUnkown_0x3e	= 0;
		g_ItemDatas_0x122[2].dwUnkown_0x42	= 0;
		g_ItemDatas_0x122[2].dwUnkown_0x46	= 0;
		g_ItemDatas_0x122[2].dwUnkown_0x4a	= 0;
		g_ItemDatas_0x122[2].dwUnkownCnt_0x8e	= 1;
		g_ItemDatas_0x122[2].dwUnkown_0x92	= 8;
		g_ItemDatas_0x122[2].dwUnkown_0x96	= sub_462933(2, 100);
		g_ItemDatas_0x122[2].dwUnkown_0x9a	= sub_462933(8, 342);
		g_ItemDatas_0x122[2].dwUnkown_0x9e  = 0;
		g_ItemDatas_0x122[2].dwUnkown_0xa2  = 0;
		g_ItemDatas_0x122[2].dwUnkown_0xa6  = 0;


		g_ItemDatas_0x122[3].dwUnkown_0x0 = 2001;
		g_ItemDatas_0x122[3].strName_0x04 = aCollec;
		g_ItemDatas_0x122[3].itemSize_0x08 = 5112;
		g_ItemDatas_0x122[3].dwDataNodeCnt_0x0a	= 10;
		g_ItemDatas_0x122[3].pData_0x0e	= unk_4E0AD8;
		g_ItemDatas_0x122[3].pData2_0x12	= unk_50F270;
		g_ItemDatas_0x122[3].dwIdRes_0x16	= 2012;
		g_ItemDatas_0x122[3].dwUnkown_0x1a	= 8;
		g_ItemDatas_0x122[3].dwIdx_0x1e	= 3;
		g_ItemDatas_0x122[3].funTrimEnd_0x22	= TrimEnd;
		g_ItemDatas_0x122[3].dwUnkown_0x26	= 0;
		g_ItemDatas_0x122[3].dwUnkownCnt_0x2a	= 4;
		g_ItemDatas_0x122[3].dwUnkown_0x2e	= 0;
		g_ItemDatas_0x122[3].dwUnkown_0x32	= sub_46B9D8(3, 0);
		g_ItemDatas_0x122[3].dwUnkown_0x36	= 1;
		g_ItemDatas_0x122[3].dwUnkown_0x3a	= sub_46B9D8(3, 1);
		g_ItemDatas_0x122[3].dwUnkown_0x3e	= 2;
		g_ItemDatas_0x122[3].dwUnkown_0x42	= sub_46B9D8(3, 2);
		g_ItemDatas_0x122[3].dwUnkown_0x46	= 4;
		g_ItemDatas_0x122[3].dwUnkown_0x4a	= sub_46B9D8(3, 4);
		g_ItemDatas_0x122[3].dwUnkownCnt_0x8e	= 1;
		g_ItemDatas_0x122[3].dwUnkown_0x92	= 9;
		g_ItemDatas_0x122[3].dwUnkown_0x96	= sub_462933(3, 100);
		g_ItemDatas_0x122[3].dwUnkown_0x9a	= sub_462933(9, 343);
		g_ItemDatas_0x122[3].dwUnkown_0x9e  = 0;
		g_ItemDatas_0x122[3].dwUnkown_0xa2  = 0;
		g_ItemDatas_0x122[3].dwUnkown_0xa6  = 0;
 
 }


  if ( v1 )
    sub_46BA36();


  return v1;
}






signed int __cdecl ReadIntValue(gItem_Data * a1)
{
	return a1->nFileIdx_0x0;
}

gItem_Data * __cdecl sub_4A6E38(gItem_0x2C * a1)
{
	return a1->dwData_0x1c;
}


struct st1{
	DWORD d1;
	DWORD d2;
};


BOOL __cdecl sub_4AE9EB(st1 *a1, gItem_0x27 *& a2)
{
	return getTypeDataByIdx(a1->d1, a1->d2, a2);
}

char *__cdecl loadKeyName(gItem_0x27 * pGetItem, int a3, LPSTR lpBuffer, int cchBufferMax, int a6)
{
	char *result; // eax
	char *v8; // [esp+4h] [ebp-148h]
	gItem_0x27 * pItemx27 = 0; // [esp+8h] [ebp-144h]
	char String2[100]; // [esp+Ch] [ebp-140h]
	char Buffer[64]; // [esp+10Ch] [ebp-40h]

	g_dataReader->LoadString(pGetItem->dwId_0x0, lpBuffer, cchBufferMax);

	if ( pGetItem->byteType_0x0c == 9 && a6 &&
		getTypeDataByIdx(pGetItem->byteUnkown_0x1e, pGetItem->dwIdx_0x1a, pItemx27))
	{
		loadKeyName(pItemx27, a3, Buffer, 64, a6);
		wsprintfA(String2, "%s", lpBuffer);
		lstrcpynA(lpBuffer, String2, cchBufferMax);
	}
	result = strchr(lpBuffer, ';');                // ;
	v8 = result;
	if ( result )
	{
		if ( a3 )
		{
			int v7 = strlen(result);
			result = (char *)memcpy(lpBuffer, v8 + 1, v7);
		}
		else
		{
			*result = 0;
		}
	}
	return result;
}

int __cdecl sub_45B163(int a1, LPSTR lpBuffer, int cchBufferMax)
{
	int uID; // [esp+0h] [ebp-4h]

	uID = dword_4FD898[a1].dwId1;
	if ( !uID )
		uID = 2901;

	return g_dataReader->LoadString(uID, lpBuffer, cchBufferMax);
}

BOOL __cdecl sub_45B2A5(unsigned __int8 a1, sItem_0x10_4E0C60 **a2);
int __cdecl sub_45B6BD(int a1, int a2, sParam3_0xA3 *a3)
{
	sItem_0x10_4E0C60 * v3; // ecx
	int result; // eax
	sItem_0x10_4E0C60 * v5; // [esp+0h] [ebp-4h]

	v5 = v3;
	if ( sub_45B2A5(a1, &v5) && (unsigned int)(unsigned __int16)a2 < v5->dwItemCnt_0x2 )
	{
		memcpy(a3, (const void *)&v5->pItem_0x6[a2], 0xA3);
		result = 1;
	}
	else
	{
		a3->dwUnkown_0x0 = dword_4FD890;
		a3->dwUnkown_0x4 = dword_4FD894;
		a3->ch_0x8 = 0;
		a3->dwUnkown_0x9f = 0;

		sub_45B163((unsigned __int8)a1, (LPSTR)a3->sbuf_0x9, 150);
		result = 0;
	}
	return result;
}

int __cdecl sub_45B761(char a1, int a2, LPSTR lpString1, int iMaxLength)
{
	sParam3_0xA3 sp3;

	if ( !sub_45B6BD(a1, (unsigned __int16)a2, &sp3) )
		return 0;
	if ( lpString1 )
		lstrcpynA(lpString1, sp3.sbuf_0x9, iMaxLength);
	return 1;
}

int __cdecl sub_45B19E(int a1, LPSTR lpBuffer, int cchBufferMax)
{
	int v3; // eax
	int v5; // [esp+0h] [ebp-8h]
	UINT uID; // [esp+4h] [ebp-4h]

	uID = dword_4FD898[a1].dwId1;
	if ( uID )
		v3 =  g_dataReader->LoadString(uID - 1, lpBuffer, cchBufferMax);
	else
		v3 =  g_dataReader->LoadString(0xB54, lpBuffer, cchBufferMax);
	v5 = v3;
	if ( !v3 )
		v5 =  g_dataReader->LoadString(0xB54, lpBuffer, cchBufferMax);
	return v5;
}

void * sub_45AF77(void *pthis, void *a2)
{
	return memcpy(a2, pthis, 8);
}

char *GetDirectoryNameFromReg()
{
	return g_dataPath;
}

signed int __cdecl sub_4650B5(sItem_t1 *a1)
{
	for (int i = 0; i < a1->nCnt_0x0; ++i )
	{
		if ( a1->pItem_0x4[i].nNodeIdx_0xe4 != -1 )
			return a1->pItem_0x4[i].nNodeIdx_0xe4;
	}
	return -1;
}


signed int __cdecl sub_45B003(DWORD *a1, DWORD *a2)
{
	signed int result; // eax

	if ( a1[1] == a2[1] )
	{
		if ( *a1 == *a2 )
		{
			result = 0;
		}
		else if ( *a1 <= *a2 )
		{
			result = -1;
		}
		else
		{
			result = 1;
		}
	}
	else if ( a1[1] <= a2[1] )
	{
		result = -1;
	}
	else
	{
		result = 1;
	}
	return result;
}

void * sub_46BD90(void *pthis, void *a2)
{
	ASSERT(sizeof(sParam3_0xA3) == 0xa3);
	memcpy(pthis, a2, 0xA3u);
	return pthis;
}

BOOL __cdecl sub_45AFE8(int a1)
{
	//ASSERT(0);
	return sub_45B003((DWORD*)&dword_4E0240, (DWORD *)a1) == 0;
}


int __cdecl sub_45E736(int a1, gItem_0xEC * a2);
void __cdecl sub_45E42B(gItem_subData* a1);

void __cdecl sub_45E51F(gItem_Data* a1)
{
	int v1; // [esp+0h] [ebp-Ch]
	gItem_Data* v2; // [esp+4h] [ebp-8h]
	signed int i; // [esp+8h] [ebp-4h]

	v1 = 0;
	if ( a1 )
	{
		v2 = a1;
		if ( v2 )
		{
			v1 = v2->dwUnkown_0x98;
			if ( v1 )
			{
				--v2->dwUnkown_0x98;
			}
			else
			{
				for ( i = 0; i < 12; ++i )
					sub_45E51F(v2->dwUnkown_0xd0[i]);
				sub_45E42B(v2->subData_0x100);
			}
		}
	}
}

void __cdecl sub_45E42B(gItem_subData* a1)
{
	int j; // [esp+0h] [ebp-Ch]
	gItem_Data ** v2; // [esp+4h] [ebp-8h]

	for (int i = 0; i < 12; ++i )
	{
		if ( a1[i].pDataPtr_0x08)
		{
			v2 = a1[i].pDataPtr_0x08;
			if ( v2 )
			{
				for ( j = 0; j < a1[i].dwDataCnt_0x04; ++j )
					sub_45E51F(v2[j]);
				a1[i].pDataPtr_0x08 = 0;
			}
		}
		a1[i].dwDataCnt_0x04 = 0;
		a1[i].dwUnkown_0x00 = 0;
	}
}

void __cdecl sub_45E6EB(int a1, gItem_0xEC * a2)
{
	sub_45E736(a1, a2);
}

sItem_subNode * __cdecl sub_45E687(sItem_subNode *a1)
{
	sItem_subNode * result = a1; // eax

	if ( a1->pItem_0x8 )
	{
		sub_45E6EB(a1->dwUnkown_0x4, a1->pItem_0x8);
		a1->dwUnkown_0x4 = 0;
		result = a1;
		a1->pItem_0x8 = 0;
	}
	if ( a1->dwUnkown_0x10 )
	{
		delete (void*)a1->dwUnkown_0x10;
		a1->dwUnkown_0x10 = 0;
		a1->dwCnt_0x0c = 0;
	}
	return result;
}

int __cdecl sub_45E736(int a1, gItem_0xEC * a2)
{
	int result; // eax
	int i; // [esp+0h] [ebp-4h]

	for ( i = 0; i < a1; ++i )
	{
		if ( a2[i].pSubNode_0xe8 )
		{
			sub_45E687( a2[i].pSubNode_0xe8 );

			delete a2[i].pSubNode_0xe8;

			a2[i].pSubNode_0xe8 = 0;
		}
		result = i + 1;
	}
	return result;
}

gItem_0x20 *__cdecl sub_45E7BF(gItem_0x20 *a1)
{
	gItem_0x20 *result; // eax
	gItem_Data** v2; // [esp+0h] [ebp-8h]
	int i; // [esp+4h] [ebp-4h]

	if ( a1->pDataPtr_0x1c )
	{
		v2 = a1->pDataPtr_0x1c;
		if ( v2 )
		{
			for ( i = 0; i < a1->dwDataCnt_0x10; ++i )
				sub_45E51F(v2[i]);

			a1->dwDataCnt_0x10 = 0;
			a1->pDataPtr_0x1c = 0;
		}
	}
	result = a1;
	if ( a1->pItem_0x0c )
	{
		sub_45E6EB(a1->dwUnknow_0x08, a1->pItem_0x0c);
		a1->dwUnknow_0x08 = 0;
		result = a1;
		a1->pItem_0x0c = 0;
	}
	return result;
}



sItem_0x10_4E0C60 *__cdecl sub_45AF9E(int a1)
{
	sItem_0x10_4E0C60 *result; // eax
	sItem_0x10_4E0C60 *v2; // [esp+0h] [ebp-4h]

	v2 = &g_Item_4E0C60[a1];
	g_Item_4E0C60[a1].wUnkown_0x0 = -1;
	v2->dwItemCnt_0x2 = 0;
	result = v2;
	if ( v2->pItem_0x6 )
	{
		free(v2->pItem_0x6);
		result = v2;
		v2->pItem_0x6 = 0;
	}
	return result;
}


int __cdecl sub_45B20D(char a1, gItem_0x20 * a2)
{
	char *v3; // eax
	gItem_0xEC v5;
	memset(&v5, 0, sizeof(gItem_0xEC));
	size_t v11; // [esp+ECh] [ebp-4h]
	v5.dwUnkown_0x0 = 1;
	v5.nNodeIdx_0xe4 = 1;

	v5.dwItemx27_0xe0 = (gItem_0x27*)g_dataReader->ReadData(0x4E0857, 0);//&unk_4E0857;
	v5.pSubNode_0xe8 = 0;
	v11 = dword_4E085F;
	if ( dword_4E085F != 1 )
	{
		ASSERT(0);
	}
	memcpy(v5.str_unkown_0x6a, &a1, v11);
	memcpy(v5.str_unkown_0x9b, v5.str_unkown_0x6a, v11);
	v3 = (char *)GetDirectoryNameFromReg();
	return sub_462B29(0, v3, 11, &v5, 1, a2, 0, 0, 0);
}

struct sParam4
{
	sItem_0x10_4E0C60 * pItem_0x0;
};

BOOL __cdecl sub_45B2A5(unsigned __int8 a1, sItem_0x10_4E0C60 **a2)
{
	int v3; // ecx
	int v4; // ecx
	BYTE *i; // [esp+0h] [ebp-10Ch]
	BYTE *v7; // [esp+4h] [ebp-108h]
	int v8; // [esp+8h] [ebp-104h]
	int v9; // [esp+Ch] [ebp-100h]
	char v10[8]; // [esp+10h] [ebp-FCh]
	gItem_Data * v11; // [esp+18h] [ebp-F4h]
	int v12; // [esp+1Ch] [ebp-F0h]
	int v13; // [esp+20h] [ebp-ECh]
	gItem_Data ** v14; // [esp+24h] [ebp-E8h]
	int v15; // [esp+28h] [ebp-E4h]
	int v16_NodeIdx; // [esp+2Ch] [ebp-E0h]

	sItem_0x10_4E0C60 *v18; // [esp+34h] [ebp-D8h]
	int v19; // [esp+38h] [ebp-D4h]
	int v20; // [esp+3Ch] [ebp-D0h]
	char v21; // [esp+40h] [ebp-CCh]
	CHAR Buffer[150]; // [esp+41h] [ebp-CBh]
	int v23; // [esp+D7h] [ebp-35h]
	int v24; // [esp+DCh] [ebp-30h]
	void *v25; // [esp+E0h] [ebp-2Ch]
	gItem_0x20 v26; // [esp+E4h] [ebp-28h]
	//int v27; // [esp+F4h] [ebp-18h]
	//int v28; // [esp+100h] [ebp-Ch]
	sParam3_0xA3 * v29; // [esp+104h] [ebp-8h]
	DWORD *v30; // [esp+108h] [ebp-4h]

	v15 = 0;
	v18 = &g_Item_4E0C60[a1];  
	if ( g_Item_4E0C60[a1].wUnkown_0x0 )
		sub_45AF9E(a1);
	if ( !v18->pItem_0x6 )
	{
		sub_45B20D(a1, &v26);
		v29 = (sParam3_0xA3 *)malloc(0xA3 * (v26.dwDataCnt_0x10 + 2));
		if ( v29 )
		{
			v18->wUnkown_0x0 = v15;
			v18->dwItemCnt_0x2 = v26.dwDataCnt_0x10 + 2;
			v18->pItem_0x6 = v29;
			v19 = dword_4E0240;
			v20 = ((DWORD*)&dword_4E0240)[1];
			v21 = 0;
			sub_45B19E(a1, Buffer, 150);
			sub_46BD90((void *)v29, &v19);
			v19 = dword_4FD890;
			v20 = dword_4FD894;
			v21 = 0;
			sub_45B163(a1, Buffer, 150);
			sub_46BD90((void *)&v29[1], &v19);
			if ( v26.dwDataCnt_0x10 )
			{
				v14 = v26.pDataPtr_0x1c;
				if ( v14 )
				{
					v16_NodeIdx = 0;
					v12 = 2;
					while ( v16_NodeIdx < v26.dwDataCnt_0x10 )
					{
						v11 = v14[v16_NodeIdx];
						if ( v11 )
						{
							v30 = (DWORD*)v11->pNodeData_0x190;
							v3 = *(DWORD *)(&v11->pNodeData_0x190[4]);
							v19 = *(DWORD *)(&v11->pNodeData_0x190[0]);
							v20 = v3;
							v21 = *(BYTE *)(&v11->pNodeData_0x190[8]);
							v23 = *(DWORD *)(&v11->pNodeData_0x190[0x9f]);
							v25 = (void *)(&v11->pNodeData_0x190[9]);
							memcpy(&Buffer, &v11->pNodeData_0x190[9], 0x96u);
							v13 = 2;
							v24 = v12;
							while ( v13 <= v24 && v13 < v12 )
							{
								v9 = (v24 + v13) / 2;
								sub_45AF77((void *)&v29[v9], &v10[0]);
								if ( sub_45B003(v30, (DWORD*)&v10[0]) > 0 )
									v13 = v9 + 1;
								else
									v24 = v9 - 1;

							}
							if ( v13 < v12 )
							{
								v8 = 163 * (v12 - v13);
								v7 = (BYTE *)&v29[v12];
								for ( i = (BYTE *)&v29[v12+1]; ; *i = *v7 )
								{
									v4 = v8--;
									if ( !v4 )
										break;
									--v7;
									--i;
								}
							}
							sub_46BD90(&v29[v13], &v19);
						}
						++v16_NodeIdx;
						++v12;
					}
				}
			}
		}
		sub_45E7BF(&v26);
	}
	*a2 = v18;
	return  v18->pItem_0x6 != 0;
}



signed int __cdecl sub_45B84E(sItem_0x10_4E0C60 * a1, DWORD *a2, unsigned int *a3)
{
	signed int result; // eax
	unsigned int v4; // [esp+0h] [ebp-1Ch]
	unsigned int v5; // [esp+4h] [ebp-18h]
	unsigned int v6; // [esp+8h] [ebp-14h]
	char v7[8]; // [esp+Ch] [ebp-10h]
	int v8; // [esp+14h] [ebp-8h]
	sParam3_0xA3 * v9; // [esp+18h] [ebp-4h]

	
	v9 = a1->pItem_0x6;
	if ( !a1->dwItemCnt_0x2 )
		return 0;
	if ( sub_45AFE8((int)a2) )
	{
		*a3 = 0;
		result = 1;
	}
	else
	{
		v4 = 1;
		v6 = a1->dwItemCnt_0x2 - 1;
		while ( 1 )
		{
			v5 = (v6 + v4) >> 1;
			sub_45AF77((void *)&v9[v5], (void*)&v7[0]);
			v8 = sub_45B003((DWORD*)&v7, a2);
			if ( !v8 )
			{
				*a3 = v5;
				return 1;
			}
			if ( v4 >= v6 )
				break;
			if ( v8 <= 0 )
				v4 = v5 + 1;
			else
				v6 = v5 - 1;
		}
		result = 0;
	}
	return result;
}

int __cdecl sub_45B7D4(int nBaseResID, DWORD a2, LPSTR lpBuffer, int cchBufferMax)
{
	__int16 v4; // cx
	int v5; // ecx
	int result; // eax
	int v7; // [esp+0h] [ebp-Ch]
	int v8; // [esp+4h] [ebp-8h]
	sItem_0x10_4E0C60 * v9; // [esp+8h] [ebp-4h]

	v7 = 0;
	v4 = (__int16)nBaseResID;
	if ( sub_45B2A5(v4, &v9) )
	{
		v7 = sub_45B84E(v9, (DWORD*)a2, (unsigned int*)&v8);
		if ( v7 )
		{
			v5 = v8;
			sub_45B761(nBaseResID, v5, lpBuffer, cchBufferMax);
		}
	}

	if ( v7 )
		result = v7;
	else
		result = sub_45B163(nBaseResID, lpBuffer, cchBufferMax);
	return result;
}

int __cdecl sub_407FFD(gItem_0x27 * a1, byte * a2)
{
	int v3 = 0;
	if ( a1->byteType_0x0c == 2 )
		v3 = *(DWORD*)(a2 + a1->dwId2_0x4);
	return v3;
}

double __cdecl sub_421D8D(signed int a1)
{
	double result; // st7

	if ( a1 >= 0 && a1 < 3 )
	{
		BYTE * pData = g_dataReader->ReadData(0x4DC51C, 0x20);
		result = *(double *)((char *)pData + 12 * a1);
	}
	else
		result = 1.0;
	return result;
}

char __cdecl sub_421F14(double a1, int a2, char *a3, int a4)
{
	unsigned __int64 v4; // st7
	char *v5; // eax
	size_t i; // [esp+0h] [ebp-1Ch]
	CHAR Buffer[0x14]; // [esp+4h] [ebp-18h]
	char *v9; // [esp+18h] [ebp-4h]

	*(double *)&v4 = a1 / sub_421D8D(a2);
	sprintf(a3, "%f", (DWORD)v4, (DWORD)(v4 >> 32));
	TrimEnd(a3);
	for ( i = strlen(a3) - 1; i && a3[i] == 48; --i )
		a3[i] = 0;
	if ( i && a3[i] == 46 )
		a3[i] = 0;
	v5 = strchr(a3, 46);
	v9 = v5;
	if ( v5 )
	{
		//LOBYTE(v5) = sub_421E62();
		*v9 = (char)v5;
	}
	if ( a4 )
	{
		//sub_421D54(a2, &Buffer);
		strcat(a3, "-");
		//LOBYTE(v5) = (unsigned int)strcat(a3, &Buffer);
	}
	return (char)v5;
}


DWORD *__cdecl GetCatalogueNumber(gItem_Data *a1)
{
	DWORD *v2; // [esp+4h] [ebp-8h]

	switch ( a1->nFileIdx_0x0 )
	{
	case 0:
	case 1:
	case 3:
	case 4:
		v2 = (DWORD*)(a1->pNodeData_0x190 + 8);
		break;
	case 2:
		v2 = (DWORD*)(a1->pNodeData_0x190 + 0x10);
		break;
	default:
		v2 = 0;
		break;
	}
	return v2;
}

gItem_Data * __cdecl sub_461C19(gItem_Data * a1, int a2, int a3)
{
	char *v3; // ST3C_4
	int v5; // [esp+0h] [ebp-34h]
	int v6; // [esp+0h] [ebp-34h]
	signed int v7; // [esp+4h] [ebp-30h]
	gItem_Data *v9; // [esp+Ch] [ebp-28h]
	int j; // [esp+10h] [ebp-24h]
	gItem_Data * v11; // [esp+14h] [ebp-20h]
	int i; // [esp+18h] [ebp-1Ch]
	int k; // [esp+18h] [ebp-1Ch]
	int v14; // [esp+1Ch] [ebp-18h]
	int v15; // [esp+20h] [ebp-14h]
	int v16; // [esp+24h] [ebp-10h]
	int v17; // [esp+2Ch] [ebp-8h]

	gItem_Data * pv8 = new gItem_Data;
	memset(pv8, 0, sizeof(gItem_Data));

	pv8->pNodeData_0x190 = new BYTE[g_ItemDatas_0x122[a2].itemSize_0x08];
	
	if ( pv8 )
	{
		v9 = pv8;
		if ( v9 )
		{
			v9->nFileIdx_0x0 = a2;
			v9->nNodeIdx_0x4 = -1;
			v9->pNextData_0x9c = a1;
			if ( a2 == 3 )
				v9->dwUnkown_0x88 = 1;
			if ( !a2 )
				v9->dwUnkown_0x88 = 1;
			v17 = g_ItemDatas_0x122[a2].dwUnkown_0x26;
			if ( v17 )
				*(int *)&v9->pNodeData_0x190[v17] = time(0);

			if ( a1 )
			{
				v7 = a1->nFileIdx_0x0;
				for ( i = 0; i < g_ItemDatas_0x122[a2].dwUnkownCnt_0x2a; ++i )
				{
					v14 = *(DWORD *)(&g_ItemDatas_0x122[a2].dwUnkown_0x32 + 8 * i);
					if ( v14 >= 0 )
					{
						v5 = g_ItemDatas_0x122[a2].dwUnkown_0x2e;

						for ( j = 0; j < g_ItemDatas_0x122[v7].dwUnkownCnt_0x2a; ++j )
						{
							v16 = *(DWORD *)((char*)&g_ItemDatas_0x122[v7].dwUnkown_0x32 + 8 * j);

							if ( v16 >= 0 &&  g_ItemDatas_0x122[v7].dwUnkown_0x2e == v5 )
							{
								if ( v15 )
								{
									memcpy( v9->pNodeData_0x190 + g_ItemDatas_0x122[a2].pData_0x0e[v14].dwId2_0x4 ,
										a1->pNodeData_0x190 + g_ItemDatas_0x122[v7].pData_0x0e[v16].dwId2_0x4 ,
										g_ItemDatas_0x122[a2].pData_0x0e[i].dwDataLen_0x08);
								}
							}
						}
					}
				}
			}
			else
			{
				for ( k = 0; k <  g_ItemDatas_0x122[a2].dwUnkownCnt_0x2a; ++k )
				{
					v6 = *(DWORD *)((char*)&g_ItemDatas_0x122[a2].dwUnkown_0x2e + 8 * k);
					if ( *(DWORD *)((char*)&g_ItemDatas_0x122[a2].dwUnkown_0x32 + 8 * k) >= 0 )
						v11 = sub_461C19(pv8, v6, a3);
					else
						v11 = sub_461C19(pv8, v6, 0);

					v9->dwUnkown_0xd0[v6] = v11;
					v9->dwUnkown_0xa0[v6] = 1;
				}
			}

// 			if ( a3 )
// 			{
// 				v3 = (char *)GetCatalogueNumber(v9);
// 				sub_461169((int)v9, v3);
// 			}
		}
	}
// 	if ( pv8 )
// 	{
// 		sub_45F07F(v8);
// 		sub_45EC5D(v8);
// 	}
	return pv8;
}

gItem_Data *  __cdecl sub_45DE51(gItem_Data * a1)
{
	gItem_Data * result; // eax
	gItem_Data * v2 = NULL;
	if ( a1 )
	{
		v2 = a1->pNextData_0x9c;
	}
	if ( v2 )
		result = sub_45DE51(v2);
	else
		result = a1;

	return result;
}


gItem_Data * __cdecl sub_4625CE(gItem_Data *a1, gItem_Data * a2, int a3)
{
	gItem_Data * v4; // [esp+0h] [ebp-20h]
	int v5; // [esp+4h] [ebp-1Ch]
	signed int v6; // [esp+8h] [ebp-18h]
	signed int v7; // [esp+8h] [ebp-18h]
	gItem_Data *v8; // [esp+Ch] [ebp-14h]
	int v9; // [esp+10h] [ebp-10h]
	int i; // [esp+14h] [ebp-Ch]
	int j; // [esp+14h] [ebp-Ch]
	int k; // [esp+14h] [ebp-Ch]
	int v13; // [esp+18h] [ebp-8h]
	int v14; // [esp+1Ch] [ebp-4h]

	v4 = 0;
	if ( a2 )
	{
		v8 = a2;
		if ( v8 )
		{
			v14 = v8->nFileIdx_0x0;
			v9 = a1->nFileIdx_0x0;
			if ( *(DWORD *)&v8[4 * a3 + 160] )
			{
				v6 = 0;
				for ( i = 0; i < g_ItemDatas_0x122[v9].dwUnkownCnt_0x2a; ++i )
				{
					if ( *(DWORD*)((char*)&g_ItemDatas_0x122[v9].dwUnkown_0x2e + 8 * i) == a3 )
					{
						v5 = *(DWORD*)((char*)&g_ItemDatas_0x122[v9].dwUnkown_0x32 + 8 * i);
						v6 = 1;
						break;
					}
				}
				if ( v6 )
				{
					if ( v5 >= 0 )
					{
						v7 = 0;
						for ( j = 0; j <g_ItemDatas_0x122[v14].dwUnkownCnt_0x2a; ++j )
						{
							if (*(DWORD *)((char*)&g_ItemDatas_0x122[v14].dwUnkown_0x2e + 8 * j) == a3)
							{
								v13 = *(DWORD*)((char*)&g_ItemDatas_0x122[v14].dwUnkown_0x32 + 8 * j);
								v7 = 1;
								break;
							}
						}

						if ( v7
							&& !strcmp((char*)a1->pNodeData_0x190[g_ItemDatas_0x122[v9].pData_0x0e[v5].dwId2_0x4], (char*)v8->pNodeData_0x190[g_ItemDatas_0x122[v14].pData_0x0e[v13].dwId2_0x4]) 
							)
						{
							v4 = v8->dwUnkown_0xd0[a3];
						}
					}
					else
					{
						v4 = v8->dwUnkown_0xd0[a3];
					}
				}
			}
			if ( !v4 )
			{		
				for ( k = 0; k < g_ItemDatas_0x122[v14].dwUnkownCnt_0x2a && !v4; ++k )
				{
					if ( k != a3 )
						v4 = sub_4625CE(a1, v8->dwUnkown_0xd0[k], a3);
				}
			}
		}
	}
	return v4;
}

void __cdecl sub_463E71(gItem_0xEC * a1, int a2)
{
	char v2; // [esp+4h] [ebp-8h]
	int i; // [esp+8h] [ebp-4h]

	for ( i = 0; i < a2; ++i )
	{
		if ( a1->dwUnkown_0x0 )
		{
			v2 = a1[i].dwItemx27_0xe0->byteSubType_0x0d;
			if ( v2 != 1 && v2 != 7 )
			{
				a1[i].dwSubLen_0xdc = a1[i].dwItemx27_0xe0->dwDataLen_0x08;
			}
			else
			{
				a1[i].dwSubLen_0xdc = strlen(a1[i].str_unkown_0x6a);
				if ( a1[i].dwSubLen_0xdc > (signed int)strlen(a1[i].str_unkown_0x9b) )
					a1[i].dwSubLen_0xdc = strlen(a1[i].str_unkown_0x9b);
				if ( a1[i].dwSubLen_0xdc > a1[i].dwItemx27_0xe0->dwDataLen_0x08)
					a1[i].dwSubLen_0xdc = a1[i].dwItemx27_0xe0->dwDataLen_0x08;
			}
		}
	}
}


int __cdecl GetRecordCnt(int a1)
{
	int v2; // [esp+0h] [ebp-4h]
	
	if ( g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4 == 6 )
		v2 = g_ItemFileHeader_0xCE[a1].dwNodeCnt_0x16;
	else
		v2 = g_ItemFileHeader_0xCE[a1].dwUnkown_0x1A;
	return v2;
}


WORD *__cdecl EncodeBuffer(unsigned __int8 *a1, int a2, WORD *a3)
{
	WORD *result; // eax
	int v4; // ecx
	unsigned __int8 *i; // [esp+0h] [ebp-4h]

	result = (WORD*)a1;
	for ( i = a1; ; ++i )
	{
		v4 = a2--;
		if ( !v4 )
			break;
		a3[1] += *i;
		*a3 ^= a3[1];
		result = a3;
		a3[1] += *a3;
	}
	return result;
}

WORD *__cdecl encodeBuf(BYTE * a1, int a2, WORD *a3)
{
	*a3 = 0;
	a3[1] = 0;
	return EncodeBuffer((unsigned __int8 *)a1, a2, a3);
}

int __cdecl sub_45ECAE(int a1, BYTE * a2, BYTE * a3)
{
	int result; // eax
	int v4; // [esp+0h] [ebp-Ch]
	int i; // [esp+4h] [ebp-8h]

	encodeBuf(a2, g_ItemDatas_0x122[a1].itemSize_0x08, (WORD *)a3);
	*(WORD *)(a3 + 4) = 0;
	*(WORD *)(a3 + 6) = 0;
	for ( i = 0; ; ++i )
	{
		result = 290 * a1;
		if ( i >= g_ItemDatas_0x122[a1].dwUnkownCnt_0x2a)
			break;
		v4 = *(DWORD*)((char*)&g_ItemDatas_0x122[a1].dwUnkown_0x32 + 8 * i);

		if ( v4 >= 0 )
			EncodeBuffer((unsigned char*)&a2[g_ItemDatas_0x122[a1].pData_0x0e[v4].dwId2_0x4],
			g_ItemDatas_0x122[a1].pData_0x0e[v4].dwDataLen_0x08,
			(WORD *)(a3 + 4));
	}
	return result;
}

void __cdecl sub_45EC5D(gItem_Data * a1)
{
	if ( a1 )
	{
		sub_45ECAE(a1->nFileIdx_0x0, a1->byteData_0x64, (BYTE *)&a1->dwUnkown_0x23);
	}
}

gItem_Data* __cdecl sub_45E0BD(gItem_Data* a1);
void __cdecl sub_45E2BA(gItem_subData * a1, gItem_subData * a2)
{
	gItem_subData *v2; // edx
	gItem_subData *v3; // ecx
	gItem_Data ** v4; // [esp+0h] [ebp-10h]
	int j; // [esp+4h] [ebp-Ch]
	signed int i; // [esp+8h] [ebp-8h]
	gItem_Data ** v7; // [esp+Ch] [ebp-4h]

	for ( i = 0; i < 12; ++i )
	{
		v2 = &a1[i];
		v3 = &a2[i];
		v3->dwUnkown_0x00 = v2->dwUnkown_0x00;
		v3->dwDataCnt_0x04 = v2->dwDataCnt_0x04;
		v3->pDataPtr_0x08 = v2->pDataPtr_0x08;
		if ( v2->pDataPtr_0x08 )
		{
			a2[i].pDataPtr_0x08 = (gItem_Data **)malloc(a1[i].dwDataCnt_0x04 * 4);
			if ( a2[i].pDataPtr_0x08 )
			{
				v7 = a2[i].pDataPtr_0x08;
				if ( v7 )
				{
					v4 = a1[i].pDataPtr_0x08;
					if ( v4 )
					{
						for ( j = 0; j < a1[i].dwDataCnt_0x04; ++j )
							v7[j] = sub_45E0BD(v4[j]);
					}
				}
			}
			else
			{
				a2[i].dwUnkown_0x00 = 0;
				a2[i].dwDataCnt_0x04 = 0;
			}
		}
	}
}

gItem_Data* __cdecl sub_45E0BD(gItem_Data* a1)
{
	signed int v2; // [esp+0h] [ebp-1Ch]
	gItem_Data* v3; // [esp+4h] [ebp-18h]
	gItem_Data* v4; // [esp+4h] [ebp-18h]
	gItem_Data* v5; // [esp+8h] [ebp-14h]
	signed int i; // [esp+Ch] [ebp-10h]
	char * v7; // [esp+10h] [ebp-Ch]
	char * v8; // [esp+14h] [ebp-8h]
	int nSizeV9; // [esp+18h] [ebp-4h]

	v5 = 0;
	if ( a1 )
	{
		nSizeV9 = g_ItemDatas_0x122[a1->nFileIdx_0x0].itemSize_0x08;
		v5 = new gItem_Data;
		memset(v5, 0, sizeof(gItem_Data));
		if ( v5 )
		{
			v8 = (char *)v5;
			if ( v8 )
			{
				v7 = (char *)a1;
				if ( v7 )
				{
					memcpy(v8, v7, sizeof(gItem_Data));
					v5->pNodeData_0x190 = new BYTE[nSizeV9];
					memcpy(v5->pNodeData_0x190, a1->pNodeData_0x190, nSizeV9);

					v5->dwUnkown_0x98 = 0;
					for ( i = 0; i < 12; ++i )
					{
						if ( a1->dwUnkown_0xd0[i] )
						{
							v2 = 0;
							v3 = a1->dwUnkown_0xd0[i];
							if ( v3 )
							{
								if ( a1 != v3->pNextData_0x9c && v3->dwUnkown_0x98 )
									v2 = 1;
							}
							if ( v2 )
							{
								v5->dwUnkown_0xd0[i] = 0;
								v5->dwUnkown_0xa0[i] = 0;
							}
							else
							{
								v5->dwUnkown_0xd0[i] = sub_45E0BD(a1->dwUnkown_0xd0[i]);
								if ( v5->dwUnkown_0xd0[i] )
								{
									v4 = v5->dwUnkown_0xd0[i];
									if ( v4 )
									{
										v4->pNextData_0x9c = v5;
									}
								}
							}
						}
					}
					sub_45E2BA(a1->subData_0x100, v5->subData_0x100);
				}
			}
		}
	}
	return v5;
}

void __cdecl sub_4620FA(gItem_Data * a1, int a2, int a3)
{
	gItem_Data * v3; // eax
	HCURSOR v4; // eax
	CHAR v5[0x14]; // [esp+0h] [ebp-158h]
	CHAR Buffer[0x14]; // [esp+14h] [ebp-144h]
	int v7; // [esp+28h] [ebp-130h]
	gItem_Data * v8; // [esp+2Ch] [ebp-12Ch]
	gItem_Data * v9; // [esp+30h] [ebp-128h]
	gItem_Data * v10; // [esp+34h] [ebp-124h]
	gItem_Data **v11; // [esp+38h] [ebp-120h]
	int v12; // [esp+3Ch] [ebp-11Ch]

	int v14; // [esp+44h] [ebp-114h]


	gItem_0xEC itemEc;
	memset(&itemEc, 0, sizeof(itemEc));

// 	char v15[0x66];
// 	char v16[0x30]; // [esp+B2h] [ebp-A6h]
// 	char v17[0x45]; // [esp+E3h] [ebp-75h]
// 	gItem_0x27 * v18 = 0; // [esp+128h] [ebp-30h]
//	int v19; // [esp+12Ch] [ebp-2Ch]
	int v20; // [esp+130h] [ebp-28h]
	int i; // [esp+134h] [ebp-24h]
	gItem_0x20 v22; // [esp+138h] [ebp-20h]
//	int v23; // [esp+154h] [ebp-4h]

	v8 = 0;
	if ( a1 )
	{
		v10 = a1;
		if ( v10 )
		{
			v14 = v10->nFileIdx_0x0;
			if (v10->pNextData_0x9c)
			{
				v3 = sub_45DE51(a1);
				v8 = sub_4625CE(v10, v3, a2);
			}
			if ( v8 )
			{
				v9 = v8;
				v9->dwUnkown_0x98++;
			}
			else
			{
				for ( i = 0; i < g_ItemDatas_0x122[v14].dwUnkownCnt_0x2a; i++ )
				{
					v7 = *(DWORD*)((char*)&g_ItemDatas_0x122[v14].dwUnkown_0x2e + i * 8);
					if ( v7 == a2 )
					{
						v12 = *(DWORD*)((char*)&g_ItemDatas_0x122[v14].dwUnkown_0x32 + 8*i);
						if ( v12 >= 0 )
						{
							itemEc.dwUnkown_0x0 = 1;
							itemEc.nNodeIdx_0xe4 = 0;
							itemEc.dwItemx27_0xe0 =  &g_ItemDatas_0x122[v7].pData_0x0e[0];
							v20 = 0;
							memcpy(&itemEc.str_unkown_0x6a[0], 
								&v10->pNodeData_0x190[g_ItemDatas_0x122[v14].pData_0x0e[v12].dwId2_0x4], 
								g_ItemDatas_0x122[v14].pData_0x0e[v12].dwDataLen_0x08);

		
							memcpy(&itemEc.str_unkown_0x9b[0], 
								&itemEc.str_unkown_0x6a[0], 
								g_ItemDatas_0x122[v14].pData_0x0e[v12].dwDataLen_0x08);

							if ( v14 != 1 || v7 != 4 || 
								itemEc.dwItemx27_0xe0->byteType_0x0c != 10 ||
								*(int*)&itemEc.str_unkown_0x6a[0] != -1 )
							{		
								if ( sub_462B29(0, v10->sDir_0x8 , v7, &itemEc, 1, &v22, 0, 1, 0) )
								{
									v11 = v22.pDataPtr_0x1c;
									if ( v11 )
									{
										v8 = sub_45E0BD(v11[0]);
										if ( v8 )
										{
											v9 = v8;
											if ( v9 )
											{
												v9->pNextData_0x9c = a1;
											}
											sub_45EC5D(v8);
										}
									}
								}
								sub_45E7BF(&v22);
							}
							else
							{
								v8 = sub_461C19(a1, a2, 0);
							}
						}
						else
						{
							v8 = sub_461C19(a1, a2, 0);
						}
						if ( !v8 && (v12 != 2 || v7 != 4 || v14 != 1) )
						{
							ASSERT(0);
							if ( !a3 )
								v8 = sub_461C19(a1, a2, 1);
						}
						break;
					}
				}
			}

			a1->dwUnkown_0xd0[a2] = v8;
			a1->dwUnkown_0xa0[a2] = 1;
		}
	}
}

gItem_Data * __cdecl sub_46208B(gItem_Data * a1, int a2, int a3)
{
	gItem_Data * v4 = 0;
	if ( a1 )
	{
		if ( !a1->dwUnkown_0xa0[a2] )
		{
			sub_4620FA(a1, a2, a3);
		}
		v4 = a1->dwUnkown_0xd0[a2];
	}
	return v4;
}


void __cdecl sub_461F9B(gItem_Data * a1, char *a2)
{
	gItem_Data * v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	if ( a1 )
	{
		v2 = a1;
		if ( v2 )
		{
			v3 = v2->nFileIdx_0x0;
			if ( v3 == g_ItemDatas_0x122[v3].dwIdx_0x1e || 
				(a1 = sub_46208B(a1,  g_ItemDatas_0x122[v3].dwIdx_0x1e, 0)) != 0
				)
			{
				v2 = a1;
				strcpy(a2, (char*)&v2->pNodeData_0x190[g_ItemDatas_0x122[v3].dwUnkown_0x1a]);
				if (g_ItemDatas_0x122[v3].funTrimEnd_0x22)
				{
					//trimfun call
					//g_ItemDatas_0x122[v3].funTrimEnd_0x22(a2)
				}
			}
			else
			{
				*a2 = 0;
			}
		}
	}
}

signed int __cdecl sub_4612FD(char * sPath, int a1, int a2)
{
	int v3; // [esp+0h] [ebp-18h]
	char PathName[100]; // [esp+4h] [ebp-14h]

	wsprintfA(PathName, "%s%s.n%02d", sPath, g_ItemDatas_0x122[a1].strName_0x04, a2);
	v3 = InitFile(PathName, 1);
	if ( v3 == -1 )
	{
		ASSERT(0);
		return -1;
	}

	return v3;
}

signed int __cdecl sub_463C5C(char * sPath, int a1)
{
	int v2; // [esp+0h] [ebp-18h]
	char PathName[100]; // [esp+4h] [ebp-14h]

	wsprintfA(PathName, "%s%s.dt", sPath, g_ItemDatas_0x122[a1].strName_0x04);
	v2 = InitFile(PathName, 1);
	if ( v2 == -1 )
	{
		ASSERT(0);
		return -1;
	}
	return v2;
}


signed int __cdecl sub_462A88( gItem_0x20 * a1, gItem_Data * a2)
{
	signed int v3; // [esp+0h] [ebp-Ch]
	gItem_Data** v4; // [esp+4h] [ebp-8h]
	int v5; // [esp+8h] [ebp-4h]

	v3 = 0;
	if ( a1->dwDataCnt_0x10 )
		v4 = (gItem_Data**)realloc(a1->pDataPtr_0x1c, 4 * a1->dwDataCnt_0x10 + 4);
	else
		v4 = (gItem_Data**)malloc(4);

	if ( v4 )
	{
		v3 = 1;
		if ( v4 )
		{
			v4[a1->dwDataCnt_0x10] = a2;
		}
		a1->pDataPtr_0x1c = v4;
		++a1->dwDataCnt_0x10;
	}
	return v3;
}

int __cdecl sub_4651BB( gItem_0x20 * a1, void *a2, int a3, int a4, int a5, char *a6)
{
	signed int v7 = 0; // [esp+4h] [ebp-14h]
	size_t v8; // [esp+8h] [ebp-10h]
	int v10; // [esp+14h] [ebp-4h]

	v8 = g_ItemDatas_0x122[a3].itemSize_0x08;
	gItem_Data * v9 = new gItem_Data;
	memset(v9, 0, sizeof(gItem_Data));
	v9->pNodeData_0x190 = new BYTE[g_ItemDatas_0x122[a3].itemSize_0x08];

	if ( v9 )
	{
		v9->nFileIdx_0x0 = a3;
		v9->dwUnkown_0x88 = a5;
		v9->nNodeIdx_0x4 = a4;
			
		if ( a3 == 3 )
		{
			v9->dwUnkown_0x88 = 1;
		}
		if ( !a3 )
		{
			v9->dwUnkown_0x88 = 1;
		}
		if ( a6 )
			strcpy(v9->sDir_0x8, a6);
		else
			strcpy(v9->sDir_0x8, "");

		memcpy(v9->pNodeData_0x190, a2, v8);

		if ( !v9->nFileIdx_0x0 )
			TrimEnd((char *)(&v9->pNodeData_0x190[0xf]));

		sub_45EC5D(v9);

		v7 = sub_462A88(a1, v9);
		if ( !v7 )
			sub_45E51F(v9);
	}
	return v7;
}

BOOL __cdecl sub_46511A(gItem_0x20 * a1, int a2)
{
	int v2; // ecx
	BOOL v4; // [esp+0h] [ebp-10h]
	gItem_Data * v5; // [esp+4h] [ebp-Ch]
	gItem_Data **v6; // [esp+8h] [ebp-8h]
	int v7; // [esp+Ch] [ebp-4h]
	v4 = 0;
	int nIdx = 0;
	v7 = a1->dwDataCnt_0x10;
	if ( v7 )
	{
		v6 = a1->pDataPtr_0x1c;
		if ( v6 )
		{
			while ( 1 )
			{
				v2 = v7--;
				if ( !v2 || v4 )
					break;
 				v5 = v6[nIdx];
 				if ( v5 )
				{
					v4 = v5->nNodeIdx_0x4 == a2;
				}
				++nIdx;
			}
		}
	}
	return v4;
}


signed int __cdecl sub_465040(sItem_t1 * a1, int a2)
{
	int v3 = 0;
	if (a1->pItem_0x4[a2].dwItemx27_0xe0->byteType_0x0c == 4 )
	{
		for (char * i = &a1->pItem_0x4[a2].str_unkown_0x6a[0]; *i; i += 2 )
		{
			if ( *i == 8 )
				return 1;
		}
	}
	return v3;
}

int __cdecl sub_463CF3(sItem_t1 *a1, int a2)
{
	int i; // [esp+0h] [ebp-4h]

	for ( i = 0; i < a1->nCnt_0x0; ++i )
	{
		if ( a2 == a1->pItem_0x4[i].nNodeIdx_0xe4)
			return i;
	}
	return 0;
}



int __cdecl sub_4649F2(sItem_t1 *a1, int a2)
{
	int result; // eax
	int v3; // ST08_4
	int v4; // ST08_4
	gItem_0xEC v5; // [esp+Ch] [ebp-1E4h]
	int i; // [esp+F8h] [ebp-F8h]
	gItem_0x27 * v7; // [esp+FCh] [ebp-F4h]
	int v8; // [esp+100h] [ebp-F0h]
	gItem_0xEC v9; // [esp+104h] [ebp-ECh]
	gItem_0xEC itemEc;


	while ( 1 )
	{
		result = a2--;
		if ( !result )
			break;
		v8 = -1;
		for ( i = 0; i < a1->nCnt_0x0; ++i )
		{
			if (*(DWORD *)(a1->pData_0x14 + 4 * i))
			{	
				ASSERT(sizeof(gItem_0xEC) == 0xec);	//如果这里结构不一致，后面的memcpy会有问题
				if ( v8 == -1 )
				{
					v8 = i;
					memcpy(&itemEc, &a1->pItem_0x4[i], 0xECu);
				}
				else
				{
					memcpy(&v5, &a1->pItem_0x4[i], 0xECu);
					v3 = a1->pItem_0x4[i].nNodeIdx_0xe4;
					v7 = a1->pItem_0x4[i].dwItemx27_0xe0;
					memcpy(&a1->pItem_0x4[i], &v9, 0xECu);
					a1->pItem_0x4[i].nNodeIdx_0xe4 = v3;
					a1->pItem_0x4[i].dwItemx27_0xe0 = v7;

					memcpy(&v9, &v5, 0xECu);
				}
			}
		}
		if ( v8 != -1 )
		{
			v4 = a1->pItem_0x4[v8].nNodeIdx_0xe4;
			v7 = a1->pItem_0x4[v8].dwItemx27_0xe0;

			memcpy(&a1->pItem_0x4[v8], &v9, 0xECu);

			a1->pItem_0x4[v8].nNodeIdx_0xe4 = v4;
			a1->pItem_0x4[v8].dwItemx27_0xe0 = v7;

			a1->dwUnkown_0x18--;
		}
	}
	return result;
}

signed int __cdecl sub_464C32(sItem_t1 *sp1)
{
	signed int v2; // [esp+0h] [ebp-10h]
	int v3; // [esp+4h] [ebp-Ch]
	int i; // [esp+8h] [ebp-8h]
	int j; // [esp+8h] [ebp-8h]
	int k; // [esp+8h] [ebp-8h]
	int v7; // [esp+Ch] [ebp-4h]
	int v8; // [esp+Ch] [ebp-4h]

	v2 = 0;
	if ( sp1->pItem_0x4 )
	{
		sp1->dwUnkown_0x8 = 0;
		sp1->dwUnkown_0x10 = 0;
		v3 = 0;
		sp1->dwUnkown_0x20 = -1;
		sp1->dwUnkown_0x24 = 0;
		for ( i = 0; i < sp1->nCnt_0x0; ++i )
		{
			if ( sp1->pItem_0x4[i].dwItemx27_0xe0->dwUnkown_0x0e )
			{
				*(DWORD *)(sp1->pData_0x14 + 4 * i) = 1;
				++sp1->dwUnkown_0x10;
			}
			else
			{
				*(DWORD *)(sp1->pData_0x14 + 4 * i) = 0;
			}
			if (  sp1->pItem_0x4[i].dwUnkown_0x0 )
			{
				if ( *(DWORD *)(sp1->pData_0x14 + 4 * i) && sub_465040(sp1, i) )
				{
					sp1->dwUnkown_0x24 = 1;
				}
				else if ( 
					sp1->pItem_0x4[i].dwItemx27_0xe0->byteType_0x0c == 11 && 
					sub_45AFE8(sp1->pItem_0x4[i].dwUnkonw_0xd4) ||
					sp1->pItem_0x4[i].dwItemx27_0xe0->dwFlag_0x12 & 0x20 &&
					sp1->pItem_0x4[i].dwUnkonw_0xd0 == 1401 ||
					sp1->pItem_0x4[i].dwUnkonw_0xd0 == 1403
				)
				{
					sp1->dwUnkown_0x24 = 1;
				}
				else if ( sp1->dwUnkown_0x20 == -1 )
				{
					sp1->dwUnkown_0x20 = sp1->pItem_0x4[i].nNodeIdx_0xe4;
				}
				if ( *(DWORD *)(sp1->pData_0x14 + 4 * i) )
					++v3;
			}
		}
		if ( sp1->dwUnkown_0x24 )
		{
			if ( sp1->dwUnkown_0x20 == -1 )
				sp1->dwUnkown_0x20 = sub_4650B5(sp1);
			else
				sp1->dwUnkown_0x24 = 0;
		}
		if (sp1->dwUnkown_0x20 == -1 )
		{
			sp1->dwUnkown_0x20 = sub_4650B5(sp1);
			sp1->dwUnkown_0x24 = 1;
		}
		if ( sp1->dwUnkown_0x20 != -1 )
		{
			v2 = 1;
			sp1->dwUnkown_0x1c = sp1->dwUnkown_0x24 ? 0 : v3;
			if ( sp1->dwUnkown_0x1c )
			{
				sp1->dwUnkown_0x18 = sp1->dwUnkown_0x10;
				v7 = sub_463CF3(sp1, sp1->dwUnkown_0x20);
				if ( *(DWORD *)(sp1->pData_0x14 + 4 * v7) )
				{
					for ( j = 0; j < sp1->nCnt_0x0; ++j )
					{
						if (*(DWORD *)(sp1->pData_0x14 + 4 * j))
						{
							sp1->dwUnkown_0x20 = sp1->pItem_0x4[j].nNodeIdx_0xe4;
							v7 = j;
							break;
						}
					}
				}
				if ( !sp1->pItem_0x4[v7].dwUnkown_0x0 )
					v2 = sub_464C32(sp1);
			}
		}
	}
	else if ( sp1->dwUnkown_0x1c )
	{
		v8 = sub_463CF3(sp1, sp1->dwUnkown_0x20);
		do
		{
			sub_4649F2(sp1, 1);
			if (sp1->dwUnkown_0x18)
			{
				v2 = 1;
			}
			else
			{
				sp1->dwUnkown_0x18 = sp1->dwUnkown_0x10;
				v2 = 0;
				if ( *(DWORD *)(sp1->pData_0x14 + 4 * v8) )
				{
					for ( k = v8 + 1; k < sp1->nCnt_0x0; ++k )
					{
						if ( *(DWORD *)(sp1->pData_0x14 + 4 * k) )
						{
							sp1->dwUnkown_0x20 = sp1->pItem_0x4[i].nNodeIdx_0xe4;
							v8 = k;
							v2 = 1;
							break;
						}
					}
				}
			}
		}
		while ( v2 && !sp1->pItem_0x4[v8].dwUnkown_0x0);
	}

	ASSERT(v2);
	return v2;
}


void *__cdecl sub_465304(sItem_subNode * a1, int a2, gItem_0xEC *a3)
{
	void *result; // eax
	size_t v3 = a3->dwItemx27_0xe0->dwDataLen_0x08;
	
	memcpy(a3->str_unkown_0x6a, (const void *)(*(DWORD *)(a1 + 16) + 8 * a2), v3);
	a3->str_unkown_0x6a[v3] = 0;

	result = memcpy(a3->str_unkown_0x9b, (const void *)(*(DWORD *)(a1 + 16) + 8 * a2), v3);
	a3->str_unkown_0x9b[v3] = 0;

	return result;
}

int __cdecl sub_463D4E(void *a1, gItem_0xEC * a2, int a3)
{
	int result; // eax
	int i; // [esp+0h] [ebp-4h]

	result = (int)memset(a1, 0, 0x13F8u);
	for ( i = 0; i < a3; ++i )
	{
		result = 236 * i;
		
		if ( a2[i].dwUnkown_0x0 )
			result = (int)memcpy(
			(char *)a1 + a2[i].dwItemx27_0xe0->dwId2_0x4,
			(const void *)(a2[i].str_unkown_0x6a),
			a2[i].dwSubLen_0xdc);
	}
	return result;
}

int __cdecl sub_463DDE(void *a1, gItem_0xEC * a2, int a3)
{
	int result; // eax
	int i; // [esp+0h] [ebp-4h]

	result = (int)memset(a1, 0, 0x13F8u);
	for ( i = 0; i < a3; ++i )
	{
		result = 236 * i;

		if ( a2[i].dwUnkown_0x0 )
			result = (int)memcpy(
			(char *)a1 + a2[i].dwItemx27_0xe0->dwId2_0x4,
			(const void *)(a2[i].str_unkown_0x9b),
			a2[i].dwSubLen_0xdc);
	}
	return result;
}

signed int __cdecl IsHasRecord(int a1)
{
	int result;
	if ( GetRecordCnt(a1) )
		result = 0;
	else
		result = -1;
	return result;
}

int __cdecl clone3byte(void *a1)
{
	int v2; // [esp+0h] [ebp-4h]

	v2 = 0;
	memcpy(&v2, a1, 3u);
	return v2;
}

void *__cdecl memcpy3byte(char a1, void *a2)
{
	return memcpy(a2, &a1, 3u);
}

int __cdecl GetRecordSize(int a1)
{
	int v2; // [esp+0h] [ebp-4h]

	if ( g_ItemFileHeader_0xCE[a1].wUnkown_0x86 )
		v2 = g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0  - 3;
	else
		v2 = g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0;

	return v2;
}

sParam2 * __cdecl CloneValue(int a1, sParam2 * a2, sParam2 * a3)
{
	sParam2 * result; // eax
	memcpy(*(void **)a2, a3->strval_0x0,  g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
	a2->dwKnown_0x08 = a3->dwKnown_0x08;
	result = a2;
	a2->dwKnown_0x04 = a3->dwKnown_0x04;
	return result;
}



int __cdecl compareValueWithType(size_t a1, char *a2, char *a3, int a4)
{
	signed __int64 v4; // rax
	int v6; // [esp+4h] [ebp-6Ch]
	char sz[52]; // [esp+8h] [ebp-68h]
	char v8[52]; // [esp+3Ch] [ebp-34h]

	if ( a1 )
	{
		switch ( a4 )
		{
		case 1:
		case 9:
			v4 = strncmp(a2, a3, a1);
			break;
		case 2:
			v4 = (signed __int64)(*(float *)a2 - *(float *)a3);
			break;
		case 3:
			v4 = *(signed __int16 *)a2 - *(signed __int16 *)a3;
			break;
		case 4:
			if ( *(DWORD *)a2 <= *(DWORD *)a3 )
			{
				if ( *(DWORD *)a2 >= *(DWORD *)a3 )
					v4 = 0;
				else
					v4 = -1;
			}
			else
			{
				v4 = 1;
			}
			break;
		case 5:
			v4 = (unsigned __int8)*a2 - (unsigned __int8)*a3;
			break;
		case 7:
			strncpy(sz, a2, a1);
			sz[a1] = 0;
			CharUpperA(sz);
			strncpy(v8, a3, a1);
			v8[a1] = 0;
			CharUpperA(v8);
			v4 = _strcmpi(sz, v8);
			break;
		case 8:
			if ( *(DWORD *)a2 <= *(DWORD *)a3 )
			{
				if ( *(DWORD *)a2 >= *(DWORD *)a3 )
					v4 = 0;
				else
					v4 = -1;
			}
			else
			{
				v4 = 1;
			}
			break;
		case 10:
			if ( a1 )
			{
				v6 = 0;
				while ( a2[v6] == 42 || a3[v6] == 42 || a2[v6] == a3[v6] )
				{
					++v6;
					if ( !--a1 )
						goto LABEL_27;
				}
				v4 = (unsigned __int8)a2[v6] - (unsigned __int8)a3[v6];
			}
			else
			{
LABEL_27:
				v4 = 0;
			}
			break;
		case 11:
			if ( *((DWORD *)a2 + 1) == *((DWORD *)a3 + 1) )
			{
				if ( *(DWORD *)a2 == *(DWORD *)a3 )
				{
					v4 = 0;
				}
				else if ( *(DWORD *)a2 <= *(DWORD *)a3 )
				{
					v4 = -1;
				}
				else
				{
					v4 = 1;
				}
			}
			else if ( *((DWORD *)a2 + 1) <= *((DWORD *)a3 + 1) )
			{
				v4 = -1;
			}
			else
			{
				v4 = 1;
			}
			break;
		case 12:
			if ( *(unsigned __int16 *)a2 <= (signed int)*(unsigned __int16 *)a3 )
			{
				if ( *(unsigned __int16 *)a2 >= (signed int)*(unsigned __int16 *)a3 )
					v4 = 0;
				else
					v4 = -1;
			}
			else
			{
				v4 = 1;
			}
			break;
		default:
			MessageBeep(0);
			ASSERT(0);
			v4 = 0;
			break;
		}
	}
	else
	{
		v4 = 0;
	}
	return v4;
}

int __cdecl GetDataSizeByIdx(int a1)
{
	return g_ItemFileHeader_0xCE[a1].dwNodeSize_0xC;
}

int __cdecl ReadFileRecordData(int nFileIdx, int nNodeIdx, LPVOID lpBuffer)//401c1f
{
	ASSERT(nNodeIdx > 0);
	if ( fseek(g_ItemFileHeader_0xCE[nFileIdx].fHandle_0x10, g_ItemFileHeader_0xCE[nFileIdx].dwNodeSize_0xC * (nNodeIdx - 1) + 0x9E, 0) == -1 )
		return 0;
	if ( g_ItemFileHeader_0xCE[nFileIdx].dwNodeSize_0xC != fread(lpBuffer, 1, g_ItemFileHeader_0xCE[nFileIdx].dwNodeSize_0xC, g_ItemFileHeader_0xCE[nFileIdx].fHandle_0x10))
		return 0;
	return g_ItemFileHeader_0xCE[nFileIdx].dwNodeSize_0xC;
}



BOOL __cdecl sub_464512(char *a1, char *a2, int a3)
{
	int v3; // eax
	size_t v5; // [esp+0h] [ebp-8h]
	BOOL v6; // [esp+4h] [ebp-4h]

	if ( *(BYTE *)a2 )
	{
		while ( *(BYTE *)a2 )
		{
			if ( *(BYTE *)a2 == 8 )
			{
				a2 = (char *)a2 + 1;
				a1 = (char *)a1 + 1;
				v5 = 1;
				v3 = memcmp(a1, a2, 1u);
			}
			else
			{
				v5 = 2;
				v3 = memcmp(a1, a2, 2u);
			}
			v6 = v3 == 0;
			if ( v3 != 0 )
				break;
			a2 = (char *)a2 + v5;
			a1 = (char *)a1 + v5;
		}
	}
	else
	{
		v6 = *(BYTE *)a1 == 0;
	}
	if ( v6 && a3 && *(BYTE *)a1 )
		v6 = 0;
	return v6;
}

char *__cdecl sub_47FFC5(char *a1, char *a2, int a3, int a4)
{
	while ( 1 )
	{
		if ( !_strnicmp(a1, a2, (unsigned __int16)a3) )
			return a1;
		if ( !*a1 || a4 && *a1 == 32 )
			break;
		++a1;
	}
	return 0;
}

char *__cdecl sub_480022(char *a1, char *a2, int a3, int a4)
{
	char *i; // [esp+0h] [ebp-4h]

	if ( !*a1 )
		return 0;
	for ( i = &a1[strlen(a1) - 1]; ; --i )
	{
		if ( !_strnicmp(i, a2, (unsigned __int16)a3) )
			return i;
		if ( i == a1 || a4 && *i == 32 )
			break;
	}
	return 0;
}

BYTE *__cdecl sub_4800A4(BYTE *a1, unsigned __int16 a2)
{
	while ( *a1 && (signed int)a2 > 0 )
	{
		if ( (signed int)(unsigned __int8)*a1 < 128 )
			return a1;
		++a1;
		--a2;
	}
	return 0;
}

BYTE *__cdecl sub_480275(BYTE *a1, unsigned __int16 a2)
{
	BYTE *result; // eax

	while ( 1 )
	{
		result = a1;
		if ( !*a1 )
			break;
		if ( (unsigned __int8)*a1 == a2 + 1 )
		{
			*a1 = -1;
		}
		else if ( (unsigned __int8)*a1 != 255 && (unsigned __int8)*a1 > a2 + 1 )
		{
			--*a1;
		}
		++a1;
	}
	return result;
}

__int16 __cdecl sub_4800EE(unsigned __int8 *a1, unsigned __int16 a2, unsigned __int8 a3)
{
	__int16 v4; // [esp+0h] [ebp-4h]

	v4 = 0;
	while ( *a1 == a3 && (signed int)a2 > 0 )
	{
		++v4;
		++a1;
		--a2;
	}
	return v4;
}

__int16 __cdecl sub_480143(BYTE *a1, unsigned __int16 a2)
{
	__int16 v3; // [esp+0h] [ebp-4h]
	char * aAeiuoaeiou = "aeiuoAEIOU";
	v3 = 0;
	while ( *a1 && (signed int)a2 > 0 )
	{
		if ( strchr(aAeiuoaeiou, (unsigned __int8)*a1) )
			++v3;
		++a1;
		--a2;
	}
	return v3;
}

__int16 __cdecl sub_4801A9(BYTE *a1, unsigned __int16 a2)
{
	__int16 v3; // [esp+0h] [ebp-4h]
	char * asc_4E4414 = "/!@#$%^&*()\[]{}',27h,'\";:?.,<>`~+=_-";
	v3 = 0;
	while ( *a1 && (signed int)a2 > 0 )
	{
		if ( strchr(asc_4E4414, (unsigned __int8)*a1) )
			++v3;
		++a1;
		--a2;
	}
	return v3;
}

__int16 __cdecl sub_48020F(BYTE *a1, unsigned __int16 a2)
{
	__int16 v3; // [esp+0h] [ebp-4h]
	char * a01234556789 = "01234556789";
	v3 = 0;
	while ( *a1 && (signed int)a2 > 0 )
	{
		if ( strchr(a01234556789, (unsigned __int8)*a1) )
			++v3;
		++a1;
		--a2;
	}
	return v3;
}

int __cdecl compareVal(int a1, char *a2, char *a3)
{
	int v3; // ST0C_4
	int v4; // eax
	int result; // eax
	int v6; // ST14_4
	int v8; // [esp+8h] [ebp-8h]

	v3 = g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4;
	v4 = GetRecordSize(a1);
	v8 = compareValueWithType(v4, a2, a3, v3);

	if ( v8 || !g_ItemFileHeader_0xCE[a1].wUnkown_0x86 )
		return v8;

	v6 = g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0 - 3;
	int v7 = clone3byte(&a2[v6]);
	int v9 = clone3byte(&a3[v6]);
	if ( v7 >= v9 )
		result = v7 > v9;
	else
		result = -1;
	return result;
}


__int64 __cdecl sub_47E246(char *a1, char *a2, int a3, int a4)
{
	size_t v4; // eax
	size_t v5; // eax
	int v6; // eax
	int v7; // edx
	int v8; // ecx
	int v9; // ecx
	int v10; // eax
	int v11; // edx
	int v12; // ecx
	void *v13; // eax
	int v14; // edx
	size_t v15; // esi
	__int16 v16; // ax
	unsigned __int16 v17; // ax
	size_t v18; // esi
	__int16 v19; // ax
	__int16 v20; // cx
	int v21; // eax
	int v22; // ecx
	__int16 v23; // ax
	int v24; // ecx
	unsigned __int16 v25; // ST38_2
	int v26; // edx
	unsigned __int16 v27; // ax
	int v28; // eax
	unsigned __int16 v29; // ax
	int v30; // eax
	unsigned __int16 v31; // ax
	int v32; // eax
	unsigned __int16 v33; // ax
	int v34; // eax
	unsigned __int16 v35; // ax
	int v36; // esi
	int v37; // esi
	int v38; // edi
	int v39; // esi
	int v40; // edi
	int v41; // esi
	__int64 result; // rax
	signed __int16 v43; // [esp+8h] [ebp-55Ch]
	BOOL v44; // [esp+Ch] [ebp-558h]
	BOOL v45; // [esp+10h] [ebp-554h]
	unsigned __int16 v46; // [esp+14h] [ebp-550h]
	unsigned __int16 v47; // [esp+18h] [ebp-54Ch]
	unsigned __int16 v48; // [esp+20h] [ebp-544h]
	unsigned __int16 v49; // [esp+24h] [ebp-540h]
	unsigned __int16 v50; // [esp+2Ch] [ebp-538h]
	unsigned __int16 v51; // [esp+30h] [ebp-534h]
	unsigned __int16 v52; // [esp+38h] [ebp-52Ch]
	unsigned __int16 v53; // [esp+3Ch] [ebp-528h]
	unsigned __int16 v54; // [esp+40h] [ebp-524h]
	unsigned __int16 v55; // [esp+44h] [ebp-520h]
	__int16 v56; // [esp+4Ch] [ebp-518h]
	__int16 v57; // [esp+50h] [ebp-514h]
	unsigned __int16 v58; // [esp+58h] [ebp-50Ch]
	unsigned __int16 v59; // [esp+5Ch] [ebp-508h]
	char *v60; // [esp+60h] [ebp-504h]
	char *v61; // [esp+64h] [ebp-500h]
	unsigned __int16 v62; // [esp+68h] [ebp-4FCh]
	unsigned __int16 v63; // [esp+6Ch] [ebp-4F8h]
	unsigned __int16 v64; // [esp+70h] [ebp-4F4h]
	unsigned __int16 v65; // [esp+74h] [ebp-4F0h]
	unsigned __int16 v66; // [esp+78h] [ebp-4ECh]
	unsigned __int8 *v67; // [esp+7Ch] [ebp-4E8h]
	__int16 v68; // [esp+80h] [ebp-4E4h]
	unsigned __int16 v69; // [esp+88h] [ebp-4DCh]
	unsigned __int16 k; // [esp+8Ch] [ebp-4D8h]
	unsigned __int16 v71; // [esp+90h] [ebp-4D4h]
	unsigned __int16 v72; // [esp+94h] [ebp-4D0h]
	unsigned __int16 v73; // [esp+A0h] [ebp-4C4h]
	unsigned __int8 *v74; // [esp+A4h] [ebp-4C0h]
	__int16 v75; // [esp+A8h] [ebp-4BCh]
	unsigned __int16 j; // [esp+ACh] [ebp-4B8h]
	unsigned __int16 v77; // [esp+B0h] [ebp-4B4h]
	unsigned __int16 v78; // [esp+B4h] [ebp-4B0h]
	unsigned __int16 v79; // [esp+B8h] [ebp-4ACh]
	unsigned __int16 v80; // [esp+BCh] [ebp-4A8h]
	unsigned __int16 i; // [esp+C0h] [ebp-4A4h]
	unsigned __int16 v82; // [esp+C4h] [ebp-4A0h]
	unsigned __int16 v83; // [esp+C8h] [ebp-49Ch]
	unsigned __int16 v84; // [esp+D0h] [ebp-494h]
	unsigned __int16 v85; // [esp+D4h] [ebp-490h]
	signed int v86; // [esp+D8h] [ebp-48Ch]
	char *v87; // [esp+DCh] [ebp-488h]
	unsigned __int16 v88; // [esp+E0h] [ebp-484h]
	unsigned __int8 *v89; // [esp+E4h] [ebp-480h]
	unsigned __int16 v90; // [esp+E8h] [ebp-47Ch]
	__int16 v91; // [esp+E8h] [ebp-47Ch]
	signed int v92; // [esp+ECh] [ebp-478h]
	int v93; // [esp+F0h] [ebp-474h]
	int v94; // [esp+F4h] [ebp-470h]
	size_t v95; // [esp+F8h] [ebp-46Ch]
	__int16 v96; // [esp+FCh] [ebp-468h]
	__int16 v97[233]; // [esp+FEh] [ebp-466h]
	char v98[256]; // [esp+2D0h] [ebp-294h]
	char *v99; // [esp+3D0h] [ebp-194h]
	char *v100; // [esp+3D4h] [ebp-190h]
	int v101; // [esp+3D8h] [ebp-18Ch]
	char *v102; // [esp+3DCh] [ebp-188h]
	int v103; // [esp+3E0h] [ebp-184h]
	__int16 v104; // [esp+3E4h] [ebp-180h]
	__int16 v105; // [esp+3E6h] [ebp-17Eh]
	char v106[116]; // [esp+3E8h] [ebp-17Ch]
	char v107[256]; // [esp+45Ch] [ebp-108h]
	int v108; // [esp+55Ch] [ebp-8h]
	int v109; // [esp+560h] [ebp-4h]
	int savedregs; // [esp+564h] [ebp+0h]

	v109 = 0;
	v101 = 0;
	v99 = a2;
	v100 = a1;
	v92 = 1;
	v90 = 0;
	v4 = strlen(a1);
	memset(v107, 255, v4);
	v107[strlen(a1)] = 0;
	v5 = strlen(a2);
	memset(v98, 255, v5);
	v98[strlen(a2)] = 0;
	while ( *v99 && (signed int)(unsigned __int16)v109 < 30 )
	{
		v6 = strlen(v99);
		v103 = v6;
		while ( (signed int)(unsigned __int16)v103 > 0 )
		{
			if ( v92 )
			{
				v7 = v103;
				v6 = (int)sub_47FFC5(v100, v99, v7, 0);
				v102 = (char *)v6;
				v7 = HIWORD(v6);
			}
			else
			{
				v6 = v103;
				v6 = (int)sub_480022(a1, v99, v6, 0);
				v102 = (char *)v6;
			}
			if ( v6 )
			{
				v8 = v103;
				v89 = (unsigned __int8 *)sub_4800A4((BYTE*)&v107[v102 - a1], v8);
				if ( !v89 )
					goto LABEL_14;
				v88 = *v89 - 1;
				v6 = v88;
				v7 = (unsigned __int16)v103;
				if ( (unsigned __int16)*(&v105 + 2 * v88) < (signed int)(unsigned __int16)v103 )
				{
					memcpy(&v104 + 2 * v88, &v106[4 * v88], 4 * ((unsigned __int16)v109 - v88) - 4);
					v9 = v88;
					v10 = (int)sub_480275((BYTE*)v107, v9);
					v10 = v88;
					sub_480275((BYTE*)v98, v10);
					v109 = v109 - 1;
LABEL_14:
					if ( strncmp(v102, v99, (unsigned __int16)v103) )
						v90 += v103;
					*(&v105 + 2 * (unsigned __int16)v109) = v103;
					*(&v104 + 2 * (unsigned __int16)v109) = (WORD)v102 - (WORD)a1;
					memset(&v107[v102 - a1], (unsigned __int8)v109 + 1, (unsigned __int16)v103);
					memset(&v98[v99 - a2], (unsigned __int8)v109 + 1, (unsigned __int16)v103);
					v109 = v109 + 1;
					v99 += (unsigned __int16)v103;
					v100 = &v102[(unsigned __int16)v103];
					v92 = 1;
					break;
				}
			}
			v103 = v103 - 1;
		}
		if ( !(WORD)v103 )
		{
			if ( v92 )
				v92 = 0;
			else
				++v99;
		}
	}
	v87 = v98;
	v86 = 0;
	while ( *v87 )
	{
		if ( (unsigned __int8)*v87 == 255 )
		{
			++v87;
		}
		else
		{
			v85 = (unsigned __int8)*v87 - 1;
			v84 = *(&v105 + 2 * v85);
			if ( (signed int)v84 <= 2 )
			{
				if ( (signed int)v85 > 0
					&& (unsigned __int16)*(&v104 + 2 * (unsigned __int16)((unsigned __int8)*v87 - 2)) > v84
					+ (unsigned __int16)*(&v104 + 2 * (unsigned __int16)((unsigned __int8)*v87 - 1)) )
				{
					v83 = *(&v104 + 2 * (unsigned __int16)((unsigned __int8)*v87 - 2))
						- (v84
						+ *(&v104 + 2 * (unsigned __int16)((unsigned __int8)*v87 - 1)));
					v82 = 0;
					for ( i = 0; i < (signed int)v83; ++i )
					{
						if ( a1[i + v84 + (unsigned __int16)*(&v104 + 2 * v85)] == 32 )
							++v82;
					}
					if ( (signed int)v82 > 0 || v83 > (signed int)(unsigned __int16)((signed int)v84 <= 1 ? 4 : 6) )
					{
						memcpy(&v104 + 2 * v85, &v106[4 * v85], 4 * ((unsigned __int16)v109 - v85) - 4);
						v11 = v85;
						sub_480275((BYTE*)v107, v11);
						v12 = v85;
						sub_480275((BYTE*)v98, v12);
						v109 = v109 - 1;
						v86 = 1;
					}
				}
				if ( !v86 && v85 < (unsigned __int16)v109 - 1 )
				{
					v80 = v85 + 1;
					v79 = *(&v105 + 2 * (unsigned __int16)(v85 + 1));
					if ( v79 + (unsigned __int16)*(&v104 + 2 * (unsigned __int16)(v85 + 1)) < (unsigned __int16)*(&v104 + 2 * v85) )
					{
						v78 = *(&v104 + 2 * v85) - (v79 + *(&v104 + 2 * v80));
						v77 = 0;
						for ( j = 0; j < (signed int)v78; ++j )
						{
							if ( a1[j + v79 + (unsigned __int16)*(&v104 + 2 * v80)] == 32 )
								++v77;
						}
						if ( (signed int)v77 > 0 || v78 > (signed int)(unsigned __int16)((signed int)v84 <= 1 ? 4 : 6) )
						{
							v13 = memcpy(&v104 + 2 * v85, &v106[4 * v85], 4 * ((unsigned __int16)v109 - v85) - 4);
							v13 = (void*)v85;
							sub_480275((BYTE*)v107, (unsigned __int16)v13);
							v14 = v85;
							sub_480275((BYTE*)v98, v14);
							v109 = v109 - 1;
							v86 = 1;
						}
					}
				}
			}
			v87 += v84;
		}
	}
	v75 = 0;
	for ( v103 = 0; ; v103++ )
	{
		v15 = (unsigned __int16)v103;
		if ( v15 >= strlen(a2) || (signed int)(unsigned __int16)v101 >= 30 )
			break;
		if ( (unsigned __int8)v98[(unsigned __int16)v103] == 255 )
		{
			*(&v96 + 8 * (unsigned __int16)v101) = v75;
			*(&v93 + 4 * (unsigned __int16)v101) = (int)&a2[(unsigned __int16)v103];
			v74 = (unsigned __int8 *)sub_4800A4((BYTE*)&v98[(unsigned __int16)v103], 10000);
			if ( v74 )
			{
				v97[8 * (unsigned __int16)v101] = *v74 - 1;
				*((WORD *)&v95 + 8 * (unsigned __int16)v101) = (WORD)v74 - (unsigned int)(&savedregs - 165) - v103;
			}
			else
			{
				v97[8 * (unsigned __int16)v101] = 0;
				v16 = strlen(a2);
				*((WORD *)&v95 + 8 * (unsigned __int16)v101) = v16 - v103;
			}
			v73 = *(&v96 + 8 * (unsigned __int16)v101);
			v72 = v97[8 * (unsigned __int16)v101];
			if ( v73 )
				v47 = *(&v105 + 2 * v73) + *(&v104 + 2 * v73);
			else
				v47 = 0;
			if ( v72 )
				v46 = *(&v104 + 2 * v72);
			else
				v46 = strlen(a1);
			if ( v46 >= (signed int)v47 )
			{
				v69 = 0;
				v71 = 0;
				for ( k = v47; k < (signed int)v46; ++k )
				{
					if ( (unsigned __int8)v107[k] == 255 )
					{
						v17 = sub_4800EE((unsigned char*)&v107[k], v46 - k, 255);
						if ( v17 > (signed int)v69 )
						{
							v69 = v17;
							v71 = k;
							k += v17;
						}
					}
				}
				if ( v71 )
				{
					*(&v94 + 4 * (unsigned __int16)v101) = (int)&a1[v71];
					*((WORD *)&v95 + 8 * (unsigned __int16)v101 + 1) = v69;
				}
				else
				{
					*(&v94 + 4 * (unsigned __int16)v101) = (int)a1;
					*((WORD *)&v95 + 8 * (unsigned __int16)v101 + 1) = 0;
				}
			}
			else
			{
				*(&v94 + 4 * (unsigned __int16)v101) = (int)a1;
				*((WORD *)&v95 + 8 * (unsigned __int16)v101 + 1) = 0;
			}
			memset(
				&v98[*(&v93 + 4 * (unsigned __int16)v101) - (DWORD)a2],
				(unsigned __int8)v101 + 128,
				*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v101));
			memset(
				&v107[*(&v94 + 4 * (unsigned __int16)v101) - (DWORD)a1],
				(unsigned __int8)v101 + 128,
				*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v101 + 1));
			v103 = *((WORD *)&v95 + 8 * (unsigned __int16)v101) + v103;
			v101 = v101 + 1;
		}
		else
		{
			v75 = (unsigned __int8)v98[(unsigned __int16)v103] - 1;
		}
	}
	v68 = 0;
	for ( v103 = 0; ; ++v103)
	{
		v18 = (unsigned __int16)v103;
		if ( v18 >= strlen(a1) || (signed int)(unsigned __int16)v101 >= 30 )
			break;
		if ( (unsigned __int8)v107[(unsigned __int16)v103] == 255 )
		{
			*(&v96 + 8 * (unsigned __int16)v101) = v68;
			*(&v94 + 4 * (unsigned __int16)v101) = (int)&a1[(unsigned __int16)v103];
			v67 = (unsigned __int8 *)sub_4800A4((BYTE*)&v107[(unsigned __int16)v103], 10000);
			if ( v67 )
			{
				v97[8 * (unsigned __int16)v101] = *v67 - 1;
				*((WORD *)&v95 + 8 * (unsigned __int16)v101 + 1) = (WORD)v67 - (unsigned int)(&savedregs - 66) - v103;
			}
			else
			{
				v97[8 * (unsigned __int16)v101] = 0;
				v19 = strlen(a1);
				*((WORD *)&v95 + 8 * (unsigned __int16)v101 + 1) = v19 - v103;
			}
			*(&v93 + 4 * (unsigned __int16)v101) = (int)a2;
			*((WORD *)&v95 + 8 * (unsigned __int16)v101) = 0;
			memset(
				&v107[*(&v94 + 4 * (unsigned __int16)v101) - (DWORD)a1],
				(unsigned __int8)v101 + 128,
				*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v101 + 1));
			v103 = *((WORD *)&v95 + 8 * (unsigned __int16)v101 + 1) + v103;
			v101 = v101 + 1;
		}
		else if ( (signed int)(unsigned __int8)v107[(unsigned __int16)v103] < 128 )
		{
			v68 = (unsigned __int8)v107[(unsigned __int16)v103] - 1;
		}
	}
	v60 = v107;
	v61 = v98;
	v66 = 0;
	v63 = 0;
	v65 = 100;
	v64 = 100;
	v62 = strlen(v107);
	while ( *v60 )
	{
		if ( (signed int)(unsigned __int8)*v60 < 128 )
			++v66;
		++v60;
	}
	while ( *v61 )
	{
		if ( (signed int)(unsigned __int8)*v61 < 128 )
			++v63;
		++v61;
	}
	if ( (signed int)v62 > 0 )
		v65 = 100 * v66 / v62;
	if ( strlen(v98) )
		v64 = 100 * (unsigned int)v63 / strlen(v98);
	v108 = 100 * (100 - v65) / (v64 + 1);
	if ( (signed int)(unsigned __int16)v109 >= 30 || (signed int)(unsigned __int16)v101 >= 30 )
		v90 = 100;
	v103 = 0;
	while ( (unsigned __int16)v103 < (signed int)(unsigned __int16)v101 )
	{
		if ( *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1) )
		{
			if ( *((WORD *)&v95 + 8 * (unsigned __int16)v103) )
			{
				v22 = *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v25 = sub_480143((BYTE*)*(&v94 + 4 * (unsigned __int16)v103), v22);
				v26 = *((WORD *)&v95 + 8 * (unsigned __int16)v103);
				v27 = sub_480143((BYTE*)*(&v93 + 4 * (unsigned __int16)v103), v26);
				v50 = 100 * v25 / *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v28 = 100 * v27 / *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103);
				v52 = v28;
				v28 = *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v29 = sub_4801A9((BYTE*)*(&v94 + 4 * (unsigned __int16)v103), v28);
				v30 = 100 * v29 / *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v55 = v30;
				v30 = *((WORD *)&v95 + 8 * (unsigned __int16)v103);
				v31 = sub_4801A9((BYTE*)*(&v93 + 4 * (unsigned __int16)v103), v30);
				v32 = 100 * v31 / *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103);
				v54 = v32;
				v32 = *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v33 = sub_48020F((BYTE*)*(&v94 + 4 * (unsigned __int16)v103), v32);
				v34 = 100 * v33 / *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v53 = v34;
				v34 = *((WORD *)&v95 + 8 * (unsigned __int16)v103);
				v35 = sub_48020F((BYTE*)*(&v93 + 4 * (unsigned __int16)v103), v34);
				v51 = 100 * v35 / *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103);
				if ( (!a3
					|| *(BYTE *)*(&v93 + 4 * (unsigned __int16)v103) != 42
					|| *((WORD *)&v95 + 8 * (unsigned __int16)v103) != 1)
					&& (!a3
					|| *(BYTE *)*(&v93 + 4 * (unsigned __int16)v103) != 63
					|| *((WORD *)&v95 + 8 * (unsigned __int16)v103) != 1
					|| *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1) != 1) )
				{
					v36 = *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103);
					v37 = (abs(v50 - v52) / 30 + 1) * v36;
					v38 = *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103);
					v39 = 2 * abs(v55 - v54) / 20 * v38 + 2 * v37;
					v40 = *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103);
					v41 = v39
						+ 2 * abs(v53 - v51) / 25 * v40
						+ 4 * v40
						- 4
						+ 4 * *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103 + 1)
						- 4;
					v90 += v41
						+ 2
						* abs(
						*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103)
						- *((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103 + 1))
						+ 2;
				}
			}
			else
			{
				v23 = *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v57 = sub_4800EE((unsigned char*)*(&v94 + 4 * (unsigned __int16)v103), 16 * (unsigned __int16)v103, 32);
				v24 = *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1);
				v56 = sub_4801A9((BYTE*)*(&v94 + 4 * (unsigned __int16)v103), v24);
				v44 = !v97[8 * (unsigned __int16)v103] || !*(&v96 + 8 * (unsigned __int16)v103);
				if ( v44 )
				{
					if ( !a4 )
					{
						if ( (signed int)*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103 + 1) >= 5 )
							v43 = 5;
						else
							v43 = *((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1);
						v90 += v43;
					}
				}
				else
				{
					v90 += 8 * v56 + 6 * (*((WORD *)&v95 + 8 * (unsigned __int16)v103 + 1) - v57 - v56) + 2 * v57;
				}
			}
		}
		else
		{
			v20 = *((WORD *)&v95 + 8 * (unsigned __int16)v103);
			v58 = sub_4800EE((unsigned char*)*(&v93 + 4 * (unsigned __int16)v103), 16 * (unsigned __int16)v103, 32);
			v45 = !v97[8 * (unsigned __int16)v103] || !*(&v96 + 8 * (unsigned __int16)v103);
			v59 = ((signed int)*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103) > 1) + 1;
			if ( !a3
				|| *(BYTE *)*(&v93 + 4 * (unsigned __int16)v103) != 42
				|| *((WORD *)&v95 + 8 * (unsigned __int16)v103) != 1 )
			{
				if ( v45 )
				{
					v91 = v58 + v90;
					v21 = (*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103) - v58) * 2 * v59;
				}
				else
				{
					v91 = v58 * 2 * v59 + v90;
					v21 = (*((unsigned __int16 *)&v95 + 8 * (unsigned __int16)v103) - v58) * 6 * v59;
				}
				v90 = v21 + v91;
			}
		}
		v103 = v103 + 1;
	}
	v49 = 0;
	v48 = 0;
	v103 = 0;
	while ( (unsigned __int16)v103 < (signed int)(unsigned __int16)v109 )
	{
		if ( (unsigned __int16)*(&v104 + 2 * (unsigned __int16)v103) < (signed int)v49 )
			v90 += (unsigned int)(25
			* (v49 - (unsigned __int16)*(&v104 + 2 * (unsigned __int16)v103))
			/ (v48 * (unsigned __int16)*(&v105 + 2 * (unsigned __int16)v103) + 1))
			+ 5;
		v49 = *(&v104 + 2 * (unsigned __int16)v103) + *(&v105 + 2 * (unsigned __int16)v103) - 1;
		v48 = *(&v105 + 2 * (unsigned __int16)v103);
		v103 = v103 + 1;
	}
	if ( !(WORD)v109 )
		v90 += 100;
	if ( strlen(a2) )
		v90 = 15 * (unsigned int)v90 / strlen(a2);
	if ( strlen(a1) > 0xA )
		v90 = 15 * (unsigned int)v90 / strlen(a1);
	if ( strlen(a1) < 5 && strlen(a1) )
		v90 = 5 * (unsigned int)v90 / strlen(a1);
	*(DWORD*)&result = ((unsigned __int16)v108 + 2 * v90) / 3;
	*(DWORD*)&((DWORD*)&result)[1] = ((unsigned __int16)v108 + 2 * v90) % 3;
	return result;
}

bool __cdecl sub_47E0C0(char *a1, char *a2, int a3, int a4, int a5)
{
	unsigned __int16 v6; // [esp+0h] [ebp-14h]
	unsigned __int16 v7; // [esp+0h] [ebp-14h]
	char *v8; // [esp+4h] [ebp-10h]
	char *v9; // [esp+8h] [ebp-Ch]
	unsigned __int16 v10; // [esp+Ch] [ebp-8h]
	char *i; // [esp+10h] [ebp-4h]

	v10 = 1000;
	if ( (unsigned __int16)a5 == 100 )
		return 1;
	for ( i = a1; *i; ++i )
	{
		if ( (signed int)(unsigned __int8)*i < 32 )
			*i = 32;
	}
	if ( strchr(a1, 32) && a4 )
	{
		v8 = a1;
		do
		{
			v9 = strchr(v8, 32);
			if ( v9 )
				*v9++ = 0;
			v6 = sub_47E246(v8, a2, a3, 0);
			if ( v6 < (signed int)v10 )
				v10 = v6;
			if ( v10 <= (signed int)(unsigned __int16)a5 )
				return 1;
			if ( v9 )
				v8 = v9;
		}
		while ( v9 );
		v7 = sub_47E246(a1, a2, a3, a4);
		if ( v7 < (signed int)v10 )
			v10 = v7;
	}
	else
	{
		v10 = sub_47E246(a1, a2, a3, a4);
	}
	return v10 <= (signed int)(unsigned __int16)a5;
}


void __cdecl freeBuffer(LPVOID lpMem)
{
	if ( lpMem )
	{
		free(lpMem);
	}
}

int __cdecl releaseBuffer()
{
	int result; // eax
	signed int i; // [esp+0h] [ebp-4h]

	for ( i = 0; i < 20; ++i )
	{
		if ( word_4F2C92[3 * i] )
			freeBuffer(*(LPVOID *)((char *)dword_4F2C94 + 6 * i));
		word_4F2C92[3 * i] = 0;
		*(DWORD *)((char *)dword_4F2C94 + 6 * i) = 0;
		result = i + 1;
	}
	return result;
}


CHAR *__cdecl sub_401F68(int a1, int a2)
{
	signed int v3; // [esp+0h] [ebp-Ch]
	signed int v4; // [esp+4h] [ebp-8h]
	unsigned int v5; // [esp+8h] [ebp-4h]

	v3 = 0;
	v5 = dword_4DC040;
	v4 = 0;
	while ( v3 < 5 )
	{		
		if ( g_fileData_0x30A_4F2D10[v3].dwUnkown_0x04 == a2 && g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0 == a1 )
		{
			v4 = v3;
			g_fileData_0x30A_4F2D10[v3].dwUnkown_0x08 = 0;
			break;
		}
		if ( v5 > g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0c )
		{
			v4 = v3;
			v5 = g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0c;
		}
		if ( !g_fileData_0x30A_4F2D10[v3].dwUnkown_0x04 )
			break;
		++v3;
	}

	g_fileData_0x30A_4F2D10[v4].dwUnkown_0x04 = a2;
	g_fileData_0x30A_4F2D10[v4].dwUnkown_0x0 = a1;
	g_fileData_0x30A_4F2D10[v4].dwUnkown_0x08 = 1;
	g_fileData_0x30A_4F2D10[v4].dwUnkown_0x0c = dword_4DC040++;
	return &g_fileData_0x30A_4F2D10[v3].byteRecordData_0x10[0];
}


char *__cdecl GetRecordBuffer(int a1, int a2)
{
	signed int v3; // [esp+0h] [ebp-Ch]
	signed int v4; // [esp+4h] [ebp-8h]
	unsigned int v5; // [esp+8h] [ebp-4h]

	v3 = 0;
	v5 = dword_4DC040;
	v4 = 0;
	while ( v3 < 5 )
	{	
		if ( g_fileData_0x30A_4F2D10[v3].dwUnkown_0x04 == a2 && 
			g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0 == a1)
		{
			g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0c = dword_4DC040++;

			return &g_fileData_0x30A_4F2D10[v3].byteRecordData_0x10[0];
		}
		if ( v5 > g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0c )
		{
			v5 = g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0c;
			v4 = v3;
		}
		if ( !g_fileData_0x30A_4F2D10[v3].dwUnkown_0x04 )
			break;
		++v3;
	}

	if ( !ReadFileRecordData(a1, a2, &g_fileData_0x30A_4F2D10[v3].byteRecordData_0x10[0]) )
		return 0;
	g_fileData_0x30A_4F2D10[v3].dwUnkown_0x04 = a2;
	g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0 = a1;
	g_fileData_0x30A_4F2D10[v3].dwUnkown_0x08 = 0;
	g_fileData_0x30A_4F2D10[v3].dwUnkown_0x0c = dword_4DC040++;
	return &g_fileData_0x30A_4F2D10[v3].byteRecordData_0x10[0];
}


void *__cdecl mallocBuffer(size_t a1)
{
	signed int i; // [esp+0h] [ebp-8h]
	void *v3; // [esp+4h] [ebp-4h]

	v3 = malloc(a1);
	if ( !v3 )
	{
		ASSERT(0);
	}
	memset(v3, 0, a1);
	for ( i = 0; i < 20 && word_4F2C92[3 * i]; ++i )
		;
	if ( i == 20 )
	{
		ASSERT(0);
	}
	word_4F2C92[3 * i] = 1;
	*(DWORD *)((char *)dword_4F2C94 + 6 * i) = (DWORD)v3;
	return v3;
}


signed int __cdecl sub_402667(int a1, int a2, sParam1 *a3)
{
	//WORD* wPtr = (WORD*)a3;
	char *v4; // ST18_4
	char *v5; // ST18_4
	size_t v6; // [esp+0h] [ebp-10h]
	char *v7; // [esp+4h] [ebp-Ch]
	signed int i; // [esp+8h] [ebp-8h]
	char *v9; // [esp+Ch] [ebp-4h]
	char *v10; // [esp+Ch] [ebp-4h]

	v9 = GetRecordBuffer(a1, a2);
	if ( !v9 )
		return -1;
	v6 = g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0;
	v7 = (char*)mallocBuffer(0xE * (v6 + 1));
	a3->wCnt_0x0 = (unsigned __int8)*v9;
	v4 = v9 + 1;
	a3->nUnkown_0x02 = clone3byte(v4);
	v10 = v4 + 3;
	for ( i = 0; i < 0xE; ++i )
	{
		a3->sP2Data_0x6[i].strval_0x0 = &v7[(v6 + 1) * i];
		if ( i < a3->wCnt_0x0 )
		{
			memcpy(a3->sP2Data_0x6[i].strval_0x0, v10, v6);
			v5 = &v10[v6];
			a3->sP2Data_0x6[i].dwKnown_0x08 = clone3byte(v5);
			v5 += 3;
			a3->sP2Data_0x6[i].dwKnown_0x04 = clone3byte(v5);
			v10 = v5 + 3;
		}
	}
	return 0;
}

signed int __cdecl sub_4027A1(int a1, int a2, sParam1 *a3)
{
	//WORD * wPtr = (WORD *)a3;
	char *v4; // ST14_4
	char *v5; // ST14_4
	size_t v6; // [esp+0h] [ebp-Ch]
	signed int i; // [esp+4h] [ebp-8h]
	CHAR *v8; // [esp+8h] [ebp-4h]
	char *v9; // [esp+8h] [ebp-4h]

	v8 = sub_401F68(a1, a2);
	if ( !v8 )
		return -1;
	v6 = g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0;
	*v8 = a3->wCnt_0x0;
	v4 = v8 + 1;
	memcpy3byte(a3->nUnkown_0x02, v4);
	v9 = v4 + 3;
	for ( i = 0; i < 14; ++i )
	{
		if ( i < a3->wCnt_0x0 )
		{
			memcpy(v9, a3->sP2Data_0x6[i].strval_0x0, v6);
			v5 = &v9[v6];
			memcpy3byte(a3->sP2Data_0x6[i].dwKnown_0x08, v5);
			v5 += 3;
			memcpy3byte( a3->sP2Data_0x6[i].dwKnown_0x04, v5);
			v9 = v5 + 3;
		}
	}
	return 0;
}

signed int __cdecl sub_401371(int a1)
{
	void *lpBuffer; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	if ( !bInitFlag )
		InitGlobleBuffer();
	g_ItemFileHeader_0xCE[a1].dwNodeCnt_0x16++;

	word_4F2D0A = 1;

	if ( !g_ItemFileHeader_0xCE[a1].dwUnkown_0x1E )
		return g_ItemFileHeader_0xCE[a1].dwNodeCnt_0x16;
	v3 =g_ItemFileHeader_0xCE[a1].dwUnkown_0x1E;
	if ( g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4 == 6 )
	{
		lpBuffer = malloc(g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
		if ( !lpBuffer )
		{
			ASSERT(0);
			//OutputDebugStringA(aMallocFails_0);
			return -1;
		}
		if ( !ReadFileRecordData(a1, v3, lpBuffer) )
		{
			freeBuffer(lpBuffer);
			return -1;
		}
	}
	else
	{
		lpBuffer = GetRecordBuffer(a1, v3);
		if ( !lpBuffer )
			return -1;
	}
	memcpy((char *)&g_ItemFileHeader_0xCE[a1].dwUnkown_0x1E, lpBuffer, 4u);
	if ( g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4 == 6 )
	{	
		freeBuffer(lpBuffer);
	}
	return v3;
}

signed int __cdecl sub_4028E5(int a1, sParam1 * a2)
{
	//int nPtr = (int)a2;
	signed int i; // [esp+0h] [ebp-8h]
	char *v4; // [esp+4h] [ebp-4h]

	v4 = (char *)mallocBuffer(14 * (g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0 + 1));
	a2->wCnt_0x0 = 0;
	a2->nUnkown_0x02 = 0;
	for ( i = 0; i < 14; ++i )
	{
		a2->sP2Data_0x6[i].strval_0x0 = &v4[(g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0 + 1) * i];
		a2->sP2Data_0x6[i].dwKnown_0x04 = 0;
		a2->sP2Data_0x6[i].dwKnown_0x08 = 0;
	}
	return sub_401371(a1);
}

signed int __cdecl sub_402CF3(int idx, sParam1 *ap2, sParam2 * a3, signed int a4, sParam2 * a5)
{
	sParam1 spV6;
	//__int16 & v6 = spV6.wCnt_0x0; // [esp+0h] [ebp-B8h]
	//int & v7 = spV6.nUnkown_0x02; // [esp+2h] [ebp-B6h]
	//char v8[170]; // [esp+6h] [ebp-B2h]
	int i; // [esp+B0h] [ebp-8h]
	int v10; // [esp+B4h] [ebp-4h]
	int v11; // [esp+CCh] [ebp+14h]

	if ( ap2->wCnt_0x0 >= 14 )
	{
		word_4F3C42 = 1;
		v10 = sub_4028E5(idx, &spV6);
		if ( v10 == -1 )
			return -1;
		if ( a4 >= 7 )
		{
			v11 = a4 - 7;
			CloneValue(idx, a5, &spV6.sP2Data_0x6[7]);
			for ( i = 0; i < v11; ++i )
				CloneValue(idx, &spV6.sP2Data_0x6[i], &spV6.sP2Data_0x6[i+8]);
			CloneValue(idx, &spV6.sP2Data_0x6[v11], a3);
			for ( i = v11 + 1; i < 7; ++i )
				CloneValue(idx, &spV6.sP2Data_0x6[i], &spV6.sP2Data_0x6[i+7]);
		}
		else
		{
			if ( a4 == 6 )
			{
				CloneValue(idx, a5, a3);
			}
			else
			{
				CloneValue(idx, a5, &spV6.sP2Data_0x6[6]);
				for ( i = 6; i >= a4 + 2; --i )
					CloneValue(idx, &spV6.sP2Data_0x6[i], &spV6.sP2Data_0x6[i - 1]);
				CloneValue(idx, &spV6.sP2Data_0x6[a4+1], a3);
			}
			for ( i = 0; i < 7; ++i )
				CloneValue(idx, &spV6.sP2Data_0x6[i], &spV6.sP2Data_0x6[i+7]);
		}
		spV6.wCnt_0x0 = 7;
		ap2->wCnt_0x0 = 7;
		spV6.nUnkown_0x02 = *(DWORD *)(a5 + 8);
		*(DWORD *)(a5 + 8) = v10;
		if ( sub_4027A1(idx, v10, &spV6) )
			return -1;
	}
	else
	{
		++ap2->wCnt_0x0;
		word_4F2C8C = 0;
		for ( i = ap2->wCnt_0x0 - 1; i >= a4 + 2; --i )
			CloneValue(idx, &ap2->sP2Data_0x6[i], &ap2->sP2Data_0x6[i - 1]);
		CloneValue(idx, &ap2->sP2Data_0x6[a4+1], a3);
	}
	return 0;
}

signed int __cdecl sub_4029FB(int a1, sParam1 *ap2, sParam2 * a3, int a4)
{
	//signed __int16 * wPtr = (signed __int16 * )ap2;
	ASSERT(a1 < 0x100);
	int v5; // [esp+0h] [ebp-10Ch]
	int v6; // [esp+8h] [ebp-104h]
	char v71[0x34]; // [esp+Ch] [ebp-100h]
	int v8; // [esp+40h] [ebp-CCh]
	sParam1 spV9;
	//char v9[0xb0]; // [esp+44h] [ebp-C8h]
	int v10; // [esp+F4h] [ebp-18h]
	sParam2 v11;
	//char *v11; // [esp+F8h] [ebp-14h]
	int v12; // [esp+104h] [ebp-8h]
	int v13; // [esp+108h] [ebp-4h]

	v11.strval_0x0 = &v71[0];
	if ( a4 )
	{
		v12 = 0;
		v13 = ap2->wCnt_0x0 - 1;
		do
		{
			v6 = (v13 + v12) / 2;
			v10 = compareVal(a1, (char*)byte_4F2BA0, ap2->sP2Data_0x6[v6].strval_0x0);
			if ( v10 <= 0 )
				v13 = v6 - 1;
			if ( v10 >= 0 )
				v12 = v6 + 1;
		}
		while ( v13 >= v12 );
		if ( v10 )
		{
			if ( compareVal(a1, (char*)byte_4F2BA0, ap2->sP2Data_0x6[0].strval_0x0) >= 0 )
				v5 = ap2->sP2Data_0x6[v6].dwKnown_0x08;
			else
				v5 = ap2->nUnkown_0x02;
			v8 = v5;
			if ( v5 )
			{
				g_ItemFileHeader_0xCE[a1].dataArr_0x28[g_ItemFileHeader_0xCE[a1].wIdxMax_0x26++] = v8;
				if ( sub_402667(a1, v8, &spV9) )
					return -1;
			}
			if ( sub_4029FB(a1, &spV9, &v11, v8) )
				return -1;
			if ( word_4F2C8C && word_4F3C7C )
			{
				if ( sub_402CF3(a1, ap2, &v11, v13, a3) )
					return -1;
				if ( sub_4027A1(a1, a4, ap2) )
					return -1;
			}
			if ( !word_4F3C7C )
				word_4F2C8C = 0;
		}
		else
		{
			dword_4F2C88 = ap2->sP2Data_0x6[v6].dwKnown_0x04;
			memcpy(
				(char *)&g_ItemFileHeader_0xCE[a1].data_0x50,
				byte_4F2BA0,
				g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0
				);
			word_4F2C8C = 0;
		}
	}
	else
	{
		word_4F2C8C = 1;
		memcpy(
			(char *)&g_ItemFileHeader_0xCE[a1].data_0x50,
			byte_4F2BA0,
			g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
		memcpy(a3->strval_0x0, byte_4F2BA0, g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
		a3->dwKnown_0x08 = 0;
		a3->dwKnown_0x04 = (DWORD)dword_4EE0E0;
		if ( word_4F3C7C )
		{
			++g_ItemFileHeader_0xCE[a1].dwUnkown_0x1A;
			dword_4F2C88 = (DWORD)dword_4EE0E0;
		}
	}
	return 0;
}

int __cdecl sub_402414(int a1, void *pData, void *arg_8)
{
	int v4; // [esp+0h] [ebp-4h]

	if ( !bInitFlag )
		InitGlobleBuffer();

	word_4F3C42 = 0;
	dword_4F2C88 = 0;
	ASSERT(g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0 <= 0x38);
	memcpy(byte_4F2BA0, pData, g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
	if ( g_ItemFileHeader_0xCE[a1].wUnkown_0x86 )
		memcpy3byte((char)arg_8, (char *)&unk_4F2B9D[0] + g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
	dword_4EE0E0 = arg_8;
	memset((char *)&g_ItemFileHeader_0xCE[a1].dataArr_0x28[0], 0, 0x28u);
	memset((char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0], 0, 0x31u);
	g_ItemFileHeader_0xCE[a1].dataArr_0x28[0] = g_ItemFileHeader_0xCE[a1].dwUnkown_0x22;
	g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 = 1;

	if (g_ItemFileHeader_0xCE[a1].dwNodeCnt_0x16 
		&& sub_402667(a1, g_ItemFileHeader_0xCE[a1].dwUnkown_0x22, &g_data_4EE0E8) )
	{
		return -1;
	}
	ASSERT(a1 < 0x100);
	if ( sub_4029FB(a1, &g_data_4EE0E8, &dword_4F2BD8, g_ItemFileHeader_0xCE[a1].dwUnkown_0x22) )
		return -1;
	if ( !word_4F2C8C )
		goto LABEL_21;
	if ( g_ItemFileHeader_0xCE[a1].dwNodeCnt_0x16 
		&& sub_4027A1(a1,g_ItemFileHeader_0xCE[a1].dwUnkown_0x22, &g_data_4EE0E8) )
	{
		return -1;
	}
	v4 = g_ItemFileHeader_0xCE[a1].dwUnkown_0x22;
	g_ItemFileHeader_0xCE[a1].dwUnkown_0x22 = sub_4028E5(a1, &g_data_4EE0E8);
	if ( g_ItemFileHeader_0xCE[a1].dwUnkown_0x22 == -1 )
		return -1;
	g_data_4EE0E8.wCnt_0x0 = 1;
	dword_4EE0EA = v4;
	CloneValue(a1, &g_data_4EE0E8.sP2Data_0x6[0], &dword_4F2BD8);
	if ( sub_4027A1(a1, g_ItemFileHeader_0xCE[a1].dwUnkown_0x22, &g_data_4EE0E8) )
		return -1;
LABEL_21:
	releaseBuffer();
	return dword_4F2C88;
}

int __cdecl sub_404ABD(int a1, int a2, void *a3)
{
	int v4; // eax
	int v5; // [esp+4h] [ebp-B4h]
	sParam1 sV6;
// 	__int16 v6; // [esp+8h] [ebp-B0h]
// 	void *v7; // [esp+Eh] [ebp-AAh]
// 	int v8; // [esp+12h] [ebp-A6h]
// 	int v9[40]; // [esp+16h] [ebp-A2h]

	if ( a2 )
	{
		if ( sub_402667(a1, a2, &sV6) )
			return -1;
		v5 = sV6.sP2Data_0x6[sV6.wCnt_0x0 - 1].dwKnown_0x08;
		g_ItemFileHeader_0xCE[a1].dataArr_0x28[g_ItemFileHeader_0xCE[a1].wIdxMax_0x26++] = a2;
		if ( v5 )
		{
			if ( sub_404ABD(a1, v5, a3) )
				return -1;
		}
		else
		{
			memcpy(&g_ItemFileHeader_0xCE[a1].data_0x50[0],
				sV6.sP2Data_0x6[sV6.wCnt_0x0 - 1].strval_0x0,
				g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
			v4 = GetRecordSize(a1);
			memcpy(a3, sV6.sP2Data_0x6[sV6.wCnt_0x0 - 1].strval_0x0, v4);
			dword_4F2C88 = sV6.sP2Data_0x6[sV6.wCnt_0x0 - 1].dwKnown_0x04;
		}
	}
	return 0;
}

int __cdecl sub_404A0C(int a1, void *a2)
{
	if ( IsHasRecord(a1) )
		return 0;
	memset((char *)&g_ItemFileHeader_0xCE[a1].dataArr_0x28[0], 0, 0x28u);
	memset(
		(char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0],
		0,
		g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
	g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 = 0;
	dword_4F2C88 = 0;
	if ( sub_404ABD(a1, g_ItemFileHeader_0xCE[a1].dwUnkown_0x22, a2) )
		return -1;
	releaseBuffer();
	return dword_4F2C88;
}

int __cdecl sub_404190(int a1, char *a2, void *a3)
{
	int v4; // ST0C_4
	char *v5; // ST08_4
	int v6; // eax
	int v7; // eax
	__int16 v8; // ST14_2
	int v9; // eax
	int v10; // [esp+0h] [ebp-BCh]
	signed int i; // [esp+8h] [ebp-B4h]
	sParam1 sParam;
// 	__int16 v12; // [esp+Ch] [ebp-B0h]
// 	char *v13; // [esp+12h] [ebp-AAh]
// 	int v14[41]; // [esp+16h] [ebp-A6h]

	if ( IsHasRecord(a1) )
		return 0;
	sub_402414(a1, a2, 0);
	do
	{
		if ( sub_402667(a1, 
			*(int *)((char *)&g_ItemFileHeader_0xCE[a1].dwUnkown_0x22 + g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 * 4 + 2),
			&sParam) )
			return -1;
		for ( i = 0; i < sParam.wCnt_0x0; ++i )
		{
			v4 = g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4;
			v5 = sParam.sP2Data_0x6[i].strval_0x0;
			v6 = GetRecordSize(a1);
			if ( compareValueWithType(v6, a2, v5, v4) <= 0 )
			{
				memcpy(
					&g_ItemFileHeader_0xCE[a1].data_0x50[0],
					sParam.sP2Data_0x6[i].strval_0x0,
					g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);

				v7 = GetRecordSize(a1);

				memcpy(a3, sParam.sP2Data_0x6[i].strval_0x0, v7);

				releaseBuffer();
				return  sParam.sP2Data_0x6[i].dwKnown_0x04;
			}
		}
		v8 = g_ItemFileHeader_0xCE[a1].wIdxMax_0x26--;
		g_ItemFileHeader_0xCE[a1].dataArr_0x28[v8] = 0;
	}
	while (g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 > 0 );

	v10 = sub_404A0C(a1, a3);
	if ( v10 < 0 )
		return -1;
	v9 = GetRecordSize(a1);
	memcpy((char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0], a3, v9);
	releaseBuffer();
	return v10;
}




int __cdecl sub_4043B9(int a1, void *a2)
{
	int result; // eax
	int v3; // eax
	int v4; // eax
	int v5; // eax
	int i; // [esp+4h] [ebp-B4h]
	signed int j; // [esp+4h] [ebp-B4h]
	sParam1 spV8;
// 	__int16 v8; // [esp+8h] [ebp-B0h]
// 	int v9; // [esp+Ah] [ebp-AEh]
// 	char *v10; // [esp+Eh] [ebp-AAh]
// 	int v11; // [esp+12h] [ebp-A6h]
// 	int v12[40]; // [esp+16h] [ebp-A2h]

	if ( IsHasRecord(a1) )
		return 0;
	if ( sub_402667(a1, 
		*(int*)((BYTE*)&g_ItemFileHeader_0xCE[a1].dwUnkown_0x22 +  4 * g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 + 2),
		&spV8) )
		return -1;
	for ( i = spV8.wCnt_0x0 - 1; i >= 0 && compareVal(a1, spV8.sP2Data_0x6[i].strval_0x0, (char*)g_ItemFileHeader_0xCE[a1].data_0x50) > 0; --i )
		;
	if ( spV8.sP2Data_0x6[i].dwKnown_0x08 )
	{
		g_ItemFileHeader_0xCE[a1].dataArr_0x28[g_ItemFileHeader_0xCE[a1].wIdxMax_0x26++] = spV8.sP2Data_0x6[i].dwKnown_0x08;

		while ( 1 )
		{
			if ( sub_402667(
				a1,
				*(int*)((BYTE*)&g_ItemFileHeader_0xCE[a1].dwUnkown_0x22 +  4 * g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 + 2),
				&spV8) )
			{
				return -1;
			}
			g_ItemFileHeader_0xCE[a1].dataArr_0x28[g_ItemFileHeader_0xCE[a1].wIdxMax_0x26] = spV8.nUnkown_0x02;
			if ( !spV8.nUnkown_0x02 )
				break;

			g_ItemFileHeader_0xCE[a1].wIdxMax_0x26++;
		}

		memcpy(
			(char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0],
			spV8.sP2Data_0x6[0].strval_0x0,
			g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);

		v5 = GetRecordSize(a1);
		memcpy(a2, spV8.sP2Data_0x6[0].strval_0x0, v5);
		releaseBuffer();
		result = spV8.sP2Data_0x6[0].dwKnown_0x08;
	}
	else if ( i >= spV8.wCnt_0x0 - 1 )
	{
		while ( --g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 )
		{
			if ( sub_402667(
				a1,
				*(int *)((char *)&g_ItemFileHeader_0xCE[a1].dwUnkown_0x22 + 4 * g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 + 2),
				&spV8) )
			{
				return -1;
			}
			for ( j = 0; j < spV8.wCnt_0x0; ++j )
			{
				if ( compareVal(a1, spV8.sP2Data_0x6[j].strval_0x0, (char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0]) > 0 )
				{
					memcpy(
						(char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0],
						spV8.sP2Data_0x6[j].strval_0x0,
						g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);

					v4 = GetRecordSize(a1);
					memcpy(a2, spV8.sP2Data_0x6[j].strval_0x0, v4);
					releaseBuffer();
					return  spV8.sP2Data_0x6[j].dwKnown_0x04;
				}
			}
		}
		if ( sub_404A0C(a1, a2) >= 0 )
		{
			releaseBuffer();
			result = dword_4F2C88;
		}
		else
		{
			result = -1;
		}
	}
	else
	{
		memcpy(
			(char *)&g_ItemFileHeader_0xCE[a1].data_0x50[0],
			spV8.sP2Data_0x6[i+1].strval_0x0,
			g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
		v3 = GetRecordSize(a1);
		memcpy(a2, spV8.sP2Data_0x6[i+1].strval_0x0, v3);
		releaseBuffer();
		result = spV8.sP2Data_0x6[i+1].dwKnown_0x04;
	}
	return result;
}

int __cdecl sub_4048EA(int a1, int a2, void *a3)
{
	int v4; // eax
	int v5; // [esp+4h] [ebp-B4h]
	sParam1 sV6;
// 	char v6; // [esp+8h] [ebp-B0h]
// 	int v7; // [esp+Ah] [ebp-AEh]
// 	void *v8; // [esp+Eh] [ebp-AAh]
// 	int v9; // [esp+12h] [ebp-A6h]

	if ( a2 )
	{
		if ( sub_402667(a1, a2, &sV6) )
			return -1;
		v5 = sV6.nUnkown_0x02;
		g_ItemFileHeader_0xCE[a1].dataArr_0x28[g_ItemFileHeader_0xCE[a1].wIdxMax_0x26++] = a2;
		if ( v5 )
		{
			if ( sub_4048EA(a1, v5, a3) )
				return -1;
		}
		else
		{
			memcpy(
				g_ItemFileHeader_0xCE[a1].data_0x50,
				sV6.sP2Data_0x6[0].strval_0x0,
				g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
			v4 = GetRecordSize(a1);
			memcpy(a3, sV6.sP2Data_0x6[0].strval_0x0, v4);
			dword_4F2C88 = sV6.sP2Data_0x6[0].dwKnown_0x04;
		}
	}
	return 0;
}

signed int __cdecl sub_45EA1C(char *a1, BYTE * a2, int a3, gItem_0x20 * a4, int a5)
{
	int v5; // ST2C_4
	int v6; // ST30_4
	int v8; // [esp+0h] [ebp-104h]
	int v9; // [esp+4h] [ebp-100h]
	gItem_0xEC v10; // [esp+10h] [ebp-F4h]
// 	char v11[0x30]; // [esp+7Ah] [ebp-8Ah]
// 	char v12[0x44]; // [esp+ABh] [ebp-59h]
//	gItem_0x27 * v13; // [esp+F0h] [ebp-14h]
//	int v14; // [esp+F4h] [ebp-10h]
//	int v15; // [esp+F8h] [ebp-Ch]
	size_t v16; // [esp+FCh] [ebp-8h]
	int i; // [esp+100h] [ebp-4h]


	v9 = 0;
	for ( i = 0; i < g_ItemDatas_0x122[a3].dwUnkownCnt_0x8e; ++i )
	{
		v8 = *(DWORD *)((char*)&g_ItemDatas_0x122[a3].dwUnkown_0x92 + i * 12);

		if ( v8 == a5 )
		{
			v5 = *(DWORD *)((char*)&g_ItemDatas_0x122[a3].dwUnkown_0x96 + i * 12);
			v6 = *(DWORD *)((char*)&g_ItemDatas_0x122[a3].dwUnkown_0x9a + i * 12);

			v10.dwUnkown_0x0 = 1;
			v10.nNodeIdx_0xe4 = v6;
			v10.dwItemx27_0xe0 = &g_ItemDatas_0x122[v8].pData_0x0e[v6];

			v10.pSubNode_0xe8 = 0;
			v16 = g_ItemDatas_0x122[a3].pData_0x0e[v5].dwDataLen_0x08;

			memcpy(&v10.str_unkown_0x6a[0], &a2[g_ItemDatas_0x122[a3].pData_0x0e[v5].dwId2_0x4], v16);
			memcpy(&v10.str_unkown_0x9b, &v10.str_unkown_0x6a[0], v16);
			sub_462B29(0, a1, v8, &v10, 1, a4, 0, 0, 0);
			return 1;
		}
	}
	return v9;
}


int __cdecl sub_463FEB(gItem_0xEC *a1, bool a2, int a3, BYTE * a4, void * a5, void * a6, int a7, char *a8, int a9)
{
	int v11; // [esp+Ch] [ebp-14Ch]
	unsigned int j; // [esp+10h] [ebp-148h]
	void *v13; // [esp+14h] [ebp-144h]
	gItem_Data * v14; // [esp+18h] [ebp-140h]
	gItem_Data ** v15; // [esp+1Ch] [ebp-13Ch]
	void *v16; // [esp+20h] [ebp-138h]
	gItem_0xEC v17; // [esp+24h] [ebp-134h]
	gItem_0x27 * v18; // [esp+104h] [ebp-54h]
	char *v19; // [esp+110h] [ebp-48h]
	gItem_0x27 * v20; // [esp+114h] [ebp-44h]
	BOOL v21; // [esp+118h] [ebp-40h]
	int v22; // [esp+11Ch] [ebp-3Ch]
	int i; // [esp+120h] [ebp-38h]
	int v24; // [esp+124h] [ebp-34h]
	int v25; // [esp+128h] [ebp-30h]
	gItem_0x20 v26; // [esp+12Ch] [ebp-2Ch]
	// 	int v27; // [esp+13Ch] [ebp-1Ch]
	// 	int v28; // [esp+148h] [ebp-10h]
	int v29; // [esp+14Ch] [ebp-Ch]
	LPSTR lpsz; // [esp+150h] [ebp-8h]
	char *v31; // [esp+154h] [ebp-4h]
	char String1[100];
	char chText[100];
	v20 = a1->dwItemx27_0xe0;
	v25 = v20->dwId2_0x4;
	v19 = (char *)(v25 + a4);
	lpsz = (LPSTR)(v25 + (char*)a5);
	v31 = (char *)(v25 + (char*)a6);
	if ( v20->byteType_0x0c == 9 )
	{
		v29 = 0;
		if ( sub_45EA1C(a8, a4, a7, &v26, v20->byteUnkown_0x1e && v26.dwDataCnt_0x10 ))
		{
			v15 = v26.pDataPtr_0x1c;
			if ( v15 )
			{
				ASSERT(sizeof(v17) == 0xec);
				memcpy(&v17, a1, 0xECu);

				v18 = sub_45C4F0(a1);
				v16 = (void *)new BYTE[5112];
				v13 = (void *)new BYTE[5112];
				if ( v13 && v16 )
				{
					sub_463E71(&v17, 1);
					sub_463D4E(v16, &v17, 1);
					sub_463DDE(v13, &v17, 1);
					for ( i = 0; i < v26.dwDataCnt_0x10 && !v29; ++i )
					{
						v14 = v15[i];
						if ( v14 )
						{
							v29 = sub_463FEB(&v17, 1, 0, v14->pNodeData_0x190, v16, v13, v20->byteUnkown_0x1e, a8, a9);
						}
					}
				}
				if ( v16 )
					delete [] v16;
				if ( v13 )
					delete [] v13;
			}
			sub_45E7BF(&v26);
		}
		return v29;
	}
	if (!(v20->dwFlag_0x12 & 0x40) || !a1->pSubNode_0xe8 )
	{
		if ( v20->dwFlag_0x12 & 0x20 )
		{
			v21 = v20->byteSubType_0x0d == 7;
			if ( v20->dwFlag_0x12 & 2 )
			{
				v21 = 1;
				CharUpperA(lpsz);
			}
			v11 = a1->dwUnkonw_0xd0;
			switch ( v11 )
			{
			case 1401:
				strcpy(String1, v19);
				if ( v21 )
					CharUpperA(String1);
				return strstr(String1, lpsz) != 0;
			case 1402:
				if ( !v21 )
					return strcmp(v19, lpsz) == 0;
				strcpy(String1, v19);
				CharUpperA(String1);
				return _strcmpi(String1, lpsz) == 0;
			case 1403:
				strcpy(String1, v19);
				if ( v21 )
					CharUpperA(String1);
				strcpy(chText, lpsz);
				return (unsigned __int16)sub_47E0C0(String1, chText, 0, 1, 25);
			}
		}
		if ( v20->byteType_0x0c == 4 )
			return sub_464512(v19, lpsz, a9);
		if ( v20->byteType_0x0c == 2 )
		{
			v22 = sub_407FFD(v20, a4);
			v19 = (char *)&v22;
		}
		v24 = v20->byteSubType_0x0d;
		return compareValueWithType(a1->dwSubLen_0xdc, lpsz, v19, v24) <= 0 && compareValueWithType(a1->dwSubLen_0xdc, v19, v31, v24) <= 0;
	}
	v29 = 0;
	for ( j = 0; j < a1->pSubNode_0xe8->dwCnt_0x0c; ++j )
	{
		memcpy(lpsz, (const void *)(a1->pSubNode_0xe8->dwUnkown_0x10 + 8 * j), a1->dwSubLen_0xdc);
		if ( !compareValueWithType(a1->dwSubLen_0xdc, lpsz, v19, v20->byteSubType_0x0d) )
			return 1;
	}
	return v29;
}


int __cdecl sub_404839(int a1, void *a2)
{
	if ( IsHasRecord(a1) )
		return 0;
	memset(&g_ItemFileHeader_0xCE[a1].dataArr_0x28[0], 0, 0x28u);
	memset(
		(char *)&g_ItemFileHeader_0xCE[a1].data_0x50,
		0,
		g_ItemFileHeader_0xCE[a1].dwSubNodeSize_0x0);
	g_ItemFileHeader_0xCE[a1].wIdxMax_0x26 = 0;
	dword_4F2C88 = 0;
	if ( sub_4048EA(a1, g_ItemFileHeader_0xCE[a1].dwUnkown_0x22, a2) )
		return -1;
	releaseBuffer();
	return dword_4F2C88;
}


int __cdecl sub_45D2FF(char *a1)
{
	int v1; // eax
	char v3[100]; // [esp+0h] [ebp-104h]

	strcpy(v3, a1);
	chdir(v3);
	v1 = toupper((unsigned __int8)*a1);
	return _chdrive(v1 - 64);
}

int __cdecl sub_462B29(HWND hWndParent, char *spath, int a3, gItem_0xEC * a4, 
	int a5,		//1
	gItem_0x20 * pOutData,
	int a7,		//0
	int a8,		//0 
	int a9		//0
	)
{
	HWND v10; // eax
	size_t v11; // ST38_4
	int v12; // eax
	HCURSOR v13; // eax
	gItem_Data * v15; // [esp+18h] [ebp-1728h]
	gItem_Data ** v16; // [esp+1Ch] [ebp-1724h]
	gItem_0xEC v17; // [esp+20h] [ebp-1720h]
	//char v18[80]; // [esp+8Ah] [ebp-16B6h]
	//char v19[80]; // [esp+BBh] [ebp-1685h]
	//gItem_0x27 * v20; // [esp+100h] [ebp-1640h]
	//int v21; // [esp+104h] [ebp-163Ch]
	//int v22; // [esp+108h] [ebp-1638h]
	int v23; // [esp+10Ch] [ebp-1634h]
	gItem_0x20 v24; // [esp+110h] [ebp-1630h]
	//int v25; // [esp+12Ch] [ebp-1614h]
	gItem_0x27* v26; // [esp+130h] [ebp-1610h]
	int j; // [esp+134h] [ebp-160Ch]
	void *v28; // [esp+138h] [ebp-1608h]
	void *v29; // [esp+13Ch] [ebp-1604h]
	int v30; // [esp+140h] [ebp-1600h]
	int v31; // [esp+144h] [ebp-15FCh]
	HWND hDlg; // [esp+148h] [ebp-15F8h]
	int v33; // [esp+14Ch] [ebp-15F4h]
	int v34; // [esp+150h] [ebp-15F0h]
	bool v35; // [esp+154h] [ebp-15ECh]
	LPARAM lParam; // [esp+158h] [ebp-15E8h]
	LPARAM v37; // [esp+15Ch] [ebp-15E4h]
	int v38; // [esp+160h] [ebp-15E0h]
	int v39; // [esp+164h] [ebp-15DCh]

	int v41; // [esp+16Ch] [ebp-15D4h]
	HCURSOR hCursor; // [esp+170h] [ebp-15D0h]
	sItem_t1 v43; // [esp+174h] [ebp-15CCh]
// 	gItem_0xEC *  v44; // [esp+178h] [ebp-15C8h]
// 	int v45; // [esp+17Ch] [ebp-15C4h]
// 	int v46; // [esp+180h] [ebp-15C0h]
// 	int v47; // [esp+184h] [ebp-15BCh]
// 	BYTE * v48; // [esp+188h] [ebp-15B8h]
// 	int v49; // [esp+18Ch] [ebp-15B4h]
// 	int v50; // [esp+190h] [ebp-15B0h]
// 	int v51; // [esp+194h] [ebp-15ACh]
// 	int v52; // [esp+198h] [ebp-15A8h]
	int i; // [esp+19Ch] [ebp-15A4h]
	void *v54; // [esp+1A0h] [ebp-15A0h]
	void *v55; // [esp+1A4h] [ebp-159Ch]
	CHAR String[0x50]; // [esp+1A8h] [ebp-1598h]
	int v57; // [esp+1F8h] [ebp-1548h]
	gItem_0xEC v58; // [esp+1FCh] [ebp-1544h]
	//gItem_0x27 *v59; // [esp+2DCh] [ebp-1464h]
	//int v60; // [esp+2E0h] [ebp-1460h]
	BYTE v61[5112]; // [esp+2E8h] [ebp-1458h]
	sItem_subNode * vp62; // [esp+16E0h] [ebp-60h]
	int v63; // [esp+16E4h] [ebp-5Ch]
	DLGPROC lpDialogFunc; // [esp+16E8h] [ebp-58h]
	int nfileIdx; // [esp+16ECh] [ebp-54h]
	int v66; // [esp+16F0h] [ebp-50h]
	char v67[0x30]; // [esp+16F4h] [ebp-4Ch]
	int v68; // [esp+1724h] [ebp-1Ch]
	CHAR Buffer[0x14]; // [esp+1728h] [ebp-18h]
	int v70; // [esp+173Ch] [ebp-4h]

	v38 = -1;
	v63 = -1;
	v55 = 0;
	v29 = 0;
	lpDialogFunc = 0;
	hDlg = 0;
	vp62 = 0;

	pOutData->dwUnknow_0x08  = 0;
	pOutData->pItem_0x0c  = 0;
	pOutData->dwDataCnt_0x10  = 0;
	pOutData->pDataPtr_0x1c  = 0;

	v31 = a3;
	v41 = a5;
	gItem_0xEC *v40 = a4;
	v70 = 1;
	for ( i = 0; i < a5; ++i )
	{
		if ( a4[i].dwUnkown_0x0 &&  a4[i].dwItemx27_0xe0->byteType_0x0c != 9 )
		{
			v70 = 0;
			break;
		}
	}
	if ( v70 )
	{
		v70 = 0;
		for ( i = 0; i < a5; ++i )
		{
			if ( a4[i].dwUnkown_0x0 )
			{
				if ( a4[i].dwItemx27_0xe0->byteType_0x0c == 9 )
				{
					memcpy(&v58, &a4[i], 0xECu);
					getTypeDataByIdx(a4[i].dwItemx27_0xe0->byteUnkown_0x1e,
						a4[i].dwItemx27_0xe0->dwIdx_0x1a, v58.dwItemx27_0xe0);

					v58.nNodeIdx_0xe4 = sub_462933(a4[i].dwItemx27_0xe0->byteUnkown_0x1e, v58.dwItemx27_0xe0->dwId_0x0);

					if ( v58.nNodeIdx_0xe4 != -1 )
					{
						a3 = a4[i].dwItemx27_0xe0->byteUnkown_0x1e;
						a5 = 1;
						a4 = &v58;
						v70 = 1;
						break;
					}
				}
			}
		}
	}
	v34 = 1;

// 	if ( a2 )
// 		sub_45D2FF(a2);

	nfileIdx = sub_463C5C(spath, a3);

	if ( nfileIdx != -1 )
	{
		v54 = (void *)new BYTE[5112];
		v28 = (void *)new BYTE[5112];
		v43.pData_0x14 = new BYTE[4 * a5];
		if ( v54 && v28 && v43.pData_0x14 )
		{
			sub_463E71(a4, a5);
			do
			{
				v43.nCnt_0x0 = a5;
				v43.pItem_0x4 = a4;
				v43.dwUnkown_0x8 = 1;
				v43.dwUnkown_0xc = a3;
				v57 = 0;
				lParam = GetRecordCnt(nfileIdx);
				v37 = 0;
				while ( (!hDlg || !dword_4FD3E8) && !v57 && sub_464C32(&v43) )
				{
					if ( !vp62 && !v43.dwUnkown_0x24 )
					{
						for ( j = 0; j < v43.nCnt_0x0; ++j )
						{
							if ( v43.pItem_0x4[j].dwUnkown_0x0
								&& v43.pItem_0x4[j].pSubNode_0xe8
								&& v43.pItem_0x4[j].pSubNode_0xe8->dwCnt_0x0c)
							{
								v66 = j;
								v33 = 0;
								vp62 = v43.pItem_0x4[j].pSubNode_0xe8;
								v43.pItem_0x4[j].pSubNode_0xe8 = 0;
								break;
							}
						}
					}
					if ( vp62 )
						sub_465304(vp62, v33, &v43.pItem_0x4[v66]);

					sub_463D4E(v54, a4, a5);

					sub_463DDE(v28, a4, a5);

					if ( v43.dwUnkown_0x20 != v38 && (v63 == -1) && (v63 = sub_4612FD(spath, a3, v43.dwUnkown_0x20), v63 == -1) )
					{
						ASSERT(0);	//error
						//sub_45D2A8();
					}
					else
					{
						v38 = v43.dwUnkown_0x20;
						v26 = a4[sub_463CF3(&v43, v43.dwUnkown_0x20)].dwItemx27_0xe0;
						if ( v26->dwDataLen_0x08 <= 48 )
							memcpy(v67, (char *)v54 + v26->dwId2_0x4, v26->dwDataLen_0x08);
						else
							memcpy(v67, (char *)v54 + v26->dwId2_0x4, 0x30u);

						if ( !v43.dwUnkown_0x24 && (v30 = sub_404190(v63, v67, v67)) != 0 || v43.dwUnkown_0x24 && (v30 = sub_404839(v63, &v67)) != 0 )
						{
							do
							{
								if ( v57
									|| !ReadFileRecordData(nfileIdx, v30, v61)
									|| !sub_4645D6(&v43, v61, v54, (BYTE*)v28, &v35, a3, spath, a9) )
								{
									break;
								}

								if ( v35 )
								{
									if ( v70 )
									{
										v17.dwUnkown_0x0 = 1;
										v17.nNodeIdx_0xe4 = 0;
										v17.dwItemx27_0xe0 = g_ItemDatas_0x122[v31].pData_0x0e;
										v17.pSubNode_0xe8 = 0;
										v34 = 0;
										for ( i = 0; i < g_ItemDatas_0x122[v31].dwUnkownCnt_0x8e; ++i )
										{
											if (*(DWORD*)((char*)&g_ItemDatas_0x122[v31].dwUnkown_0x92 + 12 * i) == a3)
											{
												v11 =  g_ItemDatas_0x122[v31].pData_0x0e[*(DWORD*)((char*)&g_ItemDatas_0x122[v31].dwUnkown_0x96 + 12 * i)].dwDataLen_0x08;
													memcpy(
													v17.str_unkown_0x6a,
													&v61[g_ItemDatas_0x122[a3].pData_0x0e[*(DWORD*)((char*)&g_ItemDatas_0x122[v31].dwUnkown_0x9a + 12 * i)].dwId2_0x4],
													v11);
												memcpy(v17.str_unkown_0x9b, v17.str_unkown_0x6a, v11);
												v34 = 1;
												break;
											}
										}
										if ( v34 )
										{
											v34 = 0;
											if ( sub_462B29(0, spath, v31, &v17, 1, &v24, 0, 1, 0) )
											{
												v16 = v24.pDataPtr_0x1c;
												if ( v16 )
												{
													v15 = v16[0];
													if ( v15 )
													{
														v23 = v15->nNodeIdx_0x4;
														v34 = 1;
														if ( !sub_46511A(pOutData, v23) )
														{
															if ( !v55 )
															{
																v55 = new BYTE[5112];
																if ( v55 )
																{
																	sub_463E71(v40, v41);
																	sub_463D4E(v55, v40, v41);
																	if ( !v29 )
																	{
																		v29 = new BYTE[5112];
																		if ( v29 )
																			sub_463DDE(v29, v40, v41);
																	}
																}
															}
															v68 = 1;
															if ( v29 && v55 )
															{
																for ( i = 0; i < v41 && v68; ++i )
																{
																	if (v40[i].dwUnkown_0x0)
																		v68 = sub_463FEB(&v40[i], 0, 0, v15->pNodeData_0x190, v55, v29, v31, spath, a9);
																}
															}
															if ( v68 && !sub_4651BB(pOutData, v15->pNodeData_0x190, v31, v23, 0, spath) )
																v34 = 0;
														}
													}
												}
											}
										}
										sub_45E7BF(&v24);
										if ( !v34 )
											v57 = 1;
									}
									else if ( (!v43.dwUnkown_0x1c || v43.dwUnkown_0x10 < 2 || !sub_46511A(pOutData, v30)) && !sub_4651BB(pOutData, v61, a3, v30, v43.dwUnkown_0x20, spath) )
									{
										v34 = 0;
										v57 = 1;
									}

									if ( a8 && a8 == pOutData->dwDataCnt_0x10 )
										v57 = 1;
								}
								v39 = v30;
								v30 = sub_4043B9(v63, &v67);
								if ( !v30 )
									break;
							}
							while ( v30 != v39 );
						}
					}
					if ( !pOutData->dwDataCnt_0x10 )
					{
						if ( !v43.dwUnkown_0x1c || (v12 = sub_463CF3(&v43, v43.dwUnkown_0x20), !*(DWORD *)(v43.pData_0x14 + 4 * v12)) )
							v57 = 1;
					}
				}
				if ( v43.dwUnkown_0x1c && v43.dwUnkown_0x18 != v43.dwUnkown_0x10 )
					sub_4649F2(&v43, v43.dwUnkown_0x18);
				if ( vp62 && !dword_4FD3E8 && ++v33 == vp62->dwCnt_0x0c)
				{
					v43.pItem_0x4[v66].pSubNode_0xe8 = vp62;
					vp62 = 0;
				}
			}
			while ( vp62 && (!hDlg || !dword_4FD3E8) );
			if ( v63 != -1 )
			{
				//sub_4612C1(a3, v63);
				//ASSERT(0);//close file
			}
		}
		if ( v54 )
			delete [] v54;
		if ( v28 )
			delete [] v28;

		if ( v43.pData_0x14 )
			delete [] v43.pData_0x14;

		//ASSERT(0);
		//close file
		//sub_463C25(a3, v65);
	}
	if ( v55 )
		delete [] v55;
	if ( v29 )
		delete [] v29;
	return pOutData->dwDataCnt_0x10;
}

bool __cdecl sub_46475E(sItem_t1 *a1, BYTE * a2, void* a3, BYTE* a4, int a5)
{
	BOOL v6; // [esp+4h] [ebp-3Ch]
	BOOL v7; // [esp+8h] [ebp-38h]
	int v8; // [esp+Ch] [ebp-34h]
	bool v9; // [esp+10h] [ebp-30h]
	char *v10; // [esp+14h] [ebp-2Ch]
	gItem_0x27 * v11; // [esp+18h] [ebp-28h]
	int v12; // [esp+1Ch] [ebp-24h]
	int k; // [esp+1Ch] [ebp-24h]
	int i; // [esp+20h] [ebp-20h]
	int j; // [esp+20h] [ebp-20h]
	DWORD * v16; // [esp+24h] [ebp-1Ch]
	int v17; // [esp+28h] [ebp-18h]
	DWORD * v18; // [esp+2Ch] [ebp-14h]
	int v19; // [esp+30h] [ebp-10h]
	gItem_0xEC * v20; // [esp+34h] [ebp-Ch]
	char *v21; // [esp+38h] [ebp-8h]

	v9 = 1;
	v17 = a1->nCnt_0x0;
	v16 = new DWORD[a1->nCnt_0x0];
	v18 = new DWORD[v17];
	if ( v16 && v18 )
	{
		v12 = sub_463CF3(a1, a1->dwUnkown_0x20);
		for ( i = 0; i < v17; ++i )
		{
			if ( i == v12 )
				v18[i] = 0;
			else
				v18[i] = *(DWORD *)(a1->pData_0x14 + 4 * i);
			v7 = a1->pItem_0x4[i].dwUnkown_0x0 && v18[i];
			v16[i] = v7;
		}
		for ( j = 0; j < v17 && v9; ++j )
		{
			if (v16[j])
			{
				v20 = &a1->pItem_0x4[j];
				v19 = v20->dwItemx27_0xe0->dwId2_0x4;
				v21 = (char *)(v19 + (BYTE*)a3);
				v9 = 0;
				for ( k = 0; k < v17 && !v9; ++k )
				{
					if (v18[k])
					{
						v11 = a1->pItem_0x4[k].dwItemx27_0xe0;
						v10 = (char *)(v11->dwId2_0x4 + a2);
						if ( v11->byteType_0x0c == 4 )
						{
							v9 = sub_464512(v10, v21, a5);
						}
						else
						{
							v8 = v11->byteSubType_0x0d;
							v6 = compareValueWithType(v20->dwSubLen_0xdc, v21, v10, v8) <= 0
								&& compareValueWithType(v20->dwSubLen_0xdc, v10, (char *)(v19 + a4), v8) <= 0;
							v9 = v6;
						}
						if ( v9 )
							v18[k] = 0;
					}
				}
			}
		}
	}

	delete [] v18;
	delete [] v16;

	return v9;
}

BOOL __cdecl sub_4645D6(sItem_t1 *a1, BYTE* a2, void* a3, BYTE * a4, bool *a5, int a6, char* a7, int a8)
{
	int i; // [esp+4h] [ebp-14h]
	int v11; // [esp+8h] [ebp-10h]
	int v12; // [esp+Ch] [ebp-Ch]
	signed int v13; // [esp+10h] [ebp-8h]
	signed int v14; // [esp+14h] [ebp-4h]

	v13 = 0;
	*a5 = true;
	v12 = a1->nCnt_0x0;
	v11 = sub_463CF3(a1, a1->dwUnkown_0x20);
	for ( i = 0; i < v12; ++i )
	{
		if ( a1->pItem_0x4[i].dwUnkown_0x0 )
		{
			if (!*(DWORD *)(a1->pData_0x14 + 4 * i) ||
				!a1->dwUnkown_0x1c &&
				!a1->dwUnkown_0x24 ||
				i == v11)
			{
				v14 = sub_463FEB(&a1->pItem_0x4[i], i == v11, a1->nCnt_0x0 + 9, a2, a3, a4, a6, a7, a8);
				if ( !v14 )
					*a5 = false;
				if ( i == v11 )
				{
					v13 = v14;
					if ( !*a5 )
						break;
				}
			}
		}
		else if ( a1->dwUnkown_0x24 )
		{
			if ( i == v11 )
				v13 = 1;
		}
	}
	if ( v13 && *a5 && 
		a1->dwUnkown_0x1c || a1->dwUnkown_0x24)
		*a5 = sub_46475E(a1, a2, a3, a4, a8);
	return v13 || a1->dwUnkown_0x24;
}

void __cdecl sub_45E95C(gItem_Data * a1, BYTE a2)
{
	gItem_0x20 v6;
	if ( a1 )
	{
		if ( sub_45EA1C(a1->sDir_0x8, a1->pNodeData_0x190, a1->nFileIdx_0x0, &v6, a2) )
		{
			a1->subData_0x100[a2].dwUnkown_0x00 = 1;
			a1->subData_0x100[a2].dwDataCnt_0x04 = v6.dwDataCnt_0x10;	
			a1->subData_0x100[a2].pDataPtr_0x08 = v6.pDataPtr_0x1c;
		}
	}
}

int __cdecl sub_45E8C3(gItem_Data * a1, BYTE a2, gItem_Data *** a3)
{
	gItem_Data ** v4 = 0; // [esp+0h] [ebp-Ch]
	gItem_Data * v5; // [esp+4h] [ebp-8h]
	int v6Cnt = 0; // [esp+8h] [ebp-4h]
	if ( a1 )
	{	
		if ( !a1->subData_0x100[a2].dwUnkown_0x00 )
			sub_45E95C(a1, a2);
		v6Cnt = a1->subData_0x100[a2].dwDataCnt_0x04;
		v4 = a1->subData_0x100[a2].pDataPtr_0x08;
	}
	if ( a3 )
		*a3 = v4;

	return v6Cnt;
}

int __cdecl sub_4B24DD(st1* pst, gItem_Data * a2, gItem_Data * a3, char *outstr, int a5, int a6, int a7, DWORD * a8, int a9, int a10)
{
	int result; // eax
	unsigned __int64 v11; // st7
	unsigned __int64 v12; // st7
	int v13; // ST1C_4
	signed int v14; // ST38_4
	int v15; // ST1C_4
	signed int v16; // ST34_4
	int v17 = 0; // [esp+4h] [ebp-42D4h]
	unsigned __int8 v18; // [esp+1Ch] [ebp-42BCh]
	byte v19[0x44c]; // [esp+40h] [ebp-4298h]
	int v20; // [esp+48Ch] [ebp-3E4Ch]
	byte v21[0x13F8] = {0}; // [esp+490h] [ebp-3E48h]
	byte v22[0x44c]  = {0}; // [esp+A26h] [ebp-38B2h]
	float v23; // [esp+1888h] [ebp-2A50h]
	float v24; // [esp+188Ch] [ebp-2A4Ch]
	char v25[0x13F8]; // [esp+1890h] [ebp-2A48h]
	//int v26; ---0x1e4  // [esp+1A74h] [ebp-2864h]
	//int v27; ---0x1e8  // [esp+1A78h] [ebp-2860h]
	char *v28; // [esp+2C88h] [ebp-1650h]
	float v29; // [esp+2C8Ch] [ebp-164Ch]
	float v30; // [esp+2C90h] [ebp-1648h]
	char v31[0x13F8]; // [esp+2C94h] [ebp-1644h]
	//int v32-----0x1dc; // [esp+2E70h] [ebp-1468h] 
	//int v33v------0x1e0; // [esp+2E74h] [ebp-1464h]

	char *v34; // [esp+408Ch] [ebp-24Ch]
	char *v35; // [esp+4090h] [ebp-248h]
	char *v36; // [esp+4094h] [ebp-244h]
	char *v37; // [esp+4098h] [ebp-240h]
	int v38; // [esp+409Ch] [ebp-23Ch]
	gItem_Data ** v39; // [esp+40A0h] [ebp-238h]
	st1 stNext;
// 	int v40; // [esp+40A4h] [ebp-234h]
// 	int v41; // [esp+40A8h] [ebp-230h]
	int v42Cnt; // [esp+40B4h] [ebp-224h]
	gItem_Data * v43; // [esp+40B8h] [ebp-220h]
	BOOL v44; // [esp+40BCh] [ebp-21Ch]
	gItem_0x27 * pItemx27 = 0; // [esp+40C4h] [ebp-214h]
	char *v47; // [esp+40C8h] [ebp-210h]
	int v48; // [esp+40CCh] [ebp-20Ch]
	int v49; // [esp+40D0h] [ebp-208h]
	char Buffer[512] = {0}; // [esp+40D4h] [ebp-204h]
	char chText[512] = {0};
	char v51; // [esp+40D5h] [ebp-203h]
	int v52; // [esp+42D4h] [ebp-4h]

	v48 = 1;
	v44 = 0;
	if ( a7 )
		*(DWORD *)a7 = 0;
	if ( a9 )
		*(DWORD *)a9 = 0;

	if ( sub_4AE9EB(pst, pItemx27) )
	{
		v52 = pst->d1;
		v44 = 1;
		if ( a10 > 0 && pItemx27->byteType_0x0c != 9 )
		{
			*outstr = -1;
			outstr[1] = 0;
			return 1;
		}
		if ( pItemx27->dwFlag_0x12 & 0x40 )
		{
 			v43 = sub_46208B(a2, pItemx27->byteUnkown_0x1e, 0);
 			sub_461F9B(v43, Buffer);
			v44 = 1;
		}
		else if ( a2 )
		{
			v47 = (char *)(a2->pNodeData_0x190 + pItemx27->dwId2_0x4);
			switch ( pItemx27->byteType_0x0c )
			{
			case 0u:
				strcpy(chText, v47);
				//strncpy(chText, v47, pItemx27->dwDataLen_0x08);
				//*(chText + pItemx27->dwDataLen_0x08) = 0;
				if ( a5 )
				{
					//sub_4216D0((int)&chText, &Buffer, 0);
				}
				else
					strcpy(Buffer, chText);
				break;
			case 1u:
			case 6u:
				switch ( pItemx27->byteSubType_0x0d )
				{
				case 1u:
				case 7u:
					{
						strncpy(Buffer, v47, pItemx27->dwDataLen_0x08);
						*(Buffer + pItemx27->dwDataLen_0x08) = 0;
					}
					break;
				case 2u:
					{
						sprintf(Buffer, "%.2f", *(float *)v47);
						v37 = strchr(Buffer, '.');
						if ( v37 )
							*v37 = '\0';
					}		
					break;
				case 3u:
					wsprintfA(Buffer, "%d", *(signed __int16 *)v47);
					break;
				case 4u:
					wsprintfA(Buffer, "%ld", *(DWORD *)v47);
					break;
				case 5u:
					wsprintfA(Buffer, "%d", (unsigned __int8)*v47);
					break;
				case 8u:
					wsprintfA(Buffer, "%lu", *(DWORD *)v47);
					break;
				default:
					break;
				}
				break;
			case 2u:
				if ( pItemx27->dwFlag_0x12 & 0x80 )
				{
					if ( v52 == 3 )
					{
						v43 = sub_46208B(a3, 0, 0);
						if ( v43 )
						{
							v49 = *(DWORD*)v43;
							if ( v49 )
							{
								v20 = v49 + 400;
								memcpy(&v21, a2->pNodeData_0x190, 0x13F8u);
								memcpy(&v19, (const void *)(v49 + 0x1AF), 0x44Cu);
								memcpy(&v22, &v19, 0x44Cu);
								v13 = GetUnitsFromReg();
								v14 = sub_407FFD(pItemx27, &v21[0]);
								sub_421F14((double)v14, v13, Buffer, 0);
							}
						}
					}
				}
				else
				{
					v15 = GetUnitsFromReg();
					v16 = sub_407FFD(pItemx27, a2->pNodeData_0x190);
					sub_421F14((double)v16, v15, Buffer, 0);
				}
				break;
			case 3u:
				{
					g_dataReader->LoadString((unsigned __int8)*v47 + pItemx27->dwBaseResId_0x16, Buffer, 512);
				}
				break;
			case 4u:
				v44 = 0;
				break;
			case 5u:
				v44 = 0;
				if ( a8 && a9 )
				{
					*(DWORD *)a8 = *(DWORD *)v47;
					*(DWORD *)a9 = 1;
				}
				break;
			case 7u:
			case 8u:
				if ( a6 && a7 )
				{
					*(DWORD *)a6 = *(DWORD *)v47;
					*(DWORD *)a7 = 1;
				}
				v44 = 0;
				break;
			case 9u:
				{
				//	ASSERT(0);
					v44 = 0;
					v42Cnt = sub_45E8C3(a2, pItemx27->byteUnkown_0x1e, &v39);
					if ( v42Cnt )
					{
						if ( v39 )
						{
							v48 = v42Cnt;
							if ( a10 < v42Cnt )
							{
								stNext.d1 = pItemx27->byteUnkown_0x1e;
								stNext.d2 = pItemx27->dwIdx_0x1a;
								v44 = sub_4B24DD(&stNext, v39[a10], 0, Buffer, a5, a6, v17, a8, a9, 0) > 0;
							}
						}
					}
					if ( !v44 )
					{
						v44 = 1;
						if ( a10 )
						{
							Buffer[0] = -1;
							v51 = 0;
							if ( a7 )
								*(DWORD *)a7 = 0;
							if ( a9 )
								*(DWORD *)a9 = 0;
						}
						else
						{
							g_dataReader->LoadString(0x856u, Buffer, 512);
						}
					}
				}
				break;
			case 0xAu:
				wsprintfA(Buffer, "%d", *(DWORD *)v47);
				break;
			case 0xBu:
				sub_45B7D4(pItemx27->dwBaseResId_0x16, (int)v47, Buffer, 512);
				break;
			case 0xCu:
				if ( pItemx27->byteSubType_0x0d == 2 )
				{
					sprintf(Buffer, "%15.2f gram     %10.1f grain", *(float *)v47 / 15.4323583529414, *(float *)v47);
					v36 = strchr(Buffer, '.');
					if ( v36 )
						*v36 = '\0';
					if ( *(float *)v47 < 0.0 )
						strcpy(Buffer, "-");
				}
				else
				{
					Buffer[0] = 0;
				}
				break;
			case 0xDu:
				if ( pItemx27->byteSubType_0x0d == 2 )
				{
					if ( v52 == 3 )
					{
						sprintf(Buffer, "%15.2f mm     %10.4f inch", *(float *)v47, *(float *)v47 / 25.399956);
						v35 = strchr(Buffer, '.');
						if ( v35 )
							*v35 = '\0';
						if ( *(float *)v47 < 0.0 )
							strcpy(Buffer, "-");
					}
				}
				else
				{
					Buffer[0] = 0;
				}
				break;
			case 0xEu:
				if ( pItemx27->byteSubType_0x0d == 4 )
				{
					if ( v52 == 3 )
					{
						memcpy(&v31, a2->pNodeData_0x190, 0x13F8u);
						v30 = *(double*)&v31[0x1e0] / 0.9144;
						*(double *)&v11 = *(double*)&v31[0x1dc] / 0.3048;
						v29 = *(double *)&v11;
						sprintf(Buffer, "V%d=%d (V meters=meters per sec)  ==  V%.1f=%.1f (V yards=feet pe", *(int*)&v31[0x1e0], *(int*)&v31[0x1dc], v30, (DWORD)v11, (DWORD)(v11 >> 32));
						v34 = strchr(Buffer, '.');
						if ( v34 )
							*v34 = '\0';
						if ( *(int*)&v31[0x1dc] < 0 )
							strcpy(Buffer, "-");
					}
				}
				else
				{
					Buffer[0] = 0;
				}
				break;
			case 0xFu:
				if ( pItemx27->byteSubType_0x0d == 4 )
				{
					if ( v52 == 3 )
					{
						memcpy(&v25, a2->pNodeData_0x190, 0x13F8u);
						v24 = *(double*)&v25[0x1e8] / 0.9144;
						*(double *)&v12 = *(double*)&v25[0x1e4] / 1.3563;
						v23 = *(double *)&v12;
						sprintf(Buffer, "E%d=%d (E meters=joules)  ==  E%.1f=%.1f (E yards=footpounds)", *(int*)&v25[0x1e8], *(int*)&v25[0x1e4], v24, (DWORD)v12, (DWORD)(v12 >> 32));
						v28 = strchr(Buffer, '.');
						if ( v28 )
							*v28 = '\0';
						if ( *(int*)&v25[0x1e4] < 0 )
							strcpy(Buffer, "-");
					}
				}
				else
				{
					Buffer[0] = 0;
				}
				break;
			case 0x10u:
				{
					strncpy(chText, v47, pItemx27->dwDataLen_0x08);
					*(chText +  pItemx27->dwDataLen_0x08) = 0;
					if ( a5 )
					{
						//sub_4216D0((int)&chText, Buffer, 0);
						ASSERT(0);
					}
					else
					{
						strcpy(Buffer, chText);
					}
						
					if ( !chText )
					{
						g_dataReader->LoadString(0xB55u, Buffer, 512);
					}
				}
				break;
			case 0x11u:
				{
					char sTmp[512] = {0};
					g_dataReader->LoadString(pItemx27->dwId_0x0, sTmp, 512);
					sprintf(Buffer, "------------------------------------------------- %s ------------", sTmp);
				}
				break;
			default:
				break;
			}
		}
		else
		{
			v44 = 1;
			v18 = pItemx27->byteType_0x0c;
			if ( v18 >= 4u && v18 <= 5u )
				v44 = 0;
		}
		if ( v44 )
		{
			TrimEnd(Buffer);
			strcpy(outstr, Buffer);
		}
	}
	if ( v44 )
		result = v48;
	else
		result = 0;
	return result;
}


int __cdecl sub_43E559(int a1, LPSTR lpBuffer, int a3)
{
	int result; // eax
	char Buffer[256] = {0}; // [esp+8h] [ebp-100h]

	result = (unsigned __int16)a1;
	if ( (signed int)(unsigned __int16)a1 < 945 && (signed int)(unsigned __int16)a1 >= 100 )
	{
		if ( !a3 )
		{
			//a3 = (int)&dword_4F5D18;
			ASSERT(0);
		}

		*lpBuffer = 0;
		for (int i = 0; i < *(DWORD *)(a3 + 8); ++i )
		{
			if ( *(unsigned __int16 *)(*(DWORD *)(a3 + 4) + 11 * i + 2) == (unsigned __int16)a1 )
			{
				if ( !*(DWORD *)(*(DWORD *)(a3 + 4) + 11 * i + 7) )
				{
					return g_dataReader->LoadString((unsigned __int16)a1 + 12000, lpBuffer, 128);
				}	
				//result = obj_GlobalLock(*(DWORD *)(*(DWORD *)(a3 + 4) + 11 * i + 7));
				result = *(DWORD*)(*(DWORD *)(*(DWORD *)(a3 + 4) + 11 * i + 7));
				if ( result )
				{
					strcpy(lpBuffer, (const char *)result);
					//result = obj_GlobalUnlock(*(DWORD *)(*(DWORD *)(a3 + 4) + 11 * i + 7));
				}
				return result;
			}
			result = i + 1;
		}
	}
	else
	{
		g_dataReader->LoadString((unsigned __int16)a1 + 12000, Buffer, 256);

		if ( (signed int)(unsigned __int16)a1 < 1000 )
			result = (int)strcpy(lpBuffer, Buffer);
		else
			result = wsprintfA(lpBuffer, "RAL %u %s", (unsigned __int16)a1, Buffer);
	}
	return result;
}

int __cdecl sub_43DCA0(int a1, LPSTR lpBuffer)
{
	int v2; // eax
	WORD * pData = (WORD*)&v2;

	pData[1] = HIWORD(a1);
	unsigned __int16 v3 = *(WORD *)&a1;
	pData[0] = *(WORD *)&a1;
	sub_43E559(v2, lpBuffer, 0);
	return v3;
}

bool __cdecl sub_4A6E86(gItem_0x2C * a1, gItem_0x258 * a2, WPARAM wParam, int a4)
{
	bool bret = false;
	char v5; // [esp+0h] [ebp-2Ch]
	int v6; // [esp+4h] [ebp-28h]
	int v7; // [esp+8h] [ebp-24h]
	int v9; // [esp+10h] [ebp-1Ch]
	int id_ptr; // [esp+14h] [ebp-18h]
	WPARAM v12; // [esp+1Ch] [ebp-10h]
	int v13; // [esp+28h] [ebp-4h]

	v7 = 0;
	gItem_Data * v8 = sub_4A6E38(a1);
	v12 = wParam;

	DWORD v11 = ReadIntValue(v8);
	
	st1 st;
	st.d1 = v11;
	st.d2 = wParam;
	gItem_0x27 * pItem27 = 0;

	if ( sub_4AE9EB(&st, pItem27) )
	{
		a2->pItem27_0x0 = pItem27;
		a2->dwUnkown_0x248 = v11;
 		loadKeyName(pItem27, 1, a2->sKey_0x4, 64, 0);

		if (stricmp(a2->sKey_0x4, "literature source") == 0)	//该类型存在bug,先屏蔽
		{
			bret = true;
			strcpy(a2->sValue_0x44, "");
		}
		else
		if ( sub_4B24DD(&st, v8, v8, a2->sValue_0x44, 0, (int)&v13, (int)&v6, &a2->dwUnkown_0x244, (int)&v9, 0) || v9 || v6 )
		{
			a2->dwUnkown_0x24c = a1->dwUnkown_0x28;
			if ( v9 )
			{
				sub_43DCA0(a2->dwUnkown_0x244, a2->sValue_0x44);
			}
			
			if ( v6 )
			{
				bret = true;
				v5 = pItem27->byteType_0x0c;
				if ( v5 == 7 )
				{
					//lst_make_date_str(v13, a2 + 68, 0);
				}
				else if ( v5 == 8 )
				{
					//lst_make_time_str(v13, a2 + 68);
				}
			}
			v7 = 1;
		}
	}
	return v7;
}

// void InitFiles(char * pPath)
// {
// 	char sFile[520] = {0};
// 	for (int i = 0; i < 12; i++)
// 	{
// 		sprintf(sFile, "%s%s", pPath, g_ItemDatas_0x122[i].strName_0x04);
// 		strcat(sFile, ".dt");
// 		if (_access(sFile, 0) != 0)
// 		{
// 			ASSERT(0);
// 		}
// 		InitFile(sFile, i);		
// 	}
// }

void __cdecl RefreshTableData(gItem_0x2C * a1, vector<pair<string, string>> & arrDatas)
{
	gItem_0x258 item0x258;
	BYTE Data[4]; // [esp+254h] [ebp-Ch]
	int v5; // [esp+258h] [ebp-8h]
	int v6 = 0; // [esp+25Ch] [ebp-4h]

	int nCnt = getTypeDataCnt(a1->wType_0x20);
	int nRealCnt = 0;
	for ( int i = 0; i < nCnt; ++i )
	{
		if ( sub_4A6E86(a1, &item0x258, i, 0) )
		{
			string s1 = item0x258.sKey_0x4;
			string s2 = item0x258.sValue_0x44;
			arrDatas.push_back(make_pair(s1, s2));
			OutputDebugStringA(item0x258.sKey_0x4);
			OutputDebugStringA("=====");
			OutputDebugStringA(item0x258.sValue_0x44);
			OutputDebugStringA("\n");

// 			if ( v6 )
// 			{
// 				if ( *(_BYTE *)(v2 + 12) != 2 && !(*(DWORD *)(v2 + 18) & 0x2050) )
// 					SendMessageA(*(HWND *)(a1 + 12), LB_ADDSTRING, 0, i);// 
// 			}
//			else
			if ( !item0x258.pItem27_0x0->dwUnkown_0x1f && 
				  item0x258.pItem27_0x0->byteType_0x0c != 2 &&
				 !item0x258.pItem27_0x0->dwFlag_0x12 & 0x2050 )
			{
				nRealCnt++;
				//SendMessageA(*(HWND *)(a1 + 12), LB_ADDSTRING, 0, i);// LB_ADDSTRING
			}
		}
	}
// 	sub_4AD63D(a1);
// 	sub_4A6FE8(a1);
// 	SendMessageA(*(HWND *)(a1 + 12), 0x186u, 0, 0);// LB_SETCURSEL
// 	SendMessageA(*(HWND *)(a1 + 12), 0x197u, 0, 0);// LB_SETTOPINDEX
// 	result = sub_4AAAA7(a1, 1);

}

int __cdecl FillDataByIdx_45BE92(int nidx, int a2, int a3)
{
	int result; // eax
	signed int v4; // [esp+8h] [ebp-Ch]
	int v6 = 0;
	int i;
	for ( i = 0; ; i += 2 )
	{
		result = (int)&g_ItemDatas_0x122[0];
		if ( v6 >=  g_ItemDatas_0x122[nidx].dwDataNodeCnt_0x0a)
			break;
		int nType = g_ItemDatas_0x122[nidx].pData_0x0e[v6].byteSubType_0x0d;
		*(DWORD *)(a3 + 4 * v6) = nType;
		v4 = 1;
		switch ( nType )
		{
		case 3:
			if (g_ItemDatas_0x122[nidx].pData_0x0e[v6].dwDataLen_0x08 != 2)
			{
				v4 = 0;
			}			
			break;
		case 4:
			if (g_ItemDatas_0x122[nidx].pData_0x0e[v6].dwDataLen_0x08 != 4)
			{
				v4 = 0;
			}	
			break;
		case 5:
			if (g_ItemDatas_0x122[nidx].pData_0x0e[v6].dwDataLen_0x08 != 1)
			{
				v4 = 0;
			}	
			break;
		case 0xB:
			if (g_ItemDatas_0x122[nidx].pData_0x0e[v6].dwDataLen_0x08 != 8)
			{
				v4 = 0;
			}	
			break;
		default:
			break;
		}

		if ( !v4 )
		{
			OutputDebugStringA("Invalid key type length!!!!");      // Invalid key type length!!!!
			MessageBeep(0);
			ASSERT(0);
		}

		if ( a2 )
		{
			*(DWORD *)(a2 + 4 * i) = g_ItemDatas_0x122[nidx].pData_0x0e[v6].dwId2_0x4;
			*(DWORD *)(a2 + 4 * i + 4) = g_ItemDatas_0x122[nidx].pData_0x0e[v6].dwDataLen_0x08;
			if ( *(DWORD *)(a2 + 4 * i + 4) > 45 )
				*(DWORD *)(a2 + 4 * i + 4) = 45;
		}
		++v6;
	}

	if ( a2 )
		*(DWORD *)(a2 + 4 * i) = -1;
	return result;
}


int __cdecl GetHeader_0x98(int a1)
{
	if ( !bInitFlag )
		InitGlobleBuffer();
	return g_ItemFileHeader_0xCE[a1].wUnkown_0x86;
}

int __cdecl InitDBFile(char *sFile, int a2, int a3, int a4, HWND hWnd)
{
	int result; // eax
	int subFileOpenIdx; // eax
	__int16 v7; // ax
	size_t v9; // [esp+1Ch] [ebp-6Ch]
	char v10[8]; // [esp+20h] [ebp-68h]
	size_t nDataSize; // [esp+28h] [ebp-60h]
	int j; // [esp+2Ch] [ebp-5Ch]
	int i; // [esp+30h] [ebp-58h]
	void *lpBuffer; // [esp+34h] [ebp-54h]
	UINT uMode; // [esp+38h] [ebp-50h]
	int v17; // [esp+40h] [ebp-48h]
	char PathName[100]; // [esp+44h] [ebp-44h]
	char sBaseName[100];

	i = 0;
	v17 = -1;
	while ( i < 13 )
	{
		if ( !g_ItemDBfile_0xE6[i].bIsUseSubFile_4FE1F8 )
		{
			v17 = i;
			break;
		}
		++i;
	}
	if ( v17 >= 0 )
	{
		strcpy(PathName, g_dataPath);
		strcat(PathName, sFile);
		strcpy(sBaseName, PathName);
		strcat(PathName, ".dt");
		
		g_ItemDBfile_0xE6[i].dwOpenFileIdx_4FE274 = InitFile(PathName, a4);

		ASSERT(g_ItemDBfile_0xE6[i].dwOpenFileIdx_4FE274 != 0x13) ;

		if ( g_ItemDBfile_0xE6[v17].dwOpenFileIdx_4FE274 >= 0 )
		{
			nDataSize = GetDataSizeByIdx(g_ItemDBfile_0xE6[v17].dwOpenFileIdx_4FE274);

			if ( nDataSize == -1 )
			{
				ASSERT(0);
			}
			else
			{
				lpBuffer = malloc(nDataSize);
				ASSERT(lpBuffer);

				if ( ReadFileRecordData(g_ItemDBfile_0xE6[v17].dwOpenFileIdx_4FE274, 1, lpBuffer) )
				{		
					memcpy(&g_ItemDBfile_0xE6[v17].subFileCnt_4FE27C, lpBuffer, 2u);// 子文件个数，.n01,n02...的文件

					memcpy(&g_ItemDBfile_0xE6[v17].subFileNode->wPos, (char *)lpBuffer + 2, sizeof(gItemSubFileNode) * g_ItemDBfile_0xE6[v17].subFileCnt_4FE27C);

					free(lpBuffer);

					v9 = strlen(sFile);

					strcpy( g_ItemDBfile_0xE6[v17].fileName_4FE1FA, sFile);
					g_ItemDBfile_0xE6[v17].subFileIdx_4FE278 = 0;
					g_ItemDBfile_0xE6[v17].bIsUseSubFile_4FE1F8 = 1;
			
					g_ItemDBfile_0xE6[v17].basePtr_dataPtr_4FE2B8 = (int)malloc(nDataSize);
					if ( !g_ItemDBfile_0xE6[v17].basePtr_dataPtr_4FE2B8 )
						ASSERT(0);

					for ( i = 0; i < g_ItemDBfile_0xE6[v17].subFileCnt_4FE27C; ++i )
					{
						sprintf(v10, ".n%02d", i);
						strcpy(PathName, sBaseName);
						strcat(PathName, v10);
	
						subFileOpenIdx = InitFile(PathName, a4);
						g_ItemDBfile_0xE6[v17].dwSubFileOpenIdx_4FE23C[i] = subFileOpenIdx;
						if(subFileOpenIdx < 0) 
						{
							ASSERT(0);
						}
					}
					
					v7 = GetHeader_0x98(g_ItemDBfile_0xE6[v17].dwSubFileOpenIdx_4FE23C[0]);
					g_ItemDBfile_0xE6[v17].word_4FE2B6 = v7;

					//clearDataBuffer(v17);
					result = v17 + 1;
				}
				else
				{
					ASSERT(0);
				}
			}
		}
		else
		{
			ASSERT(0);
		}
	}
	else
	{
		ASSERT(0);
	}
	return result;
}

int __cdecl sub_45D3A8(int nidx)
{
	BYTE v3[0x3c]; // [esp+100h] [ebp-40h]
	int v4; // [esp+13Ch] [ebp-4h]

	
	if ( g_openInfo[nidx].nFileIdx_4FD8A8)
	{
		v4 = g_openInfo[nidx].nFileIdx_4FD8A8;
		g_openInfo[nidx].nFileOpenCnt++;
	}
	else
	{
		FillDataByIdx_45BE92(nidx, 0, (int)&v3[0]);
		v4 = InitDBFile(g_ItemDatas_0x122[nidx].strName_0x04, (int)&v3[0], 0, 1, 0);
		if ( v4 < 1 )
		{
			ASSERT(0);
			return 0;
		}
		if ( g_openInfo[nidx].nFileOpenCnt )
		{
			
		}
		else
		{
			g_openInfo[nidx].nFileIdx_4FD8A8 = v4;
			g_openInfo[nidx].nFileOpenCnt++;
		}
	}
	return v4;
}


INT_PTR __cdecl InitGlobleFiles(char *a1)
{
	INT_PTR result = 0; // eax
	int bFileOpenOK = 1;
	
	sub_45D2FF(a1);

	for (int i = 0; i < 12; ++i )
	{
		g_openInfo[i].nFileIdx_4FD8A8 = sub_45D3A8(i);
		if ( !g_openInfo[i].nFileIdx_4FD8A8 )
		{
			bFileOpenOK = 0;
			ASSERT(0);
			break;
		}
		g_openInfo[i].nFileOpenCnt = 1;
	}
	
	return result;
}

signed int __cdecl IsFileValidate(signed int a1)
{
	signed int result = 0; // eax

	if ( a1 >= 0 && a1 < 13 )
	{	
		if ( g_ItemDBfile_0xE6[a1].bIsUseSubFile_4FE1F8 )
		{
			result = 1;
		}
		else
		{
			ASSERT(0);
		}
	}
	else
	{
		ASSERT(0);
	}
	return result;
}

int __cdecl ReadRecordBuffer(int a1, int a2, void *lpBuffer)
{
	int result; // eax
	int v4; // esi
	int v5; // eax

	if ( a2 > 0 )
	{
		v4 = ReadFileRecordData(g_ItemDBfile_0xE6[a1].dwOpenFileIdx_4FE274, a2, lpBuffer);
		if ( v4 == GetDataSizeByIdx(g_ItemDBfile_0xE6[a1].dwOpenFileIdx_4FE274))
		{
			g_ItemDBfile_0xE6[a1].dwNodeIdx_4FE2BC = a2;
			v5 = GetDataSizeByIdx(g_ItemDBfile_0xE6[a1].dwOpenFileIdx_4FE274);
			memcpy((void*)g_ItemDBfile_0xE6[a1].basePtr_dataPtr_4FE2B8, lpBuffer, v5);
			result = 1;
		}
		else
		{
			ASSERT(0);
		}
	}
	else
	{
		ASSERT(0);
	}
	return result;
}

int __cdecl sub_4925F2(int a1, void *lpBuffer)
{
	char v3[0x30]; // [esp+0h] [ebp-34h]
	int v4; // [esp+30h] [ebp-4h]
	int v5; // [esp+3Ch] [ebp+8h]

	v5 = a1 - 1;
	if ( !IsFileValidate(v5) )
		return -1;
	v4 = sub_404839(g_ItemDBfile_0xE6[v5].dwSubFileOpenIdx_4FE23C[g_ItemDBfile_0xE6[v5].subFileIdx_4FE278], &v3);
	dword_4FEF04 = -2;
	return ReadRecordBuffer(v5, v4, lpBuffer);
}

void *__cdecl clearDataBuffer(int a1)
{
	int v1; // eax
	g_ItemDBfile_0xE6[a1].dwNodeIdx_4FE2BC = 0;
	
	v1 = GetDataSizeByIdx(g_ItemDBfile_0xE6[a1].dwOpenFileIdx_4FE274);

	return memset((void*)g_ItemDBfile_0xE6[a1].basePtr_dataPtr_4FE2B8, 0, v1);
}

signed int __cdecl GetSubFileWordBufferFromBuffer(int a1, signed int nSubFileIdx, void *dataPtr)
{
	int v4; // ST10_4
	size_t v5; // ST0C_4
	
	if ( nSubFileIdx >= g_ItemDBfile_0xE6[a1].subFileCnt_4FE27C )
		return 0;

	v4 = g_ItemDBfile_0xE6[a1].subFileNode[nSubFileIdx].wPos;
	v5 = g_ItemDBfile_0xE6[a1].subFileNode[nSubFileIdx].wSize;

	memset(subFileWordBuffer0x30, 0, 0x30u);
	memcpy(subFileWordBuffer0x30, (char *)dataPtr + v4, v5);

	subFileWordBuffer0x30[v5] = 0;

	return 1;
}

int __cdecl sub_4022E2(int a1, char *a2);
int __cdecl sub_404C1E(int a1, char *a2, int a3)
{
	int v4; // ST0C_4
	int v5; // eax
	int v6; // [esp+0h] [ebp-3Ch]
	int v7; // [esp+4h] [ebp-38h]
	char v8[0x200]; // [esp+8h] [ebp-34h]

	v6 = sub_4022E2(a1, a2);
	v7 = v6;
	if ( v6 == -1 )
		return 0;
	
	if ( !g_ItemFileHeader_0xCE[a1].wUnkown_0x86 )
		return a3 == v6 ? v6 : 0;
	while ( 1 )
	{
		if ( v6 == a3 )
			return a3;
		v6 = sub_4043B9(a1, &v8);
		if ( v6 == -1 )
			return 0;
		v4 = g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4;
		v5 = GetRecordSize(a1);
		if ( compareValueWithType(v5, v8, a2, v4) || v6 == v7 )
			break;
		v7 = v6;
	}
	return 0;
}

int __cdecl sub_4022E2(int a1, char *a2)
{
	int result; // eax
	int v3; // ST0C_4
	int v4; // eax
	char v5[0x30]; // [esp+0h] [ebp-34h]
	int v6; // [esp+30h] [ebp-4h]

	if ( IsHasRecord(a1) )
		return 0;
	word_4F3C7C = 0;
	if ( sub_402414(a1, a2, 0) == -1 )
		return -1;
	
	if ( dword_4F2C88 || !g_ItemFileHeader_0xCE[a1].wUnkown_0x86 )
		return dword_4F2C88;
	v6 = sub_4043B9(a1, v5);
	if ( v6 == -1 )
		return -1;
	v3 = g_ItemFileHeader_0xCE[a1].dwKeyTypePtr_0x4;
	v4 = GetRecordSize(a1);
	if ( compareValueWithType(v4, a2, v5, v3) )
		result = 0;
	else
		result = v6;
	return result;
}

int __cdecl sub_492D81(int a1, int subFileIdx, char *a3, int a4)
{
	int result; // eax
	int v5; // [esp+8h] [ebp+8h]

	v5 = a1 - 1;
	if ( !IsFileValidate(v5) )
		return -1;
	
	if ( subFileIdx < g_ItemDBfile_0xE6[v5].subFileCnt_4FE27C && subFileIdx >= 0 )
	{
		if ( a4 )
		{
			if ( sub_404C1E(g_ItemDBfile_0xE6[v5].dwSubFileOpenIdx_4FE23C[subFileIdx], a3, a4) == a4 )
				result = a4;
			else
				result = 0;
		}
		else
		{
			result = sub_4022E2(g_ItemDBfile_0xE6[v5].dwSubFileOpenIdx_4FE23C[subFileIdx], a3);
		}
	}
	else
	{
		ASSERT(0);
		result = 0;
	}
	return result;
}

signed int __cdecl sub_492B1E(int a1, int recordId)
{
	int v3; // esi
	signed int v4; // [esp+Ch] [ebp+8h]

	v4 = a1 - 1;
	if ( !IsFileValidate(v4) )
		return -1;
	if ( !recordId )
	{
		clearDataBuffer(v4);
		return 0;
	}
	if ( g_ItemDBfile_0xE6[v4].dwNodeIdx_4FE2BC != recordId )
	{
		v3 = ReadFileRecordData(
			g_ItemDBfile_0xE6[v4].dwOpenFileIdx_4FE274,
			recordId,
			(void*)g_ItemDBfile_0xE6[v4].basePtr_dataPtr_4FE2B8);
		if ( v3 != GetDataSizeByIdx(g_ItemDBfile_0xE6[v4].dwOpenFileIdx_4FE274))
		{
			clearDataBuffer(v4);
			ASSERT(0);
			return 0;
		}
		g_ItemDBfile_0xE6[v4].dwNodeIdx_4FE2BC = recordId;
	}

	GetSubFileWordBufferFromBuffer(
		v4,
		g_ItemDBfile_0xE6[v4].subFileIdx_4FE278,
		(void*)g_ItemDBfile_0xE6[v4].basePtr_dataPtr_4FE2B8);

	if ( sub_492D81(v4 + 1,  g_ItemDBfile_0xE6[v4].subFileIdx_4FE278, (char*)subFileWordBuffer0x30, recordId) == recordId )
		return 1;
	clearDataBuffer(v4);
	return 0;
	// 	LoadStringA(hInstance, 0x466u, byte_4FEEB0, 80);// Could not find key for data record
// 	return OutputDbgString(-1, (int)byte_4FEEB0);
}

int __cdecl sub_492CB5(int a1, signed int a2)
{
	int result; // eax
	signed int v3; // [esp+8h] [ebp+8h]

	v3 = a1 - 1;
	if ( !IsFileValidate(v3) )
		return -1;
	if ( a2 >= 0 && a2 < g_ItemDBfile_0xE6[v3].subFileCnt_4FE27C )
	{
		g_ItemDBfile_0xE6[v3].subFileIdx_4FE278 = a2;
		result = sub_492B1E(v3 + 1, g_ItemDBfile_0xE6[v3].dwNodeIdx_4FE2BC);
	}
	else
	{
		ASSERT(0);
	}
	return result;
}

int __cdecl sub_492A9B(int a1, void *a2)
{
	int v3; // eax
	int v4; // [esp+8h] [ebp+8h]

	v4 = a1 - 1;
	if ( !IsFileValidate(v4) )
		return -1;
	if ( !g_ItemDBfile_0xE6[v4].dwNodeIdx_4FE2BC)
		return 0;
	if ( a2 )
	{
		v3 = GetDataSizeByIdx(g_ItemDBfile_0xE6[v4].dwOpenFileIdx_4FE274);
		memcpy(a2, (void*)g_ItemDBfile_0xE6[v4].basePtr_dataPtr_4FE2B8, v3);
	}
	return g_ItemDBfile_0xE6[v4].dwNodeIdx_4FE2BC;
}

void __cdecl sub_45E5D8(gItem_Data* a1)
{
	gItem_Data * v1 = a1; // [esp+4h] [ebp-8h]
	signed int i; // [esp+8h] [ebp-4h]

	if ( v1 )
	{
		if ( !v1->dwUnkown_0x98 )
		{
			for ( i = 0; i < 12; ++i )
			{
				sub_45E51F(v1->dwUnkown_0xd0[i]);
				v1->dwUnkown_0xd0[i] = 0;
				v1->dwUnkown_0xa0[i] = 0;
			}
			sub_45E42B(&v1->subData_0x100[0]);
		}
	}
}

int __cdecl sub_492674(int a1, void *lpBuffer)
{
	char v3; // [esp+0h] [ebp-34h]
	int v4; // [esp+30h] [ebp-4h]
	int v5; // [esp+3Ch] [ebp+8h]

	v5 = a1 - 1;
	if ( !IsFileValidate(v5) )
		return -1;

	if ( !g_ItemDBfile_0xE6[v5].dwNodeIdx_4FE2BC)
		return sub_4925F2(v5 + 1, lpBuffer);
	v4 = sub_4043B9(
		g_ItemDBfile_0xE6[v5].dwSubFileOpenIdx_4FE23C[g_ItemDBfile_0xE6[v5].subFileIdx_4FE278], &v3);

	if ( v4 == g_ItemDBfile_0xE6[v5].dwNodeIdx_4FE2BC)
		dword_4FEF04 = -1;
	else
		dword_4FEF04 = -3;
	return ReadRecordBuffer(v5, v4, lpBuffer);
}

BOOL __cdecl sub_46554E(char *sdirName, gItem_Data* & a2, int a3, int a4, int a5, int a6)
{
	gItem_Data * v7; // [esp+4h] [ebp-1454h]
	gItem_Data * v8; // [esp+8h] [ebp-1450h]
	signed int i; // [esp+Ch] [ebp-144Ch]
	int j; // [esp+Ch] [ebp-144Ch]
	char *v11; // [esp+10h] [ebp-1448h]
	int v12[12]; // [esp+14h] [ebp-1444h]
	int v13; // [esp+44h] [ebp-1414h]
	int v14; // [esp+48h] [ebp-1410h]
	BOOL v15; // [esp+4Ch] [ebp-140Ch]
	size_t v16; // [esp+50h] [ebp-1408h]
	gItem_Data * v17; // [esp+54h] [ebp-1404h]
	char Buffer[0x13f8]; // [esp+58h] [ebp-1400h]
	int v19; // [esp+1450h] [ebp-8h]
	int v20; // [esp+1454h] [ebp-4h]

	v15 = 0;
	v14 = 0;
	v19 = 0;
	v16 =  g_ItemDatas_0x122[a3].itemSize_0x08;// item_size
	if ( !a2 )
	{
		a2 = new gItem_Data;
		memset(a2, 0, sizeof(gItem_Data));
		if ( !a2 )
			return 0;
		a2->pNodeData_0x190 = new BYTE[v16];
		memset(a2->pNodeData_0x190, 0, v16);
		v14 = 1;
	}
	if ( a2 )
	{
		v17 = a2;
		if ( v17 )
		{
			if ( a5 && *(DWORD *)a5 )
			{
				v20 = *(DWORD *)a5;
			}
			else
			{
				sub_45D2FF(sdirName);
				v20 = sub_45D3A8(a3);
				if ( a5 )
				{
					*(DWORD *)a5 = v20;
					v19 = 1;
				}
			}
			if ( v20 )
			{
				if ( sub_492CB5(v20, v17->dwUnkown_0x88) == -1 )
				{
					//sub_45D2A8();
				}
				else
				{
					*(DWORD *)v17 = a3;
					sub_492B1E(v20, v17->nNodeIdx_0x4);
					memcpy(&Buffer, v17->pNodeData_0x190, v16);
					switch ( a4 )
					{
					case 0:                             // go to start
						v15 = sub_4925F2(v20, &Buffer) == 1;
						break;
// 					case 1:                             // go to end
// 						v15 = sub_49280C(v20, &Buffer) == 1;
// 						break;
					case 2:                             // go to next
						v15 = sub_492674(v20, &Buffer) == 1;
						break;
// 					case 3:                             // go to prev
// 						v15 = sub_492740(v20, &Buffer) == 1;
// 						break;
					default:
						break;
					}
					if ( v15 )
					{
						v13 = sub_492A9B(v20, 0);
						if ( v13 == v17->nNodeIdx_0x4 )
						{
							v15 = 0;
						}
						else
						{
							if ( !v14 )
							{
								for ( i = 0; i < 12; ++i )
								{
									v12[i] = -1;
									if ( v17->dwUnkown_0xd0[i])
									{
										v8 = v17->dwUnkown_0xd0[i];
										if ( v8 )
										{
											v12[i] = v8->dwUnkown_0x88;
										}
									}
								}
							}
							sub_45E5D8(a2);
							v17->nNodeIdx_0x4 = v13;
							strcpy(v17->sDir_0x8, sdirName);
							memcpy((void *)v17->pNodeData_0x190, Buffer, v16);
							v11 = (char *)GetCatalogueNumber(v17);
							if ( v11 )
							{
								strcpy(&byte_4F5A28[12 * a3], v11);
								TrimEnd(&byte_4F5A28[12 * a3]);
							}
							if ( v14 )
							{
								if ( a3 == 3 )
									v17->dwUnkown_0x88 = 1;
								if ( !a3 )
									v17->dwUnkown_0x88 = 1;
							}
							else
							{
								for ( j = 0; j < 12; ++j )
								{
									if ( v12[j] != -1 )
									{
										sub_46208B(a2, j, a6);
										if (v17->dwUnkown_0xd0[j])
										{
											v7 = v17->dwUnkown_0xd0[j];
											if ( v7 )
											{
												v7->dwUnkown_0x88 = v12[j];
											}
										}
									}
								}
							}
						}
					}
				}
				if ( !a5 || !v15 && v19 )
				{	//sub_45D34A(a3, v20);
					//close file;
				}
			}
		}
	}
	if ( v15 )
	{
		sub_45EC5D(a2);
	}
	else if ( v14 )
	{
		delete a2;
		a2 = 0;
	}
	return v15;
}


void __cdecl sub_43B41D(int a1)
{
	char *sdirName; // eax
	char v4[0x80]; // [esp+0h] [ebp-88h]
	gItem_Data * v5; // [esp+80h] [ebp-8h]

	sdirName = (char *)GetDirectoryNameFromReg();
	strcpy(v4, sdirName);
	v5 = 0;
	if ( sub_46554E(v4, v5, a1, 0, 0, 0) )
	{
		{
			switch ( v5->nFileIdx_0x0 )
			{
			case 1:
				//Headstamp;
				break;
			case 2:
				//Color;
				break;
			case 3:
				//Collection;
				break;
			case 4:
				//Factory
				break;
			default:
				//Caliber
				break;
			}
		}
		sub_45E51F(v5);
	}
	else
	{
		MessageBeep(0);
	}
}