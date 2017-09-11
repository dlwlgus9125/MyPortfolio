#pragma once
#include <string>
#include "ArrayList.h"
#include "Constant.h"

using namespace std;


struct CharacterData
{
	string m_race;
	CHARACTER_TAG m_tag;
	RACE_TYPE m_type;
	int m_id;
	float m_life;
	float m_attack;
	float m_defense;
	float m_actionpoint;

	CharacterData(string race, CHARACTER_TAG tag, RACE_TYPE type, int id, float life, float attack, float defense, float actionpoint)
	{
		this->m_race = race;
		this->m_tag = tag;
		this->m_type = type;
		this->m_id = id;
		this->m_life = life;
		this->m_attack = attack;
		this->m_defense = defense;
		this->m_actionpoint = actionpoint;
	}
};


class CharacterDB
{
	static CharacterDB* m_pInstance;
	ArrayList<CharacterData*> m_dataList;

	CharacterDB();
	~CharacterDB();
public:
	
	static CharacterDB* Instance();

	void Initialize();

	void Add(CharacterData* data);

	static CharacterData* GetData(CHARACTER_TAG tag);
};

