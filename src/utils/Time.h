#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <cstdio>
#include <string>
#include <stdexcept>

class Time {
private:
    int _h;
    int _m;
    int _s;

public:
    Time();
    Time(int s);
    Time(int m, int s);
    Time(int h, int m, int s);
    Time(const std::string& str);

public:
    int hour() const;
    int minute() const;
    int second() const;

public:
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

public:
    static std::string toString(int s);
    static int toSec(const std::string& str);
    static Time getCurrentTime();

private:
    void normalize();

public:
    std::string toString() const;
    int toSec() const;

public:
    bool operator<(const Time& t) const;
    bool operator<=(const Time& t) const;
    bool operator>(const Time& t) const;
    bool operator>=(const Time& t) const;
    bool operator==(const Time& t) const;
    bool operator!=(const Time& t) const;
    int operator-(const Time& t) const;
};

#endif // !TIME_H
