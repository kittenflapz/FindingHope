#pragma once
#include "GameObject.h"
class LightFuelBar :
	public GameObject
{
public:
	LightFuelBar(float x, float y, float width, float maxFuel);
	~LightFuelBar();

	// Overrides

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;

	// Getters and setters
	void SetMaxFuel();
	void SetCurrentFuel();
	float GetMaxFuel();
	float GetCurrentFuel();

	// Other functions
	void DecrementFuel();

private:
	vec2<float> position;
	float maxFuel;
	float currentFuel;
	float width;

};

