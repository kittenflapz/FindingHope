#include "stdafx.h"
#include "Level9.h"

void Level9::Init()
{
	// UI
	SetStartText("chapter nine");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.475f, 150.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(512.0f, 700.0f));
	CreateHope();

	// Enemies
	// Griefs
	// Column 1
	for (int i = 0; i < 30; i++)
	{
		Grief* grief = new Grief(442.0f, 40.0f * i, 20.0f, 0.5f);
		AddToEnemyList(grief);
	}

	// Column 2
	for (int i = 0; i < 30; i++)
	{
		Grief* grief = new Grief(582.0f, 0.0f + (40.0f * i), 20.0f, 0.5f);
		AddToEnemyList(grief);
	}

	// Fears
	// start bottom left patrol to top right
	Fear* fear = new Fear(0.0f, 0.0f, 20.0f, 0.5f, vec2<float>(0.0f, 0.0f), vec2<float>(1024.0f, 768.0f));
	AddToEnemyList(fear);
	// start bottom right patrol to top left
	fear = new Fear(1024.0f, 0.0f, 20.0f, 0.5f, vec2<float>(1024.0f, 0.0f), vec2<float>(0.0f, 768.0f));
	AddToEnemyList(fear);

	// Perfectionism

	std::list<vec2<float>> patrolPoints;
	float angle = 2.0f * M_PI / 20;
	int radius = 100;
	for (int i = 0; i < 20 + 1; i++)
	{
		if (i > 0)
		{
			patrolPoints.push_back(vec2<float>(512.0f + radius * sin(i * angle), 384.0f + radius * cos(i * angle)));
		}
	}
	Perfectionism* perfectionism = new Perfectionism(512.0f, 384.0f, 20.0f, 0.4f);
	perfectionism->SetPatrolPoints(patrolPoints);
	AddToEnemyList(perfectionism);

	

	LevelScene::Init();

}

void Level9::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level9::Render()
{
	LevelScene::Render();
}

void Level9::Shutdown()
{
	LevelScene::Shutdown();
}
