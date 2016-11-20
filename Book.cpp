#include "Date.h"
#include "Book.h"
#include <iostream>
#include <string>
using namespace std;


Book::Book(){
	author = "";       //Set all of these to default values. Make sure that they do not mess up sorting operations, etc.
	title = "";
	ISBN = "";
	publisher = "";
	date = "";
	quantity = "";
	wholesale = "";
	retail = "";
}
Book::Book(string a, string t, string i, string p, int d, int m, int y, int q, double w, double r)
{
	author = a;
	title = t;
	ISBN = i;
	publisher = p;
	date = Date(m, d, y);
	quantity = q;
	wholesale = w;
	retail = r;
}

ostream& operator<<(ostream& out, const Book &thi)
{
	out << thi.author << ' ' << thi.title << ' ' << thi.ISBN << ' ' << thi.publisher << ' ' << thi.date << ' ' << thi.quantity << ' ' << thi.wholesale << ' ' << thi.retail << endl;
	return out;
}

istream& operator<<(istream& in, const Book&thi)
{
	//This requires that the read position start at the beginning of a book
	in >> thi.author >> thi.title >> thi.ISBN >> thi.publisher >> thi.date >> thi.quantity >> thi.wholesale >> thi.retail;
	return in;
}
