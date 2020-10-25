#include "Scene.h"

#ifndef WINSCENE_H
#define WINSCENE_H

// The win scene
class WinScene :
	public Scene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;

private:
	Light* light;
	CSimpleSprite* winText;
};

#endif // WINSCENE_H
