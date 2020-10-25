#include "stdafx.h"
#include "Level2.h"


void Level2::Init()
{
	// UI
	SetStartText("chapter two: fear");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	bool startLeft = false;
	for (int i = 0; i < 3; i++)
	{
		Fear* fear = new Fear(512.0f, 240.0f + (i * 160.0f), 20.0f, 0.5f, vec2<float>(startLeft ? 100.0f : 900.0f, 240.0f + (i * 160.0f)), vec2<float>(startLeft ? 900.0f : 100.0f, 240.0f + (i * 160.0f)));
		startLeft = !startLeft;
		AddToEnemyList(fear);
	}

	LevelScene::Init();
}

void Level2::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level2::Render()
{
	LevelScene::Render();
}

void Level2::Shutdown()
{
	LevelScene::Shutdown();
}
