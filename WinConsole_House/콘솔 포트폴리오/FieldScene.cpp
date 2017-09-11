#include "FieldScene.h"


void FieldScene::OnEnter()
{
	ObjectMgr::CreateMonster(15, 15, CharacterDB::GetData(RABBIT));
	ObjectMgr::CreateMonster(35, 15, CharacterDB::GetData(BOAR));
	ObjectMgr::CreateMonster(55, 15, CharacterDB::GetData(BULL));
}

void FieldScene::OnUpdate()
{

	Character* pPlayer = ObjectMgr::GetPlayer();

	POS pos = POS(7, 15);



	ObjectMgr::GetPlayer()->SetPosition(pos);


	RenderMgr::ClearScreen();
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::SetCursorPosition(0, 0);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩{들판}▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", 1);
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


	DrawBackGround();



	bool exit = true;
	while (exit)
	{
		Status::ShowStatus();
		

		ArrayList<Character*> list = ObjectMgr::GetMonsters();
		for (int i = 0; i < list.Count(); i++)
		{
			Character* monster = list.GetData(i);
			monster->DrawCharacter(0);
		}
		pPlayer->DrawCharacter(0);

		for (int i = 0; i < list.Count(); i++)
		{
			Character* monster = list.GetData(i);
			if (monster->IsCollided(pPlayer))
			{
				RenderMgr::SetColor(COLOR_RED, COLOR_SKY);
				monster->Attack(pPlayer, 0);
				pos.x -= 8;
				pPlayer->RemoveDrawCharacter(0);
				DrawBackGround();
				pPlayer->SetPosition(pos);
				monster->DrawCharacter(0);
				for (int i = 0; i < list.Count(); i++)
				{
					Character* monster = list.GetData(i);
					monster->DrawCharacter(0);
				}
				break;
			}
		}

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
		case Key::C:
			Status::ShowStatuslist();
			DrawEdge();
			DrawBackGround();
			break;
		case Key::SPACE:ObjectMgr::GetPlayer()->Swing();
			for (int i = 0; i < list.Count(); i++)
			{
				Character* monster = list.GetData(i);
				if (pPlayer->IsCollided(monster))
				{
					ObjectMgr::GetPlayer()->SetAction(-1);
					RenderMgr::SetColor(COLOR_RED, COLOR_SKY);
					pPlayer->Attack(monster, 0);

					if (monster->GetLife() == 0.0f)
					{
						monster->RemoveDrawCharacter(0);

						for (int i = 0; i < monster->GetTag(); i++)
						{
							if (ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_NONE) < 1)
							{
								ObjectMgr::GetPlayer()->LackInventory();
								break;
							}
							ObjectMgr::GetPlayer()->Inventory()->Add(ITEM_LEATHER);
							ObjectMgr::GetPlayer()->Inventory()->Add(ITEM_MEAT);
						}
						ObjectMgr::DestroyMonster(monster);
						break;
					}

				}



			}

			break;
		case Key::I:
			Bag bag;
			bag.ShowBag();
			DrawEdge();
			DrawBackGround();
			break;
		}






		pos.x = Math::Clamp(pos.x, 6, 69);
		pPlayer->RemoveDrawCharacter(0);
		pPlayer->SetPosition(pos);

		if (pos.x == 6)
		{
			if (exitConfirm())
			{
				if (pos.x == 6)SceneMgr::Instance()->ChangeScene(SCENE_FOREST);
				exit = false;
			}
			else
			{
				pos.x = 8;
				RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
				RenderMgr::Draw("                                    ", POS(23, 9), 1);
				RenderMgr::Draw("                                    ", POS(23, 10), 1);
				RenderMgr::Draw("                                    ", POS(23, 11), 1);
				RenderMgr::Draw("                                    ", POS(23, 12), 1);
			}
		}
		if (CheckHealth())exit = false;
	}


	RenderMgr::SetColor(COLOR_BLACK, COLOR_BLACK);
}

void FieldScene::OnExit()
{

	ObjectMgr::DestroyAllMonster();
}

bool FieldScene::exitConfirm()
{
	Menu menu(POS(25, 10));
	menu.Add("             확  인             ");
	menu.Add("             취  소             ");

	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩나가기▩▩▩▩▩▩▩", POS(23, 9), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 10 + menu.GetCount()), 1);

	for (int i = 0; i < menu.GetCount(); i++)
	{
		RenderMgr::Draw("▩                                ▩", POS(23, 10 + i), 1);
	}




	switch (menu.Update())
	{
	case 0:
		return true;
		break;
	case 1:
		return false;
		break;
	}
}

bool FieldScene::CheckHealth()
{
	if (ObjectMgr::GetPlayer()->GetLife() <= 0)
	{
		
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩죽  음▩▩▩▩▩▩▩", POS(23, 9), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 11), 1);
		RenderMgr::Draw("당신은 죽었습니다", POS(26, 10), 0);
		for (int i = 0; i < 5; i++)
		{
			RenderMgr::Draw(".", POS(43 + i, 10), 0);
			Sleep(1000);
		}
		SceneMgr::Instance()->ChangeScene(SCENE_START);
		RenderMgr::SetCursorPosition(20, 15);
		return true;
	}
	return false;
}
void FieldScene::DrawEdge()
{

	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::SetCursorPosition(0, 0);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩{들판}▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", 1);
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
void FieldScene::DrawBackGround()
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
