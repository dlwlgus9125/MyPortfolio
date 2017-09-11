#include "HomeScene.h"


void HomeScene::OnEnter()
{

}

void HomeScene::OnUpdate()
{
	Character* pPlayer = ObjectMgr::GetPlayer();

	POS pos;
	if (m_checker == 0) pos = pPlayer->GetPosition();
	if (ObjectMgr::GetPlayer()->GetChecker() == 1) pos = POS(65, 15);


	ObjectMgr::GetPlayer()->SetPosition(pos);

	DrawEdge();
	Status::ShowStatus();

	DrawBackGround();




	bool exit = true;
	while (exit)
	{
		pPlayer->DrawCharacter(0);
		DrawHouse(pPlayer);

		switch (Key::GetInput())
		{
		case Key::LEFT:
			pos.x -= 2;
			if (ObjectMgr::Instance()->GetPlayer()->GetSee() == SEE_RIGHT)ObjectMgr::GetPlayer()->SetSee(SEE_LEFT);
			break;
		case Key::RIGHT: pos.x += 2;
			if (ObjectMgr::Instance()->GetPlayer()->GetSee() == SEE_LEFT)ObjectMgr::GetPlayer()->SetSee(SEE_RIGHT);
			break;
		case Key::UP:  break;
		case Key::ENTER:
			if (pos.x == 18)
			{
				Confirm();

				DrawHouse(pPlayer);
			}
			break;
		case Key::SPACE:ObjectMgr::GetPlayer()->Swing(); break;
		case Key::I:
			Bag bag;
			bag.ShowBag();
			DrawEdge();
			DrawBackGround();
			break;
		case Key::C:
			Status::ShowStatuslist();
			DrawEdge();
			DrawBackGround();
			break;
		case Key::ESC:
			SceneMgr::Instance()->ChangeScene(SCENE_PLAYER);
			break;
		}

		pos.x = Math::Clamp(pos.x, 18, 69);
		pPlayer->RemoveDrawCharacter(0);
		pPlayer->SetPosition(pos);

		RenderMgr::SetColor(COLOR_BLACK, COLOR_BLACK);

		if (pos.x == 69)
		{
			if (exitConfirm())
			{
				if (ObjectMgr::GetPlayer()->GetChecker() == 0)ObjectMgr::GetPlayer()->SetChecker(1);
				SceneMgr::Instance()->ChangeScene(SCENE_FOREST);
				exit = false;
			}
			else
			{
				pos.x = 67;

			}
		}
	}



}

void HomeScene::OnExit()
{

}


bool HomeScene::exitConfirm()
{
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩나가기▩▩▩▩▩▩▩", POS(23, 9), 1);
	RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
	RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);

	Menu menu(POS(25, 10));
	menu.Add("             확  인             ");
	menu.Add("             취  소             ");



	switch (menu.Update())
	{
	case 0:
		return true;
		menu.RemoveMenu(menu.GetCount());
		break;
	case 1:
		menu.RemoveMenu(menu.GetCount());
		return false;
		break;
	}
}

void HomeScene::Confirm()
{
	Menu menu(POS(25, 10));
	if (ObjectMgr::Instance()->GetPlayer()->GetHouseTag() != HOUSE_STONE)menu.Add("           거주지 증축          ");
	menu.Add("           집에서 쉬기          ");
	menu.Add("           아이템 제작          ");
	menu.Add("             창  고             ");
	menu.Add("             취  소             ");

	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	if (ObjectMgr::Instance()->GetPlayer()->GetHouseTag() == HOUSE_NONE)RenderMgr::Draw("▩▩▩▩▩▩▩{집  터}▩▩▩▩▩▩▩", POS(23, 9), 1);
	if (ObjectMgr::Instance()->GetPlayer()->GetHouseTag() == HOUSE_TENT)RenderMgr::Draw("▩▩▩▩▩▩▩{텐  트}▩▩▩▩▩▩▩", POS(23, 9), 1);
	if (ObjectMgr::Instance()->GetPlayer()->GetHouseTag() == HOUSE_WOOD)RenderMgr::Draw("▩▩▩▩▩▩▩{나무집}▩▩▩▩▩▩▩", POS(23, 9), 1);
	if (ObjectMgr::Instance()->GetPlayer()->GetHouseTag() == HOUSE_STONE)RenderMgr::Draw("▩▩▩▩▩▩▩{돌  집}▩▩▩▩▩▩▩", POS(23, 9), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 10 + menu.GetCount()), 1);

	for (int i = 0; i < menu.GetCount(); i++)
	{
		RenderMgr::Draw("▩                                ▩", POS(23, 10 + i), 1);
	}



	switch (menu.Update())
	{
	case 0:
		menu.RemoveMenu(menu.GetCount());
		if (ObjectMgr::GetPlayer()->GetHouseTag() != HOUSE_STONE)
		{
			
			if (!Upgrade())
			{

				RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
				RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
				RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
				RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
				RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
				RenderMgr::Draw("            -경  고-            ", POS(25, 10), 1);
				RenderMgr::Draw("       자원이 모자랍니다.       ", POS(25, 11), 1);
				Sleep(2000);

			}
			menu.RemoveMenu(4);
		}
		else
		{
			HouseSleep();
		}
		break;
	case 1:
		menu.RemoveMenu(menu.GetCount()); 
		if (ObjectMgr::GetPlayer()->GetHouseTag() == HOUSE_STONE)
	       {
			   CreateItem();
	       }
		   else
		   {
			   HouseSleep();
		   }
		   break;
	case 2:
		menu.RemoveMenu(menu.GetCount());
		if (ObjectMgr::GetPlayer()->GetHouseTag() == HOUSE_STONE)
		{
			Storage storage;
			storage.ShowStrageMain();
			DrawEdge();
			DrawBackGround();
		}
		else
		{
			CreateItem();
		}
		break;
	case 3:
		if (ObjectMgr::GetPlayer()->GetHouseTag() != HOUSE_STONE)
		{
			Storage storage;
			storage.ShowStrageMain();
			DrawEdge();
			DrawBackGround();
		}
		break;
	}
	menu.RemoveMenu(menu.GetCount());
}

