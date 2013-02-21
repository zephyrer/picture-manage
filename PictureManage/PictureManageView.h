
// PictureManageView.h : CPictureManageView ��Ľӿ�
//


#pragma once


class CPictureManageView : public CView
{
protected: // �������л�����
	CPictureManageView();
	DECLARE_DYNCREATE(CPictureManageView)

// ����
public:
	CPictureManageDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CPictureManageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PictureManageView.cpp �еĵ��԰汾
inline CPictureManageDoc* CPictureManageView::GetDocument() const
   { return reinterpret_cast<CPictureManageDoc*>(m_pDocument); }
#endif

