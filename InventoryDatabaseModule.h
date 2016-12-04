#ifndef _INVENTORYDATABASEMODULE_H
#define _INVENTORYDATABASEMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
class InventoryDatabaseModule : public Module
{
public:
    InventoryDatabaseModule(Inventory * i) : Module(i) {}
    void userInteraction() { cout << "Do nothing\n"; }
	void lookUpBook() { cout << "Do nothing\n"; }
	void addBook() { cout << "Do nothing\n"; }
	void deleteBook() { cout << "Do nothing\n"; }
	void editBook() { cout << "Do nothing\n"; }
};

#endif
