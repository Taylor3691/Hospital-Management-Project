#include "ServiceUsage.h"

ServiceUsage::ServiceUsage(Patient* patient, Service* service, const Date& registerDate, double cost) {
    _patient = patient;
    _service = service;
    _registerDate = registerDate;
    _cost = cost;
}

Patient* ServiceUsage::patient() const {
    return _patient;
}

Service* ServiceUsage::service() const {
    return _service;
}

Date ServiceUsage::registerDate() const {
    return _registerDate;
}

double ServiceUsage::cost() const {
    return _cost;
}

void ServiceUsage::setPatient(Patient* patient) {
    _patient = patient;
}

void ServiceUsage::setService(Service* service) {
    _service = service;
}

void ServiceUsage::setRegisterDate(const Date& date) {
    _registerDate = date;
}

void ServiceUsage::setCost(double cost) {
    _cost = cost;
}
