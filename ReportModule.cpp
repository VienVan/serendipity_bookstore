#define _CRT_SECURE_NO_WARNINGS
#include "ReportModule.h"

void ReportModule::userInteraction()
{
	int choice;
	do{
		cout << "Serendipity Booksellers Reports" << endl
			 << "1. Inventory Listing" << endl
			 << "2. Inventory Wholesale Value" << endl
			 << "3. Inventory Retail Value" << endl
			 << "4. Listing by Quantity" << endl
			 << "5. Listing by Cost" << endl
			 << "6. Listing by Age" << endl
			 << "7. Return to Main Menu" << endl
		     << "Enter Your Choice: ";
		cin >> choice;
	} while (choice != 7);
}
