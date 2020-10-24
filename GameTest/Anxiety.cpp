#include "stdafx.h"
#include "Anxiety.h"

Anxiety::Anxiety(float x, float y, float radius, float speed, vec2<float> patrolPointA, vec2<float> patrolPointB) : Emotion{ x, y, radius, speed }
{
	SetPulseRate(0.8f);
	SetColor(0.5f, 0.7f, 0.3f);
	SetSpeed(0.2f);
	this->patrolPointA = patrolPointA;
	this->patrolPointB = patrolPointB;
	targetPoint = patrolPointB;
}

Anxiety::~Anxiety()
{
}

// Super simple patrol like fear, except randomizing points!

void Anxiety::PatrolRandomPoints()
{
	if (aiController.WithinDistance(GetPosition(), patrolPointA, 10.0f))
	{
		targetPoint = patrolPointB;
		patrolPointA += GetRandomFloatPair();


	}

	if (aiController.WithinDistance(GetPosition(), patrolPointB, 10.0f))
	{
		targetPoint = patrolPointA;
		patrolPointB += GetRandomFloatPair();
	}

	vec2<float> normalizedDirectionalVector = aiController.GetNormalizedVectorTowardsPoint(GetPosition(), targetPoint);
	SetVelocity(normalizedDirectionalVector.x, normalizedDirectionalVector.y);
}

vec2<float> Anxiety::GetRandomFloatPair()
{
	vec2<float> pairToReturn;
	std::random_device randdev;
	std::mt19937 generator(randdev());
	std::uniform_real_distribution<> distrib(-300.0f, 300.0f);
	pairToReturn.x = distrib(generator);

	std::random_device randdev2;
	std::mt19937 generator2(randdev2());
	std::uniform_real_distribution<> distrib2(-300.0f, 300.0f);
	pairToReturn.y = distrib2(generator2);
	return pairToReturn;
}
