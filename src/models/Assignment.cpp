#include "Assignment.h"

Assignment::Assignment(Employee* employee, Shift* shift, bool isNight, bool isHoliday) {
    _employee = employee;
    _shift = shift;
    _isNightShift = isNight;
    _isHoliday = isHoliday;
}

Employee* Assignment::employee() const {
    return _employee;
}

Shift* Assignment::shift() const {
    return _shift;
}

bool Assignment::isNightShift() const {
    return _isNightShift;
}

bool Assignment::isHoliday() const {
    return _isHoliday;
}
