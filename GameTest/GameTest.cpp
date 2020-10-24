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

#include "SceneManager.h"

SceneManager* SceneManager::instance = 0;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	TheSceneManager::Instance()->ChangeSceneState(TITLE_SCENE);
	TheSceneManager::Instance()->Init();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	TheSceneManager::Instance()->Update(deltaTime);

	//// This is not really how I want the scene switching to be, a singleton may be better

	//if (gameStarted == false && App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	//{
	//	delete currentScene;
	//	currentScene = new Level1();
	//	currentScene->Init();
	//	gameStarted = true;
	//}

	//if (gameStarted == true && level1Done == true)
	//{
	//	Sleep(2000);
	//	delete currentScene;
	//	currentScene = new TitleScene();
	//	currentScene->Init();
	//	gameStarted = false;
	//}

	//currentScene->Update(deltaTime);
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	TheSceneManager::Instance()->Render();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	TheSceneManager::Instance()->Shutdown();
}