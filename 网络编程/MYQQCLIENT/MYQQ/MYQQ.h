
// MYQQ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMYQQApp: 
// �йش����ʵ�֣������ MYQQ.cpp
//

class CMYQQApp : public CWinApp
{
public:
	CMYQQApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMYQQApp theApp;