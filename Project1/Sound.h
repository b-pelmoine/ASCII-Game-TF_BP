#pragma once

#include <Windows.h>


/*
===============================================================================
> Sound
Let the user define sound providing a base Harmonics, its range and a duration
===============================================================================
*/

class Sound
{
public:
	Sound(const float hrm, unsigned short range, DWORD duration);
	~Sound();
	DWORD freq	( void ) const;
	DWORD dur	( void ) const;
private:
	DWORD m_freq;
	DWORD m_duration;
};


