#pragma once

#include "SceneMgr.h"
#include "RenderMgr.h"
#include "Menu.h"
#include "Constant.h"
#include "ObjectMgr.h"
#include "CharacterDB.h"

class PlayerScene : public IScene
{
	int m_cursor;
public:
	void OnEnter();
	void OnUpdate();
	void OnExit();

	void ShowRaceInfo(int cursor);

	bool Confirm();
};