#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	m_currentScene = NULL;
}

SceneMgr::~SceneMgr()
{

}

SceneMgr* SceneMgr::Instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new SceneMgr;
	}
	return m_pInstance;
}

IScene* SceneMgr::FindScene(int sceneID)
{
	for (int i = 0; i < m_sceneList.Count(); i++)
	{
		IScene* scene = m_sceneList.GetData(i);
		if (scene->GetID() == sceneID) return scene;
	}
	return NULL;
}

void SceneMgr::Register(int sceneID, IScene* pScene)
{
	if (FindScene(sceneID) == NULL)
	{
		pScene->setChecker();
		pScene->SetID(sceneID);
		m_sceneList.Add(pScene);
	}
}

void SceneMgr::ChangeScene(int sceneID)
{
	IScene* nextScene = FindScene(sceneID);
	if (nextScene != NULL)
	{
		if (m_currentScene != NULL)
		{
			m_currentScene->OnExit();
		}

		m_currentScene = nextScene;
		m_currentScene->OnEnter();
	}
}

void SceneMgr::Update()
{
	if (m_currentScene != NULL)
	{
		m_currentScene->OnUpdate();
	}
}