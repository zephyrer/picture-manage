
// PictureManageDoc.cpp : CPictureManageDoc ���ʵ��
//

#include "stdafx.h"
#include "PictureManage.h"

#include "PictureManageDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPictureManageDoc

IMPLEMENT_DYNCREATE(CPictureManageDoc, CDocument)

BEGIN_MESSAGE_MAP(CPictureManageDoc, CDocument)
END_MESSAGE_MAP()


// CPictureManageDoc ����/����

CPictureManageDoc::CPictureManageDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CPictureManageDoc::~CPictureManageDoc()
{
}

BOOL CPictureManageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CPictureManageDoc ���л�

void CPictureManageDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CPictureManageDoc ���

#ifdef _DEBUG
void CPictureManageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPictureManageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPictureManageDoc ����
