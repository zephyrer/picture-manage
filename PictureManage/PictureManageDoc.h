
// PictureManageDoc.h : CPictureManageDoc ��Ľӿ�
//


#pragma once


class CPictureManageDoc : public CDocument
{
protected: // �������л�����
	CPictureManageDoc();
	DECLARE_DYNCREATE(CPictureManageDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CPictureManageDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


