// Corresponding header
#include "utils/input_output/Assert.h"

// C/C++ system includes
#include <iostream>

#if defined WIN32 || _WIN32
#include <windows.h>

#elif defined OS_LINUX || LINUX || UNIX
#include <syslog.h>

#endif // !WIN32 || _WIN32

// Third-party includes

// Own includes

// =============================================================================
void Assert::Assert(const char* text)
{
#if defined _DEBUG
#if defined WIN32 || _WIN32
	Log::Console(ConsoleTextColor::Red, "ASSERT TRIGGERED:\n");
	Log::Console(ConsoleTextColor::Red, text);
	MessageBoxA(nullptr, text, "Error!", MB_ICONERROR | MB_OK);
	if (IsDebuggerPresent())
	{
		DebugBreak();
	}

#else //if defined OS_LINUX || LINUX || UNIX
	//TODO Insert Linux message box here
	_asm int 3;

#endif // !WIN32 || _WIN32

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