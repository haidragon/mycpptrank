#include "CCAutoTrank.h"



CCAutoTrank::CCAutoTrank()
{
}

CCAutoTrank::CCAutoTrank(int x , int y , int life, int dir, int ccSpeed, char color)
{
	this->x = x;
	this->y = y;
	this->life = life;
	this->dir = dir;
	this->ccSpeed = ccSpeed;
	this->color = color;
	//敌方坦克
	this->ccTirank = 2;
}


CCAutoTrank::~CCAutoTrank()
{
}

//
//bool CCAutoTrank::ccSpriteMove() {
//	CCSprite::ccClsObject(this->x, this->y, KONG, 0x00);
//	if (x >= 2 && x <= 36 && y >= 3 && y <= 36) {
//		switch (this->dir) {
//		case TANK_DIR_UP:
//			this->y -= ccSpeed;
//			break;
//		case TANK_DIR_DW:
//			this->y += ccSpeed;
//			break;
//		case TANK_DIR_LF:
//			this->x -= ccSpeed;
//			break;
//		case TANK_DIR_RH:
//			this->x += ccSpeed;
//			break;
//
//		}
//		CCSprite::ccDrawObject(this->x, this->y, SPRITE, this->color);
//		return true;
//	}
//}
//
bool CCAutoTrank::ccSpriteMove()

{   
	//坦克移动时判断前面的坦克
	 if (ccMoveOthterTrank()) {
		return false;
	}
	 //坦克移动时判断前面的障碍物
	/* if (ccMoveBalk()) {
		 return false;
	 }*/
	//清理所有
	ccClsObject(this->x, this->y, KONG, 0x00);
	CCAstar as;
	as.InitMapInfo((int*)ccGlMap, 39, 39, ZHANGAIMAP);
	as.InitCoord({ this->x,this->y}, { ccUserTrankX, ccUserTrankY });
	
	as.InitCoord({ this->x,  this->y }, { ccUserTrankX, ccUserTrankY });
	if (as.FindPath())
	{
		as.GetPath();


		for (int i = as.m_Path.size() - 1; i >0; i--)
		{
			this->ccChargeDir(as.m_Path[i].d);
			//ccDrawObject(this->x, this->y, SPRITE, this->color);
			break;

		}
	}
	if (x >= 1 && x <= 38 && y >= 1 && y <= 38) {
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
	    ccDrawObject(this->x, this->y, SPRITE, this->color);
		return true;
	}
	return false;

}

//改变方向
bool CCAutoTrank::ccChargeDir(int cDir) {
	int nNewDir = -1;
	switch (cDir) {
	case 0:
		this->ccSetDir(TANK_DIR_UP);
		break;
	case 1:
		this->ccSetDir(TANK_DIR_DW);
		break;
	case 2:
		this->ccSetDir(TANK_DIR_LF);
		break;
	case 3:
		this->ccSetDir(TANK_DIR_RH);
		break;
	}
	return true;
}