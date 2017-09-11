#pragma once
#include "SceneMgr.h"
class ExitScene :
	public IScene
{
public:
	void OnEnter();
	void OnUpdate();
	void OnExit();
};

