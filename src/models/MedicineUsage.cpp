#include "MedicineUsage.h"

MedicineUsage::MedicineUsage()
    : _usedQuantity(), _price() {}

MedicineUsage::MedicineUsage(
    const std::string& id,
    const std::string& patientId,
    const std::string& doctorId,
    const std::string& medicineId,
    int usedQuantity,
    double price,
    const std::string& description
)
    : BillableComponent(id, "")
    , _patientId(patientId)
    , _doctorId(doctorId)
    , _medicineId(medicineId)
    , _usedQuantity(usedQuantity)
    , _price(price)
    , _description(description) {}

std::string MedicineUsage::patientId() const {
    return _patientId;
}

std::string MedicineUsage::doctorId() const {
    return _doctorId;
}

std::string MedicineUsage::medicineId() const {
    return _medicineId;
}

int MedicineUsage::usedQuantity() const {
    return _usedQuantity;
}

double MedicineUsage::price() const {
    return _price;
}

std::string MedicineUsage::description() const {
    return _description;
}

void MedicineUsage::setPatientId(const std::string& patientId) {
    _patientId = patientId;
}

void MedicineUsage::setDoctorId(const std::string& doctorId) {
    _doctorId = doctorId;
}

void MedicineUsage::setMedicineId(const std::string& medicineId) {
    _medicineId = medicineId;
}

void MedicineUsage::setUsedQuantity(int usedQuantity) {
    _usedQuantity = usedQuantity;
}

void MedicineUsage::setPrice(double price) {
    _price = price;
}

void MedicineUsage::setDescription(const std::string& description) {
    _description = description;
}

double MedicineUsage::calculateFee() const {
    return _price * _usedQuantity;
}
