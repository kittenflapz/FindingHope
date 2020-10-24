#include "stdafx.h"
#include "GameOverScene.h"

void GameOverScene::Init()
{
	gameOverString = "GAME OVER";
	playAgainString = "Sometimes it's a little harder to find hope, and that's okay! Press A to try again.";
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
	App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.6f, gameOverString.c_str());
	App::Print(APP_INIT_WINDOW_WIDTH * 0.05f, APP_INIT_WINDOW_HEIGHT * 0.5f, playAgainString.c_str());
	light->Render();
}

void GameOverScene::Shutdown()
{
	delete light;
}
