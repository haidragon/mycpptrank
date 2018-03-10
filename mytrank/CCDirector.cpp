#include "CCDirector.h"
#include "CCAstar.h"
#include<stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h> 

int ccUserTrankX;
int ccUserTrankY;
int n = 0;
int ccGlMap[40][40] = { 0 };
extern int ccUserTrank1;
extern int ccUserTrank2;
//////////////////////////////////////
extern int ccUserTrank1life1=100;
extern int ccUserTrank2life2=100;
//////////////////////////////////////
extern int CCEnemyTranklife=20;
extern int CCEnemyTranklife2 = 20;
extern bool ccOver = false;

extern int num = 0;
void CCDirector::ccStartAnimation() {
	int a = 0;
	printf(" %s\n", "请选择模式");
	printf("1 %s\n", "电脑模式");
	printf("2 %s\n", "在原来地图基础上自定义模式(右键单击画障碍物，单击同时拖动画草）");
	scanf_s("%d", &a);
	//先选择
	switch (a)
	{
	case 1:
		//电脑初始化
		ccInitMap();
		//再画
		ccDrawMap();
		//开始
		ccStart();
		break;
	case 2:
		//手动初始化
		ccDraw();
		break;
	default:
		break;
	}
}


CCDirector::CCDirector()
{
	
	ccSetWindowInfo("Tank", 100, 45);
}


CCDirector::~CCDirector()
{
}

bool CCDirector::ccInitMap() {
	for (int i = 0; i <MAPWIDE; i++) {
		for (int j = 0; j < MAPLONG; j++) {
			if (i == 20 && j == 38) {
				ccGlMap[i][j] = HOMEMAP;
				continue;
			}
			if ((i > 18 && i <22) && j>35 && j<MAPLONG - 1) {
				ccGlMap[i][j] = ZHANGAIMAP2;
				continue;
			}
			
			if (i == 0 || i == MAPLONG - 1 ||
				j == 0 || j == MAPWIDE - 1) {
				ccGlMap[i][j] = QANGMAP;
				continue;
			}
			else
			{
				ccGlMap[i][j] = KONGMAP;

			}
		}
	}
	//生成草
	for (int i = 10; i < 30; i++) {
		for (int j = 7; j< 10; j++) {
			ccGlMap[i][j] = CAOMAP;
		}

	}
	for (int i = 10; i < 30; i++)
	{
		for (int j = 23;j < 25;j++) {
			ccGlMap[i][j] = ZHANGAIMAP;
		}
			
		
	}
	return true;
}
bool CCDirector::ccDrawMap() {
	ccDrawChar(0, 0, " ", 0x44);
	//printf("﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍|\n");
	for (int i = 0; i < MAPWIDE; i++) {
		for (int j = 0; j < MAPLONG; j++) {
			if (ccGlMap[i][j] == QANGMAP)
				ccDrawChar(i, j, "∷", 0x9);
			if (ccGlMap[i][j] == USERTANKMAP)
				ccDrawChar(i, j, USERTANK, 0x5);
			if (ccGlMap[i][j] == KONGMAP)
				ccDrawChar(i, j, " ", 0x0);
			if (ccGlMap[i][j] == HOMEQANGMAP)
				ccDrawChar(i, j, "■", 0x2);
			if (ccGlMap[i][j] == CAOMAP)
				ccDrawChar(i, j, CAO, 0x2);
			if (ccGlMap[i][j] == ZHANGAIMAP)
				ccDrawChar(i, j, ZHANGAI, 0xf);
			if (ccGlMap[i][j] == ZHANGAIMAP2)
				ccDrawChar(i, j, ZHANGAI2, 0x2);
			if (ccGlMap[i][j] == HOMEMAP) {
					ccDrawChar(i, j, "∧", 0xa);
				
			}

		}

	}
	//printf("﹍﹍﹍﹍﹍﹍﹍﹍﹍﹍|\n");
	return true;
}
bool CCDirector::ccSetWindowInfo(char* pTitle, int nWid, int nHeight) {
	//设置窗口标题
	SetConsoleTitleA(pTitle);
	// 设置窗口大小
	// 因为屏幕大小不能比缓冲区大，所以先把缓冲区大小设置为足够大
	// 先获取当前屏幕的最大值
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd = GetLargestConsoleWindowSize(hOut);
	// 设置缓冲区最大值
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("设置窗口缓冲区大小失败1！\n");
		return false;
	}
	// 按要求设置窗口大小
	SMALL_RECT sr = { 0,0,nWid - 1,nHeight - 1 };
	if (!SetConsoleWindowInfo(hOut, 1, &sr)) {
		printf("设置窗口大小失败！\n");
		return false;
	}
	// 重新设置缓冲区大小
	cd.X = nWid;
	cd.Y = nHeight;
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("设置窗口缓冲区大小失败2！\n");
		return false;
	}
	return true;
}
bool CCDirector::ccDrawChar(int x, int y, char* pszChar, WORD wAttr) {
	// 设置光标位置
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(hOut, pos);
	// 隐藏光标
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = false;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// 设置打印符号的前景色背景色
	SetConsoleTextAttribute(hOut, wAttr);
	printf("%s", pszChar);
	return true;
}
bool CCDirector::ccgrade() {
	// 设置光标位置
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 42 * 2,5 };
	SetConsoleCursorPosition(hOut, pos);
	// 隐藏光标
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = false;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// 设置打印符号的前景色背景色
	SetConsoleTextAttribute(hOut, 0x9);
	printf("%s", "当 前 分 数:");
	printf("%d", num*10);
	COORD pos2 = { 42 * 2,10 };
	SetConsoleCursorPosition(hOut, pos2);
	//printf("%s", "坦 克 血 量:");
	//printf("%d", ccUserTrank1life1);



	COORD pos3 = { 3* 2,41 };
	SetConsoleCursorPosition(hOut, pos3);
	printf("%s", "按键：E(发射子弹) W（上）S(下) A(左）D（右）Q（退出）所有按键不分大小写");

	return true;
}

