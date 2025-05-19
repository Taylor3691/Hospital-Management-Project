#ifndef MEDICINE_USAGE_H
#define MEDICINE_USAGE_H

#include "BillableComponent.h"

class MedicineUsage : public BillableComponent {
private:
    std::string _patientId;
    std::string _doctorId;
    std::string _medicineId;
    int _usedQuantity;
    double _price;
    std::string _description;

public:
    MedicineUsage();
    MedicineUsage(const std::string& id, const std::string& patientId,
        const std::string& doctorId, const std::string& medicineId,
        int usedQuantity, double price, const std::string& description);

public:
    std::string patientId() const;
    std::string doctorId() const;
    std::string medicineId() const;
    int usedQuantity() const;
    double price() const;
    std::string description() const;

public:
    void setPatientId(const std::string& patientId);
    void setDoctorId(const std::string& doctorId);
    void setMedicineId(const std::string& medicineId);
    void setUsedQuantity(int usedQuantity);
    void setPrice(double price);
    void setDescription(const std::string& description);

public:
    double calculateFee() const override;
};

#endif // !MEDICINE_USAGE_H
