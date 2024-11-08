#ifndef SDL_UTILS_DEFINES_H_
#define SDL_UTILS_DEFINES_H_

#include <cstdint>
#include <unordered_map>

enum class ELanguage : int8_t;

////////////////////////////////////////////////////////////////////////////////
// ================================= DEFINES ===================================
////////////////////////////////////////////////////////////////////////////////

#define _MinImageId		1000000
#define _MaxImageId		1099999
#define _MinFontId		1100000
#define _MaxFontId		1199999
#define _MinTextId		1200000
#define _MaxTextId		1299999
#define _MinSoundId		1300000
#define _MaxSoundId		1399999
#define _MinMusicId		1400000
#define _MaxMusicId		1499999
#define _MinTimerId		1500000
#define _MaxTimerId		1599999
#define _MinCursorId	1600000
#define _MaxCursorId	1699999

#define IsResourceIdValid(__ResIdType, __Value) //(__Value >= _Min##__ResIdType && __Value <= _Max##__ResIdType)

////////////////////////////////////////////////////////////////////////////////
// ================================= TYPEDEFS ==================================
////////////////////////////////////////////////////////////////////////////////

typedef std::unordered_map<ELanguage, std::string> LanguageStringMap;

////////////////////////////////////////////////////////////////////////////////
// =============================== ENUMERATIONS ================================
////////////////////////////////////////////////////////////////////////////////

// Gotta be careful with this one in IsEnumValueValid<>()
enum class EWindowFlags
{
	Fullscreen				= 0x00000001				// SDL_WINDOW_FULLSCREEN
	, OpenGL				= 0x00000002				// SDL_WINDOW_OPENGL
	, Shown					= 0x00000004				// SDL_WINDOW_SHOWN
	, Hidden				= 0x00000008				// SDL_WINDOW_HIDDEN
	, Borderless			= 0x00000010				// SDL_WINDOW_BORDERLESS
	, Resizable				= 0x00000020				// SDL_WINDOW_RESIZABLE
	, Minimized				= 0x00000040				// SDL_WINDOW_MINIMIZED
	, Maximized				= 0x00000080				// SDL_WINDOW_MAXIMIZED
	, MouseGrabbed			= 0x00000100				// SDL_WINDOW_MOUSE_GRABBED
	, InputFocus			= 0x00000200				// SDL_WINDOW_INPUT_FOCUS
	, MouseFocus			= 0x00000400				// SDL_WINDOW_MOUSE_FOCUS
	, FullscreenDesktop		= (Fullscreen | 0x00001000)	// SDL_WINDOW_FULLSCREEN_DESKTOP
	, Foreign				= 0x00000800				// SDL_WINDOW_FOREIGN
	, AllowHighDPI			= 0x00002000				// SDL_WINDOW_ALLOW_HIGHDPI
	, MouseCapture			= 0x00004000				// SDL_WINDOW_MOUSE_CAPTURE
	, AlwaysOnTop			= 0x00008000				// SDL_WINDOW_ALWAYS_ON_TOP
	, SkipTaskbar			= 0x00010000				// SDL_WINDOW_SKIP_TASKBAR
	, Utility				= 0x00020000				// SDL_WINDOW_UTILITY
	, Tooltip				= 0x00040000				// SDL_WINDOW_TOOLTIP
	, PopUpMenu				= 0x00080000				// SDL_WINDOW_POPUP_MENU
	, KeyboardGrabbed		= 0x00100000				// SDL_WINDOW_KEYBOARD_GRABBED
	, Vulkan				= 0x10000000				// SDL_WINDOW_VULKAN
	, Metal					= 0x20000000				// SDL_WINDOW_METAL
};

// Gotta be careful with this one in IsEnumValueValid<>()
enum class ERendererFlags
{
	Software				= 0x00000001				// SDL_RENDERER_SOFTWARE
	, Accelerated			= 0x00000002				// SDL_RENDERER_ACCELERATED
	, PresentVSync			= 0x00000004				// SDL_RENDERER_PRESENTVSYNC
	, TargetTexture			= 0x00000008				// SDL_RENDERER_TARGETTEXTURE
};

enum class EFontWrapAlign
	: int8_t
{
	Invalid = -1
	, Left					= 0							// TTF_WRAPPED_ALIGN_LEFT
	, Middle				= 1							// TTF_WRAPPED_ALIGN_CENTER
	, Right					= 2							// TTF_WRAPPED_ALIGN_RIGHT
	, Count
};

enum class EDrawLayer
{
	Invalid = -1
	, First
	, Second
	, Third
	, Fourth
	, Fifth
	, Count
};

enum class ELanguage
	:int8_t
{
	Invalid = -1
	, BG
	, EN
	, Count
};

enum class ETimerType
	: int8_t
{
	Invalid = -1
	, OneShot
	, Pulse
	, Count
};

////////////////////////////////////////////////////////////////////////////////
// ================================= CONSTANTS =================================
////////////////////////////////////////////////////////////////////////////////

namespace Constants
{
} // !namespace Constants

//TODO remove this from here as it is only temporary here
//namespace Utils
//{
//ELanguage				GetLanguageIdFromString(const std::string& langString);
//std::string				GetLanguageStringFromId(ELanguage id);
//} // !namespace Utils

namespace Utils
{
////////////////////////////////////////////////////////////////////////////////
inline ELanguage GetLanguageIdFromString(const std::string& langString)
{
	if (langString == "BG") return ELanguage::BG;
	if (langString == "EN") return ELanguage::EN;

	return ELanguage::Invalid;
}

////////////////////////////////////////////////////////////////////////////////
inline std::string GetLanguageStringFromId(ELanguage id)
{
	if (id == ELanguage::BG) return "BG";
	if (id == ELanguage::EN) return "EN";

	return "";
}
} // !namespace Utils

#endif // !SDL_UTILS_DEFINES_H_