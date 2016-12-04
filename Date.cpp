#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>

using namespace std;

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDate(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}

bool operator==(const Date &thi, const Date &tha)
{
	return thi.day == tha.day && thi.month == tha.month && thi.year == tha.year;
}

bool operator!=(const Date &thi, const Date &tha)
{
	return !operator==(tha,thi);
}

bool operator>(const Date &thi, const Date &tha)
{
	if (thi.year != tha.year)
		return thi.year > tha.year;
	else if (thi.month != tha.month)
		return thi.month > tha.month;
	else if (thi.day != tha.day)
		return thi.day > tha.day;
	return false;
}
bool operator<(const Date &thi, const Date &tha)
{
	return !operator>(thi, tha) && thi != tha;
}
bool operator>=(const Date &thi, const Date &tha)
{
	return operator==(thi, tha) || operator>(thi, tha);
}
bool operator<=(const Date &thi, const Date &tha)
{
	return operator==(thi, tha) || operator<(thi, tha);
}

/*ostream& operator<<(ostream& out, const Date&thi)
{
	(thi.month < 10) ? (out << '0' << thi.month) : (out << thi.month);
	out << '/';
	(thi.day < 10) ? (out << '0' << thi.day) : (out << thi.day);
	out << '/' << thi.year;
	return out;
}

istream &operator>>(istream &in, const Date &thi) {
	in.ignore();
	getline(in, thi.month, 2, '/');
	getline(in, thi.day, 2, '/');
	in >> thi.year;
	return in;
}
*/