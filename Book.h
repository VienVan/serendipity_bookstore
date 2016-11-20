#ifndef _BOOK_H
#define _BOOK_H

#include "Date.h"
#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
	string author;
	string title;
	long ISBN;
	string publisher;
	Date date;
	int quantity;
	double wholesale;
	double retail;
public:
	Book();
	Book(string a, string t, long i, string p, int d, int m, int y, int q, double w, double r);
	friend ostream& operator<< (ostream &out, const Book &thi);
	friend istream& operator>> (istream &in, const Book &thi);
	string getAuthor() { return author; }
	string getTitle() { return title; }
	string getISBN() { return ISBN; }
	string getPublisher() { return publisher; }
	Date getDate() { return date; }
	int getQuantity() { return quantity; }
	double getWholesale() { return wholesale; }
	double getRetail() { return retail; }
	void setAuthor(string a) { author = a; }
	void setTitle(string t) { title = t; }
	void setISBN(long i) { ISBN = i; }
	void setQuantity(int q) { quantity = q; }
	void setWholesale(double w) { wholesale = w; }
	void setRetail(double r) { retail = r; }
};


#endif