void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr) {
	// 设置光标位置
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { nPosX * 2,nPosY };
	SetConsoleCursorPosition(hOut, pos);
	// 隐藏光标
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// 设置打印符号的前景色背景色
	SetConsoleTextAttribute(hOut, wAttr);
	// 输出你想输出的
	printf("%s", psz);
}

//用来输出坐标
void OutputPos(int nX, int nY) {
	char szBuf[100] = { 10 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d   ", nX, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(szBuf, 0, 0, 0x50);
}



//指定位置
void gotoxy(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
	HANDLE    hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleTextAttribute(hConsoleOut, 0x3);
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}



void MouseEventProc(MOUSE_EVENT_RECORD mer) {

	//如果点击左键画墙
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		int x = mer.dwMousePosition.X;
		int y = mer.dwMousePosition.Y;


		OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);

		if ((x >80 && x<88) && y == 10) {

			//初始化
			//CCDirector::ccInitMap();
			gotoxy(82, 10);
			printf("       ");

			//再画
			CCDirector::ccDrawMap();
			CCDirector::ccStart();
			
		}
		if (x <78 && y < 33 && x >2 && y >2) {
			WriteChar(ZHANGAI, (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0xff);
			ccGlMap[(mer.dwMousePosition.X) / 2][mer.dwMousePosition.Y] = ZHANGAIMAP;
		}
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
			if (mer.dwMousePosition.X < 78 && mer.dwMousePosition.Y < 38 && mer.dwMousePosition.X >2 && mer.dwMousePosition.Y >2) {
				WriteChar(CAO, (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x2);
				ccGlMap[x / 2][y] = CAOMAP;
			}
		}
	}
	else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
		//WriteChar("右单击", (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x6);
	}

}


