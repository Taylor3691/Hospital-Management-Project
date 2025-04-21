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

	void normalize();

public:
	Time();
	Time(int);
	Time(int, int);
	Time(int, int, int);
	Time(const std::string&);
	
	static std::string toString(int);
	static int toSec(const std::string&);
	static Time getCurrentTime();

	std::string toString() const;
	int toSec() const;
	bool operator<(const Time&) const;
	int operator-(const Time&) const;
};

#endif