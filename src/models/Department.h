// Department.h
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Object.h"
#include <string>
#include <ctime>

class Department : public Object {
public:
    Department(const std::string& id, const std::string& name, const std::string& headId,
               const std::tm& foundedDay, const std::string& subscription);

    // Triển khai từ Object
    std::string name() const override;
    std::string id() const override;

    // Getter
    std::string getHeadId() const;
    std::tm getFoundedDay() const;
    std::string getSubscription() const;

    // Setter
    void setHeadId(const std::string& headId);
    void setFoundedDay(const std::tm& foundedDay);
    void setSubscription(const std::string& subscription);

private:
    std::string _headId;
    std::tm _foundedDay;
    std::string _subscription;
};

#endif