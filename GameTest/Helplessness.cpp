#include "stdafx.h"
#include "Helplessness.h"

Helplessness::Helplessness(float x, float y, float radius, float speed) : Emotion{ x, y, radius, speed }
{
	SetPulseRate(0.8f);
	SetColor(0.5f, 0.5f, 0.5f);
	SetSpeed(0.2f);
	targetPoint = vec2<float>(x, y);
}

Helplessness::~Helplessness()
{
}

void Helplessness::FollowPlayerIfClose(vec2<float> playerPos)
{
	if (aiController.WithinDistance(playerPos, GetPosition(), 300.0f))
	{
		targetPoint = playerPos;
	}
	vec2<float> normalizedDirectionalVector = aiController.GetNormalizedVectorTowardsPoint(GetPosition(), targetPoint);
	SetVelocity(normalizedDirectionalVector.x, normalizedDirectionalVector.y);
}





