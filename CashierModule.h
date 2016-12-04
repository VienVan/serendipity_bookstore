#ifndef _CASHIERMODULE_H
#define _CASHIERMODULE_H

#include "Book.h"
#include "Inventory.h"
#include "Module.h"
class CashierModule : public Module
{
private:
    int quantity;
    string title;

public:
    CashierModule(Inventory *i) : Module(i){};
    CashierModule();
    void userInteraction();
    double getTotal();
    bool isBookThere(Inventory *i);
    int searchBook(Inventory *i, string t);
};

#endif
