#ifndef UTILS_INPUT_OUTPUT_ASSERT_H_
#define UTILS_INPUT_OUTPUT_ASSERT_H_

// C/C++ system includes
#include <string>

// Third-party includes

// Own includes

// Forward declarations

namespace Assert
{
void Assert(const std::string& text);
void Assert(bool condition, const std::string& text);
}

#endif // !UTILS_INPUT_OUTPUT_ASSERT_H_