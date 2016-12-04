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
Inventory::Inventory(string filepath) {
    currentSize = 0;
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
    inputFile.open(filepath);
    for (int count = 0; count < SIZE; ++count) {
        inputFile >> *inventory[count];
        ++currentSize;
    }
    inputFile.close();
}

//*********************************************************************************************
//Definition of function sortInventoryByQuantity                                              *
//This function accepts no parameters and does a selection sort of the inventory by quantity  *
//*********************************************************************************************
void Inventory::sortInventoryByQuantity() {
    int pos_min;
    Book *temp;
	for (int i = 0; i < SIZE - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < SIZE; j++) {
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
void Inventory::sortInventoryByCost() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < SIZE - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < SIZE; j++) {
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
void Inventory::sortInventoryByDate() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < SIZE - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < SIZE; j++) {
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

//******************************************************************************************
//Definition of function sortInventoryByTitle                                              *
//This function accepts no parameters and does a selection sort of the inventory by title  *
//******************************************************************************************
void Inventory::sortInventoryByTitle() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < SIZE - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < SIZE; j++) {
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

//*****************************************************************************
//Definition of function editBook                                             *
//This function accepts and index int and a modified Book as arguements and   *
//replaces the Book in the specified index with the modified Book             *
//*****************************************************************************
void Inventory::editBook(int index, Book modified)
{
    *inventory[index] = modified;
}

//****************************************************************************************
//Definition of function deleteBook                                                      *
//This function accepts and index int and removes the specified Book from the inventory  *
//****************************************************************************************
void Inventory::deleteBook(int index)
{
    if (currentSize == 0) {
        for (;index < SIZE - 1; index++) {
            inventory[index] = inventory[index + 1];
        }
        currentSize--;
    }
   // else throw "Error: The inventory is already empty.\n";
}

//**************************************************************************************
//Definition of function editBook                                                      *
//This function accepts a Book as an argument and adds it to the end of the inventory  *
//**************************************************************************************
void Inventory::addBook(Book input)
{
    if (currentSize != SIZE) {
        *inventory[currentSize] = input;
	}
	//else throw "Error: The the inventory is already full.\n";
}

//********************************************************************************
//Definition of function searchTitle                                             *
//This function accepts a title as a string, seraches for it in the inventory,   *
//and returns the index of the Book once found                                   *
//********************************************************************************
int Inventory::searchTitle(string title) {
    int index = -1;
    sortInventoryByTitle();
    int min = 0, max = SIZE - 1, midpoint = 0;
    while (min <= max && index == -1) {
        midpoint = min + (max - min)/2;
        if (title == inventory[midpoint]->getTitle()) {
            index = midpoint;
        }
        else if (title < inventory[midpoint]->getTitle()) {
            max = midpoint - 1;
        }
        else { //if (title > inventory[midpoint]->getTitle())
            min = midpoint + 1;
        }
    }
    return index;
}

ostream &Inventory::operator<<(ostream &cout) {
    for (int i = 0; i < currentSize; ++i) {
        cout << *inventory[i] << endl;
    }
    return cout;
}
