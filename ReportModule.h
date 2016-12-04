#ifndef __REPORTMODULE__H
#define __REPORTMODULE__H

#include "Module.h"


class ReportModule : public Module
{
	void userInteraction();
	ReportModule(Inventory * i) : Module(i) {};
};

#endif
