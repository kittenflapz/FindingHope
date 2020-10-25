#include "stdafx.h"
#include "Level7.h"

void Level7::Init()
{
	// UI
	SetStartText("chapter seven");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 668.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(512.0f, 384.0f));
	CreateHope();

	// Enemies
	vec2<float> centre(512.0f, 384.0f);
	// Anxieties
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Anxiety* anxiety = new Anxiety(220.0f + (i * 300.0f), 180.0f + (j * 400.0f), 20.0f, 0.2f, vec2<float>(220.0f + (i * 300.0f), 180.0f + (j * 400.0f)), centre);
			AddToEnemyList(anxiety);
		}
	}

	// Perfectionisms
	// Patrolling in circle
	std::list<vec2<float>> patrolPoints = {};
	float angle = 2.0f * M_PI / 20;
	int radius = 100;
	for (int i = 0; i < 20 + 1; i++)
	{
		if (i > 0)
		{
			patrolPoints.push_back(vec2<float>(512.0f + radius * sin(i * angle), 384.0f + radius * cos(i * angle)));
		}
	}
	Perfectionism* perfectionism = new Perfectionism(512.0f, 384.0f, 20.0f, 0.3f);
	perfectionism->SetPatrolPoints(patrolPoints);
	AddToEnemyList(perfectionism);

	perfectionism = new Perfectionism(512.0f, 384.0f, 20.0f, 0.3f);
	patrolPoints.reverse();
	perfectionism->SetPatrolPoints(patrolPoints);
	AddToEnemyList(perfectionism);



	LevelScene::Init();

}

void Level7::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level7::Render()
{
	LevelScene::Render();
}

void Level7::Shutdown()
{
	LevelScene::Shutdown();
}
