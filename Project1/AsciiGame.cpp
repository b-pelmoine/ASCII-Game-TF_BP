#include "AsciiGame.h"

//! Ctor
/*
 * init the game window properties
 * init gameObject pools
 */
AsciiGame::AsciiGame() : m_isRunning(false)
{
	/* game window */
	m_hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	m_dwBufferSize = { CONSTANT::SCREEN_WIDTH, CONSTANT::SCREEN_HEIGHT };
	m_dwBufferCoord = { 0, 0 };
	m_rcRegion = { 0, 0, CONSTANT::SCREEN_WIDTH - 1, CONSTANT::SCREEN_HEIGHT - 1 };

	SetConsoleWindowInfo(m_hOutput, true, p_rcRegion);

	/* GameObject pools */
	for (int i = 0; i < CONSTANT::MOBS_COUNT; ++i)
	{
		m_mobs[i] = new GameObject;
	}
	for (int i = 0; i < CONSTANT::BULLETS_COUNT; ++i)
	{
		m_bullets[i] = new GameObject;
	}
	m_player = new Player;
}

//! Dtor
AsciiGame::~AsciiGame()
{
	for (int i = 0; i < CONSTANT::MOBS_COUNT; ++i)
	{
		delete[] m_mobs[i];
	}
	for (int i = 0; i < CONSTANT::BULLETS_COUNT; ++i)
	{
		delete[] m_bullets[i];
	}
	delete p_rcRegion;
	delete m_player;
}

//! start the game
/*
 * launch the game instance
 */
void AsciiGame::start()
{
	m_isRunning = true;
	m_timer.start();
	while (m_isRunning){
		handleInputs();
		update(m_timer.getElapsedSeconds());
		render();
	}
}

//! render the window
/*
* clear the portion of the game window that aren't up-to-date and draw on top the new context
*/
void AsciiGame::render()
{
	clear();
	ReadConsoleOutput(m_hOutput, (CHAR_INFO *)m_buffer, m_dwBufferSize,
		m_dwBufferCoord, &m_rcRegion);

	for (size_t i = 0; i < CONSTANT::MOBS_COUNT; i++)
	{
		m_mobs[i]->display(m_buffer);
	}
	for (size_t i = 0; i < CONSTANT::BULLETS_COUNT; i++)
	{
		m_mobs[i]->display(m_buffer);
	}
	m_player->display(m_buffer);

	WriteConsoleOutput(m_hOutput, (CHAR_INFO *)m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);
}

//! clear
/*
* clear a portion of the game Window
*/
void AsciiGame::clear()
{
	for (size_t i = 0; i < CONSTANT::SCREEN_WIDTH; i++)
	{
		for (size_t j = 0; j < CONSTANT::SCREEN_HEIGHT; j++)
		{
			m_buffer[j][i].Char.AsciiChar = ' ';
			m_buffer[j][i].Attributes = 0x00;
		}
	}
}

//! handle inputs
/*
* command pattern tied to the player game object
*/
void AsciiGame::handleInputs()
{
	m_leftIsPressed = (GetKeyState(INPUT_LEFT) & 0x8000) ? true : false;
	m_topIsPressed = (GetKeyState(INPUT_TOP) & 0x8000) ? true : false;
	m_rightIsPressed = (GetKeyState(INPUT_RIGHT) & 0x8000) ? true : false;
	m_downIsPressed = (GetKeyState(INPUT_DOWN) & 0x8000) ? true : false;
}

//! update game objects
/*
* run through all game object and update there components (AI, position)
*/
void AsciiGame::update(float timeElapsed){
	
}