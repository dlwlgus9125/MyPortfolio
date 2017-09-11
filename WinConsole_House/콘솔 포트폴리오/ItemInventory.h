#pragma once
#include "ItemDB.h"
#include "ArrayList.h"
#include "Constant.h"

class ItemInventory
{
	ArrayList<ITEM_TAG> m_list;
	int m_capacity;


public:
	ItemInventory(int capacity);//샘플에서 소멸자가 없는 이유 질문하기

	bool IsFull(){ return m_capacity == m_list.Count(); }

	void Initialize();

	void Add(ITEM_TAG tag);

	void Remove(int index);
	void Remove(ITEM_TAG tag, int count);

	int CheckItem(ITEM_TAG tag);

	ArrayList<ItemData*>& GetItems();
};

