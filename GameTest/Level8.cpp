#include "stdafx.h"
#include "Level8.h"

void Level8::Init()
{
	// UI
	SetStartText("chapter eight");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.2f, 668.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(312.0f, 150.0f));
	CreateHope();

	// Enemies
	// Griefs
	// Row 1
	for (int i = 0; i < 20; i++)
	{
		Grief* grief = new Grief(200.0f + (i * 40.0f), 490.0f, 20.0f, 0.5f);
		AddToEnemyList(grief);
	}

	// Row 2

	for (int i = 0; i < 17; i++)
	{
		Grief* grief = new Grief(50.0f + (i * 40.0f), 320.0f, 20.0f, 0.5f);
		AddToEnemyList(grief);
	}

	// Fear

	Fear* fear = new Fear(870.0f, 100.0f, 20.0f, 0.3f, vec2<float>(870.0f, 150.0f), vec2<float>(470.0f, 150.0f));
	AddToEnemyList(fear);

	LevelScene::Init();

}

void Level8::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level8::Render()
{
	LevelScene::Render();
}

void Level8::Shutdown()
{
	LevelScene::Shutdown();
}
