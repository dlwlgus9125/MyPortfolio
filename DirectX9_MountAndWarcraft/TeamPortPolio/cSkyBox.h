#pragma once
#include <d3dx9tex.h>
#include <d3dx9math.h>

class cCamera;

enum SKYBOX_FACE
{
	SKYBOX_FACE_TOP,
	SKYBOX_FACE_BOTTOM,
	SKYBOX_FACE_LEFT,
	SKYBOX_FACE_RIGHT,
	SKYBOX_FACE_FRONT,
	SKYBOX_FACE_BACK,
};


class cSkyBox
{
public:
	cSkyBox();
	~cSkyBox();

	// object�� ���� �Լ�

	// �ʱ�ȭ + render state ����
	void Setup(float sizeX, float sizeY, float sizeZ, char* szFolder, char* szExtension);
	void Setup_Texture(char* szFolder, char* szExtension);

	// Projection, View, World Matrix�� ���� ó��
	void Update(cCamera* pCamera);

	// Render
	void Render();

protected:
	vector<ST_PT_VERTEX>	m_vecVertex;
	vector<DWORD>			m_vecIndex;

	map<SKYBOX_FACE, LPDIRECT3DTEXTURE9>			m_mapCurrentTexture;
};