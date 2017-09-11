#include "Character.h"







void Character::UpdateLife(float life)
{
	m_life = Math::Clamp(m_life + life, 0.0f, m_pData->m_life);
}


void Character::Attack(Character* pTarget, int scene)
{
	int length = 0;
	if (pTarget->GetType() == RACE_MONSTER)length = 4;
	char message[10] = {};
	float damage = Math::Max(0.0f, GetAttack() - pTarget->GetDefense());
	pTarget->AddLife(-damage);
	sprintf(message, "-%.f", damage);
	RenderMgr::Draw(message, POS(pTarget->m_position.x+length, pTarget->m_position.y - 3), 1);
	Sleep(1000);

	if (scene == 0)RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
	if (scene == 1)RenderMgr::SetColor(COLOR_DARK_YELLOW, COLOR_DARK_YELLOW);
	RenderMgr::Draw("      ", POS(pTarget->m_position.x + length, pTarget->m_position.y - 3), 1);
}