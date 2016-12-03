#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"
#include "Date.h"
#include "Inventory.h"


using namespace std;


int main()
{
    ControlModule runner = ControlModule();
    runner.userInteraction();
	system("pause");
	return 0;
}
