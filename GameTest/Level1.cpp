#include "stdafx.h"
#include "Level1.h"

Player* player;
Hope* hope;
LightFuelBar* lightFuelBar;

std::vector<Grief*> griefs;

CollisionChecker collisionChecker;
bool lightOn;
bool hasWon;
bool gameOver; // this might go in LevelScene
vec2<float> startPosition;

void Level1::Init()
{
	startPosition = vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f);

	player = new Player (startPosition.x, startPosition.y, 50.0f, 50.0f, 0.2f);
	hope = new Hope(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f, 20.0f, 0.5f);
	lightFuelBar = new LightFuelBar(APP_INIT_WINDOW_WIDTH - 50.0f, APP_INIT_WINDOW_HEIGHT * 0.33f, 20.0f, APP_INIT_WINDOW_HEIGHT * 0.33f);

	// Griefs

	Grief* grief1 = new Grief(200.0f, 200.0f, 20.0f, 0.5f);
	Grief* grief2 = new Grief(250.0f, 250.0f, 20.0f, 0.5f);
	Grief* grief3 = new Grief(20.0f, 500.0f, 20.0f, 0.5f);
	Grief* grief4 = new Grief(500.0f, 200.0f, 20.0f, 0.5f);
	Grief* grief5 = new Grief(100.0f, 600.0f, 20.0f, 0.5f);
	Grief* grief6 = new Grief(500.0f, 200.0f, 20.0f, 0.5f);
	Grief* grief7 = new Grief(750.0f, 250.0f, 20.0f, 0.5f);
	Grief* grief8 = new Grief(580.0f, 500.0f, 20.0f, 0.5f);
	Grief* grief9 = new Grief(700.0f, 200.0f, 20.0f, 0.5f);
	Grief* grief10 = new Grief(600.0f, 600.0f, 20.0f, 0.5f);

	griefs.push_back(grief1);
	griefs.push_back(grief2);
	griefs.push_back(grief3);
	griefs.push_back(grief4);
	griefs.push_back(grief5);	
	griefs.push_back(grief6);
	griefs.push_back(grief7);
	griefs.push_back(grief8);
	griefs.push_back(grief9);
	griefs.push_back(grief10);
}

void Level1::Update(float deltaTime)
{
	if (!gameOver)
	{
		player->Update(deltaTime);
		hope->Update(deltaTime);

		if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, false))
		{
			if (lightFuelBar->GetCurrentFuel() > 0)
			{
				lightOn = true;
				lightFuelBar->DecrementFuel();
			}
		}
		else
		{
			lightOn = false;
		}

		for (int i = 0; i < griefs.size(); i++)
		{
			griefs[i]->Update(deltaTime);
			if (collisionChecker.PlayerEmotion(player, griefs[i]))
			{
				gameOver = true;
			}
		}

	
		if (collisionChecker.PlayerEmotion(player, hope))
		{
			player->SetColor(0.0f, 1.0f, 0.0f);
			hasWon = true;
		}
		else
		{
			player->SetColor(player->GetDefaultRColour(), player->GetDefaultGColour(), player->GetDefaultBColour());
		}

	}
	else
	{
		player->SetPosition(startPosition.x, startPosition.y);
		gameOver = false;
	}
}

void Level1::Render()
{
	if (hasWon)
	{
		std::string scoreString = "Hope: You've found me! Thank you!";
		App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.5f, scoreString.c_str());
		level1Done = true;
	}
	else
	{
		if (lightOn)
		{
			player->Render();
			hope->Render();
			lightFuelBar->Render();
			glClearColor(0.074f, 0.035f, 0.07f, 1.0f); // Shouldn't need to set this every frame, should be on a light turning on function

			for (int i = 0; i < griefs.size(); i++)
			{
				griefs[i]->Render();
			}
		}
		else
		{
			lightFuelBar->Render();
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
}

void Level1::Shutdown()
{
	delete player;
	for (int i = 0; i < griefs.size(); i++)
	{
		delete griefs[i];
	}
	delete hope;
}
