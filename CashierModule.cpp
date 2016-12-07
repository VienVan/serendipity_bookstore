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
        if(inv->searchTitle(title) != -1)
        {
            books[titles] = inv->searchTitle(title);
            bookQuantity[titles] = quantity;
            cout << books[titles] << endl;
            titles++;
        }
        else if(inv->searchTitle(title) == -1)
        {
            cout << "We don't have that book." << endl;
        }

    } while(wantToContinue);
}

double CashierModule::getTotal()
{
    double price;
    total = 0.0;
    for(int i = 0; i < titles; i++)
    {
        totalBooks += bookQuantity[i];
        price = (*(*inv)[books[i]]).getWholesale() * bookQuantity[i];
        total += price * WHOLESALEMARKUP * SALESTAX;
    }
    return total;
}

void CashierModule::printTotal()
{


}
