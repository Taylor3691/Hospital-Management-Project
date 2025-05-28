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

MedicalRecord::MedicalRecord(const MedicalRecord& other) {
    *this = other;
}

std::string MedicalRecord::patientId() const {
    return _patientId;
}

std::string MedicalRecord::roomId() const {
    return _roomId;
}

std::string MedicalRecord::doctorId() const {
    return _doctorId;
}

std::string MedicalRecord::diagnosisResult() const {
    return _diagnosisResult;
}

std::vector<const MedicineUsage*> MedicalRecord::prescribedMedicines() const {
    std::vector<const MedicineUsage*> medicines;
    medicines.reserve(_prescribedMedicines.size());
    for (const auto& medicine : _prescribedMedicines) {
        medicines.push_back(medicine.get());
    }
    return medicines;
}

std::vector<const ClinicalTest*> MedicalRecord::clinicalTests() const {
    std::vector<const ClinicalTest*> tests;
    tests.reserve(_clinicalTests.size());
    for (const auto& test : _clinicalTests) {
        tests.push_back(test.get());
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

void MedicalRecord::setPatientId(const std::string& patientId) {
    _patientId = patientId;
}

void MedicalRecord::setCreateDay(const std::string& date) {
    _createdDate = Date(date);
}

void MedicalRecord::setCreateTime(const std::string& time) {
    _createdTime = Time(time);
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

void MedicalRecord::prescribeMedicine(std::unique_ptr<MedicineUsage> medicine) {
    for (auto& ptr : _prescribedMedicines) {
        if (ptr.get()->id() == medicine.get()->id()) {
            ptr = std::move(medicine);
            return;
        }
    }
    _prescribedMedicines.push_back(std::move(medicine));
}

void MedicalRecord::orderClinicalTest(std::unique_ptr<ClinicalTest> test) {
    for (auto& ptr : _clinicalTests) {
        if (ptr.get()->id() == test.get()->id()) {
            ptr = std::move(test);
            return;
        }
    }
    _clinicalTests.push_back(std::move(test));
}

void MedicalRecord::compeleteExamination() {
    _state = std::make_unique<CompletedState>();
}

void MedicalRecord::changeState(std::unique_ptr<ExaminationState> state) {
    if (state == nullptr) {
        throw std::invalid_argument("State cannot be null");
    }
    _state = std::move(state);
}

void MedicalRecord::acceptWrite(IVisitor* visitor, std::ostream& os) {
    auto unit = (dynamic_cast<IWritingVisitor*>(visitor));
    unit->write(this, os, unit);
}

Object* MedicalRecord::clone() const {
    return new MedicalRecord(*this);
}

MedicalRecord& MedicalRecord::operator=(const MedicalRecord& other) {
    if (this != &other) {
        _id = other._id;
        _name = other._name;
        _patientId = other._patientId;
        _doctorId = other._doctorId;
        _roomId = other._roomId;
        _createdDate = other._createdDate;
        _createdTime = other._createdTime;
        _diagnosisResult = other._diagnosisResult;
        _prescribedMedicines.clear();
        _clinicalTests.clear();

        for (auto medicine : other.prescribedMedicines()) {
            auto unit = dynamic_cast<MedicineUsage*>(medicine->clone());
            _prescribedMedicines.push_back(std::unique_ptr<MedicineUsage>(unit));
        }

        for (auto test : other.clinicalTests()) {
            auto unit = dynamic_cast<ClinicalTest*>(test->clone());
            _clinicalTests.push_back(std::unique_ptr<ClinicalTest>(unit));
        }
        ExaminationState* tone;
        tone = other.state()->clone();
        std::unique_ptr<ExaminationState> state(tone);
        _state = std::move(state);

    }
    return *this;
}
