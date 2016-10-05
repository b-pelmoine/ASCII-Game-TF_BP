#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(float posX, float posY, float sizeX, float sizeY, char * ascii);
	~GameObject();
	void move(void);
	void display(void);



private:
	float m_posX;
	float m_posY;
	short m_sizeX;
	short m_sizeY;
	char * m_ascii;
};

