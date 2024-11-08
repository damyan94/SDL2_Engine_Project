#include "stdafx.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "System/SDLUtils/SDLLoader.h"

namespace SDLLoader
{
////////////////////////////////////////////////////////////////////////////////
bool Init()
{
	AssertReturnIf(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO)
		&& SDL_GetError(), false);

	AssertReturnIf(EXIT_SUCCESS == (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
		&& SDL_GetError(), false);

	AssertReturnIf(EXIT_SUCCESS != TTF_Init()
		&& SDL_GetError(), false);

	AssertReturnIf(0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048)
		&& SDL_GetError(), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Deinit()
{
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
} // !namespace SDLLoader