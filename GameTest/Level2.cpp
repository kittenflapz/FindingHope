#include "stdafx.h"
#include "Level2.h"


void Level2::Init()
{
	// Player
	startPosition = vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f);
	player = new Player(startPosition.x, startPosition.y, 50.0f, 50.0f, 0.05f);

	// Goal
	hope = new Hope(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f, 20.0f, 0.5f);

	// UI
	lightFuelBar = new LightFuelBar(APP_INIT_WINDOW_WIDTH - 50.0f, APP_INIT_WINDOW_HEIGHT * 0.33f, 20.0f, APP_INIT_WINDOW_HEIGHT * 0.33f);
	light = new Light(512.0f, 384.0f);
	light->Init();



	// Enemies
	Fear* fear1 = new Fear(156.0f, 300.0f, 20.0f, 0.5f, vec2<float> (156.0f, 300.0f), vec2<float>(856.0f, 300.0f));
	Fear* fear2 = new Fear(856.0f, 550.0f, 20.0f, 0.5f, vec2<float>(856.0f, 550.0f), vec2<float>(156.0f, 550.0f));

	fears.push_back(fear1);
	fears.push_back(fear2);

}

void Level2::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);

	if (!restartLevel)
	{
		player->Update(deltaTime);
		hope->Update(deltaTime);

		if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, false))
		{
			if (lightFuelBar->GetCurrentFuel() > 0)
			{
				SetLightOn(true);
				lightFuelBar->DecrementFuel();
			}
		}
		else
		{
			SetLightOn(false);
		}

		for (int i = 0; i < fears.size(); i++)
		{
			fears[i]->Patrol();
			fears[i]->Update(deltaTime);
			if (collisionChecker.PlayerEmotion(player, fears[i]))
			{
				App::PlaySound(".\\Sounds\\Pop.wav", false);
				restartLevel = true;
				TheSceneManager::Instance()->LoseLife();
			}
		}

		if (collisionChecker.PlayerEmotion(player, hope) && !hasWon)
		{
			App::PlaySound(".\\Sounds\\Bells.wav", false);
			hasWon = true;
		}

	}
	else
	{
		player->SetPosition(startPosition.x, startPosition.y);
		restartLevel = false;
	}
}

void Level2::Render()
{
	if (hasWon)
	{
		if (timerForWinMessage < timeToWaitOnWinMessage)
		{
			std::string scoreString = "Hope: You've found me! Thank you!";
			App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.5f, scoreString.c_str());
			timerForWinMessage++;
		}
		else
		{
			TheSceneManager::Instance()->ChangeSceneState(SceneState::LEVEL3_SCENE);
		}

	}
	else
	{
		if (LightIsOn())
		{
			player->Render();
			hope->Render();
			light->Render();
			lightFuelBar->Render();
			glClearColor(0.074f, 0.035f, 0.07f, 1.0f);

			for (int i = 0; i < fears.size(); i++)
			{
				fears[i]->Render();
			}
		}
		else
		{
			lightFuelBar->Render();
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}

	int lives = TheSceneManager::Instance()->GetLivesLeft();
	std::string livesString = "Lives: " + std::to_string(lives);
	App::Print(100.0f, APP_INIT_WINDOW_HEIGHT - 100.0f, livesString.c_str());
}

void Level2::Shutdown()
{
	delete player;
	for (int i = 0; i < fears.size(); i++)
	{
		delete fears[i];
	}
	delete hope;
	delete light;
}
