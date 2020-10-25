#include "LevelScene.h"

#ifndef LEVEL8_H
#define LEVEL8_H

// Level 8!

class Level8 : public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
};

#endif // LEVEL8_H
