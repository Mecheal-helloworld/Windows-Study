// MySocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MYQQ.h"
#include "MySocket.h"
#include "MYQQDlg.h"


// CMySocket

CMySocket::CMySocket()
{
	m_pDlg = NULL;
}

CMySocket::~CMySocket()
{
	m_pDlg = NULL;
}


// CMySocket ��Ա����


void CMySocket::SetParent(CMYQQDlg* pDlg)
{
	m_pDlg = pDlg;
}


void CMySocket::OnClose(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	// if (nErrorCode == 0) 
	if (nErrorCode == 0) m_pDlg->OnClose();
}


void CMySocket::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0) m_pDlg->OnConnect();
}

void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0) m_pDlg->OnReceive();
}


//void CMySocket::OnSend(int nErrorCode)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	if (nErrorCode == 0) m_pDlg->OnSend();
//	CAsyncSocket::OnSend(nErrorCode);
//}
