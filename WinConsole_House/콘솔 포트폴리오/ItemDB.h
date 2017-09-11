#pragma once
#include <string>
#include "ArrayList.h"
#include "Constant.h"

using namespace std;

struct ItemData
{
	int id;
	ITEM_TAG tag;
	ITEM_TYPE type;
	string name;
	string emoticon;
	float increaseAttack;
	float increaseDefense;
	float RecoveryActionPoint;

	ItemData(int id, ITEM_TYPE type, ITEM_TAG tag, string name, string emoticon, float increaseAttack, float increaseDefense, float RecoveryActionPoint)
	{
		this->id = id;
		this->tag = tag;
		this->name = name;
		this->emoticon = emoticon;
		this->type = type;
		this->increaseAttack = increaseAttack;
		this->increaseDefense = increaseDefense;
		this->RecoveryActionPoint = RecoveryActionPoint;
	}
};

class ItemDB
{
	static ItemDB* m_pInstance;
	ArrayList<ItemData*> m_list;

	ItemDB();
	~ItemDB();
public:
	static ItemDB* Instance();

	void Initialize();

	void Add(ItemData* pData);

	ItemData* GetDataByID(int id);

	ItemData* GetDataByTag(ITEM_TAG tag);
};

