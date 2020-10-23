#include "stdafx.h"
#include "vec2.h"
#include "GameObject.h"

#ifndef PLAYER_H
#define PLAYER_H

// The player class. Handles most input.

class Player :
	public GameObject
{
public:
	Player(float x, float y, float w, float h, float speed);
	~Player();

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;


	// Getters and setters
	vec2<float> GetPosition() { return position; }
	vec2<float> GetScale() { return scale; }
	float GetSpeed() { return speed; }
	float GetDefaultRColour() { return defaultR; }
	float GetDefaultGColour() { return defaultG; }
	float GetDefaultBColour() { return defaultB; }
	void SetPosition(float x, float y);
	void SetScale(float w, float h);
	void SetSpeed(float speed);
	void SetColor(float r, float g, float b);

private:
	vec2<float> position;
	vec2<float> scale;
	float speed;

	// Colour variables
	// Current
	float r;
	float b;
	float g;

	// To default back to
	float defaultR;
	float defaultG;
	float defaultB;
};
#endif // PLAYER_H
