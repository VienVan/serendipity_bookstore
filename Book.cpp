#include "Date.h"
#include "Book.h"
#include <iostream>
#include <string>
using namespace std;


Book::Book(){}
Book::Book(string a, string t, string i, string p, int d, int m, int y, int q, double w, double r)
{
	author = a;
	title = t;
	isbn = i;
	publisher = p;
	date = Date(m, d, y);
	quantity = q;
	wholesale = w;
	retail = r;
}

ostream& operator<<(ostream& out, const Book&thi)
{
	out << thi.author << " " << thi.title << " " << thi.isbn << " " << thi.publisher << " " << thi.date << " " << thi.quantity << " " << thi.wholesale << " " << thi.retail;
	return out;
}