#include "AsciiGame.h"


AsciiGame::AsciiGame() : m_isRunning(false)
{
}


AsciiGame::~AsciiGame()
{
}


void AsciiGame::start()
{
	m_isRunning = true;
	while (m_isRunning){
		handleInputs();
		update();
		render();
	}
}

void AsciiGame::render()
{
	HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
	const SMALL_RECT* p_rcRegion = &rcRegion;

	SetConsoleWindowInfo(hOutput, true, p_rcRegion);

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	for (size_t i = 0; i < SCREEN_WIDTH; i++)
	{
		for (size_t j = 0; j < SCREEN_HEIGHT; j++)
		{
			buffer[j][i].Char.AsciiChar = '.';
			buffer[j][i].Attributes = 0x0E;
		}
	}

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

void AsciiGame::clear(){

}

void AsciiGame::handleInputs()
{

}

void AsciiGame::update(){

}