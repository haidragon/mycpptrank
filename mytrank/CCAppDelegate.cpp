#include "CCAppDelegate.h"



CCAppDelegate::CCAppDelegate()
{
}

CCAppDelegate::CCAppDelegate(const CCAppDelegate&) {

}
CCAppDelegate& CCAppDelegate::operator=(const CCAppDelegate&) {
	return *instance;
}
CCAppDelegate* CCAppDelegate::instance = new CCAppDelegate();

CCAppDelegate*CCAppDelegate::getInstance() {
	return instance;
}

//��ʼ��һ������
CCDirector* CCAppDelegate::InitccDiretor() {
	CCDirector* ccDirector = new CCDirector();
	return ccDirector;
}
