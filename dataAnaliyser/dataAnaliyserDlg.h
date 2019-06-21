
// dataAnaliyserDlg.h : header file
//

#pragma once


// CdataAnaliyserDlg dialog
class CdataAnaliyserDlg : public CDialogEx
{
// Construction
public:
	CdataAnaliyserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DATAANALIYSER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CString LoadStr(DWORD);
	int		m_nRecIdx;
	int		m_nType;
	HICON m_hIcon;
	HMODULE	m_hModuleRes;

	int		GetOpType();


	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	bool RefreshPage(int nType, int nRecIdx);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonPre();
	afx_msg void OnBnClickedButtonNext();
	int m_type1;
	afx_msg void OnBnClickedButtonToxls();
};
