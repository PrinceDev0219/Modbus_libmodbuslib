
// Modbus_Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Modbus_.h"
#include "Modbus_Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CModbusDlg dialog



CModbusDlg::CModbusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODBUS__DIALOG, pParent)
	, m_strRegValue1(_T("None"))
	, m_strRegValue2(_T("None"))
	, m_strRegValue3(_T("None"))
	, m_strRegValue4(_T("None"))
	, m_strRegValue5(_T("None"))
	, m_strRegValue6(_T("None"))
	, m_strRegValue7(_T("None"))
	, m_strRegValue8(_T("None"))
	, m_nPort1(0)
	, m_nPort2(0)
	, m_nPort3(0)
	, m_nPort4(0)
	, m_nPort5(0)
	, m_nPort6(0)
	, m_nPort7(0)
	, m_nPort8(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CModbusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctl_IP1);
	DDX_Text(pDX, IDC_RegValue1, m_strRegValue1);
	DDX_Text(pDX, IDC_RegValue2, m_strRegValue2);
	DDX_Text(pDX, IDC_RegValue3, m_strRegValue3);
	DDX_Text(pDX, IDC_RegValue4, m_strRegValue4);
	DDX_Text(pDX, IDC_RegValue5, m_strRegValue5);
	DDX_Text(pDX, IDC_RegValue6, m_strRegValue6);
	DDX_Text(pDX, IDC_RegValue7, m_strRegValue7);
	DDX_Text(pDX, IDC_RegValue8, m_strRegValue8);
	DDX_Text(pDX, IDC_EDIT_Port1, m_nPort1);
	DDX_Text(pDX, IDC_EDIT_Port2, m_nPort2);
	DDX_Text(pDX, IDC_EDIT_Port3, m_nPort3);
	DDX_Text(pDX, IDC_EDIT_Port4, m_nPort4);
	DDX_Text(pDX, IDC_EDIT_Port5, m_nPort5);
	DDX_Text(pDX, IDC_EDIT_Port6, m_nPort6);
	DDX_Text(pDX, IDC_EDIT_Port7, m_nPort7);
	DDX_Text(pDX, IDC_EDIT_Port8, m_nPort8);
}

BEGIN_MESSAGE_MAP(CModbusDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnConnect, &CModbusDlg::OnBnClickedBtnconnect)
END_MESSAGE_MAP()


// CModbusDlg message handlers

BOOL CModbusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_bChk = true;
	CIPAddressCtrl * temp = &m_ctl_IP1;
	for (int i = 0; i < 8; i++)
	{
		temp->SetAddress(127,0,0,i+1);
		temp++;
	}
	//delete temp;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CModbusDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CModbusDlg::OnPaint()
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
HCURSOR CModbusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CModbusDlg::fnShowcomponent(bool b)
{
	GetDlgItem(IDC_IPADDRESS1)->EnableWindow(b);
	int nEditID = IDC_EDIT_Port1;
	for (int i = 0; i < 8; i++)
	{
		GetDlgItem(nEditID + i)->EnableWindow(b);
	}
	
}
#include <modbus.h>

