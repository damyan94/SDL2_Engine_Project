#ifndef UTILS_INPUT_OUTPUT_LOG_H_
#define UTILS_INPUT_OUTPUT_LOG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsDefines.h"

// Forward declarations

namespace Log
{
void ConsoleSetTextColor(ConsoleTextColor color);
void Console(const char* fmt...);
void Console(ConsoleTextColor color, const char* fmt...);

void File(const char* fmt...);
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

#endif // !UTILS_INPUT_OUTPUT_LOG_H_