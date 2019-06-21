
// dataAnaliyserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dataAnaliyser.h"
#include "dataAnaliyserDlg.h"
#include "afxdialogex.h"

#include <string>
#include <vector>
#include <map>
#include <libxl.h>
#pragma comment(lib, "libxl.lib")
using namespace std;
using namespace libxl;

#include "code.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include <iostream>
#include "libxl.h"
#pragma comment(lib,"libxl.lib")
using namespace libxl;


class CXlsDataExp
{
public:
	CXlsDataExp(LPCTSTR strFile){
		m_pbook = xlCreateBook();//创建一个二进制格式的XLS（Execl97-03）的实例,在使用前必须先调用这个函数创建操作excel的对象		
		if (strFile)
		{
			m_pbook->load(strFile);
		}
	};


	~CXlsDataExp(){
		Close();
	};

	int GetRecCount(const wstring & strSheet)
	{
		for (int i = 0; i < m_pbook->sheetCount(); i++)
		{
			Sheet* sheet = m_pbook->getSheet(i);
			if (sheet)
			{
				if (sheet->name() == strSheet)
				{
					int nLast = sheet->lastRow();
					if (nLast > 0)
					{
						nLast--;
					}
					return nLast;
				}				
			}
		}
		return 0;
	}

	bool WriteRec(const wstring & strSheet, const vector<wstring> & rec)
	{
		//book->setKey(......);//如果购买了该库，则设置相应的key，若没有购买，则不用这行
		if (!m_pbook)//是否创建实例成功
		{
			return false;
		}

		for (int i = 0; i < m_pbook->sheetCount(); i++)
		{
			Sheet* sheet = m_pbook->getSheet(i);
			if (sheet)
			{
				if (sheet->name() == strSheet)
				{
					m_sheetMap[strSheet] = sheet;
					break;
				}				
			}
		}

		Sheet* sheet = NULL;
		if (m_sheetMap.count(strSheet))
		{
			sheet = m_sheetMap[strSheet];
		}
		else
		{
			sheet = m_pbook->addSheet(strSheet.c_str());//添加一个工作表
			m_sheetMap[strSheet] = sheet;
		}

		//一个excel文件既是一个工作簿，你可以把工作簿看作是一个本子，而本子是由一页一页的纸张装订在一起的，excel中的sheet就是这些纸张。
		if (sheet)
		{
			int nLast = sheet->lastRow();
			int ncolCnt = rec.size();

			for (int i = 0; i < ncolCnt; i++)
			{
				sheet->writeStr(nLast, i, rec[i].c_str());//在第二行 第二列（B列）的表格中写入字符串"Hello, World !"。程序中从0开始计数。第0行就是execl的第1行
			}
		}
	};

	void Save(LPCTSTR strFile)
	{
		if (m_pbook->save(strFile))//保存到example.xls
		{
			//.....
		}
		else
		{
			std::cout << m_pbook->errorMessage() << std::endl;
		}
	};

	void Close(){
		if (m_pbook)
		{
			m_pbook->release();//释放对象！！！！！
			m_pbook = 0;
		}
	}
protected:
	Book* m_pbook;
	map<wstring, Sheet*>	m_sheetMap;
};

CString _GetAppPath()
{
	static CString strName = _T("");

	if (_tcscmp((LPCTSTR)strName, _T("")) != NULL)
	{		
		CString strPath = _T("");
		strPath += strName;
		return strPath;
	}

	LPTSTR pBuffer = (LPTSTR)strName.GetBuffer(MAX_PATH);
	VERIFY(::GetModuleFileName(NULL, pBuffer, MAX_PATH));
	strName.ReleaseBuffer();

	for (int i = _tcslen(pBuffer) - 1; i > 0; i--)
	{
		if (pBuffer[i] == '\\')
		{
			pBuffer[i + 1] = 0;
			break;
		}
	}

	CString strPath;
	strPath.Append(strName);
	return strPath;
}



