#include "LevelScene.h"

#ifndef PROLOGUE_H
#define PROLOGUE_H

// Level 1!

class Prologue :
	public LevelScene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
private:
};

#endif // PROLOGUE_H
