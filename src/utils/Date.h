#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	Date(int day, int month, int year);
	Date(int day);
    Date(const std::string& str);

    int day();
    int month();
    int year();

    static int getDay();
    static int getMonth();
    static int getYear();
    static Date getDate();
};

#endif
