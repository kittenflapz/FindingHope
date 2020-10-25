#include "stdafx.h"
#include "Fear.h"

Fear::Fear(float x, float y, float radius, float speed, vec2<float> patrolPointA, vec2<float> patrolPointB) : Emotion{ x, y, radius, speed }
{
	SetPulseRate(0.8f);
	SetColor(0.9f, 0.1f, 0.2f);
	SetSpeed(0.2f);
	this->patrolPointA = patrolPointA;
	this->patrolPointB = patrolPointB;
	targetPoint = patrolPointA;
}

Fear::~Fear()
{
}

void Fear::Update(float deltaTime)
{
	Patrol();
	Emotion::Update(deltaTime);
}

// Super simple patrol. If we're at A, go to B. If we're at B, go to A.

void Fear::Patrol()
{
	if (aiController.WithinDistance(GetPosition(), patrolPointA, 10.0f))
	{
		targetPoint = patrolPointB;
	}

	if (aiController.WithinDistance(GetPosition(), patrolPointB, 10.0f))
	{
		targetPoint = patrolPointA;
	}

	vec2<float> normalizedDirectionalVector = aiController.GetNormalizedVectorTowardsPoint(GetPosition(), targetPoint);
	SetVelocity(normalizedDirectionalVector.x, normalizedDirectionalVector.y);
}
