#ifndef UTILS_OTHERS_CODEREADABILITYDEFINES_H_
#define UTILS_OTHERS_CODEREADABILITYDEFINES_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/input_output/Assert.h"

// Forward declarations

#define ReturnIf(__Condition, ...)					do { if(__Condition) { return __VA_ARGS__; }} while(false)
#define AssertReturnIf(__Condition, ...)			do { if(__Condition) { Assert::Assert(__ASSERT_INFO); return __VA_ARGS__; }} while(false)

#define ContinueIf(__Condition)						do { if(__Condition) { continue; }} while(false)
#define AssertContinueIf(__Condition)				do { if(__Condition) { Assert::Assert(__ASSERT_INFO); continue; }} while(false)

#define BreakIf(__Condition)						do { if(__Condition) { break; }} while(false)
#define AssertBreakIf(__Condition)					do { if(__Condition) { Assert::Assert(__ASSERT_INFO); break; }} while(false)

#define SafeDelete(__Ptr)							do { if(__Ptr) { delete __Ptr; __Ptr = nullptr; }} while(false)
#define SafeDeleteArray(__Ptr)						do { if(__Ptr) { delete[] __Ptr; __Ptr = nullptr; }} while(false)

#endif // !UTILS_OTHERS_CODEREADABILITYDEFINES_H_