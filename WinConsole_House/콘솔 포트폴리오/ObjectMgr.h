#pragma once
#include "ArrayList.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Resource.h"

class ObjectMgr
{
	static ObjectMgr*   m_pInstance;

	ArrayList<Character*>  m_monsters;
	ArrayList<Character*>  m_resources;
	Character*             m_pPlayer;

	ObjectMgr();
	~ObjectMgr();
public:
	static ObjectMgr* Instance();
	static Character* CreatePlayer(CharacterData* pData);
	static Character* CreateMonster(int x, int y, CharacterData* pData);
	static Character* CreateResource(int x, int y, CharacterData* pData);
	static void DestroyPlayer();
	static void DestroyMonster(Character* pMonster);
	static void DestroyResource(Character* pResource);
	static void DestroyAllMonster();
	static void DestroyAllResource();

	static Character* GetMonster(CHARACTER_TAG tag);
	static Character* GetResource(CHARACTER_TAG tag);
	static Character* GetPlayer() { return Instance()->m_pPlayer; };
	static ArrayList<Character*> GetMonsters() { return Instance()->m_monsters; };
	static ArrayList<Character*> GetResources() { return Instance()->m_resources; };

	
};

