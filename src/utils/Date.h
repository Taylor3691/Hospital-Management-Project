#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using std::ostream;
using std::string;
class Date {
private:
	int _day;
	int _month;
	int _year;
    inline static int _daysInMonth[][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
    static bool isLeapYear(int);
    void normalize();
public:
	Date();
	Date(int,int,int);
	Date(int);
    Date(const string&);

    int day();
    int month();
    int year();
	
    static string toString(const Date& date);
    friend ostream& operator<<(ostream& os, const Date& date);
    static int getDay();
    static int getMonth();
    static int getYear();
    static Date getDate();
};

#endif
