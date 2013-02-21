
// PictureManageView.cpp : CPictureManageView 类的实现
//

#include "stdafx.h"
#include "PictureManage.h"

#include "PictureManageDoc.h"
#include "PictureManageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPictureManageView

IMPLEMENT_DYNCREATE(CPictureManageView, CView)

BEGIN_MESSAGE_MAP(CPictureManageView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPictureManageView 构造/析构

CPictureManageView::CPictureManageView()
{
	// TODO: 在此处添加构造代码

}

CPictureManageView::~CPictureManageView()
{
}

BOOL CPictureManageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPictureManageView 绘制

void CPictureManageView::OnDraw(CDC* /*pDC*/)
{
	CPictureManageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPictureManageView 打印

BOOL CPictureManageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPictureManageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPictureManageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPictureManageView 诊断

#ifdef _DEBUG
void CPictureManageView::AssertValid() const
{
	CView::AssertValid();
}

void CPictureManageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPictureManageDoc* CPictureManageView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureManageDoc)));
	return (CPictureManageDoc*)m_pDocument;
}
#endif //_DEBUG


// CPictureManageView 消息处理程序
