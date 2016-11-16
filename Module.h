#ifndef _MODULE_H
#define _MODULE_H

class Module
{
protected:
	const double SALESTAX = 0.0875;
	const double WHOLESALEMARKUP = 1.3;
public:
	virtual void UserInteraction() = 0;
};

#endif
