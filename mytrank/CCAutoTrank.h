#pragma once

#include "CCGlobal.h"
#include "CCTrank.h"
#include "CCAstar.h"
class CCAutoTrank :
	public CCTrank
{
public:
	CCAutoTrank();
	CCAutoTrank(int, int, int life = 20, int dir = TANK_DIR_UP, int ccSpeed = 1, char color = 0x3);
	~CCAutoTrank();
	//ÒÆ¶¯
	bool ccSpriteMove();
	bool ccChargeDir(int);
};

