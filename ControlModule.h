#ifndef _CONTROLMODULE_H
#define _CONTROLMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
#include "CashierModule.h"
#include "ReportModule.h"
#include "InventoryDatabaseModule.h"
class ControlModule : public Module
{
private:
    Inventory *I;
    CashierModule *cm;
    ReportModule *rm;
    InventoryDatabaseModule *im;
public:
    ControlModule(string);
    ~ControlModule();
	void userInteraction();

};

#endif

