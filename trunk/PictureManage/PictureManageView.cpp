
// PictureManageView.cpp : CPictureManageView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPictureManageView ����/����

CPictureManageView::CPictureManageView()
{
	// TODO: �ڴ˴���ӹ������

}

CPictureManageView::~CPictureManageView()
{
}

BOOL CPictureManageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPictureManageView ����

void CPictureManageView::OnDraw(CDC* /*pDC*/)
{
	CPictureManageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPictureManageView ��ӡ

BOOL CPictureManageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPictureManageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPictureManageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CPictureManageView ���

#ifdef _DEBUG
void CPictureManageView::AssertValid() const
{
	CView::AssertValid();
}

void CPictureManageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPictureManageDoc* CPictureManageView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureManageDoc)));
	return (CPictureManageDoc*)m_pDocument;
}
#endif //_DEBUG


// CPictureManageView ��Ϣ�������
