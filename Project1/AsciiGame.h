#pragma once

#include <Windows.h>

const short SCREEN_WIDTH = 60;
const short SCREEN_HEIGHT = 30;

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
	void update(void);

	bool m_isRunning;
};

