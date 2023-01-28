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
	extern const char* WINDOW_NAME;
	extern const int32_t WINDOW_POS_X;
	extern const int32_t WINDOW_POS_Y;
	extern const int32_t WINDOW_WIDTH;
	extern const int32_t WINDOW_HEIGHT;
	extern const int32_t WINDOW_FLAGS;
}

namespace EngineConstants
{
	extern const int32_t FPS;
	extern const int32_t TIME_PER_FRAME;
	extern const Color RENDERER_DRAW_COLOR;
}

namespace GameConstants
{

}

#endif // !DEFINES_CONSTS_GLOBALCONSTANTS_H_