#include "GameObject.h"
#include "stdafx.h"
#include "vec2.h"

#ifndef EMOTION_H
#define EMOTION_H

// Base class for 'Emotions' - NPCs

class Emotion :
	public GameObject
{
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
	void SetPosition(float x, float y);
	void SetRadius(float radius);
	void SetSpeed(float speed);
	void SetVelocity(float x, float y);
	void SetColor(float r, float g, float b);

private:
	vec2<float> position;
	vec2<float> velocity;
	float radius;
	float speed;
	float r;
	float g;
	float b;
	
};

#endif EMOTION_H
