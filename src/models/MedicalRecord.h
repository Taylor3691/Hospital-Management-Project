#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include "MedicineUsage.h"
#include "Patient.h"
#include "Doctor.h"
#include "../utils/Date.h"
class MedicalRecord{
private:
    std::string _recordId;
    Patient* _patient;
    Doctor* _doctor;
    std::string _diagnosis;
    std::string _treatment;
    Date _date;
    std::vector<MedicineUsage> _prescribedMedicines;

public:
    MedicalRecord();
    MedicalRecord(std::string id, Patient* patient, Doctor* doctor,
        std::string diagnosis, std::string treatment, std::vector<MedicineUsage> medicine);
    ~MedicalRecord();

public:
    std::string id();
    Patient* patient();
    Doctor* doctor();
    std::string diagnosis();
    std::string treatment();
    Date& date();
    std::vector<MedicineUsage>& prescribedMedicines();
    void setID(std::string id);
    void setPatient(Patient* patient);
    void setDoctor(Doctor* doctor);
    void setDate(const Date& date);

public:
    bool addMedicineUsage(const MedicineUsage& medicine);
    bool removeMedicineUsage(std::string id);
};

#endif
