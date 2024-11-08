#include "stdafx.h"

#include "system/utils/input_output/Log.h"

#define _PRINTF_VARIADIC_ARGS \
va_list args;\
va_start(args, fmt);\
vfprintf(stderr, fmt, args);\
printf("\n");\
va_end(args)

namespace Log
{
////////////////////////////////////////////////////////////////////////////////
void ConsoleSetTextColor(const EConsoleTextColor color)
{
	auto colorText = "\033[" + std::to_string((int16_t)color) + "m";
	printf("%s", colorText.c_str());
}

////////////////////////////////////////////////////////////////////////////////
void Console(const char* fmt ...)
{
	_PRINTF_VARIADIC_ARGS;
}

////////////////////////////////////////////////////////////////////////////////
void Console(const EConsoleTextColor color, const char* fmt ...)
{
	ConsoleSetTextColor(color);
	_PRINTF_VARIADIC_ARGS;
	ConsoleSetTextColor(EConsoleTextColor::Default);
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleWarning(const char* fmt ...)
{
	ConsoleSetTextColor(EConsoleTextColor::Yellow);
	printf("WARNING! ");
	_PRINTF_VARIADIC_ARGS;
	ConsoleSetTextColor(EConsoleTextColor::Default);
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleError(const char* fmt ...)
{
	ConsoleSetTextColor(EConsoleTextColor::Red);
	printf("ERROR! ");
	_PRINTF_VARIADIC_ARGS;
	ConsoleSetTextColor(EConsoleTextColor::Default);
}

////////////////////////////////////////////////////////////////////////////////
void File(const char* fileName, const char* text, const EWriteMode mode)
{
	std::ofstream datFile;
	datFile.open(fileName, mode == EWriteMode::App ? std::ofstream::app : std::ofstream::out);
	ReturnIf(!datFile.is_open(), void());

	datFile.write(text, strlen(text));
	datFile.close();
}
} // !namespace Log