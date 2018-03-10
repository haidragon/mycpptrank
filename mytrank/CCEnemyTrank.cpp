#include "CCEnemyTrank.h"





CCEnemyTrank::~CCEnemyTrank()
{
}

//坦克移动
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

CCEnemyTrank::CCEnemyTrank(int x, int y, int life , int dir, int ccSpeed , char color) {
	this->x = x;
	this->y = y;
	this->life = life;
	this->dir = dir;
	this->ccSpeed = ccSpeed;
	this->color = color;
	//敌方坦克
	this->ccTirank = 2;

}
bool CCEnemyTrank::ccMoveBalk() {

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
		//先擦掉再判断
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