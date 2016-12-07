//#define _CRT_SECURE_NO_WARNINGS
#include "ControlModule.h"


ControlModule::ControlModule(string filepath)
{
	I = new Inventory(filepath, retailmarkup, salestax);
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
    string choice;
    do{
        cout << "\n\t Serendipity Booksellers\n\t\t Main Menu" << endl
        << "1. Cashier Module" << endl
        << "2. Inventory Database Module" << endl
        << "3. Report Module" << endl
        << "4. Exit" << endl << endl
        << "Enter Your Choice: ";
        getline(cin,choice);
        switch(atoi(choice.c_str()))
        {
			case 1: { cm->userInteraction(); } break;
			case 2: { im->userInteraction(); } break;
			case 3: { rm->userInteraction(); } break;
			case 4: { }break;
			default: { cout << endl << "INPUT ERROR" << endl; }
        }
	} while (atoi(choice.c_str()) != 4);
}
