#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

#include "Book.h"
#include "Inventory.h"

using namespace std;

Inventory::Inventory(string filename, double markup)
{
	for (int x = 0; x < SIZE; x++)
	{
		inv[x] = Book("me", "how to not suck at programming", "9999999999999", "generic publisher", 15, 11, 2016, 1, 19.99, 19.99*markup);
	}
}
Inventory::~Inventory()
{
}

void Inventory::pullInventoryFromFile(string filename, Book inventory[]){
	ifstream inputFile(filename);
	for (int count = 0; count < 1024 && inputFile >> inventory[count]; ++count);
	inputFile.close();
}

void Inventory::sortInventoryByQuantity(Book inventory[], const int size){
	int pos_min, temp;
	for (int i = 0; i < n - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < n; j++) {
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

void Inventory::sortInventoryByCost(Book inventory[], const int size){  //By Wholesale or retail?
	int pos_min, temp;
	for (int i = 0; i < n - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < n; j++) {
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
void Inventory::sortInventoryByDate(Book inventory[], const int size){
	int pos_min, temp;
	for (int i = 0; i < n - 1; i++) {
	    pos_min = i;
		for (int j = i + 1; j < n; j++) {
		if (inventory[j].getDate() < inventory[pos_min].getDate())
                   pos_min = j;
		}
            if (pos_min != i) {
                 temp = inventory[i].getDate();
                 inventory[i].setDate(inventory[pos_min].getDate());
                 inventory[pos_min].setDate(temp);
            }
	}
}
Book * Inventory::getInventory(){ return inv; }
