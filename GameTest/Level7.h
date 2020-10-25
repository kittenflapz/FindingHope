#include "LevelScene.h"

#ifndef LEVEL7_H
#define LEVEL7_H

// Level 7!

class Level7 : public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
};

#endif // LEVEL7_H
