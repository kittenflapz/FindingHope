#include "stdafx.h"
#include "Scene.h"

#ifndef LEVELSCENE_H
#define LEVELSCENE_H

// Base class for gameplay levels
// May be unnecessary as everything could derive directly from Scene, but this is more organized
class LevelScene : public Scene
{
public:
	void Init() = 0;
	void Update(float deltaTime) = 0;
	void Render() = 0;
	void Shutdown() = 0;
};

#endif //BENGINE_GAMESCENE_H