//#define _CRT_SECURE_NO_WARNINGS
#include "ControlModule.h"

void ControlModule::userInteraction()
{
	int choice;
	do{
        cout << "\t Serendipity Booksellers\n\t\t Main Menu" << endl
             << "1. Cashier Module" << endl
             << "2. Inventory Database Module" << endl
             << "3. Report Module" << endl
             << "4. Exit" << endl << endl
             << "Enter Your Choice:";
		cin >> choice;
		switch(choice)
		{
		    case 1: { cm->userInteraction(); }
		    case 2: { im->userInteraction(); }
		    case 3: { rm->userInteraction(); }
		}
	} while (choice != 4);
}

ControlModule::ControlModule()
{
    I = new Inventory("booklist.txt");
    cm = CashierModule(I);
    rm = ReportModule(I);
    im = InventoryDatabaseModule(I);


}

ControlModule::~ControlModule()
{
    delete I;
    I = nullptr;
}
