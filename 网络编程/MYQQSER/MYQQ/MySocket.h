#pragma once
#include "MySocket.h"

// CMySocket ÃüÁîÄ¿±ê

class CMYQQDlg;
class CMySocket : public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
private:
	CMYQQDlg* m_pDlg;
public:
	void SetParent(CMYQQDlg* pDlg);
//	virtual void OnClose(int nErrorCode);
//	virtual void OnConnect(int nErrorCode);
//	virtual void OnReceive(int nErrorCode);
//	virtual void OnSend(int nErrorCode);
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


