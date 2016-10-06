#pragma once
#include "GameObject.h"

enum Direction {
	North,
	NorthWest,
	West,
	SouthWest,
	South,
	SouthEast,
	East,
	NorthEast
};

class Bullet : public GameObject
{
public:
	Bullet(Direction direction);
	~Bullet();
	void spriteAndPosition();

private:
	Direction	m_direction;
};



