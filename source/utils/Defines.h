#ifndef UTILS_DEFINES_H_
#define UTILS_DEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <vector>

// Third-party includes

// Own includes

// Forward declarations

template <typename EnumType>
bool IsEnumValueValid(EnumType value)
{
	return value > EnumType::Invalid
		&& value < EnumType::Count;
}

// =============================================================================
// ================================= DEFINES ===================================
// =============================================================================

#ifdef __ASSERT_INFO
	#undef __ASSERT_INFO
#endif

#if defined _DEBUG
	#define __ASSERT_INFO(__Condition, ...)\
		"Check: " #__Condition\
		"\nFile: " __FILE__\
		"\nFunction: " __FUNCTION__\
		"\nLine: " _STRINGIZE(__LINE__)\
		"\nReason: " __VA_ARGS__
#else
	#define __ASSERT_INFO(__Condition, ...)\
		"Check: " #__Condition\
		"File: " __FILE__\
		"\nFunction: " __FUNCTION__\
		"\nLine: " _STRINGIZE(__LINE__)\
		"\nReason: " __VA_ARGS__
#endif // !_DEBUG

#ifdef _CONFIG_ERROR_INFO
	#undef _CONFIG_ERROR_INFO
#endif

#define _CONFIG_ERROR_INFO(__Line)				"Config file corrupted. Line: " + std::to_string(__Line + 1)

// =============================================================================
// ================================= TYPEDEFS ==================================
// =============================================================================

typedef std::wstring	String;
typedef uint64_t		TimePoint;
typedef int32_t			TimerId;

typedef std::vector<std::string> ConfigStrings;
typedef int32_t			ImageId;
typedef int32_t			FontId;
typedef int32_t			TextId;
typedef int32_t			SoundId;
typedef int32_t			MusicId;

// =============================================================================
// =============================== ENUMERATIONS ================================
// =============================================================================

enum class EUnitOfTime
	: int8_t
{
	Invalid = -1
	, Nanoseconds
	, Microseconds
	, Milliseconds
	, Seconds
	, Minutes
	, Hours
	, Days
	, Count
};

enum class ETimeStringFormat
	: int8_t
{
	Invalid = -1
	, yyyymmddHHmmss_ZeroPunctuation
	, yyyymmddHHmmss_Dots
	, ddmmyyyyHHmmss_ZeroPunctuation
	, ddmmyyyyHHmmss_Dots
	, Count
};

// Gotta be careful with this one in IsEnumValueValid<>()
enum class EConsoleTextColor
	: int16_t
{
	Invalid = -1
	, Default	= 37
	, Black		= 90
	, Red		= 91
	, Green		= 92
	, Yellow	= 93
	, Blue		= 94
	, Magenta	= 95
	, Cyan		= 96
	, White		= 97
	, Count		= 10
};

enum class EWriteMode
	: int8_t
{
	Invalid = -1
	, Out
	, App
	, Count
};

enum class EObjectType
	: int8_t
{
	Invalid = -1
	, Image
	, Text
	, DynamicText
	, Sound
	, Music
	, Count
};

enum class EBlendMode
	: int8_t
{
	Invalid = -1
	, None
	, Blend
	, Add
	, Mod
	, Count
};

enum class EFlipMode
	: int8_t
{
	Invalid = -1
	, None
	, Horizontal
	, Vertical
	, HorizontalAndVertical
	, Count
};

// =============================================================================
// ================================= CONSTANTS =================================
// =============================================================================

namespace Constants
{
inline constexpr int64_t TimeSecondsInMinute	= 60;
inline constexpr int64_t TimeMinutesInHour		= 60;
inline constexpr int64_t TimeHoursInDay			= 24;
inline constexpr int64_t TimeDaysInYear			= 365;

inline constexpr int64_t TimeSecondsInHour		= TimeSecondsInMinute * TimeMinutesInHour;
inline constexpr int64_t TimeSecondsInDay		= TimeSecondsInHour * TimeHoursInDay;
inline constexpr int64_t TimeSecondsInYear		= TimeSecondsInDay * TimeDaysInYear;

inline constexpr int64_t TimeMinutesInDay		= TimeMinutesInHour * TimeHoursInDay;
inline constexpr int64_t TimeMinutesInYear		= TimeMinutesInDay * TimeDaysInYear;

inline constexpr int64_t TimeHoursInYear		= TimeHoursInDay * TimeDaysInYear;

inline constexpr int64_t TimerMinInterval		= 20;

inline constexpr int32_t ZeroOpacity			= 0;
inline constexpr int32_t FullOpacity			= 255;
inline constexpr int32_t ZeroRotation			= 0;
inline constexpr int32_t FullRotation			= 360;

inline constexpr int32_t ZeroVolume				= 0;
inline constexpr int32_t MaxVolume				= 0;
} // !namespace Constants

#endif // !UTILS_DEFINES_H_