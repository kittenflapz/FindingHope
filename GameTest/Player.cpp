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
	dragMultiplier = 0.9f;

	
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(float deltaTime)
{
	CheckBounds();
	ResolveInput(deltaTime);
	Move();

}

void Player::CheckBounds() 
{
	if (position.x + scale.x > APP_INIT_WINDOW_WIDTH)
	{
		position.x = APP_INIT_WINDOW_WIDTH - scale.x;
	}
	else if (position.x - scale.x < 0)
	{
		position.x = scale.x;
	}

	if (position.y + scale.y > APP_INIT_WINDOW_HEIGHT)
	{
		position.y = APP_INIT_WINDOW_HEIGHT - scale.y;
	}
	if (position.y - scale.y < 0)
	{
		position.y = scale.y;
	}
}

void Player::ResolveInput(float deltaTime)
{
	// Check inputs 
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		velocity.x += speed * deltaTime;
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		velocity.x -= speed * deltaTime;
	}

	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		velocity.y += speed * deltaTime;
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		velocity.y -= speed * deltaTime;
	}
}

void Player::Move() 
{
	// Apply some drag 
	velocity *= dragMultiplier;

	position += velocity;
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
