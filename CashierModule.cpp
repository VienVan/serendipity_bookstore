#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "CashierModule.h"
#include <iomanip>

using namespace std;

void CashierModule::userInteraction()
{
	// local variables
    bool wantToContinue = false;
    char y;
	// loop for user interaction
    do
    {
        wantToContinue = false;
		// read in title and quantity
        cout << "Book Title: " << endl;
        getline(cin, title);
        cout << "Quantity: " << endl;
        cin  >> quantity;
		// ask if user wants to continue
        cout << "Continue? y or n: ";
        cin  >> y;
        cin.ignore();
        if(y == 'y' || y == 'Y')
        {
            wantToContinue = true;
        }
		// check if book exists
        if(inv->searchTitle(title) != -1)
        {
			// store index of book in inventory in an array
            bookIndices[titles] = inv->searchTitle(title);
            int bookQuantities =  (*(*inv)[bookIndices[titles]]).getQuantity();
			// check if inventory's quantity is less than input quantity
            if(bookQuantities < quantity)
            {
				// get new quantity 
                cout << "We only have " << bookQuantities
                << " copies of this book. How many copies would you like?" << endl;
                cin >> quantity;
                cin.ignore();
            }
            else if(bookQuantities <= 0)
            {
                cout << "This book is out of stock." << endl;
            }
			// store quantities in an array, matching index of bookIndices array
            bookQuantity[titles] = quantity;
            titles++;

        }
        else if(inv->searchTitle(title) == -1)
        {
            cout << "We don't have that book." << endl;
        }

    } while(wantToContinue);
    printScreen();
    updateInventory();
	// reset local variables
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
		// get total price of books 
		price = (*(*inv)[bookIndices[i]]).getWholesale()*retailmarkup * bookQuantity[i];
        totalPrice += price;
    }
    return totalPrice;
}

void CashierModule::updateInventory()
{
    for(int i = 0; i < titles; i++)
    {
		// update quantity of books
        int quantity =  (*(*inv)[bookIndices[i]]).getQuantity() - bookQuantity[i];
        (*(*inv)[bookIndices[i]]).setQuantity(quantity);
		// if quantity is 0 or less, delete book from inventory
        if (quantity <= 0)
        {
            inv->deleteBook(bookIndices[i]);
        }
    }
}
void CashierModule::printScreen()
{
	// print books to screen
    cout << endl;
    cout << "Serendipity Book Sellers" << endl << endl;
    cout << setfill(' ');
    cout << setprecision(2) << fixed;
    cout << "Date: 12/08/2016" << endl << endl;
    cout << setw(8) << left << "Qty" << setw(16) <<  "ISBN" << setw(30) << "Title"
    << setw(8) << "Price" << setw(8) << "Total" << endl;
    cout << "_____________________________________________________________________" << endl;
    for(int i = 0; i < titles; i++)
    {
        cout << setw(8) << left << bookQuantity[i] << setw(16) << (*(*inv)[bookIndices[i]]).getISBN() << setw(30) << (*(*inv)[bookIndices[i]]).getTitle() << setw(8) << (*(*inv)[bookIndices[i]]).getWholesale()*retailmarkup << setw(8) << (*(*inv)[bookIndices[i]]).getWholesale()*retailmarkup * bookQuantity[i] << endl;
    }
	cout << endl << setfill(' ');
    cout << setw(48) << right << "Subtotal: " << getTotal() << endl;
	cout << setw(48) << right << "Tax: " << getTotal() * salestax - getTotal() << endl;
    cout << setw(48) << right << "Total: " << getTotal() * salestax << endl << endl;
    cout << "Thank you for shopping with us!" << endl;

}
