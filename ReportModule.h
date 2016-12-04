#ifndef __REPORTMODULE__H
#define __REPORTMODULE__H

#include "Module.h"


class ReportModule : public Module
{
public:
	ReportModule(Inventory * i) : Module(i){}
	void userInteraction();


};

#endif
