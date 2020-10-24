#include "Scene.h"

#ifndef WINSCENE_H
#define WINSCENE_H

// The game over scene
class WinScene :
	public Scene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;

private:
	std::string winString;
	std::string playAgainString;
	Light* light;

};

#endif // WINSCENE_H
