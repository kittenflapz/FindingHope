#include "GameObject.h"
#include "app\app.h"

#ifndef LIGHT_H
#define LIGHT_H

class Light :
	public GameObject
{
public:
	Light(float x, float y);
	~Light();

	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
private:
	CSimpleSprite *sprite;
	vec2<float> position;
	

};
#endif LIGHT_H
