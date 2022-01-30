// MySocket.cpp : 实现文件
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


// CMySocket 成员函数


void CMySocket::SetParent(CMYQQDlg* pDlg)
{
	m_pDlg = pDlg;
}


//void CMySocket::OnClose(int nErrorCode)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	if (nErrorCode == 0) m_pDlg->OnClose();
//	CAsyncSocket::OnClose(nErrorCode);
//}


//void CMySocket::OnConnect(int nErrorCode)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//}


//void CMySocket::OnReceive(int nErrorCode)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	if (nErrorCode == 0) m_pDlg->OnReceive();
//	CAsyncSocket::OnReceive(nErrorCode);
//}


//void CMySocket::OnSend(int nErrorCode)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	if (nErrorCode == 0) m_pDlg->OnSend();
//	CAsyncSocket::OnSend(nErrorCode);
//}


void CMySocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0) m_pDlg->OnAccept();
	CAsyncSocket::OnAccept(nErrorCode);
}


void CMySocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0) m_pDlg->OnClose();
	CAsyncSocket::OnClose(nErrorCode);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0) m_pDlg->OnReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}
