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

}

void Level2::Update(float deltaTime)
{
	if (!gameOver)
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

		/*for (int i = 0; i < griefs.size(); i++)
		{
			griefs[i]->Update(deltaTime);
			if (collisionChecker.PlayerEmotion(player, griefs[i]))
			{
				App::PlaySound(".\\Sounds\\Pop.wav", false);
				gameOver = true;
			}
		}*/

		if (collisionChecker.PlayerEmotion(player, hope) && !hasWon)
		{
			App::PlaySound(".\\Sounds\\Bells.wav", false);
			hasWon = true;
		}

	}
	else
	{
		player->SetPosition(startPosition.x, startPosition.y);
		gameOver = false;
	}
}

void Level2::Render()
{
	if (hasWon)
	{
		std::string scoreString = "Hope: You've found me! Thank you!";
		App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.5f, scoreString.c_str());
		//level1Done = true;
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

		/*	for (int i = 0; i < griefs.size(); i++)
			{
				griefs[i]->Render();
			}*/
		}
		else
		{
			lightFuelBar->Render();
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
}

void Level2::Shutdown()
{
	delete player;
	//for (int i = 0; i < griefs.size(); i++)
	//{
	//	delete griefs[i];
	//}
	delete hope;
	delete light;
}
