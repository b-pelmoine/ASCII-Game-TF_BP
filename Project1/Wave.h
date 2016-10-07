#pragma once

#include "Mob.h"
#include "AsciiGame.h"

class Wave
{
public:
	Wave(AsciiGame* gameRef, Mob* waveMobs, size_t waveLength, float spawnRate);
	~Wave();
	void start( float startTime);
	void update(float timeElapsed);
private:
	AsciiGame*	m_game;
	float		m_lastTime;
	size_t		m_wavelength;
	Mob*		m_waveMobs;
	float		m_spawnRate;

	unsigned short	m_spawnCount;
	float			m_lastSpawn;
};

