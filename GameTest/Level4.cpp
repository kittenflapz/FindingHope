#include "stdafx.h"
#include "Level4.h"

void Level4::Init()
{
	// UI
	SetStartText("chapter four: perfectionism");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies

	// Patrolling in square
	std::list<vec2<float>> patrolPoints = { vec2<float>(150.0f, 550.0f), vec2<float>(150.0f, 250.0f), vec2<float>(750.0f, 250.0f), vec2<float>(750.0f, 550.0f) };
	Perfectionism* perfectionism = new Perfectionism(512.0f, 600.0f, 20.0f, 0.4f);
	perfectionism->SetPatrolPoints(patrolPoints);
	AddToEnemyList(perfectionism);

	// Patrolling in circle
	patrolPoints.clear();
	float angle = 2.0f * M_PI / 20;
	int radius = 100;
	for (int i = 0; i < 20 + 1; i++)
	{
		if (i > 0)
		{
			patrolPoints.push_back(vec2<float>(512.0f + radius * sin(i * angle), 384.0f + radius * cos(i * angle)));
		}
	}
	perfectionism = new Perfectionism(512.0f, 384.0f, 20.0f, 0.4f);
	perfectionism->SetPatrolPoints(patrolPoints);
	AddToEnemyList(perfectionism);

	// Patrolling in triangle
	patrolPoints.clear();
	patrolPoints = { vec2<float>(512.0f, 400.0f), vec2<float>(482.0f, 360.0f), vec2<float>(542.0f, 360.0f) };
	perfectionism = new Perfectionism(512.0f, 384.0f, 20.0f, 0.4f);
	perfectionism->SetPatrolPoints(patrolPoints);
	AddToEnemyList(perfectionism);

	LevelScene::Init();
}

void Level4::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level4::Render()
{
	LevelScene::Render();
}

void Level4::Shutdown()
{
	LevelScene::Shutdown();
}
