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

enum class ELanguage
	:int8_t
{
	Invalid = -1
	, BG
	, EN
	, Count
};

enum class WindowFlags
{
	Fullscreen				= 0x00000001
	, OpenGL				= 0x00000002
	, Shown					= 0x00000004
	, Hidden				= 0x00000008
	, Borderless			= 0x00000010
	, Resizable				= 0x00000020
	, Minimized				= 0x00000040
	, Maximized				= 0x00000080
	, MouseGrabbed			= 0x00000100
	, InputFocus			= 0x00000200
	, MouseFocus			= 0x00000400
	, FullscreenDesktop		= (Fullscreen | 0x00001000)
	, Foreign				= 0x00000800
	, AllowHighDPI			= 0x00002000
};

enum class RendererFlags
{
	Software				= 0x00000001
	, Accelerated			= 0x00000002
	, PresentVSync			= 0x00000004
	, TargetTexture			= 0x00000008
};

enum class ETimerType
	: int8_t
{
	Invalid = -1
	, OneShot
	, Pulse
	, Count
};

// =============================================================================
// ================================= CONSTANTS =================================
// =============================================================================

namespace Constants
{
} // !namespace Constants

#endif // !SDL_UTILS_DEFINES_H_