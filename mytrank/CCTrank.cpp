#include "CCTrank.h"
#include "vector"
#include<stdio.h>
#pragma comment(lib,"Winmm.lib")
//������
bool CCTrank::ccDrawObject(int x, int y, char* pszChar, WORD wAttr) {
	bool Bool = true;
	this->ccDrawTrank(x, y, pszChar, wAttr, Bool);
	return true;
}
//�������
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

//��ӡ̹��
bool CCTrank::ccDrawTrank(int x, int y, char* pszChar, WORD wAttr,bool Bool) {	
	switch (this->ccGetDir())
	{
	case TANK_DIR_LF:
		for (int a = x - 1, i = 0; i<3, a <= x + 1; i++, a++) {
			for (int b = y - 1, j = 0; j<3, b <= y + 1; j++, b++) {
				if (ccmyTrank[0][i][j] == 8) {
					///////////////�ж��Ǵ�ӡ��������/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//�ж���ʲô���͵�̹��
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
					///////////////�ж��Ǵ�ӡ��������/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//ccGlMap[a][b] = USERTANKMAP;
							//�ж���ʲô���͵�̹��
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
					///////////////�ж��Ǵ�ӡ��������/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//ccGlMap[a][b] = USERTANKMAP;
							//�ж���ʲô���͵�̹��
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
					///////////////�ж��Ǵ�ӡ��������/////////////////////
					if (Bool) {
						if (ccGlMap[a][b] != CAOMAP&&ccGlMap[a][b] != QANGMAP) {
							this->ccDrawChar(a, b, pszChar, wAttr);
							//ccGlMap[a][b] = USERTANKMAP;
							//�ж���ʲô���͵�̹��
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

//�ı䷽��
bool CCTrank::ccChargeDir(char cDir) {
	int nNewDir = -1;
	ccClsObject(this->x, this->y, KONG, 0x00);
	//���ж�ǰ���Ƿ�Ϊ�ϰ�

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
		//�����ӵ�
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
	//������ͬ�ͼ���
	if (this->ccGetDir() == nNewDir)
	{
		ccSpriteMove();
		return true;
	}
	this->ccSetDir(nNewDir);
	//�ֶ��ƶ�
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
//̹���ƶ�
bool CCTrank::ccSpriteMove() {
	if (this->cctrankBullet.size()) {
		ccMoveTrankBullet();
	}
	//̹���ƶ�ʱ�ж�ǰ����ϰ���
	if (ccMoveBalk()) {
		return true;
	}
	//̹���ƶ�ʱ�ж�ǰ���̹��
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
		//Ҫ�ŵ��ж����� ���ж��������ӵ�
		this->ccCreateBullet(2);
		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (x <= 2) {
		//��������
		ccClsObject(this->x, this->y, KONG, 0x00);
		//��̹���·���
		x++;
		ccChargeDir('d');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (y <= 2) {
		//��������
		ccClsObject(this->x, this->y, KONG, 0x00);
		y++;
		//��̹���·���
		ccChargeDir('s');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (x >= 37) {
		//��������
		ccClsObject(this->x, this->y, KONG, 0x00);
		//��̹���·���
		x--;
		ccChargeDir('a');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	else if (y >= 37) {

		//��������
		ccClsObject(this->x, this->y, KONG, 0x00);
		//��̹���·���
		y--;
		ccChargeDir('w');
		ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
}


//�ӵ��ƶ�
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

	//������ô��   ��Ϊ���ָ������Ƹı�Ĳ���ԭ���Ǹ�  
	/*for (auto i : cctrankBullet) {
	i.ccSpriteMove();
	}*/
	return true;
}

//�ж�̹���ƶ�ʱǰ���Ƿ�Ϊ�ϰ���
bool CCTrank::ccMoveBalk() {
	//��ǰ�ƶ�ʱֻ�ж���̹��ǰ��������
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
//�ж�̹���ƶ�ʱǰ���Ƿ�Ϊ̹��
bool CCTrank::ccMoveOthterTrank() {
	//����Ƿ��ǵз�̹��
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

	////////////////��////////////////////
	{
		{ 0,8,0 },
		{ 8,8,8 },
		{ 8,0,8 }
	},
	////////////////��////////////////////
	{
		{ 8,0,8 },
		{ 8,8,8 },
		{ 0,8,0 }
	},
	////////////////��////////////////////
	{
		{ 0,8,8 },
		{ 8,8,0 },
		{ 0,8,8 }
	},
	////////////////��////////////////////
	{
		{ 8,8,0 },
		{ 0,8,8 },
		{ 8,8,0 }
	}
};