#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"


using namespace std;


int main()
{
    ControlModule runner = ControlModule();
    runner.userInteraction();
	cin.ignore();
	cin.get();
	return 0;
}
