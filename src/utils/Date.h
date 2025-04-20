#ifndef DATE_H_
#define DATE_H_
#include <iostream>

class Date {
private:
		int _day;
		int _month;
		int _year;
		inline static const int _daysInMonth[][13] = {
			{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
			{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
		};
		static void standardizeDate(Date*);
		static bool isLeapYear(const int& year);
public:
	Date();
	Date(const int&,const int&,const int&);
	Date(const int&);
	Date(const Date&);
	~Date();
};


#endif // !DATE_H_
