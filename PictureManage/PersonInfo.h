#pragma once
#include "afx.h"

class DoctorInfo
{
public:
	int pid;
	char name[50];

public:
	void RefreshFromDatabase();
	void RefreshToDatabase();
	static DoctorInfo GetFromDatabase(int pid);
}

class PatientInfo
{
public:
	DoctorInfo doctor;
	int pid;
	char name[50];

public:
	void RefreshFromDatabase();
	void RefreshToDatabase();
	static PatientInfo GetFromDatabase(int pid);
}
