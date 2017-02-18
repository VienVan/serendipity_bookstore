#define _CRT_SECURE_NO_WARNINGS
#include "InventoryDatabaseModule.h"
#include <iomanip>
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
		switch (stoi(choice))
		{
			case 1:
			{
				cout << "Enter the title of the book you would like to look up: ";
				getline(cin, temp);
				int index = inv->searchTitle(temp);
				if (index != -1)
				{

					cout << setw(36) << right << "Serendipity Booksellers" << endl;
					cout << setw(24) << right << "Book Information" << endl;
					cout << "ISBN:             " << setw(20) << (*(*inv)[index]).getISBN() << endl;
					cout << "Title:            " << setw(20) << (*(*inv)[index]).getTitle() << endl;
					cout << "Author:           " << setw(20) << (*(*inv)[index]).getAuthor() << endl;
					cout << "Publisher:        " << setw(20) << (*(*inv)[index]).getPublisher() << endl;
					cout << "Date Added:                 " << (*(*inv)[index]).getDate() << right << endl;
					cout << "Quantity on hand: "  << setfill(' ') << setw(20) << (*(*inv)[index]).getQuantity() << endl;
					cout << "Wholesale Cost:   " << setw(20) << (*(*inv)[index]).getWholesale() << endl;
					cout << "Retail Price:     " << setw(20) << (*(*inv)[index]).getWholesale() * retailmarkup << endl;
				}
				else
					cout << "Your book could not be found!" << endl;
			}break;
			case 2:
			{
				bool dontadd = false;
				Book build;
				cout << "Enter the title of the book you would like to add: ";
				getline(cin, temp);
				if (temp.length() > 30)
					temp = temp.substr(0, 30);
				build.setTitle(temp);

				cout << "Enter the author of the book you would like to add: ";
				getline(cin, temp);
				if (temp.length() > 30)
					temp = temp.substr(0, 30);
				build.setAuthor(temp);

				cout << "Enter the ISBN of the book you would like to add: ";
				getline(cin, temp);
				if (temp.length() > 13)
					temp = temp.substr(0, 13);
				build.setISBN(temp);
			
				cout << "Enter the publisher of the book you would like to add: ";
				getline(cin, temp);
				if (temp.length() > 30)
					temp = temp.substr(0, 30);
				build.setPublisher(temp);

				cout << "Enter the current date in MM/DD/YYYY format. e.g. 04/03/1990: ";
				getline(cin, temp);
				try{
					build.setDate(Date(temp));
				}
				catch (...)
				{
					dontadd = true;
				}

				cout << "Enter the quantity of books to add: ";
				getline(cin, temp);
				int t = stoi(temp);
				if (t > 0)
					build.setQuantity(stoi(temp));
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
				{
					try{ inv->addBook(build); }
					catch (Inventory::FullInventory){ cout << "ERROR: Inventory is full" << endl; }
				}
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
						cout << "Your book currently holds the data values: " << endl << *build << endl;
						switch (stoi(choice2))
						{
						case 1:
						{
					
							cout << "Enter a new title: ";
							getline(cin, temp);
							build->setTitle(temp);
						}break;
						case 2:
						{
							cout << "Enter a new author: ";
							getline(cin, temp);
							build->setAuthor(temp);
						}break;
						case 3:
						{
							cout << "Enter a new ISBN: ";
							getline(cin, temp);
							build->setISBN(temp);
						}break;
						case 4:
						{
							cout << "Enter a new publisher: ";
							getline(cin, temp);
							build->setPublisher(temp);
						}break;
						case 5:
						{
							cout << "Enter a new date in the format MM/DD/YYYY e.g. 04/05/1998: ";
							getline(cin, temp);
							try{
								build->setDate(Date(temp));
							}
							catch (string ErrorCode)
							{
								cout << ErrorCode << endl;
							}
						}break;
						case 6:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new quantity: ";
							getline(cin, temp);
							int t = stoi(temp);
							if (t > 0)
								build->setQuantity(stoi(temp));
							else
								cout << "INVALID VALUE" << endl;
						}break;
						case 7:
						{
							cout << "Your book currently holds the data values: " << endl << *build << endl;
							cout << "Enter a new wholesale value: ";
							getline(cin, temp);
							int t = stoi(temp);
							if (t > 0)
								build->setWholesale(stoi(temp));
							else
								cout << "INVALID VALUE" << endl;
						}break;
						case 8:{ }break;
						default:{ cout << endl << "INPUT ERROR" << endl; }
						}
					} while (stoi(choice2) != 8);
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
				{
					try{ inv->deleteBook(index); }
					catch (Inventory::EmptyInventory){ cout << endl << "ERROR: Inventory is empty" << endl; }
				} else
					cout << "Your book could not be found or deleted." << endl;
			}break;
			case 5:{}break;
			default:{ cout << endl << "INPUT ERROR" << endl; }
		}
	} while (stoi(choice) != 5);
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
