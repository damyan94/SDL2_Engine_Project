// Corresponding header
#include "utils/input_output/Log.h"

// C/C++ system includes
#include <cstdio>
#include <cstdarg>

// Third-party includes

// Own includes

// =============================================================================
void Log::ConsoleSetTextColor(EConsoleTextColor color)
{
	switch (color)
	{
	case EConsoleTextColor::Default:
		printf("\033[37m");
		break;

	case EConsoleTextColor::Black:
		printf("\033[90m");
		break;

	case EConsoleTextColor::Red:
		printf("\033[91m");
		break;

	case EConsoleTextColor::Green:
		printf("\033[92m");
		break;

	case EConsoleTextColor::Yellow:
		printf("\033[93m");
		break;

	case EConsoleTextColor::Blue:
		printf("\033[94m");
		break;

	case EConsoleTextColor::Magenta:
		printf("\033[95m");
		break;

	case EConsoleTextColor::Cyan:
		printf("\033[96m");
		break;

	case EConsoleTextColor::White:
		printf("\033[97m");
		break;

	default:
		printf("\033[37m");
		break;
	}
}

// =============================================================================
void Log::Console(const char* fmt ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	printf("\n");
	va_end(args);
}

// =============================================================================
void Log::Console(EConsoleTextColor color, const char* fmt ...)
{
	ConsoleSetTextColor(color);

	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	printf("\033[37m");
	printf("\n");
	va_end(args);

	ConsoleSetTextColor(EConsoleTextColor::Default);
}

// =============================================================================
void Log::File(const char* fmt ...)
{
	//TODO Add this functionality
}