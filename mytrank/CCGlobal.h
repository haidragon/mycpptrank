#pragma once
#include<list>
#include "CCAstar.h"
/////////////////////////////////////
//MAP�ж�Ӧ������ֵ
#define KONGMAP 0
#define USERTANKMAP 1
#define ENEMYTANKMAP 2
#define BOMBMAP 3
#define QANGMAP 4
#define USERBULLETMAP 5
#define ENEMYTBULLETMAP 6
#define HOMEQANGMAP 7
#define HOMEMAP 8
#define CAOMAP 9
#define ZHANGAIMAP  10
#define ZHANGAIMAP2  12
#define SPRITEMAP 11
#define MAPLONG 40
#define MAPWIDE 40
////////////////////////////////////
//MAP�в�ͬ���ζ�Ӧ�������ַ�
#define USERTANK "��"
#define SPRITE "��"
#define ZHANGAI  "��"
#define ZHANGAI2 "��"
#define ENEMYTANK "��"//������
#define USERBULLET "��"
#define ENEMYBULLET "��"
#define HOME "��"
#define CAO "��"
#define KONG " "
//////////////////////////////////
//��ͬ�����Ӧ��ͬ���ַ�
#define TANK_DIR_UP 0
#define TANK_DIR_DW 1
#define TANK_DIR_LF 2
#define TANK_DIR_RH 3
#define TANKUP "��"
#define TANKDW "��"
#define TANKLF "��"
#define TANKRH "��"
//ȫ�ֵ�ͼ����
extern int ccGlMap[40][40];
extern int ccUserTrankX;
extern int ccUserTrankY;


extern int ccUserTrank1;
extern int ccUserTrank2;

extern bool ccOver;
//////////////////////////////////////
extern int ccUserTrank1life1;
extern int ccUserTrank2life2;
//////////////////////////////////////
extern int CCEnemyTranklife;
extern int CCEnemyTranklife2;

extern int num;