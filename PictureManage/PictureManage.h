
// PictureManage.h : PictureManage Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "PersonInfo.h"

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
	virtual void OnFileOpen();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	//PatientInfo m_patient;
	//DoctorInfo m_doctor;

};

extern CPictureManageApp theApp;
