#include "Emotion.h"
#include "vec2.h"
#include "AIController.h"

#ifndef PERFECTIONISM_H
#define PERFECTIONISM_H

// 'Perfectionisms', an enemy type

class Perfectionism :
	public Emotion
{
public:
	Perfectionism(float x, float y, float radius, float speed);
	~Perfectionism();

	void Update(float deltaTime);

	// Functions specific to Perfectionism
	void SetPatrolPoints(std::list<vec2<float>> patrolPoints);
	void PatrolInLoop();
private:
	AIController aiController;
	vec2<float> targetPoint;

};
#endif // PERFECTIONISM_H