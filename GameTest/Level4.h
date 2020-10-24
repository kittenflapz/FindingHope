#include "LevelScene.h"

#ifndef LEVEL4_H
#define LEVEL4_H

// Level 4!

class Level4 : public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
	Player* player;
	Hope* hope;
	LightFuelBar* lightFuelBar;
	Light* light;

	Perfectionism *perfectionism;

	CollisionChecker collisionChecker;
	bool hasWon;
	bool restartLevel; // this might go in LevelScene
	vec2<float> startPosition;

	// For ending the level gracefully
	float timeToWaitOnWinMessage;
	float timerForWinMessage;
};

#endif // LEVEL4_H
