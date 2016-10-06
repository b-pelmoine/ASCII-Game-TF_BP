#include "Sound.h"

//! Ctor
/*
* ~ init the sound properties
* hrm is a base harmonic
* range is the range of the harmonic
* duration the duration the sound must be played
*/
Sound::Sound(const float hrm, unsigned short range, DWORD duration)
{
	m_freq = static_cast<DWORD>(hrm * range);
	m_duration = duration;
}

//! Dtor
Sound::~Sound()
{
}

//! freq
/*
* return computed frequency
*/
DWORD Sound::freq() const
{
	return m_freq;
}

//! dur
/*
* return duration
*/
DWORD Sound::dur() const
{
	return m_duration;
}