#pragma once

#include "GameObject.h"


enum mobBreed {
	Tiny,
	Middle,
	Large
};

class Mob : public GameObject
{
	
public:

	Mob(mobBreed breed, float posX, float posY);
	~Mob();



private:
	mobBreed m_breed;

};

