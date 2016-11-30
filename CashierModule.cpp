#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

#include "CashierModule.h"

using namespace std;

void CashierModule::UserInteraction() 
{
  cout << "Book Title: " << endl;
  cin  >> title;
  cout << "Quantity: " << endl;
  cin  >> quantity;
}

double CashierModule::getSalesTax()
{

}

void CashierModule::deleteBookFromInventory()
{
  book.quantity -= quantity;
}
