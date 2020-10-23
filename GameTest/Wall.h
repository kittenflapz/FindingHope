#include "GameObject.h"

#ifndef WALL_H
#define WALL_H
class Wall :
	public GameObject
{
public:
	Wall(float x, float y, float w, float h, float r, float g, float b);
	~Wall();

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;


	// Getters and setters
	vec2<float> GetPosition() { return position; }
	vec2<float> GetScale() { return scale; }

private:
	vec2<float> position;
	vec2<float> scale;

	float r;
	float b;
	float g;
};
#endif WALL_H