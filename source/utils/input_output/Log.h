#ifndef UTILS_INPUT_OUTPUT_LOG_H_
#define UTILS_INPUT_OUTPUT_LOG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/Defines.h"

// Forward declarations

namespace Log
{
void ConsoleSetTextColor(const EConsoleTextColor color);
void Console(const char* fmt...);
void Console(const EConsoleTextColor color, const char* fmt...);

void File(const char* fileName, const char* text, const EWriteMode mode = EWriteMode::App);
} // !namespace Log

#endif // !UTILS_INPUT_OUTPUT_LOG_H_