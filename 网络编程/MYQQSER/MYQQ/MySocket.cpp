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


//void CMySocket::OnClose(int nErrorCode)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	if (nErrorCode == 0) m_pDlg->OnClose();
//	CAsyncSocket::OnClose(nErrorCode);
//}


//void CMySocket::OnConnect(int nErrorCode)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//
//}


//void CMySocket::OnReceive(int nErrorCode)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	if (nErrorCode == 0) m_pDlg->OnReceive();
//	CAsyncSocket::OnReceive(nErrorCode);
//}


//void CMySocket::OnSend(int nErrorCode)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	if (nErrorCode == 0) m_pDlg->OnSend();
//	CAsyncSocket::OnSend(nErrorCode);
//}


void CMySocket::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0) m_pDlg->OnAccept();
	CAsyncSocket::OnAccept(nErrorCode);
}


void CMySocket::OnClose(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0) m_pDlg->OnClose();
	CAsyncSocket::OnClose(nErrorCode);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0) m_pDlg->OnReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}
