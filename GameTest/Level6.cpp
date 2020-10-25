#include "stdafx.h"
#include "Level6.h"

void Level6::Init()
{
	// UI
	SetStartText("chapter six");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.8f, 668.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.3f, 100.0f));
	CreateHope();

	// Enemies
	// Griefs
	bool isOffset = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Grief* grief = new Grief(100.0f + (200.0f * i), 180.0f + ((isOffset ? 150.0f : 120.0f) * j), 20.0f, 0.5f);
			AddToEnemyList(grief);
		}
		isOffset = !isOffset;
	}

	// Fears
	Fear* fear = new Fear(350.0f, 180.0f, 20.0f, 0.5f, vec2<float>(350.0f, 150.0f), vec2<float>(350.0f, 650.0f));
	AddToEnemyList(fear);

	fear = new Fear(640.0f, 180.0f, 20.0f, 0.5f, vec2<float>(640.0f, 650.0f), vec2<float>(640.0f, 150.0f));
	AddToEnemyList(fear);

	

	LevelScene::Init();

}

void Level6::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level6::Render()
{
	LevelScene::Render();
}

void Level6::Shutdown()
{
	LevelScene::Shutdown();
}
