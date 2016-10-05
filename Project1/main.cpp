#include <Windows.h>
#include <iostream>

int main()
{
	const int SCREEN_WIDTH	= 60;
	const int SCREEN_HEIGHT = 30;

	HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
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

	getchar();
	return 0;
}