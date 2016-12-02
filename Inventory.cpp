#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

#include "Book.h"
#include "Inventory.h"

using namespace std;

Inventory::Inventory(string filename, Book inventory[]) {
	ifstream inputFile(filename);
	for (int count = 0; count < 1024 && inputFile >> inventory[count]; ++count);
	inputFile.close();
}

void Inventory::sortInventoryByQuantity(Book inventory[], const int size) {
	int pos_min, temp;
	for (int i = 0; i < size - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < size; j++) {
		if (inventory[j].getQuantity() < inventory[pos_min].getQuantity())
                   pos_min = j;
		}
            if (pos_min != i) {
                 temp = inventory[i].getQuantity();
                 inventory[i].setQuantity(inventory[pos_min].getQuantity());
                 inventory[pos_min].setQuantity(temp);
            }
	}
}

void Inventory::sortInventoryByCost(Book inventory[], const int size) { 
	int pos_min, temp;
	for (int i = 0; i < size - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < size; j++) {
		if (inventory[j].getWholesale() < inventory[pos_min].getWholesale())
                   pos_min = j;
		}
            if (pos_min != i) {
                 temp = inventory[i].getWholesale();
                 inventory[i].setWholesale(inventory[pos_min].getWholesale());
                 inventory[pos_min].setWholesale(temp);
            }
	}
}
void Inventory::sortInventoryByDate(Book inventory[], const int size) {
	int pos_min, temp;
	for (int i = 0; i < size - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < size; j++) {
		if (inventory[j].getDate() > inventory[pos_min].getDate())
                   pos_min = j;
		}
            if (pos_min != i) {
                 temp = inventory[i].getDate();
                 inventory[i].getDate(inventory[pos_min].getDate());
                 inventory[pos_min].getDate(temp);
            }
	}
}

void Inventory::reverseOrder(Book inventory[], const int size)
{
	for (int i = 0; i < size / 2; ++i)
		inventory[i] = inventory[size - i];
}

void Inventory::modify(Book inventory[]) 
{
	int index;
	char selection;
	string temp_data;
	cout << "Please enter the number of the book you want to modify:\n";
	cin >> index--;
	do {
		cout << "Please select which of the following you would like to modify:\nA: Title\nB: Author\nC: Publisher\nD: ISBN\nE: Date\n F: Quantity\nG: Wholesale Cost\nH: Retail Cost\n";
		cin >> selection;
		cin.ignore();
		switch(toupper(selection)) {
			case 'A':
				"Please enter the new title. Press tab once you are done\n";
				getline(cin, temp_data, '\t');
				inventory[index].setTitle(temp_data);
				break;
			case 'B': 
				"Please enter the new author. Press tab once you are done\n";
				getline(cin, temp_data, '\t');
				inventory[index].setAuthor(temp_data);
				break;
			case 'C':
				"Please enter the new publisher. Press tab once you are done\n";
				getline(cin, temp_data, '\t');
				inventory[index].setPublisher(temp_data);
				break;
			case 'D': 
				cout << "Please enter the new ISBN:\n";
				cin >> temp_data;
				inventory[index].setISBN(temp_data);
				break;
			case 'E':
			
				break;
			case 'F': 
				cout << "Please enter the updated quantity:\n";
				cin >> temp_data;
				inventory[index].setQuantity(stoi(temp_data));
				break;
			case 'G': 
				cout << "Please enter the updated cost:\n";
				cin >> temp_data;
				inventory[index].setWholesale(stod(temp_data));
				break;
			case 'H': 
				cout << "Please enter the updated price:\n";
				cin >> temp_data;
				inventory[index].setRetail(stod(temp_data));
				break;
			default: selection = 0;
		}
	} while (selection == 0);
		
}

void Inventory::view(Book inventory[]) 
{
	int index;
	char selection;
	cout << "Please enter the number of the book you want to view:\n";
	cin >> index;
	do {
		cout << "Please select which of the following you would like to view:\nA: Title\nB: Author\nC: Publisher\nD: ISBN\nE: Date\n F: Quantity\nG: Wholesale Cost\nH: Retail Cost\n";
		cin >> selection;
		cin.ignore();
		switch(toupper(selection)) 
		{
			case 'A': cout << inventory[index].getTitle();
				break;
			case 'B': cout << inventory[index].getAuthor();
				break;
			case 'C': cout << inventory[index].getPublisher();
				break;
			case 'D': cout << inventory[index].getISBN();
				break;
			case 'E': cout << inventory[index].getDate();
				break;
			case 'F': cout << inventory[index].getQuantity();
				break;
			case 'G': cout << inventory[index].getWholesale();
				break;

			case 'H': cout << inventory[index].getRetail();
				break;
			default: selection = 0;
		}
	} while (selection == 0);		
}
		 
void Inventory::deleteBook(Book inventory[], int index, const int size)
{
	while (index < size - 1)
	{
		inventory[index] = inventory[++index];
	}
}

void Inventory::addBook(Book inventory[], const int size)
{
	Book temp;
	if (!inventory[size])
	{
		cout << "Please enter, in order: the title of the book, name of the author, ISBN, publisher, date added, quantity, wholesale cost, and retail value of the book: ";
		cin >> inventory[size];
	}
	else
	{
		cout << "Sorry, there are too many books already in the inventory.\n";
	}
}
