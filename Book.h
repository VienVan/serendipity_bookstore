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
	string ISBN;
	string publisher;
	Date date;
	int quantity;
	double wholesale;
    	double retailmarkup, 
	double salestax;
public:
	Book() {retailmarkup = 1.3; salestax = 1.0875; }
	void setupBook(string a);
	Book(string a, string t, string i, string p, int d, int m, int y, int q, double r);
	friend ostream& operator<< (ostream &, Book &);
	friend istream& operator>> (istream &, Book &);
	string getAuthor() { return author; }
	string getTitle() { return title; }
	string getISBN() { return ISBN; }
	string getPublisher() { return publisher; }
	Date getDate() { return date; }
	int getQuantity() { return quantity; }
	double getWholesale() { return wholesale; }
	double getRetail() { return wholesale * retailmarkup; }
	void setAuthor(string a) { author = a; }
	void setTitle(string t) { title = t; }
	void setISBN(string i) { ISBN = i; }
	void setQuantity(int q) { quantity = q; }
	void setWholesale(double w) { wholesale = w; }
	void setPublisher(string p) { publisher = p;}
	void setDate(Date d) { date = d; }
    class Inventory;
    ostream &printBook(ostream &);
};


#endif
