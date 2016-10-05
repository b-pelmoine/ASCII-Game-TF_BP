#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(float posX, float posY, short sizeX, short sizeY, CHAR_INFO * ascii, float speed, int life) : m_posX(posX), m_posY(posY), m_sizeX(sizeX), m_sizeY(sizeY), m_speed(speed), m_life(life)
{
	m_ascii = new CHAR_INFO[sizeX*sizeY];
}


GameObject::~GameObject()
{
	delete [] m_ascii;
}

void GameObject::move(float x, float y)
{
	m_posX += x;
	m_posY += y;
}

void GameObject::display(CHAR_INFO ** buffer)
{
	for (int x = 0; x < m_sizeX; ++x ) {
		for (int y = 0; y < m_sizeY; ++y) {
			buffer[x + (int)(m_posX)][y + (int)(m_posY)] = m_ascii[ x + y * m_sizeX];
		}
	}
}
