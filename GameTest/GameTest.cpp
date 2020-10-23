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
#include "Scene.h"
#include "LevelScene.h"
#include "Level1.h"
#include "GameManager.h"

Scene* currentScene;
extern int currentSceneIndex = 0;

// make a title scene and see if you can change the scene on a keypress using the global currentSceneIndex variable

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	currentScene = new Level1();
	currentScene->Init();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	currentScene->Update(deltaTime);
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	currentScene->Render();
	
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
	currentScene->Shutdown();
}