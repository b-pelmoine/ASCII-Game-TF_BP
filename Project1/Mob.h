#pragma once

#include "GameObject.h"

class Mob : public GameObject
{
	enum mobBreed {
		Tiny,
		Middle,
		Large
	};
public:
	Mob(mobBreed breed, float posX, float posY);
	~Mob();

private:
	mobBreed m_breed;

};

