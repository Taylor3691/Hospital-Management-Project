#include "Date.h"

bool Date::isLeapYear(const int& year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void Date::standardizeDate(Date* date) {
	if (date->_month > 12) {
		date->_year += date->_month / 12;
		date->_month = date->_month % 12;
	}
	int index = isLeapYear(date->_year) ? 1 : 0;
	while(date->_day > _daysInMonth[index][date->_month]) {
		date->_day -= _daysInMonth[index][date->_month];
		date->_month++;
		if (date->_month > 12) {
			date->_year++;
			date->_month = 1;
		}
	}
}

Date::Date() {
	_day = 1;
	_month = 1;
	_year = 1;
}

Date::Date(const int& day, const int& month, const int& year) {
	_day = abs(day);
	_month = abs(month);
	_year = abs(year);
	standardizeDate(this);
	if(_day == 0 || _month == 0 || _year == 0) {
		_day = _year = _month = 1;
		return;
	}
}

Date::Date(const int& day) {
	_day = abs(day);
	_month = 1;
	_year = 1;
	if(_day == 0){
		_day = 1;
		return;
	}
	standardizeDate(this);
}

Date::Date(const Date& date) {
	_day = date._day;
	_month = date._month;
	_year = date._year;
}

Date::~Date() {
}