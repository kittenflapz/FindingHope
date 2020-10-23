#include "stdafx.h"
#include "GameObject.h"
#include <vector>

GameObject::GameObject() 
{

}

void GameObject::setID(int id)
{
	m_id = id;
}


int GameObject::getID() const // ***Not sure any of the ID stuff is needed***
{
	return m_id;
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