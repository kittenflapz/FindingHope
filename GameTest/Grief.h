#include "Emotion.h"

#ifndef GRIEF_H
#define GRIEF_H

// 'Griefs', the enemy

class Grief :
	public Emotion
{
public:
	Grief(float x, float y, float radius, float speed);
	~Grief();

	// Functions specific to Grief

};
#endif // GRIEF_H

