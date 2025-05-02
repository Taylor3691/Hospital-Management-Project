#include "Service.h"

Service::Service(
    const std::string& id,
    const std::string& name,
    double cost,
    const std::string& status,
    const std::string& description,
    Department* department
) {
    _serviceId = id;
    _name = name;
    _cost = cost;
    _status = status;
    _description = description;
    _department = department;
}

std::string Service::id() const {
    return _serviceId;
}

std::string Service::name() const {
    return _name;
}

double Service::cost() const {
    return _cost;
}

std::string Service::status() const {
    return _status;
}

std::string Service::description() const {
    return _description;
}

const Department* Service::department() const {
    return _department;
}

void Service::setId(const std::string& id) {
    _serviceId = id;
}

void Service::setName(const std::string& name) {
    _name = name;
}

void Service::setCost(double cost) {
    _cost = cost;
}

void Service::setStatus(const std::string& status) {
    _status = status;
}

void Service::setDescription(const std::string& description) {
    _description = description;
}

void Service::setDepartment(Department* department) {
    _department = department;
}
