#pragma once

#include <thread>

#include "Sound.h"

/*
===============================================================================
> SoundPlayer
Let the user play defined sounds (The class use the Windows Beep() function)
===============================================================================
*/

class SoundPlayer
{
public:
	SoundPlayer();
	~SoundPlayer();
	void play(Sound* sounds[], size_t size);
};

