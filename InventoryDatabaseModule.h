#ifndef _INVENTORYDATABASEMODULE_H
#define _INVENTORYDATABASEMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
class InventoryDatabaseModule : public Module
{
public:
    InventoryDatabaseModule(Inventory * i) : Module(i) {}
    void userInteraction();
	void lookUpBook();
	void addBook();
	void deleteBook();
	void editBook();
};

#endif
