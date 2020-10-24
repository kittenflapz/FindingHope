#include "stdafx.h"
#include "vec2.h"
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

/*Base class for game objects.
Originally, I had included the beginning of a component system here, but as the ideas developed for the game 
I realized that each GameObject (namely the enemies) were different enough that most, if not all, components
would only end up being used once. It may be something for the roadmap to integrate (especially for AI additions)
but for now this simple inheritance system is easier to use and, I think, easier to understand. */

class  GameObject
{
public:
	int id; // The ID for the game object

	GameObject();
	virtual ~GameObject(); // Memory leaks are spooky 

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	// Getters and setters
	void setID(int id);

	int getID() const;

};

#endif GAMEOBJECT_H