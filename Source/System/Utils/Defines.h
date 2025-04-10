#pragma once

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

class QuitApplication
{
public:
	const char* Why() const
	{
		return "'cause I'm havin' fun";
	}
};

////////////////////////////////////////////////////////////////////////////////
// ================================= DEFINES ===================================
////////////////////////////////////////////////////////////////////////////////


#define _Stringify_(X) #X
#define _Stringify(X) _Stringify_(X)

#ifdef _MSC_VER
#define _DebugBreak __debugbreak()
#else
#define _DebugBreak
#endif

#define _DebugBreakInfo(_Reason)\
"Reason: " _Stringify(_Reason) \
", File: " __FILE__ \
", Line: " _Stringify(__LINE__)

#define _DebugBreakInfoMsgBox(_Reason)\
"Reason: " _Stringify(_Reason) \
"\nFile: " __FILE__ \
"\nLine: " _Stringify(__LINE__)

#define _MessageBoxError(_Text)\
UI::ShowMessageBoxOK("Error!", _Text, UI::EMessageBoxIcon::Error)

#define Assert(...)\
Logger::LogError(_DebugBreakInfo(__VA_ARGS__));\
_MessageBoxError(_DebugBreakInfoMsgBox(__VA_ARGS__));\
_DebugBreak

#define AssertReturnIf(_Condition, ...)		do { if (_Condition) { Assert(_Condition); return __VA_ARGS__; }} while(false)

//std::string DebugBreakInfo(const std::string& text, const std::string& separator)
//{
//	return "Reason: " + text + separator + "File: " + __FILE__ + separator + "Line: " + _Stringify(__LINE__);
//}
//
//void Assert(const std::string& text)
//{
//	Logger::LogError(DebugBreakInfo(text, ", "));
//	UI::ShowMessageBoxOK("Error!", DebugBreakInfo(text, "\n"), UI::EMessageBoxIcon::Error);
//	_DebugBreak;
//}

#define Format(_Text, ...)			std::format(_Text, __VA_ARGS__)

#define ReturnIf(_Condition, ...)	if (_Condition) return __VA_ARGS__
#define BreakIf(_Condition)			if (_Condition) break
#define ContinueIf(_Condition)		if (_Condition) continue

#define AssertReturnIf(_Condition, ...)		do { if (_Condition) { Assert(_Condition); return __VA_ARGS__; }} while(false)
#define AssertBreakIf(_Condition)			do { if (_Condition) { Assert(_Condition); break; }} while(false)
#define AssertContinueIf(_Condition)		do { if (_Condition) { Assert(_Condition); continue; }} while(false)

#define SafeDelete(_Pointer)				do { if (_Pointer) { delete _Pointer; _Pointer = nullptr; }} while(false)
#define SafeDeleteArray(_Pointer)			do { if (_Pointer) { delete[] _Pointer; _Pointer = nullptr; }} while(false)

////////////////////////////////////////////////////////////////////////////////
// ================================= TYPEDEFS ==================================
////////////////////////////////////////////////////////////////////////////////

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

typedef std::vector<std::string> LinesOfText;

typedef uint32_t		ImageId;
typedef uint32_t		StringId;
typedef uint32_t		FontId;
typedef uint32_t		TextId;
typedef uint32_t		DynamicTextId;
typedef uint32_t		SoundId;
typedef uint32_t		MusicId;

typedef uint32_t		UIComponentId;

//CREATE_STRONG_TYPE(ImageId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(FontId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(TextId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(SoundId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(MusicId, uint32_t, 0, -1)
//CREATE_STRONG_TYPE(UIComponentId, uint32_t, 0, -1)

////////////////////////////////////////////////////////////////////////////////
// =============================== ENUMERATIONS ================================
////////////////////////////////////////////////////////////////////////////////

enum class ELogLevel
	: int8_t
{
	Invalid = -1
	, LogNone		// Log nothing
	, LogText		// Log text
	, LogError		// Log text and errors
	, LogWarning	// Log text, errors and warnings
	, LogInfo		// Log everything
	, Count
};

enum class ETextColor
	: int8_t
{
	Invalid = -1
	, Black
	, Red
	, Green
	, Yellow
	, Blue
	, Magenta
	, Cyan
	, White
	, Count
};

enum class ETextStyle
	: int8_t
{
	Invalid = -1
	, Regular
	, Dim
	, Italic
	, Underlined
	, CrossedOut
	, DoublyUnderlined
	, Count
};

enum class EMessageType
	: int8_t
{
	Invalid = -1
	, Text
	, Error
	, Count
};

enum class EUnitOfTime
	: int8_t
{
	Invalid = -1
	, Nanosecond
	, Microsecond
	, Millisecond
	, Second
	, Minute
	, Hour
	, Day
	, Week
	, Month
	, Year
	, Count
};

enum class ETimeStringFormat
	: int8_t
{
	Invalid = -1
	, Default
	, Timestamp
	, TimePoint
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

////////////////////////////////////////////////////////////////////////////////
// ================================= CONSTANTS =================================
////////////////////////////////////////////////////////////////////////////////

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