#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>
#include "ServiceUsage.h"
#include "MedicalRecord.h"
#include "Patient.h"

class Bill {
    std::string _billId;
    std::vector<ServiceUsage*> _serviceUsages;
    const MedicalRecord* _medicineUsage;
    const Patient* _patient;
    std::string _status;
    double _totalPrice;

public:
    Bill(const std::string& id, const std::vector<ServiceUsage*> usages,
        MedicalRecord* record, Patient* patient, const std::string& status);

public:
    std::string id() const;
    std::vector<ServiceUsage*> serviceUsages() const;
    const MedicalRecord* medicineUsage() const;
    const Patient* patient() const;
    std::string status() const;
    double totalPrice() const;

public:
    void setId(const std::string& id);
    void setServiceUsages(const std::vector<ServiceUsage*>& usages);
    void setMedicineUsage(MedicalRecord* record);
    void setPatient(Patient* patient);
    void setStatus(const std::string& status);

public:
    void addServiceUsage(ServiceUsage* usage);
};

#endif
