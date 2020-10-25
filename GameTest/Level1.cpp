#include "stdafx.h"
#include "Level1.h"



void Level1::Init()
{
	// UI
	SetStartText("chapter one: grief");

	// Player
	SetPlayerStartPosition(vec2<float> (APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float> (APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	// Row 1
	for (int i = 0; i < 3; i++)
	{
		Grief* grief = new Grief(171.0f + (341.0f * i), 560.0f, 20.0f, 0.5f);
		AddToEnemyList(grief);
	}
	// Row 2
	for (int i = 0; i < 4; i++)
	{
		Grief* grief = new Grief(50.0f + (341.0f * i), 400.0f, 20.0f, 0.5f);
		AddToEnemyList(grief);
	}

	// Row 3
	for (int i = 0; i < 3; i++)
	{
		Grief* grief = new Grief(171.0f + (341.0f * i), 240.0f, 20.0f, 0.5f);
		AddToEnemyList(grief);
	}

	LevelScene::Init();
}

void Level1::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level1::Render()
{
	LevelScene::Render();
}

void Level1::Shutdown()
{
	LevelScene::Shutdown();
}
