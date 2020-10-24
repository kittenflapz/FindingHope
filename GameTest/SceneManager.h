#include "Scene.h"
#include "LevelScene.h"
#include "TitleScene.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

// Singleton for scene management

class SceneManager {
public:
	static SceneManager* Instance()
	{
		if (instance == 0)
		{
			instance = new SceneManager();
			return instance;
		}

		return instance;
	}

	void ChangeSceneState(SceneState newState)
		{
		currentSceneState = newState;

		switch (currentSceneState)
		{
		case SceneState::TITLE_SCENE:
			currentScene = new TitleScene();
			Init();
			break;
		case SceneState::LEVEL1_SCENE:
			currentScene->Shutdown();
			currentScene = new Level1();
			Init();
			break;
		case SceneState::LEVEL2_SCENE:
			currentScene->Shutdown();
			currentScene = new Level2();
			Init();
			break;
		case SceneState::LEVEL3_SCENE:
			currentScene->Shutdown();
			currentScene = new Level3();
			Init();
			break;
					/*case SceneState::GAMEOVER_SCENE:
						currentScene = new GameOverScene();
						break;*/
						/*case SceneState::WIN_SCENE:
				currentScene = new WinScene();
				break;*/
		default:

			break;
		}
	}

	void Init()
	{
		currentScene->Init();
	}

	void Update(float deltaTime)
	{
		currentScene->Update(deltaTime);
	}

	void Render()
	{
		currentScene->Render();
	}

	void Shutdown()
	{
		currentScene->Shutdown();
	}

private:
	static SceneManager* instance;
	Scene* currentScene;
	SceneState currentSceneState;
};

typedef SceneManager TheSceneManager;

#endif