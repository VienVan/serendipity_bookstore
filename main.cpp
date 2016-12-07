#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"


using namespace std;


int main()
{
	string filepath;
    cout << "Please enter the path to the inventory file:\n";
    getline(cin, filepath);
    Module *runner = new ControlModule(filepath);
    runner->userInteraction();
    delete runner;
    runner = nullptr;
	return 0;
}

/*Problems and modifications:
 -Massive revamping of all input/output stream functions/operators
 -Changed runner to a pointer to Module for sake of including polymorphism
 -Fix in.ignore()
 -Add exceptions and templates; polymorphism done
 -Still need to complete all three branch modules
 -Documentation and Deliverables
 -Modified Book and Date entry. See below.
 For Ronald: I changed the cout/cin functions for both the Book and Date classes. Here's how it needs to be done:
 Tabs delimit anything that has spaces (Title, Author, Publisher). Everything else has a space at the end.
 For Date, make sure entry is in format: "MM/DD/YYYY"
*/
