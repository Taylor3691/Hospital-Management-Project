#ifndef DATE_H_
#define DATE_H_

class Date {
private:
		int _day;
		int _month;
		int _year;
public:
	Date();
	Date(const int&,const int&,const int&);
	Date(const int&);
};


#endif // !DATE_H_
