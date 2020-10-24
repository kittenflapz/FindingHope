#include "stdafx.h"
#include "LevelScene.h"

void LevelScene::Update(float deltaTime)
{
	if (TheSceneManager::Instance()->GetLivesLeft() == 0)
	{
		TheSceneManager::Instance()->ChangeSceneState(SceneState::GAMEOVER_SCENE);
	}
}
