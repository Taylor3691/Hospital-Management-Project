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
	Time(int s);
	Time(int m, int s);
	Time(int h, int m, int s);
	Time(const std::string& str);
	
	static std::string toString(int s);
	static int toSec(const std::string& str);
	static Time getCurrentTime();

	std::string toString() const;
	int toSec() const;
	bool operator<(const Time& t) const;
	int operator-(const Time& t) const;
};

#endif
