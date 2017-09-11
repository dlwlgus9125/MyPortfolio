#pragma once
#include "SceneMgr.h"
#include "RenderMgr.h"
#include "Menu.h"
#include "Constant.h"
#include "ObjectMgr.h"
#include "CharacterDB.h"
#include "Math.h"
#include "Bag.h"
#include "Status.h"


class FieldScene :
	public IScene
{
public:
	void OnEnter();
	void OnUpdate();
	void OnExit();
	bool CheckHealth();
	void DrawEdge();
	void DrawBackGround();
	bool exitConfirm();
};

