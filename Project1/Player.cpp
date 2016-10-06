#include "Player.h"



Player::Player()
{
	CHAR_INFO * ascii = new CHAR_INFO();
	ascii[0].Char.AsciiChar = '/';
	ascii[0].Attributes = 0x0001;
	ascii[1].Char.AsciiChar = '*';
	ascii[1].Attributes = 0x0001;
	ascii[2].Char.AsciiChar = '\\';
	ascii[2].Attributes = 0x0001;
	ascii[3].Char.AsciiChar = '*';
	ascii[3].Attributes = 0x0001;
	ascii[4].Char.AsciiChar = '#';
	ascii[4].Attributes = 0x0001;
	ascii[5].Char.AsciiChar = '*';
	ascii[5].Attributes = 0x0001;
	ascii[6].Char.AsciiChar = '\\';
	ascii[6].Attributes = 0x0001;
	ascii[7].Char.AsciiChar = '*';
	ascii[7].Attributes = 0x0001;
	ascii[8].Char.AsciiChar = '/';
	ascii[8].Attributes = 0x0001;
	m_posX = 30.0f;
	m_posY = 15.0f;
	m_sizeX = 3;
	m_sizeY = 3;
	m_ascii = ascii;
	m_speed = 0.0f;
	m_life = 3;
}


Player::~Player()
{
}
