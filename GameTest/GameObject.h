#include "stdafx.h"

#ifndef BENGINE_GAMEOBJECT_H
#define BENGINE_GAMEOBJECT_H

//---------------------------------------------------------------------------------
// Base class for all game objects
//---------------------------------------------------------------------------------
class  GameObject
{
public:
	int m_id; // The ID for the game object

	GameObject();
	virtual ~GameObject();

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	// Getters and setters
	void setID(int id);

	int getID() const;

};

#endif //BENGINE_GAMEOBJECT_H