#include "stdafx.h"
#include "app\app.h"

#ifndef SCENE_H
#define SCENE_H


enum class SceneState
{
	NO_SCENE = -1,
	TITLE_SCENE,
	PROLOGUE, 
	LEVEL1_SCENE,
	LEVEL2_SCENE,
	LEVEL3_SCENE,
	LEVEL4_SCENE,
	LEVEL5_SCENE,
	LEVEL6_SCENE,
	LEVEL7_SCENE,
	LEVEL8_SCENE,
	LEVEL9_SCENE,
	LEVEL10_SCENE,
	WIN_SCENE,
	GAMEOVER_SCENE,
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
