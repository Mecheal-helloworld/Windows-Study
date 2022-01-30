
// MYQQDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MYQQ.h"
#include "MYQQDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMYQQDlg 对话框



CMYQQDlg::CMYQQDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYQQ_DIALOG, pParent)
	, m_SerName(_T(""))
	, m_SerPort(0)
	, m_MSG(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  m = 0;
}

void CMYQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SerName);
	DDX_Text(pDX, IDC_EDIT2, m_SerPort);
	DDX_Text(pDX, IDC_EDIT3, m_MSG);
	DDX_Control(pDX, IDC_LIST1, m_sent);
	DDX_Control(pDX, IDC_LIST2, m_received);
	//  DDX_Control(pDX, IDC_STATIC_SERVNAME, m_Sername);
	//  DDX_Control(pDX, IDC_STATIC_SERVPORT, m_Portname);
}

BEGIN_MESSAGE_MAP(CMYQQDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_LBN_SELCHANGE(IDC_LIST1, &CMYQQDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMYQQDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMYQQDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMYQQDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMYQQDlg 消息处理程序

BOOL CMYQQDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (!AfxSocketInit())
	{
		AfxMessageBox(TEXT("套接字初始化失败！"), MB_OK | MB_ICONSTOP);
		return FALSE;
	}
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_SerName = "localhost";
	m_SerPort = 12345;
	UpdateData(FALSE);

	m_sListenSocket.SetParent(this);
	m_sConnectSocket.SetParent(this);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMYQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMYQQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMYQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMYQQDlg::OnLbnSelchangeList1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

// 当用户单击“监听”按钮时，执行此函数
void CMYQQDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL ifget=false;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC2)->EnableWindow(FALSE);
	ifget=m_sListenSocket.Create(m_SerPort); //用指定的端口创建服务器端监听套接字对象的底层套接字
	if (ifget == true) {
		// 开始监听客户端的连接请求
		m_sListenSocket.Listen();
	}
	else {
		OnClose();
	}
}


void CMYQQDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}


void CMYQQDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nLen;
	int nSent;
	UpdateData(TRUE);
	// 有消息需要发送吗
	if (!m_MSG.IsEmpty())
	{
		nLen = m_MSG.GetLength()*2;
		memcpy(m_send_buf, m_MSG, nLen);
		nSent = m_sConnectSocket.Send(m_send_buf, nLen);
		if (nSent != SOCKET_ERROR)
		{
			m_sent.AddString(m_MSG);
			UpdateData(FALSE);
		}
		else {
			AfxMessageBox(TEXT("信息发送错误！"), MB_OK | MB_ICONSTOP);
		}
		m_MSG.Empty();
		UpdateData(FALSE);
	}
}


void CMYQQDlg::OnClose()
{ 
	m_sConnectSocket.Close(); // 关闭客户端的连接套接字
	// 禁止消息发送的对话框中的控件
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);

	// 清除两个列表框
	while (m_sent.GetCount() != 0) m_sent.DeleteString(0);
	while (m_received.GetCount() != 0)
		m_received.DeleteString(0);

	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC1)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);

}

// 当套接字收到连接请求已被接收的消息时，通过套接字类的OnConnect函数调用此函数
//void CMYQQDlg::OnConnect()
//{
//	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
//	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
//	GetDlgItem(IDC_STATIC3)->EnableWindow(TRUE);
//	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
//}


//void CMYQQDlg::OnReceive()
//{
//	char *pBuf = new char[1025];
//	int nBuffSize = 1024;
//	int nReceived;
//	CString StrReceived;
//
//	// 接收套接字中的服务器发来的消息
//	nReceived = m_sConnectSocket.Receive(pBuf, nBuffSize);
//	if (nReceived != SOCKET_ERROR)  // 接收成功吗？
//	{
//		pBuf[nReceived] = NULL;  // 如果接收成功，将字符串的结尾置为空
//		StrReceived = pBuf;   // 将消息复制到串变量中
//		// 将消息显示到“接收到的数据”列表框中
//		m_received.AddString(StrReceived);
//		UpdateData(FALSE);
//	} else{
//		AfxMessageBox(TEXT("信息接收错误！"), MB_OK | MB_ICONSTOP);
//	}
//}


void CMYQQDlg::OnAccept()
{
	m_received.AddString(TEXT("服务器收到了OnAccept消息"));  //显示信息
	m_sListenSocket.Accept(m_sConnectSocket);
	// 开放“消息”文本框和“发送”按钮
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
}


void CMYQQDlg::OnReceive()
{
	char *pBuf = new char[1024];
	int nBuffSize = 1024;
	int nReceived;
	CString StrReceived;
	//
	// 接收套接字中的服务器发来的消息
	nReceived = m_sConnectSocket.Receive(pBuf, nBuffSize);
	if (nReceived != SOCKET_ERROR)  // 接收成功吗？
	{
		pBuf[nReceived] = NULL;  // 如果接收成功，将字符串的结尾置为空
		StrReceived.Format(_T("%s"), pBuf);   // 将消息复制到串变量中
		// 将消息显示到“接收到的数据”列表框中
		m_received.AddString(StrReceived);
		UpdateData(FALSE);
	} else{
		AfxMessageBox(TEXT("信息接收错误！"), MB_OK | MB_ICONSTOP);
		}
}
