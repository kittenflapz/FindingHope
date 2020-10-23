#include "stdafx.h"
#include "GameObject.h"
#include <vector>

GameObject::GameObject() : id(0)
{

}

void GameObject::setID(int id)
{
	id = id;
}


int GameObject::getID() const // ***Not sure any of the ID stuff is needed***
{
	return id;
}



void GameObject::Init()
{


}
void GameObject::Update(float deltaTime) 
{

}
void GameObject::Render()
{

}

GameObject::~GameObject()
{

}