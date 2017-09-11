#pragma once
#include <string>
#include "ArrayList.h"
#include "RenderMgr.h"
#include "Key.h"
#include "Math.h"

using namespace std;

class Menu
{
	ArrayList<string> m_list;
	POS m_pos;
	int m_cursor;
	int m_count;
	CONSOLE_COLOR m_fontColor;
	CONSOLE_COLOR m_bgColor;
	CONSOLE_COLOR m_selectedFontColor;
	CONSOLE_COLOR m_selectedBgColor;

	void Clear()
	{
		for (int i = 0; i < m_list.Count(); i++)
		{
			RenderMgr::SetCursorPosition(m_pos.x, m_pos.y + i);
			RenderMgr::SetColor(COLOR_WHITE, COLOR_BLACK);
			RenderMgr::Erase(m_list.GetData(i).length());
		}
	}

	void Draw()
	{
		for (int i = 0; i < m_list.Count(); i++)
		{
			CONSOLE_COLOR fontColor = (m_cursor == i) ? m_selectedFontColor : m_fontColor;
			CONSOLE_COLOR bgColor = (m_cursor == i) ? m_selectedBgColor : m_bgColor;

			RenderMgr::SetCursorPosition(m_pos.x, m_pos.y+i);
			RenderMgr::SetColor(fontColor, bgColor);
			RenderMgr::Draw(m_list.GetData(i));
		}
	}

	bool MoveCursor()
	{
		switch (Key::GetArrow())
		{
		case Key::UP: m_cursor--; break;
		case Key::DOWN: m_cursor++; break;
		case Key::ENTER: return true; break;
		}

		m_cursor = Math::Clamp(m_cursor, 0, m_list.Count() - 1);
		return false;
	}

public:
	Menu(POS pos)
	{
		m_pos               = pos;
		m_cursor            = 0;
		m_fontColor         = COLOR_WHITE;
		m_bgColor           = COLOR_BLACK;
		m_selectedFontColor = COLOR_BLACK;
		m_selectedBgColor   = COLOR_WHITE;
		m_count = 0;
	}

	void SetDefaultColor(CONSOLE_COLOR fontColor, CONSOLE_COLOR bgColor)
	{
		m_fontColor = fontColor;
		m_bgColor = bgColor;
	}

	void SetSelectedColor(CONSOLE_COLOR fontColor, CONSOLE_COLOR bgColor)
	{
		m_selectedFontColor = fontColor;
		m_selectedBgColor = bgColor;
	}

	void Add(string text)
	{
		m_list.Add(text);
		m_count++;
	}

	int Update()
	{
		while (true)
		{
			Clear();
			Draw();
			if (MoveCursor()) break;
		}
		Clear();

		return m_cursor;
	}

	void RemoveMenu(int length)
	{
		RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
		for (int i = 0; i < length+2; i++)
		{
			RenderMgr::Draw("                                    ", POS(23, 9 + i), 1);
		}
	}

	int GetCount(){	return m_count;	}


};