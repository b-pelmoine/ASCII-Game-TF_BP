#include "Mob.h"



Mob::Mob(Mob::mobBreed breed, float posX, float posY)
{
	switch (breed)
	{
	case Mob::mobBreed::Tiny :
		CHAR_INFO ascii[3];
		ascii[0].Char.AsciiChar = '<';
		ascii[0].Attributes = 0x0004;
		ascii[1].Char.AsciiChar = '^';
		ascii[1].Attributes = 0x0004;
		ascii[2].Char.AsciiChar = '>';
		ascii[2].Attributes = 0x0004;
		GameObject(posX, posY, 1, 3, ascii, 0.2f, 1);
		break;

	default:
		break;
	}
}


Mob::~Mob()
{
}
