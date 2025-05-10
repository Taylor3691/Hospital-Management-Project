#ifndef HEALTHINSURANCE_H
#define HEALTHINSURANCE_H

#include <string>
#include "../utils/Date.h"

class HealthInsurance {
private:
    std::string _insuranceId;
    double _serviceCoveragePercent;
    double _medicineCoveragePercent;
    Date _expiryDate;

public:
    std::string id() const;
    double serviceCoveragePercent() const;
    double medicineCoveragePercent() const;
    Date expiryDate() const;

public:
    void setId(const std::string& id);
    void setServiceCoveragePercent(double percent);
    void setMedicineCoveragePercent(double percent);
    void setExpiryDate(const Date& date);

public:
    bool checkExpired() const;
};

#endif
