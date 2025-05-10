#ifndef SHIFT_H
#define SHIFT_H

#include <string>
#include <vector>
#include <cstdio>
#include "../utils/Time.h"
#include "../utils/Date.h"

class Shift {
private:
    std::string _shiftId;
    Time _startTime;
    Time _endTime;
    Date _workingDate;

public:
    Shift(const std::string& id, const Date& workingDate, const std::string& schedule);

public:
    std::string id() const;
    Time startTime() const;
    Time endTime() const;
    Date workingDate() const;

public:
    void setId(const std::string& id);
    void setStartTime(const Time& time);
    void setEndTime(const Time& time);
    void setWorkingDate(const Date& date);

public:
    double getWorkingHours();
    bool checkStatus();
};

#endif
