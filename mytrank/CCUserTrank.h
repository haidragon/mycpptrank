#pragma once
#include "CCTrank.h"
#include "CCEnemyTrank.h"
#include <vector>
class CCUserTrank :
	public CCTrank
{
public:
	CCUserTrank(int = 20, int =20, int life = 20, int dir = TANK_DIR_UP, int ccSpeed = 1, char color = 0x3);
	~CCUserTrank();
	bool ccSpriteMove();
	bool ccCCsetTrankDir();

};

