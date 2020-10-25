#include "GameObject.h"
#include "stdafx.h"
#include "vec2.h"

#ifndef EMOTION_H
#define EMOTION_H

// Base class for 'Emotions' - NPCs



class Emotion :
	public GameObject
{
	enum class BlinkState
	{
		BLINKING,
		NOTBLINKING
	};


public:
	Emotion(float x, float y, float radius, float speed);
	~Emotion();

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;

	// Getters and setters
	vec2<float> GetPosition() { return position; }
	float GetRadius() { return radius; }
	float GetSpeed() { return speed; }
	vec2<float> GetVelocity() { return velocity; }
	vec2<float> GetPlayerPosition() { return playerPosition; }
	void SetPosition(float x, float y);
	void SetRadius(float radius);
	void SetSpeed(float speed);
	void SetVelocity(float x, float y);
	void SetColor(float r, float g, float b);
	void SetPulseRate(float pulseRate);
	void SetPlayerPosition(vec2<float> playerPosition);

	void Pulse(float deltaTime);
	BlinkState SwitchStateAndResetBlinkTime();



private:
	// Movement
	vec2<float> position;
	vec2<float> velocity;
	vec2<float> playerPosition;
	float radius;
	float maxRadius;
	float minRadius;
	float speed;

	// Animation
	float pulser;
	
	// Color
	float r;
	float g;
	float b;

	// Blink
	BlinkState currentBlinkState;
	double blinkStateTime;
	double blinkTimer;



};

#endif EMOTION_H
