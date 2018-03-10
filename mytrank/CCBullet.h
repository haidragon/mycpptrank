#pragma once
#include "CCSprite.h"
class CCBullet :
	public CCSprite
{
public:
	CCBullet(int =20,int = 20,char = 0x2);
	//子弹的移动
	bool ccSpriteMove();
	~CCBullet();
	//什么类型子弹
	int ccBullet;

	bool ccDrawObject(int x, int y, char* pszChar, WORD wAttr);
};

