#pragma once
#include "ObjectMgr.h"
#include "ItemDB.h"
#include "Constant.h"
#include "Status.h"



class Bag
{
	int m_cursor;





public:
	void equipChecker(int cursor)
	{
		if (m_cursor != cursor)RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
		if (m_cursor == cursor)RenderMgr::SetColor(COLOR_DARK_RED, COLOR_WHITE);
	}


	void ShowBag()
	{
		m_cursor = 3;
		RenderMgr::SetColor(COLOR_RED, COLOR_DARK_RED);
		RenderMgr::Draw("〓〓〓〓착  용〓〓〓〓", POS(30, 7), 1);
		RenderMgr::Draw("||                  ||", POS(30, 8), 1);
		RenderMgr::Draw("||                  ||", POS(30, 9), 1);
		RenderMgr::Draw("||                  ||", POS(30, 10), 1);
		RenderMgr::Draw("〓〓〓〓가  방〓〓〓〓", POS(30, 11), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||", POS(30, 12), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓", POS(30, 13), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||", POS(30, 14), 1);
		RenderMgr::Draw("〓〓〓〓〓〓〓〓〓〓〓", POS(30, 15), 1);
		RenderMgr::Draw("||  ||  ||  ||  ||  ||", POS(30, 16), 1);
		RenderMgr::Draw("〓〓〓〓      〓〓〓〓", POS(30, 17), 1);


		bool exit = true;
		while (exit)
		{
			ArrayList<ItemData*> items = ObjectMgr::GetPlayer()->Inventory()->GetItems();

			RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
			RenderMgr::Draw("무기[  ]", POS(37, 8), 1);
			RenderMgr::Draw("의류[  ]", POS(37, 9), 1);
			RenderMgr::Draw("장갑[  ]", POS(37, 10), 1);
			equipChecker(0);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getWeapon()->emoticon, POS(42, 8), 1);
			equipChecker(1);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getCloth()->emoticon, POS(42, 9), 1);
			equipChecker(2);
			RenderMgr::Draw(ObjectMgr::GetPlayer()->getGlove()->emoticon, POS(42, 10), 1);
			for (int i = 0 + 3; i < items.Count() + 3; i++)
			{
				ItemData* itemData = items.GetData(i - 3);

				if (m_cursor == i)RenderMgr::SetColor(COLOR_DARK_RED, COLOR_WHITE);
				if (m_cursor != i)RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
				if (i < 8)RenderMgr::Draw(itemData->emoticon, POS((32 + 4 * (i - 3)), 12), 0);
				if (i<13 && i>7)RenderMgr::Draw(itemData->emoticon, POS((32 + 4 * ((i - 3) - 5)), 14), 0);
				if (i<18 && i>12)RenderMgr::Draw(itemData->emoticon, POS((32 + 4 * ((i - 3) - 10)), 16), 0);
			}
			
			
				RenderMgr::SetColor(COLOR_WHITE, COLOR_DARK_RED);
				RenderMgr::Draw("나가기-esc키-", POS(35, 17), 1);
			
			if (m_cursor < 3)
			{
				switch (Key::GetInput())
				{
				case Key::UP: m_cursor--; break;
				case Key::DOWN: m_cursor++; break;
				case Key::ENTER: 
					ObjectMgr::GetPlayer()->unEquipItem(m_cursor);break;
				case Key::ESC:exit = false; break;
				}
				m_cursor = Math::Clamp(m_cursor, 0, items.Count() + 3);
			}
			else
			{
				switch (Key::GetInput())
				{
				case Key::LEFT: if (m_cursor > 3)m_cursor--; break;
				case Key::RIGHT: if (m_cursor < items.Count() + 2)m_cursor++; break;
				case Key::UP: m_cursor -= 5; break;
				case Key::DOWN: if(m_cursor<items.Count()-2)m_cursor += 5; break;
				case Key::ESC:exit = false; break;
				case Key::ENTER:
					if (m_cursor != items.Count() + 3)
					{
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
					};
					ObjectMgr::GetPlayer()->UpdateEquip();
					break;
				}
				m_cursor = Math::Clamp(m_cursor, 2, items.Count()+2);
			}
		}
	
		
	}
	
};