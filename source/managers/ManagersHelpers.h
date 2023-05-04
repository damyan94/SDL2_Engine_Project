#ifndef MANAGERS_MANAGERSHELPERS_H_
#define MANAGERS_MANAGERSHELPERS_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Rectangle.h"

// Forward declarations

namespace Helpers
{
const Rectangle&		GetWindowRect();
int32_t					GetDrawCalls();
} // !namespace Helpers

#endif // !MANAGERS_MANAGERSHELPERS_H_