#include "stdafx.h"
#include "TitleScene.h"

std::string titleString;
std::string instructionsString;

void TitleScene::Init()
{
	titleString = "FINDING HOPE";
	instructionsString = "I know things have been a little dark lately, so I thought we'd go on a trip together to find some hope. Press A to play.";
	
	glClearColor(0.074f, 0.035f, 0.07f, 1.0f);
}

void TitleScene::Update(float deltaTime)
{
}

void TitleScene::Render()
{
	App::Print(APP_INIT_WINDOW_WIDTH * 0.36f, APP_INIT_WINDOW_HEIGHT * 0.6f, titleString.c_str());
	App::Print(APP_INIT_WINDOW_WIDTH * 0.05f, APP_INIT_WINDOW_HEIGHT * 0.5f, instructionsString.c_str());
}

void TitleScene::Shutdown()
{
}
