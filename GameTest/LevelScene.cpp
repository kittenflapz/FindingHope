#include "stdafx.h"
#include "LevelScene.h"

void LevelScene::Init()
{
	for (int i = 0; i < TheSceneManager::Instance()->GetLivesLeft(); i++)
	{
		flameSprites[i] = App::CreateSprite(".\\TestData\\flame.bmp", 1, 1);
		flameSprites[i]->SetPosition(30.0f + (i * 30.0f), 688.0f);
		flameSprites[i]->SetScale(2.0f);
	}

}

void LevelScene::Update(float deltaTime)
{
	if (TheSceneManager::Instance()->GetLivesLeft() == 0)
	{
		TheSceneManager::Instance()->ChangeSceneState(SceneState::GAMEOVER_SCENE);
	}
}

void LevelScene::Render()
{
	// Render sprites representing lives left
	for (int i = 0; i < TheSceneManager::Instance()->GetLivesLeft(); i++)
	{
		flameSprites[i]->Draw();
	}

}
