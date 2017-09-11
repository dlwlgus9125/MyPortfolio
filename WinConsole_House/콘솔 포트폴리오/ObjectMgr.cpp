#include "ObjectMgr.h"


ObjectMgr::ObjectMgr()
{
	m_pPlayer = NULL;




}

ObjectMgr::~ObjectMgr()
{

}

ObjectMgr* ObjectMgr::Instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new ObjectMgr;
	}
	return m_pInstance;
}

Character* ObjectMgr::CreatePlayer(CharacterData* pData)
{
	DestroyPlayer();
	Instance()->m_pPlayer = new Player(pData);
	Instance()->m_pPlayer->SetChecker(0);
	return Instance()->m_pPlayer;
}

void ObjectMgr::DestroyPlayer()
{
	if (Instance()->m_pPlayer != NULL)
	{
		delete Instance()->m_pPlayer;
		Instance()->m_pPlayer = NULL;
	}
}

Character* ObjectMgr::CreateMonster(int x, int y, CharacterData* pData)
{
	Character* pMonster = new Monster(pData);
	pMonster->SetPosition(POS(x, y));
	Instance()->m_monsters.Add(pMonster);
	return pMonster;
}

void ObjectMgr::DestroyAllMonster()
{
	while (Instance()->m_monsters.Count() > 0)
	{
		delete Instance()->m_monsters.RemoveAt(0);
	}
}

void ObjectMgr::DestroyMonster(Character* pMonster)
{
	if (pMonster != NULL)
	{
		Instance()->m_monsters.Remove(pMonster);
		delete pMonster;
	}
}

Character* ObjectMgr::GetMonster(CHARACTER_TAG tag)
{
	ArrayList<Character*> list = Instance()->m_monsters;

	for (int i = 0; i < list.Count(); i++)
	{
		Character* pMonster = list.GetData(i);
		if (pMonster->GetTag() == tag) return pMonster;
	}
	return NULL;
}

Character* ObjectMgr::CreateResource(int x, int y, CharacterData* pData)
{
	Character* pResources = new Resource(pData);
	pResources->SetPosition(POS(x, y));
	Instance()->m_resources.Add(pResources);
	return pResources;
}

void  ObjectMgr::DestroyResource(Character* pResource)
{
	if (pResource != NULL)
	{
		Instance()->m_resources.Remove(pResource);
		delete pResource;
	}
}

void ObjectMgr::DestroyAllResource()
{
	while (Instance()->m_resources.Count() > 0)
	{
		delete Instance()->m_resources.RemoveAt(0);
	}
}

Character* ObjectMgr::GetResource(CHARACTER_TAG tag)
{
	ArrayList<Character*> list = Instance()->m_resources;

	for (int i = 0; i < list.Count(); i++)
	{
		Character* pResource = list.GetData(i);
		if (pResource->GetTag() == tag) return pResource;
	}
	return NULL;
}