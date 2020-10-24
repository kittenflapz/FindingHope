#include "stdafx.h"
#include "Level5.h"

void Level5::Init()
{

	LevelScene::Init();
	// Player
	startPosition = vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f);
	player = new Player(startPosition.x, startPosition.y, 50.0f, 50.0f, 0.05f);

	// Goal
	hope = new Hope(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f, 20.0f, 0.5f);

	// UI
	lightFuelBar = new LightFuelBar(APP_INIT_WINDOW_WIDTH - 50.0f, APP_INIT_WINDOW_HEIGHT * 0.33f, 20.0f, APP_INIT_WINDOW_HEIGHT * 0.33f);
	light = new Light(512.0f, 384.0f);
	light->Init();

	// Enemies
	anxiety = new Anxiety(400.0f, 400.0f, 20.0f, 0.2f, vec2<float>(450.0f, 400.0f), vec2<float>(650.0f, 400.0f));
	
}

void Level5::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
	if (!restartLevel)
	{
		player->Update(deltaTime);
		hope->Update(deltaTime);
		anxiety->PatrolRandomPoints();
		anxiety->Update(deltaTime);

		if (collisionChecker.PlayerEmotion(player, anxiety))
		{
			App::PlaySound(".\\Sounds\\Pop.wav", false);
			restartLevel = true;
			TheSceneManager::Instance()->LoseLife();
		}

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

void Level5::Render()
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
			TheSceneManager::Instance()->ChangeSceneState(SceneState::WIN_SCENE);
		}

	}
	else
	{
		if (LightIsOn())
		{
			player->Render();
			hope->Render();
			anxiety->Render();
			light->Render();
			lightFuelBar->Render();
			glClearColor(0.074f, 0.035f, 0.07f, 1.0f);

		}
		else
		{
			lightFuelBar->Render();
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
	LevelScene::Render();
}

void Level5::Shutdown()
{
	delete player;
	delete hope;
	delete light;
	delete anxiety;
}
