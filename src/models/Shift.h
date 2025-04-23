#ifndef SHIFT_H
#define SHIFT_H

#include <string>
#include <vector>
#include <cstdio>
#include "../utils/Time.h"
#include "../utils/Date.h"
#include "Assignment.h"

class Shift {
private:
    std::string _shiftId;
    Time _startTime;
    Time _endTime;
    Date _workingDate;
    std::vector<Assignment*> _employees;

public:
    Shift(const std::string& id, const Date& workingDate, const std::string& schedule);

    double getWorkingHours();
    bool checkStatus();
    void releaseShift(); // redundant, will be managed by `Database` class or somewhere else
    void showEmployees();
    void addAssignment(Assignment* assignment);
};

#endif
