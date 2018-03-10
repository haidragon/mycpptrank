#pragma once
#include<list>
#include "CCAstar.h"
/////////////////////////////////////
//MAP中对应的整形值
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
//MAP中不同整形对应的输入字符
#define USERTANK "■"
#define SPRITE "■"
#define ZHANGAI  "■"
#define ZHANGAI2 "∷"
#define ENEMYTANK "■"//◎●※∷
#define USERBULLET "◎"
#define ENEMYBULLET "●"
#define HOME "∷"
#define CAO "※"
#define KONG " "
//////////////////////////////////
//不同方向对应不同的字符
#define TANK_DIR_UP 0
#define TANK_DIR_DW 1
#define TANK_DIR_LF 2
#define TANK_DIR_RH 3
#define TANKUP "∧"
#define TANKDW "∨"
#define TANKLF "＜"
#define TANKRH "＞"
//全局地图数组
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