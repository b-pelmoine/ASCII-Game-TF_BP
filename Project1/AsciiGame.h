#pragma once

#include <Windows.h>
#include "NYTimer.h"

const short SCREEN_WIDTH = 60;
const short SCREEN_HEIGHT = 30;

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
};

