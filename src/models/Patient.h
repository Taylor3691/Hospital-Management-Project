#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <memory>
#include <iterator>
#include "Person.h"
#include "MedicineUsage.h"

class Patient : public Person {
private:
    std::vector<std::string> _allergies;
    std::vector<std::unique_ptr<MedicineUsage>> _medicineUsages;

public:
    Patient(const std::string& id, const std::string& name, const Date& dob,
        const std::string& gender, const std::string& phone, const std::string& address,
        const std::vector<std::string>& allergies, std::vector<std::unique_ptr<MedicineUsage>>& usages);

public:
    std::vector<std::string>& allergies();
    std::vector<std::unique_ptr<MedicineUsage>>& medicineUsages();
};

#endif
