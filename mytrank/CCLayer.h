#pragma once
#include<Windows.h>
#include<iostream>
#include "CCGlobal.h"
class CCLayer
{
public:
	//������
	virtual bool ccDrawObject(int, int, char*, WORD) = 0;
	//�������
	virtual bool ccClsObject(int, int, char*, WORD) = 0;
	//��ӡ�ַ�
	bool ccDrawChar(int, int, char*, WORD);
	//����
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

