#include "PlayerScene.h"


void PlayerScene::OnEnter()
{
	m_cursor = 0;
}

void PlayerScene::OnUpdate()
{
	RenderMgr::ClearScreen();
	RenderMgr::SetColor(COLOR_RED, COLOR_BLACK);
	RenderMgr::SetCursorPosition(0, 0);
	RenderMgr::Draw("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�{����ó}�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("��                                                                          ��", 1);
	RenderMgr::Draw("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�", 1);


	Sleep(200);
	ShowRaceInfo(m_cursor);

	switch (Key::GetInput())
	{
	case Key::LEFT:   m_cursor--; break;
	case Key::RIGHT:  m_cursor++; break;
	case Key::ENTER:

		if (Confirm())
		{
			CharacterData* selectData = NULL;
			switch (m_cursor)
			{
			case 0:selectData = CharacterDB::GetData(HUMAN); break;
			case 1:selectData = CharacterDB::GetData(ELF); break;
			case 2:selectData = CharacterDB::GetData(DWARF); break;
			}
			ObjectMgr::CreatePlayer(selectData)->SetPlayer(m_cursor);
			SceneMgr::Instance()->ChangeScene(SCENE_HOME);
		} break;

	case Key::ESC:SceneMgr::Instance()->ChangeScene(SCENE_START); break;
	}

	m_cursor = Math::Clamp(m_cursor, 0, 2);





}

void PlayerScene::OnExit()
{

}

bool PlayerScene::Confirm()
{
	RenderMgr::Draw("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�", POS(24, 14), 1);
	RenderMgr::Draw("��                                ��", POS(24, 15), 1);
	RenderMgr::Draw("��                                ��", POS(24, 16), 1);
	RenderMgr::Draw("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�", POS(24, 17), 1);
	Menu menu(POS(26, 15));
	menu.Add("             Ȯ  ��             ");
	menu.Add("             ��  ��             ");



	switch (menu.Update())
	{
	case 0: return true;
	case 1: return false;
	}
}

void PlayerScene::ShowRaceInfo(int cursor)
{
	if (cursor == 0)
	{
		RenderMgr::SetColor(COLOR_BLUE, COLOR_BLACK);
		RenderMgr::Draw("   ��    ��   ��      ��   ��      ��        ��       ��        ��", POS(5, 4), 1);
		RenderMgr::Draw("   ��    ��   ��      ��   �̢�  �̢�      ��  ��     �̢�      ��", POS(5, 5), 1);
		RenderMgr::Draw("   ��    ��   ��      ��   ��  ��  ��    ��      ��   �� ��     ��", POS(5, 6), 1);
		RenderMgr::Draw("   �̢̢̢�   ��      ��   ��      ��    �̢̢̢̢�   ��   ��   ��", POS(5, 7), 1);
		RenderMgr::Draw("   ��    ��   ��      ��   ��      ��    ��      ��   ��     �� ��", POS(5, 8), 1);
		RenderMgr::Draw("   ��    ��   ��      ��   ��      ��    ��      ��   ��      �̢�", POS(5, 9), 1);
		RenderMgr::Draw("   ��    ��     �̢̢�     ��      ��    ��      ��   ��        ��", POS(5, 10), 1);

		RenderMgr::SetColor(COLOR_WHITE, COLOR_BLACK);
		RenderMgr::Draw("  ���� : ���� �ʿ��Ѱ�.", POS(8, 16), 1);
		RenderMgr::Draw("  Ư¡ : ����� Ÿ�������� ���縦 �� ���� �� �ִ�.", POS(8, 17), 1);
	}
	else if (cursor == 1)
	{
		RenderMgr::SetColor(COLOR_GREEN, COLOR_BLACK);
		RenderMgr::Draw("              �̢̢̢̢�   ��            �̢̢̢̢̢�         ", POS(5, 4), 1);
		RenderMgr::Draw("              ��           ��            ��                   ", POS(5, 5), 1);
		RenderMgr::Draw("              ��           ��            ��                   ", POS(5, 6), 1);
		RenderMgr::Draw("              �̢̢̢̢�   ��            �̢̢̢̢̢�         ", POS(5, 7), 1);
		RenderMgr::Draw("              ��           ��            ��                   ", POS(5, 8), 1);
		RenderMgr::Draw("              ��           ��            ��                   ", POS(5, 9), 1);
		RenderMgr::Draw("              �̢̢̢̢�   �̢̢̢̢̢�  ��                   ", POS(5, 10), 1);

		RenderMgr::SetColor(COLOR_WHITE, COLOR_BLACK);
		RenderMgr::Draw("  ���� : �Ͱ� �� �ΰ��� ����.", POS(8, 16), 1);
		RenderMgr::Draw("  Ư¡ : ��ɽ� ������ �� ���� �� �ִ�.", POS(8, 17), 1);
	}
	else if (cursor == 2)
	{
		RenderMgr::SetColor(COLOR_GRAY, COLOR_BLACK);
		RenderMgr::Draw("  �̢̢̢�     ��        ��       ��       �̢̢̢�     �̢̢̢̢�", POS(5, 4), 1);
		RenderMgr::Draw("  ��      ��   ��        ��     ��  ��     ��      ��   ��        ", POS(5, 5), 1);
		RenderMgr::Draw("  ��      ��   ��        ��   ��      ��   ��      ��   ��        ", POS(5, 6), 1);
		RenderMgr::Draw("  ��      ��   ��        ��   �̢̢̢̢�   �̢̢̢�     �̢̢̢̢�", POS(5, 7), 1);
		RenderMgr::Draw("  ��      ��   ��   ��   ��   ��      ��   ��      ��   ��        ", POS(5, 8), 1);
		RenderMgr::Draw("  ��      ��   �� ��  �� ��   ��      ��   ��      ��   ��        ", POS(5, 9), 1);
		RenderMgr::Draw("  �̢̢̢�      ��      ��    ��      ��   ��      ��   ��        ", POS(5, 10), 1);

		RenderMgr::SetColor(COLOR_WHITE, COLOR_BLACK);
		RenderMgr::Draw("  ���� : Ű�� �۰� �β��� �ΰ��� ����.", POS(8, 16), 1);
		RenderMgr::Draw("  Ư¡ : ä���� Ÿ�������� �ϼ��� �� ���� �� �ִ�.", POS(8, 17), 1);
	}






}