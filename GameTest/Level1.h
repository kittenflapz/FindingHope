#include "LevelScene.h"
#include "GameManager.h"

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
};

#endif

