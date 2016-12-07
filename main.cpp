#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"


using namespace std;

const int SIZE = 1024; /**/

int main()
{
	string filepath;
     cout << "Please enter the path to the inventory file:\n";
     cin >> filepath;
    Module *runner = new ControlModule(filepath);
    runner->userInteraction();
    delete runner;
    runner = nullptr;
	return 0;
}

/*
 What's left:
 Finish modules
 Fix module interaction
 Fix inventory/book/date and book file
*/
