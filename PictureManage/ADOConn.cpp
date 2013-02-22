#include "StdAfx.h"
#include "ADOConn.h"

ADOConn* ADOConn::m_pConn=NULL;

ADOConn::ADOConn(void)
{
	ZeroMemory(m_error,sizeof(m_error));
}

ADOConn* ADOConn::GetInstance()
{
	if (m_pConn==NULL)
	{
		m_pConn=new ADOConn;
		bool bOk=m_pConn->Connect(g_bstrConnect);
		assert(bOk==true);
	}
	return m_pConn;
}

bool  ADOConn::Connect(_bstr_t bstrConnect)
{
	::CoInitialize(NULL);
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		m_pConnection->Open(bstrConnect,"","",adModeUnknown);
		return true;
	}
	catch(_com_error e)
	{
		strcpy(m_error, (char*)(e.Description()) );
		return false;
	}
}

_RecordsetPtr&  ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		strcpy(m_error, (char*)(e.Description()) );
	}
	return m_pRecordset;
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		// Connection对象的Execute方法:(_bstr_t CommandText, 
		// VARIANT * RecordsAffected, long Options ) 
		// 其中CommandText是命令字串，通常是SQL命令。
		// 参数RecordsAffected是操作完成后所影响的行数, 
		// 参数Options表示CommandText的类型：adCmdText-文本命令；adCmdTable-表名
		// adCmdProc-存储过程；adCmdUnknown-未知
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		strcpy(m_error, (char*)(e.Description()) );
		return false;
	}
}

void ADOConn::CloseConnect()
{
	if (m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	::CoUninitialize();
}

char* ADOConn::GetLastError()
{
	return m_error;
}