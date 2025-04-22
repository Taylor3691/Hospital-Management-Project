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
    Assignment(const Employee*, const Shift*, bool = false, bool = false);

    Employee* getEmployee();
    Shift* getShift();

    friend std::ostream& operator<<(std::ostream& os, const Assignment& record);
};

#endif
