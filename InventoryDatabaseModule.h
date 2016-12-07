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
	Book lookUpBook(string t);
	void addBook(Book b);
	void deleteBook(string t);
	void editBook(string t, Book b);
};

#endif
