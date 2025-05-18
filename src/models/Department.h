#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Object.h"
#include "../utils/Date.h"
#include "TxtWritingVisitor.h"

class Department : public Object {
private:
    std::string _headId;
    Date _foundationDate;
    std::string _subscription;

public:
    Department() = default;
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

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override;
};

#endif // !DEPARTMENT_H
