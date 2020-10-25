#include "stdafx.h"
#include "LevelScene.h"

void LevelScene::Init()
{
	// Initializing everything that is common across all levels. Called after level setup in derived class init.
	for (int i = 0; i < TheSceneManager::Instance()->GetLivesLeft(); i++)
	{
		flameSprites[i] = App::CreateSprite(".\\TestData\\flame.bmp", 1, 1);
		flameSprites[i]->SetPosition(35.0f + (i * 40.0f), 720.0f);
		flameSprites[i]->SetScale(2.0f); 
		flameSprites[i]->SetColor(0.8f, 0.8f, 0.8f, 0.5f);
	}
	typewriter = new Typewriter();
	typewriter->PopulateQueue(chapterIntroText);

	timeToWaitOnWinMessage = 200.0f;
	timerForWinMessage = 0.0f;
	winString = "Hope: You've found me! Thank you!";
	outOfFuelString = "You're out of fuel! Chapter restarting...";

	levelResetTime = 100.0f;
	outOfFuelTimer = 0.0f;

	lightFuelBar = new LightFuelBar(APP_INIT_WINDOW_WIDTH - 50.0f, APP_INIT_WINDOW_HEIGHT * 0.33f, 20.0f, APP_INIT_WINDOW_HEIGHT * 0.33f);
	light = new Light(512.0f, 384.0f);
	light->Init();
}

void LevelScene::Update(float deltaTime)
{
	if (TheSceneManager::Instance()->GetLivesLeft() == 0)
	{
		TheSceneManager::Instance()->ChangeSceneState(SceneState::GAMEOVER_SCENE);
	}
	if (!hasWon)
	{
		if (lightFuelBar->GetCurrentFuel() > 0)
		{
			if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, false))
			{
				SetLightOn(true);
				lightFuelBar->DecrementFuel();
			}
			else
			{
				SetLightOn(false);
			}
		}
		else
		{
			SetLightOn(false);
			if (outOfFuelTimer < levelResetTime)
			{
				showFuelString = true;
				outOfFuelTimer++;
			}
			else
			{
				showFuelString = false;
				App::PlaySound(".\\Sounds\\Pop.wav", false);
				RestartLevel();
				TheSceneManager::Instance()->LoseLife();
			}
		}


		if (LevelRestart() == false)
		{
			GetPlayer()->Update(deltaTime);
			GetHope()->Update(deltaTime);

			for (int i = 0; i < enemyList.size(); i++)
			{
				enemyList[i]->Update(deltaTime);
				enemyList[i]->SetPlayerPosition(GetPlayer()->GetPosition());
				if (GetCollisionChecker().PlayerEmotion(GetPlayer(), enemyList[i]))
				{
					App::PlaySound(".\\Sounds\\Pop.wav", false);
					RestartLevel();
					TheSceneManager::Instance()->LoseLife();
				}
			}

			if (GetCollisionChecker().PlayerEmotion(GetPlayer(), GetHope()) && HasWon() == false || App::GetController().CheckButton(XINPUT_GAMEPAD_B, false))
			{
				App::PlaySound(".\\Sounds\\Bells.wav", false);
				Win();
			}

		}
		else
		{
			TheSceneManager::Instance()->ChangeSceneState(TheSceneManager::Instance()->GetCurrentSceneState());
			restartLevel = false;
		}
	}
}

void LevelScene::Render()
{
	if (hasWon)
	{
		if (timerForWinMessage < timeToWaitOnWinMessage)
		{
		
			App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.5f, winString.c_str(), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_8_BY_13);
			timerForWinMessage++;
		}
		else
		{
			// Go to the next scene (this is why they're in order in the enum)
			TheSceneManager::Instance()->ChangeSceneState(static_cast<SceneState>(static_cast<int>(TheSceneManager::Instance()->GetCurrentSceneState()) + 1));
		}

	}
	else
	{
		if (LightIsOn())
		{
			player->Render();
			hope->Render();
			light->Render();
			lightFuelBar->Render();
			for (int i = 0; i < enemyList.size(); i++)
			{
				enemyList[i]->Render();
			}
			glClearColor(0.074f, 0.035f, 0.07f, 1.0f);
		}
		else
		{
			lightFuelBar->Render();
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}

	if (showFuelString)
	{
		App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.5f, outOfFuelString.c_str(), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_8_BY_13);
	}

	// Render sprites representing lives left
	for (int i = 0; i < TheSceneManager::Instance()->GetLivesLeft(); i++)
	{
		flameSprites[i]->Draw();
	}

	// Render chapter title
	typewriter->Update();

}

void LevelScene::Shutdown()
{
	delete hope;
	delete light;
	delete player;
	for (int i = 0; i < enemyList.size(); i++)
	{
		delete enemyList[i];
	}
}

void LevelScene::SetStartText(std::string chapterIntroText)
{
	this->chapterIntroText = chapterIntroText;
}

CollisionChecker LevelScene::GetCollisionChecker()
{
	return collisionChecker;
}

void LevelScene::SetPlayerStartPosition(vec2<float> startPos)
{
	playerStartPosition = startPos;
}

vec2<float> LevelScene::GetPlayerStartPosition()
{
	return playerStartPosition;
}

void LevelScene::SetHopeStartPosition(vec2<float> startPos)
{
	hopeStartPosition = startPos;
}

vec2<float> LevelScene::GetHopeStartPosition()
{
	return hopeStartPosition;
}

Player* LevelScene::GetPlayer()
{
	return player;
}

Hope* LevelScene::GetHope()
{
	return hope;
}

void LevelScene::RestartLevel()
{
	restartLevel = true;
}

void LevelScene::Win()
{
	hasWon = true;
}

bool LevelScene::HasWon()
{
	return hasWon;
}

bool LevelScene::LevelRestart()
{
	return restartLevel;
}

void LevelScene::AddToEnemyList(Emotion* enemy)
{
	enemyList.push_back(enemy);
}

void LevelScene::CreatePlayer()
{
	player = new Player(playerStartPosition.x, playerStartPosition.y, 50.0f, 50.0f, 0.05f);
}

void LevelScene::CreateHope()
{
	hope = new Hope(hopeStartPosition.x, hopeStartPosition.y, 20.0f, 0.5f);
}
