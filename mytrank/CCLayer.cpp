#include "CCLayer.h"



int CCLayer::ccGetX() {
	return x;
}

int CCLayer::ccGetY() {
	return y;
}
void CCLayer::ccSetX(int x) {
	this->x = x;
}
void CCLayer::ccSetY(int y) {
	this->y = y;
}
char CCLayer::ccGetcolor() {
	return color;
}
void CCLayer::ccSetcolor(char ch) {
	this->color = ch;
}
CCLayer::CCLayer()
{
}


CCLayer::~CCLayer()
{
}
bool CCLayer::ccDrawChar(int x, int y, char* pszChar, WORD wAttr) {
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