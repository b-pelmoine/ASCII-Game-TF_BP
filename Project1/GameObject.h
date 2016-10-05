#pragma once
#include <Windows.h>
class GameObject
{
public:
	GameObject();
	GameObject(float posX, float posY, short sizeX, short sizeY, CHAR_INFO * ascii, float speed, int life);
	~GameObject();
	void move(void);
	void display(CHAR_INFO ** buffer);



private:
	int m_life;
	float m_speed;
	float m_posX;
	float m_posY;
	short m_sizeX;
	short m_sizeY;
	CHAR_INFO * m_ascii;
};

