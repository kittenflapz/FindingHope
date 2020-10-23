#pragma once
#include "Player.h"
#include "Emotion.h"
class CollisionChecker
{
public: 
	// Functions to check collisions!
	bool PlayerEmotion(Player *paddle, Emotion *ball);
	int PaddleBallResponse(Player paddle, Emotion ball);
	bool CircleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
};

