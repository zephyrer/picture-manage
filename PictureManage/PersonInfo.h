#pragma once
#include "afx.h"
#include "ADOConn.h"

class DoctorInfo
{
public:
	int m_pid;
	char m_strName[50];
private:
	ADOConn* m_pConn;

public:
	DoctorInfo();
	void RefreshFromDatabase();
	void RefreshToDatabase();
	static DoctorInfo GetFromDatabase(int pid);
};

class PatientInfo
{
public:
	DoctorInfo m_doctor;
	int m_pid;
	char m_strName[50];
private:
	ADOConn* m_pConn;

public:
	PatientInfo();
	void RefreshFromDatabase();
	void RefreshToDatabase();
	static PatientInfo GetFromDatabase(int pid);
};
