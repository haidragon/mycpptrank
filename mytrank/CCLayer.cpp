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