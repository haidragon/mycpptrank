#pragma once
#include "CCSprite.h"
class CCBullet :
	public CCSprite
{
public:
	CCBullet(int =20,int = 20,char = 0x2);
	//�ӵ����ƶ�
	bool ccSpriteMove();
	~CCBullet();
	//ʲô�����ӵ�
	int ccBullet;

	bool ccDrawObject(int x, int y, char* pszChar, WORD wAttr);
};

