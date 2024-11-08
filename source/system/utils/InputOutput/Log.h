#pragma once

namespace Log
{
void ConsoleSetTextColor(const EConsoleTextColor color);
void Console(const char* fmt...);
void Console(const EConsoleTextColor color, const char* fmt...);

void ConsoleWarning(const char* fmt...);
void ConsoleError(const char* fmt...);

void File(const char* fileName, const char* text, const EWriteMode mode = EWriteMode::App);
} // !namespace Log