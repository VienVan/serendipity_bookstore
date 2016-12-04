#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"


using namespace std;


int main()
{
    ControlModule * runner = new ControlModule();
    runner->userInteraction();
    delete runner;
    runner = nullptr;
	return 0;
}
