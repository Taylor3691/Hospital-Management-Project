#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Object.h"
#include "../utils/Date.h"

class Department : public Object {
private:
    std::string _headId;
    Date _foundationDate;
    std::string _subscription;

public:
    Department(const std::string& id, const std::string& name,
        const std::string& headId, const Date& date,
        const std::string& subscription);

public:
    std::string headId() const;
    Date foundationDate() const;
    std::string subscription() const;

public:
    void setHeadId(const std::string& id);
    void setFoundationDate(const Date& date);
    void setSubscription(const std::string& subscription);
};

#endif // !DEPARTMENT_H
