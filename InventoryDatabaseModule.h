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

/*Problems and modifications:
 -"Fixed" linker errors by filling these in with empty functions
 -Massive revamping of all input/output stream functions/operators
 -Date entry formatting
 -Fix in.ignore()
 -Add exceptions and templates; polymorphism done
 -Need to complete all three branch modules
 -Documentation and Deliverables
*/
