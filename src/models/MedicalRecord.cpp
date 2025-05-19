#include "MedicalRecord.h"

MedicalRecord::MedicalRecord(
    const std::string& id,
    const std::string& patientId
)
    : BillableComponent(id, "")
    , _patientId(patientId)
    , _state(std::make_unique<RegisteredState>())
    , _createdDate(Date::getDate())
    , _createdTime(Time::getCurrentTime()) {}

std::string MedicineUsage::patientId() const {
    return _patientId;
}

std::string MedicalRecord::roomId() const {
    return _roomId;
}

std::string MedicineUsage::doctorId() const {
    return _doctorId;
}

std::string MedicalRecord::diagnosisResult() const {
    return _diagnosisResult;
}

std::vector<const MedicineUsage*> MedicalRecord::prescribedMedicines() const {
    std::vector<const MedicineUsage*> medicines;
    medicines.reserve(_prescribedMedicines.size());
    for (const auto& medicine : _prescribedMedicines) {
        medicines.push_back(medicine);
    }
    return medicines;
}

std::vector<const ClinicalTest*> MedicalRecord::clinicalTests() const {
    std::vector<const ClinicalTest*> tests;
    tests.reserve(_clinicalTests.size());
    for (const auto& test : _clinicalTests) {
        tests.push_back(test);
    }
    return tests;
}

const ExaminationState* MedicalRecord::state() const {
    return _state.get();
}

Date MedicalRecord::createdDate() const {
    return _createdDate;
}

Time MedicalRecord::createdTime() const {
    return _createdTime;
}

double MedicalRecord::calculateFee() const {
    double totalCost = 0.0;

    for (const auto& medicine : _prescribedMedicines) {
        totalCost += medicine->calculateFee();
    }

    for (const auto& test : _clinicalTests) {
        totalCost += test->calculateFee();
    }

    return totalCost;
}

void MedicalRecord::assignToRoom(const std::string& roomId) {
    _roomId = roomId;
}

void MedicalRecord::startExamination(const std::string& doctorId) {
    _doctorId = doctorId;
}

void MedicalRecord::setDiagnosisResult(const std::string& result) {
    _diagnosisResult = result;
}

void MedicalRecord::prescribeMedicine(MedicineUsage* medicine) {
    _prescribedMedicines.push_back(medicine);
}

void MedicalRecord::orderClinicalTest(ClinicalTest* test) {
    _clinicalTests.push_back(test);
}

void MedicalRecord::compeleteExamination() {
    _state = std::make_unique<CompletedState>();
}

void MedicalRecord::changeState(std::unique_ptr<ExaminationState> state) {
    _state = std::move(state);
}