void HomeScene::HouseSleep()
{
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩휴  식▩▩▩▩▩▩▩", POS(23, 9), 1);
	RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 11), 1);

	for (int i = 0; i < 4; i++)
	{
		RenderMgr::Draw("z", POS(26 + i, 10), 0);
		Sleep(1000);
	}
	RenderMgr::Draw("ZZZ", POS(30, 10), 0);
	Sleep(1000);
	ObjectMgr::GetPlayer()->AddLife((ObjectMgr::GetPlayer()->GetHouseTag() + 1) * 2);
	ObjectMgr::GetPlayer()->SetAction(10);
	Status::ShowStatus();

}

void HomeScene::CreateItem()
{
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	Menu menu(POS(25, 10));
	menu.Add("             곡괭이             ");
	menu.Add("              도끼              ");
	menu.Add("             가죽옷             ");
	menu.Add("             장  갑             ");
	menu.Add("             취  소             ");

	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩제  작▩▩▩▩▩▩▩", POS(23, 9), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 10 + menu.GetCount()), 1);

	for (int i = 0; i < menu.GetCount(); i++)
	{
		RenderMgr::Draw("▩                                ▩", POS(23, 10 + i), 1);
	}

	switch (menu.Update())
	{
	case 0:
		menu.RemoveMenu(menu.GetCount());
		ObjectMgr::GetPlayer()->CheckingCreateItem(ITEM_PICKAXE, 2, 3, 0); break;
	case 1:
		menu.RemoveMenu(menu.GetCount());
		ObjectMgr::GetPlayer()->CheckingCreateItem(ITEM_AXE, 3, 4, 0); break;
	case 2:
		menu.RemoveMenu(menu.GetCount());
		ObjectMgr::GetPlayer()->CheckingCreateItem(ITEM_CLOTH, 2, 1, 4); break;
	case 3:
		menu.RemoveMenu(menu.GetCount());
		ObjectMgr::GetPlayer()->CheckingCreateItem(ITEM_GLOVES, 1, 0, 3); break;
	case 4:break;

	}
	menu.RemoveMenu(menu.GetCount());
}

bool HomeScene::Upgrade()
{
	if (ObjectMgr::GetPlayer()->GetHouseTag() == HOUSE_NONE&&ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_WOOD) >= 2)
	{
		ObjectMgr::GetPlayer()->Inventory()->Remove(ITEM_WOOD, 2);
		ObjectMgr::GetPlayer()->SetHouse(HOUSE_TENT);
		UpgradeSuccess();
		return true;
	}
	else if (ObjectMgr::GetPlayer()->GetHouseTag() == HOUSE_TENT&&ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_WOOD) >= 4 && ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_ROCK) >= 1)
	{
		ObjectMgr::GetPlayer()->Inventory()->Remove(ITEM_WOOD, 4);
		ObjectMgr::GetPlayer()->Inventory()->Remove(ITEM_ROCK, 1);
		ObjectMgr::GetPlayer()->SetHouse(HOUSE_WOOD);
		UpgradeSuccess();
		return true;
	}
	else if (ObjectMgr::GetPlayer()->GetHouseTag() == HOUSE_WOOD&&ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_WOOD) >= 2 && ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_ROCK) >= 6 && ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_LEATHER) >= 2)
	{
		ObjectMgr::GetPlayer()->Inventory()->Remove(ITEM_WOOD, 2);
		ObjectMgr::GetPlayer()->Inventory()->Remove(ITEM_ROCK, 6);
		ObjectMgr::GetPlayer()->Inventory()->Remove(ITEM_LEATHER, 2);
		ObjectMgr::GetPlayer()->SetHouse(HOUSE_STONE);
		UpgradeSuccess();
		return true;
	}
	else if (ObjectMgr::GetPlayer()->GetHouseTag() == HOUSE_STONE)
	{
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
		RenderMgr::Draw("            -알  림-            ", POS(25, 10), 1);
		RenderMgr::Draw("   더이상 증축할 수 없습니다.   ", POS(25, 11), 1);
		Sleep(2000);
		return true;
	}

	return false;
}

