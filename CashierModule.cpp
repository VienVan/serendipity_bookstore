#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#include "CashierModule.h"

using namespace std;

CashierModule::CashierModule()
{
    userInteraction();
}
void CashierModule::userInteraction()
{
    bool wantToContinue = false;
    int i = 0;
    char y;
    do
    {
        wantToContinue = false;
        cout << "Book Title: " << endl;
        cin.ignore();
        getline(cin, title);
        cout << "Quantity: " << endl;
        cin  >> quantity;
        cout << "Continue? y or n: ";
        cin  >> y;
        cout << y;
        if(y == 'y' || y == 'Y')
        {
            wantToContinue = true;
        }
        books[i] = inv->searchTitle(title);
        bookQuantity[i] = quantity;
        cout << books[i] << endl;
        i++;
        totalBooks++;

    } while(wantToContinue);
    cout << bookQuantity[0];
}

double CashierModule::getTotal()
{
    return 0.0;
}

void CashierModule::printTotal()
{
    for(int i = 0; i < count; i++)
    {


}
