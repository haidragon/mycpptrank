#pragma once
#include "CCLayer.h"
class CCSprite :
	public CCLayer
{
public:
	CCSprite(int x = 20, int y =20, int life =20, int dir= TANK_DIR_UP, int ccSpeed =1, char color = 0x1);
	~CCSprite();
////////////////////CCSprite方法////////////////////
    //画对象
     bool ccDrawObject(int, int, char*, WORD);
	//清除对象
	 bool ccClsObject(int, int, char*, WORD);
	//创建精灵
	bool ccCreateSprite();
	//移动
	virtual bool ccSpriteMove();
	//能否移动
	bool ccSpriteCanMove(); 
	//改变方向
	virtual bool ccChargeDir(char);
	
	//碰撞检测
	void ccOllide(CCSprite);

	int ccGetLife();
	void ccSetLife(int);

	void ccSetDir(int);
	int ccGetDir();

////////////////////CCSprite属性////////////////////
//private:
	//生命值
	int life;
	//方向
	int dir;
	//速度
	int ccSpeed;
};

