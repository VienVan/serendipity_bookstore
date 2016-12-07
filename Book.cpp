#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;


Book::Book(string a, string t, string i, string p, int d, int m, int y, int q, double r)
{
	author = a;
	title = t;
	ISBN = i;
	publisher = p;
	date = Date(m, d, y);
	quantity = q;
	retail = r;
	wholesale = r*1.3;
}

ostream& operator<<(ostream& out, Book &thi)
//Printing the Book to the file
//and printing the Book to standard output
{
	out << thi.title << '\t' << thi.author << '\t' << thi.ISBN << ' ' << thi.publisher << '\t' << thi.date << ' ' << thi.quantity << ' ' << thi.wholesale << ' ' << thi.retail << ' ';
	return out;
}

istream& operator>>(istream& in, Book&thi)
//For inputting the Book from the file to the inventory
//also for entering the Book manually
{
	in.ignore(); //Should this be here or not?
	getline(in, thi.title, '\t');
	getline(in, thi.author,'\t');
	in >> thi.ISBN;
    in.ignore();
	getline(in, thi.publisher, '\t');
    //Note: User/File should be instructed to enter Date in format: MM/DD/YYYY
    in >> thi.date;
    in >> thi.quantity;
    in >> thi.wholesale;
    in >> thi.retail;
	return in;
}
