#pragma once
#include <Windows.h>

#include "GameVar.h"

class GameObject
{
public:
	GameObject();
	GameObject(float posX, float posY, short sizeX, short sizeY, CHAR_INFO * ascii, float speed, int life);
	~GameObject();
	void move(float x, float y);
	void display(CHAR_INFO buffer[CONSTANT::SCREEN_HEIGHT][CONSTANT::SCREEN_WIDTH]);
	void coloring();

protected:
	int m_color;
	int m_life;
	float m_speed;
	float m_posX;
	float m_posY;
	short m_sizeX;
	short m_sizeY;
	CHAR_INFO * m_ascii;
};

