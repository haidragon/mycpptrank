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
		//��һ����ά�����ʾ̹�˵Ĳ�ͬ����
	static const int ccmyTrank[4][3][3];
	//������
	bool ccDrawObject(int,int, char*, WORD);
	//�������
	bool ccClsObject(int,int, char*, WORD);
	//��ӡ̹��
	bool ccDrawTrank(int, int, char*, WORD,bool);
	//��д
	//�ƶ�
	bool ccSpriteMove();
	//�ı䷽��
	bool ccChargeDir(char);
	bool ccCreateBullet(int Bullet);
	vector  <CCBullet> cctrankBullet;
	bool ccMoveTrankBullet();
	//�ƶ���ǰ���Ƿ�Ϊ�ϰ�
	bool ccMoveBalk();
	//�ж�̹���ƶ�ʱǰ���Ƿ�Ϊ̹��
	bool ccMoveOthterTrank();
	//ʲô̹��
	int ccTirank;

	CCTrank(int =20, int =20, int life = 20, int dir = TANK_DIR_UP, int ccSpeed = 1, char color = 0x3);
	~CCTrank();
};

