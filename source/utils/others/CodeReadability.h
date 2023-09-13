#ifndef UTILS_OTHERS_CODEREADABILITY_H_
#define UTILS_OTHERS_CODEREADABILITY_H_

#include "utils/Defines.h"
#include "utils/input_output/Assert.h"

#ifdef ReturnIf
	#undef ReturnIf
#endif

#ifdef AssertReturnIf
	#undef AssertReturnIf
#endif

#ifdef ContinueIf
	#undef ContinueIf
#endif

#ifdef AssertContinueIf
	#undef AssertContinueIf
#endif

#ifdef BreakIf
	#undef BreakIf
#endif

#ifdef AssertBreakIf
	#undef AssertBreakIf
#endif

#ifdef SafeDelete
	#undef SafeDelete
#endif

#ifdef SafeDeleteArray
	#undef SafeDeleteArray
#endif

#define ReturnIf(__Condition, __Result)				if(__Condition) return __Result
#define ContinueIf(__Condition)						if(__Condition) continue
#define BreakIf(__Condition)						if(__Condition) break

#define AssertReturnIf(__Condition, __Result, ...)	if(__Condition) Assert::Assert(__ASSERT_INFO(__Condition, __VA_ARGS__)); if(__Condition) return __Result
#define AssertContinueIf(__Condition, ...)			if(__Condition) Assert::Assert(__ASSERT_INFO(__Condition, __VA_ARGS__)); if(__Condition) continue
#define AssertBreakIf(__Condition, ...)				if(__Condition) Assert::Assert(__ASSERT_INFO(__Condition, __VA_ARGS__)); if(__Condition) break

#define SafeDelete(__Ptr)							do { if(__Ptr) { delete __Ptr; __Ptr = nullptr; }} while(false)
#define SafeDeleteArray(__Ptr)						do { if(__Ptr) { delete[] __Ptr; __Ptr = nullptr; }} while(false)

#endif // !UTILS_OTHERS_CODEREADABILITY_H_