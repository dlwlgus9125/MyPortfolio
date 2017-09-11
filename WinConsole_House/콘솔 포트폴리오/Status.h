#pragma once
#include "ObjectMgr.h"




class Status
{
public:

	static void ShowStatus()
	{
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩                                                                          ▩", POS(0, 24), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(0, 25), 1);
	
		RenderMgr::SetColor(COLOR_WHITE, COLOR_BLACK);
		RenderMgr::Draw("이름 :             생명력 :                  기력 :", POS(2, 24), 1);
		RenderMgr::Draw(ObjectMgr::GetPlayer()->GetName(), POS(9, 24), 0);
	  
		for (int i = 0; i < ObjectMgr::GetPlayer()->GetLife(); i++)
		{
			RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
			RenderMgr::Draw("|", POS(30 + i, 24), 0);
		}
		for (int i = 0; i < ObjectMgr::GetPlayer()->GetActionPoint(); i++)
		{
			RenderMgr::SetColor(COLOR_YELLOW, COLOR_BLACK);
			RenderMgr::Draw("|", POS(54 + i, 24), 0);
		}
	
	}

	static void ShowStatuslist()
	{
		bool exit = true;
		while (exit)
		{
			RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
			RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩상태▩▩▩▩▩▩▩▩▩▩", POS(20, 7), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 8), 1);
			RenderMgr::Draw("▩   {외관}   ▩                              ▩", POS(20, 9), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 10), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 11), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 12), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 13), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 14), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 15), 1);
			RenderMgr::Draw("▩            ▩                              ▩", POS(20, 16), 1);
			RenderMgr::Draw("▩▩▩▩▩▩▩▩-나가기 esc키-▩▩▩▩▩▩▩▩▩", POS(20, 17), 1);
			Character* pPlayer = ObjectMgr::GetPlayer();

			pPlayer->SetPosition(POS(27, 11));


			pPlayer->DrawCharacter(1);

			char text[100];
			sprintf(text, "이름 : %s", pPlayer->GetName().c_str());
			RenderMgr::Draw(text, POS(22, 15), 0);
			sprintf(text, "생명력(%3.f/%3.f)", pPlayer->GetLife(), pPlayer->GetLifeMax());
			RenderMgr::Draw(text, POS(40, 9), 0);
			sprintf(text, "기  력(%3.f/%3.f)", pPlayer->GetActionPoint(), pPlayer->GetActionPointMax());
			RenderMgr::Draw(text, POS(40, 11), 0);
			sprintf(text, "공격력(%3.f+(%.f))", pPlayer->GetAttackMax(), pPlayer->getWeapon()->increaseAttack);
			RenderMgr::Draw(text, POS(40, 13), 0);
			sprintf(text, "방어력(%3.f+(%.f))", pPlayer->GetDefenseMax(), pPlayer->getCloth()->increaseDefense);
			RenderMgr::Draw(text, POS(40, 15), 0);
			switch (Key::GetInput())
			{
			case Key::ESC:exit=false; break;
			}
		}
	}

};
