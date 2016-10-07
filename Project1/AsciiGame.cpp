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
AsciiGame::AsciiGame() : m_isRunning(false), m_wlvl(0)
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
		m_bullets[i] = new Bullet(Direction::None);
	}
	m_player = new Player;

	/* Sound initialization */
	m_regSounds.insert(pair_SSND("A7_100"	, new Sound(CST::HRM::A, 7, 100)));
	m_regSounds.insert(pair_SSND("As7_150"	, new Sound(CST::HRM::As, 7, 150)));
	m_regSounds.insert(pair_SSND("C5_250"	, new Sound(CST::HRM::C, 5, 250)));
	m_regSounds.insert(pair_SSND("C5_150"	, new Sound(CST::HRM::C, 5, 150)));
	m_regSounds.insert(pair_SSND("G5_150"	, new Sound(CST::HRM::G, 5, 150)));
	m_regSounds.insert(pair_SSND("G5_250"	, new Sound(CST::HRM::G, 5, 250)));
	m_regSounds.insert(pair_SSND("B9_500"	, new Sound(CST::HRM::B, 9, 500)));
	m_regSounds.insert(pair_SSND("B7_500"	, new Sound(CST::HRM::B, 7, 500)));
	m_regSounds.insert(pair_SSND("D3_800"	, new Sound(CST::HRM::D, 3, 800)));
	m_regSounds.insert(pair_SSND("D5_500"	, new Sound(CST::HRM::D, 5, 500)));
	m_regSounds.insert(pair_SSND("D7_200"	, new Sound(CST::HRM::D, 7, 200)));
	m_regSounds.insert(pair_SSND("D9_200"	, new Sound(CST::HRM::D, 9, 200)));
	m_regSounds.insert(pair_SSND("D9_1000"	, new Sound(CST::HRM::D, 9, 1000)));

	VAR::SND::MAIN_THEME[0] = m_regSounds["B9_500"];
	VAR::SND::MAIN_THEME[1] = m_regSounds["B7_500"];
	/* ... */

	VAR::SND::MOB_DEATH[0] = m_regSounds["A7_100"];
	VAR::SND::MOB_DEATH[1] = m_regSounds["As7_150"];
	VAR::SND::MOB_DEATH[2] = m_regSounds["C5_250"];

	VAR::SND::MOB_HIT[0] = m_regSounds["C5_150"];
	VAR::SND::MOB_HIT[1] = m_regSounds["G5_250"];

	VAR::SND::WAVE_START[0] = m_regSounds["D7_200"];
	VAR::SND::WAVE_START[1] = m_regSounds["C5_150"];
	VAR::SND::WAVE_START[2] = m_regSounds["D9_200"];

	VAR::SND::WAVE_LOST[0] = m_regSounds["D7_200"];
	VAR::SND::WAVE_LOST[1] = m_regSounds["C5_150"];
	VAR::SND::WAVE_LOST[2] = m_regSounds["D5_500"];
	VAR::SND::WAVE_LOST[3] = m_regSounds["D5_500"];
	VAR::SND::WAVE_LOST[4] = m_regSounds["D3_800"];

	VAR::SND::WAVE_WIN[0] = m_regSounds["D7_200"];
	VAR::SND::WAVE_WIN[1] = m_regSounds["C5_150"];
	VAR::SND::WAVE_WIN[2] = m_regSounds["D7_200"];
	VAR::SND::WAVE_WIN[3] = m_regSounds["D7_200"];
	VAR::SND::WAVE_WIN[4] = m_regSounds["D9_1000"];

	VAR::SND::PLAYER_HIT[0] = m_regSounds["G5_150"];
	VAR::SND::PLAYER_HIT[1] = m_regSounds["C5_250"];
	

	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::MOB_DEATH, CST::SND::MOB_DEATH_t).detach();
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::MOB_HIT, CST::SND::MOB_HIT_t).detach();
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::WAVE_START, CST::SND::WAVE_START_t).detach();
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::WAVE_LOST, CST::SND::WAVE_LOST_t).detach();
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::WAVE_WIN, CST::SND::WAVE_WIN_t).detach();
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::PLAYER_HIT, CST::SND::PLAYER_HIT_t).detach();


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
	nextWave();
	m_sec = m_timer.getElapsedSeconds();
	while (m_isRunning){
		handleInputs();
		update(m_timer.getElapsedSeconds());
		render();
	}
}

//! isPlayerAlive
/*
* return current state of the player (boolean), true if alive
*/
bool AsciiGame::isPlayerAlive() const
{
	return true;//m_player->isAlive();
}

//! wave Ended
/*
* Handle the end of a wave
*/
void AsciiGame::waveEnded(bool won)
{
	if (won){
		//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::WAVE_WIN, CST::SND::WAVE_WIN_t).join();
		++m_wlvl;
		nextWave();
	}else{
		gameOver();
	}
}

//! nextWave
/*
* start a new wave
*/
void AsciiGame::nextWave()
{
	//m_wave = new Wave(this, m_mobs, static_cast<size_t>(CST::MOBS_COUNT), static_cast<float>(0.2f + (1 - m_wlvl*0.1f)));
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::WAVE_START, CST::SND::WAVE_START_t).detach();
}

//! gameOver
/*
* Handle the gale over
*/
void AsciiGame::gameOver()
{
	//std::thread(&SoundPlayer::play, std::ref(m_sndPlayer), VAR::SND::WAVE_LOST, CST::SND::WAVE_LOST_t).join();
	m_isRunning = false;
}

//! render the window
/*
* clear the portion of the game window that aren't up-to-date and draw on top the new context
*/
void AsciiGame::render()
{

	ReadConsoleOutput(m_hOutput, (CHAR_INFO *)m_buffer, m_dwBufferSize,
		m_dwBufferCoord, &m_rcRegion);
	clear();

	for (size_t i = 0; i < CST::MOBS_COUNT; i++)
	{
		//m_mobs[i]->display(m_buffer);
	}
	for (size_t i = 0; i < CST::BULLETS_COUNT; i++)
	{
		if(m_bullets[i]->testExit())
			m_bullets[i]->display(m_buffer);
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
	if (m_sec + (1/60) < timeElapsed) {
		if (m_leftIsPressed && !m_topIsPressed && !m_downIsPressed && !m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(West);
		}
		else if (m_leftIsPressed && m_topIsPressed && !m_downIsPressed && !m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(NorthWest);
		}
		else if (!m_leftIsPressed && m_topIsPressed && !m_downIsPressed && !m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(North);
		}
		else if (!m_leftIsPressed && m_topIsPressed && !m_downIsPressed && m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(NorthEast);
		}
		else if (!m_leftIsPressed && !m_topIsPressed && m_downIsPressed && !m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(South);
		}
		else if (!m_leftIsPressed && !m_topIsPressed && m_downIsPressed && m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(SouthEast);
		}
		else if (m_leftIsPressed && !m_topIsPressed && m_downIsPressed && !m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(SouthWest);
		}
		else if (!m_leftIsPressed && !m_topIsPressed && !m_downIsPressed && m_rightIsPressed) {
			m_bullets[Bullet::placeInPool]->instantiate(East);
		}


		for (int i = 0; i < CST::BULLETS_COUNT; ++i) {
			m_bullets[i]->move();
		}
		m_sec = timeElapsed;
	}
	
}