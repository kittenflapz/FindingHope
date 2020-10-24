#include "stdafx.h"
#include "Level3.h"

void Level3::Init()
{
	// Player
	startPosition = vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f);
	player = new Player(startPosition.x, startPosition.y, 50.0f, 50.0f, 0.05f);

	// Goal
	hope = new Hope(APP_INIT_WINDOW_WIDTH * 0.25f, APP_INIT_WINDOW_HEIGHT - 100.0f, 20.0f, 0.5f);

	// UI
	lightFuelBar = new LightFuelBar(APP_INIT_WINDOW_WIDTH - 50.0f, APP_INIT_WINDOW_HEIGHT * 0.33f, 20.0f, APP_INIT_WINDOW_HEIGHT * 0.33f);
	light = new Light(512.0f, 384.0f);
	light->Init();



	// Enemies
	Fear* fear1 = new Fear(386.0f, 100.0f, 20.0f, 0.5f, vec2<float>(386.0f, 100.0f), vec2<float>(386.0f, 670.0f));
	Fear* fear2 = new Fear(626.0f, 670.0f, 20.0f, 0.5f, vec2<float>(626.0f, 100.0f), vec2<float>(626.0f, 670.0f));

	fears.push_back(fear1);
	fears.push_back(fear2);

	Grief* grief1 = new Grief(106.0f, 100.0f, 20.0f, 0.5f);
	Grief* grief2 = new Grief(106.0f, 300.0f, 20.0f, 0.5f);
	Grief* grief3 = new Grief(106.0f, 500.0f, 20.0f, 0.5f);
	Grief* grief4 = new Grief(312.0f, 700.0f, 20.0f, 0.5f);
	Grief* grief5 = new Grief(312.0f, 100.0f, 20.0f, 0.5f);
	Grief* grief6 = new Grief(312.0f, 300.0f, 20.0f, 0.5f);
	Grief* grief7 = new Grief(312.0f, 500.0f, 20.0f, 0.5f);
	Grief* grief8 = new Grief(718.0f, 700.0f, 20.0f, 0.5f);
	Grief* grief9 = new Grief(718.0f, 100.0f, 20.0f, 0.5f);
	Grief* grief10 = new Grief(718.0f, 300.0f, 20.0f, 0.5f);
	Grief* grief11 = new Grief(924.0f, 500.0f, 20.0f, 0.5f);
	Grief* grief12 = new Grief(924.0f, 700.0f, 20.0f, 0.5f);
	Grief* grief13 = new Grief(512.0f, 300.0f, 20.0f, 0.5f);
	Grief* grief14 = new Grief(512.0f, 550.0f, 20.0f, 0.5f);

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
	griefs.push_back(grief11);
	griefs.push_back(grief12);
	griefs.push_back(grief13);
	griefs.push_back(grief14);

}

void Level3::Update(float deltaTime)
{
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
			}
		}

		for (int i = 0; i < griefs.size(); i++)
		{
			griefs[i]->Update(deltaTime);
			if (collisionChecker.PlayerEmotion(player, griefs[i]))
			{
				App::PlaySound(".\\Sounds\\Pop.wav", false);
				restartLevel = true;
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

void Level3::Render()
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

			for (int i = 0; i < fears.size(); i++)
			{
				fears[i]->Render();
			}

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

void Level3::Shutdown()
{
	delete player;
	for (int i = 0; i < fears.size(); i++)
	{
		delete fears[i];
	}
	for (int i = 0; i < griefs.size(); i++)
	{
		delete griefs[i];
	}
	delete hope;
	delete light;
}
