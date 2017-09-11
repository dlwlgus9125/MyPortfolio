#pragma once
#include "Character.h"
#include "ItemInventory.h"
#include "Constant.h"
#include "Menu.h"




class Player : public Character
{
protected:
	string           m_name;
	Character*       m_pPlayer;
	ItemInventory*   m_pInventory;
	ItemInventory*   m_pStorage;

	ItemData*        m_pWeapon;
	ItemData*        m_pCloth;
	ItemData*        m_pGlove;

	HOUSE_TAG        m_houseLevel;
	HEAD_SEE         m_See;
	float            m_lumberjacking;
	float            m_hunting;
	float            m_mining;

	int              m_checker;

public:
	Player(CharacterData* pData) : Character(pData)
	{
		m_name = "";
		m_pPlayer = new Character(pData);
		m_pInventory = new ItemInventory(15);
		m_pStorage = new ItemInventory(25);

		for (int i = 0; i < 6; i++)
		{
			m_pInventory->Add(ITEM_WOOD);
		}
		for (int i = 0; i < 6; i++)
		{
			m_pInventory->Add(ITEM_ROCK);
		}
		for (int i = 0; i < 2; i++)
		{
			m_pInventory->Add(ITEM_LEATHER);
		}
		

		m_pWeapon = ItemDB::Instance()->GetDataByTag(ITEM_NONE);
		m_pCloth = ItemDB::Instance()->GetDataByTag(ITEM_NONE);
		m_pGlove = ItemDB::Instance()->GetDataByTag(ITEM_NONE);

		m_houseLevel = HOUSE_STONE;
		m_lumberjacking = 10.0f;
		m_hunting = 10.0f;
		m_See = SEE_RIGHT;
		m_mining = 10.0f;

		m_position = POS(20, 15);
		
		

	}
	~Player();

	string GetName(){ return m_name; }
	ItemInventory* Inventory() { return m_pInventory; }
	ItemInventory* Storage() { return m_pStorage; }
	ItemData* getWeapon(){ return m_pWeapon; }
	ItemData* getCloth(){ return m_pCloth; }
	ItemData* getGlove(){ return m_pGlove; }

	HEAD_SEE GetSee(){ return m_See; }
	void SetSee(HEAD_SEE see)
	{
		RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
		if (m_See == SEE_LEFT)RenderMgr::Draw("  ", POS(m_position.x -4, m_position.y + 1), 1);
		if (m_See == SEE_RIGHT)RenderMgr::Draw("  ", POS(m_position.x + 4, m_position.y + 1), 1);
		m_See = see; 
	}

	bool equipItem(ITEM_TYPE type, ITEM_TAG tag)
	{
		if (type == ITEMTYPE_WEAPON)
		{
			m_pWeapon = ItemDB::Instance()->GetDataByTag(tag);
			return false;
		}
		else if (type == ITEMTYPE_ARMOR)
		{
			m_pCloth = ItemDB::Instance()->GetDataByTag(tag);
			return false;
		}
		else if (type == ITEMTYPE_GLOVES)
		{
			m_pGlove = ItemDB::Instance()->GetDataByTag(tag);
			return false;
		}
		return true;
	}

	void UpdateEquip()
	{
		m_pPlayer->SetAttack((m_pPlayer->GetAttack())+(m_pWeapon->increaseAttack));
		m_pPlayer->SetDefense((m_pPlayer->GetDefense()) + (m_pCloth->increaseDefense));
	}

	bool unEquipItem(int index)
	{
		if (index == 0)
		{
			if (m_pWeapon != ItemDB::Instance()->GetDataByTag(ITEM_NONE))
			{
				m_pPlayer->SetAttack((m_pPlayer->GetAttack()) - (m_pWeapon->increaseAttack));
				m_pInventory->Add(m_pWeapon->tag);
				m_pWeapon = ItemDB::Instance()->GetDataByTag(ITEM_NONE);
				
				return false;
			}
		}
		else if (index == 1)
		{
			if (m_pCloth != ItemDB::Instance()->GetDataByTag(ITEM_NONE))
			{
				m_pPlayer->SetDefense((m_pPlayer->GetDefense()) - (m_pCloth->increaseDefense));
				m_pInventory->Add(m_pCloth->tag);
				m_pCloth = ItemDB::Instance()->GetDataByTag(ITEM_NONE);
				return false;
			}
		}
		else if (index == 2)
		{
			if (m_pGlove != ItemDB::Instance()->GetDataByTag(ITEM_NONE))
			{
				m_pInventory->Add(m_pGlove->tag);
				m_pGlove = ItemDB::Instance()->GetDataByTag(ITEM_NONE);
				return false;
			}
		}
		return true;
	}

