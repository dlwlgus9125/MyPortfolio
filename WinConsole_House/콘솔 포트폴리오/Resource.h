#pragma once
#include "Character.h"
class Resource :
	public Character
{
protected:
	Character*       m_pResource;

public:
	Resource(CharacterData* pData) : Character(pData)
	{
		m_pResource = new Character(pData);
		m_position = POS(0, 0);
	}
	~Resource();


	void DrawCharacter(int scene)
	{


		if (scene == 0)RenderMgr::SetColor(COLOR_BLACK, COLOR_SKY);
		if (scene == 1)RenderMgr::SetColor(COLOR_BLACK, COLOR_DARK_YELLOW);

		if (m_pResource->GetTag() == WOOD)
		{
			RenderMgr::SetColor(COLOR_GREEN, COLOR_GREEN);
			RenderMgr::Draw(" ", POS(m_position.x + 2, m_position.y - 5), 1);
			RenderMgr::Draw("   ", POS(m_position.x +1, m_position.y - 4), 1);
			RenderMgr::Draw("     ", POS(m_position.x , m_position.y - 3), 1);
			RenderMgr::Draw("       ", POS(m_position.x -1, m_position.y - 2), 1);
			RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y - 1), 1);
			RenderMgr::SetColor(COLOR_DARK_RED, COLOR_DARK_RED);
			RenderMgr::Draw("    ", POS(m_position.x + 1, m_position.y), 1);
			RenderMgr::Draw("    ", POS(m_position.x + 1, m_position.y + 1), 1);
			RenderMgr::Draw("    ", POS(m_position.x + 1, m_position.y + 2), 1);
		}
		else if (m_pResource->GetTag() == STONE)
		{
			RenderMgr::SetColor(COLOR_GRAY, COLOR_SKY);
			RenderMgr::Draw("¦£¦¡¦¤", POS(m_position.x, m_position.y), 1);
			RenderMgr::Draw("¦¢µ¹¦¢", POS(m_position.x, m_position.y + 1), 1);
			RenderMgr::Draw("¦¦¦¡¦¥", POS(m_position.x, m_position.y + 2), 1);
		}
	}




	void RemoveDrawCharacter(int Scene)
	{
		if (Scene == 0)RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
		if (Scene == 1)RenderMgr::SetColor(COLOR_DARK_YELLOW, COLOR_DARK_YELLOW);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y - 5), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y - 4), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y - 3), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y - 2), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y - 1), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y + 1), 1);
		RenderMgr::Draw("         ", POS(m_position.x - 2, m_position.y + 2), 1);

	}


};
