#include "Emotion.h"
#include "vec2.h"
#include "AIController.h"

#ifndef FEAR_H
#define FEAR_H

// 'Fears', an enemy type

class Fear :
	public Emotion
{
public:
	Fear(float x, float y, float radius, float speed, vec2<float> patrolPointA, vec2<float> patrolPointB);
	~Fear();

	// Functions specific to Fear
	void Patrol();

private:
	vec2<float> patrolPointA;
	vec2<float> patrolPointB;
	vec2<float> targetPoint;
	AIController aiController;
};
#endif // FEAR_H


