#pragma once
#include "ObjectMgr.h"
#include "ItemDB.h"
#include "Constant.h"
#include "Status.h"



class Storage
{
	int m_cursor;
	int m_checker;




public:
	void equipChecker(int cursor)
	{
		if (m_cursor != cursor)RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
		if (m_cursor == cursor)RenderMgr::SetColor(COLOR_DARK_RED, COLOR_WHITE);
	}

	void ShowStorageUI()
	{
		m_checker = 1;
		RenderMgr::SetColor(COLOR_RED, COLOR_DARK_RED);
		RenderMgr::Draw("〓〓〓〓창 고〓〓〓〓    〓〓〓〓착  용〓〓〓〓", POS(20, 7), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||   ||                  ||", POS(20, 8), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓   ||                  ||", POS(20, 9), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||   ||                  ||", POS(20, 10), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓   〓〓〓〓가  방〓〓〓〓", POS(20, 11), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||   ||  ||  ||  ||  ||  ||", POS(20, 12), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓   〓〓〓〓〓〓〓〓〓〓〓", POS(20, 13), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||   ||  ||  ||  ||  ||  ||", POS(20, 14), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓   〓〓〓〓〓〓〓〓〓〓〓", POS(20, 15), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||   ||  ||  ||  ||  ||  ||", POS(20, 16), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓   〓〓〓〓〓〓〓〓〓〓〓", POS(20, 17), 1);

		
	}

	void ShowStrageMain()
	{

		ShowStorageUI();
		while (true)
		{
			if (m_checker == 0)ShowStorage();
			if (m_checker == 1)ShowBag();
			if (m_checker == 2)break;
		}
	}


