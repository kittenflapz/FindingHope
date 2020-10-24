#include "stdafx.h"
#include "AIController.h"

vec2<float> AIController::GetNormalizedVectorTowardsPoint(vec2<float> position, vec2<float> target)
{
	vec2<float> directionalVector;
	directionalVector.x = target.x - position.x;
	directionalVector.y = target.y - position.y;
	directionalVector.normalize();
	return directionalVector;
}


// Checks whether two points are within a given distance of each other
bool AIController::WithinDistance(vec2<float> posA, vec2<float> posB, float distance)
{
	return posA.dist(posB) < distance ? true : false;
}

