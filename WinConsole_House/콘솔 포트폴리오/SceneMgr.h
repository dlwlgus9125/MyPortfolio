#pragma once
#include "ArrayList.h"


class IScene
{
protected:
	int m_id;
	int m_checker;
public:
	int GetID(){ return m_id; }
	void SetID(int id){ m_id = id; }
	void setChecker(){ m_checker = 0; }
	virtual void OnEnter(){}
	virtual void OnUpdate(){}
	virtual void OnExit(){}
	virtual void VisitChecker(){};
};

class SceneMgr
{
	static SceneMgr* m_pInstance;

	ArrayList<IScene*> m_sceneList;

	IScene* m_currentScene;

	IScene* FindScene(int sceneID);

	SceneMgr();
	~SceneMgr();
public:
	static SceneMgr* Instance();
	void Register(int sceneID, IScene* pScene);
	void ChangeScene(int sceneID);
	void Update();
	IScene* GetCurrentScene(){ return m_currentScene; }
	
};

