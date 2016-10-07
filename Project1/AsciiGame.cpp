#include "AsciiGame.h"

namespace VAR{
	namespace SND{
		Sound*	MAIN_THEME[CST::SND::MAIN_THEME_t];
		Sound*	MOB_DEATH[CST::SND::MOB_DEATH_t];
		Sound*	MOB_HIT[CST::SND::MOB_HIT_t];
		Sound*	WAVE_START[CST::SND::WAVE_START_t];
		Sound*	WAVE_LOST[CST::SND::WAVE_LOST_t]; // defeat
		Sound*	WAVE_WIN[CST::SND::WAVE_WIN_t]; // lvl_up
		Sound*	PLAYER_HIT[CST::SND::PLAYER_HIT_t];
	}
}

//! Ctor
/*
 * init the game window properties
 * init gameObject pools
 */
AsciiGame::AsciiGame() : m_isRunning(false)
{
	/* game window */
	m_hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	m_dwBufferSize = { CST::SCREEN_WIDTH, CST::SCREEN_HEIGHT };
	m_dwBufferCoord = { 0, 0 };
	m_rcRegion = { 0, 0, CST::SCREEN_WIDTH - 1, CST::SCREEN_HEIGHT - 1 };

	SetConsoleWindowInfo(m_hOutput, true, p_rcRegion);

	/* GameObject pools */
	for (int i = 0; i < CST::MOBS_COUNT; ++i)
	{
		m_mobs[i] = new GameObject;
	}
	for (int i = 0; i < CST::BULLETS_COUNT; ++i)
	{
		m_bullets[i] = new GameObject;
	}
	//m_player = new 

	/* Sound initialization */
	m_regSounds.insert(pair_SSND("A7_100", new Sound(CST::HRM::A, 7, 100)));
	m_regSounds.insert(pair_SSND("As7_150", new Sound(CST::HRM::As, 7, 150)));
	m_regSounds.insert(pair_SSND("C5_250", new Sound(CST::HRM::C, 5, 250)));

	VAR::SND::MOB_DEATH[0] = m_regSounds["A7_100"];
	VAR::SND::MOB_DEATH[1] = m_regSounds["As7_150"];
	VAR::SND::MOB_DEATH[2] = m_regSounds["C5_250"];

	std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::MOB_DEATH, CST::SND::MOB_DEATH_t).detach();
	//m_sndPlayer.play(VAR::SND::MOB_DEATH, CST::SND::MOB_DEATH_t);
}

//! Dtor
AsciiGame::~AsciiGame()
{
	for (int i = 0; i < CST::MOBS_COUNT; ++i)
	{
		delete[] m_mobs[i];
	}
	for (int i = 0; i < CST::BULLETS_COUNT; ++i)
	{
		delete[] m_bullets[i];
	}
	delete p_rcRegion;
	delete m_player;

	for (auto& snd : m_regSounds)
	{
		delete snd.second;
	}
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

	for (size_t i = 0; i < CST::MOBS_COUNT; i++)
	{
		m_mobs[i]->display(m_buffer);
	}
	for (size_t i = 0; i < CST::BULLETS_COUNT; i++)
	{
		m_bullets[i]->display(m_buffer);
	}

	WriteConsoleOutput(m_hOutput, (CHAR_INFO *)m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);
}

//! clear
/*
* clear a portion of the game Window
*/
void AsciiGame::clear()
{
	for (size_t i = 0; i < CST::SCREEN_WIDTH; i++)
	{
		for (size_t j = 0; j < CST::SCREEN_HEIGHT; j++)
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