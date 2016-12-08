#define _CRT_SECURE_NO_WARNINGS
#include "ReportModule.h"
#include <iomanip>
void ReportModule::userInteraction()
{
	string choice;
	do{
		cout << "\n\tSerendipity Booksellers\n\t\t Reports" << endl
			 << "1. Inventory Listing By Title" << endl
			 << "2. Inventory Wholesale Value" << endl
			 << "3. Inventory Retail Value" << endl
			 << "4. Listing by Quantity" << endl
			 << "5. Listing by Cost" << endl
			 << "6. Listing by Age" << endl
			 << "7. Return to Main Menu" << endl
		     << "Enter Your Choice: ";
		getline(cin, choice);
        switch (atoi(choice.c_str())) {
			case 1:
			{
				inv->sortByTitle();
				cout << *inv;
			}break;
			case 2:
			{
				cout << setfill(' ');
				for (int x = 0; x < inv->getCurrentSize(); x++)
					cout << setw(30) << (*(*inv)[x]).getTitle() << ' ' << setw(12) << fixed << showpoint << setprecision(2) << (*(*inv)[x]).getWholesale() * (*(*inv)[x]).getQuantity() << endl;
				cout << setw(10) << fixed << setprecision(2) << "The total wholesale value of the inventory is: " << inv->totalWholesale() << endl;
			}break;
			case 3:
			{
				cout << setfill(' ');
				for (int x = 0; x < inv->getCurrentSize(); x++)
					cout << setw(30) << (*(*inv)[x]).getTitle() << ' ' << setw(12) << fixed << showpoint << setprecision(2) << (*(*inv)[x]).getWholesale() * (*(*inv)[x]).getQuantity()* retailmarkup << endl;
				cout << setw(10) << fixed << setprecision(2) << "The total retail value of the inventory is: " << inv->totalWholesale()*retailmarkup*salestax << endl;
			}break;
			case 4:
			{
				inv->sortByQuantity();
				cout << *inv;
			}break;
			case 5:
			{
				inv->sortByCost();
				cout << *inv;
			}break;
			case 6:
			{
				inv->sortByDate();
				cout << *inv;
			}break;
			case 7:{ }break;
			default:{ cout << endl << "INPUT ERROR" << endl; }
        }
	} while (atoi(choice.c_str()) != 7);
}
