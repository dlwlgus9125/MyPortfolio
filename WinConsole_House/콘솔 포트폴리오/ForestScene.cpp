#include "ForestScene.h"



void ForestScene::OnEnter()
{
	ObjectMgr::CreateResource(15, 15, CharacterDB::GetData(WOOD));
	ObjectMgr::CreateResource(35, 15, CharacterDB::GetData(WOOD));
	ObjectMgr::CreateResource(55, 15, CharacterDB::GetData(STONE));


}

void ForestScene::OnUpdate()
{
	Character* pPlayer = ObjectMgr::GetPlayer();

	POS pos;

	if (ObjectMgr::GetPlayer()->GetChecker() == 0) { pos = POS(65, 15); }
	else if (ObjectMgr::GetPlayer()->GetChecker() == 1) { pos = POS(7, 15); }

	ObjectMgr::GetPlayer()->SetPosition(pos);




	DrawEdge();
	DrawBackGround();



	bool exit = true;
	while (exit)
	{
		Status::ShowStatus();

		ArrayList<Character*> list = ObjectMgr::GetResources();
		for (int i = 0; i < list.Count(); i++)
		{
			Character* resource = list.GetData(i);
			resource->DrawCharacter(0);
		}
		pPlayer->DrawCharacter(0);



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
				Character* resource = list.GetData(i);
				if (pPlayer->IsCollided(resource) && pPlayer->GetActionPoint()>0)
				{
					ObjectMgr::GetPlayer()->SetAction(-1);
					RenderMgr::SetColor(COLOR_RED, COLOR_SKY);
					pPlayer->Attack(resource, 0);

					if (resource->GetLife() == 0.0f)
					{
						resource->RemoveDrawCharacter(0);
						ITEM_TAG tag = (resource->GetTag() == WOOD) ? ITEM_WOOD : ITEM_ROCK;


						for (int i = 0; i < 2 + pPlayer->SetBonusResource(pPlayer, resource->GetTag()); i++)
						{
							if (ObjectMgr::GetPlayer()->Inventory()->CheckItem(ITEM_NONE) < 1)
							{
								ObjectMgr::GetPlayer()->LackInventory();
								
								break;
							}
							ObjectMgr::GetPlayer()->Inventory()->Add(tag);
						}
						ObjectMgr::DestroyResource(resource);
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

		if (pos.x == 6 || pos.x == 69)
		{
			if (exitConfirm())
			{
				if (pos.x == 6)
				{
					ObjectMgr::GetPlayer()->SetChecker(1);
					SceneMgr::Instance()->ChangeScene(SCENE_HOME);

				}
				else if (pos.x == 69)
				{
					ObjectMgr::GetPlayer()->SetChecker(0);
					SceneMgr::Instance()->ChangeScene(SCENE_FIELD);
				}
				exit = false;
			}
			else
			{
				if (pos.x <= 6)pos.x = 9;
				if (pos.x >= 69)pos.x = 67;

				RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
				RenderMgr::Draw("                                    ", POS(23, 9), 1);
				RenderMgr::Draw("                                    ", POS(23, 10), 1);
				RenderMgr::Draw("                                    ", POS(23, 11), 1);
				RenderMgr::Draw("                                    ", POS(23, 12), 1);
				
			}
			
		}
		
	}

	RenderMgr::SetColor(COLOR_BLACK, COLOR_BLACK);
}

void ForestScene::OnExit()
{
	ObjectMgr::DestroyAllMonster();
}

bool ForestScene::exitConfirm()
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
		break;
	case 1:
		
		return false;
		break;
	}
}

void ForestScene::DrawEdge()
{
	
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::SetCursorPosition(0, 0);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩{숲속}▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", 1);
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

void ForestScene::DrawBackGround()
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
