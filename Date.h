#ifndef _DATE_H
#define _DATE_H

#include <iostream>
using namespace std;
class Date
{
protected:
	int day;
	int month;
	int year;
public:
	Date(){}
	Date(int m, int d, int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	friend bool operator==(const Date &thi, const Date &tha);
	friend bool operator!=(const Date &thi, const Date &tha);
	friend bool operator>(const Date &thi, const Date &tha);
	friend bool operator<(const Date &thi, const Date &tha);
	friend bool operator>=(const Date &thi, const Date &tha);
	friend bool operator<=(const Date &thi, const Date &tha);
	friend ostream& operator<< (ostream &out, const Date &thi);
};

#endif
