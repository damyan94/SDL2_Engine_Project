#ifndef UTILS_DEFINES_H_
#define UTILS_DEFINES_H_

#include <cstdint>
#include <string>
#include <vector>

template <typename EnumType>
bool IsEnumValueValid(EnumType value)
{
	return value > EnumType::Invalid
		&& value < EnumType::Count;
}

//TODO move to a separate file maybe
class INonCopyable
{
public:
	INonCopyable() = default;
	~INonCopyable() = default;

private:
	INonCopyable(const INonCopyable&) = delete;
	INonCopyable& operator=(const INonCopyable&) = delete;
};

class INonMoveable
{
public:
	INonMoveable() = default;
	~INonMoveable() = default;

private:
	INonMoveable(INonMoveable&&) = delete;
	INonMoveable& operator=(INonMoveable&&) = delete;
};

class INonCopyMoveable
	: public INonCopyable
	, public INonMoveable
{
public:
	INonCopyMoveable() = default;
	~INonCopyMoveable() = default;
};

// =============================================================================
// ================================= DEFINES ===================================
// =============================================================================

#ifdef __ASSERT_INFO
	#undef __ASSERT_INFO
#endif

#if defined _DEBUG
	#define __ASSERT_INFO(__Condition)\
		"Check: " #__Condition\
		"\nFile: " __FILE__//\
		//"\nFunction: " __func__\
		"\nLine: " __LINE__
#else
	#define __ASSERT_INFO(__Condition, ...)\
		"Check: " #__Condition\
		"File: " __FILE__//\
		//"\nFunction: " __func__\
		"\nLine: " __LINE__
#endif // !_DEBUG

#ifdef _CONFIG_ERROR_INFO
	#undef _CONFIG_ERROR_INFO
#endif

#define _CONFIG_ERROR_INFO(__Line) ("Config file corrupted. Line: " + std::to_string(__Line + 1)).c_str()

// =============================================================================
// ================================= TYPEDEFS ==================================
// =============================================================================

//TODO think of strong type for these values
typedef uint64_t		TimePoint;
typedef uint32_t		TimerId;

#define CREATE_STRONG_TYPE(_Name, _Type, _DefaultValue, _InvalidValue)\
class _Name\
{\
public:\
	_Name() = default;\
	~_Name() = default;\
	_Name(_Type initialValue) : value(initialValue) {};\
\
	bool operator==(const _Name& other) const { return value == other.value; }\
	bool operator!=(const _Name& other) const { return value != other.value; }\
\
	bool IsValid() const { return value != _Name::Invalid; }\
\
	static _Type Default;\
	static _Type Invalid;\
\
public:\
	_Type value = _DefaultValue;\
};\
_Type _Name::Default = _DefaultValue;\
_Type _Name::Invalid = _InvalidValue;

typedef std::vector<std::string> ConfigStrings;
typedef uint32_t		ImageId;
typedef uint32_t		FontId;
typedef uint32_t		TextId;
typedef uint32_t		SoundId;
typedef uint32_t		MusicId;

typedef uint32_t		UIComponentId;

//CREATE_STRONG_TYPE(ImageId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(FontId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(TextId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(SoundId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(MusicId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(UIComponentId, uint32_t, 0, -1)

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
	Invalid		= -1
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
	Invalid	= -1
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

inline constexpr int64_t TimerMinInterval		= 20; // Milliseconds

inline constexpr int32_t ZeroOpacity			= 0;
inline constexpr int32_t FullOpacity			= 255;
inline constexpr int32_t ZeroRotation			= 0;
inline constexpr int32_t FullRotation			= 360;

inline constexpr int32_t ZeroVolume				= 0;
inline constexpr int32_t MaxVolume				= 127;
} // !namespace Constants

#endif // !UTILS_DEFINES_H_