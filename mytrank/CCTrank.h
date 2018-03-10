#pragma once
#include "CCSprite.h"
#include "CCBullet.h"
#include "CCGlobal.h"
#include <list>
#include <vector>
using namespace std;
class CCTrank :
	public CCSprite
{
public:
		//用一个二维数组表示坦克的不同坐标
	static const int ccmyTrank[4][3][3];
	//画对象
	bool ccDrawObject(int,int, char*, WORD);
	//清除对象
	bool ccClsObject(int,int, char*, WORD);
	//打印坦克
	bool ccDrawTrank(int, int, char*, WORD,bool);
	//重写
	//移动
	bool ccSpriteMove();
	//改变方向
	bool ccChargeDir(char);
	bool ccCreateBullet(int Bullet);
	vector  <CCBullet> cctrankBullet;
	bool ccMoveTrankBullet();
	//移动到前面是否为障碍
	bool ccMoveBalk();
	//判断坦克移动时前面是否为坦克
	bool ccMoveOthterTrank();
	//什么坦克
	int ccTirank;

	CCTrank(int =20, int =20, int life = 20, int dir = TANK_DIR_UP, int ccSpeed = 1, char color = 0x3);
	~CCTrank();
};

