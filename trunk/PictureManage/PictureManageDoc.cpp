
// PictureManageDoc.cpp : CPictureManageDoc 类的实现
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


// CPictureManageDoc 构造/析构

CPictureManageDoc::CPictureManageDoc()
{
	// TODO: 在此添加一次性构造代码

}

CPictureManageDoc::~CPictureManageDoc()
{
}

BOOL CPictureManageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CPictureManageDoc 序列化

void CPictureManageDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CPictureManageDoc 诊断

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


// CPictureManageDoc 命令
