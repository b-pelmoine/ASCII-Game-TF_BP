#pragma once

#include "GameObject.h"

class Mob : public GameObject
{
	
public:
	static enum mobBreed {
		Tiny,
		Middle,
		Large
	};

	Mob(mobBreed breed, float posX, float posY);
	~Mob();



private:
	mobBreed m_breed;

};

