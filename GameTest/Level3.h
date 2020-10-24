#include "LevelScene.h"

#ifndef LEVEL3_H
#define LEVEL3_H

// Level 3!

class Level3 : public LevelScene
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
	std::vector<Grief*> griefs;

	CollisionChecker collisionChecker;
	bool hasWon;
	bool restartLevel; // this might go in LevelScene
	vec2<float> startPosition;
};

#endif // LEVEL3_H
