#include "SceneMgr.h"
#include "StartScene.h"
#include "PlayerScene.h"
#include "ExitScene.h"
#include "InfoScene.h"
#include "HomeScene.h"
#include "FieldScene.h"
#include "ForestScene.h"
#include "Constant.h"
#include "CharacterDB.h"
#include "ObjectMgr.h"
#include "ItemDB.h"

RenderMgr*		RenderMgr::m_pInstance = NULL;
SceneMgr*		SceneMgr::m_pInstance = NULL;
CharacterDB*	CharacterDB::m_pInstance = NULL;
ObjectMgr*		ObjectMgr::m_pInstance = NULL;
ItemDB*			ItemDB::m_pInstance = NULL;

void main()
{
	SceneMgr::Instance()->Register(SCENE_START, new StartScene);
	SceneMgr::Instance()->Register(SCENE_PLAYER, new PlayerScene);
	SceneMgr::Instance()->Register(SCENE_EXIT, new ExitScene); 
	SceneMgr::Instance()->Register(SCENE_INFOSCENE, new InfoScene);
	SceneMgr::Instance()->Register(SCENE_HOME, new HomeScene);
	SceneMgr::Instance()->Register(SCENE_FIELD, new FieldScene);
	SceneMgr::Instance()->Register(SCENE_FOREST, new ForestScene);
	SceneMgr::Instance()->ChangeScene(SCENE_START);

	while (true)
	{
		SceneMgr::Instance()->Update();
		/*printf("\a");*/




		if (SceneMgr::Instance()->GetCurrentScene()->GetID() == SCENE_EXIT)
		{
			SceneMgr::Instance()->Update();
			break;
		}
	} 



}