#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;


Book::Book(){
	author = "";       //Set all of these to default values. Make sure that they do not mess up sorting operations, etc.
	title = "";
	ISBN = 0;
	publisher = "";
	date = setDate(1, 1, 1900);
	quantity = 0;
	wholesale = 0.0;
	retail = 0.0;
}
Book::Book(string a, string t, long i, string p, int d, int m, int y, int q, double w, double r)
{
	author = a;
	title = t;
	ISBN = i;
	publisher = p;
	date = setDate(m, d, y);
	quantity = q;
	wholesale = w;
	retail = r;
}

ostream& operator<<(ostream& out, const Book &thi)
{
	out << thi.title << '\t' << thi.author << '\t' << thi.ISBN << '\t' << thi.publisher << '\t' << thi.date << '\t' << thi.quantity << '\t' << thi.wholesale << '\t' << thi.retail << '\n';
	//Tab marks end of field; Newline marks end of book
	return out;
}

istream& operator>>(istream& in, const Book&thi)
{
	//This requires that the read position start at the beginning of a book
	in.ignore();
	getline(in, thi.title, 1024, '\t');
	getline(in, thi.author, 1024, '\t');
	getline(in, thi.ISBN, 13, '\t');
	getline(in, thi.publisher, 1024, '\t');
	getline(in, thi.date, 10, '\t');
	getline(in, thi.quantity, 1024, '\t');
	getline(in, thi.wholesale, 1024, '\t');
	getline(in, thi.retail, 1024, '\n');
	//Using getline because tab is our limiting character
	return in;
}
