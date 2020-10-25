#include "stdafx.h"
#include "TitleScene.h"



void TitleScene::Init()
{
	titleText = App::CreateSprite(".\\TestData\\titleText.bmp", 1, 1);
	titleText->SetPosition(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT * 0.5f);
	titleText->SetScale(3.0f);
	App::PlaySound(".\\Sounds\\PatakasWorld.wav", true);
	light = new Light(512.0f, 384.0f);
	light->Init();
	std::string testStr = "in memory of Donnie";
	typewriter = new Typewriter();
	typewriter->PopulateQueue(testStr);

	TheSceneManager::Instance()->SetLivesLeft(3);
	glClearColor(0.074f, 0.035f, 0.07f, 1.0f);
}

void TitleScene::Update(float deltaTime)
{

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		TheSceneManager::Instance()->ChangeSceneState(SceneState::PROLOGUE);
	}
}

void TitleScene::Render()
{
	light->Render();
	titleText->Draw();
	typewriter->Update();
}

void TitleScene::Shutdown()
{
	delete light;
}
