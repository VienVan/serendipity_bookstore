#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include "Date.h"
#include "Book.h"
#include "Inventory.h"

using namespace std;

Inventory::Inventory() {
    currentSize = 0;
    for (int i = 0; i < SIZE; ++i) {
        inventory[i] = new Book;
    }
    ifstream inputFile;
    inputFile.open("books.txt");
    for (int count = 0; count < SIZE && inputFile >> *inventory[count]; ++count, ++currentSize);
	inputFile.close();
}

Inventory::~Inventory() {
    for (int i = 0; i < SIZE; ++i) {
        delete inventory[i];
    }
}

void Inventory::pullInventoryFromFile(string filepath) {
    ifstream inputFile;
    inputFile.open(filepath);
    for (int count = 0; count < SIZE; ++count) {
        inputFile >> *inventory[count];
        ++currentSize;
    }
    inputFile.close();
}

void Inventory::sortInventoryByQuantity() {
    int pos_min;
    Book *temp;
	for (int i = 0; i < SIZE - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < SIZE; j++) {
		if (inventory[j]->getQuantity() < inventory[pos_min]->getQuantity())
                   pos_min = j;
		}
            if (pos_min != i) {
                 temp = inventory[i];
                 inventory[i] = inventory[pos_min];
                 inventory[pos_min] = temp;
            }
	}
}

void Inventory::sortInventoryByCost() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < SIZE - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (inventory[j]->getWholesale() < inventory[pos_min]->getWholesale())
                pos_min = j;
        }
        if (pos_min != i) {
            temp = inventory[i];
            inventory[i] = inventory[pos_min];
            inventory[pos_min] = temp;
        }
    }
}

void Inventory::sortInventoryByDate() {
    int pos_min;
    Book *temp;
    for (int i = 0; i < SIZE - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (inventory[j]->getDate() > inventory[pos_min]->getDate())
                pos_min = j;
        }
        if (pos_min != i) {
            temp = inventory[i];
            inventory[i] = inventory[pos_min];
            inventory[pos_min] = temp;
        }
    }
}

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

void Inventory::editBook(int index, Book modified)
{
    *inventory[index] = modified;
}
		 
void Inventory::deleteBook(int index)
{
    if (currentSize == 0) {
        for (;index < SIZE - 1; index++) {
            inventory[index] = inventory[index + 1];
        }
        currentSize--;
    }
    else throw "Error: The inventory is already empty.\n";
}

void Inventory::addBook(Book input)
{
    if (currentSize != SIZE) {
        *inventory[currentSize] = input;
	}
	else {
		throw "Error: The the inventory is already full.\n";
    }
}

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
