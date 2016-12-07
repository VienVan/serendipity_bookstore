#define _CRT_SECURE_NO_WARNINGS
#include "InventoryDatabaseModule.h"

using namespace std;

void InventoryDatabaseModule::userInteraction()
{
	string choice;
	do{
		cout << "\n\n\t Serendipity Booksellers\n\t\t Main Menu" << endl
			<< "1. Look Up a Book" << endl
			<< "2. Add a Book" << endl
			<< "3. Edit a Book's Record" << endl
			<< "4. Delete a Book" << endl
			<< "5. Return to the Main Menu" << endl << endl
			<< "Enter Your Choice: ";
		getline(cin, choice);

		string temp;
		switch (atoi(choice.c_str()))
		{
			case 1:
			{
				cout << "Enter the title of the book you would like to look up: ";
				getline(cin, temp);
				int index = inv->searchTitle(temp);
				cout << "Your book is as follows:" << endl << *((*inv)[index]);
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
				cin.ignore();
				build.setWholesale(d);
				  
				addBook(build);
			}break;
			case 3:
			{
				cout << "Enter the title of the book you would like to edit: ";
				getline(cin, temp);
				cout << temp;
				Book * build = (*inv)[(inv->searchTitle(temp))];
				cout << *build;
				string choice2;
				do
				{
					cout << "Edit Book Menu" << endl
						<< "1. Edit Title" << endl
						<< "2. Edit Author" << endl
						<< "3. Edit ISBN" << endl
						<< "4. Edit Publisher" << endl
						<< "5. Edit Date" << endl
						<< "6. Edit Quantity" << endl
						<< "7. Edit Wholesale Value" << endl
						<< "8. Return to Inventory Database Module";
					getline(cin, choice2);
					
					switch (atoi(choice2.c_str()))
					{
						case 1:
						{
							cout << "Your current book's data is:" << endl << *build;
							cout << "Enter a new title: ";
							getline(cin, temp);
							build->setTitle(temp);
						}break;
						case 2:
						{
								  cout << "Your current book's data is:" << endl << *build;
								  cout << "Enter a new author: ";
								  getline(cin, temp);
								  build->setAuthor(temp);
						}break;
						case 3:
						{
								  cout << "Your current book's data is:" << endl << *build;
								  cout << "Enter a new ISBN: ";
								  getline(cin, temp);
								  build->setISBN(temp);
						}break;
						case 4:
						{
								  cout << "Your current book's data is:" << endl << *build;
								  cout << "Enter a new publisher: ";
								  getline(cin, temp);
								  build->setPublisher(temp);
						}break;
						case 5:
						{
								  cout << "Your current book's data is:" << endl << *build;
								  cout << "Enter a new date in the format MM/DD/YYYY e.g. 04/05/1998: ";
								  getline(cin, temp);
								  build->setDate(Date(temp));
						}break;
						case 6:
						{
								  cout << "Your current book's data is:" << endl << *build;
								  cout << "Enter a new quantity: ";
								  getline(cin, temp);
								  build->setQuantity(atoi(temp.c_str()));
						}break;
						case 7:
						{
								  cout << "Your current book's data is:" << endl << *build;
								  cout << "Enter a new author: ";
								  getline(cin, temp);
								  build->setWholesale(atoi(temp.c_str()));
						}break;
						default:{ cout << endl << "INPUT ERROR" << endl; }
					}
				} while (atoi(choice2.c_str()) != 8);
			}break;
			case 4: 
			{
					  cout << "Enter the title of the book you would like to delete: ";
					  getline(cin, temp);
					  deleteBook(temp);
			}break;
			default:{ cout << endl << "INPUT ERROR" << endl; }
		}
	} while (atoi(choice.c_str()) != 5);
}

void InventoryDatabaseModule::addBook(Book b)
{
	inv->addBook(b);
}

void InventoryDatabaseModule::deleteBook(string t)
{
	int index = inv->searchTitle(t);
	inv->deleteBook(index);
}  
