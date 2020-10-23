#include "stdafx.h"
#include "Light.h"

Light::Light(float x, float y)
{
	position.x = x;
	position.y = y;
	sprite = App::CreateSprite(".\\TestData\\LightMask.bmp", 1, 1);
}

Light::~Light()
{
}

void Light::Init()
{
	sprite->SetPosition(position.x, position.y);
	sprite->SetScale(2.0f);
}

void Light::Update(float deltaTime)
{
}

void Light::Render()
{
	sprite->Draw();
}
