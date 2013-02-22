#pragma once
#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")

class ADOConn
{
public:
	ADOConn(void);
	~ADOConn(void);

public:
	// 初始化—连接数据库
	bool  Connect(_bstr_t bstrConnect);
	// 执行查询
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	// 执行SQL语句，Insert Update _variant_t
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void CloseConnect();
	char* GetLastError();

private:
	//添加一个指向Connection对象的指针:
	_ConnectionPtr m_pConnection;
	//添加一个指向Recordset对象的指针:
	_RecordsetPtr m_pRecordset;
	char m_error[255];
};
