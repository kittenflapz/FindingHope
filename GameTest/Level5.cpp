#include "stdafx.h"
#include "Level5.h"

void Level5::Init()
{
	// UI
	SetStartText("chapter five: helplessness");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	Helplessness* helplessness = new Helplessness(350.0f, 384.0f, 20.0f, 0.3f);
	AddToEnemyList(helplessness);
	helplessness = new Helplessness(650.0f, 384.0f, 20.0f, 0.3f);
	AddToEnemyList(helplessness);

	LevelScene::Init();
	
}

void Level5::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level5::Render()
{
	LevelScene::Render();
}

void Level5::Shutdown()
{
	LevelScene::Shutdown();
}
