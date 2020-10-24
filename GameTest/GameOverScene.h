#include "Scene.h"

#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

// The game over scene
class GameOverScene :
	public Scene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;

private:
	std::string gameOverString;
	std::string playAgainString;
	Light* light;

};

#endif // GAMEOVERSCENE_H