class CDataReaderImpl : public IDataReader
{
public:
	CDataReaderImpl(){
		m_hModuleRes = 0;
		m_pBuffer = NULL;
		m_dwBaseAddr = 0x4dc000;
		USES_CONVERSION;
		CString sDataFile1 = _GetAppPath();
		sDataFile1 += L"cartwin40pro_004DC000.bin";
		FILE * fp = fopen(W2A(sDataFile1), "rb");
		if (fp)
		{
			fseek(fp, 0, SEEK_END);
			int nLen = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			m_pBuffer = new BYTE[nLen];
			int nFrom = 0;
			do 
			{
				int nr = fread(&m_pBuffer[nFrom], 1, nLen, fp);
				nLen -= nr;
				nFrom += nr;
			} while (nLen > 0);
			fclose(fp);
		}
	}

	virtual BYTE* ReadData(DWORD ptr, int nSize) {
		if (m_pBuffer)
		{
			return  (BYTE *)&m_pBuffer[ptr - m_dwBaseAddr];
		}
		return NULL;
	}

	virtual void ReleaseData(BYTE *) {

	}

	virtual bool LoadString(UINT idRes, char* buf, int nbufSize) 
	{
		USES_CONVERSION;
		TCHAR sBuf[255] = {0};
		int nRet = ::LoadString(m_hModuleRes, idRes, sBuf, 255);
		strcpy(buf, T2A(sBuf));
		return nRet > 0;
	}

	void SetResModule(HMODULE h){m_hModuleRes = h;}
protected:
	BYTE * m_pBuffer;
	DWORD m_dwBaseAddr;
	HMODULE	m_hModuleRes;
};


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdataAnaliyserDlg dialog





CdataAnaliyserDlg::CdataAnaliyserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdataAnaliyserDlg::IDD, pParent)
	, m_type1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	static CDataReaderImpl obj;
	g_dataReader = &obj;
	CString sPath = _GetAppPath();
	sPath += L"c_english32.dll";
	m_hModuleRes = LoadLibrary(sPath);
	ASSERT(m_hModuleRes);
	obj.SetResModule(m_hModuleRes);

	m_nRecIdx = 0;
	m_nType = 0;

	m_type1 = 0;
}

CString CdataAnaliyserDlg::LoadStr(DWORD idRes)
{
	TCHAR sBuf[255] = {0};
	LoadString(m_hModuleRes, idRes, sBuf, 255);
	CString sRet = sBuf;
	return sRet;
}

void CdataAnaliyserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CdataAnaliyserDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CdataAnaliyserDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_PRE, &CdataAnaliyserDlg::OnBnClickedButtonPre)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CdataAnaliyserDlg::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_TOXLS, &CdataAnaliyserDlg::OnBnClickedButtonToxls)
END_MESSAGE_MAP()


// CdataAnaliyserDlg message handlers

BOOL CdataAnaliyserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CListCtrl * plb = (CListCtrl*)GetDlgItem(IDC_LIST2);
	if (plb)
	{
		plb->InsertColumn(0, L"kay", LVCFMT_LEFT, 100);
		plb->InsertColumn(1, L"value", LVCFMT_LEFT, 500);
	}
	// Add "About..." menu item to system menu.


	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CheckDlgButton(IDC_RADIO_1, true);

	OnBnClickedOk();

 	OnBnClickedButtonToxls();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CdataAnaliyserDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CdataAnaliyserDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CdataAnaliyserDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

gItem_Data m_dt;

