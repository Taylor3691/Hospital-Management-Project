#include "Time.h"

Time::Time() {
    _h = _m = _s = 0;
}

Time::Time(int s) : Time() {
    _s = abs(s);
    normalize();
}

Time::Time(int m, int s) {
    _h = 0;
    _m = abs(m);
    _s = abs(s);
    normalize();
}

Time::Time(int h, int m, int s) {
    _h = abs(h);
    _m = abs(m);
    _s = abs(s);
    normalize();
}

Time::Time(const std::string& str) {
    sscanf_s(str.c_str(), "%d:%d:%d", &_h, &_m, &_s);
    _h = abs(_h);
    _m = abs(_m);
    _s = abs(_s);
    normalize();
}

int Time::hour() const {
    return _h;
}

int Time::minute() const {
    return _m;
}

int Time::second() const {
    return _s;
}

void Time::setHour(int h) {
    _h = abs(h);
}

void Time::setMinute(int m) {
    _m = abs(m);
    normalize();
}

void Time::setSecond(int s) {
    _s = abs(s);
    normalize();
}

std::string Time::toString(int s) {
    Time t(s);
    return t.toString();
}

int Time::toSec(const std::string& str) {
    Time t(str);
    return t.toSec();
}

Time Time::getCurrentTime() {
    time_t info = time(0);
    tm now;
    localtime_s(&now, &info);
    return Time(now.tm_hour, now.tm_min, now.tm_sec);
}

void Time::normalize() {
    _m += _s / 60;
    _s %= 60;

    _h += _m / 60;
    _m %= 60;
}

std::string Time::toString() const {
    const int bufferSize = 9;
    std::string buffer(bufferSize, 0);
    sprintf_s(const_cast<char*>(buffer.c_str()), bufferSize, "%02d:%02d:%02d", _h, _m, _s);
    return buffer;
}

int Time::toSec() const {
    return _h * 3600 + _m * 60 + _s;
}

bool Time::operator<(const Time& t) const {
    if (_h > t._h) {
        return 0;
    }
    if (_h < t._h) {
        return 1;
    }
    if (_m > t._m) {
        return 0;
    }
    if (_m < t._m) {
        return 1;
    }
    if (_s > t._s) {
        return 0;
    }
    if (_s < t._s) {
        return 1;
    }
    return 0;
}

bool Time::operator<=(const Time& t) const {
    return *this < t || *this == t;
}

bool Time::operator>(const Time& t) const {
    return !(*this <= t);
}

bool Time::operator>=(const Time& t) const {
    return *this > t || *this == t;
}

bool Time::operator==(const Time& t) const {
    return _h == t._h && _m == t._m && _s == t._s;
}

bool Time::operator!=(const Time& t) const {
    return !(*this == t);
}

int Time::operator-(const Time& t) const {
    if (*this < t) {
        throw std::runtime_error("cannot subtract a later time");
    }
    return this->toSec() - t.toSec();
}
