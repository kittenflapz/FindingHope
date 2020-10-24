#include "stdafx.h"
#include "app\app.h"

#ifndef SCENE_H
#define SCENE_H


enum class SceneState
{
	NO_SCENE = -1,
	TITLE_SCENE,
	LEVEL1_SCENE,
	LEVEL2_SCENE,
	LEVEL3_SCENE,
	GAMEOVER_SCENE,
	WIN_SCENE,
	NUM_OF_SCENES
};

// Base class for scenes
class Scene
{
public:
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Shutdown() = 0;
};

#endif // SCENE_H
