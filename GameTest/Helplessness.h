#include "Emotion.h"
#include "vec2.h"
#include "AIController.h"

#ifndef HELPLESSNESS_H
#define HELPLESSNESS_H

// 'Fears', an enemy type

class Helplessness :
	public Emotion
{
public:
	Helplessness(float x, float y, float radius, float speed);
	~Helplessness();

	// Functions specific to Fear
	void FollowPlayerIfClose(vec2<float> playerPos);

private:
	vec2<float> targetPoint;
	AIController aiController;
};
#endif // HELPLESSNESS_H

