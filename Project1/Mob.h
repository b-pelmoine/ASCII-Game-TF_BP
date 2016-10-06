#pragma once

#include "GameObject.h"


enum MobBreed {
	Tiny,
	Middle,
	Large
};

class Mob : public GameObject
{
	
public:

	Mob(MobBreed breed, float posX, float posY);
	~Mob();



private:
	MobBreed m_breed;

};

