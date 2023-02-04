// Corresponding header
#include "utils/input_output/Log.h"

// C/C++ system includes
#include <cstdio>
#include <cstdarg>

// Third-party includes

// Own includes

// =============================================================================
void Log::ConsoleSetTextColor(ConsoleTextColor color)
{
	switch (color)
	{
	case ConsoleTextColor::Default:
		printf("\033[37m");
		break;

	case ConsoleTextColor::Black:
		printf("\033[90m");
		break;

	case ConsoleTextColor::Red:
		printf("\033[91m");
		break;

	case ConsoleTextColor::Green:
		printf("\033[92m");
		break;

	case ConsoleTextColor::Yellow:
		printf("\033[93m");
		break;

	case ConsoleTextColor::Blue:
		printf("\033[94m");
		break;

	case ConsoleTextColor::Magenta:
		printf("\033[95m");
		break;

	case ConsoleTextColor::Cyan:
		printf("\033[96m");
		break;

	case ConsoleTextColor::White:
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
	va_end(args);
}

// =============================================================================
void Log::Console(ConsoleTextColor color, const char* fmt ...)
{
	ConsoleSetTextColor(color);

	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	ConsoleSetTextColor(ConsoleTextColor::Default);
}

// =============================================================================
void Log::File(const char* fmt ...)
{
	//TODO Add this functionality
}