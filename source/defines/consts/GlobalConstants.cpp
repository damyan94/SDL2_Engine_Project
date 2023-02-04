// Corresponding header
#include "defines/consts/GlobalConstants.h"

// C/C++ system includes

// Third-party includes

// Own includes

namespace WindowConstants
{
	enum WindowFlags
	{
		WINDOW_FULLSCREEN = 1,
		WINDOW_SHOWN = 4,
		WINDOW_BORDERLESS = 16,
		WINDOW_RESIZABLE = 32,
		WINDOW_FULLSCREEN_DESKTOP = 4097,
	};

	const char* WINDOW_NAME = "Application";
	const int32_t WINDOW_POS_X = 0x1FFF0000u; // SDL_WINDOWPOS_UNDEFINED
	const int32_t WINDOW_POS_Y = 0x1FFF0000u; // SDL_WINDOWPOS_UNDEFINED
	const int32_t WINDOW_WIDTH = 1280;
	const int32_t WINDOW_HEIGHT = 720;
	const int32_t WINDOW_FLAGS = WINDOW_SHOWN;
}

namespace EngineConstants
{
	const int32_t FPS = 50;
	const int32_t TIME_PER_FRAME = 1000 / FPS;
	const Color RENDERER_DRAW_COLOR = Colors::LightGrey;
}

namespace GameConstants
{

}