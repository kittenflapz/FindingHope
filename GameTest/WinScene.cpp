#include "stdafx.h"
#include "WinScene.h"

void WinScene::Init()
{
	winText = App::CreateSprite(".\\TestData\\winText.bmp", 1, 1);
	winText->SetPosition(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT * 0.5f);
	winText->SetScale(3.0f);
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
	light->Render();
	winText->Draw();
}

void WinScene::Shutdown()
{
	delete light;
}
