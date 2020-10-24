#include "vec2.h"

#ifndef AICONTROLLER_H
#define AICONTROLLER_H
class AIController
{
	// Helper functions for moving NPCs. more like AIHelper since the 'control' part is happening in each enemy 
public:
	vec2<float> GetNormalizedVectorTowardsPoint(vec2<float> position, vec2<float> target);
	bool WithinDistance(vec2<float> posA, vec2<float> posB, float distance);
};
#endif AICONTROLLER_H

