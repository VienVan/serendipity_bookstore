#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Book.h"
#include <string>

using namespace std;

class Inventory
{
private:
	const int SIZE = 1024;
	Book inv[1024];

public:
    Inventory(string);
	void pullInventoryFromFile(string, Book []);
	void sortInventoryByQuantity(Book [], const int);
	void sortInventoryByCost(Book [], const int);
	void sortInventoryByDate(Book [], const int);
	void modify(Book []);
	void view(Book []);
	void deleteBook(Book [], int, const int);
	void addBook(Book [], const int);
	void reverseOrder(Book inventory[], const int size);
	Book *getInventory() { return inv; }
	//read books first, then destructor kill the array//
};

#endif
