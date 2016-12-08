#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "CashierModule.h"
#include <iomanip>

using namespace std;

void CashierModule::userInteraction()
{
    bool wantToContinue = false;
    char y;
    do
    {
        wantToContinue = false;
        cout << "Book Title: " << endl;
        getline(cin, title);
        cout << "Quantity: " << endl;
        cin  >> quantity;
        cout << "Continue? y or n: ";
        cin  >> y;
        cin.ignore();
        if(y == 'y' || y == 'Y')
        {
            wantToContinue = true;
        }
        if(inv->searchTitle(title) != -1)
        {

            bookIndices[titles] = inv->searchTitle(title);
            cout << (*(*inv)[bookIndices[titles]]).getTitle() << endl;
            int bookQuantities =  (*(*inv)[bookIndices[titles]]).getQuantity();
            cout << "quantities: " << bookQuantities << endl;
            if(bookQuantities < quantity)
            {
                cout << "We only have " << bookQuantities
                << " copies of this book. How many copies would you like?" << endl;
                cin >> quantity;
                cin.ignore();
            }
            else if(bookQuantities <= 0)
            {
                cout << "This book is out of stock." << endl;
            }
            bookQuantity[titles] = quantity;
            cout << bookIndices[titles] << endl;
            titles++;

        }
        else if(inv->searchTitle(title) == -1)
        {
            cout << "We don't have that book." << endl;
        }

    } while(wantToContinue);
    printScreen();
    updateInventory();
    titles = 0;
    for(int i = 0; i < 1024; i++)
    {
        bookQuantity[i] = 0;
        bookIndices[i] = 0;
    }
}

double CashierModule::getTotal()
{
    double price;
    totalPrice = 0.0;
    for(int i = 0; i < titles; i++)
    {
        totalBooks += bookQuantity[i];
        price = (*(*inv)[bookIndices[i]]).getRetail() * bookQuantity[i];
        totalPrice += price;
    }
    return totalPrice;
}

void CashierModule::updateInventory()
{
    for(int i = 0; i < titles; i++)
    {
        int quantity =  (*(*inv)[bookIndices[i]]).getQuantity() - bookQuantity[i];
        (*(*inv)[bookIndices[i]]).setQuantity(quantity);
        if (quantity <= 0)
        {
            inv->deleteBook(bookIndices[i]);
        }
    }
}
void CashierModule::printScreen()
{
    cout << endl;
    cout << "Serendipity Book Sellers" << endl << endl;
    cout << setfill(' ');
    cout << setprecision(2) << fixed;
    cout << "Date: " << endl << endl;
    cout << setw(8) << left << "Qty" << setw(16) <<  "ISBN" << setw(30) << "Title"
    << setw(8) << "Price" << setw(8) << "Total" << endl;
    cout << "_____________________________________________________________________" << endl;
    for(int i = 0; i < titles; i++)
    {
        cout << setw(8) << left << bookQuantity[i] << setw(16) << (*(*inv)[bookIndices[i]]).getISBN() << setw(30) << (*(*inv)[bookIndices[i]]).getTitle() << setw(8) << (*(*inv)[bookIndices[i]]).getRetail() << setw(8) << (*(*inv)[bookIndices[i]]).getRetail() * bookQuantity[i] << endl;
    }
    cout << endl;
    cout << setw(48) << right << "Subtotal: " << getTotal() << endl;
    cout << setw(48) << right << "Total: " << getTotal() * salestax << endl << endl;
    cout << "Thank you for shopping with us!" << endl;

}
