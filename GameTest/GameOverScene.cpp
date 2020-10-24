#include "stdafx.h"
#include "GameOverScene.h"

void GameOverScene::Init()
{
	gameOverText = App::CreateSprite(".\\TestData\\gameOverText.bmp", 1, 1);
	gameOverText->SetPosition(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT * 0.5f);
	gameOverText->SetScale(3.0f);
	light = new Light(512.0f, 384.0f);
	light->Init();
	glClearColor(0.074f, 0.035f, 0.07f, 1.0f);
}

void GameOverScene::Update(float deltaTime)
{
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		TheSceneManager::Instance()->ChangeSceneState(SceneState::TITLE_SCENE);
	}

}

void GameOverScene::Render()
{
	gameOverText->Draw();
	light->Render();
}

void GameOverScene::Shutdown()
{
	delete light;
}
