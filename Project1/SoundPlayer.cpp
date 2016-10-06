#include "SoundPlayer.h"

//! Ctor
SoundPlayer::SoundPlayer()
{
}


//! Dtor
SoundPlayer::~SoundPlayer()
{
}

//! play
/*
* play the sound
*/
void SoundPlayer::play(Sound* sounds[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		Beep(sounds[i]->freq(), sounds[i]->dur());
	}
}