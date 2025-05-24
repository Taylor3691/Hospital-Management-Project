#include "MedicineUsage.h"

MedicineUsage::MedicineUsage()
    : _usedQuantity(), _price() {}

MedicineUsage::MedicineUsage(
    const std::string& id,
    const std::string& recordId,
    const std::string& medicineId,
    int usedQuantity,
    double price,
    const std::string& description
)
    : BillableComponent(id, "")
    , _recordId(recordId)
    , _medicineId(medicineId)
    , _usedQuantity(usedQuantity)
    , _price(price)
    , _description(description) {}

std::string MedicineUsage::recordId() const {
    return _recordId;
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

void MedicineUsage::setRecordId(const std::string& recordId) {
    _recordId = recordId;
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

void MedicineUsage::acceptWrite(IVisitor* visitor, std::ostream& os) {

}

Object* MedicineUsage::clone() const {
    return new MedicineUsage(*this);
}
