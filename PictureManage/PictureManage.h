
// PictureManage.h : PictureManage Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CPictureManageApp:
// �йش����ʵ�֣������ PictureManage.cpp
//

class CPictureManageApp : public CWinApp
{
public:
	CPictureManageApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPictureManageApp theApp;