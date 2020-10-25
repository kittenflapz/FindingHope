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
};

#endif // LEVEL2_H

