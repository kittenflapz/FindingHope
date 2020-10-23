#include "stdafx.h"
#include "app\app.h"
#include "Player.h"

Player::Player(float x, float y, float w, float h, float speed)
{
	position = vec2<float>(x, y);
	scale = vec2<float>(w, h);
	this->speed = speed;
	defaultR = r = 0.694f;
	defaultB = b = 0.274f;
	defaultG = g = 0.137f;

	
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(float deltaTime)
{
	// Check inputs 
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		position.x += speed * deltaTime;
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		position.x -= speed * deltaTime;
	}

	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		position.y += speed * deltaTime;
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		position.y -= speed * deltaTime;
	}
}

void Player::Render()
{
	App::DrawRect(position.x, position.y, position.x + scale.x, position.y + scale.y, r, g, b);
}


void Player::SetPosition(float x, float y)
{
	position = vec2<float>(x, y);
}

void Player::SetScale(float w, float h)
{
	scale = vec2<float>(w, h);
}

void Player::SetSpeed(float speed)
{
	this->speed = speed;
}

void Player::SetColor(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
