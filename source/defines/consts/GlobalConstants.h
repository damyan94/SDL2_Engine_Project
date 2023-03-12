#ifndef DEFINES_CONSTS_GLOBALCONSTANTS_H_
#define DEFINES_CONSTS_GLOBALCONSTANTS_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations

namespace WindowConstants
{
	enum WindowFlags
	{
		WINDOW_FULLSCREEN = 0x00000001
		//, WINDOW_OPENGL					= 0x00000002
		, WINDOW_SHOWN = 0x00000004
		//, WINDOW_HIDDEN					= 0x00000008
		, WINDOW_BORDERLESS = 0x00000010
		, WINDOW_RESIZABLE = 0x00000020
		, WINDOW_MINIMIZED				= 0x00000040
		, WINDOW_MAXIMIZED = 0x00000080
		//, WINDOW_MOUSE_GRABBED			= 0x00000100
		//, WINDOW_INPUT_FOCUS			= 0x00000200
		//, WINDOW_MOUSE_FOCUS			= 0x00000400
		, WINDOW_FULLSCREEN_DESKTOP = (WINDOW_FULLSCREEN | 0x00001000)
		//, WINDOW_FOREIGN				= 0x00000800
		//, WINDOW_ALLOW_HIGHDPI			= 0x00002000
	};
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
} // !RendererConstants

namespace EngineConstants
{
	extern const int32_t FPS;
	extern const int32_t TIME_PER_FRAME;
	extern const Color RENDERER_DRAW_COLOR;
} // !EngineConstants

namespace GameConstants
{

} // !GameConstants

#endif // !DEFINES_CONSTS_GLOBALCONSTANTS_H_