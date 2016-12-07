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
    int titles = 0;
    int books[1024];
    int bookQuantity[1024];
    int totalBooks = 0;
    double total = 0.0;

public:
    CashierModule(Inventory *i) : Module(i){};
    CashierModule();
    void userInteraction();
    double getTotal();
    void printTotal();
};

#endif
