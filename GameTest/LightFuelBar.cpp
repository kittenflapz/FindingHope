#include "stdafx.h"
#include "app\app.h"
#include "LightFuelBar.h"

LightFuelBar::LightFuelBar(float x, float y, float width, float maxFuel)
{
	this->position.x = x;
	this->position.y = y;
	this->width = width;
	this->maxFuel = maxFuel;
	currentFuel = maxFuel;
}

LightFuelBar::~LightFuelBar()
{
}

void LightFuelBar::Init()
{
}

void LightFuelBar::Update(float deltaTime)
{
}

void LightFuelBar::Render()
{
	// Draw an outline box height of maxFuel and width of width
	App::DrawRectOutline(position.x, position.y + maxFuel, position.x + width, position.y, 0.0f, 0.0f, 0.0f);

	if (currentFuel > 0)
	{	// Draw a fill box height of currentFuel and width of width
		App::DrawRect(position.x, position.y + currentFuel, position.x + width, position.y, 1.0f, 1.0f, 1.0f);
	}

}

void LightFuelBar::SetMaxFuel()
{
}

void LightFuelBar::SetCurrentFuel()
{
}

float LightFuelBar::GetMaxFuel()
{
	return maxFuel;
}

float LightFuelBar::GetCurrentFuel()
{
	return currentFuel;
}

void LightFuelBar::DecrementFuel()
{
	// maybe delta time here
	currentFuel -= 1.0f;
}