bool CdataAnaliyserDlg::RefreshPage(int nType, int nRecIdx)
{
	if (nType < 0 || nRecIdx < 0)
	{
		return false;
	}

	int nOpenIdx = g_ItemDBfile_0xE6[nType].dwOpenFileIdx_4FE274;
	ReadFileRecordData(
		nOpenIdx, 
		nRecIdx + 1, 
		m_dt.pNodeData_0x190);

	gItem_0x2C item;
	memset(&item, 0, sizeof(item));
	item.dwData_0x1c = &m_dt;
	item.wType_0x20 = nType;

	 vector<pair<string, string>> arrDatas;

	RefreshTableData(&item, arrDatas);

	USES_CONVERSION;
	CListCtrl * plb = (CListCtrl*)GetDlgItem(IDC_LIST2);
	if (plb)
	{
		plb->DeleteAllItems();

		for (int i = 0; i < arrDatas.size(); i++)
		{
			int nIdx = plb->InsertItem(i,A2T(arrDatas[i].first.c_str()));
			plb->SetItemText(nIdx, 1, A2T(arrDatas[i].second.c_str()));
		}
	}

	return true;
}




void CdataAnaliyserDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString sPath = _GetAppPath();
	USES_CONVERSION;
	sPath+= L"res\\";
	strcpy(g_dataPath, T2A((LPCTSTR)sPath)); 

	InitGlobleBuffer();

	InitGlobleMem_46A695();

	InitGlobleFiles(T2A((LPCTSTR)sPath));



	/*********************************************/
	//collect		:3
	//calibre		:0
	//headstamp		:1
	//colour code	:2
	//manufacturer	:4
	int nFileType = GetOpType();

	if (nFileType < 0)
	{
		AfxMessageBox(L"先指定类型");
		return ;
	}

	/**********************************************/

	int nRecordIdx = 0;	//记录编号，从1开始


// 	sub_43B41D(nFileType);
// 
// 	return;

	memset(&m_dt, 0, sizeof(m_dt));
	m_dt.nFileIdx_0x0 = nFileType;
	m_dt.nNodeIdx_0x4 = 1;
	strcpy(m_dt.sDir_0x8, T2A((LPCTSTR)sPath));

	int nOpenIdx = g_ItemDBfile_0xE6[nFileType].dwOpenFileIdx_4FE274;

	m_dt.pNodeData_0x190 = new BYTE[GetDataSizeByIdx(nOpenIdx)];

	int nCnt = 0;
	do 
	{
		break;

		ReadFileRecordData(
			nOpenIdx, 
			nRecordIdx + 1 + nCnt++, 
			m_dt.pNodeData_0x190);

		gItem_0x2C item;
		memset(&item, 0, sizeof(item));
		item.dwData_0x1c = &m_dt;
		item.wType_0x20 = nFileType;

		vector<pair<string, string>> datas;
		RefreshTableData(&item, datas);

		OutputDebugString(L"******************************\n");

	} while (nCnt < g_ItemFileHeader_0xCE[nOpenIdx].dwNodeCnt_0x16);

}

int	CdataAnaliyserDlg::GetOpType()
{
	int nType = -1;
	bool b1 = IsDlgButtonChecked(IDC_RADIO_0);
	bool b2 = IsDlgButtonChecked(IDC_RADIO_1);
	bool b3 = IsDlgButtonChecked(IDC_RADIO_2);
	bool b4 = IsDlgButtonChecked(IDC_RADIO_3);
	bool b5 = IsDlgButtonChecked(IDC_RADIO_4);

	if (b1)
	{
		nType = 0;
	}
	else
	if (b2)
	{
		nType = 1;
	}
	else
		if (b3)
		{
			nType = 2;
		}
		else
			if (b4)
			{
				nType = 3;
			}
			else
			{
				nType = 4;
			}

			return nType;
}


void CdataAnaliyserDlg::OnBnClickedButtonPre()
{
	// TODO: Add your control notification handler code here
	if(!RefreshPage(GetOpType(), --m_nRecIdx))
	{
		m_nRecIdx++;
	}
}


void CdataAnaliyserDlg::OnBnClickedButtonNext()
{
	// TODO: Add your control notification handler code here
	if(!RefreshPage(GetOpType(), ++m_nRecIdx))
	{
		m_nRecIdx--;
	}
}

