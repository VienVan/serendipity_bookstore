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
            case 3: //Print list
                //Then print wholesale value
                break;
            case 4: inv->sortInventoryByCost();
                //Then print list
                break;
            case 5: inv->sortInventoryByQuantity();
                //Then print list
                break;
            case 6: inv->sortInventoryByDate();
                //Then print list
                break;
        }
	} while (atoi(choice.c_str()) != 7);
}
