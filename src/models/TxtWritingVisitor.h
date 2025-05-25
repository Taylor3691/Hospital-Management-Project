#ifndef TXT_WRITING_VISITOR_H
#define TXT_WRITING_VISITOR_H

#include <iomanip>
#include "../interfaces/IWritingVisitor.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Receptionist.h"
#include "Department.h"
#include "Patient.h"
#include "Medicine.h"
#include "TestService.h"
#include "MedicalRecord.h"
#include "MedicineUsage.h"
#include "ClinicalTest.h"
#include "RoomExamination.h"

class TxtWritingVisitor : public IWritingVisitor {
private:
    char _delim;

public:
    TxtWritingVisitor(char delim = '|');

public:
    void write(Patient* patient, std::ostream& os) override;
    void write(Doctor* doctor, std::ostream& os) override;
    void write(Nurse* nurse, std::ostream& os) override;
    void write(Receptionist* receptionist, std::ostream& os) override;
    void write(Department* department, std::ostream& os) override;
    void write(Medicine* medicine, std::ostream& os) override;
    void write(TestService* testService, std::ostream& os) override;
    void write(MedicalRecord* record, std::ostream& os, IWritingVisitor* write = nullptr) override;
    void write(MedicineUsage* usage, std::ostream& os) override;
    void write(ClinicalTest* result, std::ostream& os) override;
    void write(RoomExamination* room, std::ostream& os) override;
};

#endif // !TXT_WRITING_VISITOR_H
