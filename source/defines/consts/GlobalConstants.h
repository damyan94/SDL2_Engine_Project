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
	extern const char* Name;
	extern const int32_t PosX;
	extern const int32_t PosY;
	extern const int32_t Width;
	extern const int32_t Height;
	extern const int32_t Flags;
} // !WindowConstants

namespace EngineConstants
{
	extern const int32_t FPS;
	extern const int32_t TIME_PER_FRAME;
	extern const Color RENDERER_DRAW_COLOR;
} // !EngineConstants

namespace RendererConstants
{
	extern const int32_t Flags;
} // !RendererConstants

namespace GameConstants
{

} // !GameConstants

#endif // !DEFINES_CONSTS_GLOBALCONSTANTS_H_