	void ShowStorage()
	{
		m_cursor = 18;
		

		bool exit = true;
		while (exit)
		{
			ArrayList<ItemData*> items = ObjectMgr::GetPlayer()->Inventory()->GetItems();
			ArrayList<ItemData*> storage = ObjectMgr::GetPlayer()->Storage()->GetItems();
			RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
			RenderMgr::Draw("무기[  ]", POS(52, 8), 1);
			RenderMgr::Draw("의류[  ]", POS(52, 9), 1);
			RenderMgr::Draw("장갑[  ]", POS(52, 10), 1);
			equipChecker(0);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getWeapon()->emoticon, POS(57, 8), 1);
			equipChecker(1);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getCloth()->emoticon, POS(57, 9), 1);
			equipChecker(2);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getGlove()->emoticon, POS(57, 10), 1);
			for (int i = 0 + 3; i < items.Count() + 3; i++)
			{
				ItemData* itemData = items.GetData(i - 3);

				RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
				if (i < 8)RenderMgr::Draw(itemData->emoticon, POS((47 + 4 * (i - 3)), 12), 0);
				if (i<13 && i>7)RenderMgr::Draw(itemData->emoticon, POS((47 + 4 * ((i - 3) - 5)), 14), 0);
				if (i<18 && i>12)RenderMgr::Draw(itemData->emoticon, POS((47 + 4 * ((i - 3) - 10)), 16), 0);
			}
			for (int i = 3 + items.Count(); i < items.Count() + storage.Count() + 3; i++)
			{
				ItemData* itemData = storage.GetData(i - 18);

				if (m_cursor == i)RenderMgr::SetColor(COLOR_DARK_RED, COLOR_WHITE);
				if (m_cursor != i)RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
				if (i<23 && i>17)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * (i - 18)), 8), 0);
				if (i<28 && i>22)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 5)), 10), 0);
				if (i<33 && i>27)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 10)), 12), 0);
				if (i<38 && i>32)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 15)), 14), 0);
				if (i<43 && i>37)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 20)), 16), 0);
			}

			RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
			RenderMgr::Draw("나가기-esc키-", POS(36, 17), 1);


			switch (Key::GetInput())
			{
			case Key::LEFT: if (m_cursor > 3)m_cursor--;
				break;
			case Key::RIGHT: if (m_cursor < items.Count() + storage.Count() + 2)m_cursor++; break;
			case Key::UP: m_cursor -= 5; break;
			case Key::DOWN: if (m_cursor < items.Count() + storage.Count() - 2)m_cursor += 5; break;
			case Key::TAB:
				m_checker = 1;
				exit = false;
				break;
			case Key::ENTER:
				if (storage.GetData(m_cursor - items.Count() - 3)->tag != ITEM_NONE&&ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_NONE) > 0)
				{
					ObjectMgr::GetPlayer()->Inventory()->Add(storage.GetData(m_cursor - items.Count() - 3)->tag);
					ObjectMgr::GetPlayer()->Storage()->Remove(m_cursor - items.Count() - 3);
				}
				else if(ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_NONE) <= 0)
				{
					ObjectMgr::GetPlayer()->LackInventory();
					ShowStorageUI();
				}
				break;
			case Key::ESC:
				m_checker = 2;
				exit = false; 
				break;
			}
			m_cursor = Math::Clamp(m_cursor, 18, items.Count()+storage.Count() + 2);

		}
	}

	void ShowBag()
	{
		m_cursor = 3;
		

		bool exit = true;
		while (exit)
		{
			ArrayList<ItemData*> items = ObjectMgr::GetPlayer()->Inventory()->GetItems();
			ArrayList<ItemData*> storage = ObjectMgr::GetPlayer()->Storage()->GetItems();
			RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
			RenderMgr::Draw("무기[  ]", POS(52, 8), 1);
			RenderMgr::Draw("의류[  ]", POS(52, 9), 1);
			RenderMgr::Draw("장갑[  ]", POS(52, 10), 1);
			equipChecker(0);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getWeapon()->emoticon, POS(57, 8), 1);
			equipChecker(1);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getCloth()->emoticon, POS(57, 9), 1);
			equipChecker(2);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getGlove()->emoticon, POS(57, 10), 1);
			for (int i = 0 + 3; i < items.Count() + 3; i++)
			{
				ItemData* itemData = items.GetData(i - 3);

				if (m_cursor == i)RenderMgr::SetColor(COLOR_DARK_RED, COLOR_WHITE);
				if (m_cursor != i)RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
				if (i < 8)RenderMgr::Draw(itemData->emoticon, POS((47 + 4 * (i - 3)), 12), 0);
				if (i<13 && i>7)RenderMgr::Draw(itemData->emoticon, POS((47 + 4 * ((i - 3) - 5)), 14), 0);
				if (i<18 && i>12)RenderMgr::Draw(itemData->emoticon, POS((47 + 4 * ((i - 3) - 10)), 16), 0);
			}
			for (int i = 3 + items.Count(); i < items.Count() + storage.Count() + 3; i++)
			{
				ItemData* itemData = storage.GetData(i - 18);

				RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
				if (i<23 && i>17)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * (i - 18)), 8), 0);
				if (i<28 && i>22)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 5)), 10), 0);
				if (i<33 && i>27)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 10)), 12), 0);
				if (i<38 && i>32)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 15)), 14), 0);
				if (i<43 && i>37)RenderMgr::Draw(itemData->emoticon, POS((22 + 4 * ((i - 18) - 20)), 16), 0);
			}

			RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
			RenderMgr::Draw("나가기-esc키-", POS(36, 17), 1);

			if (m_cursor < 3)
			{
				switch (Key::GetInput())
				{
				case Key::UP: m_cursor--; break;
				case Key::DOWN: m_cursor++; break;
				case Key::TAB:
					m_checker = 0;
					exit = false;
					break;
				case Key::SPACE:
					ObjectMgr::GetPlayer()->unEquipItem(m_cursor); break;
				case Key::ESC:
					m_checker = 2;
					exit = false;
					break;
				}
				m_cursor = Math::Clamp(m_cursor, 0, items.Count() + 3);
			}
			else
			{
				switch (Key::GetInput())
				{
				case Key::LEFT: 
					if (m_cursor > 3)m_cursor--;
					break;
				case Key::RIGHT: if (m_cursor < items.Count() + 2)m_cursor++; break;
				case Key::UP: m_cursor -= 5; break;
				case Key::DOWN: if (m_cursor < items.Count() - 3)m_cursor += 5; break;
				case Key::ESC: 
					m_checker = 2;
					exit = false;
					break;
				case Key::TAB:
					m_checker = 0;
					exit = false;
					break;
				case Key::ENTER:
					if (items.GetData(m_cursor - 3)->tag != ITEM_NONE&&ObjectMgr::GetPlayer()->Storage()->CheckItem(ITEM_NONE) >0)
					{
						ObjectMgr::GetPlayer()->Storage()->Add(items.GetData(m_cursor - 3)->tag);
						ObjectMgr::GetPlayer()->Inventory()->Remove(m_cursor - 3);
					}
					else if (ObjectMgr::GetPlayer()->Storage()->CheckItem(ITEM_NONE) <1)
					{
						ObjectMgr::GetPlayer()->LackStorage();
						ShowStorageUI();
					}
					break;
				case Key::SPACE:
						if (!ObjectMgr::GetPlayer()->equipItem(items.GetData(m_cursor - 3)->type, items.GetData(m_cursor - 3)->tag))
						{
							ObjectMgr::GetPlayer()->Inventory()->Remove(m_cursor - 3);
						}
						else if (items.GetData(m_cursor - 3)->type == ITEMTYPE_FOOD)
						{
							ObjectMgr::GetPlayer()->Eat(items.GetData(m_cursor - 3)->tag);
							ObjectMgr::GetPlayer()->Inventory()->Remove(m_cursor - 3);
							Status::ShowStatus();
						}
						ObjectMgr::GetPlayer()->UpdateEquip();
						break;
					
				}
				m_cursor = Math::Clamp(m_cursor, 2, items.Count() + 2);
			}
		}
		ObjectMgr::GetPlayer()->UpdateEquip();

	}

};