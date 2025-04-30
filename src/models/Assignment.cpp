#include "Assignment.h"

Assignment::Assignment(Employee* employee, Shift* shift, bool isNight, bool isHoliday) {
    _employee = employee;
    _shift = shift;
    _isNightShift = isNight;
    _isHoliday = isHoliday;
}

Employee* Assignment::getEmployee() {
    return _employee;
}

Shift* Assignment::getShift() {
    return _shift;
}
