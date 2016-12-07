#define _CRT_SECURE_NO_WARNINGS
#include "InventoryDatabaseModule.h"

using namespace std;
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
		
		string temp;
		switch (choice)
		{
			case 1:
			{
				cout << "Enter the title of the book you would like to look up: ";
				getline(cin, temp);
				cout << "Your book is as follows:" << endl << lookUpBook(temp);
			}break;
			case 2:
			{
				Book build;
				cout << "Enter the title of the book you would like to add: ";
				getline(cin, temp);
				build.setTitle(temp);

				cout << "Enter the author of the book you would like to add: ";
				getline(cin, temp);
				build.setAuthor(temp);

				cout << "Enter the ISBN of the book you would like to add: ";
				getline(cin, temp);
				build.setISBN(temp);
			
				cout << "Enter the publisher of the book you would like to add: ";
				getline(cin, temp);
				build.setPublisher(temp);

				cout << "Enter the current date in MM/DD/YYYY format. e.g. 04/03/1990: ";
				getline(cin, temp);
				build.setDate(Date(temp));

				cout << "Enter the quantity of books to add: ";
				getline(cin, temp);
				build.setQuantity(atoi(temp.c_str()));

				cout << "Enter the wholesale value of the book to add: ";
				double d;
				cin >> d;
				build.setWholesale(d);
				  
				addBook(build);
			}break;
			case 3:
			{
					  cout << "Enter the title of the book you would like to edit: ";
					  getline(cin, temp);
					  Book build = (*inv)[(inv->searchTitle(temp))];

					  //cout << ;
			}break;
			case 4: 
			{
					  cout << "Enter the title of the book you would like to delete: ";
					  getline(cin, temp);
					  deleteBook(temp);
			}break;
		}
	} while (choice != 5);
}

Book InventoryDatabaseModule::lookUpBook(string t)
{
	int index = inv->searchTitle(t);
	return (*inv)[index];
}
void InventoryDatabaseModule::addBook(Book b)
{
	inv->addBook(b);
}
void InventoryDatabaseModule::editBook(string t, Book b)
{
	int index = inv->searchTitle(t);
	inv->editBook(index, b);
}  

void InventoryDatabaseModule::deleteBook(string t)
{
	int index = inv->searchTitle(t);
	//inv->
}  
