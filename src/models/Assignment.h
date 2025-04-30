#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include "Employee.h"
#include "Shift.h"

class Assignment {
private:
    Employee* _employee;
    Shift* _shift;
    bool _isNightShift;
    bool _isHoliday;

public:
    Assignment(Employee* employee, Shift* shift, bool isNight = false, bool isHoliday = false);

public:
    Employee* getEmployee();
    Shift* getShift();
};

#endif
