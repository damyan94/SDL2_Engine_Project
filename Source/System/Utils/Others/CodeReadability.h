#pragma once

#include "System/Utils/Defines.h"
#include "System/Utils/InputOutput/Assert.h"

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

//TODO REWORK THIS AND THE LOGGING!!!
#define ReturnIf(__Condition, ...)					if(__Condition) return __VA_ARGS__
#define ContinueIf(__Condition)						if(__Condition) continue
#define BreakIf(__Condition)						if(__Condition) break

#define ReturnUnless(__Condition, ...)				ReturnIf(!__Condition, __VA_ARGS__)
#define ContinueUnless(__Condition)					ContinueIf(!__Condition)
#define BreakUnless(__Condition)					BreakIf(!__Condition)

#define AssertReturnIf(__Condition, ...)			if(__Condition) Assert::Assert(__ASSERT_INFO(__Condition)); if(__Condition) return __VA_ARGS__
#define AssertContinueIf(__Condition)				if(__Condition) Assert::Assert(__ASSERT_INFO(__Condition)); if(__Condition) continue
#define AssertBreakIf(__Condition)					if(__Condition) Assert::Assert(__ASSERT_INFO(__Condition)); if(__Condition) break

#define AssertReturnUnless(__Condition, ...)		AssertReturnIf(!__Condition, __VA_ARGS__)
#define AssertContinueUnless(__Condition)			AssertContinueIf(!__Condition)
#define AssertBreakUnless(__Condition)				AssertBreakIf(!__Condition)

#define SafeDelete(__Ptr)							delete __Ptr; __Ptr = nullptr
#define SafeDeleteArray(__Ptr)						delete[] __Ptr; __Ptr = nullptr