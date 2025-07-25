#ifndef IVISITOR_H
#define IVISITOR_H

class Doctor;
class Nurse;
class Receptionist;
class Department;
class Patient;
class Medicine;
class TestService;
class MedicalRecord;
class MedicineUsage;
class ClinicalTest;
class RoomExamination;

class IVisitor {
public:
    virtual ~IVisitor() = default;
};

#endif // !IVISITOR_H
