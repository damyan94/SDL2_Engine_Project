#ifndef UTILS_INPUT_OUTPUT_ASSERT_H_
#define UTILS_INPUT_OUTPUT_ASSERT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsDefines.h"
#include "utils/input_output/Log.h"

// Forward declarations

namespace Assert
{
void Assert(const char* text);
void Assert(bool condition, const char* text);
}

#endif // !UTILS_INPUT_OUTPUT_ASSERT_H_