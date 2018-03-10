#include "CCEnemyTrank.h"





CCEnemyTrank::~CCEnemyTrank()
{
}

//̹���ƶ�
bool CCEnemyTrank::ccSpriteMove() {

	if (this->life <= 0) {
			for (int i = 0;i < this->cctrankBullet.size();i++) {
				cctrankBullet[i].ccClsObject(cctrankBullet[i].x, cctrankBullet[i].y, KONG, 0x00);
			}
			ccClsObject(this->x, this->y, KONG, 0x00);
			return false;
	}





	this->life =CCEnemyTranklife;
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
			this->y -= this->ccSpeed;
			break;
		case TANK_DIR_DW:
			this->y += this->ccSpeed;
			break;
		case TANK_DIR_LF:
			this->x -= this->ccSpeed;
			break;
		case TANK_DIR_RH:
			this->x += this->ccSpeed;
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

CCEnemyTrank::CCEnemyTrank(int x, int y, int life , int dir, int ccSpeed , char color) {
	this->x = x;
	this->y = y;
	this->life = life;
	this->dir = dir;
	this->ccSpeed = ccSpeed;
	this->color = color;
	//�з�̹��
	this->ccTirank = 2;

}
bool CCEnemyTrank::ccMoveBalk() {

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
		//�Ȳ������ж�
		ccClsObject(this->x, this->y, KONG, 0x00);
		switch (this->ccGetDir()) {
		case TANK_DIR_UP:
			this->y+=1;
			break;
		case TANK_DIR_DW:
			this->y -=1;
			break;
		case TANK_DIR_LF:
			this->x += 1;
			break;
		case TANK_DIR_RH:
			this->x -=1;
			break;
		}
		return true;
	}

	return false;
}