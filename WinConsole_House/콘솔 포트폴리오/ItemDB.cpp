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
	ItemDB::Instance()->Add(new ItemData(1000, ITEMTYPE_NONE, ITEM_NONE, "", "ºö", 0, 0, 0));

	ItemDB::Instance()->Add(new ItemData(1001, ITEMTYPE_WEAPON, ITEM_PICKAXE, "°î±ªÀÌ","°î", 10, 0, 0));
	ItemDB::Instance()->Add(new ItemData(1002, ITEMTYPE_WEAPON, ITEM_AXE, "µµ³¢", "µµ", 20, 0, 0));

	ItemDB::Instance()->Add(new ItemData(2001, ITEMTYPE_ARMOR, ITEM_CLOTH, "¿Ê", "¿Ê", 0, 10, 0));
	ItemDB::Instance()->Add(new ItemData(2002, ITEMTYPE_GLOVES, ITEM_GLOVES, "Àå°©", "Àå", 0, 5, 0));

	ItemDB::Instance()->Add(new ItemData(3001, ITEMTYPE_FOOD, ITEM_MEAT, "°í±â", "À°", 0, 0, 20));
	ItemDB::Instance()->Add(new ItemData(3002, ITEMTYPE_FOOD, ITEM_APPLE, "»ç°ú", "»ç", 0, 0, 20));

	ItemDB::Instance()->Add(new ItemData(4001, ITEMTYPE_MATERIAL, ITEM_LEATHER, "°¡Á×", "°¡", 0, 0, 0));
	ItemDB::Instance()->Add(new ItemData(4002, ITEMTYPE_MATERIAL, ITEM_WOOD, "³ª¹«", "¸ñ", 0, 0, 0));
	ItemDB::Instance()->Add(new ItemData(4003, ITEMTYPE_MATERIAL, ITEM_ROCK, "¼®Àç", "¼®", 0, 0, 0));
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
