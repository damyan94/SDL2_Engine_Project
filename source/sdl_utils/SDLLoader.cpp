// Corresponding header
#include "sdl_utils/SDLLoader.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Own includes

// =============================================================================
int32_t SDLLoader::Init()
{
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO))
	{
		std::cerr << "Error, SDL_Init() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS == (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cerr << "Error, IMG_Init() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != TTF_Init())
	{
		std::cerr << "Error, TTF_Init() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	/*if (0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048))
	{
		std::cerr << "Error, Mix_OpenAudio() failed. Reason: "
		<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}*/

	return EXIT_SUCCESS;
}

// =============================================================================
void SDLLoader::Deinit()
{
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}