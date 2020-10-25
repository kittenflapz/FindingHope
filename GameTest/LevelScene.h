#include "stdafx.h"
#include "Scene.h"

#ifndef LEVELSCENE_H
#define LEVELSCENE_H

// Base class for gameplay levels

class LevelScene : public Scene
{
public:
	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();

	// Getters and setters
	inline bool LightIsOn() { return lightOn; }
	inline void SetLightOn(bool lightOn) { this->lightOn = lightOn; }

	void SetStartText(std::string chapterIntroText);

	CollisionChecker GetCollisionChecker();

	void SetPlayerStartPosition(vec2<float> startPos);
	vec2<float> GetPlayerStartPosition();

	void SetHopeStartPosition(vec2<float> startPos);
	vec2<float> GetHopeStartPosition();

	Player* GetPlayer();
	Hope* GetHope();


	// Other functions

	void RestartLevel();
	void Win();
	void CreatePlayer();
	void CreateHope();
	bool HasWon();
	bool LevelRestart();
	void AddToEnemyList(Emotion* enemy);

private:
	// UI
	CSimpleSprite* flameSprites[3];
	Typewriter* typewriter;
	std::string chapterIntroText;

	// For ending the level gracefully
	float timeToWaitOnWinMessage;
	float timerForWinMessage;

	// GameObjects
	LightFuelBar* lightFuelBar;
	Light* light;
	Player* player;
	Hope* hope;
	std::vector<Emotion*> enemyList;


	CollisionChecker collisionChecker;

	// Gameplay
	bool hasWon;
	bool restartLevel;
	bool lightOn;
	vec2<float> playerStartPosition; 
	vec2<float> hopeStartPosition;


};

#endif //BENGINE_GAMESCENE_H