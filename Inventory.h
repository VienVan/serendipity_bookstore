#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Book.h"
#include <string>
#include <fstream>

const int SIZE = 1024;
using namespace std;

class Inventory
{
private:
    Book *inventory[SIZE];
    double retailmarkup;
    double salestax;
    int currentSize;
    string filepath;

public:
    Inventory(string, double, double);
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
    double totalWholesale();
    
    double totalRetail() { return totalWholesale() * retailmarkup * salestax; }
    Book *operator[] (int index) { return inventory[index]; }
    //To throw exceptions:
    class InvalidFile {};
    class EmptyInventory {};
    class FullInventory {};
};

#endif
