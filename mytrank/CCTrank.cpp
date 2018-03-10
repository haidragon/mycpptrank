#include "CCTrank.h"
#include "vector"
#include<stdio.h>
#pragma comment(lib,"Winmm.lib")
//画对象
bool CCTrank::ccDrawObject(int x, int y, char* pszChar, WORD wAttr) {
	bool Bool = true;
	this->ccDrawTrank(x, y, pszChar, wAttr, Bool);
	return true;
}
//清除对象
bool CCTrank::ccClsObject(int x, int y, char* pszChar, WORD wAttr) {
	bool Bool = false;
	this->ccDrawTrank(x, y, pszChar, wAttr, Bool);
	return true;
}
CCTrank::CCTrank(int x, int y , int life, int dir, int ccSpeed, char color)
{
	this->x = x;
	this->y = y;
	this->life = life;
	this->dir = dir;
	this->ccSpeed = ccSpeed;
	this->color;
}


CCTrank::~CCTrank()
{
}

//打印坦克
bool CCTrank::ccDrawTrank(int x, int y, char* pszChar, WORD wAttr,bool Bool) {	
	switch (this->ccGetDir())
	{
	case TANK_DIR_LF:
		for (int a = x - 1, i = 0; i<3, a <= x + 1; i++, a++) {
			for (int b = y - 1, j = 0; j<3, b <= y + 1; j++, b++) {
				if (ccmyTrank[0][i][j] == 8) {
					///////////////判断是打印还是清理/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//判断是什么类型的坦克
							if (this->ccTirank == 1){
								ccGlMap[a][b] = USERTANKMAP;
							}
							else {
								ccGlMap[a][b] = ENEMYTANKMAP;
							}

						}

					}
					else {
						if (ccGlMap[a][b] == USERTANKMAP|| ccGlMap[a][b] == ENEMYTANKMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							ccGlMap[a][b] = KONGMAP;
						}
					}
				}
			}
		}
		break;
	case TANK_DIR_RH:
		for (int a = x - 1, i = 0; i<3, a <= x + 1; i++, a++) {
			for (int b = y - 1, j = 0; j<3, b<= y + 1; j++, b++) {
				if (ccmyTrank[1][i][j] == 8) {
					///////////////判断是打印还是清理/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//ccGlMap[a][b] = USERTANKMAP;
							//判断是什么类型的坦克
							if (this->ccTirank == 1) {
								ccGlMap[a][b] = USERTANKMAP;
							}
							else {
								ccGlMap[a][b] = ENEMYTANKMAP;
							}
						}

					}
					else {
						if (ccGlMap[a][b] == USERTANKMAP || ccGlMap[a][b] == ENEMYTANKMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							ccGlMap[a][b] = KONGMAP;
						}
					}
				}
			}
		}
		break;
	case TANK_DIR_UP:
		for (int a = x - 1, i = 0; i<3, a <= x + 1; i++, a++) {
			for (int b = y - 1, j = 0; j<3, b<= y + 1; j++, b++) {
				if (ccmyTrank[2][i][j] == 8) {
					///////////////判断是打印还是清理/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//ccGlMap[a][b] = USERTANKMAP;
							//判断是什么类型的坦克
							if (this->ccTirank == 1) {
								ccGlMap[a][b] = USERTANKMAP;
							}
							else {
								ccGlMap[a][b] = ENEMYTANKMAP;
							}
						}

					}
					else {
						if (ccGlMap[a][b] == USERTANKMAP || ccGlMap[a][b] == ENEMYTANKMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							ccGlMap[a][b] = KONGMAP;
						}
					}
				}
			}
		}
		break;
	case TANK_DIR_DW:
		for (int a = x - 1, i = 0; i<3, a <= x + 1; i++, a++) {
			for (int b = y - 1, j = 0; j<3, b<= y + 1; j++, b++) {
				if (ccmyTrank[3][i][j] == 8) {
					///////////////判断是打印还是清理/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//ccGlMap[a][b] = USERTANKMAP;
							//判断是什么类型的坦克
							if (this->ccTirank == 1) {
								ccGlMap[a][b] = USERTANKMAP;
							}
							else {
								ccGlMap[a][b] = ENEMYTANKMAP;
							}
						}

					}
					else {
						if (ccGlMap[a][b] == USERTANKMAP || ccGlMap[a][b] == ENEMYTANKMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							ccGlMap[a][b] = KONGMAP;
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
	return true;
}

//改变方向
bool CCTrank::ccChargeDir(char cDir) {
	int nNewDir = -1;
	ccClsObject(this->x, this->y, KONG, 0x00);
	//先判断前面是否为障碍

	switch (cDir) {
	case 'W':
	case 'w':
	case 'i':
	case 'I':
		nNewDir = TANK_DIR_UP;
		break;
	case 's':
	case 'S':
	case 'K':
	case 'k':
		nNewDir = TANK_DIR_DW;
		break;
	case 'a':
	case 'A':
	case 'j':
	case 'J':
		nNewDir = TANK_DIR_LF;
		break;
	case 'd':
	case 'D':
	case 'l':
	case 'L':
		nNewDir = TANK_DIR_RH;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'e':
	case 'E':
	case 'O':
	case 'o':
		//创建子弹
		PlaySound("allen.wav",0,0);
		ccCreateBullet(1);

		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		break;
	default:
		break;
	}
	if (nNewDir == -1)
	{
		return false;
	}
	//方向相同就加速
	if (this->ccGetDir() == nNewDir)
	{
		ccSpriteMove();
		return true;
	}
	this->ccSetDir(nNewDir);
	//手动移动
	ccSpriteMove();
	return true;
}
bool CCTrank::ccCreateBullet(int Bullet) {
	CCBullet ccBul;
	ccBul.x = this->x;
	ccBul.y = this->y;
	ccBul.ccSpeed = 1;
	ccBul.life = 1;
	ccBul.ccBullet = Bullet;
	ccBul.ccSetDir(this->ccGetDir());
	this->cctrankBullet.push_back(ccBul);
	return true;
}
//坦克移动
bool CCTrank::ccSpriteMove() {
	if (this->cctrankBullet.size()) {
		ccMoveTrankBullet();
	}
	//坦克移动时判断前面的障碍物
	if (ccMoveBalk()) {
		return true;
	}
	//坦克移动时判断前面的坦克
	else if (ccMoveOthterTrank()) {
		return false;
	}
	else if (x >= 2 && x <= 36 && y >= 3 && y <= 36)
	{
		ccClsObject(this->x, this->y, KONG, 0x00);
		switch (this->ccGetDir()) {
		case TANK_DIR_UP:
			this->y-= this->ccSpeed;
			break;
		case TANK_DIR_DW:
			this->y+= this->ccSpeed;
			break;
		case TANK_DIR_LF:
			this->x-= this->ccSpeed;
			break;
		case TANK_DIR_RH:
			this->x+= this->ccSpeed;
			break;
		}
		//要放到判断下面 先判断再生成子弹
		this->ccCreateBullet(2);
		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (x <= 2) {
		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		//给坦克新方向
		x++;
		ccChargeDir('d');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (y <= 2) {
		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		y++;
		//给坦克新方向
		ccChargeDir('s');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (x >= 37) {
		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		//给坦克新方向
		x--;
		ccChargeDir('a');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (y >= 37) {

		//清理所有
		ccClsObject(this->x, this->y, KONG, 0x00);
		//给坦克新方向
		y--;
		ccChargeDir('w');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
}


//子弹移动
bool CCTrank::ccMoveTrankBullet() {
	if (cctrankBullet.size() != 0) {
		for (auto Iter = cctrankBullet.begin(); Iter != cctrankBullet.end();)
		{
			if (!(*Iter).life) {
				Iter = cctrankBullet.erase(Iter++);
			}
			else {
				Iter++;
			}
		}
	}
	for (int i = 0; i < (this->cctrankBullet.size()); i++) {
		this->cctrankBullet[i].ccSpriteMove();
	}

	//不能这么用   因为出现副本机制改变的不是原来那个  
	/*for (auto i : cctrankBullet) {
	i.ccSpriteMove();
	}*/
	return true;
}

//判断坦克移动时前面是否为障碍物
bool CCTrank::ccMoveBalk() {
	//向前移动时只判断了坦克前面三个点
	if (
		
		((ccGlMap[2 + this->x][this->y] == ZHANGAIMAP || ccGlMap[1 + this->x][-1 + this->y] == ZHANGAIMAP || ccGlMap[1 + this->x][1 + this->y] == ZHANGAIMAP) && this->dir == TANK_DIR_RH) ||
		((ccGlMap[-2 + this->x][this->y] == ZHANGAIMAP || ccGlMap[-1 + this->x][-1 + this->y] == ZHANGAIMAP || ccGlMap[-1 + this->x][1 + this->y] == ZHANGAIMAP) && this->dir == TANK_DIR_LF) ||
		((ccGlMap[this->x][2 + this->y] == ZHANGAIMAP || ccGlMap[1 + this->x][1 + this->y] == ZHANGAIMAP || ccGlMap[-1 + this->x][1 + this->y] == ZHANGAIMAP) && this->dir == TANK_DIR_DW) ||
		((ccGlMap[this->x][-2 + this->y] == ZHANGAIMAP || ccGlMap[-1 + this->x][-1 + this->y] == ZHANGAIMAP || ccGlMap[1 + this->x][-1 + this->y] == ZHANGAIMAP) && this->dir == TANK_DIR_UP)
		||
		((ccGlMap[2 + this->x][this->y] == ZHANGAIMAP2 || ccGlMap[1 + this->x][-1 + this->y] == ZHANGAIMAP2 || ccGlMap[1 + this->x][1 + this->y] == ZHANGAIMAP2) && this->dir == TANK_DIR_RH) ||
		((ccGlMap[-2 + this->x][this->y] == ZHANGAIMAP2 || ccGlMap[-1 + this->x][-1 + this->y] == ZHANGAIMAP2 || ccGlMap[-1 + this->x][1 + this->y] == ZHANGAIMAP2) && this->dir == TANK_DIR_LF) ||
		((ccGlMap[this->x][2 + this->y] == ZHANGAIMAP2 || ccGlMap[1 + this->x][1 + this->y] == ZHANGAIMAP2 || ccGlMap[-1 + this->x][1 + this->y] == ZHANGAIMAP2) && this->dir == TANK_DIR_DW) ||
		((ccGlMap[this->x][-2 + this->y] == ZHANGAIMAP2 || ccGlMap[-1 + this->x][-1 + this->y] == ZHANGAIMAP2 || ccGlMap[1 + this->x][-1 + this->y] == ZHANGAIMAP2) && this->dir == TANK_DIR_UP)

		
		) {
		  this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}

	return false;
}
//判断坦克移动时前面是否为坦克
bool CCTrank::ccMoveOthterTrank() {
	//检测是否是敌方坦克
	if (((ccGlMap[2 + this->x][this->y] == USERTANKMAP || ccGlMap[1 + this->x][-1 + this->y] == USERTANKMAP || ccGlMap[1 + this->x][1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_RH) ||
		((ccGlMap[-2 + this->x][this->y] == USERTANKMAP || ccGlMap[-1 + this->x][-1 + this->y] == USERTANKMAP || ccGlMap[-1 + this->x][1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_LF) ||
		((ccGlMap[this->x][2 + this->y] == USERTANKMAP || ccGlMap[1 + this->x][1 + this->y] == USERTANKMAP || ccGlMap[-1 + this->x][1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_DW) ||
		((ccGlMap[this->x][-2 + this->y] == USERTANKMAP || ccGlMap[-1 + this->x][-1 + this->y] == USERTANKMAP || ccGlMap[1 + this->x][-1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_UP)
		||
		((ccGlMap[2 + this->x][this->y] == ENEMYTANKMAP || ccGlMap[1 + this->x][-1 + this->y] == ENEMYTANKMAP || ccGlMap[1 + this->x][1 + this->y] == ENEMYTANKMAP) && this->dir == TANK_DIR_RH) ||
		((ccGlMap[-2 + this->x][this->y] == ENEMYTANKMAP || ccGlMap[-1 + this->x][-1 + this->y] == ENEMYTANKMAP || ccGlMap[-1 + this->x][1 + this->y] == ENEMYTANKMAP) && this->dir == TANK_DIR_LF) ||
		((ccGlMap[this->x][2 + this->y] == ENEMYTANKMAP || ccGlMap[1 + this->x][1 + this->y] == ENEMYTANKMAP || ccGlMap[-1 + this->x][1 + this->y] == ENEMYTANKMAP) && this->dir == TANK_DIR_DW) ||
		((ccGlMap[this->x][-2 + this->y] == ENEMYTANKMAP || ccGlMap[-1 + this->x][-1 + this->y] == ENEMYTANKMAP || ccGlMap[1 + this->x][-1 + this->y] == ENEMYTANKMAP) && this->dir == TANK_DIR_UP)
		)
	{

		if (((ccGlMap[2 + this->x][this->y] == USERTANKMAP || ccGlMap[1 + this->x][-1 + this->y] == USERTANKMAP || ccGlMap[1 + this->x][1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_RH) ||
			((ccGlMap[-2 + this->x][this->y] == USERTANKMAP || ccGlMap[-1 + this->x][-1 + this->y] == USERTANKMAP || ccGlMap[-1 + this->x][1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_LF) ||
			((ccGlMap[this->x][2 + this->y] == USERTANKMAP || ccGlMap[1 + this->x][1 + this->y] == USERTANKMAP || ccGlMap[-1 + this->x][1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_DW) ||
			((ccGlMap[this->x][-2 + this->y] == USERTANKMAP || ccGlMap[-1 + this->x][-1 + this->y] == USERTANKMAP || ccGlMap[1 + this->x][-1 + this->y] == USERTANKMAP) && this->dir == TANK_DIR_UP)
			) {

		}
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else {
		return false;
	}
	
}
const int CCTrank::ccmyTrank[4][3][3] = {

	////////////////上////////////////////
	{
		{ 0,8,0 },
		{ 8,8,8 },
		{ 8,0,8 }
	},
	////////////////下////////////////////
	{
		{ 8,0,8 },
		{ 8,8,8 },
		{ 0,8,0 }
	},
	////////////////左////////////////////
	{
		{ 0,8,8 },
		{ 8,8,0 },
		{ 0,8,8 }
	},
	////////////////右////////////////////
	{
		{ 8,8,0 },
		{ 0,8,8 },
		{ 8,8,0 }
	}
};