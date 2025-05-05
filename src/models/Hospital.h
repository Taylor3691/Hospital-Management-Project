#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include <memory>
#include "Department.h"

class Hospital {
private:
    std::string _name;
    std::string _address;
    std::string _phone;
    std::vector<std::unique_ptr<Department>> _departments;

public:
    Hospital(const std::string& name, const std::string& address,
        const std::string& phone, std::vector<std::unique_ptr<Department>>& departments);

public:
    std::string name() const;
    std::string address() const;
    std::string phone() const;
    const std::vector<std::unique_ptr<Department>>& departments() const;
};

#endif
