#include "stdafx.h"
#include "Level3.h"

void Level3::Init()
{
	// UI
	SetStartText("chapter three: anxiety");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	for (int i = 0; i < 6; i++)
	{
		// They'll move randomly, so no need to place them super carefully. Just start middle left and end middle right.
		Anxiety* anxiety = new Anxiety(50.0f + (170.05f * i), 400.0f, 20.0f, 0.2f, vec2<float>(50.0f + (170.05f * i), 400.0f), vec2<float>(50.0f + (170.05f * i), 700.0f));
		AddToEnemyList(anxiety);
	}

	LevelScene::Init();
}

void Level3::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level3::Render()
{
	LevelScene::Render();
}

void Level3::Shutdown()
{
	LevelScene::Shutdown();
}
