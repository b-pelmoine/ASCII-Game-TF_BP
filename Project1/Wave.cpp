#include "Wave.h"

Wave::Wave(AsciiGame* gameRef, Mob* waveMobs[CST::MOBS_COUNT], size_t waveLength, float spawnRate) : m_spawnCount(0)
{
	for (size_t i = 0; i < waveLength; i++)
	{
		m_waveMobs[i] = waveMobs[i];
	}
	m_wavelength = waveLength;
	m_spawnRate = spawnRate;
	m_game = gameRef;
}

Wave::~Wave()
{
}

void Wave::start(float startTime)
{	
	m_lastTime = startTime;
	m_lastSpawn = startTime;
}

void Wave::update(float timeElapsed)
{
	if (timeElapsed - m_lastSpawn < m_spawnRate){
		if (m_spawnCount < m_wavelength) ++m_spawnCount;
		m_lastSpawn = timeElapsed;
		//m_waveMobs[m_spawnCount]->pop();
	}
	for (size_t i = 0; i < m_spawnCount; ++i)
	{
		m_waveMobs[i]->update();
	}

	bool playerAlive = m_game->isPlayerAlive();
	bool waveWon = true;
	for (size_t i = 0; i < m_wavelength; ++i)
	{
		if (m_waveMobs[i]->isAlive())
		{
			waveWon = false;
			break;
		}
	}
	if (!playerAlive)
	{
		m_game->waveEnded(false);
	}
	if (waveWon && playerAlive)
	{
		m_game->waveEnded(true);
	}
}