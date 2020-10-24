#include "Emotion.h"
#include "vec2.h"
#include "AIController.h"

#ifndef ANXIETY_H
#define ANXIETY_H

// 'Fears', an enemy type

class Anxiety :
	public Emotion
{
public:
	Anxiety(float x, float y, float radius, float speed, vec2<float> patrolPointA, vec2<float> patrolPointB);
	~Anxiety();

	// Functions specific to Fear
	void PatrolRandomPoints();
	vec2<float> GetRandomFloatPair();

private:
	vec2<float> patrolPointA;
	vec2<float> patrolPointB;
	vec2<float> targetPoint;
	AIController aiController;
};
#endif // ANXIETY_H

