#include "LevelScene.h"

#ifndef LEVEL2_H
#define LEVEL2_H

// Level 2!

class Level2 : public LevelScene
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

	std::vector<Fear*> fears;

	CollisionChecker collisionChecker;
	bool hasWon;
	bool restartLevel; // this might go in LevelScene
	vec2<float> startPosition;
};

#endif // LEVEL2_H

