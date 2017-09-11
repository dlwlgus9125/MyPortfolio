#include "ExitScene.h"
#include "RenderMgr.h"

using namespace std;

void ExitScene::OnEnter()
{

}

void ExitScene::OnUpdate()
{
	for (int i = 0; i < 5; i++)
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
		RenderMgr::SetCursorPosition(28, 10);
		RenderMgr::Draw("Thank you for Playing", 0);
		for (int j = 0; j < i; j++)RenderMgr::Draw(".", 0);
		Sleep(500);
	}
	RenderMgr::SetCursorPosition(20, 15);
}

void ExitScene::OnExit()
{

}