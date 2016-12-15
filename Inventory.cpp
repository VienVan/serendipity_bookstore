#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include "Date.h"
#include "Book.h"
#include "Inventory.h"

using namespace std;

//******************************************************************************
//Definition of Inventory Class Default Constructor                            *
//The constructor takes no arguments and pulls an inventory from a file        *
//******************************************************************************
Inventory::Inventory(string f, double markup, double tax) {
    currentSize = 0;
    filepath = f;
    retailmarkup = markup;
    salestax = tax;
    for (int i = 0; i < SIZE; ++i) {
       	inventory[i] = new Book;
    }
    pullInventoryFromFile(filepath);
}

//******************************************************************************
//Definition of Inventory Class Deconstructor                                  *
//This function deletes the dynamically-allocated book inventory               *
//******************************************************************************
Inventory::~Inventory() {
    string outfileName;
    ofstream outputFile;
	cout << "Please enter a path to return your updated inventory:\n";
	getline(cin, outfileName, '\n');
	outputFile.open(outfileName);
    for (int i = 0; i < currentSize; i++) {
        inventory[i]->printBook(outputFile);
	    outputFile << endl;
    }
    
    outputFile.close();
    for (int i = 0; i < SIZE; ++i) {
        delete inventory[i];
    }
}

//*************************************************************************************
//Definition of pullInventoryFromFile                                                 *
//This function accepts a filepath string argument and pulls an inventory from a file *
//*************************************************************************************
void Inventory::pullInventoryFromFile(string filepath) {
	ifstream inputFile;
	string temp;
	inputFile.open(filepath);
	if (inputFile.fail()) throw InvalidFile();
	else
	{
		while (inputFile)
		{
			getline(inputFile, temp);
			inventory[currentSize]->setupBook(temp);
			currentSize++;
			if (inputFile.eof())
			{
				break;
			}
		}
	}
	inputFile.close();
}

//**************************************************************************************
//Definition of function addBook                                                       *
//This function accepts a Book as an argument and adds it to the end of the inventory  *
//**************************************************************************************
void Inventory::addBook(Book input)
{
    if (currentSize == SIZE) throw FullInventory();
    *(inventory[currentSize]) = input;
    currentSize++;
}

//****************************************************************************************
//Definition of function deleteBook                                                      *
//This function accepts and index int and removes the specified Book from the inventory  *
//****************************************************************************************
void Inventory::deleteBook(int index)
{
	if (currentSize == 0) throw EmptyInventory();
	delete inventory[index];
	for (; index < SIZE - 1; index++) {
		inventory[index] = inventory[index + 1];
	}
	inventory[index] = new Book;
	currentSize--;
}

//**********************************************************************
//Definition of function totalWholesale                                *
//This function accepts no arguements, and returns the                 *
//total wholesale value of the entire inventory                        *
//**********************************************************************
long long Inventory::totalWholesale() {
    long long total = 0;
    for (int i = 0; i < currentSize; ++i) {
        total += (inventory[i]->getWholesale())*(inventory[i]->getQuantity());
    }
    return total;
}

//********************************************************************************
//Definition of function searchTitle                                             *
//This function accepts a title as a string, seraches for it in the inventory,   *
//and returns the index of the Book once found                                   *
//********************************************************************************
int Inventory::searchTitle(string title) {
    int index = -1;
    bool isFound = false;
    for (int i = 0; i < currentSize && !isFound; i++) {
        if (inventory[i]->getTitle() == title) {
            index = i;
            isFound = true;
        }
    }
    return index;
}

//******************************************************************************************
//Definition of function sortInventoryByTitle                                              *
//This function accepts no parameters and does a selection sort of the inventory by title  *
//******************************************************************************************
void Inventory::sortByTitle() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < currentSize - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < currentSize; j++) {
            if (inventory[j]->getTitle() < inventory[pos_min]->getTitle())
                pos_min = j;
        }
        if (pos_min != i) {
            temp = inventory[i];
            inventory[i] = inventory[pos_min];
            inventory[pos_min] = temp;
        }
    }
}
//********************************************************************************************
//Definition of function sortInventoryByQuantity                                              *
//This function accepts no parameters and does a selection sort of the inventory by quantity  *
//*********************************************************************************************
void Inventory::sortByQuantity() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < currentSize - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < currentSize; j++) {
            if (inventory[j]->getQuantity() > inventory[pos_min]->getQuantity())
                pos_min = j;
        }
        if (pos_min != i) {
            temp = inventory[i];
            inventory[i] = inventory[pos_min];
            inventory[pos_min] = temp;
        }
    }
}

//*****************************************************************************************
//Definition of function sortInventoryByCost                                              *
//This function accepts no parameters and does a selection sort of the inventory by cost  *
//*****************************************************************************************
void Inventory::sortByCost() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < currentSize - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < currentSize; j++) {
            if (inventory[j]->getWholesale() > inventory[pos_min]->getWholesale())
                pos_min = j;
        }
        if (pos_min != i) {
            temp = inventory[i];
            inventory[i] = inventory[pos_min];
            inventory[pos_min] = temp;
        }
    }
}

//*******************************************************************************************************
//Definition of function sortInventoryByDate                                                            *
//This function accepts no parameters and does a selection sort of the inventory by date(earliest first)*
//*******************************************************************************************************
void Inventory::sortByDate() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < currentSize - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < currentSize; j++) {
            if (inventory[j]->getDate() < inventory[pos_min]->getDate())
                pos_min = j;
        }
        if (pos_min != i) {
            temp = inventory[i];
            inventory[i] = inventory[pos_min];
            inventory[pos_min] = temp;
        }
    }
}

//*******************************************************************
//Overloading the << operator for use with an Inventory object      *
//It print each Book with an empty line at the end                   *
//*******************************************************************
ostream& operator<<(ostream &out, const Inventory &thi) {
    for (int i = 0; i < thi.currentSize; ++i) {
        out << *(thi.inventory[i]) << endl << endl;
    }
    return out;
}

