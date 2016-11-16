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

void Inventory::pullInventoryFromFile(string filename){}
void Inventory::sortInventoryByQuantity(){}
void Inventory::sortInventoryByCost(){}
void Inventory::sortInventoryByDate(){}
Book * Inventory::getInventory(){ return inv; }