void CModbusDlg::OnBnClickedBtnconnect()
{
	// TODO: Add your control notification handler code here
	if (m_bChk)
	{
		GetDlgItem(IDC_BtnConnect)->SetWindowTextW(L"Disconnect");
		m_bChk = false;
		fnShowcomponent(m_bChk);
	}
	else
	{
		GetDlgItem(IDC_BtnConnect)->SetWindowTextW(L"connect");
		m_bChk = true;
		fnShowcomponent(m_bChk);
		return;
	}

	UpdateData(true);

	char pchDevice_Ip_Addr[100];
	memset(pchDevice_Ip_Addr, 0, 100);
	BYTE	b1, b2, b3,b4;
	m_ctl_IP1.GetAddress(b1, b2, b3, b4);
	sprintf_s(pchDevice_Ip_Addr, "%d.%d.%d.%d", b1, b2, b3, b4);
	modbus_t *ctx[8];
	uint16_t data[8][2];
	int rc[8];

	ctx[0] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort1);
	ctx[1] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort2);
	ctx[2] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort3);
	ctx[3] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort4);
	ctx[4] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort5);
	ctx[5] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort6);
	ctx[6] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort7);
	ctx[7] = modbus_new_tcp(pchDevice_Ip_Addr, m_nPort8);

	if (ctx[0] == NULL || ctx[1] == NULL || ctx[2] == NULL || ctx[3] == NULL || ctx[4] == NULL || ctx[5] == NULL || ctx[6] == NULL || ctx[7] == NULL) {
		MessageBoxA(0, "Unable to create modbus context\n", 0, 0);
		return ;
	}

	CString * strTemp = &m_strRegValue1;
	for (int i = 0; i < 8; i++) {
		modbus_set_slave(ctx[i], 1);
		rc[i] = modbus_connect(ctx[i]);
		if (rc[i] == -1) {
			CString str;
			str.Format(L"Unable to connect to deviceNumber:  %d", i + 1);
			MessageBox(str);
			/*for (int j = 0; j <= i; j++) {
				modbus_close(ctx[j]);
				modbus_free(ctx[j]);
			}*/
			//return;
		}

		rc[i] = modbus_read_registers(ctx[i], 0, 2, data[i]);
		strTemp->Format(L"0x%X", data[i]);
		strTemp++;
		UpdateData(false);

		if (rc[i] == -1) {
			CString str;
			str.Format(L"Error reading data from deviceNumber: %d", i + 1);
			MessageBox(str);
			/*for (int j = 0; j < 8; j++) {
				modbus_close(ctx[j]);
				modbus_free(ctx[j]);
			}*/
			//return;
		}
	}

	// Process data from all slaves
	// ...

	for (int i = 0; i < 8; i++) {
		modbus_close(ctx[i]);
		modbus_free(ctx[i]);
	}
}
/*#include <modbus.h>

#define DEVICE_IP_ADDRESS "192.168.0.1"
#define DEVICE_PORT_1 502
#define DEVICE_PORT_2 503
#define DEVICE_PORT_3 504
#define DEVICE_PORT_4 505
#define DEVICE_PORT_5 506
#define DEVICE_PORT_6 507
#define DEVICE_PORT_7 508
#define DEVICE_PORT_8 509
#define DEVICE_ID 1

int main() {
  modbus_t *ctx[8];
  uint16_t data[8][2];
  int rc[8];

  ctx[0] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_1);
  ctx[1] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_2);
  ctx[2] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_3);
  ctx[3] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_4);
  ctx[4] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_5);
  ctx[5] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_6);
  ctx[6] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_7);
  ctx[7] = modbus_new_tcp(DEVICE_IP_ADDRESS, DEVICE_PORT_8);

  if (ctx[0] == NULL || ctx[1] == NULL || ctx[2] == NULL || ctx[3] == NULL || ctx[4] == NULL || ctx[5] == NULL || ctx[6] == NULL || ctx[7] == NULL) {
    fprintf(stderr, "Unable to create modbus context\n");
    return -1;
  }

  for (int i = 0; i < 8; i++) {
    modbus_set_slave(ctx[i], DEVICE_ID);
    rc[i] = modbus_connect(ctx[i]);
    if (rc[i] == -1) {
      fprintf(stderr, "Unable to connect to device %d\n", i + 1);
      for (int j = 0; j <= i; j++) {
        modbus_close(ctx[j]);
        modbus_free(ctx[j]);
      }
      return -1;
    }
    rc[i] = modbus_read_registers(ctx[i], 0, 2, data[i]);
    if (rc[i] == -1) {
      fprintf(stderr, "Error reading data from device %d\n", i + 1);
      for (int j = 0; j < 8; j++) {
        modbus_close(ctx[j]);
        modbus_free(ctx[j]);
      }
      return -1;
    }
  }

  // Process data from all slaves
  // ...

  for (int i = 0; i < 8; i++) {
    modbus_close(ctx[i]);
    modbus_free(ctx[i]);
  }

  return 0;
}
*/