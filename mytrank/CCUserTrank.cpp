#include "CCUserTrank.h"



CCUserTrank::CCUserTrank(int x, int y, int life , int dir , int ccSpeed , char color)
{
	this->x = x;
	this->y = y;
	this->life = life;
	this->dir = dir;
	this->ccSpeed = ccSpeed;
	this->color;
	//�û�̹��
	this->ccTirank = 1;
}

CCUserTrank::~CCUserTrank()
{
}
//̹���ƶ�
bool CCUserTrank::ccSpriteMove() {

	ccUserTrankX = this->x;
	ccUserTrankY = this->y;
	//̹���ƶ�ʱ�ж�ǰ����ϰ���
	if (ccMoveBalk()) {
		return false;
	}
	//̹���ƶ�ʱ�ж�ǰ���̹��
	else if (ccMoveOthterTrank()) {
		return false;
	}
	//ccMoveTrankBullet();
	ccClsObject(this->x, this->y, KONG, 0x00);
	if (x == 2||y==2||y==37||x==37) {
		if (x == 2 && this->ccGetDir() == TANK_DIR_LF)
		{
		//	return true;
		}
		else if (x == 37 && this->ccGetDir() == TANK_DIR_RH){
		}
		else if (y == 37 && this->ccGetDir() == TANK_DIR_DW) {
		}
		else if (y == 2 && this->ccGetDir() == TANK_DIR_UP) {
		}
		else {
			ccCCsetTrankDir();
		}
		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	if (x >2 && x < 37 && y > 1 && y < 37)
	{
		
		ccCCsetTrankDir();
		this->ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
}

bool CCUserTrank::ccCCsetTrankDir() {
	switch (this->ccGetDir()) {
	case TANK_DIR_UP:
		this->y--;
		break;
	case TANK_DIR_DW:
		this->y++;
		break;
	case TANK_DIR_LF:
		this->x--;
		break;
	case TANK_DIR_RH:
		this->x++;
		break;
	}
	return true;
}