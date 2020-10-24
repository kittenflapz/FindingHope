#include "LevelScene.h"

#ifndef LEVEL1_H
#define LEVEL1_H

// Level 1!

class Level1 :
	public LevelScene
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

	std::vector<Grief*> griefs;


	CollisionChecker collisionChecker;
	bool hasWon;
	bool restartLevel; 
	vec2<float> startPosition;

	// For ending the level gracefully
	float timeToWaitOnWinMessage;
	float timerForWinMessage;

};

#endif

