#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

#include "CashierModule.h"

using namespace std;

void CashierModule::userInteraction()
{
    cout << "Vien forgot to push this...\n";
    deleteBookFromInventory();
    
}

void CashierModule::deleteBookFromInventory()
{
    cout << "Therefore, this does nothing.\n\n";
}