void HomeScene::UpgradeSuccess()
{
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
	RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
	RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
	RenderMgr::Draw("            -알  림-            ", POS(25, 10), 1);
	RenderMgr::Draw("      증축을 완료하였습니다.    ", POS(25, 11), 1);
	Sleep(2000);
}


void HomeScene::DrawEdge()
{

	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::SetCursorPosition(0, 0);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩{거처}▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩                                                                          ▩", 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", 1);
}

void HomeScene::DrawBackGround()
{
	RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
	RenderMgr::Draw("                                                                          ", POS(2, 1), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 2), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 3), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 4), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 5), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 6), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 7), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 8), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 9), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 10), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 11), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 12), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 13), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 14), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 15), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 16), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 17), 1);

	RenderMgr::SetColor(COLOR_GREEN, COLOR_GREEN);
	RenderMgr::Draw("                                                                          ", POS(2, 18), 1);
	RenderMgr::SetColor(COLOR_DARK_RED, COLOR_DARK_RED);
	RenderMgr::Draw("                                                                          ", POS(2, 19), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 20), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 21), 1);
	RenderMgr::Draw("                                                                          ", POS(2, 22), 1);

	RenderMgr::SetColor(COLOR_WHITE, COLOR_SKY);
	RenderMgr::Draw("■■■■", POS(8, 4), 1);
	RenderMgr::Draw("■■■■■■", POS(6, 5), 1);
	RenderMgr::Draw("■■■■■■", POS(6, 6), 1);
	RenderMgr::Draw("■■■■", POS(8, 7), 1);

	RenderMgr::Draw("■■■■", POS(30, 3), 1);
	RenderMgr::Draw("■■■■■■", POS(28, 4), 1);
	RenderMgr::Draw("■■■■■■", POS(28, 5), 1);
	RenderMgr::Draw("■■■■", POS(30, 6), 1);

	RenderMgr::Draw("■■■■", POS(55, 5), 1);
	RenderMgr::Draw("■■■■■■", POS(53, 6), 1);
	RenderMgr::Draw("■■■■■■", POS(53, 7), 1);
	RenderMgr::Draw("■■■■", POS(55, 8), 1);

}

void HomeScene::DrawHouse(Character* pPlayer)
{
	if (pPlayer->GetHouseTag() == HOUSE_NONE)
	{
		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_DARK_RED);
		RenderMgr::Draw("            ", POS(5, 18), 1);
	}
	else if (pPlayer->GetHouseTag() == HOUSE_TENT)
	{
		RenderMgr::SetColor(COLOR_GREEN, COLOR_SKY);
		RenderMgr::Draw("     ▲", POS(5, 9), 1);
		RenderMgr::Draw("    ▲▲", POS(5, 10), 1);
		RenderMgr::Draw("   ▲▲▲", POS(5, 11), 1);
		RenderMgr::Draw("  ▲▲▲▲", POS(5, 12), 1);
		RenderMgr::Draw(" ▲▲▲▲▲", POS(5, 13), 1);
		RenderMgr::Draw("▲▲▲▲▲▲", POS(5, 14), 1);
		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_SKY);
		RenderMgr::Draw("■        ■", POS(5, 15), 1);
		RenderMgr::Draw("■        ■", POS(5, 16), 1);
		RenderMgr::Draw("■        ■", POS(5, 17), 1);
		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_DARK_RED);
		RenderMgr::Draw("            ", POS(5, 18), 1);

	}
	else if (pPlayer->GetHouseTag() == HOUSE_WOOD)
	{
		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_SKY);
		RenderMgr::Draw("■■■■■■", POS(5, 10), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 11), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 12), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 13), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 14), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 15), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 16), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 17), 1);
		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_DARK_RED);
		RenderMgr::Draw("            ", POS(5, 18), 1);
	}
	else if (pPlayer->GetHouseTag() == HOUSE_STONE)
	{
		RenderMgr::SetColor(COLOR_GRAY, COLOR_SKY);
		RenderMgr::Draw("■■    ■■", POS(5, 9), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 10), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 11), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 12), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 13), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 14), 1);
		RenderMgr::Draw("■■■■■■", POS(5, 15), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 16), 1);
		RenderMgr::Draw("■■    ■■", POS(5, 17), 1);
		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_DARK_RED);
		RenderMgr::Draw("            ", POS(5, 18), 1);
	}




}
