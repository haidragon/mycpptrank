#include "CCAppDelegate.h"
int main()
{
	//////////////////Ä£Äâ°´ÏÂshift¼ü////////////////
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	CCAppDelegate* CCAppDelegate = CCAppDelegate->getInstance();
	CCDirector* ccDirector = CCAppDelegate->InitccDiretor();
	ccDirector->ccStartAnimation();
	return 0;
}