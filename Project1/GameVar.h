#ifndef GAMEVAR_H
#define GAMEVAR_H
#pragma once

class Sound;

namespace CST{
	/* game window */
	const short SCREEN_WIDTH	{ 60 };
	const short SCREEN_HEIGHT	{ 30 };

	/* game param */
	const short MOBS_COUNT		{ 50 };
	const short BULLETS_COUNT	{ 50 };

	/* sound param (harmonics) */
	namespace HRM{
		const float C	{ 16.35f };
		const float Cs	{ 17.32f };
		const float D	{ 18.35f };
		const float Ds	{ 19.45f };
		const float E	{ 20.60f };
		const float F	{ 21.83f };
		const float Fs	{ 23.12f };
		const float G	{ 24.50f };
		const float Gs	{ 25.96f };
		const float A	{ 27.50f };
		const float As	{ 29.14f };
		const float B	{ 30.87f };
	}
	namespace SND{
		const size_t	MAIN_THEME_t	{ 20 };
		const size_t	MOB_DEATH_t		{ 3 };
		const size_t	MOB_HIT_t		{ 2 };
		const size_t	WAVE_START_t	{ 3 };
		const size_t	WAVE_LOST_t		{ 5 };
		const size_t	WAVE_WIN_t		{ 5 };
		const size_t	PLAYER_HIT_t	{ 2 };
	}
}


#endif