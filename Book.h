#ifndef _BOOK_H
#define _BOOK_H

#include "Date.h"
#include <iostream>
#include <string>
using namespace std;
struct Book
{
	string author;
	string title;
	string isbn;
	string publisher;
	Date date;
	int quantity;
	double wholesale;
	double retail;
	Book();
	Book(string a, string t, string i, string p, int d, int m, int y, int q, double w, double r);
	friend ostream& operator<< (ostream &out, const Book &thi);
};


#endif
