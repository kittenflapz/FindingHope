#include "stdafx.h"
#include "Level1.h"



void Level1::Init()
{
	// Player
	SetPlayerStartPosition(vec2<float> (APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float> (APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	Grief* grief = new Grief(106.0f, 100.0f, 20.0f, 0.5f);
	AddToEnemyList(grief);

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
