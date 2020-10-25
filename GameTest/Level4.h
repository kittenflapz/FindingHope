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
};

#endif // LEVEL4_H
