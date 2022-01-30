
// MYQQDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MYQQ.h"
#include "MYQQDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMYQQDlg �Ի���



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


// CMYQQDlg ��Ϣ�������

BOOL CMYQQDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (!AfxSocketInit())
	{
		AfxMessageBox(TEXT("�׽��ֳ�ʼ��ʧ�ܣ�"), MB_OK | MB_ICONSTOP);
		return FALSE;
	}
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_SerName = "localhost";
	m_SerPort = 12345;
	UpdateData(FALSE);

	m_sListenSocket.SetParent(this);
	m_sConnectSocket.SetParent(this);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMYQQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMYQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMYQQDlg::OnLbnSelchangeList1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}

// ���û���������������ťʱ��ִ�д˺���
void CMYQQDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL ifget=false;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC2)->EnableWindow(FALSE);
	ifget=m_sListenSocket.Create(m_SerPort); //��ָ���Ķ˿ڴ����������˼����׽��ֶ���ĵײ��׽���
	if (ifget == true) {
		// ��ʼ�����ͻ��˵���������
		m_sListenSocket.Listen();
	}
	else {
		OnClose();
	}
}


void CMYQQDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnClose();
}


void CMYQQDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nLen;
	int nSent;
	UpdateData(TRUE);
	// ����Ϣ��Ҫ������
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
			AfxMessageBox(TEXT("��Ϣ���ʹ���"), MB_OK | MB_ICONSTOP);
		}
		m_MSG.Empty();
		UpdateData(FALSE);
	}
}


void CMYQQDlg::OnClose()
{ 
	m_sConnectSocket.Close(); // �رտͻ��˵������׽���
	// ��ֹ��Ϣ���͵ĶԻ����еĿؼ�
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);

	// ��������б��
	while (m_sent.GetCount() != 0) m_sent.DeleteString(0);
	while (m_received.GetCount() != 0)
		m_received.DeleteString(0);

	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC1)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);

}

// ���׽����յ����������ѱ����յ���Ϣʱ��ͨ���׽������OnConnect�������ô˺���
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
//	// �����׽����еķ�������������Ϣ
//	nReceived = m_sConnectSocket.Receive(pBuf, nBuffSize);
//	if (nReceived != SOCKET_ERROR)  // ���ճɹ���
//	{
//		pBuf[nReceived] = NULL;  // ������ճɹ������ַ����Ľ�β��Ϊ��
//		StrReceived = pBuf;   // ����Ϣ���Ƶ���������
//		// ����Ϣ��ʾ�������յ������ݡ��б����
//		m_received.AddString(StrReceived);
//		UpdateData(FALSE);
//	} else{
//		AfxMessageBox(TEXT("��Ϣ���մ���"), MB_OK | MB_ICONSTOP);
//	}
//}


void CMYQQDlg::OnAccept()
{
	m_received.AddString(TEXT("�������յ���OnAccept��Ϣ"));  //��ʾ��Ϣ
	m_sListenSocket.Accept(m_sConnectSocket);
	// ���š���Ϣ���ı���͡����͡���ť
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
	// �����׽����еķ�������������Ϣ
	nReceived = m_sConnectSocket.Receive(pBuf, nBuffSize);
	if (nReceived != SOCKET_ERROR)  // ���ճɹ���
	{
		pBuf[nReceived] = NULL;  // ������ճɹ������ַ����Ľ�β��Ϊ��
		StrReceived.Format(_T("%s"), pBuf);   // ����Ϣ���Ƶ���������
		// ����Ϣ��ʾ�������յ������ݡ��б����
		m_received.AddString(StrReceived);
		UpdateData(FALSE);
	} else{
		AfxMessageBox(TEXT("��Ϣ���մ���"), MB_OK | MB_ICONSTOP);
		}
}
