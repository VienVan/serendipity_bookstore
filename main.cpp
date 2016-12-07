#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"


using namespace std;

const int SIZE = 1024;

int main()
{
	try {
		string filepath;
    cout << "Please enter the path to the inventory file:\n";
    getline(cin, filepath);
    Module *runner = new ControlModule(filepath);
    runner->userInteraction();
    delete runner;
    runner = nullptr;
	}
	catch (...){
		cout << "ERROR\n";
	}
	delete runner;
	return 0;
}
