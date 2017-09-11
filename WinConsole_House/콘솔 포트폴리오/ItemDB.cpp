#include "ItemDB.h"


ItemDB::ItemDB()
{
}


ItemDB::~ItemDB()
{
}


ItemDB* ItemDB::Instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new ItemDB;
		m_pInstance->Initialize();
	}
	return m_pInstance;
}

void ItemDB::Initialize()
{
	ItemDB::Instance()->Add(new ItemData(1000, ITEMTYPE_NONE, ITEM_NONE, "", "��", 0, 0, 0));

	ItemDB::Instance()->Add(new ItemData(1001, ITEMTYPE_WEAPON, ITEM_PICKAXE, "���","��", 10, 0, 0));
	ItemDB::Instance()->Add(new ItemData(1002, ITEMTYPE_WEAPON, ITEM_AXE, "����", "��", 20, 0, 0));

	ItemDB::Instance()->Add(new ItemData(2001, ITEMTYPE_ARMOR, ITEM_CLOTH, "��", "��", 0, 10, 0));
	ItemDB::Instance()->Add(new ItemData(2002, ITEMTYPE_GLOVES, ITEM_GLOVES, "�尩", "��", 0, 5, 0));

	ItemDB::Instance()->Add(new ItemData(3001, ITEMTYPE_FOOD, ITEM_MEAT, "���", "��", 0, 0, 20));
	ItemDB::Instance()->Add(new ItemData(3002, ITEMTYPE_FOOD, ITEM_APPLE, "���", "��", 0, 0, 20));

	ItemDB::Instance()->Add(new ItemData(4001, ITEMTYPE_MATERIAL, ITEM_LEATHER, "����", "��", 0, 0, 0));
	ItemDB::Instance()->Add(new ItemData(4002, ITEMTYPE_MATERIAL, ITEM_WOOD, "����", "��", 0, 0, 0));
	ItemDB::Instance()->Add(new ItemData(4003, ITEMTYPE_MATERIAL, ITEM_ROCK, "����", "��", 0, 0, 0));
}

void ItemDB::Add(ItemData* pData)
{
	m_list.Add(pData);
}

ItemData* ItemDB::GetDataByID(int id)
{
	for (int i = 0; i < m_list.Count(); i++)
	{
		ItemData* pData = m_list.GetData(i);
		if (pData->id == id) return pData;
	}
	return NULL;
}

ItemData* ItemDB::GetDataByTag(ITEM_TAG tag)
{
	for (int i = 0; i < m_list.Count(); i++)
	{
		ItemData* pData = m_list.GetData(i);
		if (pData->tag == tag) return pData;
	}
	return NULL;
}
