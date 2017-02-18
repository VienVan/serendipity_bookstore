#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ControlModule.h"


using namespace std;


int main()
{
    //Name Block:
    cout << "CIS 22B\nFinal Project\nTeam #1\n\nMembers:\nEric Kim\nRonald Martin\nSyed Tihami\nVien Van\n\n";
    
	string filepath;
	cout << "Please enter the path to the inventory file:\n";
	getline(cin, filepath);
	try {
        ControlModule runner(filepath);
        runner.userInteraction();
    }
    catch (Inventory::InvalidFile) {
        cout << "ERROR: Could not open file.\n";
    }
    
    return 0;
}
