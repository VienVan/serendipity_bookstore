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
				if (index != -1)
					cout << "Your book is as follows:" << endl << *((*inv)[index]);
				else
					cout << "Your book could not be found!" << endl;
			}break;
			case 2:
			{
				bool dontadd = false;
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
				try{
					Date d = Date(temp);
					build.setDate(Date(temp));
				}
				catch (...)
				{
					dontadd = true;
				}

				cout << "Enter the quantity of books to add: ";
				getline(cin, temp);
				int t = atoi(temp.c_str());
				if (t > 0)
					build.setQuantity(atoi(temp.c_str()));
				else
					dontadd = true;

				cout << "Enter the wholesale value of the book to add: ";
				double d;
				cin >> d;
				cin.ignore();
				if (d > 0)
					build.setWholesale(d);
				else
					dontadd = true;

				if (!dontadd)
					addBook(build);
			}break;
			case 3:
			{
				cout << endl << "Enter the title of the book you would like to edit: ";
				getline(cin, temp);
				int index = (inv->searchTitle(temp));
				if (index != -1)
				{
					Book * build = (*inv)[index];

					string choice2;
					do
					{
						cout << endl << "Edit Book Menu" << endl
							<< "1. Edit Title" << endl
							<< "2. Edit Author" << endl
							<< "3. Edit ISBN" << endl
							<< "4. Edit Publisher" << endl
							<< "5. Edit Date" << endl
							<< "6. Edit Quantity" << endl
							<< "7. Edit Wholesale Value" << endl
							<< "8. Return to Inventory Database Module" << endl
							<< "Enter Your Choice: ";
						getline(cin, choice2);
						switch (atoi(choice2.c_str()))
						{
						case 1:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new title: ";
							getline(cin, temp);
							build->setTitle(temp);
						}break;
						case 2:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new author: ";
							getline(cin, temp);
							build->setAuthor(temp);
						}break;
						case 3:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new ISBN: ";
							getline(cin, temp);
							build->setISBN(temp);
						}break;
						case 4:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new publisher: ";
							getline(cin, temp);
							build->setPublisher(temp);
						}break;
						case 5:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new date in the format MM/DD/YYYY e.g. 04/05/1998: ";
							getline(cin, temp);
							try{
								Date d = Date(temp);
								build->setDate(Date(temp));
							}
							catch (...)
							{
								cout << "INVALID VALUE" << endl;
							}
						}break;
						case 6:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new quantity: ";
							getline(cin, temp);
							int t = atoi(temp.c_str());
							if (t > 0)
								build->setQuantity(atoi(temp.c_str()));
							else
								cout << "INVALID VALUE" << endl;
						}break;
						case 7:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new wholesale value: ";
							getline(cin, temp);
							int t = atoi(temp.c_str());
							if (t > 0)
								build->setWholesale(atoi(temp.c_str()));
							else
								cout << "INVALID VALUE" << endl;
						}break;
						case 8:{ }break;
						default:{ cout << endl << "INPUT ERROR" << endl; }
						}
					} while (atoi(choice2.c_str()) != 8);
				}
				else
					cout <<  endl << "Your title could not be found." << endl;
			}break;
			case 4: 
			{
				cout << "Enter the title of the book you would like to delete: ";
				getline(cin, temp);
				int index = inv->searchTitle(temp);
				if (index != -1)
					inv->deleteBook(index);
				else
					cout << "Your book could not be found or deleted." << endl;
			}break;
			case 5:{}break;
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
