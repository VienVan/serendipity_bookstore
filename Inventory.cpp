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
    if(!inputFile) throw InvalidFile();
    
    for(int i = -1; inputFile.peek() != EOF; i++)
    {
        if(i == -1)
            getline(inputFile,temp,'\n');
        else {
            getline(inputFile,temp,'\n');
            inventory[i]->setupBook(temp);
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
    *inventory[currentSize] = input;
    currentSize++;
}

//****************************************************************************************
//Definition of function deleteBook                                                      *
//This function accepts and index int and removes the specified Book from the inventory  *
//****************************************************************************************
void Inventory::deleteBook(int index)
{
    if (currentSize == 0) throw EmptyInventory();
    for (;index < SIZE - 1; index++) {
        inventory[index] = inventory[index + 1];
    }
    currentSize--;
}

//**********************************************************************
//Definition of function totalWholesale                                *
//This function accepts no arguements, and returns the                 *
//total wholesale value of the entire inventory                        *
//**********************************************************************
double Inventory::totalWholesale() {
    double total = 0;
    for (int i = 0; i < SIZE; ++i) {
        total += inventory[i]->getWholesale();
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
    sortByTitle();
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
        cout << *(thi.inventory[i]) << endl << endl;
    }
    return cout;
}


