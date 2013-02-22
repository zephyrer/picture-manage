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
		// Connection�����Execute����:(_bstr_t CommandText, 
		// VARIANT * RecordsAffected, long Options ) 
		// ����CommandText�������ִ���ͨ����SQL���
		// ����RecordsAffected�ǲ�����ɺ���Ӱ�������, 
		// ����Options��ʾCommandText�����ͣ�adCmdText-�ı����adCmdTable-����
		// adCmdProc-�洢���̣�adCmdUnknown-δ֪
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