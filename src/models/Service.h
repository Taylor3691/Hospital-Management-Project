#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Department.h"

class Service {
private:
    std::string _serviceId;
    std::string _name;
    double _cost;
    std::string _status;
    std::string _description;
    Department* _department;

public:
    Service(const std::string& id, const std::string& name, double cost, const std::string& status,
        const std::string& description, Department* department);

public:
    std::string id() const;
    std::string name() const;
    double cost() const;
    std::string status() const;
    std::string description() const;
    Department* department() const;

public:
    void setId(const std::string& id);
    void setName(const std::string& name);
    void setCost(double cost);
    void setStatus(const std::string& status);
    void setDescription(const std::string& description);
    void setDepartment(Department* department);
};

#endif
