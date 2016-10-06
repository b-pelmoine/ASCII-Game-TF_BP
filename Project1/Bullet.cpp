#include "Bullet.h"



Bullet::Bullet(Direction direction)
{
	m_direction = direction;
	m_ascii = new CHAR_INFO();
	m_sizeX = 1;
	m_sizeY = 1;
	m_life = 1;
	m_speed = 0.5f;
	m_color = 5;
	spriteAndPosition();
	coloring();

}


Bullet::~Bullet()
{
}

void Bullet::spriteAndPosition() {
	switch (m_direction) {
	case North:
		m_posX = 11.0f;
		m_posY = 28.0f;
		m_ascii->Char.AsciiChar = '|';
		break;
	case NorthEast:
		m_posX = 11.0f;
		m_posY = 31.0f;
		m_ascii->Char.AsciiChar = '/';
		break;
	case NorthWest:
		m_posX = 11.0f;
		m_posY = 25.0f;
		m_ascii->Char.AsciiChar = '\\';
		break;
	case East:
		m_posX = 13.0f;
		m_posY = 25.0f;
		m_ascii->Char.AsciiChar = '-';
		break;
	case West:
		m_posX = 13.0f;
		m_posY = 31.0f;
		m_ascii->Char.AsciiChar = '-';
		break;
	case SouthEast:
		m_posX = 15.0f;
		m_posY = 31.0f;
		m_ascii->Char.AsciiChar = '\\';
		break;
	case SouthWest:
		m_posX = 15.0f;
		m_posY = 25.0f;
		m_ascii->Char.AsciiChar = '/';
		break;
	case South:
		m_posX = 15.0f;
		m_posY = 28.0f;
		m_ascii->Char.AsciiChar = '|';
		break;
	}
}