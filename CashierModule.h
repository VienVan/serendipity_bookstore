#ifndef _CASHIERMODULE_H
#define _CASHIERMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
class CashierModule : public Module
{
public:
	void UserInteraction();
};

#endif
