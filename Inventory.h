#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Book.h"
#include <string>
#include <fstream>

using namespace std;

class Inventory
{
private:
	const int SIZE = 1024;
    Book *inventory[1024];
    int currentSize;
    string filepath;

public:
    Inventory(string);
    ~Inventory();
	void pullInventoryFromFile(string);
    void addBook(Book input);
    void deleteBook(int index);
    int searchTitle(string);
    void sortByTitle();
	void sortByQuantity();
	void sortByCost();
	void sortByDate();
    friend ostream &operator<<(ostream &, const Inventory &);
    Book *operator[] (int index) { return inventory[index]; }
    
    //To throw exceptions:
    class InvalidFile {};
    class EmptyInventory {};
    class FullInventory {};
};

#endif
