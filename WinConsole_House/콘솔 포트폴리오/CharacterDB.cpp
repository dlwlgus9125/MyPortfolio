#include "CharacterDB.h"


CharacterDB::CharacterDB()
{
}


CharacterDB::~CharacterDB()
{
}


CharacterDB* CharacterDB::Instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CharacterDB;
		m_pInstance->Initialize();
	}
	return m_pInstance;
}

void CharacterDB::Initialize()
{
	Add(new CharacterData("ÀÎ°£", HUMAN, RACE_PLAYER, 1001, 10, 3, 0, 10));
	Add(new CharacterData("¿äÁ¤", ELF, RACE_PLAYER, 1002, 7, 5, 0, 10));
	Add(new CharacterData("³­ÀïÀÌ", DWARF, RACE_PLAYER, 1003, 15, 2, 1, 10));

	Add(new CharacterData("Åä³¢", RABBIT, RACE_MONSTER, 2001, 5, 2, 1, 10));
	Add(new CharacterData("¸äµÅÁö", BOAR, RACE_MONSTER, 2002, 10, 4, 2, 10));
	Add(new CharacterData("È²¼Ò", BULL, RACE_MONSTER, 2003, 15, 7, 4, 10));

	Add(new CharacterData("³ª¹«", WOOD, RACE_RESOURCE, 3001, 10, 0.0f, 0.0f, 0.0f));
	Add(new CharacterData("¹ÙÀ§", STONE, RACE_RESOURCE, 3002, 10, 0.0f, 0.0f, 0.0f));
}

void CharacterDB::Add(CharacterData* data)
{
	if (GetData(data->m_tag) != NULL) return;
	m_dataList.Add(data);
}

CharacterData* CharacterDB::GetData(CHARACTER_TAG tag)
{
	for (int i = 0; i < Instance()->m_dataList.Count(); i++)
	{
		CharacterData* pData = Instance()->m_dataList.GetData(i);
		if (pData->m_tag == tag) return pData;
	}
	return NULL;
}