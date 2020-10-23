#include "stdafx.h"
#include "app\app.h"

#ifndef SCENE_H
#define SCENE_H

// Base class for Scenes.

class Scene
{
public:
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Shutdown() = 0;
};

#endif // SCENE_H