	float GetLumberjacking(){ return m_lumberjacking; }
	float GetHunting(){ return m_hunting; }
	float GetMining(){ return m_mining; }
	HOUSE_TAG GetHouseTag(){ return m_houseLevel; }
	void SetHouse(HOUSE_TAG tag){ m_houseLevel = tag; }
	void Eat(ITEM_TAG tag)
	{
		SetAction(ItemDB::Instance()->GetDataByTag(tag)->RecoveryActionPoint);
	}


	void SetPlayer(int cursor)
	{
		if (cursor == 0)m_lumberjacking += 20;
		if (cursor == 1)m_hunting += 20;
		if (cursor == 2)m_mining += 20;

		bool exit = true;
		while (exit)
		{
			RenderMgr::Draw("▩▩▩▩▩▩▩▩이름▩▩▩▩▩▩▩▩", POS(24, 14), 1);
			RenderMgr::Draw("▩ 입력 :                         ▩", POS(24, 15), 1);
			RenderMgr::Draw("▩                                ▩", POS(24, 16), 1);
			RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(24, 17), 1);
			RenderMgr::SetCursorPosition(34, 15);
			cin >> m_name;


			
			Menu menu(POS(26, 15));
			menu.Add("             확  인             ");
			menu.Add("             취  소             ");
			
			switch (menu.Update())
			{
			case 0: exit = false; break;
			case 1: break;
			}
		}
	}

	bool IsCollided(Character* target)
	{
		POS pos = target->GetPosition();
		int length = 0;
		if (target->GetTag() == RABBIT)length = 2;
		if (target->GetTag() == BOAR)length = 3;
		if (target->GetTag() == BULL)length = 4;

		for (int i = 0; i < 5; i++)
		{
			int checker = i;
			if (m_position.x + i == pos.x&&m_See == SEE_RIGHT)return true;
			if (m_position.x - i-4 == pos.x&&m_See == SEE_LEFT)return true;
		}
		return false;
		
	}


	void DrawCharacter(int scene)
	{


		if (scene == 0)RenderMgr::SetColor(COLOR_BLACK, COLOR_SKY);
		if (scene == 1)RenderMgr::SetColor(COLOR_WHITE, COLOR_BLACK);

		int length = 0;
		if (m_See == SEE_RIGHT)length = 4;
		if (m_See == SEE_LEFT)length = -4;

		

		if(scene!=1)RenderMgr::Draw("↑", POS(m_position.x + length, m_position.y + 1), 1);

		if (m_pPlayer->GetTag() == HUMAN)
		{
			RenderMgr::Draw("ⓗ", POS(m_position.x, m_position.y), 1);
		}
		else if (m_pPlayer->GetTag() == ELF)
		{
			RenderMgr::Draw("|ⓔ|", POS(m_position.x-1, m_position.y), 1);
		}
		else if (m_pPlayer->GetTag() == DWARF)
		{
			RenderMgr::Draw("┌ⓓ┐", POS(m_position.x -2, m_position.y + 1), 1);
		}
		if (m_pPlayer->GetTag() != DWARF)RenderMgr::Draw("┌||┐", POS(m_position.x -2, m_position.y + 1), 1);
		RenderMgr::Draw(" /| ", POS(m_position.x-1 , m_position.y + 2), 1);
	}

	void Swing()
	{
		int length = 0;
		CHAR Text[3] = {};
		if (m_See == SEE_RIGHT)
		{
			length = 4;
			sprintf(Text, "→");
		}
		else if (m_See == SEE_LEFT)
		{
			length = -4;
			sprintf(Text, "←");
		}
		RenderMgr::Draw(Text, POS(m_position.x + length, m_position.y + 1), 1);
		Sleep(100);

	}



	void RemoveDrawCharacter(int Scene)
	{
		if (Scene == 0)RenderMgr::SetColor(COLOR_SKY, COLOR_SKY);
		if (Scene == 1)RenderMgr::SetColor(COLOR_DARK_YELLOW, COLOR_DARK_YELLOW);

		RenderMgr::Draw("     ", POS(m_position.x-1, m_position.y), 1);
		RenderMgr::Draw("     ", POS(m_position.x-1 , m_position.y + 1), 1);
		RenderMgr::Draw("     ", POS(m_position.x-1 , m_position.y + 2), 1);

	}

	void ShowPlayer()
	{
		RenderMgr::ClearScreen();
		cout << "이름 : " << GetName() << endl;
		cout << "종족이름 : " << GetRace() << endl;
		cout << "life : " << GetLife() << endl;
		cout << "attack : " << GetAttack() << endl;
		cout << "defense : " << GetDefense() << endl;
		cout << "벌목 : " << GetLumberjacking() << endl;
		cout << "사냥 : " << GetHunting() << endl;
		cout << "채광 : " << GetMining() << endl;
	}

	int SetBonusResource(Character* pPlayer, CHARACTER_TAG tag)
	{
		int bonus = 0;
		if (pPlayer->GetTag() == HUMAN&&tag == WOOD)bonus++;
		if (pPlayer->GetTag() == ELF  &&tag == RABBIT&&tag == BOAR&&tag == BULL)bonus++;
		if (pPlayer->GetTag() == DWARF&&tag == STONE)bonus++;
		return bonus;
	}

	void LackResource()
	{
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
		RenderMgr::Draw("            -알  림-            ", POS(25, 10), 1);
		RenderMgr::Draw("        재료가 부족합니다.      ", POS(25, 11), 1);
		Sleep(2000);
		Menu menu(POS(0, 0));
		menu.RemoveMenu(4);
	}

	void LackInventory()
	{
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
		RenderMgr::Draw("            -알  림-            ", POS(25, 10), 1);
		RenderMgr::Draw("        가방이 꽉찻습니다.      ", POS(25, 11), 1);
		Sleep(2000);
		Menu menu(POS(0, 0));
		menu.RemoveMenu(4);

	}

	void LackStorage()
	{
		Menu menu(POS(0, 0));
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
		RenderMgr::Draw("            -알  림-            ", POS(25, 10), 1);
		RenderMgr::Draw("      창고가 가득찼습니다.      ", POS(25, 11), 1);
		Sleep(2000);
		
		menu.RemoveMenu(4);
	}

	void CreateSuccess()
	{
		Menu menu(POS(0, 0));
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 9), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 10), 1);
		RenderMgr::Draw("▩                                ▩", POS(23, 11), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(23, 12), 1);
		RenderMgr::Draw("            -알  림-            ", POS(25, 10), 1);
		RenderMgr::Draw("      제작을 성공하였습니다.    ", POS(25, 11), 1);
		Sleep(2000);

		menu.RemoveMenu(4);
	}

	void CheckingCreateItem(ITEM_TAG tag, int WOOD, int ROCK, int Leather)
	{
		
			if (m_pInventory->CheckItem(ITEM_NONE) <= 0 )
			{
				LackInventory();
			}
			else if (m_pInventory->CheckItem(ITEM_WOOD) >= WOOD && m_pInventory->CheckItem(ITEM_ROCK) >= ROCK&& m_pInventory->CheckItem(ITEM_ROCK) >= Leather)
			{
				CreateSuccess();
				m_pInventory->Remove(ITEM_WOOD, WOOD);
				m_pInventory->Remove(ITEM_ROCK, ROCK);
				m_pInventory->Remove(ITEM_LEATHER, Leather);
				m_pInventory->Add(tag);
			}
			else
			{
				LackResource();
			}
	}
};

