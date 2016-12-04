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
	Date(int m, int d, int y) { setDate(m, d, y); }
	void setDate(int, int, int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	friend bool operator==(const Date &, const Date &);
	friend bool operator!=(const Date &, const Date &);
	friend bool operator>(const Date &, const Date &);
	friend bool operator<(const Date &, const Date &);
	friend bool operator>=(const Date &, const Date &);
	friend bool operator<=(const Date &, const Date &);
	friend ostream& operator<< (ostream &, Date &);
    friend istream& operator>> (istream &, Date &);
};

#endif
