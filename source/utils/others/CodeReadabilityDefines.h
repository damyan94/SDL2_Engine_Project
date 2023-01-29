#ifndef UTILS_OTHERS_CODEREADABILITYDEFINES_H_
#define UTILS_OTHERS_CODEREADABILITYDEFINES_H_

// C/C++ system includes

// Third-party includes

// Own includes

// Forward declarations

#define ReturnIf(__Condition, __Result)				do { if(__Condition) { return __Result; }} while(false)
#define AssertReturnIf(__Condition, __Result, ...)	do { if(__Condition) { Assert(__Condition, __VA_ARGS__); return __Result; }} while(false)

#define ContinueIf(__Condition)						do { if(__Condition) { continue; }} while(false)
#define AssertContinueIf(__Condition, ...)			do { if(__Condition) { Assert(__Condition, __VA_ARGS__); continue; }} while(false)

#define BreakIf(__Condition)						do { if(__Condition) { break; }} while(false)
#define AssertBreakIf(__Condition, ...)				do { if(__Condition) { Assert(__Condition, __VA_ARGS__); break; }} while(false)

#define SafeDelete(__Ptr) if(__Ptr)					do { delete __Ptr; __Ptr = nullptr; } while(false)
#define SafeDeleteArray(__Ptr) if(__Ptr)			do { delete[] __Ptr; __Ptr = nullptr; } while(false)

#endif // !UTILS_OTHERS_CODEREADABILITYDEFINES_H_