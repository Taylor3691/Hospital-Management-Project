#ifndef MEDICAL_RECORD_H
#define MEDICAL_RECORD_H

#include <vector>
#include <memory>
#include "BillableComponent.h"
#include "MedicineUsage.h"
#include "ClinicalTest.h"
#include "RegisteredState.h"
#include "CompletedState.h"
#include "../interfaces/IWritingVisitor.h"
#include "../utils/Date.h"
#include "../utils/Time.h"

class MedicalRecord : public BillableComponent {
private:
    std::string _patientId;
    std::string _roomId;
    std::string _doctorId;
    std::string _diagnosisResult;
    std::vector<MedicineUsage*> _prescribedMedicines;
    std::vector<ClinicalTest*> _clinicalTests;
    std::unique_ptr<ExaminationState> _state;
    Date _createdDate;
    Time _createdTime;

public:
    MedicalRecord() = default;
    MedicalRecord(const std::string& id, const std::string& patientId);
    MedicalRecord(const MedicalRecord& other);

public:
    std::string patientId() const;
    std::string roomId() const;
    std::string doctorId() const;
    std::string diagnosisResult() const;
    std::vector<const MedicineUsage*> prescribedMedicines() const;
    std::vector<const ClinicalTest*> clinicalTests() const;
    const ExaminationState* state() const;
    Date createdDate() const;
    Time createdTime() const;

public:
    double calculateFee() const override;
    void assignToRoom(const std::string& roomId);
    void startExamination(const std::string& doctorId);
    void setDiagnosisResult(const std::string& result);
    void prescribeMedicine(MedicineUsage* medicine);
    void orderClinicalTest(ClinicalTest* test);
    void compeleteExamination();
    void changeState(std::unique_ptr<ExaminationState> state);
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;

public:
    MedicalRecord& operator=(const MedicalRecord& other);
};

#endif // !MEDICAL_RECORD_H
