#include "RenderMgr.h"


RenderMgr::RenderMgr()
{
}


RenderMgr::~RenderMgr()
{
}

RenderMgr* RenderMgr::Instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new RenderMgr;
	}
	return m_pInstance;
}


void RenderMgr::Draw(string text, int endLineCount)
{
	cout << text;
	EndLine(endLineCount);
}

void RenderMgr::Draw(string text, POS pos, int endLineCount)
{
	SetCursorPosition(pos.x, pos.y);
	Draw(text, endLineCount);
}

void RenderMgr::EndLine(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << endl;
	}
}

void RenderMgr::Erase(int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << ' ';
	}
}

void RenderMgr::Erase(int length, POS pos)
{
	SetCursorPosition(pos.x, pos.y);
	Erase(length);
}

void RenderMgr::SetCursorPosition(int x, int y)
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void RenderMgr::SetColor(CONSOLE_COLOR fontColor, CONSOLE_COLOR bgColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, bgColor << 4 | fontColor);
}

