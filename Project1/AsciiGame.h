#pragma once

#include <Windows.h>
#include <map>
#include <string>
#include <thread>

#include "NYTimer.h"
#include "GameObject.h"
#include "SoundPlayer.h"
#include "Player.h"
#include "Bullet.h"

/*
===============================================================================
> AsciiGame
Game engine class in charge of the whole game logic
===============================================================================
*/

using pair_SSND = std::pair < std::string, Sound* > ;

class AsciiGame
{
public:
	AsciiGame();
	~AsciiGame();
	void start( void );

private:
	void clear( void );
	void render( void );
	void handleInputs( void );
	void update( float );

	/* inputs */
	const int	INPUT_LEFT	 = 0x25;
	const int	INPUT_TOP	 = 0x26;
	const int	INPUT_RIGHT	 = 0x27;
	const int	INPUT_DOWN	 = 0x28;
	bool		m_leftIsPressed;
	bool		m_topIsPressed;
	bool		m_rightIsPressed;
	bool		m_downIsPressed;

	/* Game engine */
	bool	m_isRunning;
	NYTimer m_timer;
	float		m_sec;

	/* Game Window */
	HANDLE				m_hOutput;
	COORD				m_dwBufferSize;
	COORD				m_dwBufferCoord;
	SMALL_RECT			m_rcRegion;
	const SMALL_RECT*	p_rcRegion = &m_rcRegion;
	CHAR_INFO			m_buffer[CST::SCREEN_HEIGHT][CST::SCREEN_WIDTH];

	/* GameObjects */
	GameObject*		m_mobs[CST::MOBS_COUNT];		/* pool containing mobs */
	Bullet*		m_bullets[CST::BULLETS_COUNT];	/* pool containing particles */
	GameObject*		m_player;

	/* SoundHandler */
	SoundPlayer						m_sndPlayer;
	std::map<std::string, Sound*>	m_regSounds; /* registered sounds*/
};

