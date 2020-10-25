#include "stdafx.h"
#include "Level1.h"



void Level1::Init()
{
	// Player
	SetPlayerStartPosition(vec2<float> (APP_INIT_WINDOW_WIDTH * 0.5f, 100.0f));
	CreatePlayer();

	// Goal
	SetHopeStartPosition(vec2<float> (APP_INIT_WINDOW_WIDTH * 0.5f, APP_INIT_WINDOW_HEIGHT - 100.0f));
	CreateHope();

	// Enemies
	Grief* grief1 = new Grief(106.0f, 100.0f, 20.0f, 0.5f);
	AddToEnemyList(grief1);
	Fear* fear1 = new Fear(400.0f, 400.0f, 20.0f, 0.5f, vec2<float>(100.0f, 400.0f), vec2<float>(900.0f, 400.0f));
	AddToEnemyList(fear1);


	LevelScene::Init();

	// Griefs


//	Grief* grief2 = new Grief(106.0f, 300.0f, 20.0f, 0.5f);
//	Grief* grief3 = new Grief(106.0f, 500.0f, 20.0f, 0.5f);
//	Grief* grief4 = new Grief(312.0f, 700.0f, 20.0f, 0.5f);
//	Grief* grief5 = new Grief(312.0f, 100.0f, 20.0f, 0.5f);
//	Grief* grief6 = new Grief(312.0f, 300.0f, 20.0f, 0.5f);
//	Grief* grief7 = new Grief(312.0f, 500.0f, 20.0f, 0.5f);
//	Grief* grief8 = new Grief(718.0f, 700.0f, 20.0f, 0.5f);
//	Grief* grief9 = new Grief(718.0f, 100.0f, 20.0f, 0.5f);
//	Grief* grief10 = new Grief(718.0f, 300.0f, 20.0f, 0.5f);
//	Grief* grief11 = new Grief(924.0f, 500.0f, 20.0f, 0.5f);
//	Grief* grief12 = new Grief(924.0f, 700.0f, 20.0f, 0.5f);
//	Grief* grief13 = new Grief(512.0f, 300.0f, 20.0f, 0.5f);
//	Grief* grief14 = new Grief(512.0f, 550.0f, 20.0f, 0.5f);

	//griefs.push_back(grief1);
//griefs.push_back(grief2);
//griefs.push_back(grief3);
//griefs.push_back(grief4);
//griefs.push_back(grief5);	
//griefs.push_back(grief6);
//griefs.push_back(grief7);
//griefs.push_back(grief8);
//griefs.push_back(grief9);
//griefs.push_back(grief10);
//griefs.push_back(grief11);
//griefs.push_back(grief12);
//griefs.push_back(grief13);
//griefs.push_back(grief14);
}

void Level1::Update(float deltaTime)
{
	LevelScene::Update(deltaTime);
}

void Level1::Render()
{
	LevelScene::Render();
}

void Level1::Shutdown()
{
	LevelScene::Shutdown();
}
