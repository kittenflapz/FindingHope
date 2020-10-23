#pragma once
#include "Emotion.h"

#ifndef HOPE_H
#define HOPE_H

// To display 'Hopes', friendlies that the player needs to save by collecting

class Hope :
	public Emotion
{
public:
	Hope(float x, float y, float radius, float speed);
	~Hope();

	// Functions specific to Hope
};

#endif // HOPE_H

