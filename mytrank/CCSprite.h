#pragma once
#include "CCLayer.h"
class CCSprite :
	public CCLayer
{
public:
	CCSprite(int x = 20, int y =20, int life =20, int dir= TANK_DIR_UP, int ccSpeed =1, char color = 0x1);
	~CCSprite();
////////////////////CCSprite����////////////////////
    //������
     bool ccDrawObject(int, int, char*, WORD);
	//�������
	 bool ccClsObject(int, int, char*, WORD);
	//��������
	bool ccCreateSprite();
	//�ƶ�
	virtual bool ccSpriteMove();
	//�ܷ��ƶ�
	bool ccSpriteCanMove(); 
	//�ı䷽��
	virtual bool ccChargeDir(char);
	
	//��ײ���
	void ccOllide(CCSprite);

	int ccGetLife();
	void ccSetLife(int);

	void ccSetDir(int);
	int ccGetDir();

////////////////////CCSprite����////////////////////
//private:
	//����ֵ
	int life;
	//����
	int dir;
	//�ٶ�
	int ccSpeed;
};

