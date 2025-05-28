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
    std::vector<std::unique_ptr<MedicineUsage>> _prescribedMedicines;
    std::vector<std::unique_ptr<ClinicalTest>> _clinicalTests;
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
    void setPatientId(const std::string& id);
    void setCreateDay(const std::string& date);
    void setCreateTime(const std::string& time);
public:
    double calculateFee() const override;
    void assignToRoom(const std::string& roomId);
    void startExamination(const std::string& doctorId);
    void setDiagnosisResult(const std::string& result);
    void prescribeMedicine(std::unique_ptr<MedicineUsage> medicine);
    void orderClinicalTest(std::unique_ptr<ClinicalTest> test);
    void compeleteExamination();
    void changeState(std::unique_ptr<ExaminationState> state);
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
    Object* clone() const override;

public:
    MedicalRecord& operator=(const MedicalRecord& other);
};

#endif // !MEDICAL_RECORD_H