char g_tmpData[0x100];
char * GetBinData(unsigned char * sInput)
{
	memset(g_tmpData, 0, 0x100);
	int n = 0;
	do 
	{
		if(sInput[n] == 0)
		{
			break;
		}
		char sCode[4];
		sprintf(sCode, "%2x", sInput[n]);
		if (sCode[0] == ' ')
		{
			sCode[0] = '0';
		}
		strcat(g_tmpData, sCode);
		n++;
	} while (true);

	return g_tmpData;
}


void CdataAnaliyserDlg::OnBnClickedButtonToxls()
{
	// TODO: Add your control notification handler code here
	USES_CONVERSION;
	vector<wstring> row;
	wstring sType;
	int nType = GetOpType();
	switch(nType)
	{
	case 0:
		sType = L"calibre";
		break;
	case 1:
		sType = L"headstamp";
		break;
	case 2:
		sType = L"colour";
		break;
	case 3:
		sType = L"collect";
		break;
	case 4:
		sType = L"manufacturer";
		break;
	}

	CString sFile = L"C:\\Users\\Lenovo\\Desktop\\2所数据分析\\data_";
	sFile += sType.c_str();
	sFile += L".xls";

	CXlsDataExp xlData((LPCTSTR)sFile);
	int nOpenIdx = g_ItemDBfile_0xE6[nType].dwOpenFileIdx_4FE274;
	int nRecIdx = xlData.GetRecCount(sType);
	bool bNeedTitle = nRecIdx == 0;
	if (nRecIdx < 1)
	{
		nRecIdx = 1;
	}

	//nRecIdx = 417;
	//nRecIdx = 63;
	do 
	{
		ReadFileRecordData(
			nOpenIdx, 
			nRecIdx + 1, 
			m_dt.pNodeData_0x190);

		gItem_0x2C item;
		memset(&item, 0, sizeof(item));
		item.dwData_0x1c = &m_dt;
		item.wType_0x20 = nType;

		vector<wstring> row;
		vector<pair<string, string>> arrDatas;
		RefreshTableData(&item, arrDatas);

		if (bNeedTitle)
		{
			bNeedTitle = false;
			for (auto iter = arrDatas.begin(); iter != arrDatas.end(); iter++)
			{
				row.push_back(A2T(iter->first.c_str()));
			}

			row.push_back(L"sampleImg");
			row.push_back(L"code1");
			row.push_back(L"code2");
			row.push_back(L"code3");
			row.push_back(L"code4");
			row.push_back(L"code5");
			row.push_back(L"code6");

			xlData.WriteRec(sType, row);
			row.clear();
		}
		
		for (auto iter = arrDatas.begin(); iter != arrDatas.end(); iter++)
		{
			row.push_back(A2T(iter->second.c_str()));
		}

		if (sType == L"headstamp")
		{
			int nImgFromPos = 0x585;
			int nFromPos = 0x23;
			char * pCodeData = (char*)m_dt.pNodeData_0x190 + nFromPos;
			char* sItemImg = (char*)m_dt.pNodeData_0x190 + nImgFromPos;
			row.push_back(A2T(sItemImg));
			int nStep = 0x2c;
			for (int i = 0; i < 6; i++)
			{
				unsigned char* sItemCode = (unsigned char*)m_dt.pNodeData_0x190 + nFromPos + i * nStep;
				char* sbin = GetBinData(sItemCode);
				row.push_back(A2T(sbin));
			}
		}


		xlData.WriteRec(sType, row);
		
		nRecIdx++;
		if (nRecIdx > 10 && 0)
		{
			break;
		}

		if (nRecIdx % 100 == 0)
		{
			xlData.Save(sFile);
		}

		//AfxMessageBox(L"aaa");
	} while (nRecIdx < g_ItemFileHeader_0xCE[nOpenIdx].dwNodeCnt_0x16);
	
	xlData.Save(sFile);
	xlData.Close();
}
