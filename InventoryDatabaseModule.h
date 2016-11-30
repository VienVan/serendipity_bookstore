#ifndef _CASHIERMODULE_H
#define _CASHIERMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
class InventoryDatabaseModule : public Module
{
public:
	void UserInteraction();
};

#endif

