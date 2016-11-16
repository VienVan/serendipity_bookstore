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
	Inventory(string filename, double markup);
	void pullInventoryFromFile(string filename);
	void sortInventoryByQuantity();
	void sortInventoryByCost();
	void sortInventoryByDate();
	Book * getInventory();
	~Inventory();
};

#endif
