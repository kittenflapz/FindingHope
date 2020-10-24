#include "stdafx.h"
#include "Perfectionism.h"

Perfectionism::Perfectionism(float x, float y, float radius, float speed) : Emotion{ x, y, radius, speed }
{
	SetPulseRate(0.0f);
	targetPoint = vec2<float>(x, y);
	// Grief color will always be the same, so we can set it here
	SetColor(1.0f, 1.0f, 1.0f);
}

Perfectionism::~Perfectionism()
{
}

void Perfectionism::SetPatrolPoints(std::list<vec2<float>> patrolPoints)
{
	aiController.PopulateNodeQueue(patrolPoints);
}

void Perfectionism::PatrolInLoop()
{
	if (aiController.WithinDistance(GetPosition(), targetPoint, 10.0f))
	{
		targetPoint = aiController.SetNextNodeInQueue();
	}
	else
	{
		vec2<float> normalizedDirectionalVector = aiController.GetNormalizedVectorTowardsPoint(GetPosition(), targetPoint);
		SetVelocity(normalizedDirectionalVector.x, normalizedDirectionalVector.y);
	}
}
