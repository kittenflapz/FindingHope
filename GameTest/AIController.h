#include "vec2.h"

// Helper stuff for moving NPCs. more like AIHelper since the 'control' part is happening in each enemy 
#ifndef AICONTROLLER_H
#define AICONTROLLER_H
class AIController
{
private:
	std::queue<vec2<float>> nodeQueue;

public:
	vec2<float> GetNormalizedVectorTowardsPoint(vec2<float> position, vec2<float> target);
	vec2<float> DirectionToNextNode(vec2<float> position);
	vec2<float> SetNextNodeInQueue();
	bool WithinDistance(vec2<float> posA, vec2<float> posB, float distance);
	void PopulateNodeQueue(std::list<vec2<float>> nodes);
};
#endif AICONTROLLER_H

