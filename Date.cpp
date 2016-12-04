#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <iomanip>

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

ostream& operator<<(ostream& out, Date &date)
//Printing the Date to the file-->Not needed
//and printing the Date to standard output-->Yes
{
    out << setfill('0') << setw(2) << date.month << '/' << setfill('0') << setw(2) << date.day << '/' << date.year;
	return out;
}

istream &operator>>(istream &in, Date &date) {
    //Inputting the Date from the file to the inventory-->Yes
    //also for inputting the Date manually-->Yes
    //Enter two digits, ignore '/'', input two more, ignore again, input last four
	//in.ignore(); Why is this here?
    in >> date.month;
    in.ignore();
    in >> date.day;
    in.ignore();
    in >> date.year;
	return in;
}
