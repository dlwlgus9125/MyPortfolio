#include "StartScene.h"

void StartScene::OnEnter()
{

}

void StartScene::OnUpdate()
{
	
	
	Opening();
	Menu menu(POS(14, 15));
	menu.Add("                       시  작                       ");
	menu.Add("                       제작자                       ");
	menu.Add("                       종  료                       ");
	 

	
	switch (menu.Update())
	{
	case 0: SceneMgr::Instance()->ChangeScene(SCENE_PLAYER); break;
	case 1: SceneMgr::Instance()->ChangeScene(SCENE_INFOSCENE); break;
	case 2: SceneMgr::Instance()->ChangeScene(SCENE_EXIT); break;
	}
}

void StartScene::OnExit()
{
}

void StartScene::Opening()
{

	
	
	for (int i = 0; i < 30; i++)
	{
		RenderMgr::ClearScreen();
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(12, 6), 1);
		RenderMgr::Draw("▩                                                    ▩", POS(12, 7), 1);
		RenderMgr::Draw("▩   ▩    ▩  ▩▩▩▩  ▩    ▩  ▩▩▩▩  ▩▩▩▩ ▩", POS(12, 8), 1);
		RenderMgr::Draw("▩   ▩    ▩  ▩    ▩  ▩    ▩  ▩        ▩       ▩", POS(12, 9), 1);
		RenderMgr::Draw("▩   ▩▩▩▩  ▩    ▩  ▩    ▩  ▩▩▩▩  ▩▩▩▩ ▩", POS(12, 10), 1);
		RenderMgr::Draw("▩   ▩    ▩  ▩    ▩  ▩    ▩        ▩  ▩       ▩", POS(12, 11), 1);
		RenderMgr::Draw("▩   ▩    ▩  ▩▩▩▩  ▩▩▩▩  ▩▩▩▩  ▩▩▩▩ ▩", POS(12, 12), 1);
		RenderMgr::Draw("▩                                              v0.01 ▩", POS(12, 13), 1);
		RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(12, 14), 1);


		RenderMgr::SetColor(COLOR_DARK_GREEN, COLOR_BLACK);
		RenderMgr::Draw("▩    ▩", POS(16, 8), 1);
		RenderMgr::Draw("▩    ▩", POS(16, 9), 1);
		RenderMgr::Draw("▩▩▩▩", POS(16, 10), 1);
		RenderMgr::Draw("▩    ▩", POS(16, 11), 1);
		RenderMgr::Draw("▩    ▩", POS(16, 12), 1);

		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_BLACK);

		RenderMgr::Draw("▩▩▩▩", POS(26, 8), 1);
		RenderMgr::Draw("▩    ▩", POS(26, 9), 1);
		RenderMgr::Draw("▩    ▩", POS(26, 10), 1);
		RenderMgr::Draw("▩    ▩", POS(26, 11), 1);
		RenderMgr::Draw("▩▩▩▩", POS(26, 12), 1);

		RenderMgr::SetColor(COLOR_DARK_GREEN, COLOR_BLACK);
		RenderMgr::Draw("▩    ▩", POS(36, 8), 1);
		RenderMgr::Draw("▩    ▩", POS(36, 9), 1);
		RenderMgr::Draw("▩    ▩", POS(36, 10), 1);
		RenderMgr::Draw("▩    ▩", POS(36, 11), 1);
		RenderMgr::Draw("▩▩▩▩", POS(36, 12), 1);

		RenderMgr::SetColor(COLOR_DARK_RED, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩", POS(46, 8), 1);
		RenderMgr::Draw("▩",       POS(46, 9), 1);
		RenderMgr::Draw("▩▩▩▩", POS(46, 10), 1);
		RenderMgr::Draw("      ▩", POS(46, 11), 1);
		RenderMgr::Draw("▩▩▩▩", POS(46, 12), 1);

		RenderMgr::SetColor(COLOR_DARK_GREEN, COLOR_BLACK);
		RenderMgr::Draw("▩▩▩▩", POS(56, 8), 1);
		RenderMgr::Draw("▩",       POS(56, 9), 1);
		RenderMgr::Draw("▩▩▩▩", POS(56, 10), 1);
		RenderMgr::Draw("▩",       POS(56, 11), 1);
		RenderMgr::Draw("▩▩▩▩", POS(56, 12), 1);
		RenderMgr::EndLine(4);

		Sleep(100);
	}
	RenderMgr::SetCursorPosition(20, 15);
	RenderMgr::PauseScreen();
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::Draw("▩                                                    ▩", POS(12, 15), 1);
	RenderMgr::Draw("▩                                                    ▩", POS(12, 16), 1);
	RenderMgr::Draw("▩                                                    ▩", POS(12, 17), 1);
	RenderMgr::Draw("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩", POS(12, 18), 1);
}
