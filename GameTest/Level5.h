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
};

#endif // LEVEL5_H
