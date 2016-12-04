//#define _CRT_SECURE_NO_WARNINGS
#include "ControlModule.h"


ControlModule::ControlModule()
{
	I = new Inventory();
    cm = new CashierModule(I);
    rm = new ReportModule(I);
    im = new InventoryDatabaseModule(I);
}

ControlModule::~ControlModule()
{
    delete I;
    delete cm;
    delete im;
    delete rm;
    I = nullptr;
    cm = nullptr;
    im = nullptr;
    rm = nullptr;
}

void ControlModule::userInteraction()
{
    int choice;
    do{
        cout << "\n\t Serendipity Booksellers\n\t\t Main Menu" << endl
        << "1. Cashier Module" << endl
        << "2. Inventory Database Module" << endl
        << "3. Report Module" << endl
        << "4. Exit" << endl << endl
        << "Enter Your Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: { cm->userInteraction(); } break;
            case 2: { im->userInteraction(); } break;
            case 3: { rm->userInteraction(); } break;
        }
    } while (choice != 4);
}
