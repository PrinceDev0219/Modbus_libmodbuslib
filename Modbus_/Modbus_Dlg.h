
// Modbus_Dlg.h : header file
//

#pragma once


// CModbusDlg dialog
class CModbusDlg : public CDialogEx
{
// Construction
public:
	CModbusDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODBUS__DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnconnect();
	CIPAddressCtrl m_ctl_IP1;
	CString m_strRegValue1;
	CString m_strRegValue2;
	CString m_strRegValue3;
	CString m_strRegValue4;
	CString m_strRegValue5;
	CString m_strRegValue6;
	CString m_strRegValue7;
	CString m_strRegValue8;
	
	bool m_bChk;
public :
	void fnShowcomponent(bool b);
	int m_nPort1;
	int m_nPort2;
	int m_nPort3;
	int m_nPort4;
	int m_nPort5;
	int m_nPort6;
	int m_nPort7;
	int m_nPort8;

};
