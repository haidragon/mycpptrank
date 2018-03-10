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
	printf(" %s\n", "��ѡ��ģʽ");
	printf("1 %s\n", "����ģʽ");
	printf("2 %s\n", "��ԭ����ͼ�������Զ���ģʽ(�Ҽ��������ϰ������ͬʱ�϶����ݣ�");
	scanf_s("%d", &a);
	//��ѡ��
	switch (a)
	{
	case 1:
		//���Գ�ʼ��
		ccInitMap();
		//�ٻ�
		ccDrawMap();
		//��ʼ
		ccStart();
		break;
	case 2:
		//�ֶ���ʼ��
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
	//���ɲ�
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
	//printf("�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l|\n");
	for (int i = 0; i < MAPWIDE; i++) {
		for (int j = 0; j < MAPLONG; j++) {
			if (ccGlMap[i][j] == QANGMAP)
				ccDrawChar(i, j, "��", 0x9);
			if (ccGlMap[i][j] == USERTANKMAP)
				ccDrawChar(i, j, USERTANK, 0x5);
			if (ccGlMap[i][j] == KONGMAP)
				ccDrawChar(i, j, " ", 0x0);
			if (ccGlMap[i][j] == HOMEQANGMAP)
				ccDrawChar(i, j, "��", 0x2);
			if (ccGlMap[i][j] == CAOMAP)
				ccDrawChar(i, j, CAO, 0x2);
			if (ccGlMap[i][j] == ZHANGAIMAP)
				ccDrawChar(i, j, ZHANGAI, 0xf);
			if (ccGlMap[i][j] == ZHANGAIMAP2)
				ccDrawChar(i, j, ZHANGAI2, 0x2);
			if (ccGlMap[i][j] == HOMEMAP) {
					ccDrawChar(i, j, "��", 0xa);
				
			}

		}

	}
	//printf("�l�l�l�l�l�l�l�l�l�l|\n");
	return true;
}
bool CCDirector::ccSetWindowInfo(char* pTitle, int nWid, int nHeight) {
	//���ô��ڱ���
	SetConsoleTitleA(pTitle);
	// ���ô��ڴ�С
	// ��Ϊ��Ļ��С���ܱȻ������������Ȱѻ�������С����Ϊ�㹻��
	// �Ȼ�ȡ��ǰ��Ļ�����ֵ
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd = GetLargestConsoleWindowSize(hOut);
	// ���û��������ֵ
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("���ô��ڻ�������Сʧ��1��\n");
		return false;
	}
	// ��Ҫ�����ô��ڴ�С
	SMALL_RECT sr = { 0,0,nWid - 1,nHeight - 1 };
	if (!SetConsoleWindowInfo(hOut, 1, &sr)) {
		printf("���ô��ڴ�Сʧ�ܣ�\n");
		return false;
	}
	// �������û�������С
	cd.X = nWid;
	cd.Y = nHeight;
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("���ô��ڻ�������Сʧ��2��\n");
		return false;
	}
	return true;
}
bool CCDirector::ccDrawChar(int x, int y, char* pszChar, WORD wAttr) {
	// ���ù��λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(hOut, pos);
	// ���ع��
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = false;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// ���ô�ӡ���ŵ�ǰ��ɫ����ɫ
	SetConsoleTextAttribute(hOut, wAttr);
	printf("%s", pszChar);
	return true;
}
bool CCDirector::ccgrade() {
	// ���ù��λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 42 * 2,5 };
	SetConsoleCursorPosition(hOut, pos);
	// ���ع��
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = false;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// ���ô�ӡ���ŵ�ǰ��ɫ����ɫ
	SetConsoleTextAttribute(hOut, 0x9);
	printf("%s", "�� ǰ �� ��:");
	printf("%d", num*10);
	COORD pos2 = { 42 * 2,10 };
	SetConsoleCursorPosition(hOut, pos2);
	//printf("%s", "̹ �� Ѫ ��:");
	//printf("%d", ccUserTrank1life1);



	COORD pos3 = { 3* 2,41 };
	SetConsoleCursorPosition(hOut, pos3);
	printf("%s", "������E(�����ӵ�) W���ϣ�S(��) A(��D���ң�Q���˳������а������ִ�Сд");

	return true;
}

