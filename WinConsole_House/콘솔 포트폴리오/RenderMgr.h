#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Constant.h"

using namespace std;

struct POS
{
	int x;
	int y;

	POS(){ x = 0; y = 0; }
	POS(int x, int y){ this->x = x; this->y = y; }
};


class RenderMgr
{
	static RenderMgr* m_pInstance;

	RenderMgr();
	~RenderMgr();
public:
	static RenderMgr* Instance();
	static void Draw(string text, int endLineCount = 0);
	static void Draw(string text, POS pos, int endLineCount = 0);
	static void EndLine(int count = 0);
	static void Erase(int length);
	static void Erase(int length, POS pos);
	static void SetCursorPosition(int x, int y);
	static void SetColor(CONSOLE_COLOR fontColor = COLOR_WHITE, CONSOLE_COLOR bgColor = COLOR_BLACK);

	static void ClearScreen(){ system("cls"); };
	static void PauseScreen(){ system("pause"); };


};

