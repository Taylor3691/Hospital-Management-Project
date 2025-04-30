#ifndef PATIENTMANAGER_H_
#define PATIENTMANAGER_H_
#include "Patient.h"
#include <iostream>
#include <vector>

class PatientManager {
private:
    std::vector<Patient*> _allPatients;

private:
    PatientManager();
    ~PatientManager();

public:
    void addPatient(Patient* patient);
    void removePatient(std::string id);
    Patient* getPatientById(std::string id);
    std::vector<Patient*> getPatientByName(std::string name);
};

#endif // !PatientManager
