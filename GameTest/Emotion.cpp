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
	pulser = 0.1f;
	maxRadius = radius * 1.1f;
	minRadius = radius * 0.9f;
}

Emotion::~Emotion()
{
}

void Emotion::Init()
{
	
}

void Emotion::Update(float deltaTime)
{
	Pulse(deltaTime);
}

void Emotion::Pulse(float deltaTime)
{
	radius += pulser;
	if (radius > maxRadius || radius < minRadius)
	{
		pulser = -pulser;
	}
}

void Emotion::Render()
{
	// Draw outline
	App::DrawPolygonOutline(position.x, position.y, radius, 20, r, g, b);
	
	// Draw left eye
	App::DrawLine(position.x - 7.5f, position.y - 1.0f, position.x - 0.5f, position.y - 0.5f, r, g, b);

	// Draw right eye
	App::DrawLine(position.x + 7.5f, position.y - 1.0f, position.x + 0.5f, position.y - 0.5f, r, g, b);
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

void Emotion::SetPulseRate(float pulseRate)
{
	pulser = pulseRate;
}
