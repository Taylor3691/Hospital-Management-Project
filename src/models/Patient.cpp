#include "Patient.h"

Patient::Patient(
    const std::string& id,
    const std::string& name,
    const Date& dob,
    const std::string& gender,
    const std::string& phone,
    const std::string& address,
    const std::vector<std::string>& allergies,
    std::vector<std::unique_ptr<MedicineUsage>>& usages
) : Person(id, name, dob, gender, phone, address) {
    _allergies = allergies;
    _medicineUsages.insert(
        _medicineUsages.end(),
        std::make_move_iterator(usages.begin()),
        std::make_move_iterator(usages.end())
    );
    usages.clear();
}

std::vector<std::string>& Patient::allergies() {
    return _allergies;
}

std::vector<std::unique_ptr<MedicineUsage>>& Patient::medicineUsages() {
    return _medicineUsages;
}
