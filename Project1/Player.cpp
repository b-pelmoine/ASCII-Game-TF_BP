#include "Player.h"



Player::Player()
{
	CHAR_INFO * ascii = new CHAR_INFO();
	ascii[0].Char.AsciiChar = '/';
	ascii[1].Char.AsciiChar = '*';
	ascii[2].Char.AsciiChar = '\\';
	ascii[3].Char.AsciiChar = '*';
	ascii[4].Char.AsciiChar = '#';
	ascii[5].Char.AsciiChar = '*';
	ascii[6].Char.AsciiChar = '\\';
	ascii[7].Char.AsciiChar = '*';
	ascii[8].Char.AsciiChar = '/';
	m_color = 3;
	m_posX = 27.0f;
	m_posY = 12.0f;
	m_sizeX = 3;
	m_sizeY = 3;
	m_ascii = ascii;
	m_speed = 0.0f;
	m_life = 3;
	coloring();
}


Player::~Player()
{
}
