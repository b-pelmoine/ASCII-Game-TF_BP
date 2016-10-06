#include "Bullet.h"



Bullet::Bullet(Direction direction)
{
	m_ascii = new CHAR_INFO();
	m_sizeX = 1;
	m_sizeY = 1;
	m_life = 1;
	m_speed = 0.5f;
	m_color = 5;
	spriteAndPosition();

}


Bullet::~Bullet()
{
}

void Bullet::spriteAndPosition() {
	switch (m_direction) {
	case North:
		m_posX = 13.0f;
		m_posY = 28.0f;
		m_ascii->Char.AsciiChar = '|';
		break;
	}
}