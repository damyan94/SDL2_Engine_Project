#include "stdafx.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "sdl_utils/SDLLoader.h"

// =============================================================================
bool SDLLoader::Init()
{
	AssertReturnIf(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO),
		false, "SDL_Init() failed: " + std::string(SDL_GetError()));

	AssertReturnIf(EXIT_SUCCESS == (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG),
		false, "IMG_Init() failed " + std::string(SDL_GetError()));

	AssertReturnIf(EXIT_SUCCESS != TTF_Init(),
		false, "TTF_Init() failed " + std::string(SDL_GetError()));

	AssertReturnIf(0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048),
		false, "Mix_OpenAudio() failed. " + std::string(SDL_GetError()));

	return true;
}

// =============================================================================
void SDLLoader::Deinit()
{
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}