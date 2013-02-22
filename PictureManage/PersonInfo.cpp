#include "stdafx.h"
#include "PersonInfo.h"

DoctorInfo::DoctorInfo()
{
	m_pConn=ADOConn::GetInstance();
}

void DoctorInfo::RefreshFromDatabase()
{
	DoctorInfo info=DoctorInfo::GetFromDatabase(this->m_pid);
	strcpy(info.m_strName, info.m_strName);
}

void DoctorInfo::RefreshToDatabase()
{
	ADOConn* pConn=ADOConn::GetInstance();

	_bstr_t bstrSelect;
	char temp[255];
	sprintf(temp, "update info set name='%s' where id=%d ", this->m_strName, this->m_pid);
	bstrSelect=temp;
	BOOL bok= pConn->ExecuteSQL(bstrSelect);
	assert(bok==TRUE);
}

DoctorInfo DoctorInfo::GetFromDatabase(int pid)
{
	DoctorInfo info;
	ADOConn* pConn=ADOConn::GetInstance();

	_bstr_t bstrSelect;
	char temp[255];
	sprintf(temp, "select id, name from info where id=%d", pid);
	bstrSelect=temp;
	_RecordsetPtr recordset=pConn->GetRecordSet(bstrSelect);

	if(!recordset->adoEOF) 
	{ 
		_variant_t valueid, valuename;

		//id
		valueid=recordset->GetCollect("id");
		info.m_pid=valueid.lVal;

		//name
		valuename=recordset->GetCollect("name"); 
		char name[255];
		strcpy(info.m_strName, (char*)(_bstr_t)valuename);
	}

	recordset->Close();

	return info;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
PatientInfo::PatientInfo()
{
	m_pConn=ADOConn::GetInstance();
}

void PatientInfo::RefreshFromDatabase()
{
	PatientInfo info=PatientInfo::GetFromDatabase(this->m_pid);
	strcpy(info.m_strName, info.m_strName);
}

void PatientInfo::RefreshToDatabase()
{
	ADOConn* pConn=ADOConn::GetInstance();

	_bstr_t bstrSelect;
	char temp[255];
	sprintf(temp, "update info set name='%s' where id=%d ", this->m_strName, this->m_pid);
	bstrSelect=temp;
	BOOL bok= pConn->ExecuteSQL(bstrSelect);
	assert(bok==TRUE);
}

PatientInfo PatientInfo::GetFromDatabase(int pid)
{
	PatientInfo info;
	ADOConn* pConn=ADOConn::GetInstance();

	_bstr_t bstrSelect;
	char temp[255];
	sprintf(temp, "select id, name from info where id=%d", pid);
	bstrSelect=temp;
	_RecordsetPtr recordset=pConn->GetRecordSet(bstrSelect);

	if(!recordset->adoEOF) 
	{ 
		_variant_t valueid, valuename;

		//id
		valueid=recordset->GetCollect("id");
		info.m_pid=valueid.lVal;

		//name
		valuename=recordset->GetCollect("name"); 
		char name[255];
		strcpy(info.m_strName, (char*)(_bstr_t)valuename);
	}

	recordset->Close();

	return info;
}