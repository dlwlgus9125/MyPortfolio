#include "ItemInventory.h"


ItemInventory::ItemInventory(int capacity)
{
	m_capacity = capacity;
	Initialize();
}



void ItemInventory::Initialize()
{
	for (int i = 0; i < m_capacity; i++)
	{
		m_list.Add(ITEM_NONE);
	}
}

void ItemInventory::Add(ITEM_TAG tag)
{
	for (int i = 0; i < m_capacity; i++)
	{
		if (m_list.IndexOf(ITEM_NONE) == i)
		{
			m_list.Update(tag, i);
			break;
		}
	}
}

void ItemInventory::Remove(int index)
{
	m_list.Update(ITEM_NONE, index);
}

void ItemInventory::Remove(ITEM_TAG tag, int count)
{
	int inCount = 0;
	for (int i = 0; i < m_capacity; i++)
	{
		if (m_list.IndexOf(tag) == i)
		{
			m_list.Update(ITEM_NONE, i);
			inCount++;
			if (inCount==count)break;
		}
	}
}

int ItemInventory::CheckItem(ITEM_TAG tag)
{
	int count = 0;

	for (int i = 0; i < m_list.Count(); i++)
	{
		if (m_list.GetData(i) == tag)count++;
	}
	return count;
}

ArrayList<ItemData*>& ItemInventory::GetItems()
{
	ArrayList<ItemData*>* itemList = new ArrayList<ItemData*>;

	for (int i = 0; i<m_list.Count(); i++)
	{
		ItemData* pData = ItemDB::Instance()->GetDataByTag(m_list.GetData(i));
		itemList->Add(pData);
	}
	return *itemList;
}