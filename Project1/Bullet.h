#pragma once
#include "GameObject.h"

enum Direction {
	None,
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
	void move();
	void instantiate(Direction direction);

	static int placeInPool;
private:
	Direction	m_direction;
	void		increment();
};
