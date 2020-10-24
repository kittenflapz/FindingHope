#include "stdafx.h"
#include "WinScene.h"

void WinScene::Init()
{
	winString = "YOU WON";
	playAgainString = "You found so much hope today. That's awesome. Press A to do it again.";
	light = new Light(512.0f, 384.0f);
	light->Init();
	glClearColor(0.074f, 0.035f, 0.07f, 1.0f);
}

void WinScene::Update(float deltaTime)
{
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		TheSceneManager::Instance()->ChangeSceneState(SceneState::TITLE_SCENE);
	}
}

void WinScene::Render()
{
	App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.6f, winString.c_str());
	App::Print(APP_INIT_WINDOW_WIDTH * 0.05f, APP_INIT_WINDOW_HEIGHT * 0.5f, playAgainString.c_str());
	light->Render();
}

void WinScene::Shutdown()
{
	delete light;
}
