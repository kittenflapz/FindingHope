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

vec2<float> AIController::DirectionToNextNode(vec2<float> position)
{
	// Get the next position from the front of the queue
	vec2<float> nextNodePos = nodeQueue.front();
	nodeQueue.pop();
	// Sneakily put it on the back of the queue (so we loop)
	nodeQueue.push(nextNodePos);
	return GetNormalizedVectorTowardsPoint(position, nextNodePos);
}

vec2<float> AIController::SetNextNodeInQueue()
{
	// Get the next position from the front of the queue
	vec2<float> nextNodePos = nodeQueue.front();
	nodeQueue.pop();
	// Sneakily put it on the back of the queue (so we loop)
	nodeQueue.push(nextNodePos);

	return nextNodePos;
}


// Checks whether two points are within a given distance of each other
bool AIController::WithinDistance(vec2<float> posA, vec2<float> posB, float distance)
{
	return posA.dist(posB) < distance ? true : false;
}

void AIController::PopulateNodeQueue(std::list<vec2<float>> nodes)
{
	for(vec2<float> node : nodes)
	{
		nodeQueue.push(node);
	}
}

