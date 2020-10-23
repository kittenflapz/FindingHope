//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

#include "Player.h"
#include "Grief.h"
#include "CollisionChecker.h"


Player *player;
Grief *testGrief;
Hope *testHope;
LightFuelBar *lightFuelBar;

CollisionChecker collisionChecker;
bool lightOn;
bool hasWon;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	player = App::CreatePlayer(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f, 50.0f, 50.0f, 0.2f);
	testGrief = App::CreateGrief(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT * 0.5f, 20.0f, 0.5f);
	testHope = App::CreateHope(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f, 20.0f, 0.5f);
	lightFuelBar = App::CreateLightFuelBar(APP_INIT_WINDOW_WIDTH - 50.0f, APP_INIT_WINDOW_HEIGHT * 0.33f, 20.0f, APP_INIT_WINDOW_HEIGHT * 0.33f);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
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

	player->Update(deltaTime);
	testGrief->Update(deltaTime);
	testHope->Update(deltaTime);

	if (collisionChecker.PlayerEmotion(player, testGrief))
	{
		player->SetColor(1.0f, 0.0f, 0.0f);
	}
	else if (collisionChecker.PlayerEmotion(player, testHope))
	{
		player->SetColor(0.0f, 1.0f, 0.0f);
		hasWon = true;
	}
	else
	{
		player->SetColor(player->GetDefaultRColour(), player->GetDefaultGColour(), player->GetDefaultBColour());
	}


	
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	if (hasWon)
	{
		std::string scoreString = "Hope: You've found me! Thank you!";
		App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.5f, scoreString.c_str());
	}
	else
	{
		if (lightOn)
		{
			player->Render();
			testGrief->Render();
			testHope->Render();
			lightFuelBar->Render();
			glClearColor(0.074f, 0.035f, 0.07f, 1.0f); // Shouldn't need to set this every frame, should be on a light turning on function
		}
		else
		{
			lightFuelBar->Render();
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
	
	//std::string scoreString = std::to_string(score);
	//App::Print(100, APP_INIT_WINDOW_HEIGHT - 100, scoreString.c_str());
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	// ########## CLEAN STUFF UP HERE, DELETE GAMEOBJECTS ETC #########################

	delete player;
	delete testGrief;
	delete testHope;
}