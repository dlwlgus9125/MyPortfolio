#pragma once
#include "SceneMgr.h"
#include "RenderMgr.h"
#include "Menu.h"
#include "Constant.h"

class StartScene : public IScene
{
public:
	void OnEnter();
	void OnUpdate();
	void OnExit();


	void Opening();


};