#pragma once
#include "RenderMgr.h"


class Map
{
	string* m_pArray;
	int m_startX;
	int m_startY;
	int m_width;
	int m_height;
	string m_default;

public:
	Map(int startX, int startY, int width, int height, string default)
	{
		m_pArray = new string[width* height];
		m_startX = startX;
		m_startY = startY;
		m_width = width;
		m_height = height;
		m_default = default;
	}

	~Map()
	{
		delete m_pArray;
	}

	int Width(){ return m_width; }
	int Height(){ return m_height; }

	void Reset()
	{
		int count = m_width * m_height;
		for (int i = 0; i < count; i++)
		{
			m_pArray[i] = m_default;
		}
	}

	void Add(int x, int y, string obj)
	{
		int index = x + y * m_width;
		m_pArray[index] = obj;
	}

	void Draw()
	{
		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{
				int index = x + y * m_width;
				RenderMgr::SetCursorPosition(m_startX + x * 2, m_startY + y);
				RenderMgr::Draw(m_pArray[index]);
			}
		}
	}



};