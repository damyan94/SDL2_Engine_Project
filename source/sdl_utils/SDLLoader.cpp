// Corresponding header
#include "sdl_utils/SDLLoader.h"

// C/C++ system includes

// Third-party includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Own includes
#include "utils/others/CodeReadabilityDefines.h"

// =============================================================================
bool SDLLoader::Init()
{
	AssertReturnIf(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO),
		false, "SDL_Init() failed.");

	AssertReturnIf(EXIT_SUCCESS == (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG),
		false, "IMG_Init() failed.");

	AssertReturnIf(EXIT_SUCCESS != TTF_Init(),
		false, "TTF_Init() failed.");

	/*AssertReturnIf(0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048),
		false, "Mix_OpenAudio() failed.");*/

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