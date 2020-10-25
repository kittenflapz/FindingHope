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
	blinkStateTime = 20.0f;
	blinkTimer = 0.0f;
	currentBlinkState = BlinkState::NOTBLINKING;
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
	position += velocity * deltaTime * speed;
}

void Emotion::Pulse(float deltaTime)
{
	radius += pulser;
	if (radius > maxRadius || radius < minRadius)
	{
		pulser = -pulser;
	}
}

Emotion::BlinkState Emotion::SwitchStateAndResetBlinkTime()
{
	// Get a uniformly distributed random number
	std::random_device randdev;
	std::mt19937 generator(randdev());
	std::uniform_real_distribution<> distrib(0, 60);

	blinkStateTime = distrib(generator);
	blinkTimer = 0;

	return (currentBlinkState == BlinkState::BLINKING ? BlinkState::NOTBLINKING : BlinkState::BLINKING);
}


void Emotion::Render()
{
	// Draw outline
	App::DrawPolygonOutline(position.x, position.y, radius, 20, r, g, b);

	// Handle whether we should be blinking or not
	if (blinkTimer < blinkStateTime)
	{
		blinkTimer++;
	}
	else
	{
		currentBlinkState = SwitchStateAndResetBlinkTime();
	}


	// Blinking
	switch (currentBlinkState)
	{
	case BlinkState::BLINKING:
		// Draw left eye blink
		App::DrawLine(position.x - 7.5f, position.y - 1.0f, position.x - 0.5f, position.y - 0.5f, r, g, b);
		// Draw right eye blink
		App::DrawLine(position.x + 7.5f, position.y - 1.0f, position.x + 0.5f, position.y - 0.5f, r, g, b);
		break;
	case BlinkState::NOTBLINKING:
		// Draw left eye 
		App::DrawPolygonOutline(position.x - 6.5f, position.y - 1.0f, 3.0f, 5, 1.0f, 1.0f, 1.0f);
		// Draw right eye
		App::DrawPolygonOutline(position.x + 6.5f, position.y - 1.0f, 3.0f, 5, 1.0f, 1.0f, 1.0f);
		break;
	default:
		break;
	}
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
