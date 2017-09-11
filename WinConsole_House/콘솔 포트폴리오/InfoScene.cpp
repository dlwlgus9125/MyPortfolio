#include "InfoScene.h"
#include "RenderMgr.h"

using namespace std;

void InfoScene::OnEnter()
{

}

void InfoScene::OnUpdate()
{
	for (int i = 0; i < 4; i++)
	{

		RenderMgr::ClearScreen();
		RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
		RenderMgr::Draw("¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì", POS(12, 6), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 7), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 8), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 9), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 10), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 11), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 12), 1);
		RenderMgr::Draw("¢Ì                                                    ¢Ì", POS(12, 13), 1);
		RenderMgr::Draw("¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì", POS(12, 14), 1);

		RenderMgr::SetColor(COLOR_DARK_GREEN, COLOR_BLACK);
		RenderMgr::SetCursorPosition(32, 7+i);
		RenderMgr::Draw("Develope by EZ", 0);
		Sleep(400);
	}
	RenderMgr::EndLine(5);
	RenderMgr::SetCursorPosition(20, 15);
	RenderMgr::PauseScreen();
	SceneMgr::Instance()->ChangeScene(SCENE_START);
}

void InfoScene::OnExit()
{

}