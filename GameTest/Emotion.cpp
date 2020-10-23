#include "stdafx.h"
#include "app\app.h"
#include "Emotion.h"

Emotion::Emotion(float x, float y, float radius, float speed)
{
	position.x = x;
	position.y = y;
	this->radius = radius;
	this->speed = speed;
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
}

Emotion::~Emotion()
{
}

void Emotion::Init()
{
	
}

void Emotion::Update(float deltaTime)
{
	
}

void Emotion::Render()
{
	//App::DrawCircle(position.x, position.y, radius, r, g, b);

	App::DrawPolygonOutline(position.x, position.y, radius, 20, r, g, b);
}

void Emotion::SetPosition(float x, float y)
{

}

void Emotion::SetRadius(float radius)
{
	this->radius = radius;
}

void Emotion::SetSpeed(float speed)
{
}

void Emotion::SetVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

void Emotion::SetColor(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
