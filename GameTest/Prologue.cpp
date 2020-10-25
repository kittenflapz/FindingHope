#include "stdafx.h"
#include "Prologue.h"

void Prologue::Init()
{
	// UI
	SetStartText("prologue. hold A for light.");

	// Player
	SetPlayerStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float>(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	Grief* grief = new Grief(APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT * 0.5f, 20.0f, 0.5f);
	AddToEnemyList(grief);

	LevelScene::Init();
}

void Prologue::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Prologue::Render()
{
	LevelScene::Render();
}

void Prologue::Shutdown()
{
	LevelScene::Shutdown();
}
