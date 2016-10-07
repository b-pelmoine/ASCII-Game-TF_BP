#include "Bullet.h"



int Bullet::placeInPool = 0;

Bullet::Bullet(Direction direction)
{
	m_direction = direction;
	m_ascii = new CHAR_INFO();
	m_sizeX = 1;
	m_sizeY = 1;
	m_life = 1;
	m_speed = 0.005f;
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
		m_posX = 28.0f;
		m_posY = 11.0f;
		m_ascii->Char.AsciiChar = '|';
		break;
	case NorthEast:
		m_posX = 31.0f;
		m_posY = 11.0f;
		m_ascii->Char.AsciiChar = '/';
		break;
	case NorthWest:
		m_posX = 25.0f;
		m_posY = 11.0f;
		m_ascii->Char.AsciiChar = '\\';
		break;
	case East:
		m_posX = 31.0f;
		m_posY = 13.0f;
		m_ascii->Char.AsciiChar = '-';
		break;
	case West:
		m_posX = 25.0f;
		m_posY = 13.0f;
		m_ascii->Char.AsciiChar = '-';
		break;
	case SouthEast:
		m_posX = 31.0f;
		m_posY = 15.0f;
		m_ascii->Char.AsciiChar = '\\';
		break;
	case SouthWest:
		m_posX = 25.0f;
		m_posY = 15.0f;
		m_ascii->Char.AsciiChar = '/';
		break;
	case South:
		m_posX = 28.0f;
		m_posY = 15.0f;
		m_ascii->Char.AsciiChar = '|';
		break;
	default:
		m_posX = -1.0f;
		m_posY = -1.0f;
		m_ascii->Char.AsciiChar = ' ';
		break;
	}
}

void Bullet::move()
{
	switch (m_direction) {
	case North:
		m_posY -= m_speed;
		break;
	case East:
		m_posX += m_speed;
		break;
	case West:
		m_posX -= m_speed;
		break;
	case South:
		m_posY += m_speed;
		break;
	case NorthEast:
		m_posX += m_speed;
		m_posY -= m_speed;
		break;
	case NorthWest:
		m_posX -= m_speed;
		m_posY -= m_speed;
		break;
	case SouthEast:
		m_posX += m_speed;
		m_posY += m_speed;
		break;
	case SouthWest:
		m_posX -= m_speed;
		m_posY += m_speed;
		break;
	}
}

void Bullet::instantiate(Direction direction)
{
	increment();
	m_direction = direction;
	spriteAndPosition();
}

void Bullet::increment() {
	++placeInPool;
	if (placeInPool > CST::BULLETS_COUNT)
		placeInPool = 0;
}