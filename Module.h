#ifndef _MODULE_H
#define _MODULE_H

#include "Inventory.h"

class Module
{
protected:
	Inventory * inv;
    double retailmarkup;
    double salestax;
public:
	Module(Inventory * i) : inv(i){
        salestax = 1.0875;
        retailmarkup = 1.3;
    }
	Module(){
        salestax = 1.0875;
        retailmarkup = 1.3;
    }
	virtual ~Module(){}
	virtual void userInteraction() = 0;
};

#endif
