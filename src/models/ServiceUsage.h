#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H

#include "Patient.h"
#include "Service.h"
#include "../utils/Date.h"

class ServiceUsage {
private:
    Patient* _patient;
    Service* _service;
    Date _registerDate;
    double _cost;

public:
    ServiceUsage(Patient* patient, Service* service, const Date& registerDate, double cost);

public:
    Patient* patient() const;
    Service* service() const;
    Date registerDate() const;
    double cost() const;

public:
    void setPatient(Patient* patient);
    void setService(Service* service);
    void setRegisterDate(const Date& date);
    void setCost(double cost);
};

#endif
