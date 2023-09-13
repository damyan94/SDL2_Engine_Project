#include "stdafx.h"

#include "utils/input_output/Assert.h"

#if defined WIN32 || _WIN32
	#include <windows.h>
#elif defined OS_LINUX || LINUX || UNIX
	#include <syslog.h>
#endif // !WIN32 || _WIN32


// =============================================================================
static void _ShowMessageBox(const std::string& text)
{
#if defined WIN32 || _WIN32
	MessageBox(nullptr, text.c_str(), "Error!", MB_ICONERROR | MB_OK);
#else //if defined OS_LINUX || LINUX || UNIX
	//TODO Insert Linux message box here
#endif // !WIN32 || _WIN32
}

// =============================================================================
static void _DebugBreak()
{
#if defined WIN32 || _WIN32
	if (IsDebuggerPresent())
	{
		DebugBreak();
	}
#else //if defined OS_LINUX || LINUX || UNIX
	_asm int 3;
#endif // !WIN32 || _WIN32
}

// =============================================================================
static void _DebugLog(const std::string& text)
{
	Log::Console(EConsoleTextColor::Red, "--- ASSERT TRIGGERED ---\n");
	Log::Console(EConsoleTextColor::Red, text.c_str());
}

// =============================================================================
static void _ReleaseLog(const std::string& text)
{
	Time now;
	static const auto fileName = "./logs/" +
		now.GetString(ETimeStringFormat::yyyymmddHHmmss_ZeroPunctuation) + ".log";

	Log::File(fileName.c_str(), text.c_str(), EWriteMode::App);
}

namespace Assert
{
// =============================================================================
void Assert(const std::string& text)
{
	_ShowMessageBox(text);

#if defined _DEBUG
	_DebugLog(text);
	_DebugBreak();
#else
	_ReleaseLog(text);
#endif // !_DEBUG
}

// =============================================================================
void Assert(bool condition, const std::string& text)
{
	if (condition)
	{
		Assert(text);
	}
}
} // !namespace Assert