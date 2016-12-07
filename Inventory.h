#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Book.h"
#include <string>
#include <fstream>

using namespace std;

class Inventory
{
private:
	const int SIZE = 1024;
    Book *inventory[1024];
    int currentSize;

public:
    Inventory(string);
    ~Inventory();
	void pullInventoryFromFile(string);
	void sortInventoryByQuantity();
	void sortInventoryByCost();
	void sortInventoryByDate();
    void sortInventoryByTitle();
    void editBook(int, Book);
    void deleteBook(int index);
    void addBook(Book input);
    int searchTitle(string);
    Book *operator[] (int index) { return inventory[index]; }
    ostream &operator<<(ostream &);
};

#endif
