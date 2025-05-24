#ifndef HEALTH_INSURANCE_H
#define HEALTH_INSURANCE_H

#include <string>
#include "Object.h"
#include "../utils/Date.h"

class HealthInsurance : public Object {
private:
    Date _issueDate;
    Date _expiryDate;
    double _coveragePercent;

public:
    HealthInsurance();
    HealthInsurance(const std::string& id, const Date& issueDate,
        const Date& expiryDate, double percent);

public:
    Date issueDate() const;
    Date expiryDate() const;
    double coveragePercent() const;

public:
    void setIssueDate(const Date& date);
    void setExpiryDate(const Date& date);
    void setCoveragePercent(const double& percent);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override {};
    bool checkValid() const;
};

#endif // !HEALTH_INSURANCE_H
