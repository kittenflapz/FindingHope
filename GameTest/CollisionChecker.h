#pragma once
#include "Player.h"
#include "Emotion.h"

// Various collision functions

class CollisionChecker
{
public: 
	bool PlayerEmotion(Player *paddle, Emotion *ball);
	bool CircleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
};

