#include "LevelScene.h"

#ifndef LEVEL6_H
#define LEVEL6_H

// Level 6!

class Level6 : public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
};

#endif // LEVEL6_H
