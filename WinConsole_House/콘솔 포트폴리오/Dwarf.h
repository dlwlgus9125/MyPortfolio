#pragma once
#include "CharacterData.h"
#include "Constant.h"
#include <string>

using namespace std;

class Dwarf :
	public CharacterData
{
protected:
	float m_mining;
	float m_lumberjacking;
	float m_hunting;

public:
	Dwarf(string race, CHARACTER_TAG tag, int id, float life, float attack, float defense, float actionPoint, float mining, float lumberjacking, float hunting)
	{
		this->m_race = race;
		this->m_tag = tag;
		this->m_id = id;
		this->m_life = life;
		this->m_attack = attack;
		this->m_defense = defense;
		this->m_actionPoint = actionPoint;
		this->m_mining = mining;
		this->m_lumberjacking = lumberjacking;
		this->m_hunting = hunting;
	}
	virtual ~Dwarf(){};

	float GetMining(){ return m_mining; }
	float GetLumberjacking(){ return m_lumberjacking; }
	float GetHunting(){ return m_hunting; }
};

