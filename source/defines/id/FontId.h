#ifndef DEFINES_ID_FONTID_H_
#define DEFINES_ID_FONTID_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/SDLUtilsDefines.h"

// Forward declarations

enum class FontId
	: int32_t
{
	Invalid = -1

	, Consola_12 = 112
	, Consola_14 = 114
	, Consola_18 = 118

	, Count
};

#endif // !DEFINES_ID_FONTID_H_