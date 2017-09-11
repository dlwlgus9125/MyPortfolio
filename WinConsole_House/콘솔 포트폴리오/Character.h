#pragma once
#include "Math.h"
#include "Map.h"
#include "RenderMgr.h"
#include "CharacterDB.h"
#include "ItemInventory.h"

class Character
{
protected:
	CharacterData* m_pData;
	float m_life;
	float m_attack;
	float m_defense;
	float m_actionpoint;
	POS m_position;
	int m_checker;

public:
	Character(CharacterData* pData)
	{
		m_pData=pData;
		m_life = m_pData->m_life;
		m_attack = m_pData->m_attack;
		m_defense = m_pData->m_defense;
		m_actionpoint = m_pData->m_actionpoint;
		m_position = POS(0, 0);;
	};
	~Character(){};


	CharacterData* GetData() { return m_pData; }
	CHARACTER_TAG GetTag() { return m_pData->m_tag; }

	int       GetChecker(){ return m_checker; }
	void      SetChecker(int checker){ m_checker = checker; }

	POS GetPosition() { return m_position; }
	string GetRace() { return m_pData->m_race; }
	RACE_TYPE GetType(){ return m_pData->m_type; }
	float GetLife() { return m_life; }
	float GetLifeMax() { return m_pData->m_life; }
	float GetAttack() { return m_pData->m_attack; }
	float GetAttackMax() { return m_attack; }
	float GetDefense() { return m_pData->m_defense; }
	float GetDefenseMax() { return m_defense; }
	float GetActionPoint(){ return m_actionpoint; }
	float GetActionPointMax(){ return m_pData->m_actionpoint; }
	void UpdateLife(float life);
	void Attack(Character* pTarget, int scene);
	void SetPosition(POS pos) { m_position.x = pos.x; m_position.y = pos.y; }
	void SetAttack(float attack){ m_pData->m_attack = attack; }
	void SetDefense(float defense){ m_defense = defense; }
	void SetAction(int action)
	{
		m_actionpoint += action;
		m_actionpoint = Math::Clamp(m_actionpoint, 0.0f, 10.0f);
	}
	virtual bool IsCollided(Character* target)
	{
		POS pos = target->GetPosition();
		return m_position.x == pos.x && m_position.y == pos.y;
	}

	void AddLife(float life)
	{
		m_life = Math::Clamp(m_life + life, 0.0f, GetLifeMax());
	}



	virtual void SetPlayer(int a){};
	virtual string GetName(){ return NULL; };
	virtual float GetLumberjacking(){ return NULL; };
	virtual float GetHunting(){ return NULL; };
	virtual float GetMining(){ return NULL; };
	virtual HOUSE_TAG GetHouseTag(){ return HOUSE_NONE; };
	virtual void SetHouse(HOUSE_TAG tag){}
	virtual void ShowPlayer(){};
	virtual void DrawCharacter(int Scene){};
	virtual void RemoveDrawCharacter(int Scene){};
	virtual ItemInventory* Inventory() { return NULL; }
	virtual ItemInventory* Storage() { return NULL; }
	virtual ItemData* getWeapon(){ return NULL; }
	virtual ItemData* getCloth(){ return NULL; }
	virtual ItemData* getGlove(){ return NULL; }
	virtual bool equipItem(ITEM_TYPE type, ITEM_TAG tag){ return NULL; };
	virtual bool unEquipItem(int index){ return NULL; };
	virtual void Swing(){};
	virtual HEAD_SEE GetSee(){ return SEE_NONE; }
	virtual void SetSee(HEAD_SEE see){}
	virtual void SetLife(int index){}
	virtual void UpdateEquip(){}
	virtual void Eat(ITEM_TAG tag){}
	virtual int SetBonusResource(Character* pPlayer, CHARACTER_TAG tag){ return NULL; }
	virtual void CheckingCreateItem(ITEM_TAG tag, int WOOD, int ROCK, int STONE){};
	virtual void LackResource(){};
	virtual void LackInventory(){};
	virtual void LackStorage(){};
};

