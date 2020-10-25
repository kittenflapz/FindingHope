#include "LevelScene.h"

#ifndef LEVEL9_H
#define LEVEL9_H

// Level 9!

class Level9 : public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
};

#endif // LEVEL9_H
