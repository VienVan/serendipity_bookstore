#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


Book::Book(string a, string t, string i, string p, int d, int m, int y, int q, double r)
{
	author = a;
	title = t;
	ISBN = i;
	publisher = p;
	date = Date(m, d, y);
	quantity = q;
	wholesale = r;
	retailmarkup = 1.3;
	salestax = 1.0875;
}

//******************************************************************************
//Definition of member function setupBook			               *
//The constructor takes one arguement from the file and breaks it down into    *
//author, title, isbn, date, quantity, retail, wholesale                       *
//******************************************************************************
void Book::setupBook(string a)
{
	string td, tm, ty;
	string temp = a;

	title = temp.substr(0, temp.find('\t'));
	temp = temp.substr(temp.find('\t') + 1, temp.find('\n'));
	ISBN = temp.substr(0, temp.find('\t'));
	temp = temp.substr(temp.find('\t') + 1, temp.find('\n'));
	author = temp.substr(0, temp.find('\t'));
	temp = temp.substr(temp.find('\t') + 1, temp.find('\n'));
	publisher = temp.substr(0, temp.find('\t'));
	temp = temp.substr(temp.find('\t') + 1, temp.find('\n'));
	tm = temp.substr(0, temp.find('/'));
	temp = temp.substr(temp.find('/') + 1, temp.find('\n'));
	td = temp.substr(0, temp.find('/'));
	temp = temp.substr(temp.find('/') + 1, temp.find('\n'));
	ty = temp.substr(0, temp.find('/'));
	date = Date(atoi(tm.c_str()), atoi(td.c_str()), atoi(ty.c_str()));
	temp = temp.substr(temp.find('\t') + 1, temp.find('\n'));
	wholesale = atoi(temp.substr(0, temp.find('\t')).c_str());
	temp = temp.substr(temp.find('.') + 1, temp.find('\n'));
	wholesale += double(atoi(temp.substr(0, temp.find('\t')).c_str()))/100;
	temp = temp.substr(temp.find('\t') + 1, temp.find('\n'));
	quantity = atoi(temp.substr(0, temp.find('\t')).c_str());
}

ostream& operator<<(ostream& out, Book &thi)
//Printing the Book to the file
//and printing the Book to standard output
{
	out << setfill(' ') << left << setw(30) << thi.title << '\t'
		<< left << setw(22) << thi.author << '\t'
		<< left << setw(17) << thi.ISBN
		<< left << setw(30) << thi.publisher
		<< setfill('0') << setprecision(2) << left << setw(14) << thi.date << '\t'
		<< setfill(' ') << left << setw(12) << thi.quantity
		<< showpoint  << setprecision(2) << fixed << setw(6) << thi.wholesale << ' ';
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
	return in;
}

//**************************************************************************
//Definition of function printFile                                         *
//This function accepts and int (index) variable and prints                *
//out the corresponding book in the format used when reading the file      *
//**************************************************************************
ostream &Book::printBook(ostream & out) {
    out << title << '\t'
    << ISBN << '\t'
    << author << '\t'
    << publisher << '\t'
    << date << '\t'
    << wholesale << '\t'
    << quantity;
    return out;
}

