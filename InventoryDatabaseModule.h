#ifndef _INVENTORYDATABASEMODULE_H
#define _INVENTORYDATABASEMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
class InventoryDatabaseModule : public Module
{
public:
	void userInteraction();
	InventoryDatabaseModule(Inventory * i) : Module(i){}
};

#endif
