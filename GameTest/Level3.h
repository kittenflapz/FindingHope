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
};

#endif // LEVEL3_H
