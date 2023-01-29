#ifndef UTILS_INPUT_OUTPUT_LOG_H_
#define UTILS_INPUT_OUTPUT_LOG_H_

// C/C++ system includes
#include <cstdint>
#include <cstdio>
#include <string>

// Third-party includes

// Own includes
#include "utils/UtilsDefines.h"

// Forward declarations

namespace Log
{
void ConsoleSetTextColor(ConsoleTextColor color);
void Console(const char* fmt...);
void Console(ConsoleTextColor color, const char* fmt...);
}

//TODO move refactor file logging
////================================== DEFINES ===================================
//
//#define __FILE_LOGGING_ENABLED				1
////TODO Maybe make this filename to be dynamic and to change every time the program is run
//#define __LOG_FILE_PATH						"log.csv"
//
//#define __CONSOLE_LOG_COLOR_DEFAULT			7
//#define __CONSOLE_LOG_COLOR_BLUE			9
//#define __CONSOLE_LOG_COLOR_GREEN			10
//#define __CONSOLE_LOG_COLOR_CYAN			11
//#define __CONSOLE_LOG_COLOR_RED				12
//#define __CONSOLE_LOG_COLOR_PURPLE			13
//#define __CONSOLE_LOG_COLOR_YELLOW			14
//#define __CONSOLE_LOG_COLOR_WHITE			15
//
//#define __LOG_INFO_TEXT						"INFO"
//#define __LOG_INFO_COLOR					__CONSOLE_LOG_COLOR_WHITE
//
//#define __LOG_WARNING_TEXT					"WARNING"
//#define __LOG_WARNING_COLOR					__CONSOLE_LOG_COLOR_YELLOW
//
//#define __LOG_ERROR_TEXT					"ERROR"
//#define __LOG_ERROR_COLOR					__CONSOLE_LOG_COLOR_RED
//
//#define __LOG_SEPARATOR						"================================================================================\n"
//
//#define __FILE_LOG_SOURCE_INFO				__FILE__ "," _STRINGIZE(__LINE__) ","
//#define __ASSERT_LOG_SOURCE_INFO			"File: " __FILE__ "\nLine: " _STRINGIZE(__LINE__) "\n"
//
////================================ FILE LOGGING ================================
//
//#if __FILE_LOGGING_ENABLED
//#define LogFile(__Severity, ...)\
//	{\
//		FILE* fPtr;\
//		fopen_s(&fPtr, __LOG_FILE_PATH, "a");\
//		if(fPtr)\
//		{\
//			fprintf(fPtr, __FILE_LOG_SOURCE_INFO);\
//			fprintf(fPtr, __Severity ",");\
//			fprintf(fPtr, "\"");\
//			fprintf(fPtr, __VA_ARGS__);\
//			fprintf(fPtr, "\"\n");\
//			fclose(fPtr);\
//		}\
//	}
//
//#define LogFileInfo(...)					do { LogFile(__LOG_INFO_TEXT, __VA_ARGS__) } while(false)
//#define LogFileWarning(...)					do { LogFile(__LOG_WARNING_TEXT, __VA_ARGS__) } while(false)
//#define LogFileError(...)					do { LogFile(__LOG_ERROR_TEXT, __VA_ARGS__) } while(false)
//
//#else // !__FILE_LOGGING_ENABLED
//#define LogFile(__Severity, ...)
//
//#define LogFileInfo(...)
//#define LogFileWarning(...)
//#define LogFileError(...)
//
//#endif // !__FILE_LOGGING_ENABLED

//TODO move asserts to SDL and use SDL_Assert
////=============================== ASSERT LOGGING ===============================
//
//#if defined _DEBUG
//#if defined WIN32 || _WIN32
//#define __DEBUG_BREAK_IF(__Condition) if(__Condition && IsDebuggerPresent()) { DebugBreak(); }
//
//#define __ASSERT(__Condition, __Text, ...)\
//		{\
//			if(__Condition)\
//			{\
//				LogFileError(__Text);\
//				MessageBoxA(nullptr, __Text, "Error!", MB_ICONERROR | MB_OK);\
//				__DEBUG_BREAK_IF(true);\
//			}\
//		}
//
//#else //if defined OS_LINUX || LINUX || UNIX
//#define __DEBUG_BREAK_IF(__Condition) if(__Condition) {_asm int 3}
//
////TODO handle the Linux case to show a message box
//#define __ASSERT(__Condition, __Text, ...)\
//		{\
//			if(__Condition)\
//			{\
//				LogFileError(__Text);\
//				/*TODO Insert message box here*/\
//				__DEBUG_BREAK_IF(true);\
//			}\
//		}
//
//#endif // !WIN32 || _WIN32
//
//#define Assert(__Condition, ...)			__ASSERT(__Condition, __VA_ARGS__ "\n" __ASSERT_LOG_SOURCE_INFO)
//
//#else
//#define __DEBUG_BREAK_IF(__Condition)
//#define __ASSERT(__Condition, __Text, ...)
//#define Assert(__Condition, ...)
//
//#endif // !_DEBUG

#endif // !UTILS_INPUT_OUTPUT_LOG_H_