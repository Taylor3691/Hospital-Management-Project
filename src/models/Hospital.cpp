#include "Hospital.h"

Hospital::Hospital(
    const std::string& name,
    const std::string& address,
    const std::string& phone,
    std::vector<std::unique_ptr<Department>>& departments
) {
    _name = name;
    _address = address;
    _phone = phone;
    _departments.insert(
        _departments.end(),
        std::make_move_iterator(departments.begin()),
        std::make_move_iterator(departments.end())
    );
    departments.clear();
}

std::string Hospital::name() const {
    return _name;
}

std::string Hospital::address() const {
    return _address;
}

std::string Hospital::phone() const {
    return _phone;
}

const std::vector<std::unique_ptr<Department>>& Hospital::departments() const {
    return _departments;
}
