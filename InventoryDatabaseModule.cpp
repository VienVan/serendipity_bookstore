#define _CRT_SECURE_NO_WARNINGS
#include "InventoryDatabaseModule.h"

void InventoryDatabaseModule::userInteraction()
{
	int choice;
	do{
		cout << "\n\n\t Serendipity Booksellers\n\t\t Main Menu" << endl
			<< "1. Look Up a Book" << endl
			<< "2. Add a Book" << endl
			<< "3. Edit a Book's Record" << endl
			<< "4. Delete a Book" << endl
			<< "5. Return to the Main Menu" << endl << endl
			<< "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1: lookUpBook();
                break;
			case 2: addBook();
                break;
			case 3: editBook();
                break;
			case 4: deleteBook();
                break;
		}
	} while (choice != 5);
}

void InventoryDatabaseModule::lookUpBook()
{
	cout << "Enter the title of the book you would like to look up: ";
}
void InventoryDatabaseModule::addBook()
{
}
void InventoryDatabaseModule::editBook()
{
}  
void InventoryDatabaseModule::deleteBook()
{
}  
