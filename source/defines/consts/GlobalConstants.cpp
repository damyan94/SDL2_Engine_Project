// Corresponding header
#include "defines/consts/GlobalConstants.h"

// C/C++ system includes

// Third-party includes

// Own includes

//TODO Refactor in the fashion of UtilsDefines.h and/or create Cfgs for each
namespace WindowConstants
{
	enum WindowFlags
	{
		WINDOW_FULLSCREEN				= 0x00000001
		//, WINDOW_OPENGL					= 0x00000002
		, WINDOW_SHOWN					= 0x00000004
		//, WINDOW_HIDDEN					= 0x00000008
		, WINDOW_BORDERLESS				= 0x00000010
		, WINDOW_RESIZABLE				= 0x00000020
		//, WINDOW_MINIMIZED				= 0x00000040
		, WINDOW_MAXIMIZED				= 0x00000080
		//, WINDOW_MOUSE_GRABBED			= 0x00000100
		//, WINDOW_INPUT_FOCUS			= 0x00000200
		//, WINDOW_MOUSE_FOCUS			= 0x00000400
		, WINDOW_FULLSCREEN_DESKTOP		= (WINDOW_FULLSCREEN | 0x00001000)
		//, WINDOW_FOREIGN				= 0x00000800
		//, WINDOW_ALLOW_HIGHDPI			= 0x00002000
	};

	const char* Name					= "Application";
	const int32_t PosX					= 0x1FFF0000u; // SDL_WINDOWPOS_UNDEFINED
	const int32_t PosY					= 0x1FFF0000u; // SDL_WINDOWPOS_UNDEFINED
	const int32_t Width					= 1280;
	const int32_t Height				= 720;
	const int32_t Flags					= WINDOW_SHOWN;
} // !WindowConstants

namespace RendererConstants
{
	enum RendererFlags
	{
		RENDERER_SOFTWARE				= 0x00000001
		, RENDERER_ACCELERATED			= 0x00000002
		, RENDERER_PRESENTVSYNC			= 0x00000004
		, RENDERER_TARGETTEXTURE		= 0x00000008
	};

	const int32_t Flags					= RENDERER_ACCELERATED;
}

namespace EngineConstants
{
	const int32_t FPS = 50;
	const int32_t TIME_PER_FRAME = 1000 / FPS;
	const Color RENDERER_DRAW_COLOR = Colors::LightGrey;
} // !RendererConstants

namespace GameConstants
{

} // !GameConstants