#include "Date.h"

Date::Date() {
    _day = _month = _year = 1;
}

bool Date::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void Date::normalize() {
    if (_month > 12) {
        _year += _month / 12;
        _month %= 12;
    }
    int index = isLeapYear(_year) ? 1 : 0;
    while (_day > _daysInMonth[index][_month]) {
        _day -= _daysInMonth[index][_month];
        _month++;
        if (_month > 12) {
            _year++;
            _month = 1;
        }
    }
}

Date::Date(int day, int month, int year) {
    _day = abs(day);
    _month = abs(month);
    _year = abs(year);
    normalize();
}

Date::Date(int days) : Date() {
    _day = abs(days);
    normalize();
    if (_day == 0) {
        _day = 1;
        return;
    }
}

Date::Date(const std::string& str) {
    sscanf_s(str.c_str(), "%d/%d/%d", &_day, &_month, &_year);
    _day = abs(_day);
    _month = abs(_month);
    _year = abs(_year);
    normalize();
}

Date::~Date() {
    //Destructor
}

int Date::day() const {
    return _day;
}

int Date::month() const {
    return _month;
}

int Date::year() const {
    return _year;
}

int Date::getDay() {
    time_t info = time(0);
    tm now;
    localtime_s(&now, &info);
    return now.tm_mday;
}

int Date::getMonth() {
    time_t info = time(0);
    tm now;
    localtime_s(&now, &info);
    return now.tm_mon + 1;
}

int Date::getYear() {
    time_t info = time(0);
    tm now;
    localtime_s(&now, &info);
    return now.tm_year + 1900;
}

Date Date::getDate() {
    time_t info = time(0);
    tm now;
    localtime_s(&now, &info);
    return Date(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
}

std::string Date::toString(const Date& date) {
    const int bufferSize = 12;
    char buffer[bufferSize];
    sprintf_s(buffer, "%02d/%02d/%d", date._day, date._month, date._year);
    return std::string(buffer);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    return os << Date::toString(date);
}

bool Date::operator<(const Date& date) const {
    if (_year < date._year) {
        return true;
    }

    if (_year == date._year && _month < date._month) {
        return true;
    }

    if (_year == date._year && _month == date._month && _day < date._day) {
        return true;
    }

    return false;
}

bool Date::operator>(const Date& date) const {
    if (_year > date._year) {
        return true;
    }

    if (_year == date._year && _month > date._month) {
        return true;
    }

    if (_year == date._year && _month == date._month && _day > date._day) {
        return true;
    }
    return false;
}

bool Date::operator==(const Date& date) const {
    if (_year != date._year || _month != date._month || _day != date._day) {
        return false;
    }
    return true;
}

bool Date::operator!=(const Date& date) const {
    return !(*this == date);
}

bool Date::operator<=(const Date& date) const {
    return *this < date || *this == date;
}

bool Date::operator>=(const Date& date) const {
    return *this > date || *this == date;
}
