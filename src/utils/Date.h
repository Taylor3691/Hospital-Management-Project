#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <cstdio>
#include <string>
#include <iostream>

class Date {
private:
    inline static int _daysInMonth[][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    int _day;
    int _month;
    int _year;

    static bool isLeapYear(int year);
    void normalize();

public:
    Date();
    Date(int day, int month, int year);
    Date(int days);
    Date(const std::string& str);
    ~Date();
public:
    int day();
    int month();
    int year();

public:
    static int getDay();
    static int getMonth();
    static int getYear();
    static Date getDate();
    static std::string toString(const Date& date);
public:
    bool operator<(const Date& date);
    bool operator>(const Date& date);
    bool operator==(const Date& date);
    bool operator!=(const Date& date) const;
    bool operator<=(const Date& date);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif
