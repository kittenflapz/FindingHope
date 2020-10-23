#include "stdafx.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Base class for game objects

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