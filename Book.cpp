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

//******************************************************************************
//Definition of Secondary Book constructor			                           *
//The constructor takes one arguement from the file and breaks it down into    *
//author, title, isbn,date,quantity,retail,wholesale                           *
//******************************************************************************
void Book::setupBook(string a)
{
	int slash_count = 0;
	int tab_count = 0;
	string temp;

	string retail2;
	string date2;
	int d, m, y;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '\t')
		{
			tab_count++;
		}
		else
		{
			switch (tab_count)
			{
			case 0:
				title += a[i];
				break;
			case 1:
				ISBN += a[i];
				break;
			case 2:
				author += a[i];
				break;
			case 3:
				publisher += a[i];
				break;
			case 4:
				date2 += a[i];
				break;
			case 5:
				retail2 += a[i];
				break;
			case 6:
				temp += a[i];
				break;
			default:
				break;
			}
		}
	}
	date = Date(date2);
	quantity = stoi(temp);
	wholesale = retail*1.3;
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
