#pragma once
#include "afx.h"

typedef struct DOCTORINFO
{
	int pid;
	char name[50];
} DoctorInfo, *PDoctorInfo;

typedef struct PATIENTINFO
{
	DoctorInfo doctor;
	int pid;
	char name[50];
}PatientInfo, * PPatientInfo;
