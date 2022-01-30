
// MYQQDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MySocket.h"


// CMYQQDlg �Ի���
class CMYQQDlg : public CDialogEx
{
// ����
public:
	CMYQQDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYQQ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_SerName;
	int m_SerPort;
public:
//	afx_msg void OnLbnSelchangeList1();
	CString m_MSG;
	char m_send_buf[1024] = {0};
	CListBox m_sent;
	CListBox m_received;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
//	CMySocket m_sConnectSocket;
	void OnClose();
//	void OnConnect();
//	void OnReceive();
//	CStatic m_Sername;
//	CStatic m_Portname;
private:
//	CMySocket m_sListenScoket;
	CMySocket m_sConnectSocket;
public:
	void OnAccept();
	void OnReceive();
private:
//	int m;
	CMySocket m_sListenSocket;
};
