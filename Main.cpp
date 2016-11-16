#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Module.h"
#include "Date.h"
#include "Inventory.h"


using namespace std;


int main()
{
	Inventory inv("junk", 1.3);

	cout << inv.getInventory()[3];
	cout << endl;
	system("pause");
	return 0;
}