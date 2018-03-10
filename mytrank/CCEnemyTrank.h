#pragma once
#include "CCTrank.h"
class CCEnemyTrank :
	public CCTrank
{
public:
	CCEnemyTrank(int =20, int =20, int life = 20, int dir = TANK_DIR_UP, int ccSpeed = 1, char color = 0x3);
	~CCEnemyTrank();
	//÷ÿ–¥’œ∞≠ºÏ≤‚
	bool ccMoveBalk();
	//÷ÿ–¥“∆∂Ø
	bool ccSpriteMove();
};

