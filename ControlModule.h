#ifndef _CASHIERMODULE_H
#define _CASHIERMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
#include "CashierModule.h"
#include "ReportModule.h"
#include "InventoryDatabaseModule.h"
class ControlModule : public Module
{
private:
    CashierModule * cm = new CashierModule;
    ReportModule *rm;
    InventoryDatabaseModule *im;
    Inventory *I;
public:
    ControlModule();
	void UserInteraction();

};

#endif

