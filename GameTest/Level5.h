#include "LevelScene.h"

#ifndef LEVEL5_H
#define LEVEL5_H

// Level 5!

class Level5 : public LevelScene
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

	Anxiety* anxiety;
	Helplessness* helplessness;

	CollisionChecker collisionChecker;
	bool hasWon;
	bool restartLevel; // this might go in LevelScene
	vec2<float> startPosition;

	// For ending the level gracefully
	float timeToWaitOnWinMessage;
	float timerForWinMessage;
};

#endif // LEVEL5_H