bool CCDirector::ccDraw() {
	CCDirector::ccInitMap();
	CCDirector::ccDrawMap();

	gotoxy(82, 10);
	printf("点击开始");
	//获取一个句柄
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//声明一个输入结构体
	INPUT_RECORD stcRcord = { 0 };

	DWORD dwRead;
	//设置控制台模式输入输出
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1)
	{
		ReadConsoleInput(hStdin, &stcRcord, 1, &dwRead);
		if (stcRcord.EventType == KEY_EVENT) {

		}
		else if (stcRcord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRcord.Event.MouseEvent);
		}
	}
}



 bool CCDirector::ccStart() {
	 //CCTrank(int, int, int life = 20, int dir = TANK_DIR_UP, int ccSpeed = 1, char color = 0x3);
	
////////////////////////////////////////////////////////////////////////////////////	 
	 //用户坦克
	 CCUserTrank* ccTrank = new CCUserTrank(17, 37, 100, TANK_DIR_UP, 1, 0xa);
	 ccUserTrankX = ccTrank->x;
	 ccUserTrankY = ccTrank->y;
	 ccTrank->ccTirank = 1;
	 //打印出来
	 ccTrank->ccDrawObject(ccTrank->x, ccTrank->y, SPRITE, ccTrank->color);
	 //用户坦克
	 CCUserTrank* ccTrank2 = new CCUserTrank(23, 37, 100, TANK_DIR_UP, 1, 0xa);
	 ccTrank2->ccTirank = 1;
	 //打印出来
	 ccTrank2->ccDrawObject(ccTrank2->x, ccTrank2->y, SPRITE, ccTrank2->color);
 ////////////////////////////////////////////////////////////////////////////////////
	 //智能坦克
	 CCAutoTrank ccAutoTrank = CCAutoTrank(5, 33, 100, TANK_DIR_UP, 1, 0x5);
	 ccAutoTrank.ccTirank = 3;
 ////////////////////////////////////////////////////////////////////////////////////
	 //敌方坦克1
	 CCEnemyTrank ccEnemyTrank1 = CCEnemyTrank(2, 4, 2, TANK_DIR_DW, 1, 0x9);
	 CCEnemyTranklife = ccEnemyTrank1.ccGetLife();
	 ccEnemyTrank1.ccTirank = 2;
	 //敌方坦克2
	 CCEnemyTrank ccEnemyTrank2 = CCEnemyTrank(33, 4, 50, TANK_DIR_DW, 1, 0x9);
	 ccEnemyTrank2.ccTirank = 2;
	 CCEnemyTranklife2 = ccEnemyTrank2.ccGetLife();

////////////////////////////////////////////////////////////////////////////////////
	 clock_t tBegin1 = clock(), tBegin2 = clock(), tBegin3 = clock(), tBegin4 = clock(), tEnd1 = 0, tEnd2 = 0, tEnd3 = 0, tEnd4 = 0;
	
	 
	 
	 srand(time(NULL));//设置随机数种子	
	 char enemych = 'w';
	 char enemych1 = 's';
	 while (1)
	 {

		 if (ccOver) {
			 MessageBox(0, "GG", 0, 0);
			 break;
		 }


		 int temp = rand() % 4;
		 if (temp == 0) enemych = 'a', enemych1 = 's';
		 if (temp == 1) enemych = 'w', enemych1 = 'd';
		 if (temp == 2) enemych = 's', enemych1 = 'w';
		 if (temp == 3) enemych = 'd', enemych1 = 'a';
		 if (_kbhit())
		 {
			  char ch = _getch();
			  if (ch == 'a' || ch == 'A' || ch =='s'|| ch == 'S'|| ch == 'W' || ch == 'w' || ch == 'd' || ch == 'D'|| ch == 'e' || ch == 'E') {
				 ccTrank->ccChargeDir(ch);
			 }
			 else {
				 ccTrank2->ccChargeDir(ch);
			 }
			 

		 }

		 tEnd1 = clock();
		 tEnd2 = clock();
		 tEnd3 = clock();
		 tEnd4 = clock();
		 if (tEnd1 - tBegin1 > 50)
		 {

			 //用户坦克的子弹
			 ccTrank->ccMoveTrankBullet();
			 ccTrank2->ccMoveTrankBullet();
			 tBegin1 = tEnd1;
		 }
		 if (tEnd2 - tBegin2 > 100)
		 {
			 //智能坦克
			 ccAutoTrank.ccSpriteMove();

			 //坦克1
			 ccEnemyTrank1.life = CCEnemyTranklife;

			 CCEnemyTranklife = ccEnemyTrank1.life;
			 ccEnemyTrank1.ccSpriteMove();

			 //坦克2
			 if (CCEnemyTranklife <= 0) {
				 ccEnemyTrank2.life = CCEnemyTranklife2;
				 CCEnemyTranklife2 = ccEnemyTrank2.life;
				 ccEnemyTrank2.ccSpriteMove();
			 }
			 tBegin2 = tEnd2;
		 }
		 if (tEnd3 - tBegin3 > 200) {

			 ///坦克1
			 ccEnemyTrank1.life = CCEnemyTranklife;
			 ccEnemyTrank1.ccChargeDir(enemych);
			 //坦克2
			 if (CCEnemyTranklife <= 0) {
				 ccEnemyTrank2.life = CCEnemyTranklife2;
				 CCEnemyTranklife2 = ccEnemyTrank2.life;
				 ccEnemyTrank2.ccChargeDir(enemych1);
			 }
			 tBegin3 = tEnd3;
		 }

		 CCDirector::ccgrade();
	 }
	 return true;
}