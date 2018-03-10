#include "CCBullet.h"



CCBullet::CCBullet( int x,int y,char color)
{
	this->x = x;
	this->y = y;
	this->color = color;

}


CCBullet::~CCBullet()
{
}

//移动
bool CCBullet::ccSpriteMove() {
	if (ccGlMap[x][y] == HOMEMAP) {
		ccOver = true;
	}
	//用户坦克子弹
	if (this->ccBullet == 1) {
		if (ccGlMap[x][y] == ENEMYTANKMAP) {
			this->life = 0;
			--CCEnemyTranklife;
			++num;
		}
	}if (this->ccBullet == 2) {
		if (ccGlMap[x][y] == USERTANKMAP) {
			this->life = 0;
			--ccUserTrank1life1;
		}
	}
	if (ccGlMap[x][y] == QANGMAP) {
		this->life = 0;
	}
	else if (ccGlMap[x][y] == ZHANGAIMAP) {
		this->life = 0;
	}
	ccClsObject(this->x, this->y, KONG, 0x00);
	//这里会有个这样的bug当坐标在边界上可以进去。但改变方向时值变了 所以在打印时也要判断
	if (x >= 1 && x <= 38 && y >= 1 && y <= 38)
	{
		
		switch (this->dir) {
		case TANK_DIR_UP:
			this->y -= ccSpeed;
			break;
		case TANK_DIR_DW:
			this->y += ccSpeed;
			break;
		case TANK_DIR_LF:
			this->x -= ccSpeed;
			break;
		case TANK_DIR_RH:
			this->x += ccSpeed;
			break;
		}
		if (ccGlMap[x][y] == QANGMAP) {
			this->life = 0;
		}
		else if (ccGlMap[x][y] == ZHANGAIMAP) {
			this->life = 0;
		}


		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	//如果不在范围内
	else {
		this->life = 0;
		return true;
	}

}


bool CCBullet::ccDrawObject(int x, int y, char* pszChar, WORD wAttr) {

	//用户坦克子弹
	if (this->ccBullet == 1) {
		if (ccGlMap[x][y] == ENEMYTANKMAP) {
			this->life = 0;
			--CCEnemyTranklife;
		}
	}if (this->ccBullet == 2) {
		if (ccGlMap[x][y] == USERTANKMAP) {
			this->life = 0;
		}
	}

	if (ccGlMap[x][y] == QANGMAP) {
		this->life = 0;
	}
	if (ccGlMap[x][y] == ZHANGAIMAP) {
		this->life = 0;
	}

	if (ccGlMap[x][y] == ZHANGAIMAP2) {
		//this->ccDrawChar(x, y, "◎", 0x8);
		ccGlMap[x][y] = KONGMAP;
		this->life = 0;
		return false;
	}

	//这句必须要
	if (!(x > 0 && y > 0 && x < 39 && y < 39)) {
		return false;
	}
	//如果当前精灵死了就不打印
	if (this->life == 0) {
		return false;
	}

	if (ccGlMap[x][y] == KONGMAP) {
		this->ccDrawChar(x, y, pszChar, wAttr);
		ccGlMap[x][y] = SPRITEMAP;
		return true;
	}

	return false;
}