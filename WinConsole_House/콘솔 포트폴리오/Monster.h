#pragma once
#include "Character.h"
class Monster :
	public Character
{
protected:
	Character*       m_pMonster;

public:
	Monster(CharacterData* pData) : Character(pData)
	{
		m_pMonster = new Character(pData);
		m_position = POS(0, 0);
	}
	~Monster();


	void DrawCharacter(int scene)
	{


		if (scene == 0)RenderMgr::SetColor(COLOR_BLACK, COLOR_SKY);
		if (scene == 1)RenderMgr::SetColor(COLOR_BLACK, COLOR_DARK_YELLOW);

		if (m_pMonster->GetTag() == RABBIT)
		{
			RenderMgr::Draw(" ¡ß¦¡¦¤ ", POS(m_position.x - 1, m_position.y + 1), 1);
			RenderMgr::Draw("¦¦¦¡¦¥ ", POS(m_position.x , m_position.y + 2), 1);
		}
		else if (m_pMonster->GetTag() == BOAR)
		{
			RenderMgr::Draw("¦¦¦£¦¡¦¤", POS(m_position.x - 2, m_position.y + 1), 1);
			RenderMgr::Draw(" ¦¦¦¡¦¥", POS(m_position.x - 1, m_position.y + 2), 1);
		}
		else if (m_pMonster->GetTag() == BULL)
		{
			RenderMgr::Draw("¦¦¦£¦¡¦¡¦¤", POS(m_position.x-4, m_position.y), 1);

			RenderMgr::Draw(" ¦¢¼Ò  ¦¢", POS(m_position.x - 3, m_position.y + 1), 1);
			RenderMgr::Draw("¦¦¦¡¦¡¦¥", POS(m_position.x - 2, m_position.y + 2), 1);
		}
	}




	void RemoveDrawCharacter(int Scene)
	{
		if (Scene == 0)RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
		if (Scene == 1)RenderMgr::SetColor(COLOR_DARK_YELLOW, COLOR_DARK_YELLOW);

		RenderMgr::Draw("          ", POS(m_position.x, m_position.y), 1);
		RenderMgr::Draw("          ", POS(m_position.x + 1, m_position.y + 1), 1);
		RenderMgr::Draw("          ", POS(m_position.x + 1, m_position.y + 2), 1);

	}


};

