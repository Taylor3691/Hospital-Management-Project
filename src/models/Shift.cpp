#include "Shift.h"

Shift::Shift(const std::string& id, const Date& workingDate, const std::string& schedule) {
    _shiftId = id;
    _workingDate = workingDate;

    int h1, h2, m1, m2;
    sscanf_s(schedule.c_str(), "%d:%d - %d:%d", &h1, &m1, &h2, &m2);
    _startTime = Time(h1, m1, 0);
    _endTime = Time(h2, m2, 0);
}

std::string Shift::id() const {
    return _shiftId;
}

Time Shift::startTime() const {
    return _startTime;
}

Time Shift::endTime() const {
    return _endTime;
}

Date Shift::workingDate() const {
    return _workingDate;
}

void Shift::setId(const std::string& id) {
    _shiftId = id;
}

void Shift::setStartTime(const Time& time) {
    _startTime = time;
}

void Shift::setEndTime(const Time& time) {
    _endTime = time;
}

void Shift::setWorkingDate(const Date& date) {
    _workingDate = date;
}

double Shift::getWorkingHours() {
    return (_endTime - _startTime) / 3600.0;
}

bool Shift::checkStatus() {
    Time now = Time::getCurrentTime();
    return _startTime <= now && now < _endTime;
}
