#pragma once
#include<Windows.h>
#include<iostream>
#include "CCGlobal.h"
class CCLayer
{
public:
	//画对象
	virtual bool ccDrawObject(int, int, char*, WORD) = 0;
	//清除对象
	virtual bool ccClsObject(int, int, char*, WORD) = 0;
	//打印字符
	bool ccDrawChar(int, int, char*, WORD);
	//坐标
	int x;
	int y;
	char color;
	void ccSetcolor(char);
	char ccGetcolor();
	int ccGetX();
	int ccGetY();
	void ccSetX(int x);
	void ccSetY(int y);
	CCLayer();
	~CCLayer();
};

