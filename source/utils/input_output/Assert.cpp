// Corresponding header
#include "utils/input_output/Assert.h"

// C/C++ system includes
#include <fstream>
#include <chrono>

#if defined WIN32 || _WIN32
	#include <windows.h>
#elif defined OS_LINUX || LINUX || UNIX
	#include <syslog.h>
#endif // !WIN32 || _WIN32

// Third-party includes

// Own includes
#include "utils/input_output/Log.h"

// =============================================================================
static void _ShowMessageBox(const char* text)
{
#if defined WIN32 || _WIN32
	MessageBox(nullptr, text, "Error!", MB_ICONERROR | MB_OK);
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
static void _DebugLog(const char* text)
{
	Log::Console(EConsoleTextColor::Red, "--- ASSERT TRIGGERED ---\n");
	Log::Console(EConsoleTextColor::Red, text);
}

// =============================================================================
static void _ReleaseLog(const char* text)
{
	static const auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::ofstream datFile;
	const auto fileName = std::to_string(now) + ".log";
	datFile.open(fileName.c_str(), std::ofstream::app);
	datFile.write(text, strlen(text));
	datFile.close();
}

// =============================================================================
void Assert::Assert(const char* text)
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
void Assert::Assert(bool condition, const char* text)
{
	if (condition)
	{
		Assert(text);
	}
}