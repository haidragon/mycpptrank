#pragma once
#include "CCDirector.h"
#include "CCSprite.h"
class CCAppDelegate
{
public:
	static CCAppDelegate* getInstance();
	CCDirector* InitccDiretor();
private:
	CCAppDelegate();
	CCAppDelegate(const CCAppDelegate&);
	CCAppDelegate& operator=(const CCAppDelegate&);
	static CCAppDelegate *instance;
};

