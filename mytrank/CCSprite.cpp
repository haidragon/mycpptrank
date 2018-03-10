#include "CCSprite.h"
#include<iostream>
using namespace std;

////////////////////CCSprite方法////////////////////
//初始化精灵
//bool CCSprite::ccInitSprite() {
//	x = 10;
//	y = 10;
//	life = 100;
//	color = 0x3;
//	dir = TANK_DIR_UP;
//	return true;
//}
//创建精灵
bool CCSprite::ccCreateSprite() {
	if (ccGlMap[x][y] == KONGMAP&&x < 40 && y < 40) {
		this->ccDrawObject(x, y, SPRITE, this->color);
		ccGlMap[x][y] = SPRITEMAP;
		return true;
	}
	return false;
	
}
//移动
bool CCSprite::ccSpriteMove() {
	if (ccGlMap[x][y] == QANGMAP) {
		this->life = 0;
		return false;
	}
	else if (ccGlMap[x][y] == ZHANGAIMAP) {
		this->life = 0;
		return false;
	}
	else if (x >=2 && x <= 36 && y>= 3 &&y <= 36)
	{
		ccClsObject(this->x, this->y, KONG, 0x00);
		switch (this->dir) {
		case TANK_DIR_UP:
			this->y-=ccSpeed;
			break;
		case TANK_DIR_DW:
			this->y+=ccSpeed;
			break;
		case TANK_DIR_LF:
			this->x-= ccSpeed;
			break;
		case TANK_DIR_RH:
			this->x+= ccSpeed;
			break;
		}

		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if ( x <= 2) {
		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		//给坦克新方向
		 x++;
		ccChargeDir( 'd');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if ( y <= 2) {
		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		 y++;
		//给坦克新方向
		ccChargeDir( 's');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if ( x >= 37) {
		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		//给坦克新方向
		 x--;
		ccChargeDir( 'a');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if ( y >= 37) {

		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		//给坦克新方向
		 y--;
		ccChargeDir( 'w');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
}
//能否移动
bool CCSprite::ccSpriteCanMove() {

	//
	return true;
}

//改变方向
bool CCSprite::ccChargeDir(char cDir) {
	int nNewDir = -1;
	switch (cDir) {
	case 'W':
	case 'w':
		nNewDir = TANK_DIR_UP;
		break;
	case 's':
	case 'S':
		nNewDir = TANK_DIR_DW;
		break;
	case 'a':
	case 'A':
		nNewDir = TANK_DIR_LF;
		break;
	case 'd':
	case 'D':
		nNewDir = TANK_DIR_RH;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
		/*case 'e':
		case 'E':
			_getch();
			break;*/
	default:
		break;
	}
	if (nNewDir == -1)
	{
		return false;
	}
	// 如果和原来的方向相反，就不理你
	//if (abs(nNewDir - this->dir) == 2)
	//{
	//	return false;
	//}
	//方向相同就加速
	if (this->dir == nNewDir)
	{
		ccSpriteMove();
		return true;
	}
	//改变方向
	this->dir = nNewDir;
	return true;
}
//碰撞检测
void CCSprite::ccOllide(CCSprite) {

}
int CCSprite::ccGetLife() {
	return life;
}

void CCSprite::ccSetLife(int life) {
	this->life = life;
}
void CCSprite::ccSetDir(int dir) {
	this->dir= dir;
}
int CCSprite::ccGetDir() {

	int num = this->dir;

	return num;
}

CCSprite::CCSprite(int x, int y, int life, int dir, int ccSpeed, char color)
{	
	this->x = x;
	this->y = y;
	this->life = life;
	this->dir = dir;
	this->ccSpeed = ccSpeed;
	this->color = 0x3;
}


CCSprite::~CCSprite()
{
}

bool CCSprite::ccDrawObject(int x, int y, char* pszChar, WORD wAttr) {
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
	if (this->life==0) {
		return false;
	}

	if (ccGlMap[x][y] == KONGMAP) {
	 this->ccDrawChar(x, y, pszChar, wAttr);
	 ccGlMap[x][y] = SPRITEMAP;
	 return true;
	}
	
	return false;
}
//清除对象
bool CCSprite::ccClsObject(int x, int y, char* pszChar, WORD wAttr) {
	if (ccGlMap[x][y] == SPRITEMAP) {
		this->ccDrawChar(x, y, pszChar, wAttr);
		ccGlMap[x][y] = KONGMAP;
	}
	return true;
}

