#pragma once
#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")

class ADOConn
{
public:
	ADOConn(void);
	~ADOConn(void);

public:
	// ��ʼ�����������ݿ�
	bool  Connect(_bstr_t bstrConnect);
	// ִ�в�ѯ
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	// ִ��SQL��䣬Insert Update _variant_t
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void CloseConnect();
	char* GetLastError();

private:
	//���һ��ָ��Connection�����ָ��:
	_ConnectionPtr m_pConnection;
	//���һ��ָ��Recordset�����ָ��:
	_RecordsetPtr m_pRecordset;
	char m_error[255];
};
