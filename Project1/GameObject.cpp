#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(float posX, float posY, float sizeX, float sizeY, char * ascii) : m_posX(posX), m_posY(posY), m_sizeX(sizeX), m_sizeY(sizeY), m_ascii(ascii)
{
}


GameObject::~GameObject()
{
}

void GameObject::move(void)
{
}

void GameObject::display(void)
{
}
