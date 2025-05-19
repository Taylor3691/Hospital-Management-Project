#ifndef HEALTH_INSURANCE_H
#define HEALTH_INSURANCE_H

#include <string>
#include "Object.h"
#include "../utils/Date.h"

class HealthInsurance : public Object {
private:
    std::string _cardNumber;
    Date _issueDate;
    Date _expiryDate;
    double _coveragePercent;

public:
    HealthInsurance();
    HealthInsurance(const std::string& id, const std::string& name,
        const std::string& cardNumber, const Date& issueDate,
        const Date& expiryDate, double percent);

public:
    std::string cardNumber() const;
    Date issueDate() const;
    Date expiryDate() const;
    double coveragePercent() const;

public:
    void setCardNumber(const std::string& cardNumber);
    void setIssueDate(const Date& date);
    void setExpiryDate(const Date& date);
    void setCoveragePercent(const double& percent);

public:
    void acceptWrite(IVisitor* visitor, std::ostream& os) override {};
    bool checkValid() const;

};

#endif // !HEALTH_INSURANCE_H
