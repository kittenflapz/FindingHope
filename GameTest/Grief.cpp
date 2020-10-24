#include "stdafx.h"
#include "Grief.h"

Grief::Grief(float x, float y, float radius, float speed) : Emotion{ x, y, radius, speed}
{
	SetPulseRate(.01f);
	// Grief color will always be the same, so we can set it here

	SetColor(0.243f, 0.109f, 0.2f);
}

Grief::~Grief()
{
}
