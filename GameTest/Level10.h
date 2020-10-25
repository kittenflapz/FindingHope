#include "LevelScene.h"

#ifndef LEVEL10_H
#define LEVEL10_H

// Level 10!

class Level10 : public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
};

#endif // LEVEL10_H
