#include "Bill.h"

Bill::Bill(
    const std::string& id,
    const std::vector<ServiceUsage*> usages,
    MedicalRecord* record,
    Patient* patient,
    const std::string& status
) {
    _billId = id;
    _serviceUsages = usages;
    _medicineUsage = record;
    _patient = patient;
    _status = status;
    _totalPrice = 0.0;
}

std::string Bill::id() const {
    return _billId;
}

std::vector<ServiceUsage*> Bill::serviceUsages() const {
    return _serviceUsages;
}

const MedicalRecord* Bill::medicineUsage() const {
    return _medicineUsage;
}

const Patient* Bill::patient() const {
    return _patient;
}

std::string Bill::status() const {
    return _status;
}

double Bill::totalPrice() const {
    return _totalPrice;
}

void Bill::setId(const std::string& id) {
    _billId = id;
}

void Bill::setServiceUsages(const std::vector<ServiceUsage*>& usages) {
    _serviceUsages = usages;
}

void Bill::setMedicineUsage(MedicalRecord* record) {
    _medicineUsage = record;
}

void Bill::setPatient(Patient* patient) {
    _patient = patient;
}

void Bill::setStatus(const std::string& status) {
    _status = status;
}
