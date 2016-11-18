#ifndef _MODULE_H
#define _MODULE_H

#include "Inventory.h"

class Module
{
protected:
	const double SALESTAX = 1.0875;
	const double WHOLESALEMARKUP = 1.3;
	Inventory * inv;
public: 
	Module(Inventory * i) : inv(i){}
	Module();
	virtual void UserInteraction() = 0;
};

#endif
