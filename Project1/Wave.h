#pragma once

#include "Mob.h"
#include "AsciiGame.h"
class AsciiGame;
class Wave
{
public:
	Wave(AsciiGame* gameRef, Mob* waveMobs[CST::MOBS_COUNT], size_t waveLength, float spawnRate);
	~Wave();
	void start( float startTime);
	void update(float timeElapsed);
private:
	AsciiGame*	m_game;
	float		m_lastTime;
	size_t		m_wavelength;
	Mob*		m_waveMobs[CST::MOBS_COUNT];
	float		m_spawnRate;

	unsigned short	m_spawnCount;
	float			m_lastSpawn;
};

