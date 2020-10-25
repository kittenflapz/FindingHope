#include "stdafx.h"
#include "Scene.h"

#ifndef LEVELSCENE_H
#define LEVELSCENE_H

// Base class for gameplay levels
// May be unnecessary as everything could derive directly from Scene, but this is more organized
class LevelScene : public Scene
{
public:
	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown() = 0;

	// Getters and setters
	inline bool LightIsOn() { return lightOn; }
	inline void SetLightOn(bool lightOn) { this->lightOn = lightOn; }

private:
	bool lightOn;
	CSimpleSprite* flameSprites[3];
	std::string chapterIntroText;
	bool showStartText;
	float startTextDelay;
	float startTextTimer;
};

#endif //BENGINE_GAMESCENE_H