#ifndef SDL_UTILS_DEFINES_H_
#define SDL_UTILS_DEFINES_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

// =============================================================================
// ================================= DEFINES ===================================
// =============================================================================


// =============================================================================
// ================================= TYPEDEFS ==================================
// =============================================================================


// =============================================================================
// =============================== ENUMERATIONS ================================
// =============================================================================

enum class EAssetContainerType
	: int16_t
{
	Invalid = -1
	, Image
	, Font
	, Sound
	, Music
	, Count
};

// =============================================================================
// ================================= CONSTANTS =================================
// =============================================================================

namespace SDLUtilsConstants
{

} // !namespace SDLUtilsConstants

#endif // !SDL_UTILS_DEFINES_H_