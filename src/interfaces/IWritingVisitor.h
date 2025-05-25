#ifndef IWRITING_VISITOR_H
#define IWRITING_VISITOR_H

#include <iostream>
#include "IVisitor.h"

class IWritingVisitor : public IVisitor {
public:
    virtual ~IWritingVisitor() = default;

public:
    virtual void write(Patient* patient, std::ostream& os) = 0;
    virtual void write(Doctor* doctor, std::ostream& os) = 0;
    virtual void write(Nurse* nurse, std::ostream& os) = 0;
    virtual void write(Receptionist* receptionist, std::ostream& os) = 0;
    virtual void write(Department* department, std::ostream& os) = 0;
    virtual void write(Medicine* medicine, std::ostream& os) = 0;
    virtual void write(TestService* testService, std::ostream& os) = 0;
    virtual void write(MedicalRecord* record, std::ostream& os, IWritingVisitor* write = nullptr) = 0;
    virtual void write(MedicineUsage* usage, std::ostream& os) = 0;
    virtual void write(ClinicalTest* result, std::ostream& os) = 0;
    virtual void write(RoomExamination* room, std::ostream& os) = 0;
};

#endif // !IWRITING_VISITOR_H
