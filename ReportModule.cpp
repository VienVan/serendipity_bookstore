#define _CRT_SECURE_NO_WARNINGS
#include "ReportModule.h"

void ReportModule::userInteraction()
{
	string choice;
	do{
		cout << "\n\tSerendipity Booksellers\n\t\t Reports" << endl
			 << "1. Inventory Listing" << endl
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
				cout << *inv;
			}break;
			case 2:
			{
				cout << *inv;
			}break;
			case 3:
			{
				inv->sortByDate();
				cout << *inv;
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
