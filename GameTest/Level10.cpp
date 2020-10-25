#include "stdafx.h"
#include "Level10.h"

void Level10::Init()
{
	// UI
	SetStartText("chapter ten");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.475f, 668.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(512.0f, 384.0f));
	CreateHope();


	// Fears
	// start bottom left patrol to top right
	Fear* fear = new Fear(0.0f, 0.0f, 20.0f, 0.5f, vec2<float>(0.0f, 0.0f), vec2<float>(1024.0f, 768.0f));
	AddToEnemyList(fear);
	// start bottom right patrol to top left
	fear = new Fear(1024.0f, 0.0f, 20.0f, 0.5f, vec2<float>(1024.0f, 0.0f), vec2<float>(0.0f, 768.0f));
	AddToEnemyList(fear);

	// Perfectionism

	std::list<vec2<float>> patrolPoints; 
	std::list<vec2<float>> reversedPatrolPoints; 
	bool reversed = false;
	for (int i = 1; i < 5; i++)
	{
		float angle = 2.0f * M_PI / 20;
		int radius = 60.0f * i;
		for (int j = 0; j < 20 + 1; j++)
		{
			if (j > 0)
			{
				patrolPoints.push_back(vec2<float>(512.0f + radius * sin(j * angle), 384.0f + radius * cos(j * angle)));
			}
		}
		if (reversed)
		{
			patrolPoints.reverse();
		}

		Perfectionism* perfectionism = new Perfectionism(512.0f, 384.0f, 20.0f, 0.4f);
		perfectionism->SetPatrolPoints(patrolPoints);
		AddToEnemyList(perfectionism);
		reversed = !reversed;
		patrolPoints.clear();
	}



	LevelScene::Init();

}

void Level10::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level10::Render()
{
	LevelScene::Render();
}

void Level10::Shutdown()
{
	LevelScene::Shutdown();
}
