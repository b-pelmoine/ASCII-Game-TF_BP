#pragma once

#include <Windows.h>
#include <vector>

#include "NYTimer.h"
#include "GameObject.h"

/*
===============================================================================
> AsciiGame
Game engine class in charge of the whole game logic
===============================================================================
*/

class AsciiGame
{
public:
	AsciiGame();
	~AsciiGame();
	void start( void );
private:
	void clear( void );
	void render( unsigned long );
	void handleInputs( void );
	void update( unsigned long );

	/* Const */
	const static short SCREEN_WIDTH = 60;
	const static short SCREEN_HEIGHT = 30;
	const static short MOBS_COUNT = 50;
	const static short BULLETS_COUNT = 50;

	/* Game engine */
	bool	m_isRunning;
	NYTimer m_timer;

	/* Game Window */
	HANDLE m_hOutput;
	COORD m_dwBufferSize;
	COORD m_dwBufferCoord;
	SMALL_RECT m_rcRegion;
	const SMALL_RECT* p_rcRegion = &m_rcRegion;
	CHAR_INFO m_buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	/* GameObjects */
	GameObject** m_mobs; /* pool containing mobs */
	GameObject** m_bullets; /* pool containing particles */
	GameObject* m_player;
};

