#ifndef DEFINES_ID_SOUNDID_H_
#define DEFINES_ID_SOUNDID_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/SDLUtilsDefines.h"

// Forward declarations

enum class SoundId
	: int32_t
{
	Invalid = -1
	, Count
};

#endif // !DEFINES_ID_SOUNDID_H_