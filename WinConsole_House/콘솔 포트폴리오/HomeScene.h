#pragma once
#include "SceneMgr.h"
#include "RenderMgr.h"
#include "Menu.h"
#include "Constant.h"
#include "ObjectMgr.h"
#include "CharacterDB.h"
#include "Math.h"
#include "Bag.h"
#include "Storage.h"
#include "Status.h"


class HomeScene :
	public IScene
{
public:
	void OnEnter();
	void OnUpdate();
	void OnExit();
	void DrawEdge();
	void DrawBackGround();
	void DrawHouse(Character* pPlayer);
	void Confirm();
	void HouseSleep();
	void CreateItem();
	bool exitConfirm();
	bool Upgrade();
	void UpgradeSuccess();
};

