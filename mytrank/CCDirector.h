#pragma once
#include <time.h>
#include <windows.h>
#include <conio.h> 
#include<iostream>
#include "CCGlobal.h"
#include "CCScene.h"
#include "CCSprite.h"
#include "CCTrank.h"
#include "CCUserTrank.h"
#include "CCEnemyTrank.h"
#include "CCAutoTrank.h"

using namespace std;

class CCDirector
{
public:
	

	bool ccSetWindowInfo(char*, int, int);
	
	//Æô¶¯»­
	void ccStartAnimation();
	CCDirector();
	~CCDirector();
	bool ccDraw();

	static bool ccDrawMap();
	static bool ccDrawChar(int, int, char*, WORD);
	static bool ccStart();
	static bool ccInitMap();
	static bool ccgrade();
};
