#include "stdafx.h"
#include "Hope.h"

Hope::Hope(float x, float y, float radius, float speed) : Emotion{ x, y, radius, speed }
{
	// Hope color will always be the same, so we can set it here

	SetColor(0.964f, 0.572f, 0.113f);
}

Hope::~Hope()
{
}
