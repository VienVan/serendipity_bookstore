#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Book.h"
#include <string>

using namespace std;

class Inventory
{
private:
	const int SIZE = 1024;
	Book inv[SIZE];
public:
	void Inventory::pullInventoryFromFile(string, Book []);
	void Inventory::sortInventoryByQuantity(Book [], const int);
	void Inventory::sortInventoryByCost(Book [], const int);
	void Inventory::sortInventoryByDate(Book [], const int);
	void Inventory::modify(Book []);
	void Inventory::view(Book []);
	void Inventory::deleteBook(Book [], int, const int);
	void Inventory::addBook(Book [], const int);
	Book *getInventory() { return inv; }
};

#endif
