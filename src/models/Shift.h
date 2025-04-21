#ifndef SHIFT_H
#define SHIFT_H

#include <string>
#include <vector>
#include "../utils/Time.h"
#include "../utils/Date.h"
#include "Assignment.h"

class Shift {
private:
    std::string _shiftId;
    Time _startTime;
    Time _endTime;
    Date _workingDate;
    int _workingHours;
    std::vector<Assignment*> _employees;

public:
    Shift(const std::string& id, const std::string& schedule);

    void getWorkingHours();
    bool checkStatus();
    void releaseShift();
    void showEmployees();
    void addAssignment(const Assignment&);
};

#endif