void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr) {
	// ���ù��λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { nPosX * 2,nPosY };
	SetConsoleCursorPosition(hOut, pos);
	// ���ع��
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// ���ô�ӡ���ŵ�ǰ��ɫ����ɫ
	SetConsoleTextAttribute(hOut, wAttr);
	// ������������
	printf("%s", psz);
}

//�����������
void OutputPos(int nX, int nY) {
	char szBuf[100] = { 10 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d   ", nX, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(szBuf, 0, 0, 0x50);
}



//ָ��λ��
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

	//�����������ǽ
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		int x = mer.dwMousePosition.X;
		int y = mer.dwMousePosition.Y;


		OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);

		if ((x >80 && x<88) && y == 10) {

			//��ʼ��
			//CCDirector::ccInitMap();
			gotoxy(82, 10);
			printf("       ");

			//�ٻ�
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
		//WriteChar("�ҵ���", (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x6);
	}

}


bool CCDirector::ccDraw() {
	CCDirector::ccInitMap();
	CCDirector::ccDrawMap();

	gotoxy(82, 10);
	printf("�����ʼ");
	//��ȡһ�����
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//����һ������ṹ��
	INPUT_RECORD stcRcord = { 0 };

	DWORD dwRead;
	//���ÿ���̨ģʽ�������
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
	 //�û�̹��
	 CCUserTrank* ccTrank = new CCUserTrank(17, 37, 100, TANK_DIR_UP, 1, 0xa);
	 ccUserTrankX = ccTrank->x;
	 ccUserTrankY = ccTrank->y;
	 ccTrank->ccTirank = 1;
	 //��ӡ����
	 ccTrank->ccDrawObject(ccTrank->x, ccTrank->y, SPRITE, ccTrank->color);
	 //�û�̹��
	 CCUserTrank* ccTrank2 = new CCUserTrank(23, 37, 100, TANK_DIR_UP, 1, 0xa);
	 ccTrank2->ccTirank = 1;
	 //��ӡ����
	 ccTrank2->ccDrawObject(ccTrank2->x, ccTrank2->y, SPRITE, ccTrank2->color);
 ////////////////////////////////////////////////////////////////////////////////////
	 //����̹��
	 CCAutoTrank ccAutoTrank = CCAutoTrank(5, 33, 100, TANK_DIR_UP, 1, 0x5);
	 ccAutoTrank.ccTirank = 3;
 ////////////////////////////////////////////////////////////////////////////////////
	 //�з�̹��1
	 CCEnemyTrank ccEnemyTrank1 = CCEnemyTrank(2, 4, 2, TANK_DIR_DW, 1, 0x9);
	 CCEnemyTranklife = ccEnemyTrank1.ccGetLife();
	 ccEnemyTrank1.ccTirank = 2;
	 //�з�̹��2
	 CCEnemyTrank ccEnemyTrank2 = CCEnemyTrank(33, 4, 50, TANK_DIR_DW, 1, 0x9);
	 ccEnemyTrank2.ccTirank = 2;
	 CCEnemyTranklife2 = ccEnemyTrank2.ccGetLife();

////////////////////////////////////////////////////////////////////////////////////
	 clock_t tBegin1 = clock(), tBegin2 = clock(), tBegin3 = clock(), tBegin4 = clock(), tEnd1 = 0, tEnd2 = 0, tEnd3 = 0, tEnd4 = 0;
	
	 
	 
	 srand(time(NULL));//�������������	
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

			 //�û�̹�˵��ӵ�
			 ccTrank->ccMoveTrankBullet();
			 ccTrank2->ccMoveTrankBullet();
			 tBegin1 = tEnd1;
		 }
		 if (tEnd2 - tBegin2 > 100)
		 {
			 //����̹��
			 ccAutoTrank.ccSpriteMove();

			 //̹��1
			 ccEnemyTrank1.life = CCEnemyTranklife;

			 CCEnemyTranklife = ccEnemyTrank1.life;
			 ccEnemyTrank1.ccSpriteMove();

			 //̹��2
			 if (CCEnemyTranklife <= 0) {
				 ccEnemyTrank2.life = CCEnemyTranklife2;
				 CCEnemyTranklife2 = ccEnemyTrank2.life;
				 ccEnemyTrank2.ccSpriteMove();
			 }
			 tBegin2 = tEnd2;
		 }
		 if (tEnd3 - tBegin3 > 200) {

			 ///̹��1
			 ccEnemyTrank1.life = CCEnemyTranklife;
			 ccEnemyTrank1.ccChargeDir(enemych);
			 //̹��2
